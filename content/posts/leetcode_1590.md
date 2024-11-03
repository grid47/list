
+++
authors = ["Crafted by Me"]
title = "Leetcode 1590: Make Sum Divisible by P"
date = "2020-06-26"
description = "In-depth solution and explanation for Leetcode 1590: Make Sum Divisible by P in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1591: Strange Printer II](https://grid47.xyz/posts/leetcode_1591) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

