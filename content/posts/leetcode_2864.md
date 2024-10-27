
+++
authors = ["Yasir"]
title = "Leetcode 2864: Maximum Odd Binary Number"
date = "2016-12-25"
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

{{< highlight html >}}
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

