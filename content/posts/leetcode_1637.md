
+++
authors = ["Crafted by Me"]
title = "Leetcode 1637: Widest Vertical Area Between Two Points Containing No Points"
date = "2020-05-09"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

