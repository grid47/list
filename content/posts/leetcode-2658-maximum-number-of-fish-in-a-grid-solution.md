
+++
authors = ["grid47"]
title = "Leetcode 2658: Maximum Number of Fish in a Grid"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2658: Maximum Number of Fish in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> grid;
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        this->grid = grid;
        int mx = 0;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != 0) {
                mx = max(mx, dfs(i, j));
            }
        return mx;
    }
    
    int dfs(int i, int j) {
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
        int ans = grid[i][j];
        grid[i][j] = 0;
        
        ans += dfs(i + 1, j);
        ans += dfs(i - 1, j);
        ans += dfs(i, j + 1);
        ans += dfs(i, j - 1);
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2658.md" >}}
---
{{< youtube qn2ABHbRNnQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2660: Determine the Winner of a Bowling Game](https://grid47.xyz/posts/leetcode-2660-determine-the-winner-of-a-bowling-game-solution/) |
| --- |
