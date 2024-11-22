
+++
authors = ["grid47"]
title = "Leetcode 419: Battleships in a Board"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 419: Battleships in a Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp"
youtube = "gKhvVHd8ihI"
youtube_upload_date="2020-07-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gKhvVHd8ihI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp" 
    alt="A board game where ships glow softly as they are placed on the grid, each ship highlighted as it is positioned."
    caption="Solution to LeetCode 419: Battleships in a Board Problem"
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
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return 0;
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
 cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'); 

        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to count the number of battleships in a given 2D grid, where each battleship is represented by a series of connected 'X' cells. Battleships are either positioned horizontally or vertically, and they do not touch each other, meaning there is at least one empty cell (denoted by '.') between any two battleships.

The task is to find the number of distinct battleships in the grid.

### Approach

To solve this problem, we need to iterate through the grid and check each cell to determine if it marks the beginning of a new battleship. A battleship is represented by consecutive 'X' cells either horizontally or vertically. The key observation is that for each 'X' that forms part of a battleship, we only need to count it if it's the first 'X' in its row or column.

The idea is to avoid double-counting cells that belong to the same battleship. For example, if there is a vertical sequence of 'X' cells in a column, the first 'X' in that column should be counted, but the subsequent 'X' cells in that column should not be counted again.

### Code Breakdown (Step by Step)

#### Step 1: Check for an Empty Grid

```cpp
if(board.empty() || board[0].empty()) return 0;
```

- First, we check if the grid is empty or if the first row is empty. If either is true, we return 0, as there are no battleships to count.

#### Step 2: Initialize Variables

```cpp
int m = board.size(), n = board[0].size();
int cnt = 0;
```

- We retrieve the number of rows `m` and columns `n` in the grid.
- We initialize a variable `cnt` to keep track of the number of distinct battleships.

#### Step 3: Iterate Through the Grid

```cpp
for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X');
    }
```

- We loop through each cell in the grid using a nested for loop where `i` represents the row index and `j` represents the column index.
- Inside the loop, we check the following conditions for each cell:
  1. `board[i][j] == 'X'`: The cell must be part of a battleship.
  2. `(i == 0 || board[i - 1][j] != 'X')`: The cell must either be in the first row, or the cell above it must not be part of a battleship. This ensures that we count the first 'X' in a vertical battleship.
  3. `(j == 0 || board[i][j - 1] != 'X')`: The cell must either be in the first column, or the cell to the left must not be part of a battleship. This ensures that we count the first 'X' in a horizontal battleship.
  
  If all these conditions are satisfied, we increment the `cnt` variable by 1, indicating that we have found a new battleship.

#### Step 4: Return the Result

```cpp
return cnt;
```

- After iterating through the entire grid, we return the value of `cnt`, which represents the number of distinct battleships.

### Complexity

#### Time Complexity:

- The time complexity is determined by the double for loop that iterates through all the cells in the grid. The grid has `m` rows and `n` columns, so the time complexity is `O(m * n)`, where `m` is the number of rows and `n` is the number of columns.

#### Space Complexity:

- The space complexity is `O(1)` since we are not using any additional data structures that depend on the size of the input. The only extra space used is for the `cnt` variable.

### Conclusion

The provided solution efficiently counts the number of distinct battleships in a given grid by checking each 'X' cell and ensuring that it represents the start of a new battleship, either horizontally or vertically. This approach works in `O(m * n)` time, making it scalable for larger grids, and uses constant extra space, making it both time and space efficient.

Key highlights of the solution:
- **Efficiency**: The solution runs in linear time with respect to the size of the grid.
- **Simplicity**: The approach directly checks each cell while avoiding double-counting.
- **Optimal Space Usage**: The solution only uses a constant amount of extra space.

This method provides an optimal solution for counting battleships in a grid and can handle grids of varying sizes effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/battleships-in-a-board/description/)

---
{{< youtube gKhvVHd8ihI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
