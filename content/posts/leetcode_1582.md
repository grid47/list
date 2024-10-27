
+++
authors = ["Yasir"]
title = "Leetcode 1582: Special Positions in a Binary Matrix"
date = "2020-06-29"
description = "Solution to Leetcode 1582"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size();
        vector<int> row(m, 0), col(n, 0);
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(mat[i][j] == 1) row[i]++, col[j]++;
        }

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
                res++;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}

