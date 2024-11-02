
+++
authors = ["Crafted by Me"]
title = "Leetcode 2364: Count Number of Bad Pairs"
date = "2017-05-13"
description = "Solution to Leetcode 2364"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-number-of-bad-pairs/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long countBadPairs(vector<int>& nums, long cnt = 0) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
            cnt += i - mp[i - nums[i]]++;
        return cnt;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

