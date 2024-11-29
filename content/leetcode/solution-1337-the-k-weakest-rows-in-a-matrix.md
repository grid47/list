
+++
authors = ["grid47"]
title = "Leetcode 1337: The K Weakest Rows in a Matrix"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1337: The K Weakest Rows in a Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Heap (Priority Queue)","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a binary matrix where 1's represent soldiers and 0's represent civilians. The soldiers are positioned before the civilians in each row. A row is weaker than another if it has fewer soldiers, or if it has the same number of soldiers but appears earlier. Your task is to return the indices of the k weakest rows in the matrix, ordered from weakest to strongest.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary matrix mat of size m x n, followed by an integer k representing the number of weakest rows to return.
- **Example:** `mat = [[1, 1, 0, 0], [1, 1, 1, 0], [1, 0, 0, 0], [1, 1, 1, 1]], k = 2`
- **Constraints:**
	- 2 <= n, m <= 100
	- 1 <= k <= m
	- matrix[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of integers representing the indices of the k weakest rows, ordered from weakest to strongest.
- **Example:** `For mat = [[1, 1, 0, 0], [1, 1, 1, 0], [1, 0, 0, 0], [1, 1, 1, 1]], k = 2, the output will be [2, 0].`
- **Constraints:**
	- The number of rows to return is always valid (1 <= k <= m).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the k weakest rows in the matrix and return them in the required order.

- 1. Count the number of soldiers (1's) in each row.
- 2. Pair each row's soldier count with its index.
- 3. Sort these pairs first by soldier count, and if two rows have the same count, by their index.
- 4. Extract the indices of the k weakest rows and return them.
{{< dots >}}
### Problem Assumptions ✅
- The matrix rows contain only 0's and 1's, with 1's representing soldiers and 0's representing civilians.
- The number of soldiers in a row is always less than or equal to the number of columns.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: mat = [[1, 1, 0, 0], [1, 1, 1, 0], [1, 0, 0, 0], [1, 1, 1, 1]], k = 2`  \
  **Explanation:** The weakest rows are rows 2 (1 soldier) and 0 (2 soldiers).

- **Input:** `Example 2: mat = [[1, 0], [1, 1], [1, 0], [1, 0]], k = 3`  \
  **Explanation:** The weakest rows are rows 0, 2, and 3 (each with 1 soldier), ordered by their indices.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to count the number of soldiers in each row and then sort the rows based on the count of soldiers. We can then return the indices of the k weakest rows.

### Initial Thoughts 💭
- The matrix is binary, making it easy to count soldiers in each row.
- Sorting the rows based on the number of soldiers is a simple way to determine the weakest rows.
- Sorting is an efficient approach given that the matrix size is relatively small (maximum 100x100).
{{< dots >}}
### Edge Cases 🌐
- Empty matrices are not expected given the constraints.
- Handle matrices up to the size 100x100 efficiently.
- Rows with the same number of soldiers should be sorted by their index.
- Ensure that the sorted rows are correctly ordered first by soldier count, then by row index in case of ties.
{{< dots >}}
## Code 💻
```cpp
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n=mat[0].size();
    for(int i=0; i<mat.size(); i++){
        mat[i].push_back(i);
    }
    sort(mat.begin(), mat.end());
    vector<int> ans(k);
    for(int i=0; i<k; i++){
        ans[i]=mat[i][n];            
    }
    return ans;
}
```

This function finds the k weakest rows in a matrix. It adds the row index to the matrix, sorts it based on row strength (number of 1s), and then returns the indices of the k weakest rows.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	```
	This is the function definition, where the function takes a matrix 'mat' and an integer 'k', and returns the indices of the k weakest rows.

2. **Matrix Column Size**
	```cpp
	    int n=mat[0].size();
	```
	Here we get the number of columns 'n' in the matrix by accessing the size of the first row.

3. **Row Loop Start**
	```cpp
	    for(int i=0; i<mat.size(); i++){
	```
	We loop through each row of the matrix to append the row index to it.

4. **Append Row Index**
	```cpp
	        mat[i].push_back(i);
	```
	For each row, we append its index to the end, which helps in sorting rows by their strengths while keeping track of their original positions.

5. **Sort Matrix**
	```cpp
	    sort(mat.begin(), mat.end());
	```
	We sort the matrix rows in ascending order based on the number of 1s in each row (since the row index is appended, it will keep track of the original positions).

6. **Answer Vector Initialization**
	```cpp
	    vector<int> ans(k);
	```
	We initialize a vector 'ans' of size 'k' to store the indices of the k weakest rows.

7. **Answer Population Loop Start**
	```cpp
	    for(int i=0; i<k; i++){
	```
	We loop through the first k rows in the sorted matrix to extract their original indices.

8. **Populate Answer Vector**
	```cpp
	        ans[i]=mat[i][n];            
	```
	For each of the k weakest rows, we store the original index of the row (which is stored at the last position in the row after appending).

9. **Return Answer**
	```cpp
	    return ans;
	```
	Finally, we return the vector 'ans', which contains the indices of the k weakest rows.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m log m), where m is the number of rows in the matrix.
- **Average Case:** O(m log m)
- **Worst Case:** O(m log m)

Sorting the rows takes O(m log m), where m is the number of rows.

### Space Complexity 💾
- **Best Case:** O(m)
- **Worst Case:** O(m)

The space complexity is O(m) due to the storage of the soldier counts and row indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
