
+++
authors = ["grid47"]
title = "Leetcode 2596: Check Knight Tour Configuration"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2596: Check Knight Tour Configuration in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OBht8NT_09c"
youtube_upload_date="2023-03-19"
youtube_thumbnail="https://i.ytimg.com/vi/OBht8NT_09c/maxresdefault.jpg"
comments = true
+++



---
Given an `n x n` chessboard, the knight starts at the top-left corner and visits every cell exactly once. The knight's movements are represented by a grid where `grid[row][col]` indicates the order of the knight's visit to that cell. Determine if this sequence of moves is valid, i.e., the knight moves according to its legal movement pattern.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an `n x n` integer matrix `grid` where each element indicates the order of the knight's visit to the corresponding cell.
- **Example:** `For `grid = [[0, 11, 16, 5, 20], [17, 4, 19, 10, 15], [12, 1, 8, 21, 6], [3, 18, 23, 14, 9], [24, 13, 2, 7, 22]]`.`
- **Constraints:**
	- 3 <= n <= 7
	- grid[row][col] represents a unique visit number from 0 to n*n - 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the grid represents a valid sequence of knight moves, otherwise return `false`.
- **Example:** `For the input `grid = [[0, 11, 16, 5, 20], [17, 4, 19, 10, 15], [12, 1, 8, 21, 6], [3, 18, 23, 14, 9], [24, 13, 2, 7, 22]]`, the output should be `true`.`
- **Constraints:**
	- The output will be a boolean value, either `true` or `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if the knight’s movement follows its allowed movement rules in the given sequence.

- 1. Create a map to store the positions of each visit from the grid.
- 2. Ensure the knight starts at the top-left corner (0, 0).
- 3. Check the movement from each cell to the next one in the grid to ensure it's a valid knight's move.
- 4. Return `true` if all moves are valid; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The knight’s movement follows standard rules: it moves in an L-shape: 2 squares in one direction and 1 square in a perpendicular direction.
{{< dots >}}
## Examples 🧩
- **Input:** `For `grid = [[0, 11, 16, 5, 20], [17, 4, 19, 10, 15], [12, 1, 8, 21, 6], [3, 18, 23, 14, 9], [24, 13, 2, 7, 22]]``  \
  **Explanation:** This is a valid configuration as all knight moves follow the allowed L-shape movement. The knight correctly moves from each cell to the next in the sequence.

- **Input:** `For `grid = [[0, 3, 6], [5, 8, 1], [2, 7, 4]]``  \
  **Explanation:** This is not a valid configuration because the 8th move is not a valid knight move from the 7th move's position.

{{< dots >}}
## Approach 🚀
The approach involves mapping the knight's visit sequence and checking the validity of each move based on the knight’s allowed movement pattern.

### Initial Thoughts 💭
- The knight can only move in an L-shape, so after the first move, we can check if the move is valid based on the previous position.
- By creating a map of the grid’s positions, we can quickly check if the knight’s moves are valid based on the knight’s movement rules.
{{< dots >}}
### Edge Cases 🌐
- There will always be an input grid with a minimum size of 3x3.
- For larger grids (size 7x7), the solution should still be efficient in checking the validity of moves.
- Ensure that the knight always starts from (0, 0) and that all moves are valid L-shaped moves.
- The solution must work for all grid sizes between 3x3 and 7x7.
{{< dots >}}
## Code 💻
```cpp
bool checkValidGrid(vector<vector<int>>& grid) {
    map<int, pair<int, int>> mp;
    int n = grid.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mp[grid[i][j]] = {i, j};
        }
    }
    if(mp[0] != make_pair(0,0)) return false;
    int p = 0, q = 0;
    for(int i = 1; i < n * n; i++) {
        auto it = mp[i];
        int x = it.first;
        int y = it.second;
        if((abs(x - p) == 1 && abs(y - q) == 2) ||
           (abs(x - p) == 2 && abs(y - q) == 1)) {
            p = x;
            q = y;
        } else return false;
    }
    return true;
}
```

This is the complete code for validating a grid based on a specific movement rule.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	bool checkValidGrid(vector<vector<int>>& grid) {
	```
	Function definition to validate the grid, accepting a 2D vector as input.

2. **Data Structure**
	```cpp
	    map<int, pair<int, int>> mp;
	```
	Declare a map to store the position (row, column) of each number in the grid.

3. **Variable Initialization**
	```cpp
	    int n = grid.size();
	```
	Store the size of the grid (n x n) in a variable.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Outer loop to iterate through the rows of the grid.

5. **Loop**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	Inner loop to iterate through the columns of the grid.

6. **Map Operation**
	```cpp
	            mp[grid[i][j]] = {i, j};
	```
	Store the grid element's position in the map with the number as the key.

7. **Condition Check**
	```cpp
	    if(mp[0] != make_pair(0,0)) return false;
	```
	Check if the starting position (0) is at (0, 0); return false if not.

8. **Variable Initialization**
	```cpp
	    int p = 0, q = 0;
	```
	Initialize variables to track the current position (p, q) during the validation process.

9. **Loop**
	```cpp
	    for(int i = 1; i < n * n; i++) {
	```
	Loop to check each subsequent number in the grid, from 1 to n*n-1.

10. **Map Operation**
	```cpp
	        auto it = mp[i];
	```
	Retrieve the position of the current number (i) from the map.

11. **Variable Assignment**
	```cpp
	        int x = it.first;
	```
	Assign the row index of the current number to variable x.

12. **Variable Assignment**
	```cpp
	        int y = it.second;
	```
	Assign the column index of the current number to variable y.

13. **Condition Check**
	```cpp
	        if((abs(x - p) == 1 && abs(y - q) == 2) ||
	```
	Check if the current position is valid based on specific movement rules (L-shaped).

14. **Condition Check**
	```cpp
	           (abs(x - p) == 2 && abs(y - q) == 1)) {
	```
	Check if the movement between positions is valid based on the rule.

15. **Variable Update**
	```cpp
	            p = x;
	```
	Update the current row index (p) to the new position.

16. **Variable Update**
	```cpp
	            q = y;
	```
	Update the current column index (q) to the new position.

17. **Return**
	```cpp
	    return true;
	```
	Return true if all movements are valid, indicating the grid is valid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) because we need to check the knight’s move for each cell in the grid.

### Space Complexity 💾
- **Best Case:** O(n^2)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) because we store the positions of all n^2 cells in a map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-knight-tour-configuration/description/)

---
{{< youtube OBht8NT_09c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
