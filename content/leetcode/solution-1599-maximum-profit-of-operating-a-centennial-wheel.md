
+++
authors = ["grid47"]
title = "Leetcode 1599: Maximum Profit of Operating a Centennial Wheel"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1599: Maximum Profit of Operating a Centennial Wheel in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Jn2ELfoSRf0"
youtube_upload_date="2020-09-27"
youtube_thumbnail="https://i.ytimg.com/vi/Jn2ELfoSRf0/maxresdefault.jpg"
comments = true
+++



---
You operate a giant Ferris wheel with four gondolas, each holding up to four passengers. The Ferris wheel rotates counterclockwise and incurs a running cost for every rotation. You are given a list of customer arrivals, where each entry indicates the number of customers arriving just before the ith rotation. Customers board the gondola closest to the ground, and only a maximum of four customers can board at any time, while any excess wait for the next rotation. Each customer pays a boarding cost. Your task is to determine the minimum number of rotations needed to achieve the maximum profit. If there is no scenario where the profit is positive, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers representing the number of customers arriving just before each rotation.
- **Example:** `[12, 4]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= customers[i] <= 50
	- 1 <= boardingCost, runningCost <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of rotations to achieve the maximum profit. If no profit can be achieved, return -1.
- **Example:** `3`
- **Constraints:**
	- Return the minimum number of rotations to achieve the maximum profit.
	- If no profit can be achieved, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum number of rotations to maximize profit.

- Keep track of the number of waiting customers.
- For each rotation, add new customers and board the maximum number of customers (up to 4).
- Compute the profit after each rotation by subtracting the running cost from the boarding revenue.
- Stop when the profit is maximized and return the number of rotations required.
{{< dots >}}
### Problem Assumptions ✅
- At most four customers can board per rotation.
- The wheel rotates counterclockwise.
- Once the wheel stops, no additional rotations will be made.
{{< dots >}}
## Examples 🧩
- **Input:** `customers = [12, 4], boardingCost = 8, runningCost = 5`  \
  **Explanation:** After 3 rotations, the maximum profit of $84 is achieved. Thus, the answer is 3.

{{< dots >}}
## Approach 🚀
To maximize profit, simulate each rotation and calculate the boarding revenue and running cost. Track the maximum profit and the corresponding rotation count.

### Initial Thoughts 💭
- The wheel can hold a maximum of 4 customers at a time.
- The goal is to stop when profit is maximized, even if not all customers are served.
- Start with an initial profit of zero and simulate the wheel's rotations.
- Track waiting customers and board up to 4 at a time.
{{< dots >}}
### Edge Cases 🌐
- If no customers arrive, the answer is 0 as no rotation is needed.
- Handle large arrays efficiently with O(n) time complexity.
- When the profit is never positive, return -1.
- Make sure to handle all edge cases where the profit might be zero or negative.
{{< dots >}}
## Code 💻
```cpp
int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
    
    /*
    
    4gondolas
    couter clockwise
    running cost
    
    */

    int n = cust.size();
    int wait = 0;
    int profit = 0, rot = 0;
    int mx = INT_MIN;
    int idx = 0;
    while(idx < n || wait > 0) {
        wait += idx < n? cust[idx]:0;
        // cout << wait << " ";
        if(wait > 4) {
            profit += 4 * boardingCost - runningCost;
            wait -= 4;
        } else if(wait > 0) {
            profit += wait * boardingCost - runningCost;
            wait = 0;
        }

        if(mx < profit) {
            mx = profit;
            rot = idx + 1;
        }
        idx++;
    }
    return mx <= 0? -1: rot;
}
```

This function calculates the maximum profit achievable based on the number of customers boarding a gondola at a certain cost and the fixed running cost of operating the gondolas. The function iterates through customer data, updating the profit, and keeps track of the optimal operation rotation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
	```
	This is the function signature. It defines a function 'minOperationsMaxProfit' that takes a vector of integers 'cust', representing the number of customers at each stop, along with 'boardingCost' and 'runningCost' integers to calculate the profit.

2. **Variable Initialization**
	```cpp
	    int n = cust.size();
	```
	This line initializes 'n' with the size of the 'cust' vector, representing the total number of stops or iterations.

3. **Variable Initialization**
	```cpp
	    int wait = 0;
	```
	The 'wait' variable is initialized to 0. It will track the number of customers waiting at each stop.

4. **Variable Initialization**
	```cpp
	    int profit = 0, rot = 0;
	```
	These variables initialize the profit (set to 0 initially) and the rotation count (rot) to track the rotation with the highest profit.

5. **Variable Initialization**
	```cpp
	    int mx = INT_MIN;
	```
	The variable 'mx' is initialized to the minimum possible integer value to track the maximum profit during the iterations.

6. **Variable Initialization**
	```cpp
	    int idx = 0;
	```
	The 'idx' variable is initialized to 0 and is used to iterate through the 'cust' vector.

7. **Loop**
	```cpp
	    while(idx < n || wait > 0) {
	```
	This 'while' loop continues as long as there are customers to process (either in 'cust' or in 'wait').

8. **Customer Processing**
	```cpp
	        wait += idx < n? cust[idx]:0;
	```
	The number of customers at the current stop ('cust[idx]') is added to 'wait', unless there are no more stops left (when 'idx' is out of bounds).

9. **Profit Calculation**
	```cpp
	        if(wait > 4) {
	```
	If there are more than 4 waiting customers, the gondola will board 4 customers, and the profit will be calculated for that batch.

10. **Profit Calculation**
	```cpp
	            profit += 4 * boardingCost - runningCost;
	```
	The profit is updated by boarding 4 customers at the 'boardingCost' and subtracting the 'runningCost'.

11. **Wait Adjustment**
	```cpp
	            wait -= 4;
	```
	The number of waiting customers is reduced by 4, as 4 customers have boarded the gondola.

12. **Profit Calculation**
	```cpp
	        } else if(wait > 0) {
	```
	If there are still some customers waiting but fewer than 4, the remaining customers board the gondola.

13. **Profit Calculation**
	```cpp
	            profit += wait * boardingCost - runningCost;
	```
	The profit is updated based on the remaining number of waiting customers, charging the 'boardingCost' and subtracting the 'runningCost'.

14. **Wait Adjustment**
	```cpp
	            wait = 0;
	```
	All waiting customers are boarded, so 'wait' is reset to 0.

15. **Profit Check**
	```cpp
	        if(mx < profit) {
	```
	This checks if the current profit is greater than the previous maximum profit. If so, it updates 'mx' and tracks the rotation.

16. **Profit Update**
	```cpp
	            mx = profit;
	```
	Updates the maximum profit ('mx') with the current profit.

17. **Rotation Update**
	```cpp
	            rot = idx + 1;
	```
	Updates the rotation index 'rot' with the current gondola rotation.

18. **End Condition**
	```cpp
	        }
	```
	This closes the 'if' block that checks if the current profit is the maximum.

19. **Index Update**
	```cpp
	        idx++;
	```
	Increments the 'idx' to move to the next stop.

20. **Loop End**
	```cpp
	    }
	```
	This ends the 'while' loop.

21. **Return**
	```cpp
	    return mx <= 0? -1: rot;
	```
	If the maximum profit ('mx') is less than or equal to 0, it returns -1 (no profit). Otherwise, it returns the optimal rotation number ('rot').

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we iterate through the customers array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We use only a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/)

---
{{< youtube Jn2ELfoSRf0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
