
+++
authors = ["grid47"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1915: Number of Wonderful Substrings](https://grid47.xyz/posts/leetcode-1915-number-of-wonderful-substrings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}