
+++
authors = ["grid47"]
title = "Leetcode 1329: Sort the Matrix Diagonally"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1329: Sort the Matrix Diagonally in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "0FheWgwnG-w"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1329.md" >}}
---
{{< youtube 0FheWgwnG-w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1333: Filter Restaurants by Vegan-Friendly, Price and Distance](https://grid47.xyz/leetcode/solution-1333-filter-restaurants-by-vegan-friendly-price-and-distance/) |
| --- |
