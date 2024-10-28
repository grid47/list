
+++
authors = ["Yasir"]
title = "Leetcode 2733: Neither Minimum nor Maximum"
date = "2017-05-06"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

