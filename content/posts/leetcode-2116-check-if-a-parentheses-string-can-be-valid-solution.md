
+++
authors = ["grid47"]
title = "Leetcode 2116: Check if a Parentheses String Can Be Valid"
date = "2024-04-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2116: Check if a Parentheses String Can Be Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canBeValid(string s, string lck) {
        
        return (s.size() % 2) == 0 && check(s, lck, '(') && check(s, lck, ')');
        
    }
    
    bool check(string s, string lck, char op) {

        int blk = 0, wild = 0;
        int n = s.size();

        int st  =  ( op == '(' ) ? 0 :  n - 1;
        int nd  =  ( op == '(' ) ? n - 1:  0;
        int dir =  ( op == '(' ) ? 1 : -1;

        for(int i = st; (i < n) && (i >= 0); i += dir) {

            if(lck[i] == '1') blk += (s[i] == op) ? 1: -1;
            else              wild++;

            if(blk + wild < 0) return false;

        }

        return blk <= wild;

    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2116.md" >}}
---
{{< youtube kyyf-hiGeVc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2120: Execution of All Suffix Instructions Staying in a Grid](https://grid47.xyz/posts/leetcode-2120-execution-of-all-suffix-instructions-staying-in-a-grid-solution/) |
| --- |
