
+++
authors = ["grid47"]
title = "Leetcode 2658: Maximum Number of Fish in a Grid"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2658: Maximum Number of Fish in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "qn2ABHbRNnQ"
youtube_upload_date="2023-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qn2ABHbRNnQ/maxresdefault.webp"
comments = true
+++



---
You are given a 2D matrix `grid` of size m x n, where each cell can either be a land cell (represented by 0) or a water cell (represented by a positive integer indicating the number of fish present in that cell). A fisher can start at any water cell and perform two operations any number of times: catch all the fish in the current cell or move to an adjacent water cell. Your task is to determine the maximum number of fish the fisher can catch if they start at the optimal water cell.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a 2D grid of integers, where 0 represents a land cell and a positive integer represents a water cell containing that many fish.
- **Example:** `Input: grid = [[0, 3, 2], [4, 0, 0], [1, 0, 3]]`
- **Constraints:**
	- 1 <= m, n <= 10
	- 0 <= grid[i][j] <= 10

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of fish the fisher can catch by starting at the optimal water cell.
- **Example:** `Output: 9`
- **Constraints:**
	- The output should be a single integer representing the maximum number of fish the fisher can catch.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum number of fish that can be caught starting from any water cell, including moving through adjacent water cells.

- Step 1: Iterate over each water cell in the grid.
- Step 2: For each water cell, perform a Depth-First Search (DFS) to count the total number of fish that can be caught starting from that cell and moving through adjacent water cells.
- Step 3: Track the maximum fish count found during the search.
{{< dots >}}
### Problem Assumptions ✅
- The grid will contain at least one water cell.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: grid = [[0, 3, 2], [4, 0, 0], [1, 0, 3]]`  \
  **Explanation:** Starting at cell (0, 1), the fisher can catch 3 fish. Then, they can move to (1, 0) and catch 4 more fish. A total of 9 fish can be caught.

- **Input:** `Input: grid = [[1, 0, 0], [0, 0, 0], [0, 0, 1]]`  \
  **Explanation:** The fisher can start at either (0, 0) or (2, 2) and catch 1 fish.

{{< dots >}}
## Approach 🚀
The approach involves performing a Depth-First Search (DFS) from each water cell to find the maximum number of fish the fisher can catch. We explore all adjacent water cells recursively to accumulate the number of fish and track the maximum fish count.

### Initial Thoughts 💭
- We need to explore the grid cell by cell, performing a DFS to count fish from each starting point.
- The DFS will help us explore all possible reachable water cells from any starting cell to accumulate the maximum fish count.
{{< dots >}}
### Edge Cases 🌐
- An empty grid should not be passed as per the constraints.
- The grid size is small (maximum 10x10), so large input grids are not a concern.
- A grid with no fish should return 0.
- Ensure to handle cases where there are no water cells (i.e., the grid only contains land cells).
{{< dots >}}
## Code 💻
```cpp
int m, n;
vector<vector<int>> grid;
int findMaxFish(vector<vector<int>>& grid) {
    m = grid.size(), n = grid[0].size();
    this->grid = grid;
    int mx = 0;
    
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] != 0) {
            mx = max(mx, dfs(i, j));
        }
    return mx;
}

int dfs(int i, int j) {
    if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
    int ans = grid[i][j];
    grid[i][j] = 0;
    
    ans += dfs(i + 1, j);
    ans += dfs(i - 1, j);
    ans += dfs(i, j + 1);
    ans += dfs(i, j - 1);
    
    return ans;
}
```

This function calculates the maximum amount of fish that can be collected from a given grid by starting at any position and collecting fish in adjacent cells using a depth-first search (DFS) approach. The function tracks the maximum amount of fish collected across all potential starting points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int m, n;
	```
	This line declares two integer variables 'm' and 'n' to store the dimensions of the grid.

2. **Grid Declaration**
	```cpp
	vector<vector<int>> grid;
	```
	A 2D vector 'grid' is declared to store the fish grid values.

3. **Function Definition**
	```cpp
	int findMaxFish(vector<vector<int>>& grid) {
	```
	This defines the function 'findMaxFish', which takes the 2D grid as input and returns the maximum amount of fish that can be collected.

4. **Grid Initialization**
	```cpp
	    m = grid.size(), n = grid[0].size();
	```
	The dimensions of the grid are calculated and stored in 'm' and 'n'.

5. **Grid Assignment**
	```cpp
	    this->grid = grid;
	```
	The input grid is assigned to the member variable 'grid' for later use in the DFS function.

6. **Variable Initialization**
	```cpp
	    int mx = 0;
	```
	A variable 'mx' is initialized to 0, which will store the maximum number of fish collected during the DFS search.

7. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	An outer loop starts to iterate through each row of the grid.

8. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	An inner loop iterates through each column in the current row of the grid.

9. **Fish Check**
	```cpp
	        if(grid[i][j] != 0) {
	```
	This checks if the current grid cell contains fish (value is not 0).

10. **DFS Call**
	```cpp
	            mx = max(mx, dfs(i, j));
	```
	If the current cell contains fish, the DFS function is called from this cell, and the maximum number of fish collected is updated.

11. **Return Maximum Fish**
	```cpp
	    return mx;
	```
	The function returns the maximum number of fish collected.

12. **DFS Function Definition**
	```cpp
	int dfs(int i, int j) {
	```
	This defines the DFS function that explores the grid and collects fish from the adjacent cells.

13. **DFS Boundary Check**
	```cpp
	    if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0) return 0;
	```
	This line checks for out-of-bounds indices or cells that don't contain fish (value 0), and returns 0 if any condition is met.

14. **Fish Collection**
	```cpp
	    int ans = grid[i][j];
	```
	The variable 'ans' is initialized to the current cell's value (the amount of fish at that cell).

15. **Grid Update**
	```cpp
	    grid[i][j] = 0;
	```
	The current grid cell is marked as visited by setting its value to 0.

16. **Recursive DFS Calls**
	```cpp
	    ans += dfs(i + 1, j);
	```
	The DFS function is called recursively for the adjacent cell below the current one.

17. **Recursive DFS Calls**
	```cpp
	    ans += dfs(i - 1, j);
	```
	The DFS function is called recursively for the adjacent cell above the current one.

18. **Recursive DFS Calls**
	```cpp
	    ans += dfs(i, j + 1);
	```
	The DFS function is called recursively for the adjacent cell to the right of the current one.

19. **Recursive DFS Calls**
	```cpp
	    ans += dfs(i, j - 1);
	```
	The DFS function is called recursively for the adjacent cell to the left of the current one.

20. **Return Fish Count**
	```cpp
	    return ans;
	```
	The total number of fish collected from the current cell and its adjacent cells is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The worst-case time complexity is O(m * n) due to the DFS traversal of all grid cells in the grid of size m x n.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is O(m * n) due to the stack used by the DFS to explore all cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/)

---
{{< youtube qn2ABHbRNnQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
