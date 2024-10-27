
+++
authors = ["Yasir"]
title = "Leetcode 1594: Maximum Non Negative Product in a Matrix"
date = "2020-06-17"
description = "Solution to Leetcode 1594"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/)

---

**Code:**

{{< highlight html >}}
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

