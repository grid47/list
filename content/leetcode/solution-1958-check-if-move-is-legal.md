
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

In this problem, we are tasked with determining whether a player's move in a game (such as Tic-Tac-Toe) results in a win condition. Given a 2D board representing the game state, the player's current move coordinates, and the player's symbol, the objective is to check if the move creates a sequence of three or more of the same symbol in any direction: horizontally, vertically, or diagonally. The board contains characters that represent empty spaces and the players' symbols.

### Approach

To solve this problem, we can utilize a direction-based approach to check for sequences of the current player's symbol extending from the last move made. We will evaluate all eight possible directions from the move location: up, down, left, right, and the four diagonal directions. The algorithm will check how far the current player's symbol extends in each direction. If we find a sequence of three or more symbols, we will return true, indicating a win condition.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the provided code:

```cpp
class Solution {
public:
```
This line defines the `Solution` class, and the `public` access specifier allows the methods within the class to be accessible from outside the class.

```cpp
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char cur) {
```
The `checkMove` method takes four parameters: a reference to a 2D vector `board` representing the game state, two integers `rMove` and `cMove` representing the row and column of the player's move, and a character `cur` representing the current player's symbol.

```cpp
        int m = board.size(), n = board[0].size();
```
We initialize two integers, `m` and `n`, to hold the dimensions of the board. `m` is the number of rows, and `n` is the number of columns.

```cpp
        int dir[] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};
```
We define an array `dir` that contains the changes in row and column indices for each of the eight possible directions: up, down, left, right, and the four diagonals. The array is structured so that the first half represents row changes and the second half represents column changes.

```cpp
        for(int d = 0; d < 9; d++) {
```
This outer loop iterates over the directions defined in the `dir` array. The loop variable `d` indicates the current direction we are checking.

```cpp
            for(int x = 1; ; x++) {
```
This inner loop will incrementally check each step in the current direction. The loop variable `x` represents the number of steps taken in the current direction.

```cpp
                int i = rMove + x * dir[d], j = cMove + x * dir[d + 1];
```
We calculate the new indices `i` and `j` for the current step based on the player's last move and the direction we are currently checking. 

```cpp
                if(i < 0 || j < 0 || i == 8 || j == 8 || board[i][j] == '.')
                    break;
```
This line checks if the new indices are out of bounds or if we encounter an empty space (represented by `.`). If any of these conditions are true, we break out of the inner loop since we cannot form a valid sequence in this direction.

```cpp
                if(board[i][j] == cur) {
```
We check if the character at the current indices `i` and `j` matches the current player's symbol.

```cpp
                    if(x > 1) return true;
```
If the symbol matches and we have moved more than one step in this direction (i.e., `x > 1`), it means we have found a sequence of at least three consecutive symbols (the current move and at least two more in the same direction). In this case, we return `true`, indicating a win condition.

```cpp
                    break;
```
If the condition is not met (i.e., `x` is not greater than 1), we break out of the inner loop to check other directions.

```cpp
            }
        }
```
The loops conclude here, and if no sequences of three or more symbols were found in any direction, we proceed to return false.

```cpp
        return false;        
    }
};
```
Finally, if no winning condition is met, we return `false`, indicating that the current move did not result in a win.

### Complexity

- **Time Complexity**: The time complexity is \( O(1) \) for the checking operation since we have a constant number of directions (8) and we are checking each direction only until we reach either a limit or a match.

- **Space Complexity**: The space complexity is \( O(1) \) as we are not using any additional data structures that grow with the input size.

### Conclusion

The `checkMove` function efficiently determines whether the current player's move results in a win by checking all possible directions for sequences of identical symbols. By utilizing a straightforward approach and examining each direction in a controlled manner, we can quickly conclude the status of the game after a move is made. This method ensures that we account for the rules of the game and the potential winning scenarios.

### Key Features

1. **Direction-Based Checking**: The function systematically checks all possible winning directions, ensuring comprehensive coverage of potential win conditions.

2. **Early Exit**: The function is designed to return as soon as a winning sequence is found, which enhances performance by avoiding unnecessary computations.

3. **Simplicity**: The logic is easy to follow and implement, making the solution maintainable and understandable.

### Use Cases

This function is applicable in various game scenarios where determining the outcome of a move is necessary. Examples include:
- **Tic-Tac-Toe**: Checking if a player has won after making a move.
- **Connect Four**: Evaluating win conditions after dropping a piece in a column.
- **General Board Games**: Any situation where consecutive symbols need to be checked for winning conditions.

### Example Usage

To demonstrate how the function can be utilized, consider the following example:

```cpp
Solution sol;
vector<vector<char>> board = {
    {'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'X', 'X', 'X', '.', '.', 'O', '.'},
    {'O', 'X', '.', 'O', 'X', 'O', '.'},
    {'.', '.', 'X', 'O', 'X', '.'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.'},
    {'O', 'O', 'X', '.', '.', '.', '.'},
};

bool result = sol.checkMove(board, 2, 3, 'X'); // Example move for player 'X'
cout << (result ? "Win" : "No Win"); // Output: Win
```

In this example, the function checks if placing 'X' at the specified location results in a winning condition. By employing this function, developers can efficiently manage game logic and provide feedback on players' moves in real-time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-move-is-legal/description/)

---
{{< youtube KxK33AcQZpQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
