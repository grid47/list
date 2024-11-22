
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---



### Problem Statement
Given a matrix `mat` of integers and an integer `k`, for each cell in `mat`, compute the sum of elements within a distance of `k` (Manhattan distance) from that cell. The result is a new matrix `res` where each `res[i][j]` is the sum of elements in the submatrix surrounding `mat[i][j]` within this `k` range.

### Approach
To solve this efficiently, we use a **prefix sum matrix**. The prefix sum matrix, `sum[i][j]`, will store the cumulative sum of elements from the top-left corner `(0, 0)` to `(i-1, j-1)` in the matrix. Using this prefix sum, we can calculate the sum of any submatrix in constant time, allowing us to efficiently compute the block sums.

#### Steps:
1. **Build Prefix Sum Matrix**:
   - Create a matrix `sum` of size `(m+1) x (n+1)` where `m` is the number of rows and `n` is the number of columns in `mat`. Initialize all entries to 0.
   - For each cell `(i, j)`, compute `sum[i][j]` as the value in `mat[i-1][j-1]` plus the cumulative sums from neighboring cells.
   - This cumulative sum formula is:  
     \[
     \text{sum}[i][j] = \text{mat}[i-1][j-1] + \text{sum}[i-1][j] + \text{sum}[i][j-1] - \text{sum}[i-1][j-1]
     \]

2. **Calculate Block Sum Using Prefix Sum Matrix**:
   - Initialize a result matrix `res` of size `m x n`.
   - For each cell `(i, j)`, compute the submatrix boundaries based on `k`:
     - Define `r1` and `c1` as the bottom-right boundary using `min(i + k, m)` and `min(j + k, n)`.
     - Define `r2` and `c2` as the top-left boundary using `max(i - k, 1)` and `max(j - k, 1)`.
   - Use the prefix sum matrix to compute the block sum for `(i, j)`:
     \[
     \text{res}[i-1][j-1] = \text{sum}[r1][c1] - \text{sum}[r1][c2-1] - \text{sum}[r2-1][c1] + \text{sum}[r2-1][c2-1]
     \]
   - This formula efficiently calculates the sum of the block using only four values from the prefix sum matrix.

3. **Return the Result**:
   - Return `res`, which contains the block sum for each cell in `mat`.

### Code Breakdown (Step by Step)

1. **Initialize Variables and Prefix Sum Matrix**:
   - Set up the `sum` matrix with one extra row and column.
   - Calculate prefix sums in `sum` matrix using a nested loop for each element in `mat`.

   ```cpp
   int m = mat.size(), n = mat[0].size();
   vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));

   for(int i = 1; i < m + 1; i++)
       for(int j = 1; j < n + 1; j++)
           sum[i][j] = mat[i - 1][j - 1] + (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
   ```

2. **Compute Block Sum for Each Cell**:
   - For each cell `(i, j)`, define the boundaries and use the prefix sum matrix to get the block sum.
   - Store the block sum in the result matrix `res`.

   ```cpp
   vector<vector<int>> res(m, vector<int>(n));

   for(int i = 1; i < m + 1; i++)
       for(int j = 1; j < n + 1; j++) {
           int r1 = min(i + k, m);
           int c1 = min(j + k, n);
           int r2 = max(i - k, 1);
           int c2 = max(j - k, 1);

           res[i - 1][j - 1] = sum[r1][c1] - sum[r1][c2 - 1] - sum[r2 - 1][c1] + sum[r2 - 1][c2 - 1];
       }
   ```

3. **Return Result**:
   - Return the `res` matrix containing the block sums.

   ```cpp
   return res;
   ```

### Complexity Analysis

- **Time Complexity**: \(O(m \times n)\)  
  - Constructing the prefix sum matrix takes \(O(m \times n)\).
  - Calculating each block sum also takes \(O(m \times n)\) since each cell is computed in constant time.

- **Space Complexity**: \(O(m \times n)\)  
  - Additional space is used for the `sum` and `res` matrices.

### Conclusion
This solution uses a prefix sum approach to efficiently compute the block sum for each cell in `mat` within a specified distance `k`. The prefix sum matrix optimizes the calculation by allowing constant-time queries for submatrices, making it an optimal solution for large matrices. This technique is widely applicable to problems involving cumulative sums over ranges and enables efficient processing of multi-dimensional data.

[`Link to LeetCode Lab`](https://leetcode.com/problems/matrix-block-sum/description/)

---
{{< youtube jor18pkf9EE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
