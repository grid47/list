
+++
authors = ["Crafted by Me"]
title = "Leetcode 934: Shortest Bridge"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 934: Shortest Bridge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-bridge/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool flag = false;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(i, j, q, grid);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        int step = 0;
        int dir[5] = {0,1,0,-1,0};
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = p.first + dir[i], y = p.second + dir[i+1];
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
                        continue;
                    if(grid[x][y] == 1) return step;
                    q.push({x, y});
                    grid[x][y] = -1;
                }
            }
            step++;
        }
        return -1;
    }
    
    void dfs(int x, int y, queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return;
        q.push(make_pair(x, y));
        grid[x][y] = -1;
        dfs(x + 1, y, q, grid);
        dfs(x - 1, y, q, grid);
        dfs(x, y + 1, q, grid);
        dfs(x, y - 1, q, grid);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/934.md" >}}
---
{{< youtube 1RZijG2c1CA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #935: Knight Dialer](https://grid47.xyz/posts/leetcode_935) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
