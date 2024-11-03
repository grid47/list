
+++
authors = ["Crafted by Me"]
title = "Leetcode 2762: Continuous Subarrays"
date = "2017-04-11"
description = "In-depth solution and explanation for Leetcode 2762: Continuous Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/continuous-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        int i = 0, j = 0,n=nums.size();
        map<int,int> mp;
        while(j<n) {
            mp[nums[j]]++;
            while(mp.size()>3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            long long temp = j-i+1;
            res = res + temp;
            j++;
        }
        return res;
    }
};
{{< /highlight >}}


---

| Next : [LeetCode #2763: Sum of Imbalance Numbers of All Subarrays](https://grid47.xyz/posts/leetcode_2763) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

