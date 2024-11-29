
+++
authors = ["grid47"]
title = "Leetcode 1905: Count Sub Islands"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1905: Count Sub Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mLpW3qfbNJ8"
youtube_upload_date="2021-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/mLpW3qfbNJ8/maxresdefault.jpg"
comments = true
+++



---
You are given two m x n binary matrices, grid1 and grid2, where each cell can either be 0 (representing water) or 1 (representing land). An island is a group of connected 1's, connected either horizontally or vertically. An island in grid2 is considered a sub-island if there is a corresponding island in grid1 that contains all the cells of the island in grid2. Your task is to determine the number of sub-islands in grid2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two m x n binary matrices grid1 and grid2. Each element in the grid is either 0 or 1.
- **Example:** `Example 1: 
grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]] 
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]`
- **Constraints:**
	- 1 <= m, n <= 500
	- grid1 and grid2 have the same dimensions
	- grid1[i][j], grid2[i][j] are either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the number of islands in grid2 that are considered sub-islands.
- **Example:** `Example 1: 
Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to count the number of sub-islands in grid2 by identifying islands in grid2 that are fully contained within the corresponding islands in grid1.

- Iterate over grid2 and for each land cell (1), perform a DFS to find all connected land cells.
- For each island in grid2, check if all its cells are part of an island in grid1.
- Count the number of valid islands that satisfy the sub-island condition.
{{< dots >}}
### Problem Assumptions ✅
- Both grids are binary matrices with 0's and 1's.
- An island is formed by connected 1's in a 4-directional manner.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: 
grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]] 
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]`  \
  **Explanation:** In grid1, we have several islands formed by connected 1's. In grid2, some of these islands are fully contained within the islands of grid1, making them sub-islands. There are three sub-islands in grid2.

{{< dots >}}
## Approach 🚀
We will solve the problem by identifying all the islands in grid2, checking if they are fully contained in grid1, and counting those that qualify as sub-islands.

### Initial Thoughts 💭
- We need to iterate over grid2 and find all the connected islands (1's).
- For each island in grid2, we will check if its cells are part of a corresponding island in grid1.
- Depth-First Search (DFS) can be used to identify the islands in both grids and check if they are sub-islands.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the input grids are entirely made up of water (0's).
- Consider edge cases where the grids have the maximum size (500x500).
- Handle cases where there are no islands in grid1, making it impossible for any island in grid2 to be a sub-island.
- Ensure that the solution works efficiently for large grids.
{{< dots >}}
## Code 💻
```cpp
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    
    int m =grid2.size(), n = grid2[0].size();
    
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid2[i][j] == 1)
            dfs(grid2, i, j);
    
    int res = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid2[i][j] == 2)
            res += find(grid1, grid2, i, j);
    
    return res;
}

void dfs(vector<vector<int>>& grid2, int i, int j) {

    int m = grid2.size(), n = grid2[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;

    grid2[i][j] = 2;

    dfs(grid2, i, j + 1);
    dfs(grid2, i + 1, j);
    dfs(grid2, i - 1, j);
    dfs(grid2, i, j - 1);

}

bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
    int m = grid2.size(), n = grid2[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;

    bool res = true;
    if (grid1[i][j] != 1) res = false;

    grid2[i][j] = 3;

    res &= find(grid1, grid2, i, j + 1);
    res &= find(grid1, grid2, i + 1, j);
    res &= find(grid1, grid2, i - 1, j);
    res &= find(grid1, grid2, i, j - 1);

    return res;
}

```

This is the implementation of the algorithm to count the number of sub-islands. The solution works by checking each cell in grid2, marking parts of islands, and validating if the islands in grid2 are present in grid1.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	```
	This is the function signature for counting the sub-islands. It takes two 2D grids, grid1 and grid2, as inputs.

2. **Variable Initialization**
	```cpp
	    int m =grid2.size(), n = grid2[0].size();
	```
	Here, the dimensions of grid2 are assigned to m (rows) and n (columns).

3. **Looping Over Grid**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This is the outer loop that iterates through the rows of grid2.

4. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	The inner loop iterates through the columns of grid2.

5. **Condition Check**
	```cpp
	        if(grid2[i][j] == 1)
	```
	This condition checks if the current cell in grid2 is part of an island (value 1).

6. **DFS Call**
	```cpp
	            dfs(grid2, i, j);
	```
	If the condition is met, a depth-first search (DFS) is called to mark the connected island cells.

7. **Result Initialization**
	```cpp
	    int res = 0;
	```
	This initializes the result counter to zero, which will hold the number of sub-islands.

8. **Second Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This is another loop over the rows of grid2 to check the marked cells.

9. **Second Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	The second inner loop checks the columns of grid2 to validate islands.

10. **Condition Check for Sub-Island**
	```cpp
	        if(grid2[i][j] == 2)
	```
	If a cell is marked with 2 (indicating it is part of a valid island), the find function is called.

11. **Increment Result**
	```cpp
	            res += find(grid1, grid2, i, j);
	```
	If the find function returns true, the result counter is incremented.

12. **Return Statement**
	```cpp
	    return res;
	```
	Finally, the function returns the number of sub-islands found.

13. **DFS Function**
	```cpp
	void dfs(vector<vector<int>>& grid2, int i, int j) {
	```
	This is the DFS function that is called to explore and mark the connected components of grid2.

14. **DFS Boundaries Check**
	```cpp
	    if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;
	```
	This condition checks if the indices are within bounds and if the current cell is part of an island (value 1).

15. **Mark Cell as Visited**
	```cpp
	    grid2[i][j] = 2;
	```
	Marks the current cell as visited by changing its value to 2.

16. **Recursive DFS Calls**
	```cpp
	    dfs(grid2, i, j + 1);
	```
	Recursively calls DFS for the cell to the right.

17. **Recursive DFS Calls**
	```cpp
	    dfs(grid2, i + 1, j);
	```
	Recursively calls DFS for the cell below.

18. **Recursive DFS Calls**
	```cpp
	    dfs(grid2, i - 1, j);
	```
	Recursively calls DFS for the cell above.

19. **Recursive DFS Calls**
	```cpp
	    dfs(grid2, i, j - 1);
	```
	Recursively calls DFS for the cell to the left.

20. **Find Function**
	```cpp
	bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
	```
	The find function checks whether an island in grid2 exists in grid1 at the given coordinates.

21. **Boundary Check**
	```cpp
	    if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;
	```
	Checks if the current cell is out of bounds or already validated.

22. **Result Initialization**
	```cpp
	    bool res = true;
	```
	Initializes a boolean variable to track whether the island is a valid sub-island.

23. **Grid1 Validation**
	```cpp
	    if (grid1[i][j] != 1) res = false;
	```
	Checks if the current cell in grid2 is part of an island in grid1.

24. **Marking the Cell**
	```cpp
	    grid2[i][j] = 3;
	```
	Marks the current cell as processed.

25. **Recursive Find Calls**
	```cpp
	    res &= find(grid1, grid2, i, j + 1);
	```
	Recursively calls the find function for the cell to the right.

26. **Recursive Find Calls**
	```cpp
	    res &= find(grid1, grid2, i + 1, j);
	```
	Recursively calls the find function for the cell below.

27. **Recursive Find Calls**
	```cpp
	    res &= find(grid1, grid2, i - 1, j);
	```
	Recursively calls the find function for the cell above.

28. **Recursive Find Calls**
	```cpp
	    res &= find(grid1, grid2, i, j - 1);
	```
	Recursively calls the find function for the cell to the left.

29. **Return Statement**
	```cpp
	    return res;
	```
	Returns true if the island is valid, otherwise returns false.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns.
- **Average Case:** O(m * n), as each cell is visited once during DFS.
- **Worst Case:** O(m * n), where m is the number of rows and n is the number of columns.

The time complexity depends on the size of the grid, as we visit each cell during DFS.

### Space Complexity 💾
- **Best Case:** O(m * n), for the same reason as worst-case.
- **Worst Case:** O(m * n), as we need to store the grid and the visited states during DFS.

The space complexity is determined by the size of the grid and the recursive DFS stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-sub-islands/description/)

---
{{< youtube mLpW3qfbNJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
