
+++
authors = ["grid47"]
title = "Leetcode 309: Best Time to Buy and Sell Stock with Cooldown"
date = "2024-10-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 309: Best Time to Buy and Sell Stock with Cooldown in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/309.webp"
youtube = "t2Tw5kVkmEY"
youtube_upload_date="2023-07-17"
youtube_thumbnail="https://i.ytimg.com/vi/t2Tw5kVkmEY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/309.webp" 
    alt="A graph of stock prices where the optimal buying and selling points are gently illuminated, with cooldown periods clearly marked"
    caption="Solution to LeetCode 309: Best Time to Buy and Sell Stock with Cooldown Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer array 'prices', where 'prices[i]' represents the price of a stock on the i-th day. You are allowed to complete as many transactions as you like, with the restriction that after selling a stock, you cannot buy again the next day (cooldown). The goal is to calculate the maximum profit you can achieve by making any number of transactions while respecting the cooldown period.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array, 'prices', where each element represents the price of a stock on a specific day.
- **Example:** `prices = [1, 2, 3, 0, 2]`
- **Constraints:**
	- 1 <= prices.length <= 5000
	- 0 <= prices[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the maximum profit achievable by making transactions while respecting the cooldown period.
- **Example:** `For prices = [1, 2, 3, 0, 2], the output is 3.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the maximum profit achievable by completing multiple stock transactions while adhering to the cooldown constraint.

- Use dynamic programming to track the states: whether we are holding a stock or not, and whether we're in a cooldown period.
- For each day, decide whether to buy, sell, or cooldown based on the previous decisions.
- Memoize the results to avoid redundant calculations and improve efficiency.
{{< dots >}}
### Problem Assumptions ✅
- The solution should handle edge cases like no profit or small arrays.
{{< dots >}}
## Examples 🧩
- **Input:** `prices = [1, 2, 3, 0, 2]`  \
  **Explanation:** The optimal transaction sequence is to buy on day 1 and sell on day 2, then cooldown on day 3, then buy on day 4 and sell on day 5. The total profit is 3.

- **Input:** `prices = [5, 1, 3, 6, 4]`  \
  **Explanation:** The optimal sequence is to buy on day 2, sell on day 3, buy on day 4, and sell on day 5. The total profit is 7.

- **Input:** `prices = [1]`  \
  **Explanation:** With only one price, no transaction is possible, and the maximum profit is 0.

{{< dots >}}
## Approach 🚀
A dynamic programming approach can be used to track different states of the stock transaction, such as holding a stock, not holding a stock, or being in a cooldown state.

### Initial Thoughts 💭
- We need to track whether we are holding a stock, not holding a stock, or in a cooldown state.
- We will use a 3D DP array to store the maximum profit for each state: holding a stock, not holding a stock, or in a cooldown state.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, no transactions can be made, and the profit is 0.
- The solution must efficiently handle large arrays of up to 5000 elements.
- If all prices are the same, the maximum profit is 0 as no profit can be made.
- Ensure the solution runs within the time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
int memo[5001][2][2];
vector<int> nums;
int dp(int idx, bool buy, bool cool) {
    if(idx == nums.size()) return 0;
    
    if(memo[idx][buy][cool] != -1) return memo[idx][buy][cool];
    
    int res = dp(idx + 1, buy, false);
    if(buy && !cool) {
        res = max(res, dp(idx + 1, false, false) - nums[idx]);
    } else if(!buy) {
        res = max(res, dp(idx + 1, true, true) + nums[idx]);
    }
    return memo[idx][buy][cool] = res;
}
int maxProfit(vector<int>& prices) {
    memset(memo, -1, sizeof(memo));
    this->nums = prices;
    return dp(0, true, false);
}
```

This function calculates the maximum profit that can be made from stock transactions with the constraint of a cooldown period between consecutive buy-sell operations.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Array Initialization**
	```cpp
	int memo[5001][2][2];
	```
	Initializes a memoization table `memo` to store the results of subproblems. The table has dimensions `[5001][2][2]` to store results for each index, the buy status, and the cooldown status.

2. **Vector Declaration**
	```cpp
	vector<int> nums;
	```
	Declares a vector `nums` to store the stock prices for each day.

3. **Recursive Function Definition**
	```cpp
	int dp(int idx, bool buy, bool cool) {
	```
	Defines the recursive function `dp`, which computes the maximum profit for a given index `idx`, whether we can buy (`buy`), and whether we are in a cooldown period (`cool`).

4. **Base Case**
	```cpp
	    if(idx == nums.size()) return 0;
	```
	Base case: If the current index is equal to the size of the `nums` vector, return 0, meaning no more transactions are possible.

5. **Memoization Lookup**
	```cpp
	    if(memo[idx][buy][cool] != -1) return memo[idx][buy][cool];
	```
	Checks the `memo` table to see if the result for the current state (`idx`, `buy`, `cool`) has already been computed. If so, return the stored result.

6. **Recursive Case 1 - No Transaction**
	```cpp
	    int res = dp(idx + 1, buy, false);
	```
	Recursively calls `dp` for the next index (`idx + 1`), with the same buy status and setting `cool` to `false` to simulate not making a transaction on the current day.

7. **Recursive Case 2 - Buy Stock**
	```cpp
	    if(buy && !cool) {
	```
	Checks if we are allowed to buy stock (`buy` is `true` and `cool` is `false`).

8. **Recursive Case 3 - Make Purchase**
	```cpp
	        res = max(res, dp(idx + 1, false, false) - nums[idx]);
	```
	If a purchase is made, recursively calls `dp` for the next day (`idx + 1`), setting `buy` to `false` and `cool` to `false`, while subtracting the current stock price from `res` (representing the cost of buying the stock).

9. **Recursive Case 4 - Sell Stock**
	```cpp
	    } else if(!buy) {
	```
	Checks if we are allowed to sell stock (`buy` is `false`).

10. **Recursive Case 5 - Make Sale**
	```cpp
	        res = max(res, dp(idx + 1, true, true) + nums[idx]);
	```
	If a sale is made, recursively calls `dp` for the next day (`idx + 1`), setting `buy` to `true` and `cool` to `true`, while adding the current stock price to `res` (representing the profit from selling the stock).

11. **Memoization Storage**
	```cpp
	    return memo[idx][buy][cool] = res;
	```
	Stores the result of the current state (`idx`, `buy`, `cool`) in the `memo` table to avoid recalculating it in future calls.

12. **Main Function Definition**
	```cpp
	int maxProfit(vector<int>& prices) {
	```
	Defines the `maxProfit` function, which computes the maximum profit that can be achieved given the array of stock prices `prices`.

13. **Memoization Initialization**
	```cpp
	    memset(memo, -1, sizeof(memo));
	```
	Initializes the `memo` table to `-1` for all states, indicating that no subproblem has been solved yet.

14. **Store Prices**
	```cpp
	    this->nums = prices;
	```
	Stores the input vector `prices` in the `nums` variable to be used in the `dp` function.

15. **Return Final Result**
	```cpp
	    return dp(0, true, false);
	```
	Calls the `dp` function starting from index `0`, with the ability to buy stock and no cooldown period, and returns the result (maximum profit).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate through the array once, with each state transition taking constant time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the DP array used to store the results for each day.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

---
{{< youtube t2Tw5kVkmEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
