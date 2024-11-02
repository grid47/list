
+++
authors = ["Crafted by Me"]
title = "Leetcode 2799: Count Complete Subarrays in an Array"
date = "2017-03-05"
description = "Solution to Leetcode 2799"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        set<int> dist;
        map<int, int> mp;
        for(int x: nums)
            dist.insert(x);
        int cur = 0, req = dist.size();
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp.size() < req) continue;
            while(mp.size() >= req) {
                cnt+= (n - i);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

