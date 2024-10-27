
+++
authors = ["Yasir"]
title = "Leetcode 2762: Continuous Subarrays"
date = "2017-04-06"
description = "Solution to Leetcode 2762"
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

{{< highlight html >}}
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

