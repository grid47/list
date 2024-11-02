
+++
authors = ["Crafted by Me"]
title = "Leetcode 2527: Find Xor-Beauty of Array"
date = "2016-12-01"
description = "Solution to Leetcode 2527"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-xor-beauty-of-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        
        int tmp = 0;
        for(int it: nums)
            tmp ^= it;
        return tmp;
        
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

