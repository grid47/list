
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 130: Surrounded Regions"
date = "2024-06-23"
description = "Solution to Leetcode 130"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/surrounded-regions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1|| j == n -1)
                if(board[i][j] == 'O')
                    dfs(board, i, j);
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == '1')
                board[i][j] = 'O';
        
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || 
           j == grid[0].size() || grid[i][j] != 'O')
            return;
        grid[i][j] = '1';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/130.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

