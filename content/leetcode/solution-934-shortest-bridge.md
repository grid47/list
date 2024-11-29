
+++
authors = ["grid47"]
title = "Leetcode 934: Shortest Bridge"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 934: Shortest Bridge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1RZijG2c1CA"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1RZijG2c1CA/maxresdefault.jpg"
comments = true
+++



---
You are given an n x n binary matrix where 1 represents land and 0 represents water. There are exactly two islands in the grid, and you need to connect them by flipping the smallest number of 0's to 1's. An island is a group of 1's that are connected horizontally or vertically. Your task is to find the minimum number of flips required to connect the two islands.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an n x n binary matrix, where each cell is either 0 or 1.
- **Example:** `Input: grid = [[1,0],[0,1]]`
- **Constraints:**
	- 2 <= n <= 100
	- grid[i][j] is either 0 or 1
	- There are exactly two islands in the grid

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest number of 0's that must be flipped to connect the two islands.
- **Example:** `Output: 1`
- **Constraints:**
	- The grid will always contain exactly two islands.

{{< dots >}}
### Core Logic 🔍
**Goal:** To connect the two islands with the minimum number of flips, we first identify one island using depth-first search (DFS), then perform a breadth-first search (BFS) to find the shortest path to the other island by flipping the minimum number of 0's to 1's.

- 1. Use DFS to find the first island and store its coordinates.
- 2. Use BFS from the first island to find the shortest path to the second island, counting the number of 0's encountered along the way.
- 3. Return the number of flips required to connect the two islands.
{{< dots >}}
### Problem Assumptions ✅
- The grid will always contain exactly two islands, so no edge cases with more or fewer islands are possible.
- The grid will not be empty and will always have a size of at least 2x2.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[1,0],[0,1]]`  \
  **Explanation:** In this example, there are two islands represented by 1's at positions (0,1) and (1,0). The minimum number of flips required to connect them is 1, flipping the 0 at position (0,0).

- **Input:** `Input: grid = [[1,0,1],[0,0,0],[1,0,1]]`  \
  **Explanation:** In this example, the two islands are at positions (0,0), (0,2), (2,0), and (2,2). The minimum number of flips required to connect them is 2, flipping the two 0's at positions (1,0) and (1,2).

{{< dots >}}
## Approach 🚀
We solve this problem using depth-first search (DFS) and breadth-first search (BFS). First, we perform DFS to find and mark all the cells of one island, then use BFS to find the shortest path to the second island, flipping the minimum number of 0's along the way.

### Initial Thoughts 💭
- We can use DFS to mark all the cells of one island, then use BFS to find the shortest path to the second island, ensuring we flip the fewest number of 0's.
- This approach effectively reduces the problem to a shortest path search, ensuring an optimal solution.
{{< dots >}}
### Edge Cases 🌐
- There will always be exactly two islands, so no empty inputs are possible.
- The solution should efficiently handle the largest grid sizes (up to 100x100).
- The grid may contain only land (1's) or only water (0's), but there will always be two islands to connect.
- The input grid will always contain exactly two islands, and no more.
{{< dots >}}
## Code 💻
```cpp
int shortestBridge(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    bool flag = false;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if (grid[i][j]) {
                dfs(i, j, q, grid);
                flag = true;
                break;
            }
        }
        if (flag) break;
    }
    
    int step = 0;
    int dir[5] = {0,1,0,-1,0};
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int x = p.first + dir[i], y = p.second + dir[i+1];
                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
                    continue;
                if(grid[x][y] == 1) return step;
                q.push({x, y});
                grid[x][y] = -1;
            }
        }
        step++;
    }
    return -1;
}

void dfs(int x, int y, queue<pair<int, int>> &q, vector<vector<int>> &grid) {
    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
        return;
    q.push(make_pair(x, y));
    grid[x][y] = -1;
    dfs(x + 1, y, q, grid);
    dfs(x - 1, y, q, grid);
    dfs(x, y + 1, q, grid);
    dfs(x, y - 1, q, grid);
}
```

This code solves the problem of finding the shortest bridge between two islands in a grid using a breadth-first search (BFS) algorithm after identifying one island with depth-first search (DFS).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	int shortestBridge(vector<vector<int>>& grid) {
	```
	Start the function that accepts a 2D grid where 1 represents land and 0 represents water.

2. **Queue Setup**
	```cpp
	    queue<pair<int, int>> q;
	```
	Initialize a queue to store the coordinates of the first island's land cells that will be explored.

3. **Flag Setup**
	```cpp
	    bool flag = false;
	```
	Use a flag to indicate whether the first island has been found and DFS has been executed.

4. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Get the dimensions of the grid (number of rows and columns).

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Loop through each row of the grid.

6. **Inner Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Loop through each column of the grid.

7. **Island Detection**
	```cpp
	            if (grid[i][j]) {
	```
	Check if a land cell is found, indicating the start of the first island.

8. **DFS Call**
	```cpp
	                dfs(i, j, q, grid);
	```
	Call the DFS function to explore the first island and fill the queue with its land cells.

9. **Set Flag**
	```cpp
	                flag = true;
	```
	Set the flag to true to mark that the first island has been processed.

10. **Break Outer Loop**
	```cpp
	                break;
	```
	Break the inner loop once the first island is found.

11. **Break Outer Loop**
	```cpp
	        if (flag) break;
	```
	Break the outer loop once the first island is fully processed.

12. **Step Initialization**
	```cpp
	    int step = 0;
	```
	Initialize a variable to count the number of steps to connect the two islands.

13. **Direction Array**
	```cpp
	    int dir[5] = {0,1,0,-1,0};
	```
	Set up an array to represent the four possible movement directions (up, right, down, left).

14. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop to expand from the first island's land cells.

15. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Get the current size of the queue to process all land cells of the island.

16. **BFS Inner Loop**
	```cpp
	        for(int i = 0; i < sz; i++) {
	```
	Loop through all elements in the queue.

17. **Pop Element**
	```cpp
	            pair<int, int> p = q.front();
	```
	Pop the front element from the queue (a land cell).

18. **Queue Pop**
	```cpp
	            q.pop();
	```
	Remove the element from the queue.

19. **Direction Loop**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Loop through the four possible directions to expand from the current cell.

20. **Direction Calculations**
	```cpp
	                int x = p.first + dir[i], y = p.second + dir[i+1];
	```
	Calculate the new coordinates based on the current direction.

21. **Bounds Check**
	```cpp
	                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
	```
	Check if the new coordinates are within bounds and if the cell has already been visited.

22. **Skip Invalid Cells**
	```cpp
	                    continue;
	```
	Skip the current iteration if the cell is out of bounds or already visited.

23. **Island Found**
	```cpp
	                if(grid[x][y] == 1) return step;
	```
	If a land cell of the second island is found, return the current step count as the result.

24. **Queue Push**
	```cpp
	                q.push({x, y});
	```
	Push the new valid cell into the queue for future processing.

25. **Mark Visited**
	```cpp
	                grid[x][y] = -1;
	```
	Mark the current cell as visited by setting its value to -1.

26. **Step Increment**
	```cpp
	        step++;
	```
	Increment the step counter after processing all cells in the current layer.

27. **Return Result**
	```cpp
	    return -1;
	```
	Return -1 if no valid bridge is found (shouldn't happen for valid inputs).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Both DFS and BFS operate in O(n^2) time, where n is the number of rows (or columns) in the grid.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the need to store the grid and the visited cells during the DFS and BFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-bridge/description/)

---
{{< youtube 1RZijG2c1CA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
