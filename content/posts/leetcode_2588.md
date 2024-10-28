
+++
authors = ["Yasir"]
title = "Leetcode 2588: Count the Number of Beautiful Subarrays"
date = "2017-09-28"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

