
+++
authors = ["grid47"]
title = "Leetcode 885: Spiral Matrix III"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 885: Spiral Matrix III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0qep3f9cqVs"
youtube_upload_date="2019-12-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0qep3f9cqVs/maxresdefault.webp"
comments = true
+++



---
You are given a grid of size rows x cols, where each cell represents a coordinate. You start at a given coordinate (rStart, cStart), facing east, and your goal is to walk in a clockwise spiral through the grid. As you walk, you must visit each cell exactly once. Once you reach the boundary of the grid, continue walking outside the grid, but you may return to the grid later. Return a list of the coordinates you visit in the order you encounter them.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the dimensions of the grid (rows, cols) and your starting position (rStart, cStart).
- **Example:** `Input: rows = 3, cols = 3, rStart = 1, cStart = 1`
- **Constraints:**
	- 1 <= rows, cols <= 100
	- 0 <= rStart < rows
	- 0 <= cStart < cols

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return a list of coordinates, where each coordinate is represented as an array [r, c], in the order they were visited.
- **Example:** `Output: [[1,1],[1,2],[0,2],[0,1],[0,0],[1,0],[2,0],[2,1],[2,2]]`
- **Constraints:**
	- The output should contain all coordinates visited in the spiral traversal.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the spiral traversal, carefully switching directions and ensuring no cell is skipped.

- Start from the given position and begin moving east.
- Continue spiraling in clockwise direction, changing direction after hitting a boundary or previously visited cell.
- Use a list to keep track of the coordinates you visit.
{{< dots >}}
### Problem Assumptions ✅
- The grid has at least one cell.
- You can go outside the grid and return later when needed.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: rows = 3, cols = 3, rStart = 1, cStart = 1`  \
  **Explanation:** The grid is 3x3 with the start position at (1,1). The spiral traversal starts at (1,1), moves east to (1,2), then north to (0,2), then west to (0,1), then south to (1,0), and continues until all cells are visited. The output is the list of coordinates visited in this order.

- **Input:** `Input: rows = 2, cols = 2, rStart = 0, cStart = 0`  \
  **Explanation:** The grid is 2x2 with the start position at (0,0). The spiral traversal visits (0,0), moves east to (0,1), then south to (1,1), and finally west to (1,0).

{{< dots >}}
## Approach 🚀
The problem can be solved by simulating the spiral movement using direction changes. The directions follow a clockwise pattern: east -> south -> west -> north. After each move, check if the new position is within the grid's bounds. If it is, add the position to the result. If not, change direction.

### Initial Thoughts 💭
- The movement follows a strict clockwise pattern and will continue until all cells are visited.
- The algorithm should efficiently track the positions visited while respecting the boundaries and changing directions accordingly.
{{< dots >}}
### Edge Cases 🌐
- The problem constraints guarantee that there will always be at least one row and one column.
- The algorithm must handle grids as large as 100x100 efficiently.
- The starting point could be in any cell within the grid.
- The grid size and position constraints are relatively small, so a direct simulation approach will work efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> res = {{rStart, cStart}};
    int dx = 0, dy = 1, tmp;
    for(int n = 0; res.size() < rows* cols; n++) {
        for(int i = 0; i < n / 2 + 1; i++) {
            rStart += dx, cStart += dy;
            if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
                res.push_back({rStart, cStart});
            
        }
        tmp = dx, dx = dy, dy = -tmp;
    }
    return res;
}
```

This function generates a spiral matrix starting from a specific point in the grid. It iteratively moves in a spiral pattern while ensuring that all positions are within the bounds of the grid and adds them to the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
	```
	This line defines the function `spiralMatrixIII` which takes the grid dimensions (`rows`, `cols`) and the starting position (`rStart`, `cStart`) as parameters.

2. **Initialization**
	```cpp
	    vector<vector<int>> res = {{rStart, cStart}};
	```
	A result vector `res` is initialized with the starting position (`rStart`, `cStart`). This will store the coordinates as the spiral is generated.

3. **Variable Setup**
	```cpp
	    int dx = 0, dy = 1, tmp;
	```
	Two variables `dx` and `dy` are initialized to control the movement direction in the grid. `dx` controls row movement (initially 0), and `dy` controls column movement (initially 1). `tmp` is used for swapping direction.

4. **Loop Setup**
	```cpp
	    for(int n = 0; res.size() < rows* cols; n++) {
	```
	The loop continues until all positions in the grid are covered, and `res.size()` is less than the total number of cells (`rows * cols`).

5. **Inner Loop Setup**
	```cpp
	        for(int i = 0; i < n / 2 + 1; i++) {
	```
	The inner loop iterates through each direction step (n / 2 + 1 times). This determines how far to move in the current direction.

6. **Position Update**
	```cpp
	            rStart += dx, cStart += dy;
	```
	The current position (`rStart`, `cStart`) is updated by adding `dx` to `rStart` and `dy` to `cStart` to move in the current direction.

7. **Boundary Check**
	```cpp
	            if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
	```
	The function checks if the new position is within the bounds of the grid. If valid, it proceeds to add the new position to the result.

8. **Position Add to Result**
	```cpp
	                res.push_back({rStart, cStart});
	```
	If the new position is valid, it is added to the result vector `res`.

9. **Direction Update**
	```cpp
	        tmp = dx, dx = dy, dy = -tmp;
	```
	This line swaps the direction of movement by rotating `dx` and `dy`. This ensures the spiral continues in the correct order (right, down, left, up).

10. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the `res` vector containing all coordinates in the spiral order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * m)
- **Average Case:** O(n * m)
- **Worst Case:** O(n * m)

In the worst case, the algorithm needs to visit all cells in the grid, which takes O(n * m) time where n is the number of rows and m is the number of columns.

### Space Complexity 💾
- **Best Case:** O(n * m)
- **Worst Case:** O(n * m)

The space complexity is O(n * m) because we need to store all the visited coordinates.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/spiral-matrix-iii/description/)

---
{{< youtube 0qep3f9cqVs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
