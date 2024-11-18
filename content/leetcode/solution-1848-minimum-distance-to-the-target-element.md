
+++
authors = ["grid47"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2024-05-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1848: Minimum Distance to the Target Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "eAA1gS_2QwY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-distance-to-the-target-element/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
    int res = INT_MAX;
    for (int i = 0; i < nums.size() && res > abs(start - i); ++i)
        if (nums[i] == target)
            res = abs(start - i);
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1848.md" >}}
---
{{< youtube eAA1gS_2QwY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1849: Splitting a String Into Descending Consecutive Values](https://grid47.xyz/leetcode/solution-1849-splitting-a-string-into-descending-consecutive-values/) |
| --- |
