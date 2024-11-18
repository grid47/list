
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
youtube = "wx272jQLwkA"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/672.webp"
+++



[`Problem Link`](https://leetcode.com/problems/bulb-switcher-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/672.webp" 
    alt="A set of bulbs where switches are turned on and off, with each change softly glowing."
    caption="Solution to LeetCode 672: Bulb Switcher II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #673: Number of Longest Increasing Subsequence](https://grid47.xyz/leetcode/solution-673-number-of-longest-increasing-subsequence/) |
| --- |
