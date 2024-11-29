
+++
authors = ["grid47"]
title = "Leetcode 1329: Sort the Matrix Diagonally"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1329: Sort the Matrix Diagonally in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0FheWgwnG-w"
youtube_upload_date="2020-06-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0FheWgwnG-w/maxresdefault.webp"
comments = true
+++



---
You are given a matrix `mat` of integers with dimensions `m x n`. A matrix diagonal is a sequence of matrix elements that start from some cell in the topmost row or leftmost column and go diagonally towards the bottom-right corner. Your task is to sort each matrix diagonal in ascending order and return the resulting matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer matrix `mat` of dimensions `m x n`.
- **Example:** `For example, given mat = [[5, 9, 3], [8, 6, 1], [7, 4, 2]], the task is to sort each diagonal of this matrix.`
- **Constraints:**
	- 1 <= m, n <= 100
	- 1 <= mat[i][j] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the matrix where each diagonal is sorted in ascending order.
- **Example:** `For mat = [[5, 9, 3], [8, 6, 1], [7, 4, 2]], the output would be [[1, 3, 2], [4, 5, 1], [7, 6, 9]].`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Sort the elements along each diagonal of the matrix in ascending order while keeping the relative positions of the diagonals unchanged.

- 1. Identify all diagonals in the matrix.
- 2. For each diagonal, store the elements and sort them in ascending order.
- 3. Replace the original elements of each diagonal with the sorted values.
- 4. Return the modified matrix.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is not empty, and each element is an integer between 1 and 100.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mat = [[5, 9, 3], [8, 6, 1], [7, 4, 2]]`  \
  **Explanation:** The diagonals are [5], [9, 8], [3, 6, 7], [1, 4], and [2]. After sorting each diagonal, we get the matrix [[1, 3, 2], [4, 5, 1], [7, 6, 9]].

- **Input:** `Input: mat = [[10, 21, 30], [4, 15, 24], [5, 6, 23]]`  \
  **Explanation:** The diagonals are [10], [21, 4], [30, 15, 5], [24, 6], and [23]. After sorting each diagonal, we get the matrix [[4, 15, 23], [5, 21, 30], [10, 6, 24]].

{{< dots >}}
## Approach 🚀
The algorithm extracts the elements along each diagonal, sorts them, and then places the sorted values back in the matrix, preserving the original structure of the matrix.

### Initial Thoughts 💭
- Each diagonal is independent and can be sorted individually.
- We need to identify and extract diagonals before sorting them and placing the sorted values back into the matrix.
{{< dots >}}
### Edge Cases 🌐
- An empty matrix will not be provided based on the problem constraints.
- The matrix could be as large as 100x100, but the solution should still be efficient.
- When all elements in a diagonal are the same, the diagonal will remain unchanged after sorting.
- The matrix has at least one row and column, and each element is between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        mp[i-j].push(mat[i][j]);

    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        mat[i][j] = mp[i-j].top();
        mp[i-j].pop();
    }
    return mat;
}
```

This function sorts the diagonals of a matrix. It uses a priority queue to store and sort the elements on each diagonal. The matrix is then updated with sorted elements, effectively sorting each diagonal in ascending order.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
	```
	This line declares the 'diagonalSort' function that takes a 2D matrix 'mat' as input and returns the matrix with diagonals sorted in ascending order.

2. **Matrix Dimensions Calculation**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	The dimensions of the matrix are calculated, where 'm' is the number of rows and 'n' is the number of columns.

3. **Priority Queue Declaration**
	```cpp
	    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
	```
	A map 'mp' is declared where the keys represent the diagonals (calculated by the difference 'i-j'), and the values are priority queues that store the diagonal elements in ascending order.

4. **Outer Loop - Row Iteration**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	The outer loop iterates over each row of the matrix.

5. **Inner Loop - Column Iteration**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	The inner loop iterates over each column in the current row.

6. **Push Diagonal Element into Queue**
	```cpp
	        mp[i-j].push(mat[i][j]);
	```
	The element at position (i, j) is pushed into the priority queue corresponding to the diagonal (i-j).

7. **Reprocess Matrix with Sorted Diagonals**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	The second loop starts to reprocess the matrix and fill each diagonal with sorted elements.

8. **Set Sorted Diagonal Element**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This inner loop iterates through each column of the current row to replace the matrix elements with the sorted elements from the corresponding priority queue.

9. **Replace Element with Sorted Value**
	```cpp
	        mat[i][j] = mp[i-j].top();
	```
	The top element (smallest element) from the priority queue for the current diagonal is placed into the matrix at position (i, j).

10. **Pop the Used Element**
	```cpp
	        mp[i-j].pop();
	```
	After placing the smallest element into the matrix, it is removed from the priority queue for the current diagonal.

11. **Return Sorted Matrix**
	```cpp
	    return mat;
	```
	The sorted matrix is returned after all diagonals have been processed and updated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n * log(m))
- **Average Case:** O(m * n * log(m))
- **Worst Case:** O(m * n * log(m))

The best, average, and worst cases all involve sorting each diagonal, which requires sorting a maximum of m elements.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to storing the diagonals and the original matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sort-the-matrix-diagonally/description/)

---
{{< youtube 0FheWgwnG-w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
