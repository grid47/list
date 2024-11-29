
+++
authors = ["grid47"]
title = "Leetcode 2718: Sum of Matrix After Queries"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2718: Sum of Matrix After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GgRr0TbbsO0"
youtube_upload_date="2023-06-04"
youtube_thumbnail="https://i.ytimg.com/vi/GgRr0TbbsO0/maxresdefault.jpg"
comments = true
+++



---
You are given a number n and a list of queries. Initially, an n x n matrix is filled with zeros. Each query updates either a row or a column in the matrix to a given value. After applying all the queries, compute and return the sum of all elements in the matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A number n and a list of queries, where each query is of the form [typei, indexi, vali].
- **Example:** `n = 3, queries = [[0, 0, 1], [1, 2, 2], [0, 2, 3], [1, 0, 4]]`
- **Constraints:**
	- 1 <= n <= 10^4
	- 1 <= queries.length <= 5 * 10^4
	- queries[i].length == 3
	- 0 <= typei <= 1
	- 0 <= indexi < n
	- 0 <= vali <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all elements in the matrix after all queries are applied.
- **Example:** `23`
- **Constraints:**
	- The sum will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to efficiently calculate the sum of the matrix after applying all queries.

- Keep track of the changes for each row and column separately.
- Process the queries in reverse order to minimize redundant updates.
- Update the matrix based on the query type (row or column) and compute the sum.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is initially filled with zeros.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** For n = 3 and queries = [[0, 0, 1], [1, 2, 2], [0, 2, 3], [1, 0, 4]], we update the matrix according to the queries and calculate the sum of all elements.

- **Input:** `Example 2`  \
  **Explanation:** For n = 3 and queries = [[0, 0, 4], [0, 1, 2], [1, 0, 1], [0, 2, 3], [1, 2, 1]], the sum of all matrix elements after applying the queries is 17.

{{< dots >}}
## Approach 🚀
The approach involves processing the queries in reverse order to optimize the number of updates, while keeping track of the sum of all matrix elements.

### Initial Thoughts 💭
- The matrix can be updated by rows or columns, so we need to handle each query based on its type.
- We can use a greedy approach by iterating through the queries in reverse to minimize redundant operations and compute the final sum.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs since queries length is guaranteed to be at least 1.
- Handle large matrix sizes and a high number of queries efficiently using an optimized approach.
- If the matrix size is 1, the result is directly the value of the first query.
- The solution must handle up to 10^4 matrix size and 5 * 10^4 queries efficiently.
{{< dots >}}
## Code 💻
```cpp
long long matrixSumQueries(int n, vector<vector<int>>& q) {
    long long res = 0;

    int seen[2][10001] = {};
    int cnt[2] = {n, n};

    for(int i = q.size() - 1; i >= 0; i--) {
        
        int type = q[i][0], id = q[i][1], val = q[i][2];
        
        if(!seen[type][id]) {
            seen[type][id] = 1;
            res += val * cnt[!type];
            --cnt[type];
        }
        
    }

    return res;
}
```

This function calculates the sum of queries where each query modifies an element in a 2D matrix. The matrix elements are either row-based or column-based, and the result is the sum of values modified by the queries.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long matrixSumQueries(int n, vector<vector<int>>& q) {
	```
	The function `matrixSumQueries` is defined, accepting an integer `n` (the size of the matrix) and a 2D vector `q` containing the queries. It returns a long long integer representing the calculated sum after processing all queries.

2. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	The variable `res` is initialized to 0, which will hold the cumulative result of all valid queries.

3. **Array Initialization**
	```cpp
	    int seen[2][10001] = {};
	```
	The `seen` array is initialized to track whether a particular row or column has been processed. It has dimensions 2 by 10001 to accommodate the two types of queries and matrix indices.

4. **Array Initialization**
	```cpp
	    int cnt[2] = {n, n};
	```
	The `cnt` array is initialized with `n` for both rows and columns, representing the number of rows and columns available for modification.

5. **Loop Start**
	```cpp
	    for(int i = q.size() - 1; i >= 0; i--) {
	```
	A loop is initiated that iterates through the queries in reverse order, starting from the last query and moving backward to the first.

6. **Query Parsing**
	```cpp
	        int type = q[i][0], id = q[i][1], val = q[i][2];
	```
	For each query, the variables `type`, `id`, and `val` are extracted. `type` specifies whether the operation is on a row or a column, `id` is the row or column index, and `val` is the value to be added to the matrix.

7. **Condition Check**
	```cpp
	        if(!seen[type][id]) {
	```
	The condition checks if the row or column has already been processed in a previous query. If not, it proceeds with the operation.

8. **Mark As Seen**
	```cpp
	            seen[type][id] = 1;
	```
	The element at the specified type and index (`type`, `id`) is marked as processed by setting `seen[type][id]` to 1.

9. **Result Calculation**
	```cpp
	            res += val * cnt[!type];
	```
	The result is updated by adding the value of the query (`val`) multiplied by the remaining count of rows or columns that have not yet been processed (`cnt[!type]`).

10. **Decrement Count**
	```cpp
	            --cnt[type];
	```
	The count for the type (row or column) is decremented, as one row or column has now been processed.

11. **Return Result**
	```cpp
	    return res;
	```
	The final result is returned, which is the sum of all valid query contributions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is linear in terms of the number of queries and matrix size.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) since we only store a few arrays to track row and column updates.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-matrix-after-queries/description/)

---
{{< youtube GgRr0TbbsO0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
