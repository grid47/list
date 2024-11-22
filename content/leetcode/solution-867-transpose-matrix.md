
+++
authors = ["grid47"]
title = "Leetcode 867: Transpose Matrix"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 867: Transpose Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DzMT3bDgVn0"
youtube_upload_date="2023-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/DzMT3bDgVn0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> A) {
        int M = A.size(), N = A[0].size();
        vector<vector<int>> B(N, vector<int>(M, 0));
        for (int j = 0; j < N; j++)
            for (int i = 0; i < M; i++)
                B[j][i] = A[i][j];
        return B;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to implement a **matrix transpose** function. The task is to take a given matrix (a 2D array) and return its transpose. The **transpose** of a matrix is obtained by swapping its rows and columns. Specifically, if a matrix `A` is of size `MxN`, its transpose `B` will be of size `NxM`, and element `A[i][j]` will be placed at `B[j][i]`.

### Problem Explanation

Given a matrix `A`, you need to produce a matrix `B` such that:
- `B[j][i] = A[i][j]`
- The number of rows in matrix `A` becomes the number of columns in matrix `B`, and vice versa.

For example, if the input matrix `A` is:
```
1 2 3
4 5 6
```

The transpose of matrix `A` will be:
```
1 4
2 5
3 6
```

In this example, matrix `A` is a 2x3 matrix (2 rows and 3 columns), and its transpose `B` is a 3x2 matrix (3 rows and 2 columns).

### Approach

The approach to solve this problem involves:
1. **Identifying the dimensions**: Determine the number of rows (`M`) and columns (`N`) in the given matrix `A`.
2. **Creating the transposed matrix**: Initialize a new matrix `B` of size `N x M` to store the transposed values.
3. **Filling the transposed matrix**: Iterate through each element of matrix `A` and assign `A[i][j]` to `B[j][i]`.
4. **Returning the transposed matrix**: After the transformation is complete, return the matrix `B`.

The key observation here is that the transpose operation involves swapping the indices of the elements, i.e., rows become columns and columns become rows.

### Code Breakdown (Step by Step)

1. **Matrix Initialization and Size Determination**

```cpp
int M = A.size(), N = A[0].size();
```

- The first line of code retrieves the dimensions of the input matrix `A`. `M` represents the number of rows in `A`, and `N` represents the number of columns in `A`. This is done using the `.size()` function for the 2D vector `A`. 
- The matrix `A` is assumed to be non-empty, so `A[0].size()` is used to obtain the number of columns, which is assumed to be consistent across all rows (i.e., `A` is a well-formed matrix).

2. **Creating the Transposed Matrix**

```cpp
vector<vector<int>> B(N, vector<int>(M, 0));
```

- A new matrix `B` of size `N x M` is created, which will store the transposed values. Here, `N` is the number of rows in the transposed matrix (which is equal to the number of columns in the original matrix `A`), and `M` is the number of columns in the transposed matrix (which is equal to the number of rows in `A`).
- The matrix is initialized with all elements set to `0` using the constructor `vector<int>(M, 0)`, which creates a vector of size `M` filled with `0`s. The outer vector is then repeated `N` times to form the `N x M` matrix.

3. **Filling the Transposed Matrix**

```cpp
for (int j = 0; j < N; j++)
    for (int i = 0; i < M; i++)
        B[j][i] = A[i][j];
```

- The nested `for` loops iterate over each element of the input matrix `A`. The outer loop runs over the columns of `A` (indexed by `j`), and the inner loop runs over the rows of `A` (indexed by `i`).
- The assignment `B[j][i] = A[i][j]` swaps the row and column indices to perform the transpose. For each element in the original matrix, the element at position `(i, j)` in `A` is placed at position `(j, i)` in `B`.
  
4. **Returning the Transposed Matrix**

```cpp
return B;
```

- After the loops complete, the matrix `B` will contain the transposed version of matrix `A`. The function returns the transposed matrix `B`.

### Complexity

#### Time Complexity:
The time complexity of this solution is `O(M * N)`, where:
- `M` is the number of rows in the input matrix `A`.
- `N` is the number of columns in the input matrix `A`.

This is because we are iterating through each element of the matrix once to perform the transpose operation. The nested loops each run `M` and `N` times, respectively, and the assignment operation inside the loops takes constant time `O(1)`. Therefore, the total time complexity is the product of the number of rows and columns, which is `O(M * N)`.

#### Space Complexity:
The space complexity of the solution is `O(M * N)`, as we are using an additional matrix `B` of size `N x M` to store the transposed result. The space used by the input matrix `A` is not counted towards the space complexity because we are given it as input and are not modifying it in place.

The space complexity for storing matrix `B` is proportional to the size of the input matrix, so it is `O(M * N)`.

### Conclusion

This code efficiently transposes a matrix by swapping the rows and columns. The process is straightforward and involves creating a new matrix of the appropriate size and copying the values from the original matrix, with the rows and columns swapped. The solution has optimal time and space complexity for the given problem and ensures correctness through its simple, systematic approach to matrix transformation. This approach can be easily generalized for matrices of any size, as long as the input is a valid 2D array.

[`Link to LeetCode Lab`](https://leetcode.com/problems/transpose-matrix/description/)

---
{{< youtube DzMT3bDgVn0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
