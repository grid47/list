
+++
authors = ["Yasir"]
title = "Leetcode 494: Target Sum"
date = "2023-06-21"
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

**Code:**

{{< highlight html >}}
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

