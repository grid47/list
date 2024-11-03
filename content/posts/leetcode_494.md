
+++
authors = ["Crafted by Me"]
title = "Leetcode 494: Target Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 494: Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Dynamic Programming","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/target-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, map<int, int>> mp;
    vector<int> nums;
    
    int dp(int target, int idx) {
        if(idx == nums.size()) return target == 0;
        
        if(mp.count(target))
            if(mp[target].count(idx)) return mp[target][idx];
        
        int res = dp(target - nums[idx], idx + 1);
        res += dp(target + nums[idx], idx + 1);
        
        return mp[target][idx] = res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        return dp(target, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/494.md" >}}
---
{{< youtube Rdie0uPp7e8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #495: Teemo Attacking](https://grid47.xyz/posts/leetcode_495) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

