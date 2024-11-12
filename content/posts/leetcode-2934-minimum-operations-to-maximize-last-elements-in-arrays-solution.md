
+++
authors = ["grid47"]
title = "Leetcode 2934: Minimum Operations to Maximize Last Elements in Arrays"
date = "2024-01-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2934: Minimum Operations to Maximize Last Elements in Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-maximize-last-elements-in-arrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& A, vector<int>& B) {
        int dp1 = 0, dp2 = 0, n = A.size(), mi = min(A[n - 1], B[n - 1]), ma = max(A[n - 1], B[n - 1]);
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            if (max(a, b) > ma) return -1;
            if (min(a, b) > mi) return -1;
            if (a > A[n - 1] || b > B[n - 1]) dp1++;
            if (a > B[n - 1] || b > A[n - 1]) dp2++;
        }
        return min(dp1, dp2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2934.md" >}}
---
{{< youtube 5eDemRe02LM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2937: Make Three Strings Equal](https://grid47.xyz/posts/leetcode-2937-make-three-strings-equal-solution/) |
| --- |
