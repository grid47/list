
+++
authors = ["grid47"]
title = "Leetcode 1391: Check if There is a Valid Path in a Grid"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1391: Check if There is a Valid Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an m x n grid where each cell represents a street. The streets have different connections between neighboring cells. Starting from the top-left corner of the grid, you need to find if there exists a valid path to the bottom-right corner, following the direction of the streets.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an m x n grid where grid[i][j] is an integer between 1 and 6 that represents the type of street connecting cells.
- **Example:** `For grid = [[1,2,3],[6,5,4]], the output is true.`
- **Constraints:**
	- 1 <= m, n <= 300
	- 1 <= grid[i][j] <= 6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if there is a valid path from the top-left corner to the bottom-right corner, otherwise return false.
- **Example:** `For grid = [[1,2,3],[6,5,4]], the output is true.`
- **Constraints:**
	- Return false if no valid path exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if there is a valid path from the top-left to the bottom-right corner of the grid by moving only through the valid streets.

- 1. Initialize a queue to perform BFS starting from (0, 0).
- 2. For each cell, check its possible directions based on the street type.
- 3. If a direction leads to an unvisited cell and the connection is valid, add it to the queue.
- 4. Continue until the queue is empty or the bottom-right corner is reached.
- 5. If you reach (m-1, n-1), return true. If not, return false.
{{< dots >}}
### Problem Assumptions ✅
- You can assume that the input grid will always be valid.
{{< dots >}}
## Examples 🧩
- **Input:** `For grid = [[1,2,3],[6,5,4]], starting from (0, 0) leads to (1, 2), which connects to (1, 1), and from there, you can reach the bottom-right corner.`  \
  **Explanation:** Each cell has specific street types that define its possible connections. By carefully following these, you can determine if a path exists.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a breadth-first search (BFS) to explore the grid and check if a valid path exists between the top-left and bottom-right corners.

### Initial Thoughts 💭
- The grid represents a directional graph where cells have specific connections.
- BFS is a suitable approach as it ensures we explore all possible valid paths in an orderly manner.
{{< dots >}}
### Edge Cases 🌐
- The grid will never be empty.
- The BFS approach is designed to handle grids up to size 300x300.
- If the grid is filled with streets that do not connect in a valid way, the function should return false.
- Make sure that all the directions are properly checked for valid connections before proceeding.
{{< dots >}}
## Code 💻
```cpp

vector<vector<vector<int>>> dir{    { { 0, 1}, { 0, -1} },
                   { { 1, 0}, {-1,  0} },
                   { { 0,-1}, { 1,  0} },
                   { { 0, 1}, { 1,  0} },
                   { {0, -1}, {-1,  0} },
                   { { 0, 1}, {-1,  0} },
              };

bool hasValidPath(vector<vector<int>>& grid) {
    
    int m = grid.size(), n = grid[0].size();
    
    vector<vector<bool>> visited(m, vector(n, false));
    
    queue<vector<int>> q;
    q.push(vector<int>{0, 0});
    visited[0][0] = true;
    
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; i++) {
            vector<int> cur = q.front();
            q.pop();
            
            if(cur[0] == m - 1 && cur[1] == n - 1) return true;
            
            int num = grid[cur[0]][cur[1]];
            
            for(vector<int> go : dir[num - 1]) {
                int x = cur[0] + go[0], y = cur[1] + go[1];
                
                if (x <  0 || y <  0 ||
                    x >= m || y >= n || visited[x][y])
                    continue;
                
                int ret = grid[x][y];
                for(vector<int> rev : dir[ret - 1]) {
                    if((cur[0] == x + rev[0] && cur[1] == y + rev[1]) ||
                       (cur[1] == x + rev[0] && cur[0] == y + rev[1])) {
                        q.push(vector<int>{x, y});
                        visited[x][y] = true;
                    }
                }   
            }
        }
        
    }
    return false;
}
```

This is the solution for checking if a valid path exists in a grid using a breadth-first search approach. The grid is traversed based on specific direction pairs for each grid cell value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Direction Setup**
	```cpp
	vector<vector<vector<int>>> dir{    { { 0, 1}, { 0, -1} },
	```
	This defines the direction pairs for each type of grid cell. The direction pairs represent possible moves in the grid (right, left, down, up).

2. **Direction Setup**
	```cpp
	                   { { 1, 0}, {-1,  0} },
	```
	The next direction set represents down and up movements, corresponding to the grid's vertical direction.

3. **Direction Setup**
	```cpp
	                   { { 0,-1}, { 1,  0} },
	```
	This direction pair represents left and down movements.

4. **Direction Setup**
	```cpp
	                   { { 0, 1}, { 1,  0} },
	```
	Another set of directions: right and down.

5. **Direction Setup**
	```cpp
	                   { {0, -1}, {-1,  0} },
	```
	Direction pairs for left and up movements.

6. **Direction Setup**
	```cpp
	                   { { 0, 1}, {-1,  0} },
	```
	A direction pair for right and up movements.

7. **Direction Setup**
	```cpp
	              };
	```
	End of direction setup.

8. **Variable Initialization**
	```cpp
	bool hasValidPath(vector<vector<int>>& grid) {
	```
	Starting the function definition, taking a grid as input.

9. **Grid Size**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	We determine the size of the grid (rows `m` and columns `n`).

10. **Variable Initialization**
	```cpp
	    
	```
	Preparing variables for the queue and visited grid.

11. **Array Initialization**
	```cpp
	    vector<vector<bool>> visited(m, vector(n, false));
	```
	A `visited` array is initialized to keep track of the visited cells during traversal.

12. **Queue Operation**
	```cpp
	    queue<vector<int>> q;
	```
	Initializing the BFS queue to store the current cell positions.

13. **Queue Operation**
	```cpp
	    q.push(vector<int>{0, 0});
	```
	We add the starting cell (0, 0) to the queue.

14. **Variable Assignment**
	```cpp
	    visited[0][0] = true;
	```
	Marking the starting cell as visited.

15. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop while the queue is not empty.

16. **Queue Operation**
	```cpp
	        int sz = q.size();
	```
	Get the current size of the queue (number of elements to process in this iteration).

17. **For Loop**
	```cpp
	        for(int i = 0; i < sz; i++) {
	```
	Loop through each element in the queue.

18. **Queue Operation**
	```cpp
	            vector<int> cur = q.front();
	```
	Get the current cell from the queue.

19. **Queue Operation**
	```cpp
	            q.pop();
	```
	Remove the current cell from the queue.

20. **Condition Check**
	```cpp
	            
	```
	Checking the position of the current cell.

21. **Exit Condition**
	```cpp
	            if(cur[0] == m - 1 && cur[1] == n - 1) return true;
	```
	If the current cell is at the bottom-right corner, return true.

22. **Cell Value**
	```cpp
	            int num = grid[cur[0]][cur[1]];
	```
	Retrieve the value of the current cell.

23. **Direction Check**
	```cpp
	            for(vector<int> go : dir[num - 1]) {
	```
	Loop through possible directions based on the current cell's value.

24. **Boundary Check**
	```cpp
	                int x = cur[0] + go[0], y = cur[1] + go[1];
	```
	Calculate the new position based on the direction.

25. **Boundary Check**
	```cpp
	                if (x <  0 || y <  0 || x >= m || y >= n || visited[x][y]) continue;
	```
	Check if the new position is within bounds and hasn't been visited.

26. **Direction Validation**
	```cpp
	                int ret = grid[x][y];
	```
	Get the value of the cell at the new position.

27. **Direction Validation**
	```cpp
	                for(vector<int> rev : dir[ret - 1]) {
	```
	Check for a valid reverse direction.

28. **Push to Queue**
	```cpp
	                    if((cur[0] == x + rev[0] && cur[1] == y + rev[1]) || (cur[1] == x + rev[0] && cur[0] == y + rev[1])) {
	```
	If the reverse direction matches the previous cell's direction, add the new cell to the queue.

29. **Push to Queue**
	```cpp
	                        q.push(vector<int>{x, y});
	```
	Add the new cell to the queue.

30. **Visited Update**
	```cpp
	                        visited[x][y] = true;
	```
	Mark the new cell as visited.

31. **Final Return**
	```cpp
	        return false;
	```
	If no valid path is found, return false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) where m and n are the number of rows and columns in the grid, respectively.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the BFS queue and visited cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
