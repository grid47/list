
+++
authors = ["grid47"]
title = "Leetcode 1351: Count Negative Numbers in a Sorted Matrix"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1351: Count Negative Numbers in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, m = grid.size();
        for(int i = 0; i < m; i++) {
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            if(*grid[i].rbegin() > -1) continue;
            res += it - grid[i].rbegin();
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1351.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1352: Product of the Last K Numbers](https://grid47.xyz/leetcode/solution-1352-product-of-the-last-k-numbers/) |
| --- |
