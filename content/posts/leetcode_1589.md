
+++
authors = ["Yasir"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2020-06-22"
description = "Solution to Leetcode 1589"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        long long res = 0;
        vector<long long> cnt(n, 0);
        for(auto& r: req) {
            cnt[r[0]]++;
            if(r[1] + 1 < n)
                cnt[r[1] +1]--;
    }
        
        for(int i = 1; i < n; i++)
            cnt[i] += cnt[i -1];
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++)
            res +=  ((long long) nums[i] * cnt[i]);
        
        return res % 1000000007;
        }
};
{{< /highlight >}}

