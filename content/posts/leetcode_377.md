
+++
authors = ["Crafted by Me"]
title = "Leetcode 377: Combination Sum IV"
date = "2023-10-22"
description = "In-depth solution and explanation for Leetcode 377: Combination Sum IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum-iv/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> mem;
public:
    int combinationSum4(vector<int>& nums, int target) {
        mem.resize(target + 1, -1);
        return dp(nums, target);
    }
    
    int dp(vector<int>& nums, int left) {
        
        if(left == 0) return 1;
        if(left < 0) return 0;

        if(mem[left] != -1) return mem[left];

        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += dp(nums, left - nums[i]);

        return mem[left] = res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/377.md" >}}
---
{{< youtube hg_U5GVEM-k >}}
| Next : [LeetCode #378: Kth Smallest Element in a Sorted Matrix](https://grid47.xyz/posts/leetcode_378) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

