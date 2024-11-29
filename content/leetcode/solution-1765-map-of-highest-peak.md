
+++
authors = ["grid47"]
title = "Leetcode 1765: Map of Highest Peak"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1765: Map of Highest Peak in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0BNHd7a_ozc"
youtube_upload_date="2021-02-20"
youtube_thumbnail="https://i.ytimg.com/vi/0BNHd7a_ozc/maxresdefault.jpg"
comments = true
+++



---
Given a 2D grid where each cell is either water (1) or land (0), assign heights to the land cells such that the height difference between adjacent cells is at most 1. The goal is to maximize the height values of land cells while ensuring the height of water cells is 0. Return the grid with assigned heights.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a matrix where each element is either 0 (land) or 1 (water).
- **Example:** `isWater = [[0,0,1],[1,0,0],[0,0,0]]`
- **Constraints:**
	- m == isWater.length
	- n == isWater[i].length
	- 1 <= m, n <= 1000
	- isWater[i][j] is 0 or 1
	- There is at least one water cell

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a matrix of the same size where each land cell has a height and the height difference between adjacent cells is at most 1.
- **Example:** `Output: [[1,1,0],[0,1,1],[1,2,2]]`
- **Constraints:**
	- Each cell's height is non-negative
	- The height difference between adjacent cells is at most 1

{{< dots >}}
### Core Logic 🔍
**Goal:** To assign the maximum possible height to each land cell while ensuring the height difference between adjacent cells is at most 1.

- Initialize a queue with the positions of all water cells, and set their heights to 0.
- Perform a breadth-first search (BFS) from each water cell to assign heights to adjacent land cells.
- Ensure that the height difference rule is satisfied while maximizing the heights.
{{< dots >}}
### Problem Assumptions ✅
- It is guaranteed that there is at least one water cell in the matrix.
{{< dots >}}
## Examples 🧩
- **Input:** `isWater = [[0,1],[0,0]]`  \
  **Explanation:** In this case, the water cell has height 0, and the adjacent land cell is assigned the maximum possible height of 1. The next land cell is assigned height 2, adhering to the height difference rule.

- **Input:** `isWater = [[0,0,1],[1,0,0],[0,0,0]]`  \
  **Explanation:** The water cells are at positions (0,2) and (1,0). Heights are assigned starting from the water cells, ensuring that the maximum height is 2 for the land cells.

{{< dots >}}
## Approach 🚀
This problem requires assigning heights to land cells while respecting the height difference rule. A breadth-first search (BFS) is suitable for this, as it ensures we propagate heights from water cells to adjacent land cells.

### Initial Thoughts 💭
- The BFS approach will allow us to propagate heights efficiently from the water cells.
- We need to ensure that the maximum possible height is assigned to each land cell while keeping the height differences between adjacent cells at most 1.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there will be at least one water cell, so empty inputs do not need to be handled.
- The algorithm should be efficient enough to handle matrices up to the size of 1000x1000.
- Ensure that water cells are correctly assigned height 0.
- The matrix will always contain at least one water cell, and its size will not exceed 1000x1000.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int m = isWater.size(), n = isWater[0].size();
    
    vector<vector<int>> ans(m, vector<int>(n, 0)), vis(m, vector<int>(n, 0));
    
    queue<vector<int>> q;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(isWater[i][j] == 1)
            q.push({i, j});
    
    int rot[] = {0, 1, 0, -1, 0};
    
    int cur = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto it = q.front();
            q.pop();
            if(vis[it[0]][it[1]]) continue;
            vis[it[0]][it[1]] = 1;
            
            ans[it[0]][it[1]] = cur;
            
            for(int i = 0; i < 4; i++) {
                int x = it[0] + rot[i], y = it[1] + rot[i + 1];
                if(x < 0 || y < 0 || x == m || y == n || vis[x][y]) continue;
                q.push({x, y});
            }
        }
        cur++;
    }
    return ans;
}
```

This is the full code for finding the highest peak in a grid of water and land cells, where water cells are marked as 1, and land cells as 0. The algorithm uses a breadth-first search (BFS) approach to calculate the elevation for each cell in the grid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
	```
	The function starts by declaring a 2D vector `highestPeak` which takes the `isWater` grid as input.

2. **Variable Initialization**
	```cpp
	    int m = isWater.size(), n = isWater[0].size();
	```
	Here, the number of rows (`m`) and columns (`n`) of the `isWater` grid are stored.

3. **2D Grid Initialization**
	```cpp
	    
	```
	Initializing variables for storing the result (`ans`) and a visited status grid (`vis`).

4. **Grid Initialization**
	```cpp
	    vector<vector<int>> ans(m, vector<int>(n, 0)), vis(m, vector<int>(n, 0));
	```
	Two 2D grids `ans` and `vis` are initialized. `ans` stores the highest peak at each grid position, and `vis` keeps track of whether a cell has been visited in BFS.

5. **Queue Initialization**
	```cpp
	    queue<vector<int>> q;
	```
	A queue `q` is initialized for the breadth-first search (BFS) traversal.

6. **Loop Initialization**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This loop iterates over each row of the grid.

7. **Loop Initialization**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This loop iterates over each column of the grid.

8. **Conditional Check**
	```cpp
	        if(isWater[i][j] == 1)
	```
	This condition checks if the current cell is water (value 1). If true, it adds the cell to the queue for BFS.

9. **Queue Operation**
	```cpp
	            q.push({i, j});
	```
	If the cell is water, the current coordinates are added to the queue.

10. **Array Initialization**
	```cpp
	    int rot[] = {0, 1, 0, -1, 0};
	```
	This array represents the possible four directions (right, down, left, up) for BFS traversal.

11. **BFS Loop**
	```cpp
	    int cur = 0;
	```
	Set the current BFS level to 0.

12. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop, which continues until the queue is empty.

13. **Queue Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Get the size of the queue for the current level of BFS.

14. **BFS Level Loop**
	```cpp
	        while(sz--) {
	```
	Process each element in the current BFS level.

15. **Queue Dequeue**
	```cpp
	            auto it = q.front();
	```
	Extract the first element of the queue to process.

16. **Queue Dequeue**
	```cpp
	            q.pop();
	```
	Remove the processed element from the queue.

17. **Visited Check**
	```cpp
	            if(vis[it[0]][it[1]]) continue;
	```
	If the current cell has already been visited, skip it.

18. **Visited Mark**
	```cpp
	            vis[it[0]][it[1]] = 1;
	```
	Mark the current cell as visited.

19. **Answer Assignment**
	```cpp
	            ans[it[0]][it[1]] = cur;
	```
	Set the current elevation for the cell.

20. **Direction Check**
	```cpp
	            for(int i = 0; i < 4; i++) {
	```
	Loop through the four possible directions.

21. **Direction Update**
	```cpp
	                int x = it[0] + rot[i], y = it[1] + rot[i + 1];
	```
	Calculate the next cell's coordinates based on the direction.

22. **Boundary Check**
	```cpp
	                if(x < 0 || y < 0 || x == m || y == n || vis[x][y]) continue;
	```
	Ensure the next cell is within bounds and has not been visited.

23. **Queue Operation**
	```cpp
	                q.push({x, y});
	```
	Push the next cell into the queue for BFS processing.

24. **Level Increment**
	```cpp
	        cur++;
	```
	Increment the BFS level after processing one level.

25. **Return Result**
	```cpp
	    return ans;
	```
	Return the final `ans` grid containing the highest peak elevations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The BFS processes each cell in the matrix once.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

We use two matrices (the result matrix and the visited matrix), each of size m x n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/map-of-highest-peak/description/)

---
{{< youtube 0BNHd7a_ozc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
