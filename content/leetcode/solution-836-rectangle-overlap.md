
+++
authors = ["grid47"]
title = "Leetcode 836: Rectangle Overlap"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 836: Rectangle Overlap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "o6hHUk4DOW0"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #837: New 21 Game](https://grid47.xyz/leetcode/solution-837-new-21-game/) |
| --- |
