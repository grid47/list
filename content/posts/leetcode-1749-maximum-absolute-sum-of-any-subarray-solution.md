
+++
authors = ["grid47"]
title = "Leetcode 1749: Maximum Absolute Sum of Any Subarray"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1749: Maximum Absolute Sum of Any Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1749.md" >}}
---
{{< youtube XVVB_ZXsbnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1750: Minimum Length of String After Deleting Similar Ends](https://grid47.xyz/posts/leetcode-1750-minimum-length-of-string-after-deleting-similar-ends-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
