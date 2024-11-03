
+++
authors = ["Crafted by Me"]
title = "Leetcode 918: Maximum Sum Circular Subarray"
date = "2022-04-29"
description = "In-depth solution and explanation for Leetcode 918: Maximum Sum Circular Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/918.md" >}}
---
{{< youtube aLMZIfhhdMg >}}
| Next : [LeetCode #919: Complete Binary Tree Inserter](https://grid47.xyz/posts/leetcode_919) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

