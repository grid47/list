
+++
authors = ["grid47"]
title = "Leetcode 2319: Check if Matrix Is X-Matrix"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2319: Check if Matrix Is X-Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "l7O_4za547A"
youtube_upload_date="2022-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/l7O_4za547A/maxresdefault.webp"
comments = true
+++



---
A matrix is called an X-Matrix if all elements along the diagonals are non-zero, and all elements outside the diagonals are zero. Given a 2D integer array grid representing a matrix, return true if it is an X-Matrix, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an n x n matrix grid, where n is the number of rows and columns. The elements in the grid are integers.
- **Example:** `grid = [[1, 0, 0], [0, 2, 0], [0, 0, 3]]`
- **Constraints:**
	- 3 <= n <= 100
	- 0 <= grid[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the grid is an X-Matrix, otherwise return false.
- **Example:** `For grid = [[1, 0, 0], [0, 2, 0], [0, 0, 3]], the output is true.`
- **Constraints:**
	- The result should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if the matrix is an X-Matrix by checking if all diagonal elements are non-zero and all non-diagonal elements are zero.

- 1. Iterate through the matrix elements.
- 2. For each element at position (i, j):
-    a. If the element is on a diagonal (i == j or i + j == n - 1), check if it is non-zero.
-    b. If the element is not on a diagonal, check if it is zero.
- 3. If any condition fails, return false. If all conditions hold, return true.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is always square (n x n).
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1, 0, 0], [0, 2, 0], [0, 0, 3]]`  \
  **Explanation:** In this case, the matrix is an X-Matrix because the diagonal elements (1, 2, 3) are non-zero, and all other elements are zero.

- **Input:** `grid = [[1, 0, 0], [0, 0, 0], [0, 0, 3]]`  \
  **Explanation:** Here, the matrix is not an X-Matrix because the diagonal element at position (1,1) is 0, while it should be non-zero.

{{< dots >}}
## Approach 🚀
To determine whether the matrix is an X-Matrix, check if all diagonal elements are non-zero and all other elements are zero.

### Initial Thoughts 💭
- The diagonal elements are important, and we need to check if they are non-zero.
- All non-diagonal elements must be zero.
- The check can be performed by iterating through the matrix once and validating the diagonal and non-diagonal elements.
{{< dots >}}
### Edge Cases 🌐
- There should always be at least a 3x3 matrix, so no need to handle empty matrices.
- The solution should be efficient enough to handle a matrix of size up to 100x100.
- If any diagonal element is zero or any non-diagonal element is non-zero, return false.
- Ensure that the solution works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
bool checkXMatrix(vector<vector<int>>& g) {
for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[i].size(); ++j) {
        if (i == j || i + j == g.size() - 1) {
            if (g[i][j] == 0)
                return false;
        }
        else if (g[i][j] > 0)
            return false;
    }
return true;
}
```

This function checks if a given matrix `g` satisfies the conditions of an 'X Matrix'. The matrix must have non-zero values on its diagonals (top-left to bottom-right and top-right to bottom-left) and zero values elsewhere.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	bool checkXMatrix(vector<vector<int>>& g) {
	```
	Declare the method `checkXMatrix` that takes a 2D vector `g` (the matrix) as input and returns a boolean indicating whether it forms a valid 'X Matrix'.

2. **Outer Loop Initialization**
	```cpp
	for (int i = 0; i < g.size(); ++i)
	```
	Start an outer loop to iterate over the rows of the matrix `g`, using the variable `i` as the row index.

3. **Inner Loop Initialization**
	```cpp
	    for (int j = 0; j < g[i].size(); ++j) {
	```
	Start an inner loop to iterate over the columns of the matrix `g`, using the variable `j` as the column index.

4. **Diagonal Check**
	```cpp
	        if (i == j || i + j == g.size() - 1) {
	```
	Check if the current element `g[i][j]` lies on either of the two diagonals: top-left to bottom-right (`i == j`) or top-right to bottom-left (`i + j == g.size() - 1`).

5. **Zero Check on Diagonals**
	```cpp
	            if (g[i][j] == 0)
	```
	If the current element on the diagonal is 0, return `false` because diagonals must contain non-zero values.

6. **Return False for Invalid Element**
	```cpp
	                return false;
	```
	Return `false` if a diagonal element is found to be zero, invalidating the 'X Matrix'.

7. **Non-Diagonal Check**
	```cpp
	        else if (g[i][j] > 0)
	```
	If the current element is not on a diagonal and is greater than 0, return `false` because all non-diagonal elements must be 0.

8. **Return False for Invalid Non-Diagonal Element**
	```cpp
	            return false;
	```
	Return `false` if a non-diagonal element is greater than 0, invalidating the 'X Matrix'.

9. **Return True for Valid Matrix**
	```cpp
	return true;
	```
	Return `true` if the entire matrix is validated as an 'X Matrix' (i.e., all diagonal elements are non-zero, and all other elements are zero).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Since we need to check each element of the n x n matrix, the time complexity is O(n^2).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a constant amount of space to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-matrix-is-x-matrix/description/)

---
{{< youtube l7O_4za547A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
