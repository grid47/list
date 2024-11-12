
+++
authors = ["grid47"]
title = "Leetcode 200: Number of Islands"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 200: Number of Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-islands/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/200.webp" 
    alt="A map of glowing islands floating gently, with the number of islands appearing as a soft count."
    caption="Solution to LeetCode 200: Number of Islands Problem"
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
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == '1') {
                cnt++;
                dfs(grid, i, j);
            }
        return cnt;
    }
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/200.md" >}}
---
{{< youtube IeuyI_kZ5zI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #201: Bitwise AND of Numbers Range](https://grid47.xyz/posts/leetcode-201-bitwise-and-of-numbers-range-solution/) |
| --- |
