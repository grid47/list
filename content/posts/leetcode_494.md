
+++
authors = ["grid47"]
title = "Leetcode 494: Target Sum"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 494: Target Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #497: Random Point in Non-overlapping Rectangles](https://grid47.xyz/posts/leetcode_497) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
