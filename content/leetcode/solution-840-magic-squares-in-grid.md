
+++
authors = ["grid47"]
title = "Leetcode 840: Magic Squares In Grid"
date = "2024-08-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 840: Magic Squares In Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FV52wWrivNc"
youtube_upload_date="2024-08-09"
youtube_thumbnail="https://i.ytimg.com/vi/FV52wWrivNc/maxresdefault.jpg"
comments = true
+++



---
Given a grid of integers, the task is to find how many 3x3 magic square subgrids are present in the given grid. A 3x3 magic square is a grid that contains distinct numbers from 1 to 9, such that each row, each column, and both diagonals have the same sum. The input grid can contain numbers ranging from 0 to 15, but only numbers between 1 and 9 are valid for forming a magic square.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid of integers. The grid may contain numbers from 0 to 15. You need to identify all 3x3 subgrids that form a magic square.
- **Example:** `Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]`
- **Constraints:**
	- 1 <= row, col <= 10
	- 0 <= grid[i][j] <= 15

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the count of 3x3 magic square subgrids in the given grid.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be a non-negative integer representing the count of magic square subgrids.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to iterate through the grid and identify all possible 3x3 subgrids, check if they form a magic square, and count how many such squares exist.

- Step 1: Iterate through all possible 3x3 subgrids in the given grid.
- Step 2: For each subgrid, check if it contains distinct numbers from 1 to 9.
- Step 3: Verify if the sum of each row, column, and both diagonals is the same.
- Step 4: If the subgrid forms a magic square, increment the count.
- Step 5: Return the count of magic square subgrids.
{{< dots >}}
### Problem Assumptions ✅
- The grid contains integers within the specified range, but only numbers between 1 and 9 can form a valid magic square.
- The grid may contain numbers greater than 9, but they will not be considered part of the magic square.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: [[4, 3, 8, 4], [9, 5, 1, 9], [2, 7, 6, 2]]`  \
  **Explanation:** In this grid, the subgrid containing the numbers 4, 3, 8, 9, 5, 1, 2, 7, 6 forms a valid 3x3 magic square because the sum of each row, column, and diagonal is 15.

- **Input:** `Input: [[8]]`  \
  **Explanation:** In this case, the grid is too small to contain any 3x3 subgrids, so the output is 0.

{{< dots >}}
## Approach 🚀
The approach involves checking each possible 3x3 subgrid in the grid, verifying if the numbers are distinct and within the valid range, and then checking if they form a magic square.

### Initial Thoughts 💭
- To solve the problem efficiently, we need to iterate through the grid and extract each possible 3x3 subgrid.
- We must check if the values are distinct and lie between 1 and 9.
- By checking the sum of rows, columns, and diagonals, we can determine whether a given subgrid is a magic square.
{{< dots >}}
### Edge Cases 🌐
- If the grid is smaller than 3x3, no magic squares can exist.
- For grids near the maximum size of 10x10, ensure the solution handles the larger number of possible subgrids efficiently.
- Grids containing values outside the valid range (1-9) should not be considered for magic square formation.
- Ensure the grid dimensions are within the specified limits, and handle values greater than 9 appropriately.
{{< dots >}}
## Code 💻
```cpp
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    for(int i = 0; i < m -2; i++)
    for(int j = 0; j < n -2; j++)
        if(isMagic(grid, i, j))
         res++;
    return res;
}

bool isMagic(vector<vector<int>> &grid, int row, int col) {
    int record[10] = {0};
    for(int i = row; i < row + 3; i++)
    for(int j = col; j < col + 3; j++) {
        if(grid[i][j] < 1 || grid[i][j] > 9 || record[grid[i][j]] > 0)
        return false;
        record[grid[i][j]] = 1;
    }
    int sum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
    int sum2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
    if(sum1 != sum2) return false;
    for(int i = 0; i < 3; i++) {
        if(grid[row+i][col] + grid[row+i][col+1]+ grid[row+i][col+2] != sum1)
        return false;
        if(grid[row][col+i] + grid[row+1][col+i]+ grid[row+2][col+i] != sum1)
        return false;
    }
    return true;
}
```

This code defines a function to count the number of 3x3 magic squares in a grid. It also includes a helper function to check if a 3x3 grid is a magic square.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	int numMagicSquaresInside(vector<vector<int>>& grid) {
	```
	The main function that counts the number of magic squares inside the given grid. It iterates through potential 3x3 subgrids.

2. **Variable Declaration**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Declare the dimensions of the grid (m rows and n columns).

3. **Variable Initialization**
	```cpp
	    int res = 0;
	```
	Initialize the result variable to count the number of magic squares.

4. **Loop**
	```cpp
	    for(int i = 0; i < m - 2; i++)
	```
	Outer loop to iterate through all possible starting rows for 3x3 subgrids.

5. **Loop**
	```cpp
	    for(int j = 0; j < n - 2; j++)
	```
	Inner loop to iterate through all possible starting columns for 3x3 subgrids.

6. **Conditional**
	```cpp
	        if(isMagic(grid, i, j))
	```
	Check if the current 3x3 subgrid starting at (i, j) is a magic square.

7. **Increment**
	```cpp
	         res++;
	```
	If the subgrid is a magic square, increment the result.

8. **Return**
	```cpp
	    return res;
	```
	Return the total count of magic squares.

9. **Function**
	```cpp
	bool isMagic(vector<vector<int>> &grid, int row, int col) {
	```
	Helper function to check if a 3x3 subgrid starting at (row, col) is a magic square.

10. **Array Initialization**
	```cpp
	    int record[10] = {0};
	```
	Initialize an array to track numbers that have been seen in the 3x3 subgrid.

11. **Loop**
	```cpp
	    for(int i = row; i < row + 3; i++)
	```
	Loop through the rows of the 3x3 subgrid.

12. **Loop**
	```cpp
	    for(int j = col; j < col + 3; j++) {
	```
	Loop through the columns of the 3x3 subgrid.

13. **Conditional**
	```cpp
	        if(grid[i][j] < 1 || grid[i][j] > 9 || record[grid[i][j]] > 0)
	```
	Check if the current number is out of the valid range (1 to 9) or has been seen before.

14. **Return**
	```cpp
	        return false;
	```
	Return false if the current subgrid is invalid.

15. **Update**
	```cpp
	        record[grid[i][j]] = 1;
	```
	Mark the current number as seen.

16. **Sum Calculation**
	```cpp
	    int sum1 = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
	```
	Calculate the sum of the main diagonal of the 3x3 subgrid.

17. **Sum Calculation**
	```cpp
	    int sum2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
	```
	Calculate the sum of the anti-diagonal of the 3x3 subgrid.

18. **Conditional**
	```cpp
	    if(sum1 != sum2) return false;
	```
	If the diagonal sums are not equal, return false.

19. **Loop**
	```cpp
	    for(int i = 0; i < 3; i++) {
	```
	Loop through the rows and columns to check if all rows and columns sum to the same value.

20. **Conditional**
	```cpp
	        if(grid[row+i][col] + grid[row+i][col+1]+ grid[row+i][col+2] != sum1)
	```
	Check if the sum of each row is equal to the diagonal sum.

21. **Return**
	```cpp
	        return false;
	```
	Return false if a row sum does not match the expected sum.

22. **Conditional**
	```cpp
	        if(grid[row][col+i] + grid[row+1][col+i]+ grid[row+2][col+i] != sum1)
	```
	Check if the sum of each column is equal to the diagonal sum.

23. **Return**
	```cpp
	        return false;
	```
	Return false if a column sum does not match the expected sum.

24. **Return**
	```cpp
	    return true;
	```
	Return true if the subgrid is a magic square.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(row * col)
- **Average Case:** O(row * col)
- **Worst Case:** O(row * col)

The time complexity is proportional to the number of subgrids that need to be checked, which is O(row * col).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, O(1), since we are using a fixed amount of additional space to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/magic-squares-in-grid/description/)

---
{{< youtube FV52wWrivNc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
