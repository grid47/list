
+++
authors = ["Yasir"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2020-05-05"
description = "Solution to Leetcode 1637"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/)

---

**Code:**

{{< highlight html >}}
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

