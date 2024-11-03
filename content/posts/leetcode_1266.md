
+++
authors = ["Crafted by Me"]
title = "Leetcode 1266: Minimum Time Visiting All Points"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1266: Minimum Time Visiting All Points in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1267: Count Servers that Communicate](https://grid47.xyz/posts/leetcode_1267) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

