
+++
authors = ["Crafted by Me"]
title = "Leetcode 2540: Minimum Common Value"
date = "2016-11-18"
description = "Solution to Leetcode 2540"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-common-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        for(int x: nums1)
            mp[x] = true;
        for(int y: nums2)
            if(mp.count(y))
                return y;
        return -1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

