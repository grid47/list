
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2864: Maximum Odd Binary Number"
date = "2016-12-27"
description = "Solution to Leetcode 2864"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-odd-binary-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
    int i = 0, sz = s.size();
    for(int j = 0;j < sz - 1; ++j) {
        if(s[j] == '1') {
            swap(s[j], s[i]);
            ++i;
        } 
    }
    
    if(s.back() != '1') 
        swap(s[sz - 1], s[i - 1]);
    return s;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
