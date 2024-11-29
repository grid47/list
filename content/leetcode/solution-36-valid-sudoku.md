
+++
authors = ["grid47"]
title = "Leetcode 36: Valid Sudoku"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 36: Valid Sudoku in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.webp"
youtube = "TjFXEUCMqI8"
youtube_upload_date="2021-07-05"
youtube_thumbnail="https://i.ytimg.com/vi/TjFXEUCMqI8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/36.webp" 
    alt="A soft grid of numbers and symbols, gently highlighting valid sequences."
    caption="Solution to LeetCode 36: Valid Sudoku Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Determine if a 9x9 Sudoku board is valid. A valid Sudoku board follows three rules: Each row, column, and 3x3 sub-box must contain the digits 1-9 without repetition. Only the filled cells need to be validated.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 9x9 grid representing the Sudoku board. Cells contain digits '1'-'9' or '.' for empty cells.
- **Example:** `Input: board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], ...]`
- **Constraints:**
	- board.length == 9
	- board[i].length == 9
	- Each cell is a digit from '1' to '9' or '.'

{{< dots >}}
### Output Specifications 📤
- **Output:** Return 'true' if the board is valid according to Sudoku rules, otherwise return 'false'.
- **Example:** `Output: true`
- **Constraints:**
	- Return a boolean value indicating whether the board is valid or not.

{{< dots >}}
### Core Logic 🔍
**Goal:** To validate the Sudoku board based on the three conditions: unique digits in rows, columns, and sub-boxes.

- Iterate through each cell of the board.
- For each non-empty cell, check if the value already appears in the same row, column, or 3x3 sub-box.
- Use a set or map to track previously encountered numbers in each row, column, and sub-box.
- Return 'false' if a repeated number is found, otherwise return 'true' after checking all cells.
{{< dots >}}
### Problem Assumptions ✅
- The board is a valid 9x9 grid.
- Only the filled cells are validated.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], ...]`  \
  **Explanation:** The board is valid as no rows, columns, or sub-boxes have repeating digits. All filled cells follow Sudoku rules.

- **Input:** `Input: board = [["8", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], ...]`  \
  **Explanation:** The board is invalid because there are two '8's in the top-left 3x3 sub-box.

{{< dots >}}
## Approach 🚀
Use a set or map to track the digits that have appeared in each row, column, and 3x3 sub-box to ensure there are no duplicates.

### Initial Thoughts 💭
- We can use sets or maps to efficiently track the digits we encounter in rows, columns, and sub-boxes.
- Using a single iteration through the board and checking each non-empty cell will ensure an efficient solution.
{{< dots >}}
### Edge Cases 🌐
- The board may contain empty cells represented by '.' which should be ignored during validation.
- N/A, as the board size is fixed at 9x9.
- Consider cases where all rows, columns, and sub-boxes have exactly one number or are filled with duplicates.
- Ensure the board is always 9x9 as per the constraints.
{{< dots >}}
## Code 💻
```cpp
bool isValidSudoku(vector<vector<char>>& board) {
    map<string, bool> ma;
    
    for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++) {
        if(board[i][j] != '.') {
            string key = "(";
                key+=board[i][j];
            key+=")";
            if(ma.count(to_string(i)+key)) return false;
            else ma[to_string(i)+key] = true;
            // cout << to_string(i)+key;
            if(ma.count(key+to_string(j))) return false;
            else ma[key+to_string(j)] = true;
            // cout << key+to_string(j);
            int x = i / 3, y = j / 3;
            if(ma.count(to_string(x)+ key+ to_string(y))) return false;
            else ma[to_string(x)+ key+ to_string(y)] = true;
            // cout<< to_string(i)+ key+ to_string(j);
        }
    }
        return true;
}
```

This code checks if a given Sudoku board is valid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isValidSudoku(vector<vector<char>>& board) {
	```
	This line declares a function named 'isValidSudoku' that takes a 2D vector 'board' representing the Sudoku board as input and returns a boolean indicating whether the board is valid.

2. **Map Initialization**
	```cpp
	    map<string, bool> ma;
	```
	This line initializes an empty map 'ma' to store information about the numbers seen in each row, column, and 3x3 sub-grid.

3. **Nested Loops**
	```cpp
	    for(int i = 0; i < 9; i++)
	    for(int j = 0; j < 9; j++) {
	```
	This nested loop iterates over each cell of the Sudoku board.

4. **Conditional Check**
	```cpp
	        if(board[i][j] != '.') {
	```
	This line checks if the current cell is not empty.

5. **String Manipulation**
	```cpp
	            string key = "(";
	                key+=board[i][j];
	            key+=")";
	```
	This block creates a unique key for the current number, row, or column by concatenating the number with the row or column index enclosed in parentheses.

6. **Map Operations**
	```cpp
	            if(ma.count(to_string(i)+key)) return false;
	```
	This line checks if the current number has already been seen in the current row. If so, it means the Sudoku is invalid, and the function returns false.

7. **Map Operations**
	```cpp
	            else ma[to_string(i)+key] = true;
	```
	If the number hasn't been seen in the current row, it's added to the map with a key representing the row and number.

8. **Map Operations**
	```cpp
	            if(ma.count(key+to_string(j))) return false;
	```
	This line checks if the current number has already been seen in the current column. If so, it means the Sudoku is invalid, and the function returns false.

9. **Map Operations**
	```cpp
	            else ma[key+to_string(j)] = true;
	```
	If the number hasn't been seen in the current column, it's added to the map with a key representing the column and number.

10. **Calculation**
	```cpp
	            int x = i / 3, y = j / 3;
	```
	This line calculates the indices of the 3x3 sub-grid to which the current cell belongs.

11. **Map Operations**
	```cpp
	            if(ma.count(to_string(x)+ key+ to_string(y))) return false;
	```
	This line checks if the current number has already been seen in the current 3x3 sub-grid. If so, it means the Sudoku is invalid, and the function returns false.

12. **Map Operations**
	```cpp
	            else ma[to_string(x)+ key+ to_string(y)] = true;
	```
	If the number hasn't been seen in the current 3x3 sub-grid, it's added to the map with a key representing the sub-grid indices and number.

13. **Return**
	```cpp
	        return true;
	```
	If the loop completes without finding any violations, the function returns true, indicating that the Sudoku board is valid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Time complexity is O(n^2) because we are iterating through a 9x9 grid.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the use of sets to track digits for rows, columns, and sub-boxes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/valid-sudoku/description/)

---
{{< youtube TjFXEUCMqI8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
