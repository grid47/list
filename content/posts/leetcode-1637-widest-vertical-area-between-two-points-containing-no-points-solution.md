
+++
authors = ["grid47"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1638: Count Substrings That Differ by One Character](https://grid47.xyz/posts/leetcode-1638-count-substrings-that-differ-by-one-character-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}