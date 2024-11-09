
+++
authors = ["grid47"]
title = "Leetcode 2915: Length of the Longest Subsequence That Sums to Target"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2915: Length of the Longest Subsequence That Sums to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2915.md" >}}
---
{{< youtube NNSzElew804 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2917: Find the K-or of an Array](https://grid47.xyz/posts/leetcode-2917-find-the-k-or-of-an-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
