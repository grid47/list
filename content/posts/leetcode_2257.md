
+++
authors = ["Crafted by Me"]
title = "Leetcode 2257: Count Unguarded Cells in the Grid"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2257: Count Unguarded Cells in the Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for(auto it: walls) {
            grid[it[0]][it[1]] = 1;
        }
        
        for(auto it: guards) {
            grid[it[0]][it[1]] = 3;
        }        
        
        for(auto it: guards) {
            int x = it[0], y = it[1];
            
            for(int i = y + 1; i < n && grid[x][i] != 1 && grid[x][i] != 3; i++) {
                grid[x][i] = 2;
            }
            
            for(int i = y - 1; i >=0 && grid[x][i] != 1 && grid[x][i] != 3; i--) {
                grid[x][i] = 2;
            }            
            
            for(int i = x + 1; i < m && grid[i][y] != 1 && grid[i][y] != 3; i++) {
                grid[i][y] = 2;
            }
            
            for(int i = x - 1; i >= 0 && grid[i][y] != 1 && grid[i][y] != 3; i--) {
                grid[i][y] = 2;
            }
            // grid[x][y] = 3;
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 0) cnt++;
        
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2257.md" >}}
---
{{< youtube V4jbxAhIHJw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2259: Remove Digit From Number to Maximize Result](https://grid47.xyz/posts/leetcode_2259) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
