
+++
authors = ["grid47"]
title = "Leetcode 2717: Semi-Ordered Permutation"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2717: Semi-Ordered Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/semi-ordered-permutation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n = A.size(), 
        i = find(A.begin(), A.end(), 1) - A.begin(), 
        j = find(A.begin(), A.end(), n) - A.begin();
        return i + n - 1 - j - (i > j);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2717.md" >}}
---
{{< youtube u4bKt4MBHUU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2718: Sum of Matrix After Queries](https://grid47.xyz/posts/leetcode-2718-sum-of-matrix-after-queries-solution/) |
| --- |
