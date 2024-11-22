
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to calculate the total number of continuous descending periods in a given list of stock prices. A descending period is defined as a sequence of prices where each price is exactly one less than the previous price. The goal is to return the sum of all such descending periods, including each individual price as a valid period.

### Approach

To solve this problem, we can use a dynamic programming approach. The idea is to keep track of the number of consecutive descending prices ending at each position in the list. Here’s how the approach works:

1. **Dynamic Programming Array**: Create an array `dp` where `dp[i]` will store the number of descending periods ending at index `i`.
2. **Initialization**: Initialize `dp[0]` to 1 since the first price itself counts as a descending period.
3. **Iterate Through Prices**: For each price starting from the second one, check if it continues a descending sequence from the previous price.
4. **Update Counts**: If it does, update `dp[i]` based on `dp[i-1]`. If it doesn't, reset `dp[i]` to 1 (the current price itself).
5. **Accumulate Results**: Sum all values in the `dp` array to get the total number of descending periods.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   vector<int> dp(prices.size(), 0);
   dp[0] = 1;
   long long ans = 1;
   ```
   - A vector `dp` is created with the same size as `prices` to store the count of descending periods.
   - The first element `dp[0]` is initialized to 1 because the first price itself is a valid period.
   - The variable `ans` is initialized to 1 to account for the first price.

2. **Loop Through Prices**:
   ```cpp
   for(int i = 1; i < prices.size(); i++) {
   ```
   - Start a loop from the second price (index 1) to the last price in the `prices` vector.

3. **Check Descending Condition**:
   ```cpp
   if(prices[i] == prices[i - 1] - 1)
   ```
   - Check if the current price is exactly one less than the previous price.

4. **Update Dynamic Programming Array**:
   ```cpp
   dp[i] = dp[i - 1] + 1;
   ```
   - If the condition is true, it means that the current price continues the descending sequence, so `dp[i]` is updated to the value of `dp[i-1]` plus one.
   ```cpp
   else dp[i] = 1;
   ```
   - If the condition is false, the current price starts a new descending period, hence `dp[i]` is set to 1.

5. **Accumulate Total Descending Periods**:
   ```cpp
   ans += dp[i];
   ```
   - Add the current value of `dp[i]` to `ans` to keep track of the total number of descending periods.

6. **Return the Result**:
   ```cpp
   return ans;
   ```
   - Finally, return the total count of descending periods stored in `ans`.

### Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of prices in the `prices` array.
  - The algorithm processes each price exactly once in a single loop.

- **Space Complexity**: \(O(n)\) for the `dp` array.
  - The space used is proportional to the input size since we store counts for each price.

### Conclusion

This solution effectively counts the total number of continuous descending periods in the prices using a dynamic programming approach. By leveraging a simple iterative method and maintaining a count of descending periods, the code efficiently calculates the desired result in linear time. This approach ensures that each price is only processed once, providing both clarity and performance. The dynamic programming technique allows for easy accumulation of results, making the solution both straightforward and efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

---
{{< youtube p_hKOwJ7azU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
