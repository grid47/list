
+++
authors = ["grid47"]
title = "Leetcode 840: Magic Squares In Grid"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 840: Magic Squares In Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "FV52wWrivNc"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/magic-squares-in-grid/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i = 0; i < m -2; i++)
        for(int j = 0; j < n -2; j++)
            if(isMagic(grid, i, j))
             res++;
        return res;
    }

    bool isMagic(vector<vector<int>> &grid, int row, int col) {
        int record[10] = {0};
        for(int i = row; i < row + 3; i++)
        for(int j = col; j < col + 3; j++) {
            if(grid[i][j] < 1 || grid[i][j] > 9 || record[grid[i][j]] > 0)
            return false;
            record[grid[i][j]] = 1;
        }
        int sum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        int sum2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
        if(sum1 != sum2) return false;
        for(int i = 0; i < 3; i++) {
            if(grid[row+i][col] + grid[row+i][col+1]+ grid[row+i][col+2] != sum1)
            return false;
            if(grid[row][col+i] + grid[row+1][col+i]+ grid[row+2][col+i] != sum1)
            return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/840.md" >}}
---
{{< youtube FV52wWrivNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #841: Keys and Rooms](https://grid47.xyz/leetcode/solution-841-keys-and-rooms/) |
| --- |
