
+++
authors = ["grid47"]
title = "Leetcode 2245: Maximum Trailing Zeros in a Cornered Path"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2245: Maximum Trailing Zeros in a Cornered Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QMRHGd9ftz8"
youtube_upload_date="2022-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/QMRHGd9ftz8/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D integer array called `grid` of size `m x n`, where each cell contains a positive integer. A cornered path is a specific path in the grid with at most one directional change. The path must move either horizontally or vertically up to a single turn and then continue in the alternate direction. The product of a path is the product of all integers in that path. The task is to find the maximum number of trailing zeros in the product of a cornered path.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer array `grid` of size `m x n`, where each element is a positive integer.
- **Example:** `grid = [[5, 2, 8], [3, 4, 7], [9, 6, 1]]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 1 <= m * n <= 10^5
	- 1 <= grid[i][j] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the maximum number of trailing zeros in the product of any cornered path in the grid.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the maximum number of trailing zeros in the product of a valid cornered path in the grid.

- Traverse the grid to calculate the number of factors of 2 and 5 for each cell.
- Precompute prefix sums for horizontal and vertical movements in the grid.
- For each cell, compute possible cornered paths in all four directions and calculate the product.
- Count trailing zeros by finding the minimum of the factors of 2 and 5 in the product.
{{< dots >}}
### Problem Assumptions ✅
- Grid dimensions are positive integers.
- The product of any path will not overflow standard data types.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[10, 5, 2], [2, 20, 4], [8, 7, 6]]`  \
  **Explanation:** One possible cornered path is [10 -> 5 -> 20 -> 4], which produces a product of 4000, with 3 trailing zeros.

- **Input:** `grid = [[3, 7], [8, 9]]`  \
  **Explanation:** All paths produce products without trailing zeros.

{{< dots >}}
## Approach 🚀
The solution involves factorizing the grid values and using precomputed prefix sums to efficiently calculate the factors of 2 and 5 for potential paths.

### Initial Thoughts 💭
- Trailing zeros in a number are determined by the minimum of the number of factors of 2 and 5 in its product.
- Cornered paths allow at most one change in direction.
- Factorize each cell and compute cumulative sums for each direction to evaluate paths efficiently.
{{< dots >}}
### Edge Cases 🌐
- The grid is guaranteed to be non-empty.
- Handle grids with dimensions close to 10^5 efficiently.
- Grid cells with value 1 contribute no factors of 2 or 5.
- Cells with large multiples of 10 might have high trailing zeros.
- Grid values must remain within the range [1, 1000].
{{< dots >}}
## Code 💻
```cpp
int fact(int i, int j) {
    return i % j ? 0 : 1 + fact(i/j, j);
}

int maxTrailingZeros(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), res = 0;
    
    vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m+1, vector<array<int, 2>>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int t = grid[i][j];
            array<int, 2> node = { fact(t, 2), fact(t, 5) };
            h[i][j + 1] = h[i][j] + node;
            v[i + 1][j] = v[i][j] + node;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            
            array<int, 2> h1 = h[i][j], 
            h2 = h[i][n] - h[i][j+1],
            v1 = v[i+1][j],
            v2 = v[m][j] - v[i][j];
            res = max({res, pairs(v1+h1), pairs(v1+h2), pairs(v2+h1), pairs(v2+h2)});
            
        }
        }
    
    return res;
}
```

This solution involves calculating the maximum number of trailing zeros that can be formed from any submatrix of a given 2D grid of integers. The function 'fact' computes how many times 2 or 5 divides a number, which is essential for determining trailing zeros.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int fact(int i, int j) {
	```
	The 'fact' function is defined here, which computes the number of times 'j' divides 'i'. It is used to calculate factors of 2 and 5 for trailing zero calculation.

2. **Base Case**
	```cpp
	    return i % j ? 0 : 1 + fact(i/j, j);
	```
	This is a recursive base case for the 'fact' function. If 'i' is divisible by 'j', it keeps dividing 'i' by 'j', adding 1 each time.

3. **Main Function Definition**
	```cpp
	int maxTrailingZeros(vector<vector<int>>& grid) {
	```
	This defines the 'maxTrailingZeros' function, which aims to calculate the maximum number of trailing zeros from any submatrix in a given 2D grid of integers.

4. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size(), res = 0;
	```
	Initializes the variables: 'm' is the number of rows in the grid, 'n' is the number of columns, and 'res' stores the result for the maximum number of trailing zeros.

5. **2D Array Initialization**
	```cpp
	    vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m+1, vector<array<int, 2>>(n));
	```
	Two 2D arrays 'h' and 'v' are initialized to store the cumulative factors of 2 and 5 for each cell in the grid, which will be used to compute trailing zeros.

6. **First Loop (Grid Iteration)**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop iterates over each row of the grid.

7. **Second Loop (Grid Iteration)**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	This nested loop iterates over each column of the grid.

8. **Grid Value Assignment**
	```cpp
	            int t = grid[i][j];
	```
	The value of the grid at position (i, j) is assigned to the variable 't'.

9. **Factor Calculation**
	```cpp
	            array<int, 2> node = { fact(t, 2), fact(t, 5) };
	```
	The 'node' array stores the factors of 2 and 5 for the current grid value 't'. These factors will help in calculating trailing zeros.

10. **Cumulative Horizontal Update**
	```cpp
	            h[i][j + 1] = h[i][j] + node;
	```
	The cumulative horizontal factors (2 and 5) are updated for the current position (i, j) in the 'h' array.

11. **Cumulative Vertical Update**
	```cpp
	            v[i + 1][j] = v[i][j] + node;
	```
	The cumulative vertical factors (2 and 5) are updated for the current position (i, j) in the 'v' array.

12. **Second Loop (Max Calculation)**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop iterates again over each row of the grid, this time to calculate the maximum trailing zeros.

13. **Second Nested Loop (Max Calculation)**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	This nested loop iterates again over each column to compute the maximum trailing zeros.

14. **Array Assignment for Calculation**
	```cpp
	            array<int, 2> h1 = h[i][j], 
	```
	This line extracts the horizontal factors (2 and 5) for the current cell (i, j) from the 'h' array.

15. **Array Assignment for Calculation**
	```cpp
	            h2 = h[i][n] - h[i][j+1],
	```
	This line calculates the difference in horizontal factors to handle the rest of the row beyond (i, j).

16. **Array Assignment for Calculation**
	```cpp
	            v1 = v[i+1][j],
	```
	This line extracts the vertical factors (2 and 5) for the current cell (i, j) from the 'v' array.

17. **Array Assignment for Calculation**
	```cpp
	            v2 = v[m][j] - v[i][j];
	```
	This line calculates the difference in vertical factors to handle the rest of the column beyond (i, j).

18. **Max Calculation**
	```cpp
	            res = max({res, pairs(v1+h1), pairs(v1+h2), pairs(v2+h1), pairs(v2+h2)});
	```
	The maximum trailing zeros are calculated by considering all possible combinations of horizontal and vertical factors.

19. **Return Result**
	```cpp
	    return res;
	```
	Returns the final result, which is the maximum number of trailing zeros found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

Each cell is processed once, and prefix sums allow efficient range queries.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space is used for prefix sum arrays and factorization storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/description/)

---
{{< youtube QMRHGd9ftz8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
