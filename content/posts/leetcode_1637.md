
+++
authors = ["Crafted by Me"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end());
        int res =0;
        for(int i = 1; i < pts.size(); i++)
            res = max(res, pts[i][0] - pts[i - 1][0]);
        
        return res;
    }
};

{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1637.md" >}}
---
{{< youtube 6XnvNCTyJP4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1638: Count Substrings That Differ by One Character](https://grid47.xyz/posts/leetcode_1638) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

