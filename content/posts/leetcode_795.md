
+++
authors = ["Yasir"]
title = "Leetcode 795: Number of Subarrays with Bounded Maximum"
date = "2022-08-25"
description = "Solution to Leetcode 795"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int n = nums.size();
        
        int ans = 0, dp = 0, prv = -1;
        for(int i = 0; i < n; i++) {
            
            if(nums[i] < left)
                ans += dp;
                
            if(nums[i] > right) {
                dp = 0;
                prv = i;
            }
                
            if(nums[i] >= left && nums[i] <= right) {
                dp = i - prv;
                ans += dp;
            }
                
        }
        
        return ans;
    }
};
{{< /highlight >}}

