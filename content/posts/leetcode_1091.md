
+++
authors = ["Crafted by Me"]
title = "Leetcode 1091: Shortest Path in Binary Matrix"
date = "2021-11-07"
description = "In-depth solution and explanation for Leetcode 1091: Shortest Path in Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1092: Shortest Common Supersequence ](https://grid47.xyz/posts/leetcode_1092) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

