
+++
authors = ["Yasir"]
title = "Leetcode 10: Regular Expression Matching"
date = "2024-10-19"
description = "Solution to Leetcode 10"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/regular-expression-matching/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string s, p;
    vector<vector<int>> memo;
    bool dp(int i, int j) {
        if(i == s.size() && j == p.size()) return true;
        if(j == p.size()) return false;
        
        if(memo[i][j] != -1) return memo[i][j];
        int ans = 0;
        if(j + 1 < p.size() && p[j + 1] == '*') {
            if(i < s.size() && (s[i] == p[j] || p[j] == '.'))
                ans |= dp(i+1, j);
            ans |= dp(i, j + 2);
        } else {
            if(i < s.size() && (s[i] == p[j] || p[j] == '.'))
                ans |= dp(i+1, j + 1);            
        }
        
        return memo[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        this-> s = s;
        this-> p = p;
        
        memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dp(0, 0);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

