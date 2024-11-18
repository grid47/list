
+++
authors = ["grid47"]
title = "Leetcode 1277: Count Square Submatrices with All Ones"
date = "2024-07-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1277: Count Square Submatrices with All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1282: Group the People Given the Group Size They Belong To](https://grid47.xyz/leetcode/solution-1282-group-the-people-given-the-group-size-they-belong-to/) |
| --- |
