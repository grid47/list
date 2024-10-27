
+++
authors = ["Yasir"]
title = "Leetcode 1266: Minimum Time Visiting All Points"
date = "2021-05-11"
description = "Solution to Leetcode 1266"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-visiting-all-points/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return ans;
    }
};
{{< /highlight >}}

