
+++
authors = ["grid47"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2024-04-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1914: Cyclically Rotating a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cyclically-rotating-a-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        // cout << m << " " << n;
        // k = k % (m * n);
        for(int i = 0; i < min(m, n) / 2; i++) {            


            int l = i + 0, r = n - 1 - i;
            int t = i + 0, b = m - 1 - i;

            int total = 2 * (r - l) + 2 * (b - t);
            int rot = k % total;
            if(l < r && t < b) {

                for(int j = 0; j < rot; j++) {

                    int tmp = grid[t][l];
                    for(int p = l; p < r; p++)
                        grid[t][p] = grid[t][p + 1];

                    for(int p = t; p < b; p++)
                        grid[p][r] = grid[p + 1][r];

                    for(int p = r; p > l; p--)
                        grid[b][p] = grid[b][p-1];

                    for(int p = b; p > t; p--)
                        grid[p][l] = grid[p-1][l];

                    grid[t + 1][l] = tmp;
                }

            }
        }
        return grid;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1914.md" >}}
---
{{< youtube 3dCs1ZHDNjM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1915: Number of Wonderful Substrings](https://grid47.xyz/posts/leetcode-1915-number-of-wonderful-substrings-solution/) |
| --- |
