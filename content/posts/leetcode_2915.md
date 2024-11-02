
+++
authors = ["Crafted by Me"]
title = "Leetcode 2915: Length of the Longest Subsequence That Sums to Target"
date = "2015-11-09"
description = "Solution to Leetcode 2915"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int sum) {
        int n = nums.size();
        // Create a 2D array to store the dynamic programming results.
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 0; // Longest subsequence when the target sum is 0.

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                // Initially, set the result to be the same as the result for the previous element.
                dp[i][j] = dp[i - 1][j];

                // Check if the current element can contribute to the current sum.
                if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
                    dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);
            }
        }

        return dp[n][sum]; // Return the result for the entire array with the target sum.
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

