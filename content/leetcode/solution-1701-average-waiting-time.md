
+++
authors = ["grid47"]
title = "Leetcode 1701: Average Waiting Time"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1701: Average Waiting Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2fN7uIgCIBA"
youtube_upload_date="2024-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/2fN7uIgCIBA/maxresdefault.jpg"
comments = true
+++



---
A restaurant with a single chef serves customers. Each customer arrives at a specific time and waits for the chef to prepare their order. The chef can only serve one customer at a time and prepares orders in the order they were received. The goal is to calculate the average waiting time of all customers. The waiting time of a customer is the time between their arrival and when they receive their order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D array where each entry represents a customer, with the first value indicating the arrival time and the second value indicating the time required to prepare the order.
- **Example:** `[[1, 2], [3, 4], [6, 1]]`
- **Constraints:**
	- 1 <= customers.length <= 10^5
	- 1 <= arrivali, timei <= 10^4
	- arrivali <= arrivali+1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a floating-point number representing the average waiting time for all customers.
- **Example:** `3.33333`
- **Constraints:**
	- The result must be accurate within 10^-5

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the average waiting time of all customers.

- 1. Initialize the current time to the arrival time of the first customer.
- 2. For each customer, check if the chef is idle or still working on a previous order.
- 3. If the chef is idle, the chef starts preparing the order immediately; otherwise, the chef waits for the chef to finish the current order.
- 4. Add the waiting time (current time - arrival time) to the total waiting time.
- 5. After processing all customers, return the total waiting time divided by the number of customers.
{{< dots >}}
### Problem Assumptions ✅
- The customer arrival times are provided in non-decreasing order.
- The chef serves customers in the order they arrive.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 2], [2, 5], [4, 3]]`  \
  **Explanation:** In this example, the first customer arrives at time 1 and waits 2 units of time, so their waiting time is 2. The second customer arrives at time 2 but waits until the chef is free at time 3, so their waiting time is 6. The third customer arrives at time 4 and waits until the chef is free at time 8, giving them a waiting time of 7. The average waiting time is (2 + 6 + 7) / 3 = 5.

{{< dots >}}
## Approach 🚀
The solution iterates through the customer list while managing the time taken for each customer’s order. We track when each customer starts and finishes their order to calculate their waiting time.

### Initial Thoughts 💭
- The chef prepares orders one at a time and cannot start a new order until the previous one is finished.
- The problem requires managing the flow of customers and calculating each one's waiting time. The key observation is that the chef can only serve one customer at a time and must wait for previous orders to be completed.
{{< dots >}}
### Edge Cases 🌐
- If there are no customers, return 0.
- Ensure that the solution can handle inputs with 100,000 customers efficiently.
- When all customers have the same arrival time and order time, the waiting time will be calculated sequentially based on the previous customer's finish time.
- The input constraints should be respected to avoid performance issues with large inputs.
{{< dots >}}
## Code 💻
```cpp
double averageWaitingTime(vector<vector<int>>& cust) {
    
    int cur = cust[0][0];
    
    double n = cust.size();
    double sum = 0;
    
    for(int i = 0; i < n; i++) {
        
        if(cur > cust[i][0])
        cur += cust[i][1];
        else
        cur = cust[i][0] + cust[i][1];
        
        sum += cur - cust[i][0];
        
    }
    
    return sum / n;
}
```

This function calculates the average waiting time for a series of customers based on their arrival times and service durations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	double averageWaitingTime(vector<vector<int>>& cust) {
	```
	Defines the function `averageWaitingTime`, which calculates the average waiting time for customers based on their arrival times and service durations.

2. **Initial Setup**
	```cpp
	    int cur = cust[0][0];
	```
	Initializes the `cur` variable to represent the current time, starting with the arrival time of the first customer.

3. **Variable Initialization**
	```cpp
	    double n = cust.size();
	```
	Sets the variable `n` to the total number of customers in the `cust` array, which helps in calculating the average later.

4. **Variable Initialization**
	```cpp
	    double sum = 0;
	```
	Initializes a variable `sum` to 0, which will hold the total waiting time for all customers.

5. **Loop Through Customers**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to iterate through all customers in the `cust` array.

6. **Customer Time Check**
	```cpp
	        if(cur > cust[i][0])
	```
	Checks if the current time (`cur`) is greater than the arrival time of the current customer. If true, the customer can start being served immediately.

7. **Update Current Time**
	```cpp
	        cur += cust[i][1];
	```
	If the current customer can be served immediately, add their service duration to the current time (`cur`).

8. **Update Current Time**
	```cpp
	        cur = cust[i][0] + cust[i][1];
	```
	If the customer arrives after the current time, set the `cur` to their arrival time plus their service duration.

9. **Accumulate Waiting Time**
	```cpp
	        sum += cur - cust[i][0];
	```
	Adds the waiting time of the current customer to `sum`, which is the difference between the current time (`cur`) and their arrival time.

10. **Return Average Waiting Time**
	```cpp
	    return sum / n;
	```
	Returns the average waiting time by dividing the total accumulated waiting time (`sum`) by the number of customers (`n`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of customers. The best case occurs when the chef is always idle and the customers are served immediately.
- **Average Case:** O(n), where n is the number of customers. The average case assumes that customers arrive in a reasonable distribution.
- **Worst Case:** O(n), where n is the number of customers. The worst case happens when each customer arrives after the previous one and needs to wait for their turn.

The time complexity is linear because we iterate over the customers once.

### Space Complexity 💾
- **Best Case:** O(1), since we only need a constant amount of space for variables like current time and total waiting time.
- **Worst Case:** O(n), where n is the number of customers, due to the input size.

The space complexity is linear because we are storing a list of customers and only require a small amount of additional space for tracking the time and sums.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/average-waiting-time/description/)

---
{{< youtube 2fN7uIgCIBA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
