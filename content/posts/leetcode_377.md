
+++
authors = ["Yasir"]
title = "Leetcode 377: Combination Sum IV"
date = "2023-10-18"
description = "Solution to Leetcode 377"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

