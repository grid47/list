
+++
authors = ["grid47"]
title = "Leetcode 1605: Find Valid Matrix Given Row and Column Sums"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1605: Find Valid Matrix Given Row and Column Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ks6fGnXkHPg"
youtube_upload_date="2024-07-20"
youtube_thumbnail="https://i.ytimg.com/vi/Ks6fGnXkHPg/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m ;i++)
        for(int j = 0; j < n; j++) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i]-= ans[i][j];
            colSum[j]-= ans[i][j];
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to reconstruct a non-negative integer matrix given the sums of its rows and columns. Specifically, we are provided with two arrays: `rowSum` and `colSum`, where each element in `rowSum` represents the total of the corresponding row in the matrix, and each element in `colSum` represents the total of the corresponding column. Our goal is to create a matrix such that:
- The sum of each row matches the respective entry in `rowSum`.
- The sum of each column matches the respective entry in `colSum`.

### Approach

To solve this problem, we can employ a straightforward greedy algorithm. The idea is to iterate through each cell of the matrix and fill it with the minimum of the available sums from `rowSum` and `colSum`. After assigning a value to a cell, we update the corresponding row and column sums to reflect the remaining values.

The approach can be summarized in the following steps:

1. **Initialize the Matrix**: Create a matrix of size `m x n` (where `m` is the length of `rowSum` and `n` is the length of `colSum`) filled with zeros.

2. **Iterate Over Each Cell**: For each cell in the matrix:
   - Assign it the minimum of the corresponding row and column sums.
   - Update the row and column sums to reflect the remaining values after assigning the cell.

3. **Return the Result**: Finally, return the constructed matrix.

### Code Breakdown (Step by Step)

Here’s the detailed explanation of the provided code:

```cpp
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
```
- The `Solution` class contains a public method `restoreMatrix`, which accepts two vectors, `rowSum` and `colSum`, representing the sums of the rows and columns, respectively. The function returns a 2D vector representing the reconstructed matrix.

```cpp
        int m = rowSum.size(), n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
```
- We first determine the sizes of the row and column sums (`m` and `n`). Next, we initialize a 2D vector `ans` of size `m x n`, filled with zeros to hold the values of our matrix.

```cpp
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
```
- We use nested loops to iterate through each element of the matrix. The outer loop iterates over the rows, while the inner loop iterates over the columns.

```cpp
            ans[i][j] = min(rowSum[i], colSum[j]);
```
- For each cell at position `(i, j)`, we assign it the minimum value between `rowSum[i]` and `colSum[j]`. This ensures that we do not exceed the available sums when populating the matrix.

```cpp
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
```
- After assigning a value to `ans[i][j]`, we update the `rowSum` and `colSum` by subtracting the assigned value. This effectively reduces the remaining sum available for that particular row and column.

```cpp
        }
        return ans;
    }
};
```
- The loops continue until all cells in the matrix are filled. Finally, we return the completed matrix `ans`.

### Complexity

- **Time Complexity**: 
  - The overall time complexity is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns. This is because we need to visit each cell in the matrix once to fill it.

- **Space Complexity**: 
  - The space complexity is \(O(m \times n)\) due to the space required to store the resulting matrix.

### Conclusion

The provided implementation of the `restoreMatrix` function successfully reconstructs a non-negative integer matrix that satisfies the given row and column sums. The algorithm is efficient and straightforward, employing a greedy approach to ensure that the values assigned to the matrix do not exceed the available sums. 

**Key Aspects of the Solution**:
1. **Greedy Strategy**: The method relies on a greedy approach to fill the matrix, ensuring that we always assign the minimum possible value while respecting the constraints of the row and column sums.
2. **Efficiency**: The solution is efficient with a time complexity of \(O(m \times n)\), making it suitable for reasonably sized inputs.
3. **Clarity**: The code is easy to read and understand, with clear variable names and a logical flow.

In summary, this implementation effectively demonstrates how to reconstruct a matrix based on given constraints, providing an elegant solution to the problem. The approach is applicable in various scenarios where matrix construction based on constraints is required.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/)

---
{{< youtube Ks6fGnXkHPg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
