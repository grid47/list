
+++
authors = ["Crafted by Me"]
title = "Leetcode 795: Number of Subarrays with Bounded Maximum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 795: Number of Subarrays with Bounded Maximum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube V8jAp1Zi1Os >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #796: Rotate String](https://grid47.xyz/posts/leetcode_796) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

