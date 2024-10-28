
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2202: Maximize the Topmost Element After K Moves"
date = "2018-10-19"
description = "Solution to Leetcode 2202"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {

        int ans = 0;
        
        int n = nums.size();
        
        if (k == 0) return (n >= 1) ? nums[0] : -1;
        if (k == 1) return (n == 1) ? -1 : nums[1];
        if (n == 1) return (k % 2 == 1) ? -1 : nums[0];
        
        int mx = *max_element(begin(nums), begin(nums) + min(n, k - 1));
        if(k < n) mx = max(mx, nums[k]);
        
        return mx;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

