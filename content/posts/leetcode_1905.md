
+++
authors = ["Yasir"]
title = "Leetcode 1905: Count Sub Islands"
date = "2019-08-12"
description = "Solution to Leetcode 1905"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-sub-islands/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m =grid2.size(), n = grid2[0].size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 1)
                dfs(grid2, i, j);
        
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 2)
                res += find(grid1, grid2, i, j);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& grid2, int i, int j) {

        int m = grid2.size(), n = grid2[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;

        grid2[i][j] = 2;

        dfs(grid2, i, j + 1);
        dfs(grid2, i + 1, j);
        dfs(grid2, i - 1, j);
        dfs(grid2, i, j - 1);

    }

    bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid2.size(), n = grid2[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;

        bool res = true;
        if (grid1[i][j] != 1) res = false;

        grid2[i][j] = 3;

        res &= find(grid1, grid2, i, j + 1);
        res &= find(grid1, grid2, i + 1, j);
        res &= find(grid1, grid2, i - 1, j);
        res &= find(grid1, grid2, i, j - 1);

        return res;
    }

};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

