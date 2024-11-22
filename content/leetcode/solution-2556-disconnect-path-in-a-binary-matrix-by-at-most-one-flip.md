
+++
authors = ["grid47"]
title = "Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2556: Disconnect Path in a Binary Matrix by at Most One Flip in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JvRANmpcKcs"
youtube_upload_date="2023-02-04"
youtube_thumbnail="https://i.ytimg.com/vi/JvRANmpcKcs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> grid, memo;
    int m, n;
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid= grid;

        if(isconnected(0, 0) == false) return true;
        this->grid[0][0] = 1;
        return !isconnected(0, 0);
    }
    
    bool isconnected(int i, int j) {
        if(i == m - 1 && j == n - 1) return true;
        
        if(i >= m || j >= n || grid[i][j] == 0) return false;
        
        grid[i][j] = 0;
        return isconnected(i + 1, j) || isconnected(i, j + 1);

    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine whether it is possible to cut a path from the top-left corner to the bottom-right corner in a grid. The grid contains cells that are either passable (1) or blocked (0). The path should be able to traverse from the top-left to the bottom-right corner by moving either down or right. The challenge is to figure out if cutting the path (removing one path or one cell) between these two corners will make it impossible to traverse.

The task is to verify whether it's possible to cut the path by blocking one of the cells and making the path from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` unreachable.

### Approach

We can approach this problem with the help of **depth-first search (DFS)**. The algorithm focuses on verifying if there exists a path from the start `(0, 0)` to the end `(m-1, n-1)` in a grid. The approach can be broken down into the following steps:

1. **Check Initial Path**: We first check if there exists an initial path from `(0, 0)` to `(m-1, n-1)` in the given grid.
2. **Mark Cell as Blocked**: If there is a valid path, we try to "cut" it by marking the start `(0, 0)` as blocked (`grid[0][0] = 1`) and check if the path is still possible.
3. **DFS Traversal**: Perform a depth-first search (DFS) starting from the top-left corner `(0, 0)` to see if we can reach the bottom-right corner. If we can't, it indicates that cutting the path is possible.

### Code Breakdown

Let's break down the code step by step to understand how it works:

#### Step 1: Initialization

```cpp
vector<vector<int>> grid, memo;
int m, n;
```

- `grid`: This 2D array stores the initial configuration of the grid, where `1` represents a passable cell and `0` represents a blocked cell.
- `memo`: Though unused in this code, `memo` could be a space to store the results of previous recursive calls to avoid recalculating results (dynamic programming technique). In the given code, it's not used.
- `m` and `n`: These variables store the number of rows and columns of the grid.

#### Step 2: The Main Function - `isPossibleToCutPath`

```cpp
bool isPossibleToCutPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    this->grid = grid;
    
    if(isconnected(0, 0) == false) return true;
    this->grid[0][0] = 1;
    return !isconnected(0, 0);
}
```

- **Grid Size**: We first initialize the size of the grid using `m = grid.size()` and `n = grid[0].size()`.
- **Initial Check for Connectivity**: The first thing we do is check if there exists a path from the start `(0, 0)` to the destination `(m-1, n-1)` using the helper function `isconnected`.
  - If there's no initial path (`isconnected(0, 0) == false`), we return `true` because it's already disconnected.
- **Cutting the Path**: If there is a path, we proceed by blocking the starting cell (`grid[0][0] = 1`) and recheck if there is still a path from `(0, 0)` to `(m-1, n-1)`.
  - If the path is no longer available after blocking `(0, 0)`, we return `true`, indicating that cutting the path is possible.
  - If the path is still intact, we return `false`, indicating that cutting the path is not possible.

#### Step 3: The DFS Function - `isconnected`

```cpp
bool isconnected(int i, int j) {
    if(i == m - 1 && j == n - 1) return true;
    
    if(i >= m || j >= n || grid[i][j] == 0) return false;
    
    grid[i][j] = 0;
    return isconnected(i + 1, j) || isconnected(i, j + 1);
}
```

The `isconnected` function is a classic depth-first search that checks if there exists a path from the current cell `(i, j)` to the destination `(m-1, n-1)`:

- **Base Case**: If we have reached the destination `(m-1, n-1)`, we return `true` to indicate that the path exists.
- **Boundary Check**: If the current cell `(i, j)` is out of bounds (`i >= m || j >= n`) or blocked (`grid[i][j] == 0`), we return `false` since this is an invalid or blocked cell.
- **Mark Visited**: To avoid revisiting cells, we mark the current cell as blocked by setting `grid[i][j] = 0`.
- **Recursive Exploration**: We attempt to move either **down** (`i + 1, j`) or **right** (`i, j + 1`) from the current cell and check if either of these moves leads to the destination.

### Complexity

#### Time Complexity:

- **DFS Traversal**: In the worst case, the DFS function will visit every cell in the grid once. Hence, the time complexity is proportional to the number of cells in the grid, which is \(O(m \times n)\), where `m` is the number of rows and `n` is the number of columns.
- **Total Time Complexity**: The total time complexity for the `isPossibleToCutPath` function is \(O(m \times n)\) because we call the `isconnected` function twice (once for the initial path check and once after marking the start as blocked).

#### Space Complexity:

- **Recursive Stack**: The space complexity for the recursive calls in the DFS function is \(O(m + n)\) due to the stack used during the recursion.
- **Grid Modification**: The space used by the grid itself is \(O(m \times n)\), but this is not extra space, as we modify the grid in-place.
- **Total Space Complexity**: The total space complexity is \(O(m \times n)\).

### Conclusion

The solution successfully checks whether it's possible to disconnect the path from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)` by marking the starting point as blocked and performing a depth-first search. By using a depth-first search (DFS), the algorithm efficiently traverses the grid, checking for a valid path before and after blocking the start.

The algorithm has a time complexity of \(O(m \times n)\), making it efficient enough for reasonably large grids. Additionally, the use of recursion ensures that the solution is both simple and effective, though the space complexity is proportional to the size of the grid due to recursion.

[`Link to LeetCode Lab`](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/)

---
{{< youtube JvRANmpcKcs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
