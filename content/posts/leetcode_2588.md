
+++
authors = ["Crafted by Me"]
title = "Leetcode 2588: Count the Number of Beautiful Subarrays"
date = "2017-10-02"
description = "Solution to Leetcode 2588"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n= nums.size();
        long long cnt = 0;
        map<int, int> mp;
        mp[0] = 1;
        int tmp = 0;
        for(int i = 0; i < n; i++) {
            tmp ^= nums[i];
            if(mp.count(tmp)) cnt+= mp[tmp];
            mp[tmp]++;
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

