
+++
authors = ["Crafted by Me"]
title = "Leetcode 1329: Sort the Matrix Diagonally"
date = "2021-03-14"
description = "In-depth solution and explanation for Leetcode 1329: Sort the Matrix Diagonally in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1329.md" >}}
---

| Next : [LeetCode #1330: Reverse Subarray To Maximize Array Value](https://grid47.xyz/posts/leetcode_1330) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

