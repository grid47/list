
+++
authors = ["Yasir"]
title = "Leetcode 152: Maximum Product Subarray"
date = "2024-05-29"
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

**Code:**

{{< highlight html >}}
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

