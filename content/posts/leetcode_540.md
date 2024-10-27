
+++
authors = ["Yasir"]
title = "Leetcode 540: Single Element in a Sorted Array"
date = "2023-05-07"
description = "Solution to Leetcode 540"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res =0;
        for(int num : nums)
        res ^= num;

        return res;
    }
};
{{< /highlight >}}

