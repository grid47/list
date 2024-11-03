
+++
authors = ["Crafted by Me"]
title = "Leetcode 2116: Check if a Parentheses String Can Be Valid"
date = "2019-01-17"
description = "In-depth solution and explanation for Leetcode 2116: Check if a Parentheses String Can Be Valid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

