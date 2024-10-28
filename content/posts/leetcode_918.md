
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 918: Maximum Sum Circular Subarray"
date = "2022-04-25"
description = "Solution to Leetcode 918"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-circular-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int lmax = nums[0], lmin = nums[0];
        int gmax = nums[0], gmin = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            lmax = max(nums[i], lmax + nums[i]);
            gmax = max(lmax, gmax);
            lmin = min(nums[i], lmin + nums[i]);
            gmin = min(lmin, gmin);
        }
        return gmax > 0? max(gmax, sum - gmin): gmax;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

