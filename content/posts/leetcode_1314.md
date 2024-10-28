
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1314: Matrix Block Sum"
date = "2021-03-25"
description = "Solution to Leetcode 1314"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/matrix-block-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

        for(int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++)
        sum[i][j] = mat[i - 1][j - 1] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        
        vector<vector<int>> res(m, vector<int>(n));

        for(int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++) {

            int r1 = min(i + k, m);
            int c1 = min(j + k, n);
            int r2 = max(i - k, 1);
            int c2 = max(j - k, 1);

            res[i - 1][j - 1] = sum[r1][c1] - sum[r1][c2 - 1] - sum[r2 - 1][c1] + sum[r2 - 1][c2 - 1];

        }
        
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

