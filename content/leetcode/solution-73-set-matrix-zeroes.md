
+++
authors = ["grid47"]
title = "Leetcode 73: Set Matrix Zeroes"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 73: Set Matrix Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/73.webp"
youtube = "T41rL0L3Pnw"
youtube_upload_date="2021-01-13"
youtube_thumbnail="https://i.ytimg.com/vi/T41rL0L3Pnw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/73.webp" 
    alt="A calm matrix with soft light illuminating areas that need to be reset to zero."
    caption="Solution to LeetCode 73: Set Matrix Zeroes Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n matrix of integers. Whenever an element in the matrix is 0, you need to set all elements in the corresponding row and column to 0, but the operation must be done in place. This means you cannot use extra space for another matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix of size m x n containing integers.
- **Example:** `matrix = [[3, 5, 1], [4, 0, 2], [7, 8, 9]]`
- **Constraints:**
	- 1 <= m, n <= 200
	- -231 <= matrix[i][j] <= 231 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the transformed matrix where rows and columns containing zeros are set to zero in place.
- **Example:** `[[3, 0, 1], [0, 0, 0], [7, 0, 9]]`
- **Constraints:**
	- The output should be the matrix itself, modified in place.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the matrix in place by setting entire rows and columns to 0 whenever a zero is encountered.

- Identify if the first row or column contains a zero, and mark these as flags.
- Use the first row and column to mark which rows and columns need to be zeroed.
- Iterate through the rest of the matrix and use the flags to set the corresponding rows and columns to zero.
- Handle the first row and column separately if necessary.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is a 2D array with at least one element.
- All elements in the matrix are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `matrix = [[3, 5, 1], [4, 0, 2], [7, 8, 9]]`  \
  **Explanation:** The second row has a 0 at (1,1). Hence, the entire second row and the second column are set to 0.

- **Input:** `matrix = [[1, 2, 3], [4, 0, 6], [7, 8, 9]]`  \
  **Explanation:** The second row has a 0 at (1,1). Hence, the entire second row and the second column are set to 0.

{{< dots >}}
## Approach 🚀
The solution involves using the first row and column to store the state of rows and columns that need to be zeroed. This allows the matrix to be modified in place without using additional space.

### Initial Thoughts 💭
- The matrix needs to be transformed in place without extra space.
- We can use the first row and column to store flags for marking rows and columns that need to be zeroed.
- Using a flag system for the first row and column will prevent overwriting important data during the transformation.
{{< dots >}}
### Edge Cases 🌐
- If the matrix has only one row or one column, it must be handled appropriately.
- Consider cases where the matrix size is at the upper limit (200x200).
- Ensure that negative numbers and boundary values are handled correctly.
- The solution must be implemented in-place and must not use additional matrices for storage.
{{< dots >}}
## Code 💻
```cpp
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Check if first row has a zero
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column has a zero
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Mark the rows and columns with zeros using the first row and column
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    // Set the rows and columns marked as zero to zero
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set the first row to zero if necessary
    if (firstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    // Set the first column to zero if necessary
    if (firstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
}
```

This code sets all elements in a matrix to zero if their corresponding row or column contains a zero.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void setZeroes(vector<vector<int>>& matrix) {
	```
	Declares a function `setZeroes` that takes a 2D vector `matrix` as input and modifies it in-place.

2. **Variable Initialization**
	```cpp
	    int m = matrix.size(), n = matrix[0].size();
	```
	Initializes variables `m` and `n` to store the number of rows and columns in the matrix.

3. **Variable Initialization**
	```cpp
	    bool firstRowZero = false, firstColZero = false;
	```
	Initializes boolean flags `firstRowZero` and `firstColZero` to track if the first row and column contain zeros.

4. **Loop Iteration**
	```cpp
	    for (int j = 0; j < n; j++) {
	        if (matrix[0][j] == 0) {
	            firstRowZero = true;
	            break;
	        }
	    }
	```
	Iterates through the first row of the matrix and sets `firstRowZero` to `true` if a zero is found.

5. **Loop Iteration**
	```cpp
	    for (int i = 0; i < m; i++) {
	        if (matrix[i][0] == 0) {
	            firstColZero = true;
	            break;
	        }
	    }
	```
	Iterates through the first column of the matrix and sets `firstColZero` to `true` if a zero is found.

6. **Nested Loops**
	```cpp
	    for (int i = 1; i < m; i++) {
	        for (int j = 1; j < n; j++) {
	            if (matrix[i][j] == 0) {
	                matrix[i][0] = matrix[0][j] = 0;
	            }
	        }
	    }
	```
	Iterates through the matrix, excluding the first row and column. If a zero is found, marks the corresponding row and column using the first row and column as markers.

7. **Nested Loops**
	```cpp
	    for (int i = 1; i < m; i++) {
	        for (int j = 1; j < n; j++) {
	            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
	                matrix[i][j] = 0;
	            }
	        }
	    }
	```
	Iterates through the matrix again, setting elements to zero based on the markers in the first row and column.

8. **Conditional**
	```cpp
	    if (firstRowZero) {
	        for (int j = 0; j < n; j++) {
	            matrix[0][j] = 0;
	        }
	    }
	```
	If the first row was originally zero, set all elements in the first row to zero.

9. **Conditional**
	```cpp
	    if (firstColZero) {
	        for (int i = 0; i < m; i++) {
	            matrix[i][0] = 0;
	        }
	    }
	```
	If the first column was originally zero, set all elements in the first column to zero.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we iterate through the entire matrix twice.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because the solution is implemented in-place without additional storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/set-matrix-zeroes/description/)

---
{{< youtube T41rL0L3Pnw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
