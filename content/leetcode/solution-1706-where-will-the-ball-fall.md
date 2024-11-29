
+++
authors = ["grid47"]
title = "Leetcode 1706: Where Will the Ball Fall"
date = "2024-05-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1706: Where Will the Ball Fall in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QydaN-AVEAA"
youtube_upload_date="2020-12-27"
youtube_thumbnail="https://i.ytimg.com/vi/QydaN-AVEAA/maxresdefault.jpg"
comments = true
+++



---
You have a 2-D grid representing a box, and a number of balls that will be dropped into the box. The box has diagonal boards in each cell, which can redirect the balls either left or right. Your task is to determine the path of each ball dropped from the top of the box. The ball can either fall out of the bottom, or get stuck if it hits a 'V' shaped pattern between two boards or is redirected into a wall.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2-D grid of size 'm' x 'n' where each element in the grid can either be 1 or -1. A value of 1 indicates a board that redirects a ball to the right, and -1 indicates a board that redirects a ball to the left. Additionally, you are given an integer 'n' representing the number of balls.
- **Example:** `[[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]`
- **Constraints:**
	- 1 <= grid.length <= 100
	- 1 <= grid[i].length <= 100
	- grid[i][j] is either 1 or -1
	- 1 <= n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of size 'n' where the 'i'th element represents the column that the 'i'th ball falls out of at the bottom of the box, or -1 if the ball gets stuck.
- **Example:** `[1,-1,-1,-1,-1]`
- **Constraints:**
	- The output array should contain integers between 0 and n-1, or -1 if a ball gets stuck.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the dropping of balls into the grid and track their paths based on the redirection rules.

- 1. For each ball, start at the top of a given column and simulate its movement through the grid.
- 2. At each row, check the direction of the board in the current cell and determine if the ball can be redirected.
- 3. If the ball hits a wall or gets stuck in a 'V' shaped pattern, mark it as stuck and break out of the loop.
- 4. If the ball reaches the bottom without getting stuck, track the column where it exits.
{{< dots >}}
### Problem Assumptions ✅
- Each ball will be dropped from the top of a column and can either exit the grid or get stuck.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1, 1, 1, -1, -1], [1, 1, 1, -1, -1], [-1, -1, -1, 1, 1], [1, 1, 1, 1, -1], [-1, -1, -1, -1, -1]]`  \
  **Explanation:** Ball 0 is dropped at column 0 and falls out at column 1. Ball 1 is dropped at column 1 but gets stuck between columns 2 and 3. Balls 2-4 also get stuck due to the V-shaped pattern.

- **Input:** `[[-1]]`  \
  **Explanation:** Ball 0 is dropped at column 0 but gets stuck against the left wall, resulting in -1.

- **Input:** `[[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]`  \
  **Explanation:** Each ball from columns 0-4 exits the box through the respective columns at the bottom. Ball 5 gets stuck.

{{< dots >}}
## Approach 🚀
Simulate the process of dropping each ball from the top and track its path using the grid's redirection rules.

### Initial Thoughts 💭
- We need to follow the path of each ball through the grid row by row.
- The grid's constraints (1, -1) provide clear redirection rules, making it possible to track each ball's path.
{{< dots >}}
### Edge Cases 🌐
- The grid will always have at least one row and column, so empty grids are not an issue.
- Ensure that the solution scales for large grids with up to 100 rows and columns.
- Check for cases where balls hit the wall or get stuck due to a V-shaped pattern.
- The solution must efficiently handle multiple balls and large grid sizes.
{{< dots >}}
## Code 💻
```cpp
vector<int> findBall(vector<vector<int>>& grid) {
    vector<int> res;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < n; i++) {
        int i1 = i, i2;
        for(int j = 0; j < m; j++) {
            i2 = i1 + grid[j][i1];
            if(i2 <0 || i2 >= n || grid[j][i1] != grid[j][i2]) {
                i1 = -1;
                break;
            }
            i1 = i2;
        }
        res.push_back(i1);
    }
    return res;
}
```

This function simulates the path of a ball falling through a grid of 'v' and '>' shaped tunnels. The ball starts at each column of the top row and follows the directions in each row's grid. It returns the column where the ball ends up in the bottom row.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findBall(vector<vector<int>>& grid) {
	```
	Defines the function `findBall` that simulates the ball's path through the grid.

2. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Initializes a vector `res` to store the result of the ball's final position for each column.

3. **Grid Size Calculation**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Calculates the dimensions of the grid, with `m` being the number of rows and `n` the number of columns.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over each column at the top of the grid where the ball can start.

5. **Initialization for Ball Movement**
	```cpp
	        int i1 = i, i2;
	```
	Sets the initial position of the ball (`i1` is the column index) and initializes `i2` to track the new column position.

6. **Inner Loop**
	```cpp
	        for(int j = 0; j < m; j++) {
	```
	Iterates through each row of the grid, simulating the ball's movement.

7. **Calculate Next Column**
	```cpp
	            i2 = i1 + grid[j][i1];
	```
	Calculates the next column index `i2` based on the direction in the current grid cell (`grid[j][i1]` is either 1 for '>' or -1 for 'v').

8. **Boundary and Direction Check**
	```cpp
	            if(i2 < 0 || i2 >= n || grid[j][i1] != grid[j][i2]) {
	```
	Checks if the ball has gone out of bounds or if it is stuck in a 'V' shape (where both directions are the same).

9. **Ball Stuck Condition**
	```cpp
	                i1 = -1;
	```
	Sets `i1` to -1 to indicate the ball is stuck (cannot move further).

10. **Exit Inner Loop**
	```cpp
	                break;
	```
	Exits the inner loop early if the ball is stuck.

11. **Update Ball Position**
	```cpp
	            i1 = i2;
	```
	Updates the ball's position to the new column `i2`.

12. **Store Ball's Final Position**
	```cpp
	        res.push_back(i1);
	```
	Stores the final position of the ball after it has moved through all the rows (or is stuck) in the vector `res`.

13. **Return Result**
	```cpp
	    return res;
	```
	Returns the result vector `res`, which contains the final positions for the ball starting from each column.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns in the grid.
- **Average Case:** O(m * n), since each ball may need to traverse through each row.
- **Worst Case:** O(m * n), since in the worst case, every ball might traverse the entire grid.

The time complexity is O(m * n) due to the nested iteration over rows and columns.

### Space Complexity 💾
- **Best Case:** O(n), if all balls exit immediately.
- **Worst Case:** O(n), since we store the result of each ball's path.

The space complexity is O(n) because we only store the result for each ball.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/where-will-the-ball-fall/description/)

---
{{< youtube QydaN-AVEAA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
