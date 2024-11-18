
+++
authors = ["grid47"]
title = "Leetcode 2850: Minimum Moves to Spread Stones Over Grid"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2850: Minimum Moves to Spread Stones Over Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        // Base Case
        int t = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (grid[i][j] == 0)
                    t++;
        if (t == 0)
            return 0;
        
        int ans = INT_MAX;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (grid[i][j] == 0)
                {
                    for (int ni = 0; ni < 3; ++ni)
                    {
                        for (int nj = 0; nj < 3; ++nj)
                        {
                            int d = abs(ni - i) + abs(nj - j);
                            if (grid[ni][nj] > 1)
                            {
                                grid[ni][nj]--;
                                grid[i][j]++;
                                ans = min(ans, d + minimumMoves(grid));
                                grid[ni][nj]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2850.md" >}}
---
{{< youtube __h7BgcH_Cs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2855: Minimum Right Shifts to Sort the Array](https://grid47.xyz/leetcode/solution-2855-minimum-right-shifts-to-sort-the-array/) |
| --- |
