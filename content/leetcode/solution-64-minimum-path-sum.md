
+++
authors = ["grid47"]
title = "Leetcode 64: Minimum Path Sum"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 64: Minimum Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-path-sum/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/64.webp" 
    alt="A glowing, winding path that minimizes distance, with bright, guiding arrows showing the best route."
    caption="Solution to LeetCode 64: Minimum Path Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
                 if(i > 0 && j > 0) grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            else if(i > 0) grid[i][j] += grid[i - 1][j];
            else if(j > 0) grid[i][j] += grid[i][j - 1];
        }
        
        return grid[m - 1][n - 1];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/64.md" >}}
---
{{< youtube pGMsrvt0fpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #66: Plus One](https://grid47.xyz/leetcode/solution-66-plus-one/) |
| --- |
