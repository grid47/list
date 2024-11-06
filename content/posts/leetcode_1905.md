
+++
authors = ["Crafted by Me"]
title = "Leetcode 1905: Count Sub Islands"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1905: Count Sub Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-sub-islands/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m =grid2.size(), n = grid2[0].size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 1)
                dfs(grid2, i, j);
        
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 2)
                res += find(grid1, grid2, i, j);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& grid2, int i, int j) {

        int m = grid2.size(), n = grid2[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;

        grid2[i][j] = 2;

        dfs(grid2, i, j + 1);
        dfs(grid2, i + 1, j);
        dfs(grid2, i - 1, j);
        dfs(grid2, i, j - 1);

    }

    bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid2.size(), n = grid2[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;

        bool res = true;
        if (grid1[i][j] != 1) res = false;

        grid2[i][j] = 3;

        res &= find(grid1, grid2, i, j + 1);
        res &= find(grid1, grid2, i + 1, j);
        res &= find(grid1, grid2, i - 1, j);
        res &= find(grid1, grid2, i, j - 1);

        return res;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1905.md" >}}
---
{{< youtube mLpW3qfbNJ8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1906: Minimum Absolute Difference Queries](https://grid47.xyz/posts/leetcode_1906) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
