
+++
authors = ["grid47"]
title = "Leetcode 1605: Find Valid Matrix Given Row and Column Sums"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1605: Find Valid Matrix Given Row and Column Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "Ks6fGnXkHPg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m ;i++)
        for(int j = 0; j < n; j++) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i]-= ans[i][j];
            colSum[j]-= ans[i][j];
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1605.md" >}}
---
{{< youtube Ks6fGnXkHPg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1609: Even Odd Tree](https://grid47.xyz/leetcode/solution-1609-even-odd-tree/) |
| --- |
