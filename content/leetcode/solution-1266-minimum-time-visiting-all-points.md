
+++
authors = ["grid47"]
title = "Leetcode 1266: Minimum Time Visiting All Points"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1266: Minimum Time Visiting All Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "jqcmjnXmCaw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-time-visiting-all-points/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1266.md" >}}
---
{{< youtube jqcmjnXmCaw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1267: Count Servers that Communicate](https://grid47.xyz/leetcode/solution-1267-count-servers-that-communicate/) |
| --- |
