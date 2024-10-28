
+++
authors = ["Yasir"]
title = "Leetcode 560: Subarray Sum Equals K"
date = "2023-04-18"
description = "Solution to Leetcode 560"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

