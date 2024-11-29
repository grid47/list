
+++
authors = ["grid47"]
title = "Leetcode 518: Coin Change II"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 518: Coin Change II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/518.webp"
youtube = "3Er7qS7CQUc"
youtube_upload_date="2023-07-18"
youtube_thumbnail="https://i.ytimg.com/vi/3Er7qS7CQUc/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/518.webp" 
    alt="A series of coins where the minimum number of coins needed to make a change is glowing and highlighted."
    caption="Solution to LeetCode 518: Coin Change II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a set of coins of different denominations, determine how many distinct combinations of these coins sum up to the target amount.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array `coins` containing different coin denominations and an integer `amount` representing the target sum.
- **Example:** `amount = 8, coins = [3, 4, 5]`
- **Constraints:**
	- 1 <= coins.length <= 300
	- 1 <= coins[i] <= 5000
	- All values in coins are unique
	- 0 <= amount <= 5000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of distinct combinations of coins that can sum up to the target amount.
- **Example:** `3`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of distinct combinations that sum up to the target amount.

- 1. Use dynamic programming to calculate the number of ways to make each amount up to the target.
- 2. Initialize a DP array where dp[i] stores the number of ways to make amount i.
- 3. For each coin, update the DP array by considering using that coin multiple times.
{{< dots >}}
### Problem Assumptions ✅
- The `coins` array contains unique values.
- The `amount` is guaranteed to be within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `amount = 8, coins = [3, 4, 5]`  \
  **Explanation:** There are three distinct ways to make up the amount 8 using the coins [3, 4, 5]: 5+3, 4+4, and 3+3+3.

- **Input:** `amount = 6, coins = [2, 5]`  \
  **Explanation:** There is only one way to make the amount 6: 2+2+2.

{{< dots >}}
## Approach 🚀
The solution uses dynamic programming to count the number of ways to make the target amount.

### Initial Thoughts 💭
- The problem can be solved using dynamic programming as it is a variant of the coin change problem.
- We need to maintain a DP table to track the number of ways to make each possible amount.
{{< dots >}}
### Edge Cases 🌐
- If the amount is 0, return 1 as there is one way to make the amount 0 (by not using any coins).
- The algorithm should handle cases where the amount is large (up to 5000) efficiently.
- If no combination of coins can form the amount, return 0.
- Ensure the solution handles cases where the amount is 0 correctly.
{{< dots >}}
## Code 💻
```cpp
int memo[5001][301];
vector<int> nums;
int dp(int amnt, int idx) {
    if(idx == nums.size()) return amnt == 0;

    if(memo[amnt][idx] != -1) return memo[amnt][idx];
    // cout << amnt << " " << idx << " " << nums[idx]<< "\n";
    int res = dp(amnt, idx + 1);
    
    if(amnt >= nums[idx])
    res += dp(amnt - nums[idx], idx);
    
    return memo[amnt][idx] = res;
}
static bool cmp(int a, int b) {
    return b < a;
}
int change(int amount, vector<int>& coins) {
    this->nums = coins;
    sort(nums.begin(), nums.end(), cmp);
    memset(memo, -1, sizeof(memo));
    return dp(amount, 0);
}
```

This solution uses dynamic programming with memoization to solve the problem of calculating the number of ways to make a specific amount with the given coins.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int memo[5001][301];
	```
	This initializes a 2D array `memo` that will store the results of subproblems, where `memo[amnt][idx]` represents the number of ways to make the amount `amnt` from the first `idx` coins.

2. **Variable Initialization**
	```cpp
	vector<int> nums;
	```
	This declares a vector `nums` to hold the coins available to make the desired amount.

3. **Function Definition**
	```cpp
	int dp(int amnt, int idx) {
	```
	This is the recursive function `dp` which calculates the number of ways to make the amount `amnt` starting from coin index `idx`.

4. **Base Case**
	```cpp
	    if(idx == nums.size()) return amnt == 0;
	```
	If all coins have been considered (`idx` reaches the size of `nums`), return `1` if the remaining amount is zero, otherwise `0`.

5. **Memoization Check**
	```cpp
	    if(memo[amnt][idx] != -1) return memo[amnt][idx];
	```
	Check if the subproblem has already been computed by checking the `memo` table.

6. **Recursion**
	```cpp
	    int res = dp(amnt, idx + 1);
	```
	Recursively call `dp` to calculate the number of ways to make the amount `amnt` without using the current coin (`idx + 1`).

7. **Recursion with Coin Inclusion**
	```cpp
	    if(amnt >= nums[idx]) res += dp(amnt - nums[idx], idx);
	```
	If the current coin can be used (i.e., `amnt >= nums[idx]`), recursively call `dp` including the current coin and subtract its value from `amnt`.

8. **Memoization**
	```cpp
	    return memo[amnt][idx] = res;
	```
	Store the computed result in `memo[amnt][idx]` to avoid redundant calculations in future calls.

9. **Static Function**
	```cpp
	static bool cmp(int a, int b) {
	```
	This is a static comparator function used to sort the coins in descending order.

10. **Static Function**
	```cpp
	    return b < a;
	```
	The comparator function sorts coins in descending order to prioritize larger coins first.

11. **Main Function**
	```cpp
	int change(int amount, vector<int>& coins) {
	```
	This is the main function where the coin change problem is solved using the `dp` function.

12. **Variable Assignment**
	```cpp
	    this->nums = coins;
	```
	Assign the `coins` vector to the class member `nums`.

13. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end(), cmp);
	```
	Sort the coins in descending order using the `cmp` function.

14. **Memo Initialization**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initialize the `memo` table to `-1` to indicate that no subproblems have been solved yet.

15. **Recursive Call**
	```cpp
	    return dp(amount, 0);
	```
	Start the recursive `dp` function from the first coin (`idx = 0`) with the given `amount`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * amount)
- **Average Case:** O(n * amount)
- **Worst Case:** O(n * amount)

The time complexity is O(n * amount), where n is the number of coins and amount is the target sum.

### Space Complexity 💾
- **Best Case:** O(amount)
- **Worst Case:** O(amount)

The space complexity is O(amount) due to the DP array storing the number of combinations for each amount.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/coin-change-ii/description/)

---
{{< youtube 3Er7qS7CQUc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
