
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1329: Sort the Matrix Diagonally"
date = "2021-03-11"
description = "Solution to Leetcode 1329"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sort-the-matrix-diagonally/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            mp[i-j].push(mat[i][j]);

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mat[i][j] = mp[i-j].top();
            mp[i-j].pop();
        }
        return mat;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
