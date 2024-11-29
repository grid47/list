
+++
authors = ["grid47"]
title = "Leetcode 794: Valid Tic-Tac-Toe State"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 794: Valid Tic-Tac-Toe State in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/794.webp"
youtube = "5IGbZyPgjP0"
youtube_upload_date="2024-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/5IGbZyPgjP0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/794.webp" 
    alt="A Tic-Tac-Toe board where valid states are checked, with valid states softly glowing as they’re found."
    caption="Solution to LeetCode 794: Valid Tic-Tac-Toe State Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a Tic-Tac-Toe board represented as a 3x3 string array, return true if and only if this board could have been reached during a valid Tic-Tac-Toe game. In a valid game, players alternate placing 'X' and 'O' characters into empty spaces. 'X' always goes first, and no player can move after the game has ended.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 3x3 Tic-Tac-Toe board represented as a string array where each element in the array is a string of length 3.
- **Example:** `board = ['XOX', ' O ', '   ']`
- **Constraints:**
	- board.length == 3
	- board[i].length == 3
	- board[i][j] is either 'X', 'O', or ' ' (empty space).

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value indicating whether the given board configuration could be reached during a valid game.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if the given Tic-Tac-Toe board is a valid position during a game, respecting the rules of turn order and winning conditions.

- Count the number of 'X' and 'O' characters on the board.
- Check if a player has won. A player wins if they have three of their symbols in a row, column, or diagonal.
- Ensure that the number of 'X's is either equal to or one more than the number of 'O's.
- If a player has won, check that the game is consistent with turn order (i.e., 'X' should not have won before 'O' had a chance to play).
{{< dots >}}
### Problem Assumptions ✅
- The board is a 3x3 grid.
- Players alternate placing 'X' and 'O' with 'X' going first.
- No more moves can be made after the game has ended.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: board = ['XOX', ' O ', '   ']`  \
  **Explanation:** This board configuration is invalid because 'O' should not have played after 'X' placed their 'X'. 'X' should always play first.

- **Input:** `Input: board = ['XOX', ' X ', '   ']`  \
  **Explanation:** This board configuration is valid because the count of 'X' is one more than the count of 'O', and no one has won yet.

- **Input:** `Input: board = ['XOX', 'O O', 'XOX']`  \
  **Explanation:** This board configuration is valid because the game ended with no inconsistencies between turn order and the game status.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to simulate the sequence of moves and verify the rules governing the game, including turn order and the winning condition.

### Initial Thoughts 💭
- We need to check both the count of 'X' and 'O' characters and ensure that a player can only win if it's their turn.
- It's important to ensure that the board configuration is consistent with the rules of the game before determining if it's valid.
{{< dots >}}
### Edge Cases 🌐
- An empty board should not be considered a valid configuration.
- Since the board is always a 3x3 grid, no consideration for large inputs is needed.
- Check if the board configuration includes a winning state and that no further moves are possible after that.
- Ensure the input follows the constraint that the board is a 3x3 grid.
{{< dots >}}
## Code 💻
```cpp
bool validTicTacToe(vector<string>& board) {
    bool xwin = false, owin = false;
    vector<int> rows(3, 0), cols(3, 0);
    int diag = 0, antidiag = 0, turns = 0;

    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) {
        if(board[i][j] == 'X') {
            turns++, cols[j]++, rows[i]++;
            if(i == j) diag++;
            if(i + j == 2) antidiag++;
        } else if(board[i][j] == 'O') {
            turns--, cols[j]--, rows[i]--;
            if(i == j) diag--;
            if(i + j == 2) antidiag--;
        }      
    }

    xwin =  rows[0] == 3 || cols[0] == 3 || 
            rows[1] == 3 || cols[1] == 3 ||
            rows[2] == 3 || cols[2] == 3 ||
            diag == 3 || antidiag == 3;
    owin =  rows[0] == -3 || cols[0] == -3 || 
            rows[1] == -3 || cols[1] == -3 ||
            rows[2] == -3 || cols[2] == -3 ||
            diag == -3 || antidiag == -3;

    if(xwin && turns == 0 || owin && turns == 1)
        return false;
    
    return (turns == 0 || turns == 1) && (!xwin || !owin);
}
```

This function checks if a given Tic-Tac-Toe board configuration is valid based on the game rules, considering the number of turns and possible winning conditions for both players (X and O).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool validTicTacToe(vector<string>& board) {
	```
	This line defines the function 'validTicTacToe', which takes a 3x3 board as input and returns a boolean indicating whether the board configuration is valid.

2. **Variable Initialization**
	```cpp
	    bool xwin = false, owin = false;
	```
	This line initializes two boolean variables, 'xwin' and 'owin', which will track whether player X or player O has won the game.

3. **Variable Initialization**
	```cpp
	    vector<int> rows(3, 0), cols(3, 0);
	```
	This initializes two vectors of size 3, 'rows' and 'cols', both set to 0. These vectors will track the sum of marks (X or O) in each row and column.

4. **Variable Initialization**
	```cpp
	    int diag = 0, antidiag = 0, turns = 0;
	```
	This initializes three variables: 'diag' for tracking the diagonal sum, 'antidiag' for the anti-diagonal sum, and 'turns' for counting the number of turns taken.

5. **Looping through Board**
	```cpp
	    for(int i = 0; i < 3; i++)
	```
	This outer loop iterates over the rows of the board.

6. **Looping through Board**
	```cpp
	    for(int j = 0; j < 3; j++) {
	```
	This inner loop iterates over the columns of the board.

7. **Condition Check (X)**
	```cpp
	        if(board[i][j] == 'X') {
	```
	This checks if the current cell contains the 'X' symbol.

8. **Update Counters (X)**
	```cpp
	            turns++, cols[j]++, rows[i]++;
	```
	This increments the turn count and updates the row and column counters for player X.

9. **Update Counters (Diagonal)**
	```cpp
	            if(i == j) diag++;
	```
	This checks if the current cell is on the main diagonal (i == j) and increments the 'diag' counter if true.

10. **Update Counters (Anti-Diagonal)**
	```cpp
	            if(i + j == 2) antidiag++;
	```
	This checks if the current cell is on the anti-diagonal (i + j == 2) and increments the 'antidiag' counter if true.

11. **Condition Check (O)**
	```cpp
	        } else if(board[i][j] == 'O') {
	```
	This checks if the current cell contains the 'O' symbol.

12. **Update Counters (O)**
	```cpp
	            turns--, cols[j]--, rows[i]--;
	```
	This decrements the turn count and updates the row and column counters for player O.

13. **Update Counters (Diagonal)**
	```cpp
	            if(i == j) diag--;
	```
	This checks if the current cell is on the main diagonal (i == j) and decrements the 'diag' counter if true.

14. **Update Counters (Anti-Diagonal)**
	```cpp
	            if(i + j == 2) antidiag--;
	```
	This checks if the current cell is on the anti-diagonal (i + j == 2) and decrements the 'antidiag' counter if true.

15. **Check for X Win**
	```cpp
	    xwin =  rows[0] == 3 || cols[0] == 3 || 
	```
	This checks if player X has won by checking if any row, column, or diagonal has a sum of 3.

16. **Check for X Win**
	```cpp
	            rows[1] == 3 || cols[1] == 3 ||
	```
	Continues checking for player X's win.

17. **Check for X Win**
	```cpp
	            rows[2] == 3 || cols[2] == 3 ||
	```
	Continues checking for player X's win.

18. **Check for X Win**
	```cpp
	            diag == 3 || antidiag == 3;
	```
	Final check for player X's win.

19. **Check for O Win**
	```cpp
	    owin =  rows[0] == -3 || cols[0] == -3 || 
	```
	This checks if player O has won by checking if any row, column, or diagonal has a sum of -3.

20. **Check for O Win**
	```cpp
	            rows[1] == -3 || cols[1] == -3 ||
	```
	Continues checking for player O's win.

21. **Check for O Win**
	```cpp
	            rows[2] == -3 || cols[2] == -3 ||
	```
	Continues checking for player O's win.

22. **Check for O Win**
	```cpp
	            diag == -3 || antidiag == -3;
	```
	Final check for player O's win.

23. **Return Invalid Game Configuration**
	```cpp
	    if(xwin && turns == 0 || owin && turns == 1)
	```
	This checks if there is an invalid game configuration, where both players win or the number of turns is incorrect.

24. **Return Validity**
	```cpp
	        return false;
	```
	If the game configuration is invalid, return false.

25. **Return Validity**
	```cpp
	    return (turns == 0 || turns == 1) && (!xwin || !owin);
	```
	This ensures the game configuration is valid by verifying the correct number of turns and no simultaneous wins.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), as the board size is fixed and we only need to make a few checks.
- **Average Case:** O(1), since we always process the same fixed-size 3x3 grid.
- **Worst Case:** O(1), as the problem always involves a fixed-size board and does not scale with input size.

The time complexity is constant because the board size is always 3x3.

### Space Complexity 💾
- **Best Case:** O(1), as the space required does not depend on input size.
- **Worst Case:** O(1), as we are using a fixed amount of space to store counts and flags.

The space complexity is constant because we only need a small, fixed amount of space for variables.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-tic-tac-toe-state/description/)

---
{{< youtube 5IGbZyPgjP0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
