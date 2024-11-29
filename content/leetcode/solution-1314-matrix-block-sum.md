
+++
authors = ["grid47"]
title = "Leetcode 1314: Matrix Block Sum"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1314: Matrix Block Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jor18pkf9EE"
youtube_upload_date="2020-11-07"
youtube_thumbnail="https://i.ytimg.com/vi/jor18pkf9EE/maxresdefault.jpg"
comments = true
+++



---
Given a matrix of integers, where each element represents a value, you need to calculate the sum of all elements in a sub-matrix for each cell. For each cell, the sub-matrix includes all elements within a square grid of size (2k+1) x (2k+1) centered at that cell. If the sub-matrix extends beyond the boundaries of the matrix, only the valid elements within the matrix should be considered.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D matrix of integers and an integer k. The matrix is represented as a list of lists, where each list represents a row. The integer k represents the size of the square grid to calculate the sum for each cell.
- **Example:** `mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1`
- **Constraints:**
	- 1 <= m, n, k <= 100
	- 1 <= mat[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a matrix where each element represents the sum of the valid sub-matrix for that position in the original matrix.
- **Example:** `For mat = [[1,2,3],[4,5,6],[7,8,9]] and k = 1, the output is [[12, 21, 16], [27, 45, 33], [24, 39, 28]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the sum of each sub-matrix centered at each cell in the matrix while considering the bounds of the matrix.

- 1. Use dynamic programming to calculate prefix sums of the matrix.
- 2. For each cell in the matrix, calculate the sum of its sub-matrix using the prefix sum array.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is always valid, with at least one row and one column.
- The integer k will be chosen such that the sub-matrix can be calculated within the matrix bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `For mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]] and k = 1, the sum of the 3x3 grid surrounding each element is calculated. For example, for the element at mat[1][1] (which is 5), the sum of the 3x3 grid is 45.`  \
  **Explanation:** The sum is calculated by considering the elements within a 3x3 grid centered around each element, ensuring that any invalid positions outside the matrix bounds are ignored.

{{< dots >}}
## Approach 🚀
The approach utilizes a prefix sum technique to efficiently calculate the sum of each sub-matrix by avoiding recalculation of overlapping sub-matrices.

### Initial Thoughts 💭
- The brute force solution could involve recalculating sums for each cell, but this would be inefficient.
- By using a prefix sum array, we can quickly compute the sum of any sub-matrix in constant time.
- We will first compute the prefix sum array for the entire matrix, and then for each element, calculate the sum of its surrounding grid using this array.
{{< dots >}}
### Edge Cases 🌐
- An empty matrix (0x0 matrix) should return an empty result.
- The solution should handle large matrices up to size 100x100 efficiently.
- All elements in the matrix could be the same, or the matrix could contain very large or small values.
- The size of the matrix and the value of k are constrained to ensure that the solution remains efficient.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {

    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

    for(int i = 1; i < m + 1; i++)
    for(int j = 1; j < n + 1; j++)
    sum[i][j] = mat[i - 1][j - 1] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
    
    vector<vector<int>> res(m, vector<int>(n));

    for(int i = 1; i < m + 1; i++)
    for(int j = 1; j < n + 1; j++) {

        int r1 = min(i + k, m);
        int c1 = min(j + k, n);
        int r2 = max(i - k, 1);
        int c2 = max(j - k, 1);

        res[i - 1][j - 1] = sum[r1][c1] - sum[r1][c2 - 1] - sum[r2 - 1][c1] + sum[r2 - 1][c2 - 1];

    }
    
    return res;
}
```

This function calculates the sum of elements in a k x k block surrounding each element in a matrix, using a prefix sum approach to optimize the computation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
	```
	The function 'matrixBlockSum' is declared, which takes a matrix 'mat' and an integer 'k' as input. The goal of the function is to calculate the sum of each element's block of size k x k.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	The variables 'm' and 'n' are initialized to represent the number of rows and columns in the matrix 'mat', respectively.

3. **Prefix Sum Initialization**
	```cpp
	    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
	```
	A 'sum' matrix is initialized to store the prefix sum of the input matrix 'mat'. It has dimensions (m + 1) x (n + 1), with all values initialized to zero.

4. **Prefix Sum Calculation**
	```cpp
	    for(int i = 1; i < m + 1; i++)
	    for(int j = 1; j < n + 1; j++)
	    sum[i][j] = mat[i - 1][j - 1] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
	```
	This nested loop computes the prefix sum for each element of the 'sum' matrix. The value at each position is the sum of elements from the top-left corner of the matrix.

5. **Result Matrix Initialization**
	```cpp
	    vector<vector<int>> res(m, vector<int>(n));
	```
	A 'res' matrix is initialized to store the final result, which will hold the sum of each k x k block around every element in the matrix.

6. **Outer Loop for Rows**
	```cpp
	    for(int i = 1; i < m + 1; i++)
	```
	The outer loop iterates over each row of the matrix to calculate the k x k sum block for each element.

7. **Inner Loop for Columns**
	```cpp
	    for(int j = 1; j < n + 1; j++) {
	```
	The inner loop iterates over each column of the matrix, processing every element to calculate its k x k sum block.

8. **Boundary Calculation**
	```cpp
	        int r1 = min(i + k, m);
	        int c1 = min(j + k, n);
	        int r2 = max(i - k, 1);
	        int c2 = max(j - k, 1);
	```
	These lines calculate the boundaries of the k x k block surrounding the current element. The boundaries are adjusted to ensure they stay within the matrix dimensions.

9. **Block Sum Calculation**
	```cpp
	        res[i - 1][j - 1] = sum[r1][c1] - sum[r1][c2 - 1] - sum[r2 - 1][c1] + sum[r2 - 1][c2 - 1];
	```
	Using the prefix sum array, this line computes the sum of elements within the k x k block for the current matrix element, and stores the result in the 'res' matrix.

10. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the 'res' matrix, which contains the sum of elements for each k x k block surrounding each element in the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we compute the prefix sum array in O(m * n) time, and for each cell, we calculate the sub-matrix sum in constant time.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the storage of the prefix sum array and the result matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/matrix-block-sum/description/)

---
{{< youtube jor18pkf9EE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
