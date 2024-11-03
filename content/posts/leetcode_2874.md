
+++
authors = ["Crafted by Me"]
title = "Leetcode 2874: Maximum Value of an Ordered Triplet II"
date = "2016-12-20"
description = "In-depth solution and explanation for Leetcode 2874: Maximum Value of an Ordered Triplet II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, n = nums.size();
        long maxa = 0, maxab = 0;
        for(int a: nums) {
            res = max(res, 1L * maxab * a);
            maxab = max(maxab, (long) maxa - a);
            maxa = max(maxa, (long)a);
        }
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

