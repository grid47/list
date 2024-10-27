
+++
authors = ["Yasir"]
title = "Leetcode 149: Max Points on a Line"
date = "2024-06-01"
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

{{< highlight html >}}
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

