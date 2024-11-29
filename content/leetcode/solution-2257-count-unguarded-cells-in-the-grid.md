
+++
authors = ["grid47"]
title = "Leetcode 2257: Count Unguarded Cells in the Grid"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2257: Count Unguarded Cells in the Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "V4jbxAhIHJw"
youtube_upload_date="2022-04-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/V4jbxAhIHJw/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed grid of size `m x n`. Some cells in the grid are occupied by guards, and some by walls. A guard can observe all cells in the four cardinal directions (north, east, south, and west) from its position unless blocked by a wall or another guard. A cell is considered guarded if at least one guard can see it. Your task is to determine the number of cells that are unoccupied and are not guarded.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the grid dimensions `m` and `n`, followed by two lists: `guards` and `walls`. The `guards` list contains the positions of guards, and the `walls` list contains the positions of walls in the grid.
- **Example:** `m = 5, n = 5, guards = [[0,0],[2,2],[4,4]], walls = [[1,1],[3,3]]`
- **Constraints:**
	- 1 <= m, n <= 10^5
	- 2 <= m * n <= 10^5
	- 1 <= guards.length, walls.length <= 5 * 10^4
	- 2 <= guards.length + walls.length <= m * n
	- guards[i].length == walls[j].length == 2
	- 0 <= rowi, rowj < m
	- 0 <= coli, colj < n
	- All positions in guards and walls are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of unoccupied and unguarded cells in the grid.
- **Example:** `Output: 12`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To count the number of cells that are neither occupied by walls nor guarded by any guard.

- Initialize a grid of size `m x n` with all values set to 0 (indicating unoccupied and unguarded cells).
- Mark the cells occupied by walls with a 1.
- Mark the cells occupied by guards with a 3.
- For each guard, mark the cells in the four cardinal directions (north, south, east, and west) as guarded, until a wall or another guard is encountered.
- After processing all guards, count the number of cells that are neither occupied by walls nor guarded.
{{< dots >}}
### Problem Assumptions ✅
- Each guard can only guard cells in the four cardinal directions, and no diagonal observation is allowed.
- If a guard is at a position, it is not considered unguarded by itself.
{{< dots >}}
## Examples 🧩
- **Input:** `m = 5, n = 5, guards = [[0,0],[2,2],[4,4]], walls = [[1,1],[3,3]]`  \
  **Explanation:** The guards will guard cells in the four cardinal directions unless blocked by a wall. After processing the guards and walls, the remaining unguarded and unoccupied cells are counted.

- **Input:** `m = 4, n = 4, guards = [[0,0]], walls = [[1,1], [3,3]]`  \
  **Explanation:** The grid has walls at (1,1) and (3,3), and a guard at (0,0). After marking the guarded cells, we count the unguarded ones.

{{< dots >}}
## Approach 🚀
The problem can be solved efficiently by using a grid to keep track of the state of each cell and iterating through each guard to mark the cells they can observe.

### Initial Thoughts 💭
- Each guard can influence a significant number of cells, so the solution needs to efficiently track the influence of each guard.
- Walls block the guard's vision, so they need to be taken into account while marking guarded cells.
- We can use a grid to represent the state of each cell and iteratively mark the cells guarded by each guard. We can then count the unguarded cells.
{{< dots >}}
### Edge Cases 🌐
- If there are no guards, all cells except walls are unguarded.
- Ensure that the solution can handle grids with a large number of cells (up to 10^5) efficiently.
- If the grid is completely surrounded by walls or contains no guards, the number of unguarded cells is easy to determine.
- Handle large inputs efficiently by processing guards and walls in an optimized manner.
{{< dots >}}
## Code 💻
```cpp
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    
    vector<vector<int>> grid(m, vector<int>(n, 0));
    
    for(auto it: walls) {
        grid[it[0]][it[1]] = 1;
    }
    
    for(auto it: guards) {
        grid[it[0]][it[1]] = 3;
    }        
    
    for(auto it: guards) {
        int x = it[0], y = it[1];
        
        for(int i = y + 1; i < n && grid[x][i] != 1 && grid[x][i] != 3; i++) {
            grid[x][i] = 2;
        }
        
        for(int i = y - 1; i >=0 && grid[x][i] != 1 && grid[x][i] != 3; i--) {
            grid[x][i] = 2;
        }            
        
        for(int i = x + 1; i < m && grid[i][y] != 1 && grid[i][y] != 3; i++) {
            grid[i][y] = 2;
        }
        
        for(int i = x - 1; i >= 0 && grid[i][y] != 1 && grid[i][y] != 3; i--) {
            grid[i][y] = 2;
        }
        // grid[x][y] = 3;
    }
    int cnt = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 0) cnt++;
    
    return cnt;
}
```

This function counts the number of unguarded cells in a grid given the positions of guards and walls. The grid is marked with various values to represent walls, guards, and cells that are under the guards' influence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
	```
	This is the function signature where the input parameters `m` and `n` represent the dimensions of the grid, while `guards` and `walls` represent the locations of the guards and walls, respectively.

2. **Grid Initialization**
	```cpp
	    vector<vector<int>> grid(m, vector<int>(n, 0));
	```
	Here, we create a grid with `m` rows and `n` columns, initializing all values to 0, representing empty cells.

3. **Walls Placement**
	```cpp
	    for(auto it: walls) {
	```
	This loop iterates through the walls' positions and marks them on the grid.

4. **Mark Walls**
	```cpp
	        grid[it[0]][it[1]] = 1;
	```
	Each wall's position is marked with a value of 1 on the grid, indicating that the cell is blocked.

5. **Guards Placement**
	```cpp
	    for(auto it: guards) {
	```
	This loop iterates through the guards' positions and places them on the grid.

6. **Mark Guards**
	```cpp
	        grid[it[0]][it[1]] = 3;
	```
	Each guard's position is marked with a value of 3 on the grid.

7. **Guard Influence Calculation**
	```cpp
	    for(auto it: guards) {
	```
	This loop processes each guard's position to mark all cells in its line of sight as guarded.

8. **Get Guard Coordinates**
	```cpp
	        int x = it[0], y = it[1];
	```
	Here, we extract the coordinates `x` and `y` of the current guard.

9. **Guard Influence Right**
	```cpp
	        for(int i = y + 1; i < n && grid[x][i] != 1 && grid[x][i] != 3; i++) {
	```
	This loop marks cells to the right of the guard as being in its line of sight, stopping at walls or other guards.

10. **Mark Right Influence**
	```cpp
	            grid[x][i] = 2;
	```
	Each cell in the guard's rightward line of sight is marked with a 2 to indicate it is under guard surveillance.

11. **Guard Influence Left**
	```cpp
	        for(int i = y - 1; i >= 0 && grid[x][i] != 1 && grid[x][i] != 3; i--) {
	```
	This loop marks cells to the left of the guard as being in its line of sight.

12. **Mark Left Influence**
	```cpp
	            grid[x][i] = 2;
	```
	Each cell in the guard's leftward line of sight is marked with a 2 to indicate it is under guard surveillance.

13. **Guard Influence Down**
	```cpp
	        for(int i = x + 1; i < m && grid[i][y] != 1 && grid[i][y] != 3; i++) {
	```
	This loop marks cells below the guard as being in its line of sight.

14. **Mark Down Influence**
	```cpp
	            grid[i][y] = 2;
	```
	Each cell in the guard's downward line of sight is marked with a 2.

15. **Guard Influence Up**
	```cpp
	        for(int i = x - 1; i >= 0 && grid[i][y] != 1 && grid[i][y] != 3; i--) {
	```
	This loop marks cells above the guard as being in its line of sight.

16. **Mark Up Influence**
	```cpp
	            grid[i][y] = 2;
	```
	Each cell in the guard's upward line of sight is marked with a 2.

17. **Count Unguarded Cells**
	```cpp
	    int cnt = 0;
	```
	We initialize a counter `cnt` to track the number of unguarded cells.

18. **Iterate Grid**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This loop iterates through each row of the grid.

19. **Iterate Grid Columns**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	This loop iterates through each column of the grid.

20. **Count Unguarded Cells**
	```cpp
	        if(grid[i][j] == 0) cnt++;
	```
	If the cell is not a wall (1) or a guard (3), we increment the counter for unguarded cells.

21. **Return Count**
	```cpp
	    return cnt;
	```
	Finally, the function returns the count of unguarded cells.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is linear in terms of the number of cells in the grid, as we process each guard and wall individually.

### Space Complexity 💾
- **Best Case:** O(m * n)
- **Worst Case:** O(m * n)

The space complexity is proportional to the size of the grid, as we store the state of each cell.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/description/)

---
{{< youtube V4jbxAhIHJw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
