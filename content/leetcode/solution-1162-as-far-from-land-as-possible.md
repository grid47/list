
+++
authors = ["grid47"]
title = "Leetcode 1162: As Far from Land as Possible"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1162: As Far from Land as Possible in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fjxb1hQfrZk"
youtube_upload_date="2023-02-10"
youtube_thumbnail="https://i.ytimg.com/vi/fjxb1hQfrZk/maxresdefault.jpg"
comments = true
+++



---
Given a square grid of size n x n containing only 0s (water) and 1s (land), find the water cell that is farthest from any land cell based on Manhattan distance, and return that distance. If the grid has no water or no land, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 2D grid of size n x n where each cell contains either 0 (water) or 1 (land).
- **Example:** `grid = [[1,0,1],[0,0,0],[1,0,1]]`
- **Constraints:**
	- n == grid.length
	- n == grid[i].length
	- 1 <= n <= 100
	- grid[i][j] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the maximum Manhattan distance from a water cell to the nearest land cell. Return -1 if no valid configuration exists.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the maximum Manhattan distance of a water cell to the nearest land cell.

- Initialize a queue to store land cells' coordinates.
- Mark water cells with -1 to differentiate unvisited cells.
- Perform a breadth-first search (BFS) starting from all land cells simultaneously.
- Update water cells with their distance to the nearest land cell.
- Keep track of the maximum distance during the BFS.
{{< dots >}}
### Problem Assumptions ✅
- Grid dimensions are always square.
- Input grid contains at least one water or one land cell.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1,0,0],[0,0,0],[0,0,0]]`  \
  **Explanation:** The cell (2, 2) is the farthest from all land cells with a distance of 4.

- **Input:** `grid = [[1,1,1],[1,1,1],[1,1,1]]`  \
  **Explanation:** No water exists, so the output is -1.

{{< dots >}}
## Approach 🚀
Use BFS starting from all land cells to calculate the nearest distance for water cells.

### Initial Thoughts 💭
- Each water cell's distance depends on its proximity to land cells.
- Simultaneous BFS from all land cells ensures optimal computation.
- Iterate through the grid to initialize BFS queue with all land cells.
- Use BFS to propagate distances to water cells.
{{< dots >}}
### Edge Cases 🌐
- grid = [] -> Return -1
- grid = [[0]*100 for _ in range(100)] -> Ensure no timeouts.
- grid with all 1s -> Return -1
- grid with all 0s -> Return -1
- Ensure BFS handles edge cells correctly.
{{< dots >}}
## Code 💻
```cpp
int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 1) {
            q.push(make_pair(i, j));
            grid[i][j] = 0;
        } else grid[i][j] = -1;

    if(q.empty() || q.size() == n * n) return -1;
    
    int dir[] = {0, 1, 0, -1, 0};
    int mx = 1;
    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = tmp.first + dir[i], y = tmp.second + dir[i + 1];
            if(x < 0 || y < 0 || x == n || y == n || grid[x][y] != -1)
                continue;
            cout << grid[tmp.first][tmp.second] << " ";
            grid[x][y] = grid[tmp.first][tmp.second] + 1;
            q.push(make_pair(x, y));
            mx = max(mx, grid[x][y]);
        }
    }
    return mx;
}
```

This code finds the maximum distance from any land cell (represented by 1) to the nearest water cell (represented by 0) in a grid. It uses a breadth-first search (BFS) approach to compute the distance from all land cells to the nearest water cell and returns the largest distance found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxDistance(vector<vector<int>>& grid) {
	```
	Define the function maxDistance that takes a 2D grid as input, where 1 represents land and 0 represents water.

2. **Variable Initialization**
	```cpp
	    int n = grid.size();
	```
	Initialize the variable n to store the size of the grid, i.e., the number of rows (and columns, since the grid is square).

3. **Queue Initialization**
	```cpp
	    queue<pair<int, int>> q;
	```
	Initialize a queue of pairs to perform BFS. Each pair will represent a cell in the grid (row and column indices).

4. **Grid Initialization**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Loop through each row of the grid.

5. **Grid Traversal**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Loop through each column of the grid.

6. **Land Cell Identification**
	```cpp
	        if(grid[i][j] == 1) {
	```
	Check if the current cell is land (represented by 1).

7. **Queue Enqueue**
	```cpp
	            q.push(make_pair(i, j));
	```
	Push the coordinates of the land cell onto the queue for BFS.

8. **Grid Update**
	```cpp
	            grid[i][j] = 0;
	```
	Set the land cell to 0, marking it as visited.

9. **Water Cell Initialization**
	```cpp
	        } else grid[i][j] = -1;
	```
	Set all water cells (represented by 0) to -1, indicating they are unvisited.

10. **Empty Queue Check**
	```cpp
	    if(q.empty() || q.size() == n * n) return -1;
	```
	If the queue is empty or if the grid is already fully land (no water cells), return -1.

11. **Direction Array Initialization**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Initialize an array representing the four possible directions (right, down, left, up) for BFS traversal.

12. **Max Distance Initialization**
	```cpp
	    int mx = 1;
	```
	Initialize a variable mx to store the maximum distance encountered during BFS.

13. **BFS Traversal**
	```cpp
	    while(!q.empty()) {
	```
	Begin a while loop that continues until the queue is empty, representing the BFS process.

14. **Queue Dequeue**
	```cpp
	        pair<int, int> tmp = q.front();
	```
	Dequeue the front element of the queue to start the BFS from the current land cell.

15. **Queue Pop**
	```cpp
	        q.pop();
	```
	Remove the processed cell from the queue.

16. **Direction Loop**
	```cpp
	        for(int i = 0; i < 4; i++) {
	```
	Loop over the four possible directions (up, down, left, right) to explore neighboring cells.

17. **Neighbor Calculation**
	```cpp
	            int x = tmp.first + dir[i], y = tmp.second + dir[i + 1];
	```
	Calculate the new coordinates (x, y) by adding the respective direction offsets.

18. **Boundary Check**
	```cpp
	            if(x < 0 || y < 0 || x == n || y == n || grid[x][y] != -1)
	```
	Check if the new coordinates are out of bounds or if the neighboring cell is already visited or not water.

19. **Skip Invalid Cell**
	```cpp
	                continue;
	```
	Skip the current neighbor if it's out of bounds or already processed.

20. **Distance Output**
	```cpp
	            cout << grid[tmp.first][tmp.second] << " ";
	```
	Output the distance of the current cell (for debugging or visualization purposes).

21. **Grid Update (Distance Increment)**
	```cpp
	            grid[x][y] = grid[tmp.first][tmp.second] + 1;
	```
	Update the neighboring cell's distance to be the current cell's distance + 1.

22. **Queue Enqueue (Neighbor)**
	```cpp
	            q.push(make_pair(x, y));
	```
	Push the updated neighboring cell to the queue for further processing.

23. **Max Distance Update**
	```cpp
	            mx = max(mx, grid[x][y]);
	```
	Update the maximum distance encountered so far.

24. **Return Result**
	```cpp
	    return mx;
	```
	Return the maximum distance found from any land cell to the nearest water cell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2) when grid contains mixed cells.
- **Average Case:** O(n^2) due to full traversal during BFS.
- **Worst Case:** O(n^2) for fully mixed grids.

Each cell is visited once during BFS.

### Space Complexity 💾
- **Best Case:** O(1) for grids with uniform values.
- **Worst Case:** O(n^2) for BFS queue.

Queue size depends on the number of cells in the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/as-far-from-land-as-possible/description/)

---
{{< youtube fjxb1hQfrZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
