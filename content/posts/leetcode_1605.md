
+++
authors = ["Crafted by Me"]
title = "Leetcode 1605: Find Valid Matrix Given Row and Column Sums"
date = "2020-06-11"
description = "In-depth solution and explanation for Leetcode 1605: Find Valid Matrix Given Row and Column Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1606: Find Servers That Handled Most Number of Requests](https://grid47.xyz/posts/leetcode_1606) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

