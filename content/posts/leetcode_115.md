
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 115: Distinct Subsequences"
date = "2024-07-08"
description = "Solution to Leetcode 115"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/distinct-subsequences/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int memo[1001][1001];
    string s, t;
    int dp(int i, int j) {
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int res = 0;
        if(s[i] == t[j]) {
            res = dp(i + 1, j+ 1) + dp(i + 1, j);
        } else res = dp(i + 1, j);
        
        return memo[i][j] = res;
    }
    int numDistinct(string s, string t) {
        this->s = s;
        this->t = t;
        memset(memo, -1, sizeof(memo));
        return dp(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/115.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

