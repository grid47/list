
+++
authors = ["grid47"]
title = "Leetcode 1958: Check if Move is Legal"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1958: Check if Move is Legal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KxK33AcQZpQ"
youtube_upload_date="2021-08-07"
youtube_thumbnail="https://i.ytimg.com/vi/KxK33AcQZpQ/maxresdefault.jpg"
comments = true
+++



---
You are given a game board represented as an 8x8 grid, where each cell can either be free ('.'), white ('W'), or black ('B'). The objective is to determine if placing your piece (either 'W' or 'B') at a specified location will create a valid 'good line' where the line consists of three or more cells. A good line is defined as a line (horizontal, vertical, or diagonal) with endpoints of the same color and any cells between them of the opposite color.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a board represented as an 8x8 grid, the row and column indices of the cell where you wish to place your piece, and the color of the piece you are playing as ('W' or 'B').
- **Example:** `board = [[".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], ["W", "B", "B", ".", "W", "W", "W", "B"], [".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."]], rMove = 4, cMove = 3, color = "B"`
- **Constraints:**
	- board.length == board[r].length == 8
	- 0 <= rMove, cMove < 8
	- board[rMove][cMove] == '.'
	- color is either 'B' or 'W'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if placing your piece at the specified location will result in a valid move that creates a good line. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The board must contain only '.' for the move location, and the color must be either 'B' or 'W'.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if placing a piece at the specified location results in a good line. A good line requires that after placing the piece, the endpoints of the line are the same color, and the cells in the middle are the opposite color.

- Step 1: Start by examining the 8 possible directions (horizontal, vertical, and diagonal).
- Step 2: For each direction, look for a potential good line starting from the specified move position and check the surrounding cells.
- Step 3: If a good line is formed in any direction, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input will always provide a valid 8x8 grid with the specified row and column indices for the move.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: board = [[".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."], ["W", "B", "B", ".", "W", "W", "W", "B"], [".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "B", ".", ".", ".", "."], [".", ".", ".", "W", ".", ".", ".", "."]], rMove = 4, cMove = 3, color = "B"`  \
  **Explanation:** In this case, placing a black piece at the location (4, 3) will form valid lines in both the vertical and diagonal directions, hence the result is true.

- **Input:** `Input: board = [[".", ".", ".", ".", ".", ".", ".", "."], [".", "B", ".", ".", "W", ".", ".", "."], [".", ".", "W", ".", ".", ".", "."], [".", ".", ".", "W", "B", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", "B", "W", ".", "."], [".", ".", ".", ".", ".", "W", ".", "."], [".", ".", ".", ".", ".", ".", "B", "."]], rMove = 4, cMove = 4, color = "W"`  \
  **Explanation:** In this case, no good lines are formed with the white piece at (4, 4), so the result is false.

{{< dots >}}
## Approach 🚀
The approach involves checking all 8 possible directions (horizontal, vertical, and diagonal) to see if placing the piece at the specified location creates a valid good line. A good line requires that after placing the piece, the endpoints are the same color, and the cells in between are the opposite color.

### Initial Thoughts 💭
- A good line requires at least three cells, so we need to examine lines of length 3 or more.
- We need to consider all 8 directions to check for valid lines.
- This problem requires us to carefully track the cells in a line and check if the piece at the chosen position forms a valid good line in any direction.
{{< dots >}}
### Edge Cases 🌐
- There will always be a valid move location (i.e., '.') in the input, so no need to handle empty cells.
- The problem is constrained to a fixed 8x8 grid, so the input size is constant and manageable.
- The move will always be placed at a free cell ('.'), and the color will be either 'W' or 'B'.
- The solution should efficiently check all 8 directions for valid good lines.
{{< dots >}}
## Code 💻
```cpp
bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char cur) {

    int m = board.size(), n = board[0].size();

    int dir[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
    
    for(int d = 0; d < 9; d++) {
        for(int x = 1; ; x++) {
            int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
            if(i < 0 || j < 0 || i == 8 || j == 8|| board[i][j] == '.')
                break;
            if(board[i][j] == cur) {
                if(x > 1) return true;
                
                break;
            }
        }
    }


    return false;        
}
```

This function checks if a move in a game board leads to a valid position based on certain direction rules. It uses an array of directions to check multiple lines starting from the current position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char cur) {
	```
	This is the function header. It takes a reference to a board (2D vector), a row and column move (rMove, cMove), and the character of the current player (cur). The function checks if a given move leads to a valid position according to the game rules.

2. **Variable Initialization**
	```cpp
	
	```
	The function initializes variables for the size of the board and defines the possible movement directions. It also sets up an array of directions (dir) to handle the different directions in the game.

3. **Size Calculation**
	```cpp
	    int m = board.size(), n = board[0].size();
	```
	Here, 'm' and 'n' store the number of rows and columns of the board, respectively. This is used to check the board boundaries during the move validation.

4. **Direction Setup**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
	```
	This array 'dir' holds the direction vectors for checking adjacent positions. The values represent movement in four directions: right, down, left, and up.

5. **Loop Through Directions**
	```cpp
	    for(int d = 0; d < 9; d++) {
	```
	A loop is used to iterate through the directions array. The variable 'd' is used to select different direction vectors to check for valid moves.

6. **Move Checking**
	```cpp
	        for(int x = 1; ; x++) {
	```
	This nested loop checks multiple positions along the selected direction. The variable 'x' is used to incrementally move in the current direction.

7. **Calculate New Position**
	```cpp
	            int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
	```
	The new row (i) and column (j) are calculated based on the current move ('rMove', 'cMove') and the direction vector.

8. **Boundary and Validity Check**
	```cpp
	            if(i < 0 || j < 0 || i == 8 || j == 8 || board[i][j] == '.')
	```
	This condition checks if the new position is out of bounds or if the position on the board is empty ('.'). If so, the loop breaks as the move is invalid.

9. **Break Invalid Move**
	```cpp
	                break;
	```
	If the move leads to an invalid position, the loop breaks and no further checks are made in that direction.

10. **Match Check**
	```cpp
	            if(board[i][j] == cur) {
	```
	This checks if the board position at (i, j) matches the current player's character ('cur').

11. **Valid Move Check**
	```cpp
	                if(x > 1) return true;
	```
	If the current position matches the player's character and the move has been made for more than one step (x > 1), the function returns true, indicating a valid move.

12. **Break on Invalid Match**
	```cpp
	                break;
	```
	If the current position doesn't match the player's character, the loop breaks, and no further checking is done in that direction.

13. **Return False**
	```cpp
	    return false;        
	```
	If no valid move is found after checking all directions, the function returns false, indicating that the move is invalid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

In the worst case, the solution involves checking all 8 directions, but since the grid is fixed at 8x8, the complexity remains constant.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

Since we are not using any additional space that grows with the input, the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-move-is-legal/description/)

---
{{< youtube KxK33AcQZpQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
