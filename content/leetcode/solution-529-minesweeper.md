
+++
authors = ["grid47"]
title = "Leetcode 529: Minesweeper"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 529: Minesweeper in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/529.webp"
youtube = "zPmuqLKPbE8"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/zPmuqLKPbE8/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/529.webp" 
    alt="A glowing grid with mines and safe spots, where the player’s moves are highlighted to avoid mines."
    caption="Solution to LeetCode 529: Minesweeper Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are playing the game Minesweeper. Given an m x n grid, you must reveal the square corresponding to the next click and update the grid according to Minesweeper's rules. The grid can contain mines ('M'), empty squares ('E'), or revealed squares with adjacent mine counts.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D list representing the board and an array of two integers representing the click position.
- **Example:** `Input: board = [['E','E','E'],['E','M','E'],['E','E','E']], click = [2,2]`
- **Constraints:**
	- 1 <= m, n <= 50
	- 1 <= board[i][j] <= 105
	- 0 <= clickr < m
	- 0 <= clickc < n

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the updated board after revealing the square at the click position and applying the Minesweeper rules.
- **Example:** `Output: [['B','1','E'],['B','1','M'],['B','B','B']]`
- **Constraints:**
	- The board must be updated after revealing the click square.

{{< dots >}}
### Core Logic 🔍
**Goal:** Update the board based on Minesweeper rules after a click.

- If the clicked square is a mine, change it to 'X'.
- If the clicked square is empty and has no adjacent mines, reveal it as 'B' and recursively reveal adjacent squares.
- If the clicked square is empty and has adjacent mines, change it to the number of adjacent mines.
{{< dots >}}
### Problem Assumptions ✅
- The input board is valid and well-formed.
- The click position is a valid position within the board.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: board = [['E','E','E'],['E','M','E'],['E','E','E']], click = [2,2]`  \
  **Explanation:** Here, clicking on an empty square with adjacent mines will reveal the number of adjacent mines or recursively reveal surrounding squares if there are no adjacent mines.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to recursively reveal squares based on the Minesweeper rules.

### Initial Thoughts 💭
- The game is based on revealing squares and updating the board recursively.
- We will need to check adjacent squares and recursively reveal empty squares without adjacent mines.
{{< dots >}}
### Edge Cases 🌐
- The clicked square is already revealed.
- The board size is at the maximum allowed.
- The click lands on a corner or edge of the board.
- Ensure no out-of-bounds errors when revealing adjacent squares.
{{< dots >}}
## Code 💻
```cpp
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int m = board.size(), n = board[0].size();
    int row = click[0], col = click[1];
    if(board[row][col] == 'M') {
        board[row][col] = 'X';
    } else {
        int cnt = 0;
        for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++) {
            if(i == 0 && j == 0) continue;
            int x = row + i, y = col + j;
            if(x < 0 || y < 0 || x >= m || y >= n)    continue;
            if(board[x][y] == 'M' || board[x][y] == 'X') cnt++;
        }
        if (cnt > 0) board[row][col] = '0' + cnt;
        else {
            board[row][col] = 'B';
            for(int i = -1; i <= 1; i++)
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int x = row + i, y = col + j;
                if(x < 0 || y < 0 || x >= m || y >= n)    continue;
                vector<int> arr;
                arr.push_back(x);
                arr.push_back(y);

                if(board[x][y] == 'E') updateBoard(board, arr);
            }
        }
    }
    return board;
}
```

This code represents a function to update the board in a Minesweeper game. It handles the logic for revealing a cell based on the click and whether the cell contains a mine. If no mine is found, it recursively reveals adjacent cells in a backtracking fashion. The function employs matrix manipulation and grid traversal techniques.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
	```
	Defines the `updateBoard` function that takes a board and a click position to update the board based on Minesweeper rules.

2. **Matrix Initialization**
	```cpp
	    int m = board.size(), n = board[0].size();
	```
	Initializes `m` and `n` to hold the dimensions of the board, representing the number of rows and columns, respectively.

3. **Variable Initialization**
	```cpp
	    int row = click[0], col = click[1];
	```
	Extracts the row and column values from the `click` vector to identify the clicked cell.

4. **Base Case Check**
	```cpp
	    if(board[row][col] == 'M') {
	```
	Checks if the clicked cell is a mine. If it is, the cell is marked as 'X' to signify that the player hit a mine.

5. **Board Update for Mine**
	```cpp
	        board[row][col] = 'X';
	```
	Marks the clicked cell as 'X' to represent a mine hit.

6. **Else Block**
	```cpp
	    } else {
	```
	Handles the case when the clicked cell is not a mine.

7. **Counter Initialization**
	```cpp
	        int cnt = 0;
	```
	Initializes a counter `cnt` to keep track of the number of adjacent mines around the clicked cell.

8. **Outer Loop**
	```cpp
	        for(int i = -1; i <= 1; i++)
	```
	Iterates over the rows of the neighboring cells, including the current cell itself.

9. **Inner Loop**
	```cpp
	        for(int j = -1; j <= 1; j++) {
	```
	Iterates over the columns of the neighboring cells, ensuring all 8 surrounding cells are checked.

10. **Skip Center Cell**
	```cpp
	            if(i == 0 && j == 0) continue;
	```
	Skips the center cell (the clicked cell itself) and only checks the surrounding cells.

11. **Neighbor Coordinates**
	```cpp
	            int x = row + i, y = col + j;
	```
	Calculates the coordinates of each neighboring cell based on the offsets `i` and `j`.

12. **Boundary Check**
	```cpp
	            if(x < 0 || y < 0 || x >= m || y >= n)    continue;
	```
	Checks if the neighboring cell is within the bounds of the board. If out of bounds, the iteration continues with the next neighbor.

13. **Mine Check**
	```cpp
	            if(board[x][y] == 'M' || board[x][y] == 'X') cnt++;
	```
	Checks if the neighboring cell contains a mine ('M') or has already been revealed as a mine ('X'). If so, increments the counter `cnt`.

14. **Update Cell with Mine Count**
	```cpp
	        if (cnt > 0) board[row][col] = '0' + cnt;
	```
	If the counter `cnt` is greater than 0, updates the clicked cell with the count of adjacent mines.

15. **Open Else Block**
	```cpp
	        else {
	```
	Handles the case when no adjacent mines are found.

16. **Update for Blank Cell**
	```cpp
	            board[row][col] = 'B';
	```
	Marks the clicked cell as 'B' to indicate it is a blank space with no adjacent mines.

17. **Recursive Exploration**
	```cpp
	            for(int i = -1; i <= 1; i++)
	```
	Starts a recursive process to explore all adjacent cells if the clicked cell is blank.

18. **Recursive Exploration**
	```cpp
	            for(int j = -1; j <= 1; j++) {
	```
	Iterates over the surrounding cells to explore them recursively.

19. **Skip Center Cell Again**
	```cpp
	                if(i == 0 && j == 0) continue;
	```
	Skips the current cell when exploring adjacent cells.

20. **Neighbor Coordinates Again**
	```cpp
	                int x = row + i, y = col + j;
	```
	Calculates the coordinates of the neighboring cells during recursion.

21. **Boundary Check Again**
	```cpp
	                if(x < 0 || y < 0 || x >= m || y >= n)    continue;
	```
	Ensures the neighboring cells are within the board boundaries.

22. **Push Neighbor to Array**
	```cpp
	                vector<int> arr;
	```
	Creates a new vector `arr` to hold the coordinates of a neighboring cell.

23. **Store Coordinates**
	```cpp
	                arr.push_back(x);
	```
	Pushes the x-coordinate of the neighboring cell into the `arr` vector.

24. **Store Coordinates**
	```cpp
	                arr.push_back(y);
	```
	Pushes the y-coordinate of the neighboring cell into the `arr` vector.

25. **Recursive Call**
	```cpp
	                if(board[x][y] == 'E') updateBoard(board, arr);
	```
	If the neighboring cell is an empty space ('E'), the function is called recursively to update it.

26. **Return Updated Board**
	```cpp
	    return board;
	```
	Returns the updated board after processing the click.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

In the worst case, all squares need to be revealed.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(m * n)

Space complexity depends on the recursion depth and the board size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minesweeper/description/)

---
{{< youtube zPmuqLKPbE8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
