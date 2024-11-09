
+++
authors = ["grid47"]
title = "Leetcode 10: Regular Expression Matching"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 10: Regular Expression Matching in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Recursion"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/regular-expression-matching/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/10.jpeg" 
    alt="A web of soft strings and patterns, weaving together in a gentle pattern, signifying connection."
    caption="Solution to LeetCode 10: Regular Expression Matching Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #11: Container With Most Water](https://grid47.xyz/posts/leetcode-10-regular-expression-matching-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
