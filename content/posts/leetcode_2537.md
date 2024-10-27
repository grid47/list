
+++
authors = ["Yasir"]
title = "Leetcode 2537: Count the Number of Good Subarrays"
date = "2017-11-17"
description = "Solution to Leetcode 2537"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-good-subarrays/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, tmp = 0;
        
        int n = nums.size();
        
        map<int, int> mp, cnt;
        
        int j = 0;
        for(int i = 0; i < n; i++) {
            tmp += (cnt[nums[i]]);
            cnt[nums[i]]++;            
            while(j <= i && tmp >= k) {
                res+= (n - i);
                cnt[nums[j]]--;
                tmp -= cnt[nums[j]];
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}

