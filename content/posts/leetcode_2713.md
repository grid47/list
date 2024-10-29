
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2713: Maximum Strictly Increasing Cells in a Matrix"
date = "2017-05-27"
description = "Solution to Leetcode 2713"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    int maxIncreasingCells(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();

        vector<int> row(m, 0), col(n, 0);
        
        map<int, vector<vector<int>>> mp;
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        set<int> item;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            mp[-mat[i][j]].push_back({i, j});
            item.insert(-mat[i][j]);
        }
        
        for(int x : item) {
            
            for(auto v: mp[x]) {
                tmp[v[0]][v[1]] = max(row[v[0]], col[v[1]]) + 1;
            }
            
            for(auto v: mp[x]) {
                row[v[0]] = max(row[v[0]], tmp[v[0]][v[1]]);
                col[v[1]] = max(col[v[1]], tmp[v[0]][v[1]]);                
            }
            
        }
        
        return max(*max_element(row.begin(), row.end()), *max_element(col.begin(), col.end()));
    }    
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

