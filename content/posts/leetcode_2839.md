
+++
authors = ["Yasir"]
title = "Leetcode 2839: Check if Strings Can be Made Equal With Operations I"
date = "2017-01-20"
description = "Solution to Leetcode 2839"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        if(s1[0] != s2[0]) swap(s1[0],s1[2]);
        if(s1 == s2) return true;
        
        if(s1[1] != s2[1]) swap(s1[1],s1[3]);
        if(s1 == s2) return true;
        
        return false;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

