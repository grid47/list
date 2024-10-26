
+++
authors = ["Yasir"]
title = "Leetcode 994: Rotting Oranges"
date = "2022-02-06"
description = "Solution to Leetcode 994"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotting-oranges/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int t = 0;
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();
                if(vis[it[0]][it[1]]) continue;
                vis[it[0]][it[1]] = 1;
                for(int i = 0; i < 4; i++) {
                    int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n || vis[x][y] || grid[x][y] != 1)
                        continue;
                    grid[x][y] = grid[it[0]][it[1]] + 1;
                    q.push({x, y});
                }
            }
        }
        int mx = 2;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] > mx) mx = grid[i][j];
            else if(grid[i][j] == 1) return -1;
        return mx - 2;
    }
};
{{< /highlight >}}

