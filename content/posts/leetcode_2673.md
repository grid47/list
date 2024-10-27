
+++
authors = ["Yasir"]
title = "Leetcode 2673: Make Costs of Paths Equal in a Binary Tree"
date = "2017-07-04"
description = "Solution to Leetcode 2673"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minIncrements(int n, vector<int>& A) {
        int res = 0;
        for (int i = n / 2 - 1; i >= 0; --i) {
            int l = i * 2 + 1, r = i * 2 + 2;
            res += abs(A[l] - A[r]);
            A[i] += max(A[l], A[r]);
        }
        return res;
    }
};
{{< /highlight >}}

