
+++
authors = ["Crafted by Me"]
title = "Leetcode 2845: Count of Interesting Subarrays"
date = "2017-01-18"
description = "In-depth solution and explanation for Leetcode 2845: Count of Interesting Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


"| 2846: Minimum Edge Weight Equilibrium Queries in a Tree |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

