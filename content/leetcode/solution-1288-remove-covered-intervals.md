
+++
authors = ["grid47"]
title = "Leetcode 1288: Remove Covered Intervals"
date = "2024-07-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1288: Remove Covered Intervals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "nhAsMabiVkM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/remove-covered-intervals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());
        int res = 0, left = -1, right = -1;
        
        for(auto p: ivl) {
            if(left < p[0] && right < p[1]) {
                res++;
                left = p[0];
            }
            right = max(p[1], right);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1288.md" >}}
---
{{< youtube nhAsMabiVkM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1292: Maximum Side Length of a Square with Sum Less than or Equal to Threshold](https://grid47.xyz/leetcode/solution-1292-maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/) |
| --- |
