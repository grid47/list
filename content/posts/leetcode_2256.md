
+++
authors = ["Yasir"]
title = "Leetcode 2256: Minimum Average Difference"
date = "2018-08-25"
description = "Solution to Leetcode 2256"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-average-difference/description/)

---

**Code:**

{{< highlight html >}}

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        typedef long long ll;
        
        ll sum = 0;
        for(int a : nums) sum += a;

        ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
        ll l = 0, r = sum;
        for(int i = 0; i < n; i++) {
            int prv = res;
            l += nums[i];
            r -= nums[i];      
            la = l / (i + 1);
            ra = (i+1==n)?0:r / (n-(i+1));
            res = min(res, abs(la - ra));
            if(prv != res) ret = i;
        }
        return ret;            
    }
};
{{< /highlight >}}

