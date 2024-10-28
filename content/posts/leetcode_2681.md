
+++
authors = ["Yasir"]
title = "Leetcode 2681: Power of Heroes"
date = "2017-06-27"
description = "Solution to Leetcode 2681"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/power-of-heroes/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
                
        sort(nums.begin(), nums.end());
        
        
        int n = nums.size();
        long long res = 0, sum = 0, mod = (int) 1e9 + 7;
        
        for(int i = 0; i < n; i++) {
            res = (res + (sum + nums[i]) * nums[i] % mod * nums[i]) % mod;
            sum = (sum * 2 + nums[i]) % mod;
        }
        
        return res % mod;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

