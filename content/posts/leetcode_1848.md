
+++
authors = ["Crafted by Me"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2019-10-12"
description = "In-depth solution and explanation for Leetcode 1848: Minimum Distance to the Target Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
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


---


| Next : [LeetCode #1849: Splitting a String Into Descending Consecutive Values](grid47.xyz/leetcode_1849) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

