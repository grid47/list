
+++
authors = ["grid47"]
title = "Leetcode 498: Diagonal Traverse"
date = "2024-09-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 498: Diagonal Traverse in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/498.webp"
youtube = "xio2uEQQPZQ"
youtube_upload_date="2020-04-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/xio2uEQQPZQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/498.webp" 
    alt="A matrix where elements are traversed diagonally, each element softly glowing as it is visited."
    caption="Solution to LeetCode 498: Diagonal Traverse Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n matrix. The task is to return an array that contains all the elements of the matrix in diagonal order, starting from the top-left and moving diagonally towards the bottom-right. The diagonal order alternates between upward and downward diagonals.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n matrix where each element is an integer.
- **Example:** `[[1,2,3],[4,5,6],[7,8,9]]`
- **Constraints:**
	- 1 <= m, n <= 10^4
	- 1 <= m * n <= 10^4
	- -10^5 <= mat[i][j] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an array of integers, which represents all the elements of the matrix in diagonal order.
- **Example:** `[1, 2, 4, 7, 5, 3, 6, 8, 9]`
- **Constraints:**
	- The output array contains all the elements from the matrix in diagonal order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the matrix in diagonal order, alternating between upward and downward diagonals.

- 1. Iterate over all diagonals, starting from the top-left corner.
- 2. For each diagonal, alternate the direction of traversal (upward or downward).
- 3. Add elements to the result array in the correct diagonal order.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always have valid integer values.
- The matrix will have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1,2,3],[4,5,6],[7,8,9]]`  \
  **Explanation:** In this example, the elements are traversed diagonally starting from the top-left and moving towards the bottom-right, alternating between upward and downward diagonals.

{{< dots >}}
## Approach 🚀
The solution involves iterating over all diagonals and alternating the direction of traversal. Each element is added to the result array in the correct order.

### Initial Thoughts 💭
- The traversal alternates between upward and downward diagonals.
- We need to handle each diagonal separately and ensure the correct order of traversal.
- We can efficiently handle the diagonals by iterating over each one and managing the direction of traversal.
{{< dots >}}
### Edge Cases 🌐
- The matrix will always contain at least one element.
- The solution must be efficient enough to handle large matrices (up to 10^4 elements).
- The matrix may contain negative and large values, but they should not affect the solution.
- Ensure the algorithm is optimized for large matrices, especially when m * n approaches 10^4.
{{< dots >}}
## Code 💻
```cpp
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> res;
    for(int s = 0; s <= m + n - 2; s++) {
        for(int x = 0; x <= s; x++) {
            int i = x;
            int j = s - i;
            if(s%2 == 0) swap(i, j);
            if(i >= m || j >= n) continue;
            res.push_back(mat[i][j]);
        }
    }
    return res;
}
```

This solution calculates the diagonal order traversal of a matrix, alternating between top-down and bottom-up diagonals.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
	```
	Defines the method `findDiagonalOrder` which takes a 2D matrix `mat` and returns a vector of integers representing the diagonal order traversal.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Initializes variables `m` and `n` to store the number of rows and columns in the matrix `mat`, respectively.

3. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Declares a vector `res` that will store the result of the diagonal order traversal.

4. **Loop Structure**
	```cpp
	    for(int s = 0; s <= m + n - 2; s++) {
	```
	Outer loop iterating over the sum `s` of the row and column indices. This loop will control the traversal of diagonals in the matrix.

5. **Loop Structure**
	```cpp
	        for(int x = 0; x <= s; x++) {
	```
	Inner loop iterating over values `x` which represent the row index in the diagonal. It ensures all elements in the current diagonal are processed.

6. **Variable Assignment**
	```cpp
	            int i = x;
	```
	Assigns the value of `x` to `i`, representing the row index of the current element in the diagonal.

7. **Variable Assignment**
	```cpp
	            int j = s - i;
	```
	Calculates the column index `j` as `s - i`, ensuring that the sum of `i` and `j` is equal to `s`.

8. **Conditional Check**
	```cpp
	            if(s%2 == 0) swap(i, j);
	```
	Checks if the sum `s` is even. If so, it swaps `i` and `j` to alternate the diagonal traversal direction.

9. **Boundary Check**
	```cpp
	            if(i >= m || j >= n) continue;
	```
	Checks if the row index `i` or column index `j` is out of bounds of the matrix. If either is out of bounds, it skips the current iteration.

10. **Result Update**
	```cpp
	            res.push_back(mat[i][j]);
	```
	Adds the matrix element at position `[i][j]` to the result vector `res`.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result vector `res` containing the elements in diagonal order.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) as we visit each element of the matrix once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) for storing the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/diagonal-traverse/description/)

---
{{< youtube xio2uEQQPZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
