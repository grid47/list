
+++
authors = ["grid47"]
title = "Leetcode 2864: Maximum Odd Binary Number"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2864: Maximum Odd Binary Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Greedy"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2864.md" >}}
---
{{< youtube EUKLOAv4-IQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2865: Beautiful Towers I](https://grid47.xyz/posts/leetcode-2865-beautiful-towers-i-solution/) |
| --- |
