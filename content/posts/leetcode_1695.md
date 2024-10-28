
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1695: Maximum Erasure Value"
date = "2020-03-09"
description = "Solution to Leetcode 1695"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-erasure-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sum = 0, n = nums.size();
        map<int, int> mp;
        
        int mx = 0;
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];
            
            while(mp[nums[i]] > 1) {
                mp[nums[j]]--;
                sum -= nums[j];
                j++;
            }
            
            mx = max(mx, sum);
        }
        return mx;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

