
+++
authors = ["grid47"]
title = "Leetcode 1139: Largest 1-Bordered Square"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1139: Largest 1-Bordered Square in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has 1s on its border and 0s inside. If no such subgrid exists, return 0.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid, where each element is either 0 or 1.
- **Example:** `Input: grid = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]`
- **Constraints:**
	- 1 <= grid.length <= 100
	- 1 <= grid[0].length <= 100
	- grid[i][j] is 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of elements in the largest square subgrid with 1s on its border and 0s inside.
- **Example:** `Output: 9`
- **Constraints:**
	- The output will be an integer representing the area of the largest square subgrid.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the largest square subgrid with all 1s on its border and 0s inside.

- 1. Use dynamic programming to calculate the largest possible square that can be formed at each point.
- 2. Check the border elements of possible square subgrids to ensure they meet the condition of having 1s along the borders.
- 3. Return the area of the largest valid square found.
{{< dots >}}
### Problem Assumptions ✅
- The grid contains only 0s and 1s.
- We are looking for squares where the border consists of 1s and the inside is filled with 0s.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]`  \
  **Explanation:** In this example, the largest square with all 1s on its border is the entire 3x3 grid, which has 9 elements.

- **Input:** `Input: grid = [[1, 1, 0, 0]]`  \
  **Explanation:** Here, the only valid square is the top-left corner, which is a 1x1 square with 1 on its border, giving an output of 1.

{{< dots >}}
## Approach 🚀
The goal is to find the largest square subgrid with 1s on its border and 0s inside, using dynamic programming to check possible squares and validate their borders.

### Initial Thoughts 💭
- Dynamic programming can be used to store the size of the largest square that can end at each point.
- We need to ensure the border of the square is composed of 1s and the inside is 0s.
- The problem is a typical dynamic programming problem where we compute the largest square at each point and then check if it satisfies the condition of having 1s on the border and 0s inside.
{{< dots >}}
### Edge Cases 🌐
- An empty grid will not be given as per the constraints.
- The solution should efficiently handle grids of size 100x100.
- Grids where no valid square exists should return 0.
- The solution must be efficient enough to handle the upper limits of grid size (100x100).
{{< dots >}}
## Code 💻
```cpp
int largest1BorderedSquare(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    
    vector<vector<int>> top(m, vector<int>(n, 0)), left(m, vector<int>(n, 0));
    
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] > 0) {
            top[i][j] = i > 0? 1 + top[i - 1][j]: 1;
            left[i][j] = j > 0? 1 + left[i][j - 1]: 1;
        }
    
    for(int l = min(m, n); l >= 1; l--) {
        for(int i = 0; i < m - l + 1; i++)
        for(int j = 0; j < n - l + 1; j++)
            if(top[i + l - 1][j] >= l &&
               top[i + l - 1][j + l - 1] >= l &&
              left[i][j + l - 1] >= l &&
              left[i + l - 1][j + l - 1] >= l)
                return l * l;
    }
    return 0;
}
```

This function finds the largest square that can be formed from '1's in a given 2D grid. It uses dynamic programming to calculate the size of potential squares by storing the maximum consecutive '1's found at each position in the 'top' and 'left' arrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int largest1BorderedSquare(vector<vector<int>>& grid) {
	```
	This defines the function `largest1BorderedSquare`, which takes a reference to a 2D vector `grid` and returns an integer representing the area of the largest square with a border of '1's.

2. **Matrix Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line initializes two variables, `m` and `n`, to store the number of rows and columns in the input `grid` respectively.

3. **DP Arrays Initialization**
	```cpp
	    vector<vector<int>> top(m, vector<int>(n, 0)), left(m, vector<int>(n, 0));
	```
	This line initializes two 2D vectors, `top` and `left`, both with dimensions `m` x `n`, and fills them with zeros. These vectors will store the length of consecutive '1's up to each position in the grid (vertically for `top`, and horizontally for `left`).

4. **Loop Through Grid**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This starts a loop iterating over each row of the grid.

5. **Loop Through Grid Columns**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This nested loop iterates through each column of the grid in the current row.

6. **Check for '1'**
	```cpp
	        if(grid[i][j] > 0) {
	```
	This `if` statement checks if the current cell in the grid contains a '1'. If so, it calculates the maximum length of consecutive '1's for this position.

7. **Top Array Update**
	```cpp
	            top[i][j] = i > 0? 1 + top[i - 1][j]: 1;
	```
	If the current cell contains a '1', this line updates the `top` array at position `(i, j)` to store the length of consecutive '1's in the column, including the current cell.

8. **Left Array Update**
	```cpp
	            left[i][j] = j > 0? 1 + left[i][j - 1]: 1;
	```
	This line updates the `left` array at position `(i, j)` to store the length of consecutive '1's in the row, including the current cell.

9. **Square Size Search**
	```cpp
	    for(int l = min(m, n); l >= 1; l--) {
	```
	This `for` loop searches for the largest possible square that can be formed. It starts with the largest possible square size `l` (which is the minimum of the grid's dimensions) and decrements until it finds a valid square.

10. **Search Rows**
	```cpp
	        for(int i = 0; i < m - l + 1; i++)
	```
	This nested loop iterates through all possible starting positions for a square of size `l` in the rows.

11. **Search Columns**
	```cpp
	        for(int j = 0; j < n - l + 1; j++)
	```
	This nested loop iterates through all possible starting positions for a square of size `l` in the columns.

12. **Square Validity Check**
	```cpp
	            if(top[i + l - 1][j] >= l &&
	```
	This checks if the top row of the current square of size `l` contains enough consecutive '1's (using the `top` array).

13. **Square Validity Check**
	```cpp
	               top[i + l - 1][j + l - 1] >= l &&
	```
	This checks if the top-right corner of the current square contains enough consecutive '1's.

14. **Square Validity Check**
	```cpp
	              left[i][j + l - 1] >= l &&
	```
	This checks if the left column of the current square contains enough consecutive '1's (using the `left` array).

15. **Square Validity Check**
	```cpp
	              left[i + l - 1][j + l - 1] >= l)
	```
	This checks if the bottom-left corner of the current square contains enough consecutive '1's.

16. **Return Area of Largest Square**
	```cpp
	                return l * l;
	```
	If a valid square of size `l` is found, the function returns the area of the square (i.e., `l * l`).

17. **Return 0**
	```cpp
	    return 0;
	```
	If no square is found, the function returns 0, indicating that no valid square exists in the grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The algorithm checks each cell in the grid and performs a constant-time operation for each, leading to a time complexity of O(m * n), where m and n are the dimensions of the grid.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the storage of additional 2D arrays `top` and `left`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-1-bordered-square/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
