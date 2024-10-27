
+++
authors = ["Yasir"]
title = "Leetcode 2453: Destroy Sequential Targets"
date = "2018-02-09"
description = "Solution to Leetcode 2453"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/destroy-sequential-targets/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(int n: nums) {
            int r = n % space;
            mp[r]++;
            if(mx < mp[r]) mx = mp[r];
        }
        for(int n : nums)
        if(mx == mp[n %space]) ans = min(ans, n);
        return ans;
    }
};
{{< /highlight >}}

