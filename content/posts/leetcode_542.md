
+++
authors = ["Crafted by Me"]
title = "Leetcode 542: 01 Matrix"
date = "2023-05-09"
description = "Solution to Leetcode 542"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/01-matrix/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] == 0)
            q.push({i, j});
        
        int dis = 0;
        vector<vector<int>> vis;
        vis.resize(m, vector<int>(n, 0));
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();                
                if(vis[it[0]][it[1]]) continue;
                mat[it[0]][it[1]] = dis;
                vis[it[0]][it[1]] = 1;

                for(int i = 0; i < 4; i++) {
                    int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n)
                        continue;
                    if(!vis[x][y])
                        q.push({x, y});
                }
            }
            dis++;
        }
        return mat;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/542.md" >}}
---
{{< youtube 1xuLfxgT7yo >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

