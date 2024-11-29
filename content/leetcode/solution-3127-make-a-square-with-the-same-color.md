
+++
authors = ["grid47"]
title = "Leetcode 3127: Make a Square with the Same Color"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3127: Make a Square with the Same Color in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6krFbmlIg94"
youtube_upload_date="2024-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/6krFbmlIg94/maxresdefault.jpg"
comments = true
+++



---
You are given a 3x3 matrix consisting of characters 'B' (black) and 'W' (white). Your task is to determine if it is possible to change the color of at most one cell to form a 2x2 square where all cells are of the same color. Return true if it is possible, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 3x3 matrix where each cell contains either 'B' or 'W'.
- **Example:** `grid = [['B', 'W', 'B'], ['B', 'W', 'W'], ['B', 'W', 'B']]`
- **Constraints:**
	- grid.length == 3
	- grid[i].length == 3
	- grid[i][j] is either 'W' or 'B'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to form a 2x2 square where all cells are of the same color, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine if it's possible to form a 2x2 square of the same color by changing at most one cell.

- 1. Loop through each possible 2x2 subgrid of the matrix.
- 2. Count the occurrences of 'B' and 'W' in each 2x2 subgrid.
- 3. Check if it's possible to change one cell to make all cells in the 2x2 subgrid the same color.
- 4. Return true if such a subgrid is found, otherwise return false.
{{< dots >}}
### Problem Assumptions ✅
- The input grid will always be a 3x3 matrix.
- The characters in the grid will always be 'B' or 'W'.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [['B', 'W', 'B'], ['B', 'W', 'W'], ['B', 'W', 'B']]`  \
  **Explanation:** By changing the color of grid[0][2] (B → W), we can create a 2x2 square with all cells the same color.

- **Input:** `grid = [['B', 'W', 'B'], ['W', 'B', 'W'], ['B', 'W', 'B']]`  \
  **Explanation:** No matter which cell we change, we can't form a 2x2 square with the same color.

- **Input:** `grid = [['B', 'W', 'B'], ['B', 'W', 'W'], ['B', 'W', 'W']]`  \
  **Explanation:** The matrix already contains a 2x2 square with all cells the same color (grid[1][1], grid[1][2], grid[2][1], grid[2][2]).

{{< dots >}}
## Approach 🚀
We can iterate through all possible 2x2 subgrids in the matrix and check if it is possible to make all cells in the subgrid the same color by changing at most one cell.

### Initial Thoughts 💭
- The problem is simple because the grid is always 3x3.
- We can check each 2x2 subgrid and count how many 'B' and 'W' cells there are. If we find a 2x2 subgrid with 3 same-colored cells, we can change the fourth one.
{{< dots >}}
### Edge Cases 🌐
- The grid is always a 3x3 matrix, so this case does not apply.
- The grid is fixed at 3x3 size, so this case does not apply.
- All cells are the same color. This will automatically return true.
- The grid will always be 3x3.
{{< dots >}}
## Code 💻
```cpp
bool canMakeSquare(vector<vector<char>>& grid) {
    
    int m = grid.size(), n = grid[0].size();
    
    for(int i = 0; i + 1 < m; i++)
    for(int j = 0; j + 1 < n; j++) {
        
        int white = (grid[i][j] == 'W') + (grid[i + 1][j] == 'W') +
            (grid[i][j + 1] == 'W') + (grid[i + 1][j + 1] == 'W');
        
        int black = (grid[i][j] == 'B') + (grid[i + 1][j] == 'B') +
            (grid[i][j + 1] == 'B') + (grid[i + 1][j + 1] == 'B');            
        
        if((white == 3 && black == 1) || (white == 1 && black == 3) || white == 4 || black == 4)
            return true;
    }
    
    return false;
    
}
```

This function checks if a 2x2 square can be formed in the grid where the square has 3 cells of one color and 1 cell of another color.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool canMakeSquare(vector<vector<char>>& grid) {
	```
	Defines the function that takes a 2D grid of characters as input.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Initializes the dimensions of the grid, with m representing the number of rows and n representing the number of columns.

3. **Loop Structure**
	```cpp
	    for(int i = 0; i + 1 < m; i++)
	```
	A loop iterating over rows of the grid, ensuring that it doesn't go beyond the last row that can form a 2x2 square.

4. **Loop Structure**
	```cpp
	    for(int j = 0; j + 1 < n; j++) {
	```
	A nested loop iterating over columns of the grid, ensuring it doesn't exceed the last column for forming a 2x2 square.

5. **Conditionals**
	```cpp
	        int white = (grid[i][j] == 'W') + (grid[i + 1][j] == 'W') +
	```
	Counts how many 'W' (white) cells are present in the 2x2 square.

6. **Conditionals**
	```cpp
	            (grid[i][j + 1] == 'W') + (grid[i + 1][j + 1] == 'W');
	```
	Continues the count for the remaining positions in the 2x2 square for the color white.

7. **Conditionals**
	```cpp
	        int black = (grid[i][j] == 'B') + (grid[i + 1][j] == 'B') +
	```
	Counts how many 'B' (black) cells are present in the 2x2 square.

8. **Conditionals**
	```cpp
	            (grid[i][j + 1] == 'B') + (grid[i + 1][j + 1] == 'B');            
	```
	Completes the black cell count for the remaining positions in the 2x2 square.

9. **Conditionals**
	```cpp
	        if((white == 3 && black == 1) || (white == 1 && black == 3) || white == 4 || black == 4)
	```
	Checks if the 2x2 square has either 3 white and 1 black cells, or vice versa, or if it is completely white or completely black.

10. **Return Statement**
	```cpp
	            return true;
	```
	Returns true if a valid 2x2 square is found.

11. **Return Statement**
	```cpp
	    return false;
	```
	Returns false if no valid 2x2 square is found in the entire grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Since the matrix is always 3x3, the time complexity is constant, O(1).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), as we only need a few variables to keep track of the counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-a-square-with-the-same-color/description/)

---
{{< youtube 6krFbmlIg94 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
