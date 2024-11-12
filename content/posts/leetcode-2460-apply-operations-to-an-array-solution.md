
+++
authors = ["grid47"]
title = "Leetcode 2460: Apply Operations to an Array"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2460: Apply Operations to an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/apply-operations-to-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<int> applyOperations(vector<int>& A) {
    for (int i = 0, j = 0; i < size(A); ++i){
        if (i + 1 < size(A) and A[i] == A[i + 1]){
            A[i] *= 2;
            A[i + 1] = 0;
        }
        if (A[i]) swap(A[j++], A[i]);
    }   
    return A;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2460.md" >}}
---
{{< youtube SykhaokFEIM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2461: Maximum Sum of Distinct Subarrays With Length K](https://grid47.xyz/posts/leetcode-2461-maximum-sum-of-distinct-subarrays-with-length-k-solution/) |
| --- |
