
+++
authors = ["Crafted by Me"]
title = "Leetcode 576: Out of Boundary Paths"
date = "2023-04-05"
description = "Solution to Leetcode 576"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/out-of-boundary-paths/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = (int) 1e9 + 7;
public:
    int findPaths(int m, int n, int mv, int i, int j) {
        
        vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        
        return dfs(m, n, mv, 0, i, j, mm);
        
    }
    
    int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {

        if (x < 0 || y < 0 || x >= m || y >= n) return 1;
        if (mv == mx)                           return 0;
        if (mm[mv][x][y] > -1)                  return mm[mv][x][y];

        int res = 0;
        res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
        res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;

        return mm[mv][x][y] = (res % mod);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/576.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

