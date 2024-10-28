
+++
authors = ["Yasir"]
title = "Leetcode 1091: Shortest Path in Binary Matrix"
date = "2021-11-03"
description = "Solution to Leetcode 1091"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(grid[0][0] == 1) return -1;
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{0, 1}, {0,-1}, {1, 0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1}};
        q.push(make_pair(0,0));
        grid[0][0] = 1;
        while(!q.empty()) {
            auto p = q.front();
            int x = p.first, y = p.second;
            if(x == m -1 && y == n -1) return grid[x][y];
            
            for(auto d: dir) {
                int i = x + d[0], j = y + d[1];
                if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 0)
                    continue;
                grid[i][j] = grid[x][y] + 1;
                q.push(make_pair(i, j));
            }
            q.pop();
        }
        return -1;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

