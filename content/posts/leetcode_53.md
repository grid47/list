
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 53: Maximum Subarray"
date = "2024-09-06"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

