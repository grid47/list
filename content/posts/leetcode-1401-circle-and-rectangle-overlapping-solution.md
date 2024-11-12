
+++
authors = ["grid47"]
title = "Leetcode 1401: Circle and Rectangle Overlapping"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1401: Circle and Rectangle Overlapping in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1 -= xCenter;
        x2 -= xCenter;
        y1 -= yCenter;
        y2 -= yCenter;
        int mx = x1 * x2 > 0? min(x1 * x1, x2 * x2): 0;
        int my = y1 * y2 > 0? min(y1 * y1, y2 * y2): 0;
        return mx + my <= radius * radius;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1401.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1404: Number of Steps to Reduce a Number in Binary Representation to One](https://grid47.xyz/posts/leetcode-1404-number-of-steps-to-reduce-a-number-in-binary-representation-to-one-solution/) |
| --- |
