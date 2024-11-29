
+++
authors = ["grid47"]
title = "Leetcode 1277: Count Square Submatrices with All Ones"
date = "2024-07-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1277: Count Square Submatrices with All Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PBZCmMugu5Q"
youtube_upload_date="2020-05-22"
youtube_thumbnail="https://i.ytimg.com/vi/PBZCmMugu5Q/maxresdefault.jpg"
comments = true
+++



---
Given a m x n matrix of ones and zeros, count how many square submatrices are filled with all ones.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D matrix where each element is either a 0 or 1.
- **Example:** `Input: matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]`
- **Constraints:**
	- 1 <= arr.length <= 300
	- 1 <= arr[0].length <= 300
	- 0 <= arr[i][j] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of square submatrices that are fully filled with ones.
- **Example:** `Output: 15`
- **Constraints:**
	- All submatrices considered must be squares filled with only 1s.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the number of square submatrices that consist only of 1s.

- Iterate through the matrix and at each cell that contains 1, calculate the largest possible square submatrix that can be formed with that cell as the bottom-right corner.
- The size of the square submatrix is determined by the minimum of the squares possible at the adjacent cells (top, left, top-left diagonal).
- Accumulate the number of squares of all sizes.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is rectangular and may have varying numbers of rows and columns.
- There will be no invalid values in the matrix, i.e., only 0s and 1s.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[0,1,1,1],[1,1,1,1],[0,1,1,1]]`  \
  **Explanation:** The total count of square submatrices is determined by calculating the possible side lengths of squares that can be formed at each position. This includes squares of different sizes such as 1x1, 2x2, and 3x3.

{{< dots >}}
## Approach 🚀
We approach this problem by using dynamic programming. For each cell in the matrix, calculate the largest square submatrix that ends at that cell.

### Initial Thoughts 💭
- At each cell, we can form a square if the current cell is 1 and the adjacent cells (above, left, and top-left diagonal) are part of squares as well.
- Use dynamic programming to keep track of the largest square submatrix at each cell.
{{< dots >}}
### Edge Cases 🌐
- If the matrix is empty or all zeros, the output should be 0.
- For large matrices (300x300), ensure the solution is optimized to handle maximum size within time limits.
- Matrices with only 1s should return the maximum number of square submatrices possible.
- Ensure that the algorithm handles all possible matrix sizes up to 300x300 efficiently.
{{< dots >}}
## Code 💻
```cpp
int countSquares(vector<vector<int>>& matrix) {
    int res = 0, m = matrix.size(), n = matrix[0].size();

    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(matrix[i][j] && i && j)
        matrix[i][j] += min({matrix[i - 1][j], matrix[i -1][j-1], matrix[i][j -1]});
        res += matrix[i][j];
    }
    return res;
}
```

This function counts the total number of square submatrices with all 1s in the given 2D matrix. It uses dynamic programming to update the values in the matrix to represent the size of the largest square that can end at that cell.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Matrix Initialization**
	```cpp
	int countSquares(vector<vector<int>>& matrix) {
	```
	Defines the function to count square submatrices in the provided 2D matrix.

2. **Variable Initialization**
	```cpp
	    int res = 0, m = matrix.size(), n = matrix[0].size();
	```
	Initializes the result variable and calculates the dimensions of the matrix.

3. **Loop Setup**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Begins iterating over each row of the matrix.

4. **Loop Setup**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Begins iterating over each column within the current row.

5. **Conditional Check**
	```cpp
	        if(matrix[i][j] && i && j)
	```
	Checks if the current cell is 1 and is not in the first row or column.

6. **Matrix Update**
	```cpp
	        matrix[i][j] += min({matrix[i - 1][j], matrix[i -1][j-1], matrix[i][j -1]});
	```
	Updates the cell value to the size of the largest square that can end at this cell.

7. **Result Calculation**
	```cpp
	        res += matrix[i][j];
	```
	Adds the current cell's value to the result, representing the count of squares ending at this cell.

8. **Return Statement**
	```cpp
	    return res;
	```
	Returns the total count of square submatrices with all 1s.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The algorithm processes each cell of the matrix once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is proportional to the matrix size, as we store results for each cell.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/)

---
{{< youtube PBZCmMugu5Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
