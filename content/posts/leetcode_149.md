
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 149: Max Points on a Line"
date = "2024-06-03"
description = "Solution to Leetcode 149"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-points-on-a-line/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxPoints(vector<vector<int>>& pts) {
        if(pts.size() <= 2) return pts.size();
        
        int mx = 0;
        
        for(auto p1: pts) {
            map<double, int> ma;
            for(auto p2: pts) {
                if(p1 == p2) continue;
                double slope = 0;
                if(p1[0] == p2[0]) slope = DBL_MAX;
                else {
                    slope = (double) (p2[1] - p1[1]) / (p2[0] - p1[0]);
                }
                ma[slope]++;
                if(ma[slope] > mx)
                    mx = ma[slope];
            }
        }
        return mx + 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/149.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
