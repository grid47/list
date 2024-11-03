
+++
authors = ["Crafted by Me"]
title = "Leetcode 1736: Latest Time by Replacing Hidden Digits"
date = "2020-02-01"
description = "In-depth solution and explanation for Leetcode 1736: Latest Time by Replacing Hidden Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumTime(string t) {
        if(t[0]=='?' && t[1]=='?')
        {
            t[0]='2';
            t[1]='3';
        }
        if(t[0]=='?')
        {
            if(t[1]<='0')
                t[0]='2';
            else if(t[1]<='1')
                t[0]='2';
            else if(t[1]<='2')
                t[0]='2';
            else if(t[1]<='3')
                t[0]='2';
            else 
                t[0]='1';
        }
        if(t[1]=='?')
        {
            if(t[0]=='2')
                t[1]='3';
            else 
                t[1]='9';
        }
        if(t[3]=='?' && t[4]=='?')
        {
            t[3]='5';
            t[4]='9';
        }
        if(t[3]=='?')
        {
            t[3]='5';
        }
        if(t[4]=='?')
        {
            t[4]='9';
        }
        return t;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #1737: Change Minimum Characters to Satisfy One of Three Conditions](grid47.xyz/leetcode_1737) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

