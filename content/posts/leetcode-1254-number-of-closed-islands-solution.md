
+++
authors = ["grid47"]
title = "Leetcode 1254: Number of Closed Islands"
date = "2024-07-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1254: Number of Closed Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-closed-islands/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
                if(grid[i][j] == 0)
                    dfs(grid, i, j, 0, 1);
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 0) {
                dfs(grid, i, j, 0, cnt + 2);
                    cnt++;
            }
        return cnt;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int cur, int tgt) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i == m || j == n || grid[i][j] != cur)
            return;
        grid[i][j] = tgt;
        dfs(grid, i + 1, j, cur, tgt);
        dfs(grid, i, j + 1, cur, tgt);
        dfs(grid, i - 1, j, cur, tgt);
        dfs(grid, i, j - 1, cur, tgt);
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1254.md" >}}
---
{{< youtube ZH8TeWFYpx8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1261: Find Elements in a Contaminated Binary Tree](https://grid47.xyz/posts/leetcode-1261-find-elements-in-a-contaminated-binary-tree-solution/) |
| --- |
