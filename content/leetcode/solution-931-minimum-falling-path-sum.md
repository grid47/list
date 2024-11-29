
+++
authors = ["grid47"]
title = "Leetcode 931: Minimum Falling Path Sum"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 931: Minimum Falling Path Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "b_F3mz9l-uQ"
youtube_upload_date="2024-01-19"
youtube_thumbnail="https://i.ytimg.com/vi/b_F3mz9l-uQ/maxresdefault.jpg"
comments = true
+++



---
Given a square matrix of integers, your task is to find the minimum sum of any falling path through the matrix. A falling path starts at any element in the first row and chooses the next element from the row directly below it, which can be either directly below, diagonally left, or diagonally right.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an n x n matrix, where each element represents a value. You need to find the falling path with the minimum sum.
- **Example:** `Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]`
- **Constraints:**
	- n == matrix.length == matrix[i].length
	- 1 <= n <= 100
	- -100 <= matrix[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum sum of a falling path.
- **Example:** `Output: 13`
- **Constraints:**
	- The matrix will always be a square.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the falling path with the minimum sum, update the matrix values row by row, adding the smallest possible sum from the previous row to the current row.

- 1. Start from the second row and update each element by adding the minimum of the three possible elements from the previous row (directly above, diagonally left, diagonally right).
- 2. Once the matrix is updated, the minimum sum will be the smallest value in the last row.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is square, and all elements are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]`  \
  **Explanation:** To get the minimum falling path sum, start with any element in the first row, and for each subsequent row, pick the minimum value from the adjacent elements in the previous row. For this example, the minimum sum is 13, which is the path [1, 5, 7].

- **Input:** `Input: matrix = [[-19,57],[-40,-5]]`  \
  **Explanation:** For this example, the minimum falling path sum is -59, which follows the path [-19, -40].

{{< dots >}}
## Approach 🚀
We solve the problem using dynamic programming by updating the matrix to store the minimum path sum at each position. This allows us to compute the minimum sum in a bottom-up manner.

### Initial Thoughts 💭
- The problem can be solved efficiently using dynamic programming, where each element in the matrix is updated to represent the minimum falling path sum up to that point.
- By using dynamic programming, we avoid recalculating the same subproblems multiple times, making the solution more efficient.
{{< dots >}}
### Edge Cases 🌐
- The matrix will not be empty, as per the constraints.
- The algorithm should handle matrices up to 100x100 efficiently.
- The algorithm should work for matrices with negative numbers and ensure the minimum path sum is correctly calculated.
- The matrix is always square, which simplifies the implementation.
{{< dots >}}
## Code 💻
```cpp
int minFallingPathSum(vector<vector<int>>& mtx) {
    
    int m = mtx.size(), n = mtx[0].size();

    for(int i = 1; i < m; i++)
    for(int j = 0; j < n; j++) {

        int l = max(j - 1, 0);
        int r = min(j + 1, n - 1);

        mtx[i][j] += min(mtx[i- 1][l], min(mtx[i - 1][j], mtx[i - 1][r]));

    }

    int res = mtx[m - 1][0];
    for(int j = 0; j < n; j++)
    res = min(res, mtx[m - 1][j]);

    return res;
}
```

The function 'minFallingPathSum' calculates the minimum sum of a falling path from the top to the bottom of a matrix, where each step can only move to the left, down, or right from a given cell.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minFallingPathSum(vector<vector<int>>& mtx) {
	```
	Define the function 'minFallingPathSum', which takes a matrix 'mtx' and returns the minimum sum of a falling path.

2. **Matrix Size**
	```cpp
	    int m = mtx.size(), n = mtx[0].size();
	```
	Store the number of rows 'm' and columns 'n' in the matrix 'mtx'.

3. **Outer Loop**
	```cpp
	    for(int i = 1; i < m; i++)
	```
	Loop through each row starting from the second row (index 1), as the first row does not require modification.

4. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Loop through each column 'j' in the current row 'i'.

5. **Left Bound Calculation**
	```cpp
	        int l = max(j - 1, 0);
	```
	Calculate the index 'l' of the left cell. If 'j - 1' is less than 0, set 'l' to 0 to prevent out-of-bounds access.

6. **Initialize Result**
	```cpp
	    int res = mtx[m - 1][0];
	```
	Initialize 'res' to the value of the first element in the last row of the matrix, which will be used to track the minimum sum.

7. **Final Row Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Loop through each element in the last row of the matrix to find the minimum value.

8. **Update Minimum Result**
	```cpp
	    res = min(res, mtx[m - 1][j]);
	```
	Update 'res' to the minimum value between the current 'res' and the current element in the last row of the matrix.

9. **Return Result**
	```cpp
	    return res;
	```
	Return the minimum falling path sum from the top to the bottom of the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2), where n is the number of rows (or columns) in the matrix, as we traverse each element once and update it based on the previous row.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we update the matrix in place and do not use any extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-falling-path-sum/description/)

---
{{< youtube b_F3mz9l-uQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
