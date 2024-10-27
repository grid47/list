
+++
authors = ["Yasir"]
title = "Leetcode 1819: Number of Different Subsequences GCDs"
date = "2019-11-05"
description = "Solution to Leetcode 1819"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-different-subsequences-gcds/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> fact(200001, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j * j <= nums[i]; j++) {
                if(nums[i] % j == 0) {
                    int f1 = j;
                    int f2 = nums[i] / j;
                    fact[f1] = __gcd(fact[f1], nums[i]);
                    fact[f2] = __gcd(fact[f2], nums[i]);                    
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i <= 200000; i++)
            if(fact[i] == i) res++;
        
        return res;
    }
};
{{< /highlight >}}

