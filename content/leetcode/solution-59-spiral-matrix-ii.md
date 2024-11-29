
+++
authors = ["grid47"]
title = "Leetcode 59: Spiral Matrix II"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 59: Spiral Matrix II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/59.webp"
youtube = "RvLrWFBJ9fM"
youtube_upload_date="2023-05-10"
youtube_thumbnail="https://i.ytimg.com/vi/RvLrWFBJ9fM/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/59.webp" 
    alt="A dynamic, growing spiral matrix with radiant paths expanding outward."
    caption="Solution to LeetCode 59: Spiral Matrix II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Create an n x n matrix where numbers from 1 to n^2 are arranged in a spiral order starting from the top-left corner.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single integer n representing the size of the square matrix.
- **Example:** `Input: n = 4`
- **Constraints:**
	- 1 <= n <= 20

{{< dots >}}
### Output Specifications 📤
- **Output:** An n x n matrix filled with numbers from 1 to n^2 in a spiral order.
- **Example:** `Output: [[1, 2, 3, 4], [12, 13, 14, 5], [11, 16, 15, 6], [10, 9, 8, 7]]`
- **Constraints:**
	- Output matrix should always have dimensions n x n.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate the matrix by placing numbers sequentially in a spiral pattern.

- Initialize an n x n matrix with zeros.
- Set boundaries for rows and columns: top, bottom, left, and right.
- Iteratively fill the matrix: move right, down, left, and up while updating the boundaries.
- Stop when all numbers from 1 to n^2 have been placed.
{{< dots >}}
### Problem Assumptions ✅
- The input is always a positive integer within the valid range.
- The matrix is square (n x n).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4`  \
  **Explanation:** The numbers from 1 to 16 are filled in a 4x4 matrix in a clockwise spiral order.

- **Input:** `Input: n = 2`  \
  **Explanation:** A 2x2 matrix is filled with numbers from 1 to 4 in a spiral order.

- **Input:** `Input: n = 1`  \
  **Explanation:** A single number 1 fills the 1x1 matrix.

{{< dots >}}
## Approach 🚀
Use iterative boundary-based traversal to fill the matrix in a spiral order.

### Initial Thoughts 💭
- The spiral traversal involves updating the boundaries after each pass.
- The pattern follows clockwise movement: right, down, left, up.
- Boundaries shrink after each traversal, ensuring the spiral pattern.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as input is guaranteed.
- Maximum n value, such as n = 20.
- Minimum n value, n = 1.
- Ensure the matrix dimensions are correct for edge cases.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    int num = 1, rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        // Top row
        for (int col = colStart; col <= colEnd; col++) {
            matrix[rowStart][col] = num++;
        }
        rowStart++;

        // Right column
        for (int row = rowStart; row <= rowEnd; row++) {
            matrix[row][colEnd] = num++;
        }
        colEnd--;

        // Bottom row
        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; col--) {
                matrix[rowEnd][col] = num++;
            }
            rowEnd--;
        }

        // Left column
        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                matrix[row][colStart] = num++;
            }
            colStart++;
        }
    }

    return matrix;
}
```

This code generates a spiral matrix of size n x n, filling it with numbers from 1 to n^2 in a spiral pattern.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> generateMatrix(int n) {
	```
	This line declares a function named `generateMatrix` that takes an integer `n` as input and returns a 2D vector representing the spiral matrix.

2. **Matrix Initialization**
	```cpp
	    vector<vector<int>> matrix(n, vector<int>(n));
	```
	This line initializes a 2D vector `matrix` of size `n x n` with all elements set to 0.

3. **Variable Initialization**
	```cpp
	    int num = 1, rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1;
	```
	This line initializes variables to keep track of the current number to be filled, the starting and ending row and column indices.

4. **Spiral Filling Loop**
	```cpp
	    while (rowStart <= rowEnd && colStart <= colEnd) {
	```
	This loop continues as long as there are elements to be filled in the spiral pattern.

5. **Fill Top Row**
	```cpp
	        for (int col = colStart; col <= colEnd; col++) {
	            matrix[rowStart][col] = num++;
	        }
	```
	This loop fills the top row of the current spiral layer, starting from the `colStart` column and moving to the `colEnd` column.

6. **Update Row Start**
	```cpp
	        rowStart++;
	```
	The `rowStart` is incremented to move to the next row.

7. **Fill Right Column**
	```cpp
	        for (int row = rowStart; row <= rowEnd; row++) {
	            matrix[row][colEnd] = num++;
	        }
	```
	This loop fills the right column of the current spiral layer, starting from the new `rowStart` and moving to the `rowEnd` row.

8. **Update Column End**
	```cpp
	        colEnd--;
	```
	The `colEnd` is decremented to move to the previous column.

9. **Fill Bottom Row (Conditional)**
	```cpp
	        if (rowStart <= rowEnd) {
	```
	This condition checks if there are still rows to be filled from the bottom.

10. **Fill Bottom Row**
	```cpp
	            for (int col = colEnd; col >= colStart; col--) {
	                matrix[rowEnd][col] = num++;
	            }
	```
	This loop fills the bottom row of the current spiral layer, starting from the `colEnd` column and moving to the `colStart` column.

11. **Update Row End**
	```cpp
	            rowEnd--;
	```
	The `rowEnd` is decremented to move to the previous row.

12. **Fill Left Column (Conditional)**
	```cpp
	        if (colStart <= colEnd) {
	```
	This condition checks if there are still columns to be filled from the left.

13. **Fill Left Column**
	```cpp
	            for (int row = rowEnd; row >= rowStart; row--) {
	                matrix[row][colStart] = num++;
	            }
	```
	This loop fills the left column of the current spiral layer, starting from the `rowEnd` row and moving to the `rowStart` row.

14. **Update Column Start**
	```cpp
	            colStart++;
	```
	The `colStart` is incremented to move to the next column.

15. **Return the Matrix**
	```cpp
	    return matrix;
	```
	The function returns the completed spiral matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Each number from 1 to n^2 is placed exactly once in the matrix.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The matrix itself requires O(n^2) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/spiral-matrix-ii/description/)

---
{{< youtube RvLrWFBJ9fM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
