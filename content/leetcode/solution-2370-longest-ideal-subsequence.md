
+++
authors = ["grid47"]
title = "Leetcode 2370: Longest Ideal Subsequence"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2370: Longest Ideal Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "gR1E2oLQYSY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/longest-ideal-subsequence/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for(auto &i: s) {
            for(int j = i - k; j <= i + k; j++)
                dp[i] = max(dp[i], dp[j]);
            res = max(res, ++dp[i]);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2370.md" >}}
---
{{< youtube gR1E2oLQYSY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2373: Largest Local Values in a Matrix](https://grid47.xyz/leetcode/solution-2373-largest-local-values-in-a-matrix/) |
| --- |
