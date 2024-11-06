
+++
authors = ["Crafted by Me"]
title = "Leetcode 2116: Check if a Parentheses String Can Be Valid"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2117: Abbreviating the Product of a Range](https://grid47.xyz/posts/leetcode_2117) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
