
+++
authors = ["grid47"]
title = "Leetcode 1800: Maximum Ascending Subarray Sum"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1800: Maximum Ascending Subarray Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int maxi = sum;
        if(nums.size() == 1) return nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
                sum += nums[i];
                maxi = max(sum,maxi);
        }
            return maxi;
        }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1800.md" >}}
---
{{< youtube uiCLUTepEJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1801: Number of Orders in the Backlog](https://grid47.xyz/posts/leetcode-1801-number-of-orders-in-the-backlog-solution/) |
| --- |
