
+++
authors = ["Crafted by Me"]
title = "Leetcode 3046: Split the Array"
date = "2015-07-01"
description = "Solution to Leetcode 3046"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-the-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > 2) return false;
        }
        return true;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

