
+++
authors = ["grid47"]
title = "Leetcode 2643: Row With Maximum Ones"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2643: Row With Maximum Ones in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "yieYsDt7yVM"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yieYsDt7yVM/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int mx = 0, idx = 0;
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                if(mat[i][j]) cnt++;
            if(cnt > mx) {
                idx = i;
                mx = cnt;
            }
        }
        return vector<int>{idx, mx};
    }
};
{{< /highlight >}}
---

### Problem Statement

The task requires identifying the row in a binary matrix that contains the maximum number of `1`s. Additionally, we need to return the index of that row and the count of `1`s in that row. If there are multiple rows with the same maximum count, the row with the smallest index should be selected. 

### Approach

To solve this problem efficiently, we need to iterate through each row of the matrix, count the number of `1`s, and keep track of the row with the maximum number of `1`s encountered so far. Since the matrix is composed of binary values (either `0` or `1`), counting the number of `1`s in a row is straightforward. After identifying the row with the maximum `1`s, we return both the row index and the number of `1`s.

### Code Breakdown (Step by Step)

Let's break down the code and explain each part:

1. **Function Definition**:
   ```cpp
   vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
   ```
   - The function `rowAndMaximumOnes` takes a 2D vector `mat` (matrix) as input, which represents the binary matrix. The goal of the function is to return a vector of two integers: the index of the row with the maximum number of `1`s and the count of `1`s in that row.

2. **Matrix Dimensions**:
   ```cpp
   int m = mat.size(), n = mat[0].size();
   ```
   - The matrix has `m` rows and `n` columns. The first call `mat.size()` returns the number of rows in the matrix, and `mat[0].size()` returns the number of columns. These values are stored in the variables `m` and `n`, respectively.

3. **Initialization of Variables**:
   ```cpp
   int mx = 0, idx = 0;
   ```
   - We initialize `mx` (maximum count of `1`s) to `0` and `idx` (index of the row with the maximum count) to `0`. These variables will help keep track of the maximum number of `1`s found and the index of the row that contains this maximum.

4. **Loop Through Each Row**:
   ```cpp
   for(int i = 0; i < m; i++) {
       int cnt = 0;
       for(int j = 0; j < n; j++)
           if(mat[i][j]) cnt++;
   ```
   - The outer loop iterates through each row `i` of the matrix.
   - The variable `cnt` is initialized to `0` for each row. This variable will count the number of `1`s in the current row.
   - The inner loop iterates through each column `j` of the row `i`. For each element `mat[i][j]`, we check if the value is `1`. If it is, we increment the counter `cnt`.

5. **Update Maximum Count and Index**:
   ```cpp
   if(cnt > mx) {
       idx = i;
       mx = cnt;
   }
   ```
   - After counting the number of `1`s in row `i`, we check if the count `cnt` is greater than the current maximum `mx`. If it is, we update `mx` to `cnt` and update `idx` to the current row index `i`.

6. **Return the Result**:
   ```cpp
   return vector<int>{idx, mx};
   ```
   - After processing all rows, we return a vector containing the index of the row with the maximum count of `1`s (`idx`) and the maximum count itself (`mx`). This is the final result of the function.

### Example Walkthrough

Consider the matrix:
```
mat = [
  [1, 0, 1, 1],
  [1, 1, 1, 0],
  [0, 1, 1, 1]
]
```

1. **First Row (i = 0)**:
   - The first row is `[1, 0, 1, 1]`, and the count of `1`s is `3`.
   - Since `3 > 0`, we update `mx = 3` and `idx = 0`.

2. **Second Row (i = 1)**:
   - The second row is `[1, 1, 1, 0]`, and the count of `1`s is `3`.
   - Since `3` is not greater than the current `mx` (which is `3`), we do not update `mx` or `idx`.

3. **Third Row (i = 2)**:
   - The third row is `[0, 1, 1, 1]`, and the count of `1`s is `3`.
   - Again, `3` is not greater than `mx`, so no update is made.

After iterating through all rows, the function will return the row index `0` and the count of `1`s `3`, since that is the first row with the maximum count.

### Complexity Analysis

#### Time Complexity:
- The time complexity of this solution is **O(m * n)**, where `m` is the number of rows in the matrix and `n` is the number of columns.
  - The outer loop iterates through all `m` rows.
  - The inner loop iterates through all `n` columns for each row.
  - Thus, the total number of operations is proportional to the total number of elements in the matrix, which is \(O(m \times n)\).

#### Space Complexity:
- The space complexity is **O(1)** if we consider only the space used by variables within the function.
  - The space used by the input matrix `mat` is not considered in the space complexity, as it is passed by reference.
  - The only extra space used is for the output vector, which stores two integers. Thus, the space complexity is constant.

### Conclusion

This solution effectively solves the problem of finding the row with the maximum number of `1`s in a binary matrix. The time complexity of \(O(m \times n)\) is optimal for iterating through all elements of the matrix, and the space complexity is constant, as we only need a few auxiliary variables for tracking the row index and count. The solution is efficient and straightforward, providing the correct result by counting the number of `1`s in each row and updating the maximum when necessary.

[`Link to LeetCode Lab`](https://leetcode.com/problems/row-with-maximum-ones/description/)

---
{{< youtube yieYsDt7yVM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
