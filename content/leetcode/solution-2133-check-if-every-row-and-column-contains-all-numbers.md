
+++
authors = ["grid47"]
title = "Leetcode 2133: Check if Every Row and Column Contains All Numbers"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2133: Check if Every Row and Column Contains All Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "6l0_5Weq-3k"
youtube_upload_date="2022-01-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6l0_5Weq-3k/maxresdefault.webp"
comments = true
+++



---
You are given an n x n matrix where each element is an integer. The matrix is considered valid if every row and every column contains all the integers from 1 to n (inclusive). Your task is to check whether the given matrix satisfies this condition. Return true if the matrix is valid, and false otherwise.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a square matrix represented by a 2D array of size n x n, where each element is an integer between 1 and n.
- **Example:** `matrix = [[1,2,3],[3,1,2],[2,3,1]]`
- **Constraints:**
	- n == matrix.length == matrix[i].length
	- 1 <= n <= 100
	- 1 <= matrix[i][j] <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if the matrix is valid, otherwise return false.
- **Example:** `Input: matrix = [[1, 2, 3], [3, 1, 2], [2, 3, 1]] Output: true`
- **Constraints:**
	- The solution must return true if the matrix satisfies the condition, otherwise false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if every row and column contains all the integers from 1 to n.

- 1. Iterate over each row and check if it contains all integers from 1 to n.
- 2. Iterate over each column and check if it contains all integers from 1 to n.
- 3. If both row and column conditions are satisfied, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will always have valid integer entries between 1 and n.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: matrix = [[1, 2, 3], [3, 1, 2], [2, 3, 1]]`  \
  **Explanation:** In this case, n = 3, and every row and column contains the integers 1, 2, and 3. Therefore, the matrix is valid, and the output is true.

- **Input:** `Input: matrix = [[1, 1, 1], [1, 2, 3], [1, 2, 3]]`  \
  **Explanation:** Here, the first row and first column do not contain all integers from 1 to 3. Therefore, the matrix is not valid, and the output is false.

{{< dots >}}
## Approach 🚀
To determine if the matrix is valid, we need to check both the rows and columns for the presence of all integers from 1 to n.

### Initial Thoughts 💭
- The key observation is that the matrix must contain each integer from 1 to n in every row and column.
- We will use a set to check for uniqueness of elements in each row and column. If a row or column doesn't contain all integers from 1 to n, it is invalid.
{{< dots >}}
### Edge Cases 🌐
- Empty matrices are not a valid input as per the problem statement. We assume that the matrix has at least one element.
- The solution must be optimized to handle matrices of size up to 100 x 100 efficiently.
- Matrices where all elements are identical (e.g., [[1, 1], [1, 1]]) should be checked carefully to ensure proper validation.
- The solution must be efficient and work within the constraints of n <= 100.
{{< dots >}}
## Code 💻
```cpp
bool checkValid(vector<vector<int>>& mtx) {
    int n = mtx.size();
    for(int i = 0; i < n; i++) {
      bitset<101> row, col;
      for(int j = 0; j < n; j++)
        row[mtx[i][j]] = col[mtx[j][i]] = true;
      if (min(row.count(), col.count()) < n)
        return false;
    }
    return true;
}
```

This function checks the validity of a given square matrix by verifying if each row and column contains a unique set of numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool checkValid(vector<vector<int>>& mtx) {
	```
	Function declaration. The function `checkValid` takes a reference to a 2D vector `mtx` representing the matrix and returns a boolean indicating its validity.

2. **Variable Declaration**
	```cpp
	    int n = mtx.size();
	```
	This line initializes the variable `n` to store the size of the matrix `mtx`. It assumes the matrix is square.

3. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This starts a loop that iterates through each row of the matrix.

4. **Variable Declaration**
	```cpp
	      bitset<101> row, col;
	```
	Two bitsets `row` and `col` are declared to track which elements have been seen in the current row and column.

5. **Loop**
	```cpp
	      for(int j = 0; j < n; j++)
	```
	This nested loop iterates through each element of the row and column.

6. **Operation**
	```cpp
	        row[mtx[i][j]] = col[mtx[j][i]] = true;
	```
	This sets the respective bit in the `row` and `col` bitsets to `true` for the current element in both the row and the column.

7. **Condition**
	```cpp
	      if (min(row.count(), col.count()) < n)
	```
	This condition checks if the number of unique elements in both the current row and column is less than `n`.

8. **Return**
	```cpp
	        return false;
	```
	If the condition above is true, the function returns `false`, indicating the matrix is invalid.

9. **Return**
	```cpp
	    return true;
	```
	If the function reaches here, it means the matrix is valid, so it returns `true`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2), as we check all elements in the matrix to validate both rows and columns.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for checking the rows and columns using sets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/description/)

---
{{< youtube 6l0_5Weq-3k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
