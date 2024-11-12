
+++
authors = ["grid47"]
title = "Leetcode 1139: Largest 1-Bordered Square"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1139: Largest 1-Bordered Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-1-bordered-square/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> top(m, vector<int>(n, 0)), left(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] > 0) {
                top[i][j] = i > 0? 1 + top[i - 1][j]: 1;
                left[i][j] = j > 0? 1 + left[i][j - 1]: 1;
            }
        
        for(int l = min(m, n); l >= 1; l--) {
            for(int i = 0; i < m - l + 1; i++)
            for(int j = 0; j < n - l + 1; j++)
                if(top[i + l - 1][j] >= l &&
                   top[i + l - 1][j + l - 1] >= l &&
                  left[i][j + l - 1] >= l &&
                  left[i + l - 1][j + l - 1] >= l)
                    return l * l;
        }
        return 0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1139.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1140: Stone Game II](https://grid47.xyz/posts/leetcode-1140-stone-game-ii-solution/) |
| --- |
