
+++
authors = ["grid47"]
title = "Leetcode 647: Palindromic Substrings"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 647: Palindromic Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Dynamic Programming"]
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
---
{{< youtube EU5xSa5ZHGY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #648: Replace Words](https://grid47.xyz/posts/leetcode-648-replace-words-solution/) |
| --- |
