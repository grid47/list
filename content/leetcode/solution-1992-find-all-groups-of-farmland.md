
+++
authors = ["grid47"]
title = "Leetcode 1992: Find All Groups of Farmland"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1992: Find All Groups of Farmland in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R2mf-nBCWV4"
youtube_upload_date="2021-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/R2mf-nBCWV4/maxresdefault.jpg"
comments = true
+++



---
You are given an m x n binary matrix representing a piece of land, where '1' denotes farmland and '0' denotes forest. Your task is to identify the coordinates of each rectangular group of contiguous farmland (1's), where each group of farmland is isolated and not adjacent to another group. Return a list of 4-length arrays, where each array represents the top-left and bottom-right coordinates of a rectangular farmland group.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n binary matrix 'land'. Each element in the matrix is either 0 (forest) or 1 (farmland).
- **Example:** `land = [[1, 0, 0], [0, 1, 1], [0, 1, 1]]`
- **Constraints:**
	- 1 <= m, n <= 300
	- land[i][j] is either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a 2D list of arrays, where each array consists of four integers representing the coordinates of the top-left and bottom-right corners of a group of farmland. If no groups of farmland exist, return an empty list.
- **Example:** `Output: [[0, 0, 0, 0], [1, 1, 2, 2]]`
- **Constraints:**
	- The output should be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all the rectangular groups of farmland, starting from each cell that contains a '1', and determine the boundaries of the rectangle.

- Iterate through the matrix and for each '1', explore the connected '1's to determine the rectangular area it covers.
- Mark the visited cells as '0' to avoid counting the same farmland group again.
- Store the top-left and bottom-right coordinates of each farmland group.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix contains only '0's and '1's, representing forest and farmland, respectively.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: land = [[1, 0, 0], [0, 1, 1], [0, 1, 1]]`  \
  **Explanation:** The first group of farmland starts at (0, 0) and ends at (0, 0). The second group of farmland starts at (1, 1) and ends at (2, 2).

- **Input:** `Input: land = [[1, 1], [1, 1]]`  \
  **Explanation:** The only group of farmland starts at (0, 0) and ends at (1, 1).

- **Input:** `Input: land = [[0]]`  \
  **Explanation:** There are no groups of farmland, so the output is an empty list.

{{< dots >}}
## Approach 🚀
We can use depth-first search (DFS) to explore each farmland group and determine its boundaries. Once a group is identified, mark the cells as visited and record the coordinates of the group.

### Initial Thoughts 💭
- The land matrix contains '0's and '1's, and the groups of farmland are isolated and rectangular.
- A DFS or BFS approach would be ideal for exploring each farmland group while marking the visited cells to avoid redundant processing.
{{< dots >}}
### Edge Cases 🌐
- The input matrix will always have at least one element.
- Ensure the algorithm handles large matrices, up to the maximum size of 300x300.
- Handle matrices with no farmland (all '0's) or matrices with all farmland (all '1's).
- No farmland groups are adjacent to each other.
{{< dots >}}
## Code 💻
```cpp
int m, n;
vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    m = land.size(), n = land[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(land[i][j] == 1) {
            vector<int> tmp = {i, j, i, j};
            dfs(land, i, j, tmp);
           ans.push_back(tmp); 
        }

    }
    return ans;
}

void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {

    if(land[i][j] != 1) return;
    
    land[i][j] = 0;
    
    tmp[2] = max(tmp[2], i);
    tmp[3] = max(tmp[3], j);
    
    if(j + 1 < n)
    dfs(land, i, j + 1, tmp);
        
    if(i + 1 < m)
    dfs(land, i + 1, j, tmp);
}
```

This code defines a function `findFarmland` that identifies all rectangular farmlands in a 2D grid, where each farmland is represented by contiguous 1s in the grid. The `dfs` function is used to explore and mark the boundaries of each farmland.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int m, n;
	```
	Declares the variables `m` and `n`, which will store the number of rows and columns in the `land` grid.

2. **Function Definition**
	```cpp
	vector<vector<int>> findFarmland(vector<vector<int>>& land) {
	```
	Defines the function `findFarmland`, which takes a 2D vector `land` as input and returns a 2D vector of integers representing the coordinates of the farmlands.

3. **Grid Size Calculation**
	```cpp
	    m = land.size(), n = land[0].size();
	```
	Sets `m` and `n` to the number of rows and columns of the input grid `land` respectively.

4. **Result Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initializes the 2D vector `ans` to store the coordinates of the farmlands found during the grid traversal.

5. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Begins a loop to iterate through each row of the grid `land`.

6. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Starts a loop to iterate through each column in the current row of the grid `land`.

7. **Condition Check**
	```cpp
	        if(land[i][j] == 1) {
	```
	Checks if the current cell contains a `1`, indicating the start of a new farmland.

8. **Initialize Farmland Boundary**
	```cpp
	            vector<int> tmp = {i, j, i, j};
	```
	Initializes a vector `tmp` to store the coordinates of the top-left and bottom-right corners of the farmland.

9. **DFS Call**
	```cpp
	            dfs(land, i, j, tmp);
	```
	Calls the `dfs` function to explore the farmland starting from the current cell `(i, j)` and updates the boundary coordinates in `tmp`.

10. **Add Farmland to Results**
	```cpp
	           ans.push_back(tmp); 
	```
	Adds the coordinates of the current farmland to the result vector `ans`.

11. **Return Result**
	```cpp
	    return ans;
	```
	Returns the result vector `ans`, which contains the boundaries of all found farmlands.

12. **DFS Function Definition**
	```cpp
	void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {
	```
	Defines the `dfs` function, which performs a depth-first search to explore the farmland and update its boundaries.

13. **Condition Check**
	```cpp
	    if(land[i][j] != 1) return;
	```
	Checks if the current cell is not part of a farmland (i.e., it does not contain `1`). If so, the function returns.

14. **Mark Cell as Visited**
	```cpp
	    land[i][j] = 0;
	```
	Marks the current cell as visited by setting its value to `0`.

15. **Update Farmland Boundaries**
	```cpp
	    tmp[2] = max(tmp[2], i);
	```
	Updates the bottom boundary of the farmland by comparing the current row index `i` with the existing bottom boundary `tmp[2]`.

16. **Update Farmland Boundaries**
	```cpp
	    tmp[3] = max(tmp[3], j);
	```
	Updates the right boundary of the farmland by comparing the current column index `j` with the existing right boundary `tmp[3]`.

17. **Recursive DFS for Right Cell**
	```cpp
	    if(j + 1 < n)
	```
	Checks if the current cell has a neighbor to the right. If so, it calls `dfs` to explore that cell.

18. **Recursive DFS Call**
	```cpp
	    dfs(land, i, j + 1, tmp);
	```
	Recursively calls `dfs` to explore the right neighbor of the current cell.

19. **Recursive DFS for Bottom Cell**
	```cpp
	    if(i + 1 < m)
	```
	Checks if the current cell has a neighbor below. If so, it calls `dfs` to explore that cell.

20. **Recursive DFS Call**
	```cpp
	    dfs(land, i + 1, j, tmp);
	```
	Recursively calls `dfs` to explore the bottom neighbor of the current cell.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The algorithm performs a DFS for each farmland group, and each cell is visited once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) in the worst case due to the recursive stack used for DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-groups-of-farmland/description/)

---
{{< youtube R2mf-nBCWV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
