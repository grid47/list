
+++
authors = ["Crafted by Me"]
title = "Leetcode 53: Maximum Subarray"
date = "2023-09-10"
description = "Solution to Leetcode 53"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-subarray/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = nums[0], g = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > l + nums[i])
                l = nums[i];
            else l += nums[i];
            
            g = max(g, l);
        }
        return g;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/53.md" >}}
---
{{< youtube 5WZl3MMT0Eg >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

