
+++
authors = ["Crafted by Me"]
title = "Leetcode 1277: Count Square Submatrices with All Ones"
date = "2021-05-04"
description = "Solution to Leetcode 1277"
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



---

{{< youtube PBZCmMugu5Q >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

