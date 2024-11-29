
+++
authors = ["grid47"]
title = "Leetcode 3128: Right Triangles"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3128: Right Triangles in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Combinatorics","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SgwaC6fRCSE"
youtube_upload_date="2024-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/SgwaC6fRCSE/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D binary matrix grid, where each element is either 0 or 1. A collection of three elements of the grid is considered a right triangle if one element lies in the same row as another and in the same column as the third. The three elements must not be adjacent to each other. Your task is to count the number of right triangles that can be formed where all three elements have a value of 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D binary matrix grid of size m x n, where each element is either 0 or 1.
- **Example:** `Example 1:
Input: grid = [[0, 1, 0], [0, 1, 1], [0, 1, 0]]

Example 2:
Input: grid = [[1, 0, 0, 0], [0, 1, 0, 1], [1, 0, 0, 0]]`
- **Constraints:**
	- 1 <= grid.length <= 1000
	- 1 <= grid[i].length <= 1000
	- 0 <= grid[i][j] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of right triangles that can be formed using the 1's in the grid.
- **Example:** `Example 1:
Output: 2

Example 2:
Output: 0`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count all possible right triangles formed by the 1's in the grid.

- Use dynamic programming to count the number of 1's in the row and column directions for each cell.
- Iterate through each cell and check if it can form a right triangle with other cells in the same row and column that contain 1's.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is always a valid 2D binary grid.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** In this case, the two right triangles that can be formed have all 1's as their elements. These two right triangles are formed from grid positions that satisfy the condition of a right triangle.

- **Input:** `Example 2`  \
  **Explanation:** Here, there are no possible right triangles because no three elements form a valid right triangle.

{{< dots >}}
## Approach 🚀
This problem can be solved by leveraging dynamic programming to track the number of 1's along rows and columns for each cell. Once this information is available, we can efficiently check for potential right triangles.

### Initial Thoughts 💭
- The problem involves a large grid, so we must focus on efficiency in counting 1's in rows and columns.
- Dynamic programming seems to be the optimal approach to solve this problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- Empty matrices should return 0 as no triangles can be formed.
- For very large inputs, ensure the solution handles matrix sizes up to the maximum constraint efficiently.
- A grid consisting entirely of 0's should return 0, as no right triangles can be formed.
- The grid is guaranteed to have at least one element.
{{< dots >}}
## Code 💻
```cpp
long long numberOfRightTriangles(vector<vector<int>>& grid) {
    
    int m = grid.size(), n = grid[0].size();
    
    vector<vector<int>> hr = grid;
    vector<vector<int>> vr = grid;        
    
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            hr[i][j] += hr[i][j - 1];
            // cout << hr[i][j] << " ";
        }
        // cout << "\n";
    }


    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            vr[i][j] += vr[i - 1][j];            
            // cout << vr[i][j] << " ";
        }
        // cout << "\n";
    }


    long long  cnt = 0, net;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(grid[i][j]) {
            // if(i == 1 && j == 1) {
            //     cout << ((vr[m - 1][j] - vr[i][j]) + (i >= 1? vr[i - 1][j]: 0));                    
            // }

            net = (hr[i][n - 1] - 1) * ((vr[m - 1][j] - vr[i][j]) + (i > 0? vr[i - 1][j]: 0));
            // cout << i << " " << j << " " << net << "\n";
            cnt += net;
            
        }
    }        
    return cnt;
    
}
```

This function calculates the number of right-angled triangles in a given grid, using dynamic programming techniques to accumulate row and column sums. It checks for potential triangle formations by considering horizontal and vertical grid values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long numberOfRightTriangles(vector<vector<int>>& grid) {
	```
	Defines the function `numberOfRightTriangles` which takes a 2D grid as input and returns the count of right-angled triangles.

2. **Variable Initialization**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Initializes variables `m` and `n` to store the number of rows and columns of the grid.

3. **Grid Initialization**
	```cpp
	    vector<vector<int>> hr = grid;
	```
	Creates a copy of the grid named `hr` to store horizontal cumulative sums.

4. **Grid Initialization**
	```cpp
	    vector<vector<int>> vr = grid;        
	```
	Creates a copy of the grid named `vr` to store vertical cumulative sums.

5. **Horizontal Sum Calculation**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Starts the loop to iterate over each row of the grid for horizontal cumulative sum calculations.

6. **Nested Loop**
	```cpp
	        for(int j = 1; j < n; j++) {
	```
	Inner loop to calculate the horizontal cumulative sum for each row.

7. **Sum Calculation**
	```cpp
	            hr[i][j] += hr[i][j - 1];
	```
	Updates the horizontal sum by adding the previous horizontal value.

8. **Vertical Sum Calculation**
	```cpp
	    for(int i = 1; i < m; i++) {
	```
	Starts the loop to calculate vertical cumulative sums.

9. **Nested Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Inner loop to calculate the vertical cumulative sum for each column.

10. **Sum Calculation**
	```cpp
	            vr[i][j] += vr[i - 1][j];            
	```
	Updates the vertical sum by adding the previous vertical value.

11. **Triangle Calculation**
	```cpp
	    long long  cnt = 0, net;
	```
	Initializes counters for the total number of triangles (`cnt`) and a temporary variable (`net`) for each triangle calculation.

12. **Double Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Outer loop to iterate over each row.

13. **Nested Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Inner loop to iterate over each column.

14. **Check for Valid Grid Cell**
	```cpp
	        if(grid[i][j]) {
	```
	Checks if the current grid cell has a value indicating a potential right-angled triangle.

15. **Triangle Calculation**
	```cpp
	            net = (hr[i][n - 1] - 1) * ((vr[m - 1][j] - vr[i][j]) + (i > 0? vr[i - 1][j]: 0));
	```
	Calculates the number of triangles formed by the current grid cell.

16. **Update Count**
	```cpp
	            cnt += net;
	```
	Adds the calculated number of triangles to the total count.

17. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the total number of right-angled triangles.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The algorithm iterates through each cell in the matrix once and performs constant-time operations for each cell.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We use additional space to store the cumulative counts of 1's in the horizontal and vertical directions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/right-triangles/description/)

---
{{< youtube SgwaC6fRCSE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
