
+++
authors = ["Crafted by Me"]
title = "Leetcode 542: 01 Matrix"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 542: 01 Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #543: Diameter of Binary Tree](https://grid47.xyz/posts/leetcode_543) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
