
+++
authors = ["Crafted by Me"]
title = "Leetcode 2658: Maximum Number of Fish in a Grid"
date = "2017-07-24"
description = "In-depth solution and explanation for Leetcode 2658: Maximum Number of Fish in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---


| Next : [LeetCode #2659: Make Array Empty](grid47.xyz/leetcode_2659) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

