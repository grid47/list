
+++
authors = ["grid47"]
title = "Leetcode 1391: Check if There is a Valid Path in a Grid"
date = "2024-06-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1391: Check if There is a Valid Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<vector<int>>> dir{    { { 0, 1}, { 0, -1} },
                       { { 1, 0}, {-1,  0} },
                       { { 0,-1}, { 1,  0} },
                       { { 0, 1}, { 1,  0} },
                       { {0, -1}, {-1,  0} },
                       { { 0, 1}, {-1,  0} },
                  };
    
    bool hasValidPath(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector(n, false));
        
        queue<vector<int>> q;
        q.push(vector<int>{0, 0});
        visited[0][0] = true;
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                vector<int> cur = q.front();
                q.pop();
                
                if(cur[0] == m - 1 && cur[1] == n - 1) return true;
                
                int num = grid[cur[0]][cur[1]];
                
                for(vector<int> go : dir[num - 1]) {
                    int x = cur[0] + go[0], y = cur[1] + go[1];
                    
                    if (x <  0 || y <  0 ||
                        x >= m || y >= n || visited[x][y])
                        continue;
                    
                    int ret = grid[x][y];
                    for(vector<int> rev : dir[ret - 1]) {
                        if((cur[0] == x + rev[0] && cur[1] == y + rev[1]) ||
                           (cur[1] == x + rev[0] && cur[0] == y + rev[1])) {
                            q.push(vector<int>{x, y});
                            visited[x][y] = true;
                        }
                    }   
                }
            }
            
        }
        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine if there exists a valid path from the top-left corner to the bottom-right corner of a grid. Each cell in the grid contains a number representing a type of tunnel that can connect to adjacent cells in specific directions. Our goal is to check if we can move from the starting cell (0,0) to the destination cell (m-1,n-1) by following the rules defined by the numbers in the cells.

### Approach

To solve this problem, we can use a breadth-first search (BFS) algorithm. The BFS will help us explore all possible paths from the starting position while checking if we can reach the destination. The key steps in our approach are:

1. **Define Directional Movement**: For each number in the grid, we define the possible movements it allows, as well as the movements required for the adjacent cell's type to connect properly.
2. **Initialize BFS**: We will use a queue to facilitate the BFS and a 2D vector to track visited cells.
3. **Explore the Grid**: As we dequeue the current position, we check all valid moves based on the current cell's value and see if we can continue to unvisited cells.
4. **Check Destination**: If we reach the bottom-right corner, we return true. If the queue is exhausted without finding a path, we return false.

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the provided C++ code:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class is defined, which encapsulates the solution method.

2. **Direction Initialization**:
   ```cpp
       vector<vector<vector<int>>> dir{    
           { { 0, 1}, { 0, -1} },
           { { 1, 0}, {-1,  0} },
           { { 0,-1}, { 1,  0} },
           { { 0, 1}, { 1,  0} },
           { {0, -1}, {-1,  0} },
           { { 0, 1}, {-1,  0} },
       };
   ```
   - A 3D vector `dir` is initialized, which maps each cell type to its possible movement directions. Each inner vector corresponds to the directions for a specific cell type (1 through 6).

3. **Main Function Definition**:
   ```cpp
       bool hasValidPath(vector<vector<int>>& grid) {
   ```
   - The method `hasValidPath` takes a 2D vector `grid` as input and returns a boolean indicating if a valid path exists.

4. **Variable Initialization**:
   ```cpp
           int m = grid.size(), n = grid[0].size();
           vector<vector<bool>> visited(m, vector(n, false));
           queue<vector<int>> q;
           q.push(vector<int>{0, 0});
           visited[0][0] = true;
   ```
   - The dimensions of the grid are stored in `m` and `n`.
   - A 2D vector `visited` is initialized to track whether each cell has been visited.
   - A queue `q` is initialized for BFS, starting with the top-left cell (0, 0).

5. **BFS Loop**:
   ```cpp
           while(!q.empty()) {
               int sz = q.size();
               for(int i = 0; i < sz; i++) {
                   vector<int> cur = q.front();
                   q.pop();
   ```
   - The BFS continues until there are no more cells to explore.
   - The size of the queue `sz` is stored to process all current cells before moving to the next level.

6. **Destination Check**:
   ```cpp
                   if(cur[0] == m - 1 && cur[1] == n - 1) return true;
   ```
   - If the current cell is the bottom-right corner, we return `true`, indicating a valid path is found.

7. **Processing Current Cell**:
   ```cpp
                   int num = grid[cur[0]][cur[1]];
   ```
   - The current cell's type is stored in `num`, which is used to determine possible movements.

8. **Exploring Neighbors**:
   ```cpp
                   for(vector<int> go : dir[num - 1]) {
                       int x = cur[0] + go[0], y = cur[1] + go[1];
                       
                       if (x <  0 || y < 0 || x >= m || y >= n || visited[x][y])
                           continue;
   ```
   - For each possible move defined in `dir`, the next cell `(x, y)` is calculated.
   - We check if `(x, y)` is within bounds and has not been visited.

9. **Validating Movement**:
   ```cpp
                       int ret = grid[x][y];
                       for(vector<int> rev : dir[ret - 1]) {
                           if((cur[0] == x + rev[0] && cur[1] == y + rev[1]) ||
                              (cur[1] == x + rev[0] && cur[0] == y + rev[1])) {
                               q.push(vector<int>{x, y});
                               visited[x][y] = true;
                           }
                       }   
                   }
   ```
   - If the next cell `(x, y)` is valid, we retrieve its type `ret` and check if the movement is valid in reverse.
   - If the reverse movement is possible, we enqueue the cell and mark it as visited.

10. **Returning Result**:
    ```cpp
           }
           return false;
       }
   };
   ```
    - If the BFS completes without finding the destination, `false` is returned.

### Complexity

- **Time Complexity**:
  - The time complexity is \( O(m \times n) \) since each cell can be visited once and we explore all possible movements.

- **Space Complexity**:
  - The space complexity is also \( O(m \times n) \) for the `visited` vector and the queue used in BFS.

### Conclusion

This code provides a clear and efficient solution to the problem of finding a valid path in a grid defined by tunnel types. The use of BFS ensures that all possible paths are explored systematically, and the pre-defined directional movements based on cell types allow for flexible navigation through the grid.

Key points include:
- Understanding how to model the problem using BFS.
- Efficiently handling cell movements by mapping cell types to their possible directions.
- Properly tracking visited cells to avoid infinite loops.

By mastering such techniques, developers can tackle various pathfinding and grid traversal problems, a common requirement in algorithmic challenges and real-world applications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
