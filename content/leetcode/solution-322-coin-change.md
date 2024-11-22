
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 🚀 Problem Statement

You're given a set of coin denominations and a target amount, and your task is to find the **minimum number of coins** needed to form that amount. If it’s impossible to form the target amount with the given coins, return `-1`.

This is a classic **dynamic programming** problem, and in this solution, we’ll use a **top-down approach** (memoization) to efficiently solve it!

---

### 🧠 Approach

This problem is all about breaking it down into smaller subproblems and solving them efficiently using **dynamic programming (DP)**. Here's the process:

1. **Recursive Structure**: 
   - At each step, you have two choices:
     - **Use the coin**: If the current coin can be used to make up part of the amount, reduce the amount and try again.
     - **Skip the coin**: Move to the next coin if the current one cannot be used.
   
2. **Memoization**: 
   - Since subproblems overlap (the same amount can be recalculated multiple times), we’ll store the results in a memoization table to avoid redundant work.
   
3. **Sorting (Optional)**: 
   - Sorting the coins in descending order can help prioritize larger coins first, which can lead to quicker solutions in some cases. However, this is not strictly necessary for correctness.

By using **memoization** (storing results of already solved subproblems), we save time and avoid recalculating the same values multiple times.

---

### 🔨 Step-by-Step Code Breakdown

Let’s dive into the code, step by step:

#### Step 1: Sort the Coins (Optional)
```cpp
sort(coins.begin(), coins.end(), cmp);
```
- Here, we sort the coins in descending order to prioritize larger denominations. This is optional but can potentially speed up the solution by trying larger coins first.

#### Step 2: Memoization Table Initialization
```cpp
memo.resize(coins.size(), vector<int>(amount + 1, -1));
```
- The `memo` table stores the minimum number of coins required for each subproblem. We initialize it with `-1`, indicating that a subproblem hasn't been solved yet.

#### Step 3: Recursive DP Function (`dp`)
```cpp
int dp(int idx, int amnt) {
    if(idx == coins.size()) return amnt == 0 ? 0 : INT_MAX - 1;
    if(memo[idx][amnt] != -1) return memo[idx][amnt];
    
    int res;
    if(amnt >= coins[idx]) {
        int r1 = 1 + dp(idx, amnt - coins[idx]);            
        int r2 = dp(idx + 1, amnt);
        res = min(r1, r2);
    } else {
        res = dp(idx + 1, amnt);
    }

    return memo[idx][amnt] = res;
}
```
- **Base Case**: If we reach the end of the `coins` list (`idx == coins.size()`), we check if the remaining `amnt` is zero. If it is, we return `0` (no more coins needed). If `amnt > 0`, return a large value (`INT_MAX - 1`) to signify that it’s impossible to form the amount with the remaining coins.
  
- **Memoization Check**: If we’ve already solved for a particular subproblem (i.e., `memo[idx][amnt]` is not `-1`), we simply return the stored result.
  
- **Recursive Case**: For each coin at index `idx`, we:
  - **Use the coin**: If the remaining amount `amnt` is greater than or equal to the coin, we reduce the amount and recursively solve the subproblem.
  - **Skip the coin**: If we cannot use the coin, we move to the next coin by calling `dp(idx + 1, amnt)`.

#### Step 4: Final Result
```cpp
int ans = dp(0, amount);
return ans == INT_MAX - 1 ? -1 : ans;
```
- We start by calling `dp(0, amount)` to compute the minimum coins needed from the first coin. 
- If the result is `INT_MAX - 1` (impossible to form the amount), we return `-1`. Otherwise, we return the result.

---

### 📈 Complexity Analysis

- **Time Complexity**: `O(n * m)`, where `n` is the number of coin denominations and `m` is the target amount. This is because the memoization table has `n * m` entries, and each entry is computed once, in constant time.
  
- **Space Complexity**: `O(n * m)`, where `n` is the number of coin denominations and `m` is the target amount. The memoization table takes up `n * m` space to store the intermediate results.

---

### 🏁 Conclusion

This solution is a **dynamic programming** masterpiece! By breaking the problem down into smaller subproblems and using **memoization**, we avoid redundant calculations and can efficiently compute the minimum number of coins needed to make the given amount. 

---

### 🔑 Key Takeaways

1. **Recursive Structure**: Each step is a choice—use the coin or skip it.
2. **Memoization**: Storing results of subproblems to avoid redundant calculations.
3. **Efficient**: With time complexity of `O(n * m)`, this approach is perfect for large inputs.

Great job! 🎉 Keep up the momentum and keep solving problems like a pro! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/coin-change/description/)

---
{{< youtube xxrv-uJdV8Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
