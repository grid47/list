
+++
authors = ["grid47"]
title = "Leetcode 365: Water and Jug Problem"
date = "2024-10-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 365: Water and Jug Problem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/365.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/water-and-jug-problem/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/365.webp" 
    alt="A set of water jugs being filled and emptied, with the optimal solution softly glowing as it reaches the target amount."
    caption="Solution to LeetCode 365: Water and Jug Problem Problem"
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
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z || x + y == z) return true;
        return z % gcd(x, y) == 0;
    }

    int gcd(int a, int b) {
        return b == 0? a: gcd(b, a%b);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/365.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #368: Largest Divisible Subset](https://grid47.xyz/leetcode/solution-368-largest-divisible-subset/) |
| --- |