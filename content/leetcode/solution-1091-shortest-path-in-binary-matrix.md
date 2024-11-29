
+++
authors = ["grid47"]
title = "Leetcode 1091: Shortest Path in Binary Matrix"
date = "2024-07-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1091: Shortest Path in Binary Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "U3VJjmvRVLY"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/U3VJjmvRVLY/maxresdefault.jpg"
comments = true
+++



---
Given an n x n binary matrix grid, find the shortest clear path in the matrix that connects the top-left cell (0, 0) to the bottom-right cell (n-1, n-1). A clear path is defined as a path where all cells along the path are 0, and the path can move in 8 possible directions (up, down, left, right, and diagonals). Return the length of the shortest clear path, or -1 if no such path exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the size of the grid, followed by an n x n binary matrix `grid`, where each cell contains either a 0 or a 1. A 0 represents a free cell and a 1 represents an obstacle. Additionally, the goal is to find the shortest clear path from the top-left cell (0, 0) to the bottom-right cell (n-1, n-1).
- **Example:** `Input: grid = [[0,1],[1,0]]`
- **Constraints:**
	- 1 <= n <= 100
	- grid[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the shortest clear path in the grid, or -1 if no such path exists. The path must be clear, with each cell in the path containing 0, and the cells must be connected by 8-directional movement.
- **Example:** `Output: 2`
- **Constraints:**
	- If no clear path exists, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the shortest path, we use a breadth-first search (BFS) approach, which explores all possible paths and ensures the shortest path is found first.

- 1. Initialize a queue with the top-left cell (0, 0) and mark it as visited.
- 2. Use BFS to explore all 8-directional neighbors of each cell.
- 3. If the bottom-right cell (n-1, n-1) is reached, return the length of the path.
- 4. If the queue is empty and the bottom-right cell is not reached, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The grid is properly formed with dimensions n x n.
- The pathfinding should consider only cells that contain 0.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[0,1],[1,0]]`  \
  **Explanation:** The grid is a 2x2 matrix. The clear path is from (0, 0) to (1, 1), and the shortest path length is 2, as we move diagonally.

- **Input:** `Input: grid = [[0,0,0],[1,1,0],[1,1,0]]`  \
  **Explanation:** In this case, the shortest path from (0, 0) to (2, 2) is 4, taking the clear path through (0,0) -> (0,1) -> (1,2) -> (2,2).

- **Input:** `Input: grid = [[1,0,0],[1,1,0],[1,1,0]]`  \
  **Explanation:** In this case, it's impossible to reach (2, 2) from (0, 0) due to obstacles, so the output is -1.

{{< dots >}}
## Approach 🚀
We can solve this problem using a breadth-first search (BFS) algorithm, which will explore all possible paths from the top-left to the bottom-right corner while ensuring we always find the shortest path first.

### Initial Thoughts 💭
- The grid allows movement in 8 directions, which means we need to explore all 8 neighbors at each step.
- We need to ensure that we keep track of visited cells to avoid cycles or reprocessing.
- Using BFS is a natural choice for this problem, as it guarantees finding the shortest path in an unweighted grid.
{{< dots >}}
### Edge Cases 🌐
- If the grid is 1x1, the start and end are the same, and the output is 1 if the cell is 0.
- The algorithm should efficiently handle grids as large as 100x100, ensuring that the BFS explores all valid paths without performance issues.
- If the grid has obstacles blocking the entire path, return -1 as no path exists.
- Ensure that the BFS handles both small grids (e.g., 2x2) and large grids (up to 100x100).
{{< dots >}}
## Code 💻
```cpp
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(grid[0][0] == 1) return -1;
    queue<pair<int, int>> q;
    vector<vector<int>> dir = {{0, 1}, {0,-1}, {1, 0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1}};
    q.push(make_pair(0,0));
    grid[0][0] = 1;
    while(!q.empty()) {
        auto p = q.front();
        int x = p.first, y = p.second;
        if(x == m -1 && y == n -1) return grid[x][y];
        
        for(auto d: dir) {
            int i = x + d[0], j = y + d[1];
            if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 0)
                continue;
            grid[i][j] = grid[x][y] + 1;
            q.push(make_pair(i, j));
        }
        q.pop();
    }
    return -1;
}
```

The function `shortestPathBinaryMatrix` returns the length of the shortest path from the top-left corner to the bottom-right corner of a binary matrix, where each step can move to any of the eight neighboring cells. The function uses a breadth-first search (BFS) approach for optimal performance.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	```
	This line defines the function `shortestPathBinaryMatrix` that takes a 2D grid of integers as input and returns an integer representing the shortest path in the matrix.

2. **Variable Initialization - Matrix Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line initializes two variables, `m` and `n`, which store the number of rows and columns of the input grid, respectively.

3. **Edge Case Check**
	```cpp
	    if(grid[0][0] == 1) return -1;
	```
	If the starting point (top-left corner) is blocked (value is 1), the function immediately returns -1, indicating that there is no valid path.

4. **Queue Initialization**
	```cpp
	    queue<pair<int, int>> q;
	```
	A queue `q` is initialized to store pairs of coordinates representing the current position during the BFS traversal.

5. **Direction Setup**
	```cpp
	    vector<vector<int>> dir = {{0, 1}, {0,-1}, {1, 0}, {1,1}, {1,-1}, {-1,0}, {-1,1}, {-1,-1}};
	```
	This vector `dir` stores the possible directions for movement from each cell, including all 8 neighboring cells (up, down, left, right, and diagonals).

6. **Start BFS - Push Initial Position**
	```cpp
	    q.push(make_pair(0,0));
	```
	The starting position (0,0) is pushed into the queue to begin the BFS traversal.

7. **Mark Starting Position**
	```cpp
	    grid[0][0] = 1;
	```
	The starting position (0,0) is marked as visited by setting its value to 1, indicating that it has been processed.

8. **BFS Loop - Process Queue**
	```cpp
	    while(!q.empty()) {
	```
	The while loop starts the BFS process, which continues as long as there are positions in the queue to process.

9. **Queue - Retrieve Front Element**
	```cpp
	        auto p = q.front();
	```
	The front element of the queue is retrieved and stored in `p`, representing the current position.

10. **Variable Assignment - Coordinates**
	```cpp
	        int x = p.first, y = p.second;
	```
	The coordinates `x` and `y` are extracted from the pair `p`, representing the current cell's position.

11. **Check End Condition**
	```cpp
	        if(x == m -1 && y == n -1) return grid[x][y];
	```
	If the current position is the bottom-right corner, the function returns the value of `grid[x][y]`, which represents the length of the shortest path.

12. **Direction Iteration**
	```cpp
	        for(auto d: dir) {
	```
	This for loop iterates through each direction in `dir` to check the neighboring cells of the current position.

13. **Neighbor Calculation**
	```cpp
	            int i = x + d[0], j = y + d[1];
	```
	The new coordinates `i` and `j` are calculated based on the current position (`x`, `y`) and the direction `d`.

14. **Bounds and Validity Check**
	```cpp
	            if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 0)
	```
	This condition checks if the new coordinates are within bounds and whether the cell is unvisited (value 0). If not, it skips to the next direction.

15. **Skip Invalid Cells**
	```cpp
	                continue;
	```
	If the neighboring cell is out of bounds or already visited, the loop continues to the next direction.

16. **Mark Neighbor as Visited**
	```cpp
	            grid[i][j] = grid[x][y] + 1;
	```
	The neighboring cell is marked as visited by assigning it a value that represents the distance from the starting position.

17. **Push Neighbor to Queue**
	```cpp
	            q.push(make_pair(i, j));
	```
	The valid neighboring cell is pushed to the queue for further processing.

18. **Pop Processed Position**
	```cpp
	        q.pop();
	```
	After processing all directions for the current position, it is removed from the queue.

19. **Return -1 (No Path Found)**
	```cpp
	    return -1;
	```
	If no path is found to the bottom-right corner, the function returns -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The BFS explores each cell at most once, resulting in a time complexity of O(n^2) for an n x n grid.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the need to store the grid and the queue used in BFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-path-in-binary-matrix/description/)

---
{{< youtube U3VJjmvRVLY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
