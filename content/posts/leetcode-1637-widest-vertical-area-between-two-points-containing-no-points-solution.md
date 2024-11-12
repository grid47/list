
+++
authors = ["grid47"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2024-05-27"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1638: Count Substrings That Differ by One Character](https://grid47.xyz/posts/leetcode-1638-count-substrings-that-differ-by-one-character-solution/) |
| --- |
