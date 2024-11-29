
+++
authors = ["grid47"]
title = "Leetcode 1253: Reconstruct a 2-Row Binary Matrix"
date = "2024-07-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1253: Reconstruct a 2-Row Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a binary matrix with 2 rows and n columns, where each element is either 0 or 1. The sum of elements in the 0-th (upper) row is given by upper, the sum of elements in the 1-st (lower) row is given by lower, and the column-wise sum is given by colsum. Your task is to reconstruct the matrix based on these sums. If reconstruction is not possible, return an empty matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: upper, lower, and a list colsum representing the column-wise sums.
- **Example:** `upper = 2, lower = 1, colsum = [1,1,1]`
- **Constraints:**
	- 1 <= colsum.length <= 10^5
	- 0 <= upper, lower <= colsum.length
	- 0 <= colsum[i] <= 2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the reconstructed matrix if valid; otherwise, return an empty matrix.
- **Example:** `[[1, 1, 0], [0, 0, 1]]`
- **Constraints:**
	- The reconstructed matrix must satisfy the row and column sums.
	- If no valid solution exists, return an empty matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Reconstruct a valid binary matrix by ensuring that row and column sums match the given constraints.

- Iterate through the colsum array to reconstruct the matrix by assigning values to the two rows based on the constraints.
- Ensure that the values assigned to the rows satisfy the given upper and lower row sums as well as the colsum constraints.
{{< dots >}}
### Problem Assumptions ✅
- The input values are valid and the row sums upper and lower are feasible with respect to colsum.
{{< dots >}}
## Examples 🧩
- **Input:** `upper = 2, lower = 1, colsum = [1, 1, 1]`  \
  **Explanation:** The matrix is valid as the sums of the rows and columns match the given values.

- **Input:** `upper = 2, lower = 3, colsum = [2, 2, 1, 1]`  \
  **Explanation:** It is impossible to reconstruct a valid matrix, as the lower row sum exceeds the total sum of the columns.

- **Input:** `upper = 5, lower = 5, colsum = [2, 1, 2, 0, 1, 0, 1, 2, 0, 1]`  \
  **Explanation:** The matrix is reconstructed correctly, with the row and column sums matching the given values.

{{< dots >}}
## Approach 🚀
To solve the problem, we iterate through the column sums and try to allocate values to the two rows, ensuring that the row and column sums match the given constraints.

### Initial Thoughts 💭
- The binary matrix reconstruction requires careful allocation of values to the rows based on the column sums.
- The problem can be solved by iterating over the colsum array and using a greedy approach to assign 1s to the upper and lower rows, ensuring that the row sums are satisfied.
{{< dots >}}
### Edge Cases 🌐
- If colsum is an empty array, return an empty matrix.
- The solution should handle large inputs efficiently, with a maximum length of 100,000 for colsum.
- If the column sums are all zeros, the matrix should be filled with zeros.
- Ensure the solution handles all edge cases, including invalid cases where no solution exists.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cs) {
    vector<vector<int>> res(2, vector<int>(cs.size()));
    for(int i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i], i++) {
        res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
        res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
    }
    return u == 0 && l == 0 ? res : vector<vector<int>>();
}
```

The function `reconstructMatrix` attempts to reconstruct a binary matrix based on the given counts of ones in each row (`u` for upper row and `l` for lower row) and a vector `cs` indicating the constraints for each column. It returns the reconstructed matrix if it's possible, otherwise returns an empty matrix.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> reconstructMatrix(int u, int l, vector<int>& cs) {
	```
	The function `reconstructMatrix` is defined, which takes two integers `u` (the number of ones in the upper row) and `l` (the number of ones in the lower row) as inputs, along with a vector `cs` containing constraints for each column.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> res(2, vector<int>(cs.size()));
	```
	A 2D vector `res` of size 2xN (where N is the size of `cs`) is initialized to store the reconstructed binary matrix. The first row represents the upper row, and the second represents the lower row.

3. **For Loop**
	```cpp
	    for(int i = 0; i < cs.size(); u -= res[0][i], l -= res[1][i], i++) {
	```
	A `for` loop is used to iterate over each column in the matrix. During each iteration, `u` and `l` are reduced based on the number of ones placed in the upper and lower rows respectively.

4. **Condition for Upper Row**
	```cpp
	        res[0][i] = cs[i] == 2 || (cs[i] == 1 && l < u);
	```
	For the current column, if the value in `cs[i]` is 2, the upper row at `i` is set to 1. If the value in `cs[i]` is 1, the upper row is set to 1 only if the remaining number of ones in the lower row (`l`) is less than the upper row (`u`).

5. **Condition for Lower Row**
	```cpp
	        res[1][i] = cs[i] == 2 || (cs[i] == 1 && !res[0][i]);
	```
	For the current column, if `cs[i]` is 2, the lower row at `i` is set to 1. If `cs[i]` is 1, the lower row is set to 1 only if the upper row at the same column is 0.

6. **Return Result**
	```cpp
	    return u == 0 && l == 0 ? res : vector<vector<int>>();
	```
	After processing all columns, the function checks if both `u` and `l` have been reduced to 0, meaning the number of ones for both rows is fully satisfied. If true, it returns the reconstructed matrix `res`; otherwise, it returns an empty 2D vector indicating that the reconstruction was not possible.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution iterates through the colsum array once, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the result matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
