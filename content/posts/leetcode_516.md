
+++
authors = ["Crafted by Me"]
title = "Leetcode 516: Longest Palindromic Subsequence"
date = "2023-06-05"
description = "In-depth solution and explanation for Leetcode 516: Longest Palindromic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-palindromic-subsequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string str;
    vector<vector<int>> memo;
    int dp(int i, int j) {
        if(i == j) return 1;
        if(i == j - 1) return str[i] == str[j]? 2: 1;
        
        if(memo[i][j] != -1) return memo[i][j];
        
        int ans = 0;
        if(str[i] == str[j]) {
            ans = 2 + dp(i + 1, j - 1);
        } else {
            ans = max(dp(i + 1, j), dp(i, j - 1));
        }
        return memo[i][j] = ans;
    }
    
    int longestPalindromeSubseq(string s) {
        str = s;
        int n = s.size();
        memo.resize(n, vector<int>(n, -1));
        return dp(0, n - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/516.md" >}}
---
{{< youtube v6Ous7ofbMs >}}

| Next : [LeetCode #517: Super Washing Machines](grid47.xyz/leetcode_517) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

