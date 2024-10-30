
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1401: Circle and Rectangle Overlapping"
date = "2020-12-30"
description = "Solution to Leetcode 1401"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

