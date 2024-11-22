
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
img_src = ""
youtube = "FV52wWrivNc"
youtube_upload_date="2024-08-09"
youtube_thumbnail="https://i.ytimg.com/vi/FV52wWrivNc/maxresdefault.jpg"
+++



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
---

### Problem Statement

The problem asks to find the number of "magic squares" within a given 2D grid. A "magic square" is defined as a 3x3 subgrid that contains all numbers from 1 to 9 exactly once, and where the sums of the numbers in every row, column, and both diagonals are the same.

Given an `m x n` grid, the goal is to determine how many 3x3 subgrids within the grid form a magic square. If a 3x3 subgrid meets the criteria of a magic square, it is counted. The problem requires us to implement an efficient solution to check all possible 3x3 subgrids in the grid.

### Approach

To solve this problem, we need to check each possible 3x3 subgrid in the given grid to see if it meets the conditions of a magic square. Here's how we approach the solution:

1. **Iterate Over Possible 3x3 Subgrids**: The first step is to iterate through all possible top-left corners of the 3x3 subgrids. Since a magic square is a 3x3 grid, we can only check subgrids that start from any position within the first `m-2` rows and the first `n-2` columns.

2. **Magic Square Validity Check**: For each potential 3x3 subgrid, we must verify that:
   - All numbers in the 3x3 subgrid are distinct and between 1 and 9.
   - The sum of the rows, columns, and both diagonals must be equal.

3. **Tracking the Numbers**: A simple way to track the numbers in the 3x3 subgrid is to use an array (or hash map) to ensure that each number from 1 to 9 appears exactly once.

4. **Check Row, Column, and Diagonal Sums**: For each 3x3 subgrid, we calculate the sum of each row, each column, and the two diagonals, and ensure that they are all equal.

5. **Count the Valid Magic Squares**: For each valid magic square found, we increment the count. Finally, we return the total number of magic squares found in the grid.

### Code Breakdown (Step by Step)

1. **Function Signature**:
   ```cpp
   int numMagicSquaresInside(vector<vector<int>>& grid)
   ```
   This function takes a 2D grid as input and returns the number of magic squares inside the grid.

2. **Iterating Over the Grid**:
   ```cpp
   int m = grid.size(), n = grid[0].size();
   int res = 0;
   for (int i = 0; i < m - 2; i++)
       for (int j = 0; j < n - 2; j++)
           if (isMagic(grid, i, j))
               res++;
   return res;
   ```
   - We first calculate the dimensions `m` and `n` of the grid.
   - We initialize a counter `res` to track the number of valid magic squares.
   - Using two nested loops, we iterate through all possible 3x3 subgrids. The outer loops run from `i = 0` to `i = m-3` (for rows) and from `j = 0` to `j = n-3` (for columns).
   - For each potential 3x3 subgrid, we call the helper function `isMagic(grid, i, j)` to check if it is a valid magic square.

3. **Magic Square Validation**:
   ```cpp
   bool isMagic(vector<vector<int>>& grid, int row, int col) {
       int record[10] = {0};
       for (int i = row; i < row + 3; i++)
           for (int j = col; j < col + 3; j++) {
               if (grid[i][j] < 1 || grid[i][j] > 9 || record[grid[i][j]] > 0)
                   return false;
               record[grid[i][j]] = 1;
           }
       int sum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
       int sum2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
       if (sum1 != sum2) return false;
       for (int i = 0; i < 3; i++) {
           if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum1)
               return false;
           if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum1)
               return false;
       }
       return true;
   }
   ```
   - **Tracking Distinct Numbers**: We use an array `record[10]` to track which numbers have already appeared in the current 3x3 subgrid. If any number appears more than once or if any number is outside the range 1 to 9, the subgrid cannot be a magic square.
   - **Sum Validation**: We calculate the sum of the two diagonals (`sum1` and `sum2`) and compare them. If they are not equal, the subgrid cannot be a magic square.
   - **Row and Column Sum Check**: Finally, we check the sum of each row and each column of the 3x3 subgrid. If any of the sums do not match the sum of the diagonals, the subgrid is not a magic square.
   - If all the checks pass, we return `true`, indicating that the 3x3 subgrid is a magic square.

4. **Returning the Result**:
   After iterating through all potential 3x3 subgrids, we return the value of `res`, which holds the count of valid magic squares found in the grid.

### Complexity

1. **Time Complexity**:
   - The outer loops iterate over all possible top-left corners of 3x3 subgrids. Since there are `(m-2) * (n-2)` such subgrids, the time complexity of the outer loops is O(m * n).
   - For each subgrid, we perform a constant amount of work: checking the numbers, calculating the sums of rows, columns, and diagonals. This takes O(1) time for each subgrid.
   - Therefore, the overall time complexity is O(m * n), where `m` and `n` are the dimensions of the grid.

2. **Space Complexity**:
   - The space complexity is O(1) because we use only a fixed amount of extra space (`record[10]`) to track the numbers in the current 3x3 subgrid, and no additional data structures are used.

### Conclusion

In conclusion, the provided solution efficiently counts the number of magic squares inside a 2D grid by iterating over all possible 3x3 subgrids and validating each one. The use of the `record` array ensures that we only count distinct numbers from 1 to 9, and the row, column, and diagonal sum checks guarantee that the subgrid meets the magic square criteria. With a time complexity of O(m * n) and constant space complexity, this approach is both time-efficient and space-efficient for solving the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/magic-squares-in-grid/description/)

---
{{< youtube FV52wWrivNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
