
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1572: Matrix Diagonal Sum"
date = "2020-07-10"
description = "Solution to Leetcode 1572"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/matrix-diagonal-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += mat[i][i] + mat[n - 1 - i][i];
        if(n % 2) sum -= mat[n/2][n/2];
        return sum;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

