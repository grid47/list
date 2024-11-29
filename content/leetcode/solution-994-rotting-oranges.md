
+++
authors = ["grid47"]
title = "Leetcode 994: Rotting Oranges"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 994: Rotting Oranges in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nAVKrpJ8LUI"
youtube_upload_date="2024-05-09"
youtube_thumbnail="https://i.ytimg.com/vi/nAVKrpJ8LUI/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n grid where each cell can be empty, contain a fresh orange, or a rotten orange. Every minute, any fresh orange that is adjacent to a rotten orange becomes rotten. The task is to determine the minimum number of minutes required for all fresh oranges to rot. If this is not possible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a grid represented by a 2D array, where each element can be 0, 1, or 2.
- **Example:** `grid = [[2,1,1],[1,1,0],[0,1,1]]`
- **Constraints:**
	- 1 <= m, n <= 10
	- grid[i][j] can be 0, 1, or 2.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of minutes required for all fresh oranges to rot. If it's impossible, return -1.
- **Example:** `Output: 4`
- **Constraints:**
	- The grid has at least one cell and at most 100 cells.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum time required to rot all the fresh oranges using breadth-first search (BFS) from the rotten oranges.

- Initialize a queue with all the positions of rotten oranges.
- Perform BFS, and for each rotten orange, check its 4-directional neighbors.
- If a fresh orange is found, make it rotten and add its position to the queue.
- Keep track of the minutes elapsed while processing each level of BFS.
- Return the number of minutes, or -1 if some fresh oranges cannot be rotted.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always contain at least one cell.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[2,1,1],[1,1,0],[0,1,1]]`  \
  **Explanation:** In this example, after 4 minutes all fresh oranges rot. The rotten orange at (0,0) spreads to adjacent cells and eventually rots all the fresh oranges.

{{< dots >}}
## Approach 🚀
This problem can be solved using a breadth-first search (BFS) algorithm to simulate the spreading of the rot from all initially rotten oranges.

### Initial Thoughts 💭
- This problem is a variant of multi-source BFS where the rotten oranges are the sources.
- We will need to perform BFS from each rotten orange, updating the grid as fresh oranges become rotten.
{{< dots >}}
### Edge Cases 🌐
- This problem doesn't have empty inputs since the grid is always provided.
- The grid size is small enough (maximum 10x10) that BFS will work efficiently.
- If the grid contains no fresh oranges, the result is 0.
- The grid size is constrained (maximum 10x10), ensuring that a BFS approach is feasible.
{{< dots >}}
## Code 💻
```cpp
int orangesRotting(vector<vector<int>>& grid) {
    queue<vector<int>> q;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 2) {
            q.push({i, j});
        }
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int t = 0;
    int dir[] = {0, 1, 0, -1, 0};
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();
            if(vis[it[0]][it[1]]) continue;
            vis[it[0]][it[1]] = 1;
            for(int i = 0; i < 4; i++) {
                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                if(x < 0 || y < 0 || x == m || y == n || vis[x][y] || grid[x][y] != 1)
                    continue;
                grid[x][y] = grid[it[0]][it[1]] + 1;
                q.push({x, y});
            }
        }
    }
    int mx = 2;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] > mx) mx = grid[i][j];
        else if(grid[i][j] == 1) return -1;
    return mx - 2;
}
```

This function simulates the rotting of oranges in a grid where 1 represents a fresh orange, 2 represents a rotten orange, and 0 represents an empty space. It uses breadth-first search (BFS) to spread the rot to adjacent fresh oranges and returns the minimum time required to rot all oranges, or -1 if it's impossible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int orangesRotting(vector<vector<int>>& grid) {
	```
	Defines the function `orangesRotting` which takes a 2D vector grid representing the oranges and their states (fresh, rotten, or empty). The goal is to compute the minimum time required to rot all fresh oranges.

2. **Queue Initialization**
	```cpp
	    queue<vector<int>> q;
	```
	Initializes a queue to hold the positions of the rotten oranges, which will be used to perform the BFS.

3. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Gets the dimensions of the grid, where `m` is the number of rows and `n` is the number of columns.

4. **Queue Population - Rotten Oranges**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Loops through each row of the grid.

5. **Queue Population - Rotten Oranges**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Loops through each column of the grid.

6. **Queue Population - Rotten Oranges**
	```cpp
	        if(grid[i][j] == 2) {
	```
	Checks if the current cell contains a rotten orange (represented by 2).

7. **Queue Population - Rotten Oranges**
	```cpp
	            q.push({i, j});
	```
	Adds the position of the rotten orange to the queue.

8. **Visited Array Initialization**
	```cpp
	    vector<vector<int>> vis(m, vector<int>(n, 0));
	```
	Initializes a 2D vector `vis` to track visited positions to avoid revisiting cells during the BFS.

9. **Time Initialization**
	```cpp
	    int t = 0;
	```
	Initializes a time counter `t` to track the time taken for all fresh oranges to rot.

10. **Direction Array Initialization**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Defines an array `dir` representing the four possible directions to move in the grid: up, right, down, and left.

11. **BFS Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Starts a while loop to perform BFS as long as there are rotten oranges in the queue.

12. **BFS - Queue Size**
	```cpp
	        int sz = q.size();
	```
	Gets the current size of the queue, which corresponds to the number of oranges to process at the current time step.

13. **BFS - Processing Each Orange**
	```cpp
	        while(sz--) {
	```
	Processes each rotten orange in the current level of the BFS.

14. **BFS - Dequeue**
	```cpp
	            auto it = q.front();
	```
	Retrieves the position of the current rotten orange from the front of the queue.

15. **BFS - Dequeue**
	```cpp
	            q.pop();
	```
	Removes the processed rotten orange from the queue.

16. **BFS - Visited Check**
	```cpp
	            if(vis[it[0]][it[1]]) continue;
	```
	Checks if the current orange has already been visited. If true, skips further processing.

17. **BFS - Mark Visited**
	```cpp
	            vis[it[0]][it[1]] = 1;
	```
	Marks the current orange as visited.

18. **BFS - Spread the Rot**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Loops through each direction to spread the rot to adjacent oranges.

19. **BFS - Spread the Rot**
	```cpp
	                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
	```
	Calculates the new position (x, y) of the adjacent orange.

20. **BFS - Spread the Rot**
	```cpp
	                if(x < 0 || y < 0 || x == m || y == n || vis[x][y] || grid[x][y] != 1)
	```
	Checks if the new position is out of bounds, already visited, or not a fresh orange (i.e., not 1). If any condition is true, skips further processing.

21. **BFS - Spread the Rot**
	```cpp
	                    continue;
	```
	If any condition is true, continue to the next adjacent orange.

22. **BFS - Update and Queue**
	```cpp
	                grid[x][y] = grid[it[0]][it[1]] + 1;
	```
	Updates the state of the adjacent orange, marking it as rotting (incrementing the value from 1 to 2).

23. **BFS - Update and Queue**
	```cpp
	                q.push({x, y});
	```
	Adds the new rotten orange to the queue.

24. **Max Time Calculation**
	```cpp
	    int mx = 2;
	```
	Initializes `mx` to 2 (since rotten oranges have a value of 2) to keep track of the maximum time required.

25. **Max Time Calculation**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Loops through each row of the grid to calculate the maximum time required for all oranges to rot.

26. **Max Time Calculation**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Loops through each column of the grid.

27. **Max Time Calculation**
	```cpp
	        if(grid[i][j] > mx) mx = grid[i][j];
	```
	Updates the maximum time if a more rotten orange is found.

28. **Max Time Calculation**
	```cpp
	        else if(grid[i][j] == 1) return -1;
	```
	Checks if there are still fresh oranges left. If true, returns -1 to indicate it's impossible to rot all oranges.

29. **Return Result**
	```cpp
	    return mx - 2;
	```
	Returns the time taken to rot all oranges by subtracting 2 (the initial rotten state) from the maximum time.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n) - In the best case, every cell is processed once.
- **Average Case:** O(m * n) - The algorithm will process every cell in the grid.
- **Worst Case:** O(m * n) - All cells need to be visited during the BFS.

The time complexity is linear in terms of the grid size.

### Space Complexity 💾
- **Best Case:** O(m * n) - The space complexity is also linear in terms of the grid size.
- **Worst Case:** O(m * n) - In the worst case, the BFS queue will contain all the cells.

The space complexity is linear as we use extra space for the BFS queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/rotting-oranges/description/)

---
{{< youtube nAVKrpJ8LUI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
