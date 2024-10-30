
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2482: Difference Between Ones and Zeros in Row and Column"
date = "2018-01-14"
description = "Solution to Leetcode 2482"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/)

---
{{< youtube JwuTsHDJVdI >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }

        vector<vector<int>> g(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            g[i][j] = 2 * row[i] + 2 * col[j] - m - n;
        }
        return g;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

