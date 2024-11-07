
+++
authors = ["Crafted by Me"]
title = "Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hr, vector<int>& vt) {
        
        int mx1 = 0, mx2 = 0;
        sort(hr.begin(), hr.end());
        sort(vt.begin(), vt.end());
        mx1 = h - hr.back();
        mx2 = w - vt.back();
        int prv = 0;
        for(int i = 0; i < hr.size(); i++) {
            mx1 = max(mx1, hr[i] - prv);
            prv = hr[i];
        }
        prv= 0;
        for(int i = 0; i < vt.size(); i++) {
            mx2 = max(mx2, vt[i] - prv);
            prv = vt[i];
        }      
        long long mxa = mx1, mxb = mx2;
        return (mxa * mxb) % 1000000007;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1465.md" >}}
---
{{< youtube koGHcwtIaLY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1466: Reorder Routes to Make All Paths Lead to the City Zero](https://grid47.xyz/posts/leetcode_1466) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
