
+++
authors = ["grid47"]
title = "Leetcode 672: Bulb Switcher II"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 672: Bulb Switcher II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Bit Manipulation","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bulb-switcher-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int flipLights(int n, int m) {
        if(m==0) return 1;
        if(n==1) return 2;
        if(n==2&&m==1) return 3;
        if(n==2) return 4;
        if(m==1) return 4;
        if(m==2) return 7;
        if(m>=3) return 8;
        return 8;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/672.md" >}}
---
{{< youtube wx272jQLwkA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #673: Number of Longest Increasing Subsequence](https://grid47.xyz/posts/leetcode-673-number-of-longest-increasing-subsequence-solution/) |
| --- |
