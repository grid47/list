
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2370: Longest Ideal Subsequence"
date = "2018-05-06"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

