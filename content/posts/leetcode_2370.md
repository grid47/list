
+++
authors = ["Yasir"]
title = "Leetcode 2370: Longest Ideal Subsequence"
date = "2018-05-03"
description = "Solution to Leetcode 2370"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-ideal-subsequence/description/)

---

**Code:**

{{< highlight html >}}
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

