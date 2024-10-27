
+++
authors = ["Yasir"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2019-10-07"
description = "Solution to Leetcode 1848"
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

{{< highlight html >}}
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

