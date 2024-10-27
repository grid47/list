
+++
authors = ["Yasir"]
title = "Leetcode 2116: Check if a Parentheses String Can Be Valid"
date = "2019-01-12"
description = "Solution to Leetcode 2116"
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

{{< highlight html >}}
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

