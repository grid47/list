
+++
authors = ["Crafted by Me"]
title = "Leetcode 1380: Lucky Numbers in a Matrix"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1381: Design a Stack With Increment Operation](https://grid47.xyz/posts/leetcode_1381) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
