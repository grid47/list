
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
comments = true
+++



---
You are given a binary matrix `grid` where you can move from any cell `(row, col)` to adjacent cells `(row + 1, col)` or `(row, col + 1)` only if they have the value 1. The grid is disconnected if there is no path from the top-left corner `(0, 0)` to the bottom-right corner `(m - 1, n - 1)`. You are allowed to flip at most one cell (changing a 1 to 0 or vice versa), but you cannot flip the cells `(0, 0)` or `(m - 1, n - 1)`. Return true if it is possible to disconnect the grid by flipping at most one cell, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an `m x n` binary matrix `grid` where each cell is either 0 or 1.
- **Example:** `grid = [[1, 1, 1], [1, 0, 0], [1, 1, 1]]`
- **Constraints:**
	- 1 <= m, n <= 1000
	- 1 <= m * n <= 10^5
	- grid[i][j] is either 0 or 1
	- grid[0][0] == grid[m - 1][n - 1] == 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to disconnect the grid by flipping at most one cell, otherwise return false.
- **Example:** `true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if it is possible to disconnect the grid by flipping at most one cell.

- 1. Check if the grid is already disconnected. If there is no path from (0, 0) to (m-1, n-1), return true.
- 2. Try flipping each cell (except (0, 0) and (m-1, n-1)) and check if the grid becomes disconnected.
- 3. If flipping any cell makes the grid disconnected, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The grid is initially connected and there is a valid path from (0, 0) to (m-1, n-1).
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1, 1, 1], [1, 0, 0], [1, 1, 1]]`  \
  **Explanation:** Flipping the cell at (1, 1) disconnects the path between (0, 0) and (2, 2), making the grid disconnected.

- **Input:** `grid = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]`  \
  **Explanation:** No single flip can disconnect the grid, so the result is false.

{{< dots >}}
## Approach 🚀
The task is to check whether flipping one cell can disconnect the grid. We will check the connectivity of the grid both before and after flipping each cell.

### Initial Thoughts 💭
- To solve this, we need to first verify if the grid is initially disconnected and if any flip can disconnect it.
- We can use a depth-first search (DFS) or breadth-first search (BFS) to verify if the grid is connected or disconnected before and after flipping any cell.
{{< dots >}}
### Edge Cases 🌐
- The grid will always have a valid initial path as per the constraints.
- Ensure that the solution works efficiently with grids up to the maximum size of 1000x1000.
- Handle cases where there are few cells (e.g., 2x2 grids) or all cells are already 1s or 0s.
- The solution should work for grids with sizes up to 1000x1000.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> grid, memo;
int m, n;
bool isPossibleToCutPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    this->grid = grid;

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

```

The function 'isPossibleToCutPath' checks if it's possible to cut the path in a grid such that there's no valid path from the top-left to the bottom-right corner. The helper function 'isconnected' is used to determine if there is a valid connection to the destination.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> grid, memo;
	```
	Two 2D vectors 'grid' and 'memo' are declared. 'grid' represents the input grid, and 'memo' can be used for storing intermediate results (though it's not utilized in this function).

2. **Variable Initialization**
	```cpp
	int m, n;
	```
	Two integers, 'm' and 'n', are declared to store the dimensions of the grid.

3. **Function Definition**
	```cpp
	bool isPossibleToCutPath(vector<vector<int>>& grid) {
	```
	The 'isPossibleToCutPath' function is defined, which takes the grid as input and returns a boolean indicating whether it is possible to cut the path.

4. **Grid Dimensions**
	```cpp
	    m = grid.size();
	```
	The variable 'm' is assigned the number of rows in the grid by getting the size of the 'grid' vector.

5. **Grid Dimensions**
	```cpp
	    n = grid[0].size();
	```
	The variable 'n' is assigned the number of columns in the grid by getting the size of the first row ('grid[0]').

6. **Grid Assignment**
	```cpp
	    this->grid = grid;
	```
	The input 'grid' is assigned to the class-level 'grid' variable.

7. **Initial Check**
	```cpp
	    if(isconnected(0, 0) == false) return true;
	```
	This line checks if there is no valid path from the top-left corner (0, 0) to the bottom-right corner using the helper function 'isconnected'. If the path doesn't exist, it returns 'true', indicating the path can be cut.

8. **Modify Grid**
	```cpp
	    this->grid[0][0] = 1;
	```
	The top-left corner of the grid is marked as 1, indicating that the starting point has been 'cut' for the next step.

9. **Final Check**
	```cpp
	    return !isconnected(0, 0);
	```
	This final check calls 'isconnected' again to verify if there is still a valid path from (0, 0). If the path no longer exists, it returns 'true', meaning the path was successfully cut.

10. **Helper Function Definition**
	```cpp
	bool isconnected(int i, int j) {
	```
	The 'isconnected' function is defined, which checks if there is a valid path from the current position (i, j) to the bottom-right corner.

11. **Base Case Check**
	```cpp
	    if(i == m - 1 && j == n - 1) return true;
	```
	This is the base case: if the current position (i, j) is the bottom-right corner, the function returns 'true', indicating a valid path exists.

12. **Out-of-Bounds and Blocked Check**
	```cpp
	    if(i >= m || j >= n || grid[i][j] == 0) return false;
	```
	This line checks if the current position (i, j) is out of bounds or blocked (grid[i][j] == 0). If so, it returns 'false'.

13. **Mark Visited**
	```cpp
	    grid[i][j] = 0;
	```
	This line marks the current cell as visited by setting grid[i][j] to 0.

14. **Recursive Call**
	```cpp
	    return isconnected(i + 1, j) || isconnected(i, j + 1);
	```
	This line makes recursive calls to check the right (i, j + 1) and down (i + 1, j) cells to see if there is a valid path.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns in the grid.
- **Average Case:** O(m * n), as we may need to check all cells to determine connectivity.
- **Worst Case:** O(m * n), as we need to check connectivity multiple times for various flips.



### Space Complexity 💾
- **Best Case:** O(m * n), as the space complexity depends on the size of the grid.
- **Worst Case:** O(m * n), for the space required to track visited cells during DFS/BFS.

Space complexity is mainly dominated by the storage used for the visited cells during the traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/description/)

---
{{< youtube JvRANmpcKcs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
