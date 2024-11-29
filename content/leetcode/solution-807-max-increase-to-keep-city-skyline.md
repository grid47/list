
+++
authors = ["grid47"]
title = "Leetcode 807: Max Increase to Keep City Skyline"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 807: Max Increase to Keep City Skyline in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/807.webp"
youtube = "uVPkYy5jzRo"
youtube_upload_date="2023-02-06"
youtube_thumbnail="https://i.ytimg.com/vi/uVPkYy5jzRo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/807.webp" 
    alt="A skyline of buildings with the maximum increase calculated, glowing softly as each increase is added."
    caption="Solution to LeetCode 807: Max Increase to Keep City Skyline Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
In a city grid, buildings are represented by an n x n matrix where each element corresponds to the height of a building at a specific location. You can increase the height of any building in the city grid, but the increased height should not alter the skyline of the city when viewed from any of the four cardinal directions (north, south, east, and west). Your task is to calculate the maximum sum of the heights that can be added to the buildings without changing the skyline.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an n x n grid where each grid[i][j] represents the height of a building at row i and column j.
- **Example:** `Input: grid = [[1, 3, 2],[4, 1, 5],[6, 3, 4]]`
- **Constraints:**
	- n == grid.length
	- n == grid[r].length
	- 2 <= n <= 50
	- 0 <= grid[r][c] <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum sum that the heights of the buildings can be increased by without affecting the skyline.
- **Example:** `Output: 10`
- **Constraints:**
	- The sum must be calculated based on the heights of the buildings without affecting the skyline from any direction.

{{< dots >}}
### Core Logic 🔍
**Goal:** To maximize the height of buildings without altering the skyline, we need to calculate the maximum possible height increase for each building by comparing it to the skyline views from each direction.

- Find the maximum building heights for each row and column (north-south and west-east).
- For each building, calculate the maximum height it can reach based on the minimum of the corresponding row and column maximums.
- Sum up the differences between the calculated maximum heights and the original building heights to get the total increase in height.
{{< dots >}}
### Problem Assumptions ✅
- The height of any building can be increased, but the changes must respect the skyline constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1, 3, 2],[4, 1, 5],[6, 3, 4]]`  \
  **Explanation:** In this grid, the maximum sum that the heights of buildings can be increased by is 10. The calculated skyline views from all four directions (north, south, east, and west) are taken into account to ensure that increasing the height of any building does not alter the skyline.

{{< dots >}}
## Approach 🚀
To solve this problem, we will compute the maximum possible height for each building that maintains the city's skyline from all four cardinal directions. This involves finding the maximum building heights for each row and column, then using these to determine the permissible increase for each building.

### Initial Thoughts 💭
- We can maintain the skyline by respecting the maximum height from each direction.
- The problem requires iterating over the rows and columns to calculate the maximum heights from each direction and then determining the feasible height increase for each building.
{{< dots >}}
### Edge Cases 🌐
- If the grid has no buildings (n=0), the result will be 0.
- For large grids (n=50), ensure that the solution efficiently handles the size and performs within time limits.
- If all buildings are at the maximum possible height, no increase can be made.
- The solution must account for the constraints of grid size and building heights.
{{< dots >}}
## Code 💻
```cpp
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> row(n, 0), col(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            row[i] = max(row[i], grid[i][j]);
            col[j] = max(col[j], grid[i][j]);
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
        res += min(row[i], col[j]) - grid[i][j];
    }
    return res;
}
```

This function computes the maximum possible increase in the grid heights while maintaining the skyline view. It iterates over the grid to determine the maximum heights of each row and column and then computes the total increase for each element in the grid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
	```
	This defines the function `maxIncreaseKeepingSkyline` which takes a 2D vector `grid` as input and returns an integer. The function aims to calculate the maximum increase in grid height while keeping the skyline unchanged.

2. **Variable Initialization**
	```cpp
	    int n = grid.size();
	```
	Here, we initialize the variable `n` which stores the size of the grid (i.e., the number of rows or columns, assuming the grid is square).

3. **Array Initialization**
	```cpp
	    vector<int> row(n, 0), col(n, 0);
	```
	We create two vectors `row` and `col`, both of size `n`, initialized to 0. These will store the maximum values for each row and column in the grid, respectively.

4. **Outer Loop - Rows**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	We start an outer loop that iterates over each row of the grid.

5. **Inner Loop - Columns**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	This inner loop iterates over each column in the current row.

6. **Row Maximum Calculation**
	```cpp
	            row[i] = max(row[i], grid[i][j]);
	```
	This line updates the maximum value for the current row `i` by comparing the current element `grid[i][j]` with the existing value stored in `row[i]`.

7. **Column Maximum Calculation**
	```cpp
	            col[j] = max(col[j], grid[i][j]);
	```
	Similarly, this line updates the maximum value for the current column `j` by comparing the current element `grid[i][j]` with the existing value stored in `col[j]`.

8. **Result Initialization**
	```cpp
	    int res = 0;
	```
	We initialize a variable `res` to store the result, which will accumulate the total increase in height for the grid.

9. **Nested Loop for Calculation**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	We start a loop to iterate over each row again to calculate the increase for each element.

10. **Inner Loop for Calculation**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	An inner loop is used to process each element in the grid for a given row.

11. **Grid Height Increase Calculation**
	```cpp
	        res += min(row[i], col[j]) - grid[i][j];
	```
	For each element in the grid, we compute the maximum possible increase in height by subtracting the current value from the minimum of the maximum row and column heights.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the total calculated increase in grid heights.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the size of the grid.
- **Average Case:** O(n^2), as each building must be processed individually.
- **Worst Case:** O(n^2), since the grid size is bounded by n = 50, leading to a manageable number of operations.

The time complexity is quadratic in the size of the grid due to the need to process both rows and columns.

### Space Complexity 💾
- **Best Case:** O(n), since we only need additional space for row and column maximums.
- **Worst Case:** O(n), as space is needed to store the row and column maximums.

The space complexity is linear with respect to the grid size, as we only need to store the row and column maximum heights.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/)

---
{{< youtube uVPkYy5jzRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
