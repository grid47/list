
+++
authors = ["grid47"]
title = "Leetcode 2845: Count of Interesting Subarrays"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2845: Count of Interesting Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-of-interesting-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
    class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {        
        unordered_map<long long,long long> mp;
        long long ans = 0, prefix = 0, n = nums.size();
        mp[0]++;

        for(int i=0;i<n;i++) {
            if(nums[i]%mod==k) prefix++;

            prefix%=mod;

            if(mp.find((prefix-k+mod)%mod)!=mp.end()) 
                ans += mp[(prefix-k+mod)%mod];

            mp[prefix]++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2845.md" >}}
---
{{< youtube ao6glAa0ljY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2848: Points That Intersect With Cars](https://grid47.xyz/posts/leetcode-2848-points-that-intersect-with-cars-solution/) |
| --- |
