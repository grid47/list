
+++
authors = ["Yasir"]
title = "Leetcode 2016: Maximum Difference Between Increasing Elements"
date = "2019-04-22"
description = "Solution to Leetcode 2016"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i) {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};
{{< /highlight >}}

