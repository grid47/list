
+++
authors = ["Crafted by Me"]
title = "Leetcode 10: Regular Expression Matching"
date = "2024-10-23"
description = "In-depth solution and explanation for Leetcode 10: Regular Expression Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/10.md" >}}
---
{{< youtube ZNI_yXaGlxY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #11: Container With Most Water](https://grid47.xyz/posts/leetcode_11) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

