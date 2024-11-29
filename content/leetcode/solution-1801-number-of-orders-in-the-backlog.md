
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
comments = true
+++



---
You are managing an order system for a marketplace where both buy and sell orders are placed in batches. Each order contains a price, a quantity, and a type (either buy or sell). You need to calculate how many orders remain unfulfilled in the system after processing all the orders.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D array where each subarray represents an order with three values: price, amount, and order type (0 for buy, 1 for sell).
- **Example:** `orders = [[10, 5, 0], [15, 2, 1], [20, 1, 1], [30, 4, 0]]`
- **Constraints:**
	- 1 <= orders.length <= 100,000
	- 1 <= price_i, amount_i <= 10^9
	- orderType_i is either 0 (buy) or 1 (sell)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of unfulfilled orders in the backlog after processing all the orders, modulo 10^9 + 7.
- **Example:** `Output: 6`
- **Constraints:**
	- The result is modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Process the orders to match buy and sell orders, keeping track of unmatched orders in the backlog.

- Initialize two priority queues, one for buy orders and one for sell orders.
- For each order in the input, check if it's a buy or sell order.
- If it's a buy order, try to match it with the cheapest sell order. If no match is found, add it to the buy queue.
- If it's a sell order, try to match it with the most expensive buy order. If no match is found, add it to the sell queue.
- At the end, count the remaining orders in both queues.
{{< dots >}}
### Problem Assumptions ✅
- Orders are processed sequentially.
{{< dots >}}
## Examples 🧩
- **Input:** `orders = [[10, 5, 0], [15, 2, 1], [20, 1, 1], [30, 4, 0]]`  \
  **Explanation:** In this example, 5 buy orders at price 10 are placed and go into the backlog since no sell orders exist. Then, 2 sell orders at price 15 are added to the backlog, followed by 1 sell order at price 20. Finally, 4 buy orders at price 30 are added, and matching occurs with the 2 lowest-priced sell orders (15 and 20). The remaining orders in the backlog are 5 buy orders with price 10 and 1 buy order with price 30.

{{< dots >}}
## Approach 🚀
We will use two priority queues to efficiently match buy and sell orders. A buy order will be matched with the cheapest sell order, and a sell order will be matched with the most expensive buy order. After processing all orders, we will count the remaining unmatched orders in the backlog.

### Initial Thoughts 💭
- We can use priority queues (heaps) to store buy and sell orders in sorted order, making matching efficient.
- We need to account for all possible scenarios where orders do not match, and orders that remain unmatched must be added to the backlog.
{{< dots >}}
### Edge Cases 🌐
- An empty input should return 0, as no orders are placed.
- If the input contains the maximum allowed number of orders, the solution should handle it within the time limits.
- Consider cases where orders are exactly matched (both buy and sell orders can be fulfilled), as well as cases where no orders can be matched.
- Ensure that operations on the priority queues are efficient, as the input size can be large.
{{< dots >}}
## Code 💻
```cpp
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
```

This code solves the problem of calculating the number of orders left in the backlog after processing all the incoming buy and sell orders, considering that they can match based on specific conditions. The solution uses priority queues (heaps) to efficiently manage and match the orders.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
	```
	Start of the function definition that takes in a 2D vector of orders. The function returns an integer representing the number of remaining orders in the backlog.

2. **Variable Initialization**
	```cpp
	    int mod = (int) (1e9 + 7);
	```
	Declaring a variable 'mod' to store the modulus value, used later to prevent overflow and maintain results within the bounds of a 32-bit integer.

3. **Data Structure Operations**
	```cpp
	    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
	```
	Initialize a priority queue for sell orders with the 'greater' comparator to maintain the smallest price at the top.

4. **Data Structure Operations**
	```cpp
	    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buy;        
	```
	Initialize a priority queue for buy orders with the 'less' comparator to maintain the largest price at the top.

5. **Loop and Recursion**
	```cpp
	    for(auto it: orders) {
	```
	Start a loop to iterate over each order in the 'orders' vector.

6. **Conditional Function Call**
	```cpp
	        if(it[2] == 0) { // For a buy order
	```
	Check if the order type is 'buy' (indicated by the third element of the order).

7. **Variable Initialization**
	```cpp
	            pair<int, int> top;
	```
	Declare a pair 'top' to hold the current top element in the priority queue while processing orders.

8. **Loop and Recursion**
	```cpp
	            while(!sell.empty() && sell.top().first <= it[0] && it[1]) {
	```
	Start a loop that processes the sell orders that can be matched with the current buy order.

9. **Data Structure Operations**
	```cpp
	                top = sell.top();
	```
	Pop the top element from the sell priority queue (which contains the lowest price orders).

10. **Data Structure Operations**
	```cpp
	                sell.pop();
	```
	Remove the top element from the sell priority queue.

11. **Flow Control**
	```cpp
	                if(top.second > it[1]) {
	```
	Check if the quantity of the top sell order is greater than the quantity of the buy order.

12. **Mathematical Operations**
	```cpp
	                    top.second -= it[1];
	```
	Update the sell order quantity by subtracting the matched quantity of the buy order.

13. **Variable Initialization**
	```cpp
	                    it[1] = 0;
	```
	Set the remaining quantity of the buy order to 0, as it has been fully matched.

14. **Data Structure Operations**
	```cpp
	                    sell.push(top);
	```
	Push the updated sell order back into the sell priority queue.

15. **Flow Control**
	```cpp
	                } else {
	```
	Otherwise, update the buy order quantity by subtracting the matched quantity.

16. **Mathematical Operations**
	```cpp
	                    it[1] -= top.second;
	```
	Subtract the matched quantity from the buy order.

17. **Data Structure Operations**
	```cpp
	            if(it[1] > 0) buy.push({it[0], it[1]});
	```
	If the buy order is not fully matched, push it into the buy priority queue.

18. **Conditional Function Call**
	```cpp
	        } else if(it[2] == 1) {
	```
	Else, if the order type is 'sell', process the sell order in a similar manner.

19. **Variable Initialization**
	```cpp
	            pair<int, int> top;
	```
	Declare a pair 'top' for processing the top sell orders.

20. **Loop and Recursion**
	```cpp
	            while(!buy.empty() && buy.top().first >= it[0] && it[1]) {
	```
	Start a loop that processes the buy orders that can be matched with the current sell order.

21. **Data Structure Operations**
	```cpp
	                top = buy.top();
	```
	Pop the top element from the buy priority queue.

22. **Data Structure Operations**
	```cpp
	                buy.pop();
	```
	Remove the top element from the buy priority queue.

23. **Flow Control**
	```cpp
	                if(top.second > it[1]) {
	```
	If the quantity of the top buy order is greater than the quantity of the sell order.

24. **Mathematical Operations**
	```cpp
	                    top.second -= it[1];
	```
	Update the buy order quantity.

25. **Variable Initialization**
	```cpp
	                    it[1] = 0;
	```
	Set the remaining quantity of the sell order to 0.

26. **Data Structure Operations**
	```cpp
	                    buy.push(top);
	```
	Push the updated buy order back into the buy priority queue.

27. **Flow Control**
	```cpp
	                } else {
	```
	Otherwise, update the sell order quantity.

28. **Mathematical Operations**
	```cpp
	                    it[1] -= top.second;
	```
	Subtract the matched quantity from the sell order.

29. **Data Structure Operations**
	```cpp
	            if(it[1] > 0) sell.push({it[0], it[1]});              
	```
	If the sell order is not fully matched, push it into the sell priority queue.

30. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize the variable 'cnt' to hold the total count of remaining orders in the backlog.

31. **Data Structure Operations**
	```cpp
	    while(!sell.empty()) {
	```
	Process the remaining sell orders.

32. **Data Structure Operations**
	```cpp
	        auto top = sell.top();
	```
	Get the top sell order.

33. **Mathematical Operations**
	```cpp
	        cnt = (cnt + top.second) % mod;
	```
	Add the quantity of the remaining sell order to 'cnt' and apply modulus operation.

34. **Data Structure Operations**
	```cpp
	        sell.pop();
	```
	Pop the top element from the sell priority queue.

35. **Data Structure Operations**
	```cpp
	    while(!buy.empty()) {
	```
	Process the remaining buy orders.

36. **Data Structure Operations**
	```cpp
	        auto top = buy.top();
	```
	Get the top buy order.

37. **Mathematical Operations**
	```cpp
	        cnt = (cnt + top.second) % mod;
	```
	Add the quantity of the remaining buy order to 'cnt' and apply modulus operation.

38. **Data Structure Operations**
	```cpp
	        buy.pop();
	```
	Pop the top element from the buy priority queue.

39. **Return**
	```cpp
	    return cnt;
	```
	Return the final count of remaining orders modulo 1e9 + 7.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is determined by the need to process each order and maintain the priority queues, which takes O(log n) for each operation.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We are using two priority queues to store the orders, which requires space proportional to the number of orders.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-orders-in-the-backlog/description/)

---
{{< youtube hVVkBM-p1vg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
