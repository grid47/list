
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 516: Longest Palindromic Subsequence"
date = "2023-06-01"
description = "Solution to Leetcode 516"
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

