
+++
authors = ["grid47"]
title = "Leetcode 861: Score After Flipping Matrix"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 861: Score After Flipping Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FbhzRA5den8"
youtube_upload_date="2024-05-13"
youtube_thumbnail="https://i.ytimg.com/vi/FbhzRA5den8/maxresdefault.jpg"
comments = true
+++



---
You are given a binary matrix where each row and column can be toggled independently. A toggle operation flips all values in a row or column (changing 0s to 1s and 1s to 0s). The matrix's score is calculated by interpreting each row as a binary number and summing up these values. Your task is to determine the maximum score possible after performing any number of toggle operations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary matrix represented as a 2D array of integers. Each element is either 0 or 1.
- **Example:** `Input: grid = [[1,0,0],[0,1,1],[1,1,0]]`
- **Constraints:**
	- m == grid.length
	- n == grid[i].length
	- 1 <= m, n <= 20
	- grid[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the highest possible score of the matrix after performing any number of toggles.
- **Example:** `Output: 14`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To maximize the matrix's score by toggling rows and columns strategically to maximize the binary number values of each row.

- Step 1: Ensure the first column contains all 1s by toggling any rows where the first element is 0.
- Step 2: For each remaining column, determine whether toggling the column increases the number of 1s in that column.
- Step 3: Use the column's majority value (1s or 0s) to calculate its contribution to the total score.
- Step 4: Compute the score by interpreting each row as a binary number and summing up the values.
{{< dots >}}
### Problem Assumptions ✅
- You can perform any number of toggle operations on rows or columns.
- No limit on the number of rows or columns toggled in a single operation.
- The input matrix contains at least one row and one column.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1,0,0],[0,1,1],[1,1,0]]`  \
  **Explanation:** Toggle the second row to convert it to [1, 0, 0]. Then toggle the third column to get [[1, 0, 1], [1, 0, 1], [1, 1, 1]]. The binary representation is 0b101 (5), 0b101 (5), 0b111 (7). Total score = 5 + 5 + 7 = 17.

- **Input:** `Input: grid = [[0,1],[1,0]]`  \
  **Explanation:** Toggle the first row to make it [1, 0]. Then toggle the second column to make it [1, 1] and [1, 1]. The binary values are 0b11 (3) and 0b11 (3). Total score = 3 + 3 = 6.

{{< dots >}}
## Approach 🚀
A greedy approach is used to maximize the score by toggling rows and columns strategically.

### Initial Thoughts 💭
- The leftmost column has the highest weight in the binary score. Ensuring all 1s in the first column maximizes its contribution.
- For remaining columns, the contribution depends on the number of 1s. Maximizing 1s in each column maximizes the overall score.
- We can toggle rows to ensure the first column is all 1s, and then toggle columns to maximize the 1s in each column.
{{< dots >}}
### Edge Cases 🌐
- N/A: The constraints guarantee at least a 1x1 matrix.
- The matrix size can be up to 20x20. Ensure the solution efficiently processes matrices of this size.
- If all values are 0 initially, toggling all rows first ensures the maximum score.
- If all values are 1 initially, no toggles are needed.
- Input matrix values must strictly be binary (0 or 1).
{{< dots >}}
## Code 💻
```cpp
int matrixScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = (1 << n - 1) * m;

    for(int j = 1; j < n; j++) {
        int cur = 0;
        for(int i = 0; i < m; i++)
            cur += grid[i][0] == grid[i][j];
        res += max(cur, m - cur) * (1<<n-j-1);
    }

    return res;
}
```

This function calculates the maximum possible score of a matrix after performing row flips and column flips.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int matrixScore(vector<vector<int>>& grid) {
	```
	The function begins by accepting a 2D vector `grid` that represents a matrix of binary values.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Two variables `m` and `n` are initialized to store the number of rows and columns in the grid, respectively.

3. **Initial Result Calculation**
	```cpp
	    int res = (1 << n - 1) * m;
	```
	The initial score `res` is calculated based on the number of rows and the most significant bit of the matrix (represented by the left-most column).

4. **For Loop (Column Iteration)**
	```cpp
	    for(int j = 1; j < n; j++) {
	```
	For each column `j`, starting from column 1, we compute the contribution of the column to the score.

5. **Variable for Current Column Score**
	```cpp
	        int cur = 0;
	```
	A variable `cur` is initialized to calculate the score for the current column, based on the grid values.

6. **Inner Loop (Row Iteration)**
	```cpp
	        for(int i = 0; i < m; i++)
	```
	This inner loop iterates through each row `i` of the current column `j`.

7. **Check Column Values**
	```cpp
	            cur += grid[i][0] == grid[i][j];
	```
	The `cur` score is incremented if the value in the first column matches the value in the current column (`grid[i][j]`).

8. **Update Result**
	```cpp
	        res += max(cur, m - cur) * (1<<n-j-1);
	```
	The result `res` is updated by adding the maximum score obtainable for the current column (either flipping the column or not) multiplied by a power of 2 corresponding to the column's position.

9. **Return Statement**
	```cpp
	    return res;
	```
	Return the final calculated score after processing all columns.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where no toggling is needed and only the binary computation is performed.
- **Average Case:** O(m * n), as we toggle rows and compute column values.
- **Worst Case:** O(m * n), as all rows and columns may need toggling.



### Space Complexity 💾
- **Best Case:** O(1), since space usage remains constant.
- **Worst Case:** O(1), as no additional data structures are used apart from counters.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/score-after-flipping-matrix/description/)

---
{{< youtube FbhzRA5den8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
