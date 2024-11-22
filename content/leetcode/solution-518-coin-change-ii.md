
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine the number of ways to make a given amount using a set of coins. You are provided with an integer `amount` and a list of `coins`, where each coin has a specific denomination. The goal is to find how many different combinations of the coins can sum up to the specified `amount`.

You can use each coin any number of times. For example:
- Given coins `[1, 2, 5]` and amount `5`, there are 4 ways to make the amount:
  - `5 = 5`
  - `5 = 2 + 2 + 1`
  - `5 = 2 + 1 + 1 + 1`
  - `5 = 1 + 1 + 1 + 1 + 1`
  
The task is to return the number of ways to make the amount using the given coins.

### Approach

This problem is a classic **dynamic programming** problem that can be solved using a bottom-up approach. The idea is to keep track of the number of ways to achieve each possible sum from `0` to the `amount` using the available coins. The solution relies on the **unbounded knapsack problem** approach where each coin can be used an unlimited number of times.

#### Key Steps:
1. **Dynamic Programming Table (Memoization)**: We will use a 2D memoization table `memo[amount][idx]` to store the results of subproblems. The index `idx` represents the current coin being considered, and `amnt` represents the remaining amount that needs to be made.

2. **Recursion with Memoization**:
   - If we are at the last coin and the remaining amount is `0`, it means we have found one valid way of making the amount, so we return `1`.
   - If the remaining amount is greater than or equal to the current coin value, we can either:
     - Skip the current coin (move to the next coin).
     - Use the current coin and reduce the remaining amount by the value of the coin.
   - We store the result of each subproblem in the memo table to avoid redundant calculations.

3. **Sorting Coins**: Sorting the coins in decreasing order helps in optimization. By trying larger coins first, the recursion tree becomes smaller and may terminate earlier, avoiding unnecessary checks.

4. **Base Case**:
   - If all coins are considered and the remaining amount is `0`, we have found one valid combination.
   - If all coins are considered and the remaining amount is greater than `0`, no valid combination can be formed from the remaining coins, so we return `0`.

### Code Breakdown (Step by Step)

Let's break down the code and explain how each part works.

#### 1. **Initialization**:
```cpp
int memo[5001][301];
vector<int> nums;
```
- We define a memoization table `memo` where `memo[amnt][idx]` stores the number of ways to make the amount `amnt` using coins from index `idx` to the end of the `nums` array. The maximum amount is `5001`, and the maximum number of coins is `301`.
- We store the coins in the `nums` vector.

#### 2. **Recursive DP Function**:
```cpp
int dp(int amnt, int idx) {
    if(idx == nums.size()) return amnt == 0;
    
    if(memo[amnt][idx] != -1) return memo[amnt][idx];
    int res = dp(amnt, idx + 1);
    
    if(amnt >= nums[idx])
        res += dp(amnt - nums[idx], idx);
    
    return memo[amnt][idx] = res;
}
```
- **Base Case**: If `idx == nums.size()`, it means we have considered all coins. If the remaining amount (`amnt`) is `0`, we return `1` as we found one valid way of making the amount. Otherwise, we return `0` since no valid way exists.
  
- **Memoization Check**: If `memo[amnt][idx]` is not `-1`, it means we have already calculated the result for this subproblem, so we return the cached value to avoid recomputing it.

- **Recursive Calculation**: 
  - First, we calculate the number of ways to make the amount `amnt` without using the current coin (i.e., move to the next coin, `idx + 1`).
  - If the remaining amount (`amnt`) is greater than or equal to the current coin's value (`nums[idx]`), we also calculate the number of ways by using the current coin and reduce the amount by `nums[idx]`.
  
- The result is stored in `memo[amnt][idx]` to avoid recomputation.

#### 3. **Sorting Coins**:
```cpp
static bool cmp(int a, int b) {
    return b < a;
}
```
- We define a comparison function `cmp` to sort the coins in descending order. This ensures that we try the largest coins first during the recursion, which can lead to early termination of the recursion tree, optimizing the process.

#### 4. **Main Function**:
```cpp
int change(int amount, vector<int>& coins) {
    this->nums = coins;
    sort(nums.begin(), nums.end(), cmp);
    memset(memo, -1, sizeof(memo));
    return dp(amount, 0);
}
```
- We initialize the `nums` vector with the provided `coins` and sort it in descending order using `sort` and the custom `cmp` function.
- We then reset the memoization table (`memo`) by setting all values to `-1` to indicate that no subproblems have been solved yet.
- Finally, we call the recursive `dp` function to compute the number of ways to make the `amount` using the given coins starting from index `0`.

### Complexity

#### Time Complexity:
- **O(amount × n)**: The time complexity of this solution is determined by the size of the memoization table, which has a size of `5001 × 301`. We are solving each subproblem once and each subproblem takes constant time for recursion and calculation. Thus, the time complexity is **O(amount × n)**, where `amount` is the target amount and `n` is the number of coins.

#### Space Complexity:
- **O(amount × n)**: The space complexity is determined by the size of the memoization table (`memo[5001][301]`), which takes up `O(amount × n)` space. Additionally, the `nums` array requires space for the coins, which is `O(n)`.

### Conclusion

This solution provides an efficient way to determine the number of ways to make a given amount using the available coins. By using dynamic programming with memoization, we avoid redundant calculations and optimize the process. Sorting the coins in descending order improves performance by reducing the recursion tree's depth. 

The time and space complexity of **O(amount × n)** make this solution feasible for moderate input sizes, and the memoization ensures that subproblems are computed only once, making the solution both time-efficient and space-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/coin-change-ii/description/)

---
{{< youtube 3Er7qS7CQUc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
