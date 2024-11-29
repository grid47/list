
+++
authors = ["grid47"]
title = "Leetcode 419: Battleships in a Board"
date = "2024-09-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 419: Battleships in a Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp"
youtube = "gKhvVHd8ihI"
youtube_upload_date="2020-07-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gKhvVHd8ihI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/419.webp" 
    alt="A board game where ships glow softly as they are placed on the grid, each ship highlighted as it is positioned."
    caption="Solution to LeetCode 419: Battleships in a Board Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a grid representing a battleship field, where 'X' marks the location of a part of a battleship and '.' represents an empty sea cell. A battleship is either placed horizontally or vertically on the grid, with no adjacent battleships (there must be at least one empty cell between any two battleships). Your task is to count the number of distinct battleships on the grid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a 2D character grid where each cell contains either 'X' (part of a battleship) or '.' (empty sea).
- **Example:** `Input: board = [['X', '.', '.', 'X'], ['.', '.', '.', 'X'], ['.', '.', '.', 'X']]`
- **Constraints:**
	- 1 <= m, n <= 200
	- board[i][j] is either '.' or 'X'

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the number of distinct battleships on the board.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is an integer indicating the number of distinct battleships.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of distinct battleships by identifying connected parts of 'X' (either horizontally or vertically).

- Iterate through the grid cell by cell.
- For each 'X', check if it is the start of a new battleship (i.e., if there is no 'X' directly above or to the left of it).
- Count it as a new battleship if it is the start of one, and continue scanning the grid.
{{< dots >}}
### Problem Assumptions ✅
- The grid contains valid characters (either 'X' or '.').
- There is at least one row and one column in the grid.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: board = [['X', '.', '.', 'X'], ['.', '.', '.', 'X'], ['.', '.', '.', 'X']]`  \
  **Explanation:** In this case, there are two distinct battleships. The first one is placed horizontally from (0,0) to (0,3), and the second one is placed vertically from (0,3) to (2,3). Thus, the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, iterate through each cell of the grid. For each 'X', check if it is the start of a new battleship by ensuring there are no other 'X' directly above or to the left of it. If it is, increment the battleship count.

### Initial Thoughts 💭
- We need to avoid counting the same battleship multiple times.
- Each battleship can only be counted once, either from the start of the row or the start of the column.
- By checking the adjacent cells (above and to the left), we can avoid double-counting parts of the same battleship.
{{< dots >}}
### Edge Cases 🌐
- If the board is empty (no rows or columns), the output should be 0.
- For large grids (up to 200x200), ensure the solution can handle the maximum input size efficiently.
- A grid where all cells are empty should return 0, as there are no battleships.
- The solution should work within the problem's constraints, with a maximum grid size of 200x200.
{{< dots >}}
## Code 💻
```cpp
int countBattleships(vector<vector<char>>& board) {
    if(board.empty() || board[0].empty()) return 0;
    int m = board.size(), n = board[0].size();
    int cnt = 0;
    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
 cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'); 

    }
    return cnt;
}
```

This code counts the number of battleships in a given board. Each battleship is represented by 'X', and it is considered a single unit if no other 'X' cells are adjacent horizontally or vertically.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int countBattleships(vector<vector<char>>& board) {
	```
	This line declares the `countBattleships` function, which takes a 2D vector of characters representing the board and returns an integer representing the number of battleships.

2. **Edge Case Handling**
	```cpp
	    if(board.empty() || board[0].empty()) return 0;
	```
	This checks if the board is empty or if the first row is empty. If either condition is true, it returns 0 as there are no battleships to count.

3. **Variable Initialization**
	```cpp
	    int m = board.size(), n = board[0].size();
	```
	Here, we initialize the variables `m` and `n` to represent the number of rows and columns in the board.

4. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	This initializes the `cnt` variable to keep track of the number of battleships found on the board.

5. **Loop Initialization**
	```cpp
	    for(int i = 0; i < m; i++)
	```
	This starts a loop to iterate over each row of the board.

6. **Loop Initialization**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	This starts a nested loop to iterate over each column within the current row.

7. **Condition Check**
	```cpp
	 cnt += (board[i][j] == 'X') && (i == 0 || board[i - 1][j] != 'X') && (j == 0 || board[i][j - 1] != 'X'); 
	```
	This line checks if the current cell is an 'X' (part of a battleship). It also ensures that the current cell is not part of a battleship that has already been counted (i.e., no adjacent 'X' cells to the left or above). If both conditions are true, it increments the `cnt` variable.

8. **Return Statement**
	```cpp
	    return cnt;
	```
	This returns the final count of battleships found on the board.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n), where m is the number of rows and n is the number of columns in the grid.
- **Average Case:** O(m * n), as we must inspect every cell in the grid.
- **Worst Case:** O(m * n), since we iterate through the entire grid once.

The time complexity is linear with respect to the size of the grid.

### Space Complexity 💾
- **Best Case:** O(1), since no additional space is required besides the input grid.
- **Worst Case:** O(1), as the solution uses only a constant amount of extra memory.

The space complexity is constant because we do not use any extra data structures that depend on the size of the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/battleships-in-a-board/description/)

---
{{< youtube gKhvVHd8ihI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
