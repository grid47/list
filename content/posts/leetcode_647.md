
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 647: Palindromic Substrings"
date = "2023-01-22"
description = "Solution to Leetcode 647"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/palindromic-substrings/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> mem;
    string s;
    int dp(int i, int j) {
        if(i >= j) return 1;
        if(mem[i][j] != -1) return mem[i][j];
        return mem[i][j] = (s[i] == s[j])? dp(i + 1, j - 1): 0;
    }
    
    int countSubstrings(string s) {
        this->s = s;
        int n = s.size();
        mem.resize(n, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        for(int j = i; j < s.size(); j++)
            ans += dp(i, j);        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/647.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

