
+++
authors = ["Crafted by Me"]
title = "Leetcode 1401: Circle and Rectangle Overlapping"
date = "2021-01-01"
description = "In-depth solution and explanation for Leetcode 1401: Circle and Rectangle Overlapping in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

