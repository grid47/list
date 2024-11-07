
+++
authors = ["Crafted by Me"]
title = "Leetcode 836: Rectangle Overlap"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 836: Rectangle Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rectangle-overlap/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        int fx1=rect1[0];
        int fx2=rect1[2];
        int fy1=rect1[1];
        int fy2=rect1[3];

        int sx1=rect2[0];
        int sx2=rect2[2];
        int sy1=rect2[1];
        int sy2=rect2[3];

        return !((sy1>=fy2) ||
               (fy1>=sy2) ||
               (fx1>=sx2) ||
               (fx2<=sx1));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/836.md" >}}
---
{{< youtube o6hHUk4DOW0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #837: New 21 Game](https://grid47.xyz/posts/leetcode_837) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
