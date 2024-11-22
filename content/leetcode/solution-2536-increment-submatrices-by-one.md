
+++
authors = ["grid47"]
title = "Leetcode 2536: Increment Submatrices by One"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2536: Increment Submatrices by One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "K4SJb0I-_hw"
youtube_upload_date="2023-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K4SJb0I-_hw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        for(int i = 0; i < q.size(); i++) {
            auto it = q[i];
            for(int j = q[i][0]; j <= q[i][2]; j++) {
                ans[j][q[i][1]] += 1;
                if(q[i][3] < n - 1)
                    ans[j][q[i][3] + 1] -=1;
            }
        }
        
        for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            ans[i][j] += ans[i][j - 1];
        
        return ans;
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to efficiently apply range addition queries to an `n x n` matrix. Given a set of queries, each specifying a rectangular submatrix (defined by the top-left and bottom-right corners), we are required to increment the elements in that submatrix. The task is to return the matrix after all queries have been applied.

Each query is of the form:
- `[row1, col1, row2, col2]`, where:
  - `row1`, `col1` is the top-left corner of the submatrix.
  - `row2`, `col2` is the bottom-right corner of the submatrix.
  - The query adds `1` to all elements in the submatrix defined by these corners.

### Approach

To solve this problem efficiently, we can use the **prefix sum approach**. Instead of updating every element of the submatrix directly for each query, which would be inefficient, we can update a smaller range in the matrix and later accumulate the values.

1. **Difference Array**: 
   - The key idea here is to use a difference array to represent the increments. Instead of applying the increment to every element in the submatrix immediately, we only modify the boundaries of the submatrix.
   
   - For each query `[row1, col1, row2, col2]`, we:
     - Increment `ans[row1][col1]` by `1` to indicate the start of an increment at this position.
     - Decrement `ans[row1][col2 + 1]` by `1` if `col2 + 1 < n`, to cancel the increment beyond the end of the column range.
     - Increment `ans[row2 + 1][col1]` by `1` if `row2 + 1 < n`, to cancel the increment beyond the end of the row range.
     - Decrement `ans[row2 + 1][col2 + 1]` by `1` to ensure the area beyond the bottom-right corner is unaffected by the query.

2. **Prefix Sum**: 
   - After all queries have been applied in the difference matrix, we can compute the prefix sum of rows to obtain the final matrix. This step ensures that each element reflects the correct number of additions.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Matrix `ans`
```cpp
vector<vector<int>> ans(n, vector<int>(n, 0));
```
- We start by initializing an `n x n` matrix `ans` with all elements set to `0`. This matrix will store the intermediate results of the range additions.

#### Step 2: Processing Each Query
```cpp
for(int i = 0; i < q.size(); i++) {
    auto it = q[i];
    for(int j = q[i][0]; j <= q[i][2]; j++) {
        ans[j][q[i][1]] += 1;
        if(q[i][3] < n - 1)
            ans[j][q[i][3] + 1] -= 1;
    }
}
```
- We iterate over each query in `q`. Each query is a vector with the format `[row1, col1, row2, col2]`.
- For each query, we loop through the rows from `row1` to `row2`. Within this range, we update the first column of the range (`col1`) by incrementing it by `1`.
- We also perform a boundary check to ensure that we do not go out of bounds. If `col2 + 1` is within bounds, we decrement that cell to cancel the increment beyond the end of the column range.

#### Step 3: Compute Prefix Sum for Columns
```cpp
for(int i = 0; i < n; i++)
    for(int j = 1; j < n; j++)
        ans[i][j] += ans[i][j - 1];
```
- After processing all queries, the matrix `ans` will have partial sums. Now, we need to compute the prefix sum for each row to propagate the effects of the range additions across the columns.
- For each row `i`, starting from the second column `j = 1`, we update each `ans[i][j]` by adding the value of the previous column `ans[i][j - 1]`. This ensures that each element reflects the cumulative additions up to that point.

#### Step 4: Return the Final Matrix
```cpp
return ans;
```
- Once the prefix sums are computed, the matrix `ans` contains the final values after all queries have been applied. This matrix is then returned.

### Complexity Analysis

#### Time Complexity

1. **Processing Queries**:
   - We iterate over each query in `q`, and for each query, we loop over the rows from `row1` to `row2`. For each row in the range, we perform a constant number of operations (incrementing and decrementing specific elements).
   - In the worst case, for each query, we may have to process all `n` rows (if `row1 = 0` and `row2 = n-1`).
   - Thus, the time complexity of processing the queries is \( O(q \cdot n) \), where `q` is the number of queries and `n` is the size of the matrix.

2. **Computing Prefix Sum**:
   - After processing all queries, we compute the prefix sum for each row. This step takes \( O(n^2) \) time, as we iterate over all the elements in the `n x n` matrix to compute the sums.

3. **Overall Time Complexity**:
   - The total time complexity is \( O(q \cdot n + n^2) \), where `q` is the number of queries and `n` is the size of the matrix.

#### Space Complexity

1. **Matrix Storage**:
   - The matrix `ans` requires \( O(n^2) \) space, as it stores the values for each cell in the `n x n` matrix.

2. **Query Storage**:
   - The input `q` is a list of queries, and the space required to store this list is \( O(q) \).

3. **Overall Space Complexity**:
   - The overall space complexity is \( O(n^2) \), as this is the dominant factor due to the storage of the matrix `ans`.

### Conclusion

This solution efficiently solves the problem of applying multiple range addition queries to an `n x n` matrix using the prefix sum technique. The use of the difference array ensures that each query is processed in a time-efficient manner, avoiding the need to iterate over the entire submatrix for each query. By leveraging the prefix sum computation, we efficiently accumulate the results and obtain the final matrix after all queries are applied. The time complexity of \( O(q \cdot n + n^2) \) and the space complexity of \( O(n^2) \) make this approach suitable for handling larger inputs within reasonable time and space limits.

[`Link to LeetCode Lab`](https://leetcode.com/problems/increment-submatrices-by-one/description/)

---
{{< youtube K4SJb0I-_hw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
