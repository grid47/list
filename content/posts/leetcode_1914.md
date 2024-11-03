
+++
authors = ["Crafted by Me"]
title = "Leetcode 1914: Cyclically Rotating a Grid"
date = "2019-08-07"
description = "In-depth solution and explanation for Leetcode 1914: Cyclically Rotating a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


"| 1915: Number of Wonderful Substrings |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

