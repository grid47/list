
+++
authors = ["grid47"]
title = "Leetcode 867: Transpose Matrix"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 867: Transpose Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DzMT3bDgVn0"
youtube_upload_date="2023-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/DzMT3bDgVn0/maxresdefault.jpg"
comments = true
+++



---
Given a 2D integer array `matrix`, return its transpose. The transpose of a matrix is formed by flipping the matrix over its main diagonal, converting rows into columns and columns into rows.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D integer array `matrix` of dimensions `m x n`.
- **Example:** `Input: matrix = [[2, 4], [6, 8], [10, 12]]`
- **Constraints:**
	- m == matrix.length
	- n == matrix[i].length
	- 1 <= m, n <= 1000
	- 1 <= m * n <= 10^5
	- -10^9 <= matrix[i][j] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D integer array representing the transpose of the given matrix.
- **Example:** `Output: [[2, 6, 10], [4, 8, 12]]`
- **Constraints:**
	- The dimensions of the output matrix will be `n x m`.
	- Each element of the output is obtained by swapping rows and columns of the input matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the input matrix by swapping its rows and columns.

- Determine the dimensions `m` and `n` of the input matrix.
- Create a new matrix of dimensions `n x m` initialized with zero values.
- Iterate over each element in the input matrix, assigning `matrix[i][j]` to `transpose[j][i]`.
- Return the newly formed transposed matrix.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is non-empty and well-formed.
- All rows of the matrix have the same number of columns.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[2, 4], [6, 8], [10, 12]], Output: [[2, 6, 10], [4, 8, 12]]`  \
  **Explanation:** The transpose swaps rows and columns. The first column of the input becomes the first row of the output, and so on.

- **Input:** `Input: matrix = [[7]], Output: [[7]]`  \
  **Explanation:** A 1x1 matrix remains the same after transposition.

{{< dots >}}
## Approach 🚀
To transpose the matrix, iterate through the input matrix while constructing a new matrix where rows and columns are swapped.

### Initial Thoughts 💭
- The output matrix dimensions will be the inverse of the input matrix dimensions.
- Accessing elements efficiently is crucial for large inputs.
- Each element of the matrix needs to be accessed exactly once.
- Use a nested loop to iterate over the elements of the input matrix and assign them to their transposed positions in the output matrix.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the matrix is guaranteed to have at least one element.
- Matrices with maximum dimensions of 1000x1000 and up to 10^5 elements.
- Single-row matrices such as `[[1, 2, 3]]` should return a single-column matrix `[[1], [2], [3]]`.
- Single-column matrices such as `[[1], [2], [3]]` should return a single-row matrix `[[1, 2, 3]]`.
- Ensure no memory overflow occurs for large matrices.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> transpose(vector<vector<int>> A) {
    int M = A.size(), N = A[0].size();
    vector<vector<int>> B(N, vector<int>(M, 0));
    for (int j = 0; j < N; j++)
        for (int i = 0; i < M; i++)
            B[j][i] = A[i][j];
    return B;
}
```

This code defines a function to transpose a 2D matrix (vector of vectors), swapping its rows and columns.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> transpose(vector<vector<int>> A) {
	```
	The function definition for `transpose`, which takes a 2D vector (matrix) as input and returns its transposed version.

2. **Matrix Dimensions**
	```cpp
	    int M = A.size(), N = A[0].size();
	```
	Calculates the number of rows (M) and columns (N) of the input matrix A.

3. **Matrix Initialization**
	```cpp
	    vector<vector<int>> B(N, vector<int>(M, 0));
	```
	Initializes a new matrix B with dimensions N x M (transposed dimensions) and fills it with zeros.

4. **Outer Loop**
	```cpp
	    for (int j = 0; j < N; j++)
	```
	Outer loop iterating through columns of the original matrix A, which will become the rows of the transposed matrix B.

5. **Inner Loop**
	```cpp
	        for (int i = 0; i < M; i++)
	```
	Inner loop iterating through rows of the original matrix A, which will become the columns of the transposed matrix B.

6. **Matrix Assignment**
	```cpp
	            B[j][i] = A[i][j];
	```
	Assigns the element from matrix A to its transposed position in matrix B, swapping rows and columns.

7. **Return Statement**
	```cpp
	    return B;
	```
	Returns the transposed matrix B.

8. **Function End**
	```cpp
	}
	```
	End of the `transpose` function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m and n are the dimensions of the matrix.
- **Average Case:** O(m * n), as every element is processed once.
- **Worst Case:** O(m * n), for the largest possible matrix.

The time complexity depends linearly on the total number of elements in the matrix.

### Space Complexity 💾
- **Best Case:** O(1), if done in-place (not applicable for general cases).
- **Worst Case:** O(m * n), for storing the transposed matrix.

Space usage corresponds to the dimensions of the output matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/transpose-matrix/description/)

---
{{< youtube DzMT3bDgVn0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
