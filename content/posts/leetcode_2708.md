
+++
authors = ["Yasir"]
title = "Leetcode 2708: Maximum Strength of a Group"
date = "2017-05-31"
description = "Solution to Leetcode 2708"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strength-of-a-group/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        
        bool zero = false, allneg = true, allzero = true, pos = false;
        
        int ncnt = 0, pcnt = 0;
        
        long long ans = 1, neg = 1;
        int mxn = -10;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                pcnt++;
                pos = true;
                allzero = false;
                allneg = false;
                ans *= nums[i];
            } else if(nums[i] == 0) {
                zero = true;
            } else {
                ncnt++;
                allzero = false;                
                mxn= max(mxn, nums[i]);
                neg *= nums[i];
            }
        }
        
        if(allzero) return 0;
        
        if(ncnt > 0 && (ncnt %2)) {
            if(pcnt == 0 && ncnt == 1) return zero? 0: neg; 
            neg = neg / mxn;
        }
        

        if(pcnt == 0) {
            return neg;
        }
        
        return ans * neg;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

