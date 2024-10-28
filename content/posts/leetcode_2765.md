
+++
authors = ["Yasir"]
title = "Leetcode 2765: Longest Alternating Subarray"
date = "2017-04-04"
description = "Solution to Leetcode 2765"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-alternating-subarray/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int alternatingSubarray(vector<int>& A) {
        int n = A.size(), res = 0, j = 0;
        for (int i = 0; i < n; ++i)
            for (j = i + 1; j < n && A[j] == A[i] + (j - i) % 2; ++j)
                res = max(res, j - i + 1);
        return res > 1 ? res : -1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

