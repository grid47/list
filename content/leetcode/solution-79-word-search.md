
+++
authors = ["grid47"]
title = "Leetcode 79: Word Search"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 79: Word Search in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Backtracking","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/79.webp"
youtube = "pfiQ_PS1g8E"
youtube_upload_date="2021-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/pfiQ_PS1g8E/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/79.webp" 
    alt="A glowing word appearing in a soft matrix of letters, slowly highlighting itself."
    caption="Solution to LeetCode 79: Word Search Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a 2D grid `board` containing characters and a string `word`. The task is to determine whether the given word can be formed by starting at any cell in the grid and moving to adjacent cells, which are horizontally or vertically neighboring. The same cell cannot be reused in forming the word.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D grid `board` of characters and a string `word`.
- **Example:** `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"`
- **Constraints:**
	- 1 <= m, n <= 6
	- 1 <= word.length <= 15
	- board and word consist of only uppercase and lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the word exists in the grid, otherwise return `false`.
- **Example:** `true`
- **Constraints:**
	- The solution should return true if the word can be formed from the grid, and false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** To check if a word can be formed by navigating the grid's adjacent cells.

- Iterate over each cell in the grid.
- For each cell, perform a Depth-First Search (DFS) to explore all possible paths that form the word, marking cells as visited.
- If a complete path that forms the word is found, return true; otherwise, continue the search.
{{< dots >}}
### Problem Assumptions ✅
- The grid and word consist only of valid English alphabetic characters.
{{< dots >}}
## Examples 🧩
- **Input:** `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"`  \
  **Explanation:** Starting at the top-left corner, the word 'ABCCED' can be formed by moving through adjacent cells.

- **Input:** `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"`  \
  **Explanation:** The word 'SEE' can be formed by starting from the bottom-left corner.

- **Input:** `board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"`  \
  **Explanation:** The word 'ABCB' cannot be formed because the letter 'B' would need to be reused.

{{< dots >}}
## Approach 🚀
The approach uses Depth-First Search (DFS) to explore possible paths for forming the word, pruning the search if a path leads to an invalid state.

### Initial Thoughts 💭
- DFS is an ideal approach for exploring all paths in a grid.
- By using a visited matrix to mark cells already used, we can prevent revisiting cells.
{{< dots >}}
### Edge Cases 🌐
- If the grid is empty or the word length is 0, the result should be false.
- Ensure the solution works efficiently for the maximum grid size (6x6).
- Handle cases where the word contains repeated characters or if the grid contains the same character multiple times.
- Make sure the word does not exceed the maximum length of 15.
{{< dots >}}
## Code 💻
```cpp
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(board, visited, i, j, word, 0)) {
                return true;
            }
        }
    }
    return false;
}

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int idx) {
    if (idx == word.size()) {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
        return false;
    }

    visited[i][j] = true;
    bool found = dfs(board, visited, i - 1, j, word, idx + 1) ||
                 dfs(board, visited, i + 1, j, word, idx + 1) ||
                 dfs(board, visited, i, j - 1, word, idx + 1) ||
                 dfs(board, visited, i, j + 1, word, idx + 1);
    visited[i][j] = false;
    return found;
}
```

This code checks if a given word exists in a 2D grid of characters using a Depth-First Search (DFS) approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool exist(vector<vector<char>>& board, string word) {
	```
	Declares a function `exist` that takes a 2D character grid `board` and a string `word` as input and returns a boolean indicating whether the word exists in the grid.

2. **Variable Initialization**
	```cpp
	    int m = board.size(), n = board[0].size();
	```
	Stores the dimensions of the board in `m` and `n`.

3. **Variable Initialization**
	```cpp
	    vector<vector<bool>> visited(m, vector<bool>(n));
	```
	Initializes a 2D boolean array `visited` to track visited cells during DFS.

4. **Nested Loops**
	```cpp
	    for (int i = 0; i < m; ++i) {
	        for (int j = 0; j < n; ++j) {
	```
	Iterates through each cell in the grid.

5. **Recursive Call**
	```cpp
	            if (dfs(board, visited, i, j, word, 0)) {
	                return true;
	            }
	        }
	    }
	```
	Calls the `dfs` function to start the DFS from the current cell and returns `true` if the word is found.

6. **Return**
	```cpp
	    return false;
	```
	Returns `false` if the word is not found after checking all cells.

7. **Function Declaration**
	```cpp
	bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int idx) {
	```
	Declares a recursive `dfs` function to perform DFS from a given cell.

8. **Base Case**
	```cpp
	    if (idx == word.size()) {
	        return true;
	    }
	```
	Base case: If the current index `idx` reaches the end of the word, the word is found.

9. **Conditional**
	```cpp
	    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
	        return false;
	    }
	```
	Checks if the current cell is out of bounds, already visited, or doesn't match the current character in the word.

10. **Variable Assignment**
	```cpp
	    visited[i][j] = true;
	```
	Marks the current cell as visited.

11. **Variable Initialization**
	```cpp
	    bool found = false;
	```
	Initializes a boolean variable `found` to track if the word is found in any of the four directions.

12. **Recursive Call**
	```cpp
	    found = dfs(board, visited, i - 1, j, word, idx + 1) ||
	                 dfs(board, visited, i + 1, j, word, idx + 1) ||
	                 dfs(board, visited, i, j - 1, word, idx + 1) ||
	                 dfs(board, visited, i, j + 1, word, idx + 1);
	```
	Recursively calls the `dfs` function to explore the four neighboring cells.

13. **Variable Assignment**
	```cpp
	    visited[i][j] = false;
	```
	Unmarks the current cell as visited after exploring its neighbors.

14. **Return**
	```cpp
	    return found;
	```
	Returns `true` if the word is found in any of the four directions, otherwise `false`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m*n)
- **Average Case:** O(3^(len(word)))
- **Worst Case:** O(3^(len(word)))

The worst-case time complexity is proportional to the maximum number of recursive DFS calls, which is bounded by the length of the word and the grid size.

### Space Complexity 💾
- **Best Case:** O(m*n)
- **Worst Case:** O(m*n)

The space complexity is dominated by the recursion stack and the visited matrix, both of which are proportional to the grid size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/word-search/description/)

---
{{< youtube pfiQ_PS1g8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
