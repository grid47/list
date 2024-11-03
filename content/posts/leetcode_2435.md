
+++
authors = ["Crafted by Me"]
title = "Leetcode 2435: Paths in Matrix Whose Sum Is Divisible by K"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2435: Paths in Matrix Whose Sum Is Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<vector<int>>> memo;    
    vector<vector<int>> grid;
    int m, n, k;
    int mod = (int) 1e9 + 7;
    
    int dp(int i, int j, int sum) {
        
        if((i == (m - 1)) && (j == (n - 1))) return (sum % k) == 0;
        
        if(memo[i][j][sum] != -1) return memo[i][j][sum];
        
        long long ans = 0;
        if(i + 1 < m) ans += dp(i + 1, j, (sum + grid[i + 1][j]) % k);
        if(j + 1 < n) ans += dp(i, j + 1, (sum + grid[i][j + 1]) % k);        
        
        return memo[i][j][sum] = ans % mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        this->k = k;
        memo.resize(m, vector<vector<int>>(n, vector<int>(50, -1)));
        
        return dp(0, 0, grid[0][0] % k);
        
    }
};
{{< /highlight >}}


---
{{< youtube YG02DVAh5gQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2436: Minimum Split Into Subarrays With GCD Greater Than One](https://grid47.xyz/posts/leetcode_2436) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

