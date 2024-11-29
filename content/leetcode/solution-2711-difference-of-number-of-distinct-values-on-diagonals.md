
+++
authors = ["grid47"]
title = "Leetcode 2711: Difference of Number of Distinct Values on Diagonals"
date = "2024-02-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2711: Difference of Number of Distinct Values on Diagonals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "i166oIOHaPE"
youtube_upload_date="2023-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/i166oIOHaPE/maxresdefault.jpg"
comments = true
+++



---
Given a 2D grid of size m x n, you are tasked with finding a new matrix where each cell value is the absolute difference between the count of distinct values in the diagonal cells to the left and above it, and the count of distinct values in the diagonal cells to the right and below it.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D grid (matrix) with m rows and n columns, where each cell contains an integer.
- **Example:** `Input: grid = [[4, 2, 7], [1, 5, 8], [9, 6, 3]]`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= grid[i][j] <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a new matrix where each element at position [r][c] is the absolute difference between the number of distinct values on the diagonal to the left and above the cell and the number of distinct values on the diagonal to the right and below the cell.
- **Example:** `Output: [[0, 0, 1], [0, 0, 1], [1, 0, 0]]`
- **Constraints:**
	- The result should be an m x n matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the difference between the number of distinct values on diagonals of the matrix for each cell.

- Step 1: For each cell in the matrix, compute the distinct values on the diagonal above and to the left (leftAbove).
- Step 2: For each cell in the matrix, compute the distinct values on the diagonal below and to the right (rightBelow).
- Step 3: For each cell, compute the absolute difference between the sizes of the distinct values in leftAbove and rightBelow, and store this in the result matrix.
{{< dots >}}
### Problem Assumptions ✅
- The input grid is non-empty and contains valid integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[4, 2, 7], [1, 5, 8], [9, 6, 3]]`  \
  **Explanation:** The output matrix is calculated as follows:
For cell [0][0], leftAbove is empty and rightBelow contains distinct values {5, 6, 3}, so the result is |0 - 3| = 3. Repeat this for all cells.

- **Input:** `Input: grid = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]`  \
  **Explanation:** For each cell, we calculate the leftAbove and rightBelow diagonals and their distinct values, then compute the absolute difference.

{{< dots >}}
## Approach 🚀
The approach involves iterating over the grid and for each element, finding the distinct values in the diagonals above-left and below-right, then calculating the absolute difference.

### Initial Thoughts 💭
- Each element's value is determined by its position in the grid and the diagonals to the left and above, and to the right and below.
- Using sets will help in counting distinct values on each diagonal.
{{< dots >}}
### Edge Cases 🌐
- The input grid will not be empty as per the constraints.
- For large grids (50x50), ensure that the solution is optimized for performance.
- For grids where all values are the same, the result matrix will be all zeros.
- Ensure that the solution works for both square and rectangular matrices.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ans(m, vector<int>(n, 0));
    set<int> ls, rs;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        int r = i - 1, c = j - 1;
        
        while(r >= 0 && c >= 0) {
            ls.insert(grid[r][c]);
            r--;
            c--;
        }
        
        r = i + 1, c = j + 1;
        
        while(r < m && c < n) {
            rs.insert(grid[r][c]);
            r++;
            c++;
        }
        int res = ls.size() - rs.size();
        ans[i][j] = abs(res);
        ls.clear();
        rs.clear();
    }
    return ans;
}
```

The `differenceOfDistinctValues` function calculates the difference between the number of distinct values in the upper-left and bottom-right diagonals for each element in a given 2D grid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
	```
	The function `differenceOfDistinctValues` is declared, which takes a reference to a 2D vector `grid` and returns a 2D vector of integers representing the difference in distinct values for each grid element.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Initialize variables `m` and `n` to store the number of rows and columns of the grid, respectively.

3. **2D Vector Initialization**
	```cpp
	    vector<vector<int>> ans(m, vector<int>(n, 0));
	```
	Initialize the 2D vector `ans` with the same dimensions as the grid and fill it with zeros. This will store the result of the distinct value differences.

4. **Set Declaration**
	```cpp
	    set<int> ls, rs;
	```
	Declare two sets, `ls` and `rs`, to store the distinct values found in the upper-left and bottom-right diagonals, respectively.

5. **Outer Loop (Rows)**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Iterate through each row of the grid using the index `i`.

6. **Inner Loop (Columns)**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Iterate through each column of the grid using the index `j`.

7. **Diagonal Calculation**
	```cpp
	        int r = i - 1, c = j - 1;
	```
	Initialize variables `r` and `c` to traverse the upper-left diagonal from the current position `(i, j)`. The initial values set the pointers to the position just above and to the left of the current element.

8. **Diagonal Traversal (Left-Up)**
	```cpp
	        while(r >= 0 && c >= 0) {
	```
	Begin a loop to traverse the upper-left diagonal, stopping when we reach the boundary of the grid.

9. **Set Insertion (Left-Up)**
	```cpp
	            ls.insert(grid[r][c]);
	```
	Insert the current element from the upper-left diagonal into the set `ls`, ensuring only distinct values are stored.

10. **Pointer Update (Left-Up)**
	```cpp
	            r--;
	```
	Move the pointer `r` upwards to continue traversing the diagonal.

11. **Pointer Update (Left-Up)**
	```cpp
	            c--;
	```
	Move the pointer `c` leftwards to continue traversing the diagonal.

12. **Diagonal Setup (Right-Down)**
	```cpp
	        r = i + 1, c = j + 1;
	```
	Reinitialize `r` and `c` to point to the position just below and to the right of the current element `(i, j)` for the bottom-right diagonal traversal.

13. **Diagonal Traversal (Right-Down)**
	```cpp
	        while(r < m && c < n) {
	```
	Begin a loop to traverse the bottom-right diagonal, stopping when we reach the boundary of the grid.

14. **Set Insertion (Right-Down)**
	```cpp
	            rs.insert(grid[r][c]);
	```
	Insert the current element from the bottom-right diagonal into the set `rs`, ensuring only distinct values are stored.

15. **Pointer Update (Right-Down)**
	```cpp
	            r++;
	```
	Move the pointer `r` downwards to continue traversing the diagonal.

16. **Pointer Update (Right-Down)**
	```cpp
	            c++;
	```
	Move the pointer `c` rightwards to continue traversing the diagonal.

17. **Difference Calculation**
	```cpp
	        int res = ls.size() - rs.size();
	```
	Calculate the difference between the number of distinct elements in the upper-left (`ls`) and bottom-right (`rs`) diagonals.

18. **Store Result**
	```cpp
	        ans[i][j] = abs(res);
	```
	Store the absolute value of the difference in the result matrix `ans` at position `(i, j)`.

19. **Clear Sets**
	```cpp
	        ls.clear();
	```
	Clear the `ls` set in preparation for the next iteration.

20. **Clear Sets**
	```cpp
	        rs.clear();
	```
	Clear the `rs` set in preparation for the next iteration.

21. **Return Statement**
	```cpp
	    return ans;
	```
	Return the `ans` matrix, which contains the differences of distinct values for each element in the grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we need to process each cell and its diagonals, where m is the number of rows and n is the number of columns.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) for storing the result matrix, and additional space is used for the sets storing distinct values in the diagonals.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/)

---
{{< youtube i166oIOHaPE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
