
+++
authors = ["grid47"]
title = "Leetcode 200: Number of Islands"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 200: Number of Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/200.webp"
youtube = "IeuyI_kZ5zI"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/IeuyI_kZ5zI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/200.webp" 
    alt="A map of glowing islands floating gently, with the number of islands appearing as a soft count."
    caption="Solution to LeetCode 200: Number of Islands Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a 2D grid representing a map, where '1' represents land and '0' represents water. Your task is to count how many islands are formed by connecting adjacent lands horizontally or vertically. An island is a collection of '1's connected either horizontally or vertically.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an m x n grid of '1's (land) and '0's (water). The grid is represented as a list of lists where each inner list corresponds to a row in the grid.
- **Example:** `grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]`
- **Constraints:**
	- The grid will have between 1 and 300 rows and 1 and 300 columns.
	- Each cell of the grid is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of islands formed in the given grid, where each island consists of connected '1's.
- **Example:** `Output: 1`
- **Constraints:**
	- The output should be an integer representing the number of islands.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count how many distinct islands are present in the grid by connecting adjacent '1's.

- Iterate through each cell in the grid.
- When a '1' is encountered, it means the start of a new island. Increment the island count.
- Use Depth First Search (DFS) to mark all connected '1's as visited by changing them to '0'. This ensures that the same island is not counted multiple times.
- Continue until all cells have been processed.
{{< dots >}}
### Problem Assumptions ✅
- The grid is well-formed, with each row containing the same number of columns.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]`  \
  **Explanation:** In this example, there are three distinct islands. The first island consists of the first two rows of '1's, the second island is formed by the '1' at position (2,2), and the third island is the '1' at position (3,3). The output is 3.

- **Input:** `grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]`  \
  **Explanation:** This grid forms a single island that spans multiple rows and columns. The entire set of '1's is connected horizontally and vertically. The output is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use Depth First Search (DFS) to explore the grid and mark all cells that belong to the same island. Each time we encounter a '1', we initiate a DFS to mark all the connected '1's as visited.

### Initial Thoughts 💭
- DFS is an effective way to explore the grid and mark visited nodes. We can treat each '1' as the start of an island and use DFS to find all connected land cells.
- DFS allows us to efficiently mark connected components, and once we've visited all parts of an island, we can proceed to the next unvisited land.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty (m = 0 or n = 0), return 0.
- For large grids (e.g., 300 x 300), the solution should efficiently handle the large size without running into time or space issues.
- Handle grids with no land ('1') or only land ('1'). In these cases, the output should be 0 or 1 respectively.
- Ensure that the DFS does not go out of bounds and handles edge cases like single-cell islands or fully connected grids.
{{< dots >}}
## Code 💻
```cpp
int numIslands(vector<vector<char>>& grid) {
    int cnt = 0;
    int m = grid.size(), n = grid[0].size();
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == '1') {
            cnt++;
            dfs(grid, i, j);
        }
    return cnt;
}
void dfs(vector<vector<char>> &grid, int i, int j) {
    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
        return ;
    grid[i][j] = '0';
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
```

This code solves the 'Number of Islands' problem using Depth First Search (DFS). It iterates through a 2D grid, and whenever it encounters a land cell ('1'), it starts a DFS to mark the connected land cells as visited, incrementing the island count each time a new island is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numIslands(vector<vector<char>>& grid) {
	```
	Define the function 'numIslands' which takes a 2D grid of characters (representing water and land) and returns the number of islands. An island is surrounded by water and is formed by connecting adjacent land cells.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	Initialize a counter 'cnt' to keep track of the number of islands found during the iteration through the grid.

3. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	Store the number of rows (m) and columns (n) of the grid to control the iteration bounds.

4. **Outer Loop**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	Start the outer loop to iterate through each row of the grid.

5. **Inner Loop**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Start the inner loop to iterate through each column of the current row.

6. **Island Detection**
	```cpp
	        if(grid[i][j] == '1') {
	```
	Check if the current cell is land ('1'). If it is, it signifies the start of a new island.

7. **Increment Island Count**
	```cpp
	            cnt++;
	```
	Increment the island count (cnt) when a new island is found.

8. **DFS Call**
	```cpp
	            dfs(grid, i, j);
	```
	Call the DFS function to mark all the connected land cells as visited, ensuring we don't count the same island multiple times.

9. **End of If Statement**
	```cpp
	        }
	```
	End the if statement that checks for a land cell.

10. **Return Island Count**
	```cpp
	    return cnt;
	```
	Return the total count of islands found after iterating through the entire grid.

11. **DFS Function Definition**
	```cpp
	void dfs(vector<vector<char>> &grid, int i, int j) {
	```
	Define the helper DFS function that will mark all connected land cells as visited by changing their value to '0'. This helps prevent counting the same island multiple times.

12. **DFS Base Case Check**
	```cpp
	    if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || grid[i][j] == '0')
	```
	Check if the current position is out of bounds or if the cell is already visited (i.e., it is water or already marked as visited). If any of these conditions is true, stop the DFS.

13. **End DFS if Base Case**
	```cpp
	        return ;
	```
	End the DFS function if the base case conditions are met.

14. **Mark Visited Cell**
	```cpp
	    grid[i][j] = '0';
	```
	Mark the current cell as visited by changing its value from '1' (land) to '0' (water).

15. **DFS Recursive Calls**
	```cpp
	    dfs(grid, i + 1, j);
	```
	Recursively call DFS for the neighboring cell below the current cell (downward).

16. **DFS Recursive Call**
	```cpp
	    dfs(grid, i, j + 1);
	```
	Recursively call DFS for the neighboring cell to the right of the current cell (rightward).

17. **DFS Recursive Call**
	```cpp
	    dfs(grid, i - 1, j);
	```
	Recursively call DFS for the neighboring cell above the current cell (upward).

18. **DFS Recursive Call**
	```cpp
	    dfs(grid, i, j - 1);
	```
	Recursively call DFS for the neighboring cell to the left of the current cell (leftward).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

In the worst case, we need to visit every cell in the grid, making the time complexity O(m * n), where m is the number of rows and n is the number of columns.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

In the worst case, the DFS stack may hold all the cells in the grid, leading to a space complexity of O(m * n). For the best case (a single island), the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-islands/description/)

---
{{< youtube IeuyI_kZ5zI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
