
+++
authors = ["grid47"]
title = "Leetcode 130: Surrounded Regions"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 130: Surrounded Regions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/surrounded-regions/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/130.webp" 
    alt="A grid of cells gently surrounded by a calming border of light, with certain areas being 'captured."
    caption="Solution to LeetCode 130: Surrounded Regions Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube 9z2BunfoZ5Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #131: Palindrome Partitioning](https://grid47.xyz/posts/leetcode-131-palindrome-partitioning-solution/) |
| --- |
