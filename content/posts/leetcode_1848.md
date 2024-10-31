
+++
authors = ["Crafted by Me"]
title = "Leetcode 1848: Minimum Distance to the Target Element"
date = "2019-10-11"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

