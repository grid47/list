
+++
authors = ["Crafted by Me"]
title = "Leetcode 560: Subarray Sum Equals K"
date = "2023-04-22"
description = "In-depth solution and explanation for Leetcode 560: Subarray Sum Equals K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subarray-sum-equals-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int res = 0;
        
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, cnt = 0;
        
        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];
            if(mp.count(sum - k)) cnt += mp[sum - k];
            mp[sum] += 1;
        }

        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/560.md" >}}
---
{{< youtube fFVZt-6sgyo >}}

| Next : [LeetCode #561: Array Partition](grid47.xyz/leetcode_561) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

