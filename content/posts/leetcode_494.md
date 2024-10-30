
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 494: Target Sum"
date = "2023-06-25"
description = "Solution to Leetcode 494"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/target-sum/description/)

---
{{< youtube Rdie0uPp7e8 >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

