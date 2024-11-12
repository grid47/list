
+++
authors = ["grid47"]
title = "Leetcode 1380: Lucky Numbers in a Matrix"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1380: Lucky Numbers in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> row(matrix.size(), 0);
        vector<int> col(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++)
        {
            int m = matrix[i][0];
            for(int j = 1; j < matrix[0].size(); j++) m = min(m, matrix[i][j]);
            row[i] = m;
        }
        for(int j = 0; j < matrix[0].size(); j++)
        {
            int m = matrix[0][j];
            for(int i = 1; i < matrix.size(); i++) m = max(m,matrix[i][j]);
            col[j] = m;
        }
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                if(row[i] == col[j]) res.push_back(row[i]);

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1380.md" >}}
---
{{< youtube ceuQgACqr78 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1381: Design a Stack With Increment Operation](https://grid47.xyz/posts/leetcode-1381-design-a-stack-with-increment-operation-solution/) |
| --- |
