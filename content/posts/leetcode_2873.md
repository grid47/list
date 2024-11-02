
+++
authors = ["Crafted by Me"]
title = "Leetcode 2873: Maximum Value of an Ordered Triplet I"
date = "2016-12-21"
description = "Solution to Leetcode 2873"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, mxa = 0, mxab = 0;
        for(long a: nums) {
            res = max(res, mxab * a);
            mxab = max(mxab, mxa - a);
            mxa = max(mxa, a);
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

