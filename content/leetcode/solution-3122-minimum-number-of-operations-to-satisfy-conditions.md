
+++
authors = ["grid47"]
title = "Leetcode 3122: Minimum Number of Operations to Satisfy Conditions"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3122: Minimum Number of Operations to Satisfy Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "LLDe54TfbMs"
youtube_upload_date="2024-04-21"
youtube_thumbnail="https://i.ytimg.com/vi/LLDe54TfbMs/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D matrix `grid` of size `m x n`. In one operation, you can change the value of any cell to any non-negative number. Your task is to perform operations such that each cell is equal to the cell below it, and different from the cell to its right. Return the minimum number of operations needed to achieve these conditions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D matrix `grid` with `m` rows and `n` columns.
- **Example:** `grid = [[2, 1, 3], [2, 0, 3]]`
- **Constraints:**
	- 1 <= n, m <= 1000
	- 0 <= grid[i][j] <= 9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations needed to make each cell equal to the cell below it and different from the cell to its right.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum number of operations to make the grid satisfy the given conditions.

- 1. Initialize a frequency table to count the occurrences of each value in each column of the grid.
- 2. Use dynamic programming to recursively calculate the minimum number of operations needed by considering each column and ensuring the constraints are met.
- 3. Memoize the results of subproblems to avoid redundant calculations.
{{< dots >}}
### Problem Assumptions ✅
- The matrix consists of non-negative integers between 0 and 9.
- There will always be at least one row and one column in the matrix.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[2, 1, 3], [2, 0, 3]]`  \
  **Explanation:** The matrix can be modified to [[2, 1, 3], [2, 1, 3]] with 1 operation, changing grid[1][1] to 1.

- **Input:** `grid = [[3, 3], [3, 3], [3, 3]]`  \
  **Explanation:** The matrix already satisfies the conditions, so no operations are needed.

- **Input:** `grid = [[1, 0], [1, 0], [1, 1]]`  \
  **Explanation:** The matrix can be modified to [[1, 0], [1, 0], [1, 0]] with 1 operation, changing grid[2][1] to 0.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming. We will calculate the frequency of each value in every column and use recursion to calculate the minimum number of operations needed to satisfy the constraints.

### Initial Thoughts 💭
- The matrix needs to satisfy two conditions: matching values vertically and differing values horizontally.
- We can optimize the solution by breaking the problem into subproblems and using memoization to avoid redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- The grid will always contain at least one row and one column, as per the problem constraints.
- The solution should handle large grids up to the maximum constraints efficiently.
- If the grid already satisfies the conditions, the output should be 0.
- The matrix will only contain non-negative integers between 0 and 9.
{{< dots >}}
## Code 💻
```cpp

int m, n;
vector<vector<int>> frq, mem;

int dp(int i, int prv) {
    if(i == frq.size()) return 0;
    if(mem[i][prv + 1] != -1) return mem[i][prv + 1];

    int ans = INT_MAX;
    for(int j = 0; j <= 9; j++) {
        if(j == prv) continue;
        ans = min(ans, m - frq[i][j] + dp(i + 1, j));
    }

    return mem[i][prv + 1] = ans;
}

int minimumOperations(vector<vector<int>>& grid) {
    
    m = grid.size(), n = grid[0].size();
    
    frq.resize(n, vector<int>(10, 0));
    mem.resize(n, vector<int>(11, -1));
    
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        frq[i][grid[j][i]]++;
    }
    
    return dp(0, -1);
}
```

This code calculates the minimum number of operations required to make all the rows in a grid have distinct values. It uses dynamic programming to solve this problem efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int m, n;
	```
	Declare two integer variables 'm' and 'n' to store the number of rows and columns of the grid, respectively.

2. **Vector Initialization**
	```cpp
	vector<vector<int>> frq, mem;
	```
	Declare two 2D vectors: 'frq' to store frequency counts and 'mem' for memoization during dynamic programming.

3. **Function Definition**
	```cpp
	int dp(int i, int prv) {
	```
	Define a recursive function 'dp' that takes the current row index 'i' and the previous row's column value 'prv' as parameters.

4. **Base Case**
	```cpp
	    if(i == frq.size()) return 0;
	```
	Check if we've reached the end of the rows. If so, return 0 since no more operations are needed.

5. **Memoization Check**
	```cpp
	    if(mem[i][prv + 1] != -1) return mem[i][prv + 1];
	```
	Check if the result for the current state has already been computed using memoization. If so, return the stored value.

6. **Variable Initialization**
	```cpp
	    int ans = INT_MAX;
	```
	Initialize a variable 'ans' to store the minimum number of operations, set to the maximum possible value initially.

7. **Loop Through Digits**
	```cpp
	    for(int j = 0; j <= 9; j++) {
	```
	Iterate through the digits 0 to 9 and try to pick the optimal value for the current row.

8. **Skip If Same As Previous**
	```cpp
	        if(j == prv) continue;
	```
	Skip this digit if it is the same as the digit from the previous row, as we want distinct values across rows.

9. **Dynamic Programming Recursion**
	```cpp
	        ans = min(ans, m - frq[i][j] + dp(i + 1, j));
	```
	Recursively calculate the minimum number of operations for the next row, adjusting for the frequency of the current digit.

10. **Memoization Store**
	```cpp
	    return mem[i][prv + 1] = ans;
	```
	Store the result in the memoization table for the current state and return the computed value.

11. **Function Definition**
	```cpp
	int minimumOperations(vector<vector<int>>& grid) {
	```
	Define the main function 'minimumOperations' that takes the grid as input and calculates the minimum operations.

12. **Matrix Size Calculation**
	```cpp
	    m = grid.size(), n = grid[0].size();
	```
	Calculate the number of rows ('m') and columns ('n') from the input grid.

13. **Frequency Vector Initialization**
	```cpp
	    frq.resize(n, vector<int>(10, 0));
	```
	Resize the frequency table 'frq' to match the grid's dimensions, initializing all values to 0.

14. **Memoization Vector Initialization**
	```cpp
	    mem.resize(n, vector<int>(11, -1));
	```
	Resize the memoization table 'mem' to store results for dynamic programming, initializing all values to -1 (indicating no result stored).

15. **Frequency Table Filling**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through the columns of the grid.

16. **Grid Iteration**
	```cpp
	    for(int j = 0; j < m; j++) {
	```
	Loop through the rows of the grid.

17. **Frequency Count Update**
	```cpp
	        frq[i][grid[j][i]]++;
	```
	Update the frequency table by incrementing the count for the digit found at grid[j][i].

18. **Return DP Result**
	```cpp
	    return dp(0, -1);
	```
	Call the dynamic programming function to compute the result starting from the first row and no previous value.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the grid. We process each cell once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n), where we store the frequency table and memoization results for each column.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/)

---
{{< youtube LLDe54TfbMs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
