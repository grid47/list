
+++
authors = ["Yasir"]
title = "Leetcode 1605: Find Valid Matrix Given Row and Column Sums"
date = "2020-06-06"
description = "Solution to Leetcode 1605"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/)

---

**Code:**

{{< highlight html >}}
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

