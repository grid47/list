
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 152: Maximum Product Subarray"
date = "2024-06-01"
description = "Solution to Leetcode 152"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-subarray/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = 1, mn = 1;

        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], mx * nums[i]);
            mn = min(nums[i], mn * nums[i]);
            
            res = max(res, mx);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/152.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

