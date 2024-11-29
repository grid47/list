
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
comments = true
+++



---
You are given a positive integer `n` representing the size of an `n x n` matrix initially filled with zeros, and a 2D integer array `queries`. Each query consists of four integers `[row1, col1, row2, col2]`. For each query, add `1` to every element in the submatrix from `(row1, col1)` to `(row2, col2)` in the matrix. Return the matrix after applying all queries.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` and a 2D integer array `queries` containing multiple submatrices to update.
- **Example:** `n = 4, queries = [[0, 1, 2, 3], [1, 1, 3, 3]]`
- **Constraints:**
	- 1 <= n <= 500
	- 1 <= queries.length <= 10^4
	- 0 <= row1 <= row2 < n
	- 0 <= col1 <= col2 < n

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the matrix after applying all queries.
- **Example:** `[[0, 1, 1, 1], [0, 2, 3, 3], [0, 1, 1, 1], [0, 0, 0, 0]]`
- **Constraints:**
	- The output is an `n x n` matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently update the matrix for all the queries and return the final result.

- Create a `n x n` matrix initialized with zeros.
- For each query, update the matrix in the specified submatrix range by adding 1 to each element.
- Optimize the solution by reducing redundant operations and updating the matrix in an efficient manner.
{{< dots >}}
### Problem Assumptions ✅
- The matrix size `n` is always valid and positive.
- Each query specifies valid row and column indices within the matrix bounds.
{{< dots >}}
## Examples 🧩
- **Input:** `[[0, 1, 2, 3], [1, 1, 3, 3]]`  \
  **Explanation:** In the first query, elements in the submatrix (0,1) to (2,3) are incremented by 1. In the second query, elements in the submatrix (1,1) to (3,3) are also incremented by 1.

- **Input:** `[[0, 0, 1, 1], [1, 1, 2, 2]]`  \
  **Explanation:** In the first query, elements in the submatrix (0,0) to (1,1) are incremented by 1. In the second query, elements in the submatrix (1,1) to (2,2) are incremented by 1.

{{< dots >}}
## Approach 🚀
The approach is to efficiently apply each query to update the matrix and then return the final matrix.

### Initial Thoughts 💭
- We need to update a submatrix for each query efficiently.
- We can use a differential approach to efficiently apply the updates.
{{< dots >}}
### Edge Cases 🌐
- The matrix will never be empty as `n >= 1`.
- Handle large queries efficiently (up to 10^4 queries).
- Handle cases where queries overlap or cover the entire matrix.
- Ensure the solution works for all valid matrix sizes and queries within the provided constraints.
{{< dots >}}
## Code 💻
```cpp
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
```

The function 'rangeAddQueries' performs range updates on a 2D matrix based on the given queries. Each query specifies a range and the function uses a prefix-sum technique to efficiently compute the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& q) {
	```
	The function 'rangeAddQueries' is defined. It takes an integer 'n' (the size of the 2D matrix) and a 2D vector 'q' (the list of queries) as input.

2. **Matrix Initialization**
	```cpp
	    vector<vector<int>> ans(n, vector<int>(n, 0));
	```
	An 'n x n' matrix 'ans' is initialized with all values set to 0. This matrix will store the results after applying the range updates.

3. **Loop Over Queries**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	A loop starts to iterate over each query in the input vector 'q'. Each query is applied to the matrix 'ans'.

4. **Query Extraction**
	```cpp
	        auto it = q[i];
	```
	The current query 'it' is extracted from the 'q' vector for processing.

5. **Inner Loop Over Rows**
	```cpp
	        for(int j = q[i][0]; j <= q[i][2]; j++) {
	```
	An inner loop starts to iterate over rows from the start index 'q[i][0]' to the end index 'q[i][2]' of the query.

6. **Update Column**
	```cpp
	            ans[j][q[i][1]] += 1;
	```
	The value at 'ans[j][q[i][1]]' is incremented by 1, updating the specified column of the matrix for the current row 'j'.

7. **Boundary Check**
	```cpp
	            if(q[i][3] < n - 1)
	```
	A boundary check is performed to ensure that the column index does not exceed the matrix's bounds.

8. **Reverse Update**
	```cpp
	                ans[j][q[i][3] + 1] -= 1;
	```
	If the boundary condition is met, the value at 'ans[j][q[i][3] + 1]' is decremented by 1, effectively reversing the update beyond the end column.

9. **Prefix Sum Calculation**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A loop starts to iterate over the rows of the matrix to compute the prefix sums.

10. **Prefix Sum Over Columns**
	```cpp
	    for(int j = 1; j < n; j++)
	```
	A nested loop starts to iterate over the columns, starting from the second column (index 1), to compute the prefix sum.

11. **Update Prefix Sum**
	```cpp
	        ans[i][j] += ans[i][j - 1];
	```
	The current column value 'ans[i][j]' is updated by adding the previous column value 'ans[i][j - 1]' to it, effectively computing the prefix sum.

12. **Return Result**
	```cpp
	    return ans;
	```
	The result matrix 'ans' is returned, now containing the updated values after applying all queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2 + q)
- **Worst Case:** O(n^2 + q)

The time complexity is O(n^2) for processing the final result, and O(q) for processing each query, where `q` is the number of queries.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) since we are storing an `n x n` matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/increment-submatrices-by-one/description/)

---
{{< youtube K4SJb0I-_hw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
