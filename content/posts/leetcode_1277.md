
+++
authors = ["Crafted by Me"]
title = "Leetcode 1277: Count Square Submatrices with All Ones"
date = "2021-05-05"
description = "In-depth solution and explanation for Leetcode 1277: Count Square Submatrices with All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] && i && j)
            matrix[i][j] += min({matrix[i - 1][j], matrix[i -1][j-1], matrix[i][j -1]});
            res += matrix[i][j];
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1277.md" >}}
---
{{< youtube PBZCmMugu5Q >}}
| Next : [LeetCode #1278: Palindrome Partitioning III](https://grid47.xyz/posts/leetcode_1278) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

