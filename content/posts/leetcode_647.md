
+++
authors = ["Crafted by Me"]
title = "Leetcode 647: Palindromic Substrings"
date = "2023-01-25"
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
- by gpt
        
---
{{< youtube EU5xSa5ZHGY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

