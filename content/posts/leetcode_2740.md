
+++
authors = ["Yasir"]
title = "Leetcode 2740: Find the Value of the Partition"
date = "2017-04-28"
description = "Solution to Leetcode 2740"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-value-of-the-partition/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = nums[1] - nums[0];
        for(int i = 1; i < nums.size(); i++) {
            res = min(nums[i] - nums[i - 1], res);
        }
        return res;
    }
};
{{< /highlight >}}

