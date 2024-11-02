
+++
authors = ["Crafted by Me"]
title = "Leetcode 2733: Neither Minimum nor Maximum"
date = "2016-05-09"
description = "Solution to Leetcode 2733"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/neither-minimum-nor-maximum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNonMinOrMax(vector<int>& A) {
        if (A.size() < 3)
            return -1;
        int mx = max(A[0], max(A[1], A[2])), mn = min(A[0], min(A[1], A[2]));
        for (int i = 0; i < 3; ++i)
            if (mn < A[i] && A[i] < mx)
                return A[i];
        return -1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

