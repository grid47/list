
+++
authors = ["grid47"]
title = "Leetcode 1582: Special Positions in a Binary Matrix"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1582: Special Positions in a Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "CsxwXaPmMyE"
youtube_upload_date="2020-09-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/CsxwXaPmMyE/maxresdefault.webp"
comments = true
+++



---
You are given a binary matrix of size m x n, where each element is either 0 or 1. A position (i, j) in the matrix is considered special if mat[i][j] = 1 and all other elements in the same row i and column j are 0. Your task is to find how many such special positions exist in the matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a matrix 'mat' of size m x n, where each element is either 0 or 1.
- **Example:** `Input: mat = [[1, 0, 0], [0, 0, 1], [1, 0, 0]]`
- **Constraints:**
	- 1 <= m, n <= 100
	- mat[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of special positions in the matrix.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To find special positions, we need to check each 1 in the matrix and verify that all other elements in its row and column are 0.

- 1. Traverse the entire matrix to calculate how many 1's are present in each row and column.
- 2. For each element in the matrix, check if it's 1, and if the row and column of that element contain no other 1's.
- 3. Count the number of such positions that meet the condition.
{{< dots >}}
### Problem Assumptions ✅
- The matrix will not be empty, and the elements are constrained to 0 or 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: mat = [[1, 0, 0], [0, 0, 1], [1, 0, 0]]`  \
  **Explanation:** In this case, only the position (1, 2) is special because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0. Therefore, the output is 1.

- **Input:** `Example 2: mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]`  \
  **Explanation:** Here, the positions (0, 0), (1, 1), and (2, 2) are all special. Therefore, the output is 3.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to determine the special positions by first counting how many 1's are present in each row and column, then checking each 1 in the matrix to ensure there are no other 1's in its row and column.

### Initial Thoughts 💭
- A brute force approach would involve checking each element in the matrix for the special condition, which could lead to a time complexity of O(m * n^2).
- A more efficient approach would involve counting the number of 1's in each row and column first, then performing a single check for each element, which would improve the solution's efficiency.
{{< dots >}}
### Edge Cases 🌐
- Matrix dimensions are guaranteed to be at least 1x1.
- The solution should handle large matrices efficiently, with dimensions up to 100x100.
- When the matrix consists entirely of 0's, the output will be 0.
- Ensure the solution is efficient enough to handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int numSpecial(vector<vector<int>>& mat) {

    int m = mat.size(), n = mat[0].size();
    vector<int> row(m, 0), col(n, 0);
    int res = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(mat[i][j] == 1) row[i]++, col[j]++;
    }

    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
            res++;
        }
    }
    
    return res;
}
```

This function calculates the number of special positions in a matrix where the cell is 1 and its row and column contain exactly one 1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numSpecial(vector<vector<int>>& mat) {
	```
	Define the function `numSpecial` that takes a matrix `mat` as input, where each cell can either be 0 or 1.

2. **Variable Initialization**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Initialize variables `m` and `n` to represent the number of rows and columns in the matrix, respectively.

3. **Variable Initialization**
	```cpp
	    vector<int> row(m, 0), col(n, 0);
	```
	Create two vectors `row` and `col`, initialized to zero. These vectors will track the count of 1s in each row and each column.

4. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize `res` to 0, which will store the result (the number of special positions in the matrix).

5. **Outer Loop - Row Iteration**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start the first loop to iterate over each row in the matrix.

6. **Inner Loop - Column Iteration**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Start the second loop to iterate over each column in the current row.

7. **Update Row and Column Counts**
	```cpp
	        if(mat[i][j] == 1) row[i]++, col[j]++;
	```
	If the current cell is 1, increment the count for the corresponding row (`row[i]`) and column (`col[j]`), indicating that a 1 has been found.

8. **Second Loop - Checking Special Positions**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start the third loop to iterate over each row again, this time to check for special positions.

9. **Second Inner Loop - Checking Columns**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Start the fourth loop to iterate over each column in the current row and check if the position is special.

10. **Condition Check - Special Position**
	```cpp
	        if(row[i] == 1 && col[j] == 1 && mat[i][j] == 1) {
	```
	Check if the current cell is 1, and if both its row and column contain exactly one 1.

11. **Increment Result**
	```cpp
	            res++;
	```
	If the condition is true, increment the result `res` by 1, as this cell is a special position.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the final result `res`, which represents the number of special positions in the matrix.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we process each element in the matrix once and use auxiliary arrays to store the row and column counts.

### Space Complexity 💾
- **Best Case:** O(m + n)
- **Worst Case:** O(m + n)

The space complexity is O(m + n) because we use two arrays to store the row and column counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/)

---
{{< youtube CsxwXaPmMyE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
