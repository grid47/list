
+++
authors = ["grid47"]
title = "Leetcode 322: Coin Change"
date = "2024-10-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 322: Coin Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/322.webp"
youtube = "xxrv-uJdV8Y"
youtube_upload_date="2023-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/xxrv-uJdV8Y/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/322.webp" 
    alt="A set of coins gradually transforming into the fewest possible number of coins needed to make the change, glowing softly."
    caption="Solution to LeetCode 322: Coin Change Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a set of coins with different denominations and a target amount. Your task is to determine the fewest number of coins required to make the target amount. If it's not possible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers, coins, representing the different coin denominations, and an integer, amount, representing the target amount.
- **Example:** `coins = [1, 2, 5], amount = 11`
- **Constraints:**
	- 1 <= coins.length <= 12
	- 1 <= coins[i] <= 2^31 - 1
	- 0 <= amount <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the fewest number of coins needed to make the amount. If it's not possible to make up the amount, return -1.
- **Example:** `3`
- **Constraints:**
	- The output should be an integer indicating the minimum number of coins required.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum number of coins needed to form the target amount using dynamic programming.

- Use dynamic programming to solve this problem.
- Create a dp array where dp[i] represents the minimum number of coins needed to make amount i.
- Iterate through the coins array and update the dp array accordingly.
- If the dp value for the target amount is still infinity, return -1 as it's impossible to form the amount.
{{< dots >}}
### Problem Assumptions ✅
- You have an infinite supply of each coin denomination.
- The input coins array will not be empty, and all denominations are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `coins = [1, 2, 5], amount = 11`  \
  **Explanation:** We can form the amount 11 by using two 5-coin denominations (5 + 5) and one 1-coin denomination, so the minimum number of coins required is 3.

- **Input:** `coins = [2], amount = 3`  \
  **Explanation:** Since 3 cannot be formed with the coin denomination of 2, the result is -1.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming (DP) to find the minimum number of coins needed to form the target amount.

### Initial Thoughts 💭
- The problem is a variation of the 'coin change' problem, commonly solved using DP.
- We need to keep track of the minimum number of coins required for each possible amount up to the target amount.
- The solution should focus on building up the minimum coin count for each amount from 0 to the target amount.
{{< dots >}}
### Edge Cases 🌐
- If the input amount is 0, return 0 as no coins are needed.
- If the amount is very large, the solution should efficiently calculate the minimum coins without unnecessary computations.
- If the amount cannot be formed with the given coins, return -1.
- The solution should handle edge cases where no combination of coins can form the given amount.
{{< dots >}}
## Code 💻
```cpp
vector<int> coin;
vector<vector<int>> memo;
static bool cmp(int a, int b) {
    return a > b;
}

int dp(int idx, int amnt) {
    if(idx == coin.size()) return amnt == 0? 0: INT_MAX-1;
    
    if(memo[idx][amnt] != -1) return memo[idx][amnt];
    
    int res;
    if(amnt >= coin[idx]) {
        int r1 = 1 + dp(idx, amnt - coin[idx]);            
        int r2 = dp(idx + 1, amnt);
        res = min(r1, r2);
    } else {
        res = dp(idx + 1, amnt);
    }

    return memo[idx][amnt] = res;
}

int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end(), cmp);
    
    this->coin = coins;
    
    memo.resize(coin.size(),vector<int>(amount + 1, -1) );
    int ans = dp(0, amount);
    return ans == INT_MAX-1?-1: ans;
}
```

This function calculates the minimum number of coins needed to make up a given amount using dynamic programming. The `dp` function recursively solves subproblems and stores results in a memoization table to avoid redundant computations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<int> coin;
	```
	This initializes a vector `coin` that will store the denominations of coins.

2. **Variable Initialization**
	```cpp
	vector<vector<int>> memo;
	```
	This initializes a 2D vector `memo` for memoization to store intermediate results of subproblems, avoiding redundant calculations.

3. **Helper Function**
	```cpp
	static bool cmp(int a, int b) {
	```
	This is a helper function used for sorting the coins in descending order before starting the dynamic programming process.

4. **Helper Function**
	```cpp
	    return a > b;
	```
	The `cmp` function compares two integers and returns true if the first integer is greater than the second, ensuring coins are sorted in descending order.

5. **Recursive Function Declaration**
	```cpp
	int dp(int idx, int amnt) {
	```
	This declares the recursive function `dp`, which solves the coin change problem by evaluating all possible subproblems for a given index and remaining amount.

6. **Base Case**
	```cpp
	    if(idx == coin.size()) return amnt == 0? 0: INT_MAX-1;
	```
	This base case handles the scenario where all coins have been considered. If the remaining amount (`amnt`) is zero, it returns 0 (no more coins needed). Otherwise, it returns `INT_MAX-1` to signify an invalid solution.

7. **Memoization Check**
	```cpp
	    if(memo[idx][amnt] != -1) return memo[idx][amnt];
	```
	This checks if the result for the current subproblem (`dp(idx, amnt)`) has already been computed. If it has, the function returns the stored value to avoid redundant computation.

8. **Variable Declaration**
	```cpp
	    int res;
	```
	Declaring the variable `res` to store the result of the subproblem.

9. **Decision Making**
	```cpp
	    if(amnt >= coin[idx]) {
	```
	If the remaining amount (`amnt`) is greater than or equal to the value of the current coin (`coin[idx]`), two choices are considered: use the current coin or skip it.

10. **Recursion and Calculation**
	```cpp
	        int r1 = 1 + dp(idx, amnt - coin[idx]);            
	```
	Here, we recursively call the `dp` function to include the current coin (`coin[idx]`), reducing the remaining amount by that coin's value. `1 +` is added to account for using this coin.

11. **Recursion and Calculation**
	```cpp
	        int r2 = dp(idx + 1, amnt);
	```
	This recursive call evaluates the option where the current coin is skipped, moving to the next coin (`idx + 1`) and keeping the amount the same.

12. **Comparison**
	```cpp
	        res = min(r1, r2);
	```
	The result `res` is determined by taking the minimum of the two recursive results (`r1` and `r2`), which represents the minimum coins required.

13. **Else Case**
	```cpp
	    } else {
	```
	If the current coin cannot be used (i.e., `amnt < coin[idx]`), we proceed to the next coin.

14. **Recursion**
	```cpp
	        res = dp(idx + 1, amnt);
	```
	This recursive call evaluates the option where the current coin is skipped, moving to the next coin without reducing the amount.

15. **Memoization**
	```cpp
	    return memo[idx][amnt] = res;
	```
	Store the computed result for the current subproblem in the `memo` table to avoid redundant calculations in future calls.

16. **Main Function**
	```cpp
	int coinChange(vector<int>& coins, int amount) {
	```
	This is the main function where the coin change problem is solved. It initializes the coins and memoization table and calls the recursive `dp` function.

17. **Sorting**
	```cpp
	    sort(coins.begin(), coins.end(), cmp);
	```
	The coins are sorted in descending order using the `cmp` function to improve the efficiency of the dynamic programming solution.

18. **Coin Initialization**
	```cpp
	    this->coin = coins;
	```
	The sorted coin denominations are assigned to the `coin` vector for use in the recursive `dp` function.

19. **Memoization Table Initialization**
	```cpp
	    memo.resize(coin.size(),vector<int>(amount + 1, -1) );
	```
	The memoization table is resized to match the number of coins and the amount. Each cell is initialized to `-1`, indicating that no subproblem has been solved yet.

20. **Calling dp**
	```cpp
	    int ans = dp(0, amount);
	```
	The `dp` function is called with the initial index `0` and the target `amount`.

21. **Result**
	```cpp
	    return ans == INT_MAX-1?-1: ans;
	```
	If the result is `INT_MAX-1`, it indicates that the problem has no solution, so `-1` is returned. Otherwise, the result (minimum number of coins) is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(amount * coins.length)
- **Average Case:** O(amount * coins.length)
- **Worst Case:** O(amount * coins.length)

The time complexity is determined by the number of iterations over the dp array and the coins array.

### Space Complexity 💾
- **Best Case:** O(amount)
- **Worst Case:** O(amount)

The space complexity is O(amount) due to the dp array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/coin-change/description/)

---
{{< youtube xxrv-uJdV8Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
