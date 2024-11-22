
+++
authors = ["grid47"]
title = "Leetcode 934: Shortest Bridge"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 934: Shortest Bridge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1RZijG2c1CA"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1RZijG2c1CA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        bool flag = false;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dfs(i, j, q, grid);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        int step = 0;
        int dir[5] = {0,1,0,-1,0};
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int x = p.first + dir[i], y = p.second + dir[i+1];
                    if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
                        continue;
                    if(grid[x][y] == 1) return step;
                    q.push({x, y});
                    grid[x][y] = -1;
                }
            }
            step++;
        }
        return -1;
    }
    
    void dfs(int x, int y, queue<pair<int, int>> &q, vector<vector<int>> &grid) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
            return;
        q.push(make_pair(x, y));
        grid[x][y] = -1;
        dfs(x + 1, y, q, grid);
        dfs(x - 1, y, q, grid);
        dfs(x, y + 1, q, grid);
        dfs(x, y - 1, q, grid);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves finding the shortest bridge between two islands in a 2D grid. Each cell in the grid can be:
- `1` representing land.
- `0` representing water.

The grid contains two islands, and your task is to connect these islands by flipping the fewest number of `0`s to `1`s, i.e., build the shortest bridge. The bridge should connect the two islands through water cells, while the bridge itself is made of the water cells turned into land. You are required to return the minimum number of flips needed to connect the two islands.

### Approach

This problem is typically solved by employing a **Breadth-First Search (BFS)** algorithm in conjunction with **Depth-First Search (DFS)** to identify the two islands and find the shortest path to connect them.

#### Step-by-Step Explanation:

1. **Identifying the First Island using DFS**:
   - First, we need to find one of the islands. We can do this by iterating through the grid and performing a DFS search from the first `1` we encounter. This will allow us to mark all the land cells of this island and store their coordinates in a queue for the next step.
   - During the DFS traversal, we mark all the cells of the first island as `-1` to prevent visiting them again, and we store the coordinates of these cells in a queue. These coordinates will later serve as the starting points for the BFS.

2. **Expanding the Search using BFS**:
   - Once the first island is identified, the next step is to start the BFS from the coordinates of the first island's land cells. The BFS will explore the neighboring water cells (`0`s) and gradually expand the search in all four directions (up, down, left, right).
   - The BFS continues until it encounters the second island's land cells. As soon as the second island is reached, the BFS will return the number of water cells (`0`s) traversed, which corresponds to the number of flips needed to connect the two islands.

3. **Return the Result**:
   - The result is the number of steps taken by the BFS to connect the two islands, which is the minimal number of flips required to build the bridge.

### Code Breakdown (Step by Step)

1. **DFS for the First Island**:
   We start by using DFS to identify and mark the first island in the grid. The DFS function `dfs(x, y)` explores all connected `1`s (land cells) and marks them as `-1` to prevent revisiting them.

   ```cpp
   void dfs(int x, int y, queue<pair<int, int>>& q, vector<vector<int>>& grid) {
       if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != 1)
           return;
       q.push(make_pair(x, y));  // Add land cell to the queue for BFS
       grid[x][y] = -1;  // Mark the land cell as visited
       dfs(x + 1, y, q, grid);  // Explore down
       dfs(x - 1, y, q, grid);  // Explore up
       dfs(x, y + 1, q, grid);  // Explore right
       dfs(x, y - 1, q, grid);  // Explore left
   }
   ```

   - This function is invoked when we first find a `1` (land) during the grid traversal.
   - We then mark all land cells connected to this one, effectively identifying the first island and storing its cells in a queue.

2. **BFS to Find the Shortest Bridge**:
   After marking the first island, we use BFS to find the shortest path to the second island. BFS is particularly suited for finding the shortest path in an unweighted grid like this.

   ```cpp
   int step = 0;
   int dir[5] = {0,1,0,-1,0};  // Direction vectors for up, right, down, and left
   while(!q.empty()) {
       int sz = q.size();  // Get the number of elements in the queue
       for(int i = 0; i < sz; i++) {
           pair<int, int> p = q.front();
           q.pop();  // Get the next land cell from the queue
           for(int i = 0; i < 4; i++) {
               int x = p.first + dir[i], y = p.second + dir[i + 1];
               // Check if the new position is valid and within bounds
               if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1)
                   continue;  // Skip invalid positions or already visited cells
               if(grid[x][y] == 1) return step;  // If we find land of the second island, return the step count
               q.push({x, y});  // Add the water cell to the queue for further exploration
               grid[x][y] = -1;  // Mark the water cell as visited
           }
       }
       step++;  // Increase the number of steps after expanding one level
   }
   ```

   - The BFS starts by processing the first island’s land cells stored in the queue. For each cell, it explores the adjacent cells (up, down, left, right).
   - If an adjacent cell is water (`0`), it is added to the queue, and its value is marked as visited by setting it to `-1`.
   - If an adjacent cell is land (`1`), the BFS terminates, and the step count is returned.

3. **Main Function**:
   The `shortestBridge()` function initializes the BFS process after identifying the first island using DFS. It sets up the queue and handles the BFS iterations.

   ```cpp
   int shortestBridge(vector<vector<int>>& grid) {
       queue<pair<int, int>> q;
       bool flag = false;
       int m = grid.size(), n = grid[0].size();
       for(int i = 0; i < m; i++) {
           for(int j = 0; j < n; j++) {
               if (grid[i][j]) {
                   dfs(i, j, q, grid);  // Find the first island and mark it
                   flag = true;
                   break;
               }
           }
           if (flag) break;
       }

       return bfs(grid, q);  // Perform BFS to find the shortest bridge
   }
   ```

   - The function starts by iterating over the grid to find the first `1` (land). Once found, DFS is invoked to mark all the land cells of the first island.
   - After identifying the first island, BFS is used to find the shortest path to the second island, and the result is returned.

### Time Complexity

- **DFS**: The DFS function visits every cell of the grid exactly once, so its time complexity is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the grid.
- **BFS**: Similarly, the BFS function also processes each cell of the grid exactly once, making its time complexity **O(m * n)**.

Thus, the overall time complexity is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the grid.

### Space Complexity

- The space complexity is **O(m * n)** because the space used by the queue in the BFS can grow to the size of the grid in the worst case.
- Additionally, the DFS modifies the grid in place, which does not require extra space.

Therefore, the space complexity is **O(m * n)** due to the storage used by the grid and the queue.

### Conclusion

This solution efficiently solves the problem of finding the shortest bridge between two islands in a 2D grid using a combination of **DFS** to identify the first island and **BFS** to find the shortest path. The use of BFS ensures that the minimal number of flips is computed in optimal time, and by modifying the grid in place, we minimize space complexity. This approach ensures that the problem is solved efficiently, even for large grids.

[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-bridge/description/)

---
{{< youtube 1RZijG2c1CA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
