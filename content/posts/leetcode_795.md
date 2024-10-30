
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 795: Number of Subarrays with Bounded Maximum"
date = "2022-08-28"
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
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/795.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

