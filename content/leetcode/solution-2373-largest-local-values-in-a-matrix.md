
+++
authors = ["grid47"]
title = "Leetcode 2373: Largest Local Values in a Matrix"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2373: Largest Local Values in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wdTRu9sarFA"
youtube_upload_date="2024-05-12"
youtube_thumbnail="https://i.ytimg.com/vi/wdTRu9sarFA/maxresdefault.jpg"
comments = true
+++



---
You are given a square matrix grid of size n x n. Your task is to generate a new matrix maxLocal of size (n - 2) x (n - 2) where each element maxLocal[i][j] represents the largest value from a 3 x 3 submatrix in grid centered at (i + 1, j + 1). In other words, for each element of the new matrix, find the maximum value from its surrounding 3 x 3 region in the original grid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an n x n matrix grid.
- **Example:** `grid = [[3, 1, 2, 7], [6, 5, 8, 3], [9, 4, 0, 1], [7, 6, 5, 9]]`
- **Constraints:**
	- 3 <= n <= 100
	- 1 <= grid[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the generated matrix maxLocal, where each element is the largest value from the corresponding 3x3 region in the original grid.
- **Example:** `Output: [[8, 8], [9, 8]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute a new matrix where each element is the maximum of a 3x3 submatrix from the original matrix.

- 1. Iterate through each possible 3x3 submatrix in the input matrix.
- 2. For each submatrix, find the maximum value within the 3x3 region.
- 3. Store the maximum value in the corresponding position in the new matrix.
{{< dots >}}
### Problem Assumptions ✅
- The input grid will always have a size of at least 3x3.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[9, 9, 8, 1], [5, 6, 2, 6], [8, 2, 6, 4], [6, 2, 2, 2]]`  \
  **Explanation:** For this input, the largest 3x3 values are: [[9, 9], [8, 6]]. This corresponds to the largest values from every 3x3 region in the original grid.

- **Input:** `Input: grid = [[1, 1, 1, 1, 1], [1, 1, 1, 1, 1], [1, 1, 2, 1, 1], [1, 1, 1, 1, 1], [1, 1, 1, 1, 1]]`  \
  **Explanation:** In this case, every 3x3 region contains a 2, so the output matrix is filled with 2.

{{< dots >}}
## Approach 🚀
This problem can be efficiently solved by iterating through each 3x3 submatrix and finding the maximum value within that submatrix.

### Initial Thoughts 💭
- We need to handle the edge of the matrix carefully as the 3x3 submatrix can't extend beyond the grid boundaries.
- A brute-force solution that checks every 3x3 submatrix is feasible, as the matrix size is constrained to be at most 100x100.
{{< dots >}}
### Edge Cases 🌐
- Empty inputs are not possible since n >= 3.
- Ensure the solution handles the largest grid size (100x100) within the time limits.
- If all elements of the grid are the same, the output will be a matrix filled with the same value.
- The solution should efficiently handle grids up to size 100x100.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> largestLocal(vector<vector<int>>& g) {
int n = g.size();
vector<vector<int>> res(n - 2, vector<int>(n - 2));
for (int i = 0; i < n - 2; ++i)
    for (int j = 0; j < n - 2; ++j)
        for (int ii = i; ii < i + 3; ++ii)
            for (int jj = j; jj < j + 3; ++jj)
                res[i][j] = max(res[i][j], g[ii][jj]);
return res;
}
```

This function calculates the maximum value in each 3x3 subgrid of the given grid `g` and stores the result in the `res` vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> largestLocal(vector<vector<int>>& g) {
	```
	Defines a function `largestLocal` that takes a 2D grid `g` and returns a 2D vector with the largest value in each 3x3 subgrid.

2. **Size Calculation**
	```cpp
	int n = g.size();
	```
	Calculates the size of the grid `g` and stores it in `n`.

3. **Result Vector Initialization**
	```cpp
	vector<vector<int>> res(n - 2, vector<int>(n - 2));
	```
	Initializes a result vector `res` of size `(n-2) x (n-2)` to store the maximum values from each 3x3 subgrid.

4. **Outer Loop (i)**
	```cpp
	for (int i = 0; i < n - 2; ++i)
	```
	Outer loop that iterates over the rows of the grid, limiting the index to `n-2` to avoid going out of bounds when considering 3x3 subgrids.

5. **Outer Loop (j)**
	```cpp
	    for (int j = 0; j < n - 2; ++j)
	```
	Inner loop that iterates over the columns of the grid, limiting the index to `n-2` to avoid going out of bounds when considering 3x3 subgrids.

6. **Inner Loop (ii)**
	```cpp
	        for (int ii = i; ii < i + 3; ++ii)
	```
	Inner loop that iterates through the rows of the 3x3 subgrid, starting from the current `i` position.

7. **Inner Loop (jj)**
	```cpp
	            for (int jj = j; jj < j + 3; ++jj)
	```
	Inner loop that iterates through the columns of the 3x3 subgrid, starting from the current `j` position.

8. **Update Result**
	```cpp
	                res[i][j] = max(res[i][j], g[ii][jj]);
	```
	Updates the value at `res[i][j]` with the maximum of its current value and the value in the current 3x3 subgrid (`g[ii][jj]`).

9. **Return Statement**
	```cpp
	return res;
	```
	Returns the 2D result vector `res` that contains the largest value for each 3x3 subgrid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) since we examine each 3x3 submatrix once, and n is the grid's side length.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) as we store the result matrix of size (n-2) x (n-2).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-local-values-in-a-matrix/description/)

---
{{< youtube wdTRu9sarFA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
