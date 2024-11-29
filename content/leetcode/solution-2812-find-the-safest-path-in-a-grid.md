
+++
authors = ["grid47"]
title = "Leetcode 2812: Find the Safest Path in a Grid"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2812: Find the Safest Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-5mQcNiVWTs"
youtube_upload_date="2024-05-15"
youtube_thumbnail="https://i.ytimg.com/vi/-5mQcNiVWTs/maxresdefault.jpg"
comments = true
+++



---
You are given a square grid of size n x n, where each cell contains either a thief (represented by 1) or is empty (represented by 0). You start at the top-left corner of the grid and must find the maximum safeness factor for a path to the bottom-right corner. The safeness factor is defined as the minimum Manhattan distance from any cell in the path to the nearest thief.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a grid, where each cell is either 0 or 1. A 0 indicates an empty cell, and a 1 indicates a cell with a thief.
- **Example:** `grid = [[0, 0, 1], [0, 0, 0], [0, 0, 0]]`
- **Constraints:**
	- 1 <= n <= 400
	- grid[i][j] is either 0 or 1
	- There is at least one thief in the grid.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum safeness factor of all paths leading to cell (n-1, n-1).
- **Example:** `Output: 2`
- **Constraints:**
	- The safeness factor is an integer value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum safeness factor for any path to the bottom-right corner of the grid.

- Initialize a queue and push the positions of all thieves in the grid.
- Use a breadth-first search (BFS) to calculate the minimum distance from each cell to the nearest thief.
- Use a priority queue to find the path from the top-left to the bottom-right corner while maximizing the safeness factor.
- Return the maximum safeness factor from the top of the priority queue.
{{< dots >}}
### Problem Assumptions ✅
- The grid is square, and at least one thief is present.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1`  \
  **Explanation:** All paths from (0, 0) to (n-1, n-1) go through thieves, resulting in a safeness factor of 0.

- **Input:** `Example 2`  \
  **Explanation:** The safeness factor is calculated as the minimum Manhattan distance from the path to the nearest thief.

{{< dots >}}
## Approach 🚀
The approach involves calculating the Manhattan distance to the nearest thief for each cell, followed by a priority-based search to find the maximum safeness factor along a valid path.

### Initial Thoughts 💭
- A breadth-first search is ideal for calculating the minimum distances to thieves.
- We can use a priority queue to maximize the safeness factor while exploring possible paths.
- The key to solving this problem is efficiently calculating distances to thieves and then exploring valid paths using these distances.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs as at least one thief is guaranteed in the grid.
- Handle the scenario where the grid is large (up to 400x400) efficiently using BFS and priority queue.
- Consider edge cases where the thief is at the start or end of the path.
- Ensure the solution works within the time limits for grids as large as 400x400.
{{< dots >}}
## Code 💻
```cpp
int maximumSafenessFactor(vector<vector<int>>& g) {
queue<array<int, 2>> q;
int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        if (g[i][j])
            q.push({i, j});
while (!q.empty()) {
    auto [i, j] = q.front(); q.pop();
    for (int d = 0; d < 4; ++d) {
        int x = i + dir[d], y = j + dir[d + 1];
        if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
            g[x][y] = g[i][j] + 1;
            q.push({x, y});
        }
    }
}
priority_queue<array<int, 3>> pq;
pq.push({g[0][0], 0, 0});
while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
    auto [sf, i, j] = pq.top(); pq.pop();
    for (int d = 0; d < 4; ++d) {
        int x = i + dir[d], y = j + dir[d + 1];
        if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
            pq.push({min(sf, g[x][y]), x, y});
            g[x][y] *= -1; 
        }
    }
}
return pq.top()[0] - 1;
}
```

This function calculates the maximum safeness factor in a grid, where each cell is either a safe (1) or unsafe (0) zone. It first computes distances from safe zones using breadth-first search (BFS) and then performs a priority queue-based search to determine the maximum safeness factor by considering the minimum safeness factor encountered along paths from the starting cell.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumSafenessFactor(vector<vector<int>>& g) {
	```
	Defines the 'maximumSafenessFactor' function, which takes a 2D vector 'g' representing a grid of safe (1) and unsafe (0) zones and returns an integer representing the maximum safeness factor.

2. **Queue Initialization**
	```cpp
	queue<array<int, 2>> q;
	```
	Initializes a queue 'q' that will store coordinates of the cells in the grid to process them in the BFS.

3. **Direction Setup**
	```cpp
	int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
	```
	Defines a direction array 'dir' for moving up, right, down, and left on the grid, and stores the grid size 'n'.

4. **Grid Traversal Setup**
	```cpp
	for (int i = 0; i < n; ++i)
	```
	Starts a loop over the rows of the grid.

5. **Grid Traversal Setup**
	```cpp
	    for (int j = 0; j < n; ++j)
	```
	Starts a nested loop over the columns of the grid.

6. **Safe Zone Detection**
	```cpp
	        if (g[i][j])
	```
	Checks if the current cell is a safe zone (value 1).

7. **Queue Push**
	```cpp
	            q.push({i, j});
	```
	If the current cell is a safe zone, its coordinates are added to the queue for processing in the BFS.

8. **BFS Loop**
	```cpp
	while (!q.empty()) {
	```
	Starts a while loop that processes the queue until it is empty, performing the BFS traversal of the grid.

9. **Queue Pop**
	```cpp
	    auto [i, j] = q.front(); q.pop();
	```
	Pops the front element from the queue, representing the current cell to process.

10. **Direction Loop**
	```cpp
	    for (int d = 0; d < 4; ++d) {
	```
	Starts a loop to check the four possible directions (up, right, down, left) from the current cell.

11. **Next Cell Calculation**
	```cpp
	        int x = i + dir[d], y = j + dir[d + 1];
	```
	Calculates the coordinates of the adjacent cell in the current direction.

12. **Boundary Check**
	```cpp
	        if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
	```
	Checks if the adjacent cell is within bounds and is an unsafe zone (value 0).

13. **Distance Update**
	```cpp
	            g[x][y] = g[i][j] + 1;
	```
	Updates the distance for the adjacent cell to be one more than the current cell's distance.

14. **Queue Push**
	```cpp
	            q.push({x, y});
	```
	Pushes the coordinates of the adjacent cell onto the queue to be processed next.

15. **Priority Queue Initialization**
	```cpp
	priority_queue<array<int, 3>> pq;
	```
	Initializes a priority queue 'pq' to store cells along with their safeness factors for further processing.

16. **Start Priority Queue Push**
	```cpp
	pq.push({g[0][0], 0, 0});
	```
	Pushes the starting cell (top-left corner) along with its safeness factor to the priority queue.

17. **Priority Queue Processing**
	```cpp
	while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
	```
	Starts a while loop that processes the priority queue until the destination cell (bottom-right corner) is reached.

18. **Priority Queue Pop**
	```cpp
	    auto [sf, i, j] = pq.top(); pq.pop();
	```
	Pops the top element from the priority queue, representing the current cell to process.

19. **Direction Loop**
	```cpp
	    for (int d = 0; d < 4; ++d) {
	```
	Starts a loop to check the four possible directions from the current cell.

20. **Next Cell Calculation**
	```cpp
	        int x = i + dir[d], y = j + dir[d + 1];
	```
	Calculates the coordinates of the adjacent cell in the current direction.

21. **Cell Processing Check**
	```cpp
	        if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
	```
	Checks if the adjacent cell is within bounds and has a valid safeness factor (greater than 0).

22. **Priority Queue Push**
	```cpp
	            pq.push({min(sf, g[x][y]), x, y});
	```
	Pushes the adjacent cell and the minimum safeness factor encountered along the path to the priority queue.

23. **Mark Processed Cell**
	```cpp
	            g[x][y] *= -1;
	```
	Marks the adjacent cell as processed by multiplying its value by -1.

24. **Return Maximum Safeness Factor**
	```cpp
	return pq.top()[0] - 1;
	```
	Returns the maximum safeness factor by subtracting 1 from the top element in the priority queue, which represents the final result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2) for BFS and pathfinding.
- **Average Case:** O(n^2 log n) due to the priority queue.
- **Worst Case:** O(n^2 log n) for large grids.

The worst case is when the grid is fully explored and all cells are processed using the BFS and priority queue.

### Space Complexity 💾
- **Best Case:** O(n) for small grids.
- **Worst Case:** O(n^2) for storing the grid and BFS queue.

The space complexity depends on the grid size and the storage required for BFS and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

---
{{< youtube -5mQcNiVWTs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
