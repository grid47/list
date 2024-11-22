
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### 🚀 Problem Statement
Imagine you’re a savvy stock trader 📈, and you want to maximize your profit by buying and selling shares of a stock over several days. However, there are a few rules:

1. You can **buy** one share of the stock on any day.
2. You can **sell** one share of the stock on any day.
3. After selling a share, you need to wait one day before you can buy again (this is the "cooldown" period ❄️).

Your task is to calculate the **maximum profit** possible from these transactions given an array `prices` where `prices[i]` is the stock price on day `i`.

For example:
- **Input:** `[1, 2, 3, 0, 2]`
- **Output:** `3`
  
The optimal transactions here would be buying on day 0, selling on day 2, waiting on day 3, and buying again on day 4 for a maximum profit of 3.

---

### 🧠 Approach

To tackle this problem, we'll use **Dynamic Programming (DP)** to break it down into manageable pieces. At each day, we’ll decide whether to buy, sell, or wait based on what will maximize our profit.

#### **Key States**
Let's break down the states we need to track:
- **Day (`idx`)**: The current day we're considering.
- **Buy (`buy`)**: Whether we're allowed to buy on the current day (`true` if yes, `false` if no).
- **Cooldown (`cool`)**: Whether we're in the cooldown period after a sale (`true` if yes, `false` if no).

Each state is like a checkpoint in our journey to maximizing profit, represented by the tuple `(idx, buy, cool)`.

#### **Recursive Plan with Memoization**

The core of our approach will be a recursive function with **memoization** to avoid recalculating results for the same states. We’ll consider two main actions for each day based on our state:
1. **If we’re allowed to buy**, we can either:
   - **Skip** the day without buying.
   - **Buy** the stock and move to the next day with a "cooldown" period after the buy.
   
2. **If we’re in the "sell" state** (i.e., `buy = false`), we can:
   - **Skip** the day.
   - **Sell** the stock and enter the "cooldown" state the following day.

---

### 🔨 Step-by-Step Code Breakdown

Here's how this all translates into code:

#### **1. Memoization Table** 📝

```cpp
int memo[5001][2][2];
```

- This 3D array will store results for each `(idx, buy, cool)` state to avoid redundant calculations.

#### **2. Recursive DP Function** 📐

```cpp
int dp(int idx, bool buy, bool cool) {
    if (idx == nums.size()) return 0; // Base case: reached end of days
    
    if (memo[idx][buy][cool] != -1) return memo[idx][buy][cool]; // Return memoized result
```

- **Base Case:** When `idx` equals the length of `prices`, we’ve processed all days, so profit is `0`.
- **Memoization:** If we’ve already calculated the result for the state `(idx, buy, cool)`, return it directly.

#### **3. Decision Making** 💡

```cpp
int res = dp(idx + 1, buy, false); // Skip the current day

if (buy && !cool) { // If we can buy and we're not in cooldown
    res = max(res, dp(idx + 1, false, false) - nums[idx]); // Buy stock
} else if (!buy) { // If we can't buy (in selling state)
    res = max(res, dp(idx + 1, true, true) + nums[idx]); // Sell stock and enter cooldown
}
```

- **Skip the Day:** Profit remains unchanged if we do nothing.
- **Buy**: If we're in the "buy" state and not in cooldown, consider buying the stock.
- **Sell**: If we're in the "sell" state, consider selling and entering the cooldown.

#### **4. Memoize the Result** 📌

```cpp
return memo[idx][buy][cool] = res; // Store result for future reference
```

- Save the computed result for the current state to use later.

#### **5. Main Function** 💼

```cpp
int maxProfit(vector<int>& prices) {
    memset(memo, -1, sizeof(memo)); // Initialize memo table
    this->nums = prices; // Store prices in the global vector
    return dp(0, true, false); // Start recursion with first day
}
```

- Initialize memo table with `-1`, indicating no states have been processed.
- Start the recursive function with `idx = 0`, `buy = true`, and `cool = false`.

---

### 📈 Complexity Analysis

#### **Time Complexity** ⏱️
- **O(n)**, where `n` is the number of days in the `prices` array. This is because each state `(idx, buy, cool)` is processed once due to memoization, making the recursion efficient.

#### **Space Complexity** 💾
- **O(n)**, which accounts for the memoization table to store results for each `(idx, buy, cool)` state.

---

### 🏁 Conclusion

This DP-based solution efficiently calculates the maximum profit for the given stock trading scenario with cooldowns. By storing results for each subproblem and reusing them, we avoid unnecessary recalculations and achieve optimal performance.

---

#### 🎉 Summary

Using dynamic programming and memoization, we tackled a complex stock trading scenario with a cooldown rule. This approach ensures an **O(n)** time complexity, making it efficient even for large inputs. 

Happy trading! Remember, just like in coding, patience and strategy make all the difference. 💪📈

[`Link to LeetCode Lab`](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)

---
{{< youtube t2Tw5kVkmEY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
