
+++
authors = ["grid47"]
title = "Leetcode 2850: Minimum Moves to Spread Stones Over Grid"
date = "2024-01-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2850: Minimum Moves to Spread Stones Over Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "__h7BgcH_Cs"
youtube_upload_date="2023-09-10"
youtube_thumbnail="https://i.ytimg.com/vi/__h7BgcH_Cs/maxresdefault.jpg"
comments = true
+++



---
You are given a 3x3 grid representing stones placed in each cell. In one move, you can move a stone from its current cell to an adjacent cell. The goal is to place one stone in each cell, minimizing the number of moves.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 3x3 grid where each cell contains an integer representing the number of stones in that cell.
- **Example:** `grid = [[1, 1, 0], [1, 1, 1], [1, 2, 1]]`
- **Constraints:**
	- grid.length == grid[i].length == 3
	- 0 <= grid[i][j] <= 9
	- Sum of all grid[i][j] values is equal to 9.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to place exactly one stone in each cell of the grid.
- **Example:** `Output: 3`
- **Constraints:**
	- The output is an integer indicating the minimum number of moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the minimum number of moves to place exactly one stone in each cell.

- Identify cells that are empty (i.e., containing zero stones).
- Determine the shortest move distance to transfer stones from cells containing more than one stone to empty cells.
- Repeat until all cells contain exactly one stone.
{{< dots >}}
### Problem Assumptions ✅
- The grid is always 3x3 and contains exactly 9 stones.
- Stones can be moved to any adjacent cell.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1, 1, 0], [1, 1, 1], [1, 2, 1]]`  \
  **Explanation:** Starting with stones placed as shown in the grid, it takes 3 moves to move the stones around so that each cell contains exactly one stone.

- **Input:** `grid = [[1, 3, 0], [1, 0, 0], [1, 0, 3]]`  \
  **Explanation:** In this case, it takes 4 moves to rearrange the stones and place exactly one in each cell.

{{< dots >}}
## Approach 🚀
The approach involves moving stones from cells with excess stones to empty cells while minimizing the number of moves required to distribute the stones evenly.

### Initial Thoughts 💭
- We need to consider the cells that already contain stones and find the nearest empty cells to move stones into.
- A greedy approach can be employed to always move stones to the closest empty cell, minimizing the distance traveled.
{{< dots >}}
### Edge Cases 🌐
- There are no empty grid inputs since the grid is always 3x3.
- The algorithm should efficiently handle the grid size, which is always fixed at 3x3.
- When a grid has already one stone in each cell, no moves are needed.
- The solution needs to be efficient enough to handle up to 9 stones in the grid.
{{< dots >}}
## Code 💻
```cpp
int minimumMoves(vector<vector<int>>& grid) {
    // Base Case
    int t = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == 0)
                t++;
    if (t == 0)
        return 0;
    
    int ans = INT_MAX;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (grid[i][j] == 0)
            {
                for (int ni = 0; ni < 3; ++ni)
                {
                    for (int nj = 0; nj < 3; ++nj)
                    {
                        int d = abs(ni - i) + abs(nj - j);
                        if (grid[ni][nj] > 1)
                        {
                            grid[ni][nj]--;
                            grid[i][j]++;
                            ans = min(ans, d + minimumMoves(grid));
                            grid[ni][nj]++;
                            grid[i][j]--;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
```

This function computes the minimum number of moves required to rearrange the elements in the grid such that a specific condition is met. It recursively moves elements around and tracks the number of moves.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumMoves(vector<vector<int>>& grid) {
	```
	This line defines the function 'minimumMoves' which takes a 2D vector 'grid' as input, representing the current state of the grid.

2. **Variable Declaration**
	```cpp
	    int t = 0;
	```
	This initializes a variable 't' to zero, which will be used to count the number of zeroes in the grid.

3. **Loop**
	```cpp
	    for (int i = 0; i < 3; ++i)
	```
	This is the outer loop that iterates over the rows of the grid.

4. **Loop**
	```cpp
	        for (int j = 0; j < 3; ++j)
	```
	This inner loop iterates over the columns of the grid.

5. **Condition**
	```cpp
	            if (grid[i][j] == 0)
	```
	This condition checks if the current cell in the grid contains zero.

6. **Action**
	```cpp
	                t++;
	```
	If a zero is found, increment the variable 't' to track the number of zeroes.

7. **Condition**
	```cpp
	    if (t == 0)
	```
	This condition checks if there are no zeroes in the grid, in which case no moves are needed.

8. **Return Statement**
	```cpp
	        return 0;
	```
	If there are no zeroes in the grid, the function returns 0, indicating no moves are required.

9. **Variable Declaration**
	```cpp
	    int ans = INT_MAX;
	```
	This initializes a variable 'ans' to the maximum possible integer value, which will hold the minimum number of moves.

10. **Loop**
	```cpp
	    for (int i = 0; i < 3; ++i)
	```
	This loop iterates over the rows of the grid again for checking possible moves.

11. **Loop**
	```cpp
	        for (int j = 0; j < 3; ++j)
	```
	Inner loop to check each column within the current row.

12. **Condition**
	```cpp
	            if (grid[i][j] == 0)
	```
	This condition checks again for the presence of a zero in the current grid cell.

13. **Loop**
	```cpp
	                for (int ni = 0; ni < 3; ++ni)
	```
	This loop iterates over the rows to check for possible movements.

14. **Loop**
	```cpp
	                    for (int nj = 0; nj < 3; ++nj)
	```
	Inner loop iterating over the columns to check each grid element for possible moves.

15. **Block Start**
	```cpp
	                    {
	```
	Start of the block where the distance calculation and move checking occurs.

16. **Distance Calculation**
	```cpp
	                        int d = abs(ni - i) + abs(nj - j);
	```
	This calculates the Manhattan distance between the current cell and the target cell.

17. **Condition**
	```cpp
	                        if (grid[ni][nj] > 1)
	```
	This condition checks if the current target cell is eligible for a move (greater than 1).

18. **Action**
	```cpp
	                            grid[ni][nj]--;
	```
	Decrement the value of the target cell.

19. **Action**
	```cpp
	                            grid[i][j]++;
	```
	Increment the value of the current zero cell.

20. **Recursive Call**
	```cpp
	                            ans = min(ans, d + minimumMoves(grid));
	```
	Make a recursive call to calculate the minimum number of moves after the current swap.

21. **Action**
	```cpp
	                            grid[ni][nj]++;
	```
	Restore the value of the target cell after the recursive call.

22. **Action**
	```cpp
	                            grid[i][j]--;
	```
	Restore the value of the current zero cell after the recursive call.

23. **Return Statement**
	```cpp
	    return ans;
	```
	Return the minimum number of moves found.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is O(1) because the grid size is fixed and the solution involves a fixed number of operations for a 3x3 grid.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only use a fixed amount of space to store the grid and perform calculations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/)

---
{{< youtube __h7BgcH_Cs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
