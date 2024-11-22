
+++
authors = ["grid47"]
title = "Leetcode 1801: Number of Orders in the Backlog"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1801: Number of Orders in the Backlog in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hVVkBM-p1vg"
youtube_upload_date="2021-03-21"
youtube_thumbnail="https://i.ytimg.com/vi/hVVkBM-p1vg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        int mod = (int) (1e9 + 7);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buy;        
        
        for(auto it: orders) {
            
            if(it[2] == 0) { // For a buy order
                
                pair<int, int> top;
                while(!sell.empty() && sell.top().first <= it[0] && it[1]) {
                    top = sell.top();
                    sell.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        sell.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) buy.push({it[0], it[1]});
                
            } else if(it[2] == 1) {
                pair<int, int> top;
                while(!buy.empty() && buy.top().first >= it[0] && it[1]) {
                    top = buy.top();
                    buy.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        buy.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) sell.push({it[0], it[1]});              
            }
            
        }
        
        int cnt = 0;
        
        while(!sell.empty()) {
            auto top = sell.top();
            cnt = (cnt + top.second) % mod;
            sell.pop();
        }
        while(!buy.empty()) {
            auto top = buy.top();
            cnt = (cnt + top.second) % mod;
            buy.pop();
        }        
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves managing a backlog of buy and sell orders in a trading system. Each order is represented by a list of three integers: the price of the order, the quantity of the order, and the type of order (buy or sell). The goal is to calculate the total number of outstanding orders left in the backlog after processing a series of orders. The rules for processing orders are based on the price at which they are placed and the quantity available in the backlog.

### Approach

To solve this problem, we utilize two priority queues (also known as heaps):

1. **Sell Orders**: A min-heap that manages sell orders based on their price. The lowest priced sell orders are prioritized, allowing us to efficiently match them with incoming buy orders.

2. **Buy Orders**: A max-heap that manages buy orders based on their price. The highest priced buy orders are prioritized, enabling efficient matching with incoming sell orders.

The algorithm processes each order in the following manner:

1. **Processing Buy Orders**:
   - For each buy order (indicated by a type of `0`), we attempt to match it with sell orders.
   - While there are still orders in the sell queue and the price of the lowest sell order is less than or equal to the price of the buy order, we perform the following:
     - Compare the quantity of the sell order with the remaining quantity of the buy order.
     - If the buy order can fully match the sell order, reduce the quantity of the buy order accordingly and remove the sell order.
     - If the sell order is larger, reduce its quantity and reinsert it into the sell queue.

2. **Processing Sell Orders**:
   - For each sell order (indicated by a type of `1`), we attempt to match it with buy orders using a similar approach:
   - While there are still orders in the buy queue and the price of the highest buy order is greater than or equal to the price of the sell order, we compare the quantities and adjust them accordingly.

3. **Final Count of Backlog Orders**:
   - After processing all orders, the remaining quantities in both priority queues represent the backlog. We sum the quantities of all remaining orders in both queues to get the total backlog.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
```
- The class `Solution` defines a public method `getNumberOfBacklogOrders` which takes a vector of orders.

```cpp
        int mod = (int) (1e9 + 7);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buy;        
```
- We define a modulus value (`mod`) to ensure that results fit within the typical constraints of integer limits in competitive programming.
- Two priority queues are initialized: `sell` for managing sell orders and `buy` for managing buy orders.

```cpp
        for(auto it: orders) {
```
- We loop through each order in the input list.

```cpp
            if(it[2] == 0) { // For a buy order
```
- When a buy order is detected (type `0`), we attempt to match it with available sell orders.

```cpp
                pair<int, int> top;
                while(!sell.empty() && sell.top().first <= it[0] && it[1]) {
```
- We initiate a loop to check against the sell orders while the sell queue is not empty, and the price of the lowest sell order is less than or equal to the price of the current buy order.

```cpp
                    top = sell.top();
                    sell.pop();
```
- The top sell order is fetched and removed from the queue for processing.

```cpp
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        sell.push(top);
                    } else {
                        it[1] -= top.second;
                    }
```
- We compare the quantity of the sell order with the buy order:
  - If the sell order can satisfy the buy order, we reduce the sell order's quantity and set the buy order quantity to zero.
  - If the sell order is larger, we decrease the buy order's quantity accordingly.

```cpp
                if(it[1] > 0) buy.push({it[0], it[1]});
```
- If there is any remaining quantity in the buy order after attempting matches, we push it into the buy queue.

```cpp
            } else if(it[2] == 1) {
```
- If the current order is a sell order (type `1`), we execute a similar matching logic against buy orders.

```cpp
                pair<int, int> top;
                while(!buy.empty() && buy.top().first >= it[0] && it[1]) {
```
- Here, we check against the buy orders, ensuring that the highest priced buy orders are considered for matching.

```cpp
                if(it[1] > 0) sell.push({it[0], it[1]});              
```
- If any quantity remains in the sell order after matching attempts, we add it to the sell queue.

```cpp
        int cnt = 0;
        
        while(!sell.empty()) {
```
- After processing all orders, we initialize a counter `cnt` to accumulate the total backlog.

```cpp
            auto top = sell.top();
            cnt = (cnt + top.second) % mod;
            sell.pop();
        }
        while(!buy.empty()) {
```
- We loop through the remaining sell orders, summing their quantities to `cnt` and ensuring we apply the modulus to avoid overflow.

```cpp
            auto top = buy.top();
            cnt = (cnt + top.second) % mod;
            buy.pop();
        }        
        return cnt;
    }
};
```
- The final loop does the same for the buy orders, and the function concludes by returning the total count of backlog orders.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n \log n)\), where \(n\) is the number of orders. This is due to the fact that each insertion and deletion in the priority queues takes \(O(\log n)\) time.

- **Space Complexity**: The space complexity is \(O(n)\), as we are potentially storing all orders in the two priority queues.

### Conclusion

The implemented algorithm effectively manages the backlog of orders through the use of priority queues, allowing for efficient order matching based on pricing. The method adheres to principles of optimal data structure usage, providing a solution that can scale well with increasing order sizes. 

By utilizing priority queues, the code can efficiently handle incoming buy and sell orders, ensuring that matches are made promptly and accurately. The clear separation of logic for buy and sell orders simplifies the process and makes it easy to maintain and understand.

In the context of algorithm design and implementation, this solution is a solid example of handling priority-based operations and illustrates how to manage complex data flows effectively within a trading system. Understanding these concepts is vital for software engineers working on financial platforms or any applications that require similar functionalities.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-orders-in-the-backlog/description/)

---
{{< youtube hVVkBM-p1vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
