
+++
authors = ["grid47"]
title = "Leetcode 2017: Grid Game"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2017: Grid Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "N4wDSOw65hI"
youtube_upload_date="2021-09-26"
youtube_thumbnail="https://i.ytimg.com/vi/N4wDSOw65hI/maxresdefault.jpg"
comments = true
+++



---
You are given a 2D grid of size 2 x n, where each cell contains points. Two robots play a game where they start at (0, 0) and aim to reach (1, n-1). The first robot moves first, collecting points along its path. Then, the second robot moves, trying to maximize the points it collects. The task is to find the number of points collected by the second robot if both play optimally.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array grid of size 2 x n, where each element grid[r][c] represents the number of points at position (r, c) in the grid.
- **Example:** `[[2, 5, 4], [1, 5, 1]]`
- **Constraints:**
	- grid.length == 2
	- n == grid[r].length
	- 1 <= n <= 5 * 10^4
	- 1 <= grid[r][c] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of points collected by the second robot after both robots have moved optimally.
- **Example:** `4`
- **Constraints:**
	- The output should be the total number of points collected by the second robot.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the movement of both robots while ensuring that the first robot minimizes the points collected by the second robot and the second robot maximizes its own points.

- Initialize variables to track the points collected by the first and second robots.
- Iterate through each column and update the points for both robots.
- For each robot, calculate the optimal path by updating the number of points in the grid after each robot’s move.
- Return the result of the second robot’s collected points.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always have two rows and at least one column.
- Both robots will move optimally to achieve their respective goals.
{{< dots >}}
## Examples 🧩
- **Input:** `[[2, 5, 4], [1, 5, 1]]`  \
  **Explanation:** The first robot moves optimally to minimize the points collected by the second robot. After its path, the second robot collects 4 points.

- **Input:** `[[3, 3, 1], [8, 5, 2]]`  \
  **Explanation:** After the first robot moves, the second robot is left with 4 points on its path, as it maximizes its collection.

- **Input:** `[[1, 3, 1, 15], [1, 3, 3, 1]]`  \
  **Explanation:** The second robot collects 7 points after the first robot moves optimally.

{{< dots >}}
## Approach 🚀
The approach involves simulating both robots’ moves while keeping track of the points collected by each robot and updating the grid after the first robot's movement.

### Initial Thoughts 💭
- The grid has two rows, and each robot moves from the start to the end while collecting points.
- The first robot should minimize the points for the second robot by picking a path with fewer points, and the second robot should aim to maximize its own collection.
{{< dots >}}
### Edge Cases 🌐
- The grid will always have two rows and at least one column, so there will be no empty inputs.
- Ensure the solution handles the upper limit of grid size (n = 50,000) efficiently.
- Handle cases where the grid has very small values (e.g., 1) or large values (e.g., 100,000).
- Ensure the algorithm runs within the time limits for large inputs (up to 50,000 columns).
{{< dots >}}
## Code 💻
```cpp
long long gridGame(vector<vector<int>>& grid) {
    long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
    long long bottom = 0;
    int n = grid[0].size();
    long long ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        top -= grid[0][i];
        ans = min(ans, max(top, bottom));
        bottom+= grid[1][i];
  }
    return ans;
}
```

This function calculates the minimum maximum score a player can achieve in a grid game by processing the grid values in two rows and optimizing the values for both the top and bottom positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long gridGame(vector<vector<int>>& grid) {
	```
	This defines the function `gridGame`, which takes a 2D vector `grid` representing the game grid and returns a `long long` value as the result.

2. **Variable Initialization**
	```cpp
	    long long top = accumulate(grid[0].begin(), grid[0].end(), 0LL);
	```
	This initializes the `top` variable by summing all elements of the first row of the grid using the `accumulate` function, starting with an initial value of 0.

3. **Variable Initialization**
	```cpp
	    long long bottom = 0;
	```
	This initializes the `bottom` variable to 0, which will accumulate values from the second row of the grid.

4. **Grid Size Calculation**
	```cpp
	    int n = grid[0].size();
	```
	This determines the number of columns in the grid (the size of the first row), which will be used as the upper bound for the loop.

5. **Variable Initialization**
	```cpp
	    long long ans = LLONG_MAX;
	```
	This initializes the `ans` variable to the maximum possible long long value, which will store the result of the minimum maximum score during the game.

6. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This starts a loop that iterates over each column of the grid.

7. **Top Row Update**
	```cpp
	        top -= grid[0][i];
	```
	This subtracts the value of the current column from the `top` variable, effectively removing the score for that column from the top row.

8. **Score Calculation**
	```cpp
	        ans = min(ans, max(top, bottom));
	```
	This calculates the current maximum of `top` and `bottom` and updates the result `ans` with the minimum value of `ans` and this new maximum.

9. **Bottom Row Update**
	```cpp
	        bottom+= grid[1][i];
	```
	This adds the value of the current column from the second row of the grid to the `bottom` variable.

10. **Return Statement**
	```cpp
	    return ans;
	```
	This returns the calculated result `ans`, which is the minimum of the maximum scores across all the iterations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm iterates through the columns of the grid once, so the time complexity is linear in terms of n.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant since we only need a few variables to track the robots' movements and points.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/grid-game/description/)

---
{{< youtube N4wDSOw65hI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
