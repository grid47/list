
+++
authors = ["grid47"]
title = "Leetcode 1300: Sum of Mutated Array Closest to Target"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1300: Sum of Mutated Array Closest to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        
        int n = A.size(), i = 0;
        while(i < n && target > A[i] * (n - i)) {
            target -= A[i++];
        }
        
        if (i == n) return A[n - 1];
        
        int res = target / (n - i);
        
        if (target - res * (n - i) > (res + 1) * (n - i) - target)
            res++;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1300.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1302: Deepest Leaves Sum](https://grid47.xyz/leetcode/solution-1302-deepest-leaves-sum/) |
| --- |
