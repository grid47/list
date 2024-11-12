
+++
authors = ["grid47"]
title = "Leetcode 918: Maximum Sum Circular Subarray"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 918: Maximum Sum Circular Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Dynamic Programming","Queue","Monotonic Queue"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #919: Complete Binary Tree Inserter](https://grid47.xyz/posts/leetcode-919-complete-binary-tree-inserter-solution/) |
| --- |
