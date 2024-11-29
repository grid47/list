
+++
authors = ["grid47"]
title = "Leetcode 576: Out of Boundary Paths"
date = "2024-09-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 576: Out of Boundary Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/576.webp"
youtube = "Bg5CLRqtNmk"
youtube_upload_date="2024-01-26"
youtube_thumbnail="https://i.ytimg.com/vi/Bg5CLRqtNmk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/576.webp" 
    alt="A grid where paths leading out of bounds are highlighted and softly glowing."
    caption="Solution to LeetCode 576: Out of Boundary Paths Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an m x n grid and a ball placed at position [startRow, startColumn]. The ball can move to one of four adjacent cells or out of the grid boundary. You are allowed at most maxMove moves. Return the number of ways the ball can move out of the grid boundary modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of five integers representing the grid dimensions, maximum allowed moves, and the ball's starting position.
- **Example:** `Input: m = 3, n = 3, maxMove = 2, startRow = 1, startColumn = 1`
- **Constraints:**
	- 1 <= m, n <= 50
	- 0 <= maxMove <= 50
	- 0 <= startRow < m
	- 0 <= startColumn < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of ways to move the ball out of the grid boundary within the allowed moves, modulo 10^9 + 7.
- **Example:** `Output: 12`
- **Constraints:**
	- The result must be an integer modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the number of paths to move the ball out of the grid boundary within maxMove moves.

- Use a recursive approach to track the number of moves left and the ball's position.
- If the ball moves out of the grid boundary, count it as one valid path.
- Use memoization to avoid redundant calculations.
{{< dots >}}
### Problem Assumptions ✅
- The grid dimensions and ball position are valid.
- The ball can move in any direction, even if it immediately crosses the boundary.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: m = 3, n = 3, maxMove = 2, startRow = 1, startColumn = 1`  \
  **Explanation:** There are 12 possible ways for the ball to move out of the grid boundary within 2 moves.

- **Input:** `Input: m = 2, n = 3, maxMove = 3, startRow = 0, startColumn = 2`  \
  **Explanation:** The ball can move out of the grid boundary in 18 ways from the starting position.

{{< dots >}}
## Approach 🚀
The approach involves using Depth-First Search (DFS) with memoization to count the paths while avoiding redundant calculations.

### Initial Thoughts 💭
- The ball can move in four directions, and paths may overlap if revisiting positions.
- The number of moves is limited, so a recursive solution with memoization will be efficient.
- A grid-based recursive approach with boundary checks should solve this problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs due to constraints; the grid always has dimensions.
- For large grids (m, n = 50) and maxMove = 50, the algorithm must use memoization to remain efficient.
- The ball starts at the grid boundary; it might move out immediately.
- The solution must handle all inputs efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mod = (int) 1e9 + 7;
public:
int findPaths(int m, int n, int mv, int i, int j) {
    
    vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
    
    return dfs(m, n, mv, 0, i, j, mm);
    
}

int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {

    if (x < 0 || y < 0 || x >= m || y >= n) return 1;
    if (mv == mx)                           return 0;
    if (mm[mv][x][y] > -1)                  return mm[mv][x][y];

    int res = 0;
    res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
    res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
    res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
    res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;

    return mm[mv][x][y] = (res % mod);
}
```

The solution uses dynamic programming and recursion to calculate the number of paths in a grid that start at position `(i, j)` and can move in all 4 directions up, down, left, or right, for a total of `mv` moves. It utilizes memoization to store intermediate results and optimize the recursive calls.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the main `Solution` class which contains the function `findPaths` to solve the problem.

2. **Modulus Initialization**
	```cpp
	int mod = (int) 1e9 + 7;
	```
	Initializes the modulus `mod` to ( 10^9 + 7 ) for ensuring the result stays within integer limits.

3. **Access Modifier**
	```cpp
	public:
	```
	The public section of the class where the functions are accessible outside the class.

4. **Function Declaration - findPaths**
	```cpp
	int findPaths(int m, int n, int mv, int i, int j) {
	```
	The `findPaths` function initializes the dynamic programming table and calls the `dfs` function to calculate the number of possible paths.

5. **Memoization Table Initialization**
	```cpp
	    vector<vector<vector<int>>> mm(mv + 1, vector<vector<int>>(m, vector<int>(n, -1)));
	```
	Creates a 3D memoization table `mm` to store results for subproblems. Each element is initialized to -1 indicating that it hasn't been computed yet.

6. **Recursive Call to DFS**
	```cpp
	    return dfs(m, n, mv, 0, i, j, mm);
	```
	Calls the `dfs` function to start the recursive traversal and path calculation from the given starting position `(i, j)` with `mv` remaining moves.

7. **Function Declaration - dfs**
	```cpp
	int dfs(int m, int n, int mx, int mv, int x, int y, vector<vector<vector<int>>> & mm) {
	```
	The `dfs` function performs depth-first search to explore all possible paths from the current position `(x, y)` within `mv` moves.

8. **Boundary Check**
	```cpp
	    if (x < 0 || y < 0 || x >= m || y >= n) return 1;
	```
	Checks if the current position `(x, y)` is out of bounds of the grid. If so, returns 1 as the base case of the recursive call, indicating one valid path.

9. **Max Moves Check**
	```cpp
	    if (mv == mx)                           return 0;
	```
	Checks if the current number of moves has reached the maximum allowed moves `mx`. If so, it returns 0 since no more moves are left.

10. **Memoization Check**
	```cpp
	    if (mm[mv][x][y] > -1)                  return mm[mv][x][y];
	```
	Checks if the result for the current position `(x, y)` with `mv` moves has been previously computed. If so, it returns the stored result to avoid redundant calculations.

11. **Path Calculation**
	```cpp
	    int res = 0;
	```
	Initializes the variable `res` to store the total number of valid paths from the current position.

12. **Recursive Calls - Down**
	```cpp
	    res = ( res + dfs(m, n, mx, mv + 1, x + 1, y, mm) ) % mod;
	```
	Recursively calls `dfs` for moving down in the grid, incrementing the move count by 1.

13. **Recursive Calls - Up**
	```cpp
	    res = ( res + dfs(m, n, mx, mv + 1, x - 1, y, mm) ) % mod;
	```
	Recursively calls `dfs` for moving up in the grid, incrementing the move count by 1.

14. **Recursive Calls - Right**
	```cpp
	    res = ( res + dfs(m, n, mx, mv + 1, x, y + 1, mm) ) % mod;
	```
	Recursively calls `dfs` for moving right in the grid, incrementing the move count by 1.

15. **Recursive Calls - Left**
	```cpp
	    res = ( res + dfs(m, n, mx, mv + 1, x, y - 1, mm) ) % mod;
	```
	Recursively calls `dfs` for moving left in the grid, incrementing the move count by 1.

16. **Memoization Result Storage**
	```cpp
	    return mm[mv][x][y] = (res % mod);
	```
	Stores the computed result for the current position `(x, y)` with `mv` moves in the memoization table.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n * maxMove)
- **Average Case:** O(m * n * maxMove)
- **Worst Case:** O(m * n * maxMove)

Each grid position and number of remaining moves is calculated once, thanks to memoization.

### Space Complexity 💾
- **Best Case:** O(m * n * maxMove)
- **Worst Case:** O(m * n * maxMove)

The space complexity is driven by the memoization array, which has dimensions m x n x maxMove.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/out-of-boundary-paths/description/)

---
{{< youtube Bg5CLRqtNmk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
