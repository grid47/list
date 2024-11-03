
+++
authors = ["Crafted by Me"]
title = "Leetcode 2681: Power of Heroes"
date = "2017-07-01"
description = "In-depth solution and explanation for Leetcode 2681: Power of Heroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

