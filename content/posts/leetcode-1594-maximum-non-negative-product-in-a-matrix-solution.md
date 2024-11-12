
+++
authors = ["grid47"]
title = "Leetcode 1594: Maximum Non Negative Product in a Matrix"
date = "2024-05-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1594: Maximum Non Negative Product in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    vector<vector<long long>> memo;
    int mod = (int) 1e9 + 7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        
        this->m = grid.size();
        this->n = grid[0].size();
        this->grid = grid;
        
        memo.resize(m, vector<long long>(n, LLONG_MIN));
        
        int ans = dfs(0, 0, 1) % mod;
        
        return ans < 0? -1: ans;
        
    }
    
    long long dfs(int i, int j, long long val) {
        
        if(i == m - 1 && j == n - 1) return (val * grid[i][j]);

        // if(memo[i][j] != LLONG_MIN) return memo[i][j];
        long long ans = LLONG_MIN;
        
        if(grid[i][j] == 0) return 0;
        
        if(i + 1 < m)
        ans = max(ans, dfs(i + 1, j, val * grid[i][j]));

        if(j + 1 < n)            
        ans = max(ans, dfs(i, j + 1, val * grid[i][j]));
        
        // return memo[i][j] = ans;
        return ans;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1594.md" >}}
---
{{< youtube zGDdmRr1YIQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1598: Crawler Log Folder](https://grid47.xyz/posts/leetcode-1598-crawler-log-folder-solution/) |
| --- |
