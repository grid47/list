
+++
authors = ["grid47"]
title = "Leetcode 1572: Matrix Diagonal Sum"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1572: Matrix Diagonal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "5TLlr3y3Iww"
youtube_upload_date="2023-05-09"
youtube_thumbnail="https://i.ytimg.com/vi/5TLlr3y3Iww/maxresdefault.jpg"
comments = true
+++



---
You are given a square matrix of integers. Your task is to calculate the sum of all the elements located on the primary diagonal and the secondary diagonal, excluding the element that appears on both diagonals (i.e., the center element in an odd-sized matrix).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a square matrix, where each element is an integer. The matrix has equal number of rows and columns.
- **Example:** `Input: mat = [[3, 1, 2], [4, 5, 6], [7, 8, 9]]`
- **Constraints:**
	- 1 <= n <= 100
	- 1 <= mat[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of the elements on both the primary and secondary diagonals. If the matrix size is odd, subtract the center element once to avoid double-counting.
- **Example:** `Output: 25`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the sum of the diagonal elements efficiently without counting the center element twice.

- Iterate through the matrix and sum the elements on the primary diagonal (mat[i][i]) and secondary diagonal (mat[i][n-i-1]).
- If the matrix size is odd, subtract the center element (mat[n//2][n//2]) once as it's counted in both diagonals.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is square, meaning the number of rows is equal to the number of columns.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: mat = [[3, 1, 2], [4, 5, 6], [7, 8, 9]]`  \
  **Explanation:** The diagonals sum: 3 + 5 + 9 + 2 + 7 = 25. No element is counted twice.

- **Input:** `Example 2: mat = [[1, 1, 1], [1, 1, 1], [1, 1, 1]]`  \
  **Explanation:** The diagonals sum: 1 + 1 + 1 + 1 + 1 = 5. The center element is counted only once.

- **Input:** `Example 3: mat = [[5]]`  \
  **Explanation:** Only one element exists, and that is the center element. The sum is 5.

{{< dots >}}
## Approach 🚀
The goal is to sum the elements along both diagonals and avoid double-counting the center element for odd-sized matrices. This can be achieved by iterating through the matrix and updating the sum accordingly.

### Initial Thoughts 💭
- We need to calculate the sum of two diagonals of a square matrix.
- In case of an odd-sized matrix, the center element is part of both diagonals, so it should be counted once.
- By iterating through the matrix, we can directly access the elements on both diagonals using indices.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always have at least one row and one column.
- The solution should handle the maximum size matrix efficiently, i.e., 100x100.
- In a 1x1 matrix, the single element is both on the primary and secondary diagonal.
- Ensure that the solution works within the time limits for large matrices (100x100).
{{< dots >}}
## Code 💻
```cpp
int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size(), sum = 0;
    for(int i = 0; i < n; i++)
        sum += mat[i][i] + mat[n - 1 - i][i];
    if(n % 2) sum -= mat[n/2][n/2];
    return sum;
}
```

This function calculates the sum of the diagonals of a square matrix. If the matrix has an odd size, it subtracts the middle element to avoid counting it twice.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int diagonalSum(vector<vector<int>>& mat) {
	```
	Defines the function `diagonalSum` that takes a square matrix `mat` and calculates the sum of its diagonals.

2. **Variable Initialization**
	```cpp
	    int n = mat.size(), sum = 0;
	```
	Initializes the variable `n` to the size of the matrix and `sum` to zero, which will hold the sum of the diagonal elements.

3. **Loop Start**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a loop that iterates over the indices of the matrix, from `i = 0` to `i = n-1`.

4. **Sum Diagonal Elements**
	```cpp
	        sum += mat[i][i] + mat[n - 1 - i][i];
	```
	Adds the elements from both diagonals of the matrix: `mat[i][i]` (primary diagonal) and `mat[n - 1 - i][i]` (secondary diagonal).

5. **Odd Size Check**
	```cpp
	    if(n % 2) sum -= mat[n/2][n/2];
	```
	Checks if the matrix size `n` is odd. If so, it subtracts the center element to avoid double-counting it (as it appears in both diagonals).

6. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the calculated sum of the diagonals after the loop finishes and adjustment for odd-sized matrices is done.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only iterate once through the matrix to calculate the sum of diagonal elements.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a constant amount of space for the sum and a few variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/matrix-diagonal-sum/description/)

---
{{< youtube 5TLlr3y3Iww >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
