
+++
authors = ["grid47"]
title = "Leetcode 2482: Difference Between Ones and Zeros in Row and Column"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2482: Difference Between Ones and Zeros in Row and Column in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "JwuTsHDJVdI"
youtube_upload_date="2023-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/JwuTsHDJVdI/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n binary matrix grid. You need to create a difference matrix diff where each element diff[i][j] is calculated by summing the number of ones and subtracting the number of zeros in the respective row and column.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary matrix of size m x n, where each element is either 0 or 1.
- **Example:** `grid = [[1,0,1],[0,1,1],[1,1,0]]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the difference matrix diff, which is of the same size as the input matrix grid.
- **Example:** `Output: [[4, 4, 2], [2, 2, 4], [4, 4, 2]]`
- **Constraints:**
	- The output should be a matrix of integers with the same dimensions as the input.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the difference matrix based on the number of ones and zeros in each row and column.

- 1. First, calculate the number of ones and zeros in each row and column.
- 2. Use the formula for diff[i][j] = onesRow_i + onesCol_j - zerosRow_i - zerosCol_j to calculate each value of the matrix diff.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always contain binary values (0 or 1).
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grid = [[1,0,1],[0,1,1],[1,1,0]]`  \
  **Explanation:** For each position in the grid, the number of ones and zeros in its respective row and column are used to calculate the difference matrix. The result will depend on how the number of ones and zeros are distributed.

{{< dots >}}
## Approach 🚀
We can approach this problem by first calculating the number of ones and zeros in each row and column, then using that data to calculate the difference matrix.

### Initial Thoughts 💭
- We need to efficiently calculate the number of ones and zeros in each row and column, which can be done in O(m*n) time.
- Once we have the row and column sums, calculating the diff matrix is straightforward.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the grid, as m and n are guaranteed to be at least 1.
- The maximum size of m*n is 10^5, which is feasible for a solution with O(m*n) time complexity.
- If the grid is filled entirely with zeros, the diff matrix will be filled with zeros.
- The problem guarantees that m and n are within the given constraints.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> row(m), col(n);
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        row[i] += grid[i][j];
        col[j] += grid[i][j];
    }

    vector<vector<int>> g(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        g[i][j] = 2 * row[i] + 2 * col[j] - m - n;
    }
    return g;
}
```

This function calculates a matrix `g` where each element is derived from the number of 1's in the respective row and column of the input `grid`. The transformation computes a new value for each cell based on the formula `2 * row[i] + 2 * col[j] - m - n`, where `row[i]` and `col[j]` represent the count of 1's in the respective row and column.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
	```
	This line defines the function `onesMinusZeros`, which takes a 2D vector `grid` as input and returns a 2D vector `g` as the output.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	The dimensions of the grid are stored in `m` (number of rows) and `n` (number of columns).

3. **Vector Initialization**
	```cpp
	    vector<int> row(m), col(n);
	```
	Two vectors, `row` and `col`, are initialized to store the counts of 1's in each row and column of the grid.

4. **Row and Column Counting**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Loop through each row of the grid.

5. **Nested Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Nested loop to iterate over each column of the grid.

6. **Row Counting**
	```cpp
	        row[i] += grid[i][j];
	```
	Increment the count for the current row `i` based on the value of the cell `grid[i][j]`.

7. **Column Counting**
	```cpp
	        col[j] += grid[i][j];
	```
	Increment the count for the current column `j` based on the value of the cell `grid[i][j]`.

8. **Matrix Initialization**
	```cpp
	    vector<vector<int>> g(m, vector<int>(n, 0));
	```
	Initialize a new matrix `g` of size `m x n` with all elements set to 0.

9. **Matrix Calculation Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Loop through each row of the result matrix `g`.

10. **Nested Matrix Calculation Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Nested loop to iterate through each column of the result matrix `g`.

11. **Matrix Calculation**
	```cpp
	        g[i][j] = 2 * row[i] + 2 * col[j] - m - n;
	```
	Each element of the result matrix `g[i][j]` is computed using the formula `2 * row[i] + 2 * col[j] - m - n`, where `row[i]` and `col[j]` represent the count of 1's in the respective row and column.

12. **Return Statement**
	```cpp
	    return g;
	```
	Return the resulting matrix `g` which has been calculated based on the counts of 1's in the respective rows and columns.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m*n)
- **Average Case:** O(m*n)
- **Worst Case:** O(m*n)

The time complexity is O(m*n) as we need to traverse the grid to compute row and column sums and then calculate the diff matrix.

### Space Complexity 💾
- **Best Case:** O(m*n)
- **Worst Case:** O(m*n)

The space complexity is O(m*n) due to the storage of the input grid and the result matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/)

---
{{< youtube JwuTsHDJVdI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
