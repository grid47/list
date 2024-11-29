
+++
authors = ["grid47"]
title = "Leetcode 542: 01 Matrix"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 542: 01 Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp"
youtube = "1xuLfxgT7yo"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1xuLfxgT7yo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp" 
    alt="A matrix where cells of 1s and 0s are arranged, with the shortest distance for 1s to 0s glowing softly."
    caption="Solution to LeetCode 542: 01 Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an m x n binary matrix, return the distance of the nearest 0 for each cell. The distance between two adjacent cells is 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a binary matrix of size m x n where each cell is either 0 or 1.
- **Example:** `Input: mat = [[1,1,1],[1,0,1],[1,1,1]]`
- **Constraints:**
	- 1 <= m, n <= 10^4
	- 1 <= m * n <= 10^4
	- mat[i][j] is either 0 or 1.
	- There is at least one 0 in mat.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a matrix where each element represents the distance to the nearest 0.
- **Example:** `Output: [[1,1,1],[1,0,1],[1,1,1]]`
- **Constraints:**
	- The output matrix will have the same dimensions as the input matrix.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the nearest 0 for each cell and compute the distance.

- Initialize a queue and add all positions of the zeros in the matrix.
- Start from the zeros and use a breadth-first search (BFS) to propagate the distance to all other cells.
- For each cell, update its distance as the shortest distance from a 0.
{{< dots >}}
### Problem Assumptions ✅
- The matrix is valid and contains at least one 0.
- The matrix can be large, so the solution should be efficient.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: mat = [[1,1,1],[1,0,1],[1,1,1]]`  \
  **Explanation:** The nearest 0 to any 1 in the matrix is found by calculating the shortest path in terms of adjacency. The matrix will be updated with the distances to the nearest 0.

{{< dots >}}
## Approach 🚀
The approach uses a breadth-first search (BFS) to propagate the distances from all zeros simultaneously. Starting from each 0, we explore its neighbors and update the distances accordingly.

### Initial Thoughts 💭
- BFS is a suitable choice for this problem since it guarantees finding the shortest path in an unweighted grid.
- We can initialize a queue with all the zero positions and then explore the matrix layer by layer, updating the distances.
{{< dots >}}
### Edge Cases 🌐
- The matrix will not be empty as per the constraints.
- Ensure that the solution can handle large matrices with up to 10^4 elements efficiently.
- Handle cases where the zero is at the edges or corners of the matrix.
- The matrix must have at least one zero.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<vector<int>> q;
    int m = mat.size(), n = mat[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(mat[i][j] == 0)
        q.push({i, j});
    
    int dis = 0;
    vector<vector<int>> vis;
    vis.resize(m, vector<int>(n, 0));
    int dir[] = {0, 1, 0, -1, 0};
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();                
            if(vis[it[0]][it[1]]) continue;
            mat[it[0]][it[1]] = dis;
            vis[it[0]][it[1]] = 1;

            for(int i = 0; i < 4; i++) {
                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                if(x < 0 || y < 0 || x == m || y == n)
                    continue;
                if(!vis[x][y])
                    q.push({x, y});
            }
        }
        dis++;
    }
    return mat;
}
```

This function uses Breadth First Search (BFS) to update a matrix such that each cell contains the distance to its nearest 0. It performs BFS from all 0 cells, updating distances for all other cells accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	```
	Defines the function `updateMatrix` that takes a matrix of integers `mat` and returns the updated matrix where each cell contains the distance to its nearest zero.

2. **Queue Initialization**
	```cpp
	    queue<vector<int>> q;
	```
	Initializes a queue `q` to store the coordinates of cells that are being processed during BFS.

3. **Matrix Dimensions**
	```cpp
	    int m = mat.size(), n = mat[0].size();
	```
	Gets the number of rows (`m`) and columns (`n`) in the matrix `mat`.

4. **Matrix Traversal**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Begins a loop to traverse through each row of the matrix.

5. **Matrix Traversal**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Begins an inner loop to traverse through each column of the matrix.

6. **Check for Zeros**
	```cpp
	        if(mat[i][j] == 0)
	```
	Checks if the current cell contains a zero. If it does, its coordinates are added to the queue.

7. **Queue Operation**
	```cpp
	        q.push({i, j});
	```
	Pushes the coordinates of the zero cell to the queue for BFS processing.

8. **Distance Initialization**
	```cpp
	    int dis = 0;
	```
	Initializes the distance variable `dis`, which will be used to update the distance of each cell from the nearest zero.

9. **Visited Matrix**
	```cpp
	    vector<vector<int>> vis;
	```
	Declares a 2D vector `vis` to track which cells have been visited during the BFS.

10. **Visited Matrix Size**
	```cpp
	    vis.resize(m, vector<int>(n, 0));
	```
	Resizes the `vis` matrix to the size of the input matrix, initializing all values to 0 (unvisited).

11. **Direction Array**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Declares a direction array `dir` to represent the four possible directions (right, down, left, up) for BFS traversal.

12. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Begins the BFS loop that continues until all cells have been processed.

13. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Gets the current size of the queue, representing the number of cells to process in the current level of BFS.

14. **BFS Inner Loop**
	```cpp
	        while(sz--) {
	```
	Begins an inner loop to process each cell at the current level of BFS.

15. **Queue Operation**
	```cpp
	            auto it = q.front();
	```
	Gets the front element from the queue (coordinates of the cell to process).

16. **Queue Operation**
	```cpp
	            q.pop();
	```
	Removes the front element from the queue after processing it.

17. **Check Visited**
	```cpp
	            if(vis[it[0]][it[1]]) continue;
	```
	Checks if the current cell has already been visited. If it has, it skips the current iteration.

18. **Update Distance**
	```cpp
	            mat[it[0]][it[1]] = dis;
	```
	Updates the distance for the current cell to the value of `dis`.

19. **Mark Visited**
	```cpp
	            vis[it[0]][it[1]] = 1;
	```
	Marks the current cell as visited in the `vis` matrix.

20. **Explore Neighbors**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Begins a loop to explore the four possible directions from the current cell.

21. **Calculate New Coordinates**
	```cpp
	                int x = it[0] + dir[i], y = it[1] + dir[i + 1];
	```
	Calculates the new coordinates (x, y) based on the current direction.

22. **Boundary Check**
	```cpp
	                if(x < 0 || y < 0 || x == m || y == n)
	```
	Checks if the new coordinates are out of bounds of the matrix. If they are, it skips to the next iteration.

23. **Skip Visited Cells**
	```cpp
	                    continue;
	```
	Skips processing the neighbor if it has already been visited.

24. **Queue Operation**
	```cpp
	                if(!vis[x][y])
	```
	Checks if the neighbor has not been visited yet.

25. **Queue Operation**
	```cpp
	                    q.push({x, y});
	```
	Pushes the coordinates of the unvisited neighbor to the queue.

26. **Increment Distance**
	```cpp
	        dis++;
	```
	Increments the distance variable to move to the next level in BFS.

27. **Return Result**
	```cpp
	    return mat;
	```
	Returns the updated matrix containing the shortest distances to the nearest zero for each cell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because each cell is processed once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the storage of the result matrix and the queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/01-matrix/description/)

---
{{< youtube 1xuLfxgT7yo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
