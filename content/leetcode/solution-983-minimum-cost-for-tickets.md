
+++
authors = ["grid47"]
title = "Leetcode 983: Minimum Cost For Tickets"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 983: Minimum Cost For Tickets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "akXV67u1pTg"
youtube_upload_date="2023-07-08"
youtube_thumbnail="https://i.ytimg.com/vi/akXV67u1pTg/maxresdefault.jpg"
comments = true
+++



---
You are planning a series of train travels throughout the year. The days you plan to travel are given in a list of integers, where each integer represents a day of the year (from 1 to 365). You need to find the minimum cost needed to cover all the travel days using 1-day, 7-day, and 30-day passes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers 'days', where each integer represents a day you plan to travel. Additionally, you are given an array 'costs' with three integers, where each represents the cost of the 1-day, 7-day, and 30-day passes respectively.
- **Example:** `days = [1, 4, 6, 7, 8, 20], costs = [3, 10, 20]`
- **Constraints:**
	- 1 <= days.length <= 365
	- 1 <= days[i] <= 365
	- days is strictly increasing.
	- costs.length == 3
	- 1 <= costs[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum cost needed to cover all the travel days using one or more of the available passes.
- **Example:** `Output: 16`
- **Constraints:**
	- The output should be an integer representing the minimum cost.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to compute the minimum cost by selecting the best combination of passes for the given travel days.

- Initialize a dynamic programming array 'dp' to store the minimum cost to cover all days from 1 to the last day of travel.
- For each day in the travel list, calculate the minimum cost considering each pass type (1-day, 7-day, 30-day).
- Use previous computed costs to optimize the solution by avoiding redundant calculations.
{{< dots >}}
### Problem Assumptions ✅
- The days array is sorted in strictly increasing order.
- The costs for the 1-day, 7-day, and 30-day passes are provided and are not negative.
{{< dots >}}
## Examples 🧩
- **Input:** `days = [1, 4, 6, 7, 8, 20], costs = [3, 10, 20]`  \
  **Explanation:** In this example, we can use a combination of a 1-day pass and a 7-day pass to minimize the cost, resulting in a total of 16 dollars.

{{< dots >}}
## Approach 🚀
The approach involves using dynamic programming to keep track of the minimum cost to cover all the travel days, iterating over the travel days and considering the cost of each type of pass at each step.

### Initial Thoughts 💭
- The problem can be solved efficiently using dynamic programming.
- We should consider all possible pass options for each travel day.
- We need to minimize the total cost while ensuring that we cover all the travel days.
{{< dots >}}
### Edge Cases 🌐
- Handle edge cases where there are no travel days.
- Consider the performance of the algorithm when the number of travel days is large, near 365.
- If the travel days cover the entire year, consider optimizing the pass choices accordingly.
- The solution must handle the maximum constraints efficiently.
{{< dots >}}
## Code 💻
```cpp
int mincostTickets(vector<int>& days, vector<int>& cost) {

    int d = days.back();
    vector<int>  dp(d + 1, 0);
    vector<bool> td(d + 1, false);

    for(int x : days) td[x] = true;

    for(int i = 1; i < d + 1; i++) {
        if(!td[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        
        dp[i] = dp[i - 1] + cost[0];
        dp[i] = min(dp[i], cost[1] + dp[max(i - 7, 0)]);
        dp[i] = min(dp[i], cost[2] + dp[max(i - 30, 0)]);            

    }

    return dp[d];
}
```

This code defines the `mincostTickets` function to calculate the minimum cost of travel given specific day and cost inputs. It uses dynamic programming to compute the cost of tickets with one-day, seven-day, and thirty-day validity options.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int mincostTickets(vector<int>& days, vector<int>& cost) {
	```
	Defines the `mincostTickets` function, which calculates the minimum cost to cover the given travel days using dynamic programming.

2. **Initial Day Calculation**
	```cpp
	    int d = days.back();
	```
	Calculates the last day in the travel days array, `days`, and stores it in variable `d`. This is used as the total number of days to consider for ticket costs.

3. **Dynamic Programming Array Initialization**
	```cpp
	    vector<int>  dp(d + 1, 0);
	```
	Initializes a dynamic programming array `dp` of size `d + 1` (one extra for 0-based indexing), where each element represents the minimum cost to cover the days up to that index.

4. **Ticket Availability Array Initialization**
	```cpp
	    vector<bool> td(d + 1, false);
	```
	Initializes an array `td` of size `d + 1` to keep track of which days are travel days, marking `true` for each travel day and `false` otherwise.

5. **Mark Travel Days**
	```cpp
	    for(int x : days) td[x] = true;
	```
	Iterates through the `days` array and marks the corresponding indices in the `td` array as `true` for each travel day.

6. **Loop Over Days**
	```cpp
	    for(int i = 1; i < d + 1; i++) {
	```
	Starts a loop that iterates through each day from 1 to `d` (the last day of travel). This loop calculates the minimum cost to cover each day.

7. **Check If Not Travel Day**
	```cpp
	        if(!td[i]) {
	```
	Checks if the current day `i` is not a travel day by checking the value of `td[i]`.

8. **Copy Previous Cost**
	```cpp
	            dp[i] = dp[i - 1];
	```
	If it's not a travel day, the cost to cover day `i` is the same as the previous day (no additional ticket is needed).

9. **Skip Non-Travel Day**
	```cpp
	            continue;
	```
	Skips the current iteration if it's not a travel day and continues to the next day.

10. **Add One-Day Ticket Cost**
	```cpp
	        dp[i] = dp[i - 1] + cost[0];
	```
	For a travel day, adds the cost of a one-day ticket (represented by `cost[0]`) to the minimum cost of covering the previous day.

11. **Add Seven-Day Ticket Cost**
	```cpp
	        dp[i] = min(dp[i], cost[1] + dp[max(i - 7, 0)]);
	```
	Checks if using a seven-day ticket (represented by `cost[1]`) results in a lower total cost by comparing it with the current value of `dp[i]`.

12. **Add Thirty-Day Ticket Cost**
	```cpp
	        dp[i] = min(dp[i], cost[2] + dp[max(i - 30, 0)]);
	```
	Checks if using a thirty-day ticket (represented by `cost[2]`) results in a lower total cost by comparing it with the current value of `dp[i]`.

13. **Return Result**
	```cpp
	    return dp[d];
	```
	Returns the minimum cost to cover all the travel days, which is stored in `dp[d]`, the last element of the dynamic programming array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of travel days.
- **Average Case:** O(n) where n is the number of travel days.
- **Worst Case:** O(n) where n is the number of travel days.

The time complexity is linear in the number of travel days, as we only process each day once.

### Space Complexity 💾
- **Best Case:** O(1) if no travel days are planned.
- **Worst Case:** O(n) for storing the DP array for n travel days.

The space complexity is linear in the number of travel days, as we need to store the minimum cost for each day.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-cost-for-tickets/description/)

---
{{< youtube akXV67u1pTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
