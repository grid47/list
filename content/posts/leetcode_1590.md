
+++
authors = ["Crafted by Me"]
title = "Leetcode 1590: Make Sum Divisible by P"
date = "2020-06-25"
description = "Solution to Leetcode 1590"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-sum-divisible-by-p/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        map<int, int> mp;
        mp[0] = -1;
        int n = nums.size(), res = n, cur = 0, need = 0, want = 0;   
        
        for(int a : nums)
            need = (need + a) % p;

        for(int i = 0; i < n; i++) {

            cur = (cur + nums[i]) % p;
            mp[cur] = i;
            want = (cur - need + p) % p;

            if (mp.count(want))
            res = min(res, i - mp[want]);

        }

        return res < n? res : -1;
    }

};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

