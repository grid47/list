
+++
authors = ["grid47"]
title = "Leetcode 2735: Collecting Chocolates"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2735: Collecting Chocolates in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/collecting-chocolates/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minCost(vector<int>& A, int x) {
        int n = A.size();
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] += 1L * i * x;
            int cur = A[i];
            for (int k = 0; k < n; k++) {
                cur = min(cur, A[(i - k + n) % n]);
                res[k] += cur;
            }
        }
        return *std::min_element(res.begin(), res.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2735.md" >}}
---
{{< youtube FPkaxgatwoI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2739: Total Distance Traveled](https://grid47.xyz/posts/leetcode-2739-total-distance-traveled-solution/) |
| --- |
