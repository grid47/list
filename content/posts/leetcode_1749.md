
+++
authors = ["Crafted by Me"]
title = "Leetcode 1749: Maximum Absolute Sum of Any Subarray"
date = "2020-01-18"
description = "Solution to Leetcode 1749"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int global = 0, lx = 0, ln = 0;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > lx + nums[i])
                lx = nums[i];
            else lx += nums[i];

            if(nums[i] < ln + nums[i])
                ln = nums[i];
            else ln += nums[i];
            
            
            if(abs(lx) > global)
                global = abs(lx);
            if(abs(ln) > global)
                global = abs(ln);            
        }
        return global;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

