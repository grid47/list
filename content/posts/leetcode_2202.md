
+++
authors = ["Crafted by Me"]
title = "Leetcode 2202: Maximize the Topmost Element After K Moves"
date = "2018-10-23"
description = "In-depth solution and explanation for Leetcode 2202: Maximize the Topmost Element After K Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2203: Minimum Weighted Subgraph With the Required Paths](https://grid47.xyz/posts/leetcode_2203) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

