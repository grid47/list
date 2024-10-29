
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 867: Transpose Matrix"
date = "2022-06-16"
description = "Solution to Leetcode 867"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/transpose-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> A) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> B(N, vector<int>(M, 0));
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                B[j][i] = A[i][j];
        return B;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/867.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

