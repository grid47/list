
+++
authors = ["grid47"]
title = "Leetcode 1091: Shortest Path in Binary Matrix"
date = "2024-07-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1091: Shortest Path in Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1091.md" >}}
---
{{< youtube U3VJjmvRVLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1093: Statistics from a Large Sample](https://grid47.xyz/posts/leetcode-1093-statistics-from-a-large-sample-solution/) |
| --- |
