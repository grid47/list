
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 840: Magic Squares In Grid"
date = "2022-07-14"
description = "Solution to Leetcode 840"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

