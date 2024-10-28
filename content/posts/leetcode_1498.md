
+++
authors = ["Yasir"]
title = "Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition"
date = "2020-09-22"
description = "Solution to Leetcode 1498"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int pow2(int idx) {
        if(idx == 0) return 1;
        long res;
        if(idx % 2) {
            res = pow2(idx / 2);
            res = (res * res * 2) % mod;
        }else {
            res = pow2(idx / 2);
            res = (res * res) % mod;            
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        long res = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            if(nums[i] * 2 > target) break;
            
            int end = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), end);
            
            int idx = it - nums.begin();

            res = (res + pow2(idx - i - 1)) % mod;
            
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

