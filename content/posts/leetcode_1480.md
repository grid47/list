
+++
authors = ["Yasir"]
title = "Leetcode 1480: Running Sum of 1d Array"
date = "2020-10-09"
description = "Solution to Leetcode 1480"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/running-sum-of-1d-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
{{< /highlight >}}

