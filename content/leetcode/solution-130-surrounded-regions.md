
+++
authors = ["grid47"]
title = "Leetcode 130: Surrounded Regions"
date = "2024-10-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 130: Surrounded Regions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/130.webp"
youtube = "9z2BunfoZ5Y"
youtube_upload_date="2021-08-16"
youtube_thumbnail="https://i.ytimg.com/vi/9z2BunfoZ5Y/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/130.webp" 
    alt="A grid of cells gently surrounded by a calming border of light, with certain areas being 'captured."
    caption="Solution to LeetCode 130: Surrounded Regions Problem"
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
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(i == 0 || j == 0 || i == m - 1|| j == n -1)
                if(board[i][j] == 'O')
                    dfs(board, i, j);
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == '1')
                board[i][j] = 'O';
        
    }
    
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i == grid.size() || 
           j == grid[0].size() || grid[i][j] != 'O')
            return;
        grid[i][j] = '1';
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }
};
{{< /highlight >}}
---

### 💡 **Surrounded Regions Problem: Protecting the Boundary**

The "Surrounded Regions" problem is a fascinating challenge where we need to modify a board of characters represented by 'X' and 'O'. The goal is to change all 'O' characters that are **completely surrounded** by 'X' characters into 'X'. However, any 'O' that is **connected to the boundary** should remain unchanged. This problem is a great example of how we can use depth-first search (DFS) to traverse and modify connected regions efficiently.

#### **Problem Statement**
Given a board represented by a 2D grid of characters, where 'O' represents regions of interest and 'X' represents boundary or filled areas, we need to:
- Modify the board such that any 'O' that is **completely surrounded** by 'X' characters should be changed to 'X'.
- Any 'O' that is connected to the **boundary** (either directly or indirectly) should remain unchanged.

### **Example**

Given the following board:

```
X X X X
X O O X
X X O X
X O X X
```

After applying the solution, the board should be modified as follows:

```
X X X X
X X X X
X X X X
X O X X
```

---

### 🛠️ **Approach: Using Depth-First Search (DFS)**

To solve this problem efficiently, we'll utilize **DFS** to explore and modify the board. The idea is to:
1. **Identify Boundary 'O's**: Start by identifying all 'O' regions connected to the boundary, as these should remain unchanged.
2. **Mark Safe 'O' Regions**: Use DFS to mark all 'O' regions connected to the boundary as safe (we temporarily mark them with a different character like '1').
3. **Flip Surrounded 'O's to 'X'**: After marking all safe regions, flip all unmarked 'O's to 'X', as they are surrounded by 'X'. Finally, restore the safe regions from '1' back to 'O'.

---

### ✨ **Code Breakdown**

#### 1️⃣ **Solve Function**
```cpp
void solve(vector<vector<char>>& board)
```
This function processes the entire board, marking the boundary-connected 'O' regions and flipping the surrounded 'O' regions.

1. **Initialize Board Dimensions**:
   ```cpp
   int m = board.size(), n = board[0].size();
   ```
   Here, `m` represents the number of rows, and `n` represents the number of columns in the grid.

2. **Mark Boundary-Connected 'O' Regions**:
   ```cpp
   for(int i = 0; i < m; i++)
   for(int j = 0; j < n; j++)
       if(i == 0 || j == 0 || i == m - 1 || j == n - 1)
           if(board[i][j] == 'O')
               dfs(board, i, j);
   ```
   This loop checks all cells in the first and last rows and columns (the boundaries). If an 'O' is found, we initiate DFS to explore and mark all connected 'O' regions.

3. **Flip Surrounded 'O' Regions**:
   ```cpp
   for(int i = 0; i < m; i++)
   for(int j = 0; j < n; j++)
       if(board[i][j] == 'O')
           board[i][j] = 'X';
       else if(board[i][j] == '1')
           board[i][j] = 'O';
   ```
   After marking boundary-connected regions, this loop traverses the entire board:
   - Any 'O' that is not marked as '1' (i.e., surrounded) is flipped to 'X'.
   - Any cell marked as '1' (connected to the boundary) is restored to 'O'.

#### 2️⃣ **DFS Function**
```cpp
void dfs(vector<vector<char>> &grid, int i, int j) {
    if(i < 0 || j < 0 || i == grid.size() || 
       j == grid[0].size() || grid[i][j] != 'O')
        return;
    grid[i][j] = '1';
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
}
```
- The `dfs` function recursively explores all connected 'O' cells from a given cell `(i, j)`.
- If an 'O' is found, it is marked as '1' to indicate it is part of a safe region connected to the boundary.
- The DFS continues exploring in four directions (up, down, left, right) until no more connected 'O' cells are found.

---

### 🔍 **Time and Space Complexity**

- **Time Complexity**: `O(m * n)`
  - The DFS will visit each 'O' cell at most once. Since we perform DFS for all cells on the boundary and then process the entire board, the time complexity is proportional to the total number of cells (`m * n`), where `m` is the number of rows and `n` is the number of columns.

- **Space Complexity**: `O(m * n)`
  - The recursion stack in the DFS function can be as deep as the number of 'O' cells connected to the boundary. In the worst case, the space complexity is proportional to the number of cells in the grid (`m * n`), due to the depth of the recursion stack.

---

### 🧑‍💻 **Example Walkthrough**

Let’s walk through the example with the board:

```
X X X X
X O O X
X X O X
X O X X
```

1. **Initial Board**:
   - The boundary cells are checked, and DFS is initiated from boundary 'O's at `(1, 1)`, `(1, 2)`, and `(3, 1)`.
2. **DFS Marks Boundary Connected Regions**:
   - The 'O' at `(1, 1)` is connected to `(1, 2)` and `(3, 1)`. These are marked as '1'.
3. **Final Board**:
   - All other 'O' cells not connected to the boundary are surrounded by 'X' and are flipped.
   
   The final modified board is:

   ```
   X X X X
   X X X X
   X X X X
   X O X X
   ```

---

### 🏁 **Conclusion**

This solution effectively handles the "Surrounded Regions" problem by utilizing **DFS** to explore and mark the regions connected to the boundary. By marking the safe regions and flipping only the surrounded regions, we ensure optimal performance while maintaining clarity in the solution. With a time complexity of `O(m * n)` and a space complexity of `O(m * n)`, this approach is both efficient and suitable for large boards.

Keep practicing these techniques, and you’ll get better at identifying optimal solutions for different problems! Keep going, you’ve got this! 💪✨

[`Link to LeetCode Lab`](https://leetcode.com/problems/surrounded-regions/description/)

---
{{< youtube 9z2BunfoZ5Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
