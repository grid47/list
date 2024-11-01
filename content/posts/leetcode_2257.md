
+++
authors = ["Crafted by Me"]
title = "Leetcode 2257: Count Unguarded Cells in the Grid"
date = "2018-08-29"
description = "Solution to Leetcode 2257"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

