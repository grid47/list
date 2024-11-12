
+++
authors = ["grid47"]
title = "Leetcode 2245: Maximum Trailing Zeros in a Cornered Path"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2245: Maximum Trailing Zeros in a Cornered Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/)

---
**Code:**

{{< highlight cpp >}}
array<int, 2> operator+(const array<int, 2> &r1, const array<int, 2> &r2) { return { r1[0] + r2[0], r1[1] + r2[1] }; }

array<int, 2> operator-(const array<int, 2> &r1, const array<int, 2> &r2) { return { r1[0] - r2[0], r1[1] - r2[1] }; }

int pairs (const array<int, 2> &p) { return min(p[0], p[1]); }

class Solution {
public:
    int fact(int i, int j) {
        return i % j ? 0 : 1 + fact(i/j, j);
    }
    
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        
        vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m+1, vector<array<int, 2>>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int t = grid[i][j];
                array<int, 2> node = { fact(t, 2), fact(t, 5) };
                h[i][j + 1] = h[i][j] + node;
                v[i + 1][j] = v[i][j] + node;
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                array<int, 2> h1 = h[i][j], 
                h2 = h[i][n] - h[i][j+1],
                v1 = v[i+1][j],
                v2 = v[m][j] - v[i][j];
                res = max({res, pairs(v1+h1), pairs(v1+h2), pairs(v2+h1), pairs(v2+h2)});
                
            }
            }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2245.md" >}}
---
{{< youtube QMRHGd9ftz8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2246: Longest Path With Different Adjacent Characters](https://grid47.xyz/posts/leetcode-2246-longest-path-with-different-adjacent-characters-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
