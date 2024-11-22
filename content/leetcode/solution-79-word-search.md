
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
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    int m, n;
    string w;
    bool exist(vector<vector<char>>& board, string word) {
        this->w = word;
        this->grid = board;
        this->m = board.size();
        this->n = board[0].size();

        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(w.size() == 1 && grid[i][j] == w[0])
                return true;
            else {
                vis.resize(m, vector<bool>(n, false));
                if(dfs(i, j, 0))
                return true;
            }

        return false;
    }
    
    bool dfs(int i, int j, int idx) {
        if(idx == w.size()) return true;
        if(grid[i][j] != w[idx] || vis[i][j]) {
            return false;
        }
        vis[i][j] = true;
        bool ans = false;
        
            if(i > 0) ans |= dfs(i - 1, j, idx + 1);
            if(j > 0) ans |= dfs(i, j - 1, idx + 1);
        if(i < m - 1) ans |= dfs(i + 1, j, idx + 1);
        if(j < n - 1) ans |= dfs(i, j + 1, idx + 1);     

        vis[i][j] = false;
        return ans;
    }
};
{{< /highlight >}}
---

### 🏷️ **Problem Statement**

The goal is to determine whether a given word can be formed by traversing adjacent cells in a 2D grid of characters. Adjacent cells are those that share a side (up, down, left, or right). Each cell may only be used once per word search.

The function should return `true` if the word can be constructed from adjacent cells in the grid, otherwise `false`.

#### Example:
- **Input:** `board = [["A","B","C","E"], ["S","F","C","S"], ["A","D","E","E"]], word = "ABCCED"`
- **Output:** `true`

---

### 🧠 **Approach**

The solution uses **Depth-First Search (DFS)** combined with **backtracking** to explore all possible paths that may form the word. The approach proceeds as follows:

1. **DFS Traversal:**
   The algorithm starts by trying to match the first character of the word with each cell in the grid. Once a match is found, it recursively checks the neighboring cells to find the next character of the word. This continues until the entire word is matched or no further match can be made.

2. **Backtracking:**
   While traversing the grid, the algorithm marks cells as visited to avoid revisiting them in the current word search. If a potential path does not lead to a solution, the algorithm backtracks by unmarking the visited cell and tries another path.

3. **Pruning and Optimization:**
   - If a cell doesn’t match the current character or has already been visited, the search backtracks immediately.
   - If the word is found at any point, the search terminates early and returns `true`.

4. **Edge Case Handling:**
   - If the word is a single character, the algorithm checks if any cell contains that character.
   - If the grid dimensions are smaller than the length of the word, the search terminates early.

---

### 📝 **Code Breakdown**

#### Step 1: Class Definition and Member Variables
```cpp
class Solution {
public:
    vector<vector<char>> grid;    // The grid to search for the word
    vector<vector<bool>> vis;     // Visited cells to avoid revisiting in DFS
    int m, n;                     // Dimensions of the grid
    string w;                     // The word to search for
```
- `grid`: A 2D vector that stores the grid of characters.
- `vis`: A 2D boolean vector used to mark visited cells during DFS.
- `m, n`: The number of rows and columns of the grid.
- `w`: The target word to be searched.

#### Step 2: `exist` Method - Main Function to Check Word Existence
```cpp
bool exist(vector<vector<char>>& board, string word) {
    this->w = word;          // Store the word to search for
    this->grid = board;      // Store the input grid
    this->m = board.size();  // Number of rows in the grid
    this->n = board[0].size(); // Number of columns in the grid

    // Try to start the DFS from every cell in the grid
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            // Special case: if the word is a single character
            if (w.size() == 1 && grid[i][j] == w[0])
                return true;
            else {
                vis.resize(m, vector<bool>(n, false)); // Reset the visited matrix
                if (dfs(i, j, 0)) // Start DFS from cell (i, j)
                    return true;  // If found, return true
            }

    return false; // Return false if no path is found
}
```
- Initializes necessary member variables (`w`, `grid`, `m`, and `n`).
- Attempts to start the DFS search from every grid cell.
- If the word length is 1, it checks if any cell contains that character.
- For longer words, the DFS search is triggered, and the result is returned based on the findings.

#### Step 3: DFS Method - Recursive Depth-First Search
```cpp
bool dfs(int i, int j, int idx) {
    if (idx == w.size()) return true; // If the entire word is matched, return true
    if (grid[i][j] != w[idx] || vis[i][j]) {
        return false; // If current cell doesn't match the character or is already visited, return false
    }

    vis[i][j] = true; // Mark the current cell as visited
    bool ans = false;

    // Explore all 4 neighboring cells
    if (i > 0) ans |= dfs(i - 1, j, idx + 1);  // Explore top cell
    if (j > 0) ans |= dfs(i, j - 1, idx + 1);  // Explore left cell
    if (i < m - 1) ans |= dfs(i + 1, j, idx + 1); // Explore bottom cell
    if (j < n - 1) ans |= dfs(i, j + 1, idx + 1); // Explore right cell

    vis[i][j] = false; // Unmark the current cell (backtrack)
    return ans; // Return true if any path found, otherwise false
}
```
- The `dfs` method recursively explores neighboring cells to match characters of the word starting from `(i, j)`.
- If a cell matches the current character and hasn't been visited, it marks the cell as visited and explores its neighbors.
- The function returns `true` if the word is found, otherwise `false`.

---

### 🧮 **Complexity Analysis**

#### Time Complexity:
The time complexity of the algorithm is **O(m * n * 4^L)**, where `m` and `n` are the dimensions of the grid, and `L` is the length of the word.

- Each recursive DFS step explores up to 4 directions (top, left, bottom, right). In the worst case, for each of the `m * n` starting cells, the search explores up to `4^L` possibilities (since each character of the word could lead to 4 possible next cells).
- Thus, the total time complexity is **O(m * n * 4^L)**.

#### Space Complexity:
The space complexity is **O(m * n)** due to:
- The `vis` matrix used to track visited cells during the DFS traversal.
- The recursion stack, which can grow to a maximum depth of `L` (the length of the word), but the dominant factor is the grid size.

Therefore, the overall space complexity is **O(m * n)**.

---

### 🎯 **Conclusion**

This approach effectively solves the problem of finding a word in a 2D grid by using **DFS (Depth-First Search)** and **backtracking**. It explores all possible paths to match the word's characters while ensuring that cells are not revisited during the search. The algorithm is efficient for moderate-sized grids and word lengths, though its time complexity can grow exponentially with larger grids and longer words. The space complexity is dominated by the size of the grid and the recursion stack.

[`Link to LeetCode Lab`](https://leetcode.com/problems/word-search/description/)

---
{{< youtube pfiQ_PS1g8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
