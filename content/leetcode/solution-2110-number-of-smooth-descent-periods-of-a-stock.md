
+++
authors = ["grid47"]
title = "Leetcode 2110: Number of Smooth Descent Periods of a Stock"
date = "2024-04-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2110: Number of Smooth Descent Periods of a Stock in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "p_hKOwJ7azU"
youtube_upload_date="2021-12-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/p_hKOwJ7azU/maxresdefault.webp"
comments = true
+++



---
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day. A smooth descent period of a stock consists of contiguous days such that the price on each day decreases by exactly 1 from the previous day. The first day of the period can be a single-day smooth descent. Return the total number of smooth descent periods.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers representing the stock prices over multiple days.
- **Example:** `prices = [5, 4, 3, 6]`
- **Constraints:**
	- 1 <= prices.length <= 10^5
	- 1 <= prices[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of smooth descent periods where each period consists of one or more contiguous days where the price decreases by exactly 1 each day.
- **Example:** `For prices = [5, 4, 3, 6], the output should be 6.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the number of smooth descent periods from the given stock price list.

- Initialize a variable to keep track of the current descent period length.
- Iterate through the prices list, and for each day, check if the price is exactly 1 less than the previous day's price.
- For each valid descent period, increment the count of descent periods.
{{< dots >}}
### Problem Assumptions ✅
- The list of prices contains only positive integers.
- The stock price list can have both increasing and decreasing price sequences.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: prices = [5, 4, 3, 6]`  \
  **Explanation:** The smooth descent periods are: [5], [4], [3], [6], [5,4], and [4,3], resulting in a total of 6 smooth descent periods.

- **Input:** `Example 2: prices = [8, 6, 5, 7]`  \
  **Explanation:** The smooth descent periods are: [8], [6], [5], and [7]. There are no multi-day descent periods here.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the list of stock prices and counting the smooth descent periods by checking the difference between consecutive days.

### Initial Thoughts 💭
- Each descent period consists of a sequence of days where the price decreases by exactly 1 from one day to the next.
- For each contiguous sequence of days with this property, we can count the number of possible subarrays that form valid descent periods.
- This can be done in a single pass over the input list to ensure efficient performance.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- Ensure the solution handles arrays of length up to 100,000 efficiently.
- If the array contains only one price, there is exactly one smooth descent period.
- The solution should process the input in linear time, O(n).
{{< dots >}}
## Code 💻
```cpp
long long getDescentPeriods(vector<int>& prices) {
    vector<int> dp(prices.size(), 0);
    dp[0] = 1;
    long long ans = 1;
    for(int i = 1; i < prices.size(); i++) {
        if(prices[i] == prices[i - 1] - 1)
        dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
        ans += dp[i];
    }
    return ans;
}
```

This function calculates the total number of descent periods in a list of prices, where each descent period is a contiguous subsequence where prices decrease by 1 each time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long getDescentPeriods(vector<int>& prices) {
	```
	Define the function `getDescentPeriods` that takes a vector of integers `prices` representing stock prices and returns the total number of descent periods.

2. **Vector Initialization**
	```cpp
	    vector<int> dp(prices.size(), 0);
	```
	Initialize a vector `dp` of the same size as `prices` to store the length of the current descent period for each price. All values are initially set to 0.

3. **Initial Value Assignment**
	```cpp
	    dp[0] = 1;
	```
	Set the first element of `dp` to 1, representing that the first price is a valid descent period of length 1.

4. **Variable Initialization**
	```cpp
	    long long ans = 1;
	```
	Initialize the variable `ans` to 1 to track the total number of descent periods, starting with the first price.

5. **Loop Start**
	```cpp
	    for(int i = 1; i < prices.size(); i++) {
	```
	Start a loop from the second price in the list to check if it continues the descent from the previous price.

6. **Condition Check**
	```cpp
	        if(prices[i] == prices[i - 1] - 1)
	```
	Check if the current price `prices[i]` is exactly 1 less than the previous price, indicating a descent period.

7. **Update Descent Length**
	```cpp
	        dp[i] = dp[i - 1] + 1;
	```
	If a descent is found, set `dp[i]` to the length of the previous descent period (`dp[i - 1]`) plus 1.

8. **Reset Descent Length**
	```cpp
	        else dp[i] = 1;
	```
	If the current price does not continue the descent, reset `dp[i]` to 1, indicating a new descent period.

9. **Accumulate Total Descent Periods**
	```cpp
	        ans += dp[i];
	```
	Add the length of the current descent period (`dp[i]`) to the total count `ans`.

10. **Return Statement**
	```cpp
	    return ans;
	```
	Return the total number of descent periods stored in `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of days (length of the prices array).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) if a new array or counter is used, but could be O(1) with optimized space usage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

---
{{< youtube p_hKOwJ7azU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
