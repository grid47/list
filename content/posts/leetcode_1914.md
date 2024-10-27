
+++
authors = ["Yasir"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2019-08-02"
description = "Solution to Leetcode 1914"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/cyclically-rotating-a-grid/description/)

---

**Code:**

{{< highlight html >}}
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

