
+++
authors = ["Crafted by Me"]
title = "Leetcode 836: Rectangle Overlap"
date = "2021-07-19"
description = "Solution to Leetcode 836"
tags = [
    
]
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

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

