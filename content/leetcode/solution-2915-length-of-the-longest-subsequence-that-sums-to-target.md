
+++
authors = ["grid47"]
title = "Leetcode 2915: Length of the Longest Subsequence That Sums to Target"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2915: Length of the Longest Subsequence That Sums to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NNSzElew804"
youtube_upload_date="2023-10-28"
youtube_thumbnail="https://i.ytimg.com/vi/NNSzElew804/maxresdefault.jpg"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2917: Find the K-or of an Array](https://grid47.xyz/leetcode/solution-2917-find-the-k-or-of-an-array/) |
| --- |