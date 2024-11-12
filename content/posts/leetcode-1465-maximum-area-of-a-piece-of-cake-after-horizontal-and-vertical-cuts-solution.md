
+++
authors = ["grid47"]
title = "Leetcode 1465: Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts"
date = "2024-06-13"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1466: Reorder Routes to Make All Paths Lead to the City Zero](https://grid47.xyz/posts/leetcode-1466-reorder-routes-to-make-all-paths-lead-to-the-city-zero-solution/) |
| --- |
