
+++
authors = ["grid47"]
title = "Leetcode 2812: Find the Safest Path in a Grid"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2812: Find the Safest Path in a Grid in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-5mQcNiVWTs"
youtube_upload_date="2024-05-15"
youtube_thumbnail="https://i.ytimg.com/vi/-5mQcNiVWTs/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& g) {
    queue<array<int, 2>> q;
    int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (g[i][j])
                q.push({i, j});
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
                g[x][y] = g[i][j] + 1;
                q.push({x, y});
            }
        }
    }
    priority_queue<array<int, 3>> pq;
    pq.push({g[0][0], 0, 0});
    while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
        auto [sf, i, j] = pq.top(); pq.pop();
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d], y = j + dir[d + 1];
            if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
                pq.push({min(sf, g[x][y]), x, y});
                g[x][y] *= -1; 
            }
        }
    }
    return pq.top()[0] - 1;
}
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a square grid `g` of size `n x n` where each cell can either be:
- `0`, representing an empty cell, or
- `1`, representing a cell containing an obstacle.

The task is to compute the **maximum safeness factor** for the top-left to bottom-right path, which is defined as the minimum number of steps needed to traverse from the top-left corner to the bottom-right corner. The grid represents a map, where obstacles reduce the available path options. You are asked to find the path that maximizes the safeness factor (the minimum distance to an obstacle) while traveling along the grid.

### Approach

The solution can be broken down into two primary phases:
1. **Flood Fill (BFS)**: In the first phase, we will calculate the **minimum distance to the nearest obstacle** for every empty cell in the grid. This is accomplished using a multi-source breadth-first search (BFS), where all obstacle cells are treated as the starting points, and we propagate distances from these points to every adjacent empty cell.
  
2. **Dijkstra-like Algorithm for Safeness Factor**: After calculating the distances in the previous phase, we will employ a modified Dijkstra algorithm. Here, we treat each cell as a node and aim to find the safest path from the top-left corner to the bottom-right corner. The goal is to maximize the safeness factor along the path, which corresponds to the minimum distance to an obstacle encountered along that path.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   queue<array<int, 2>> q;
   int dir[5] = {1, 0, -1, 0, 1}, n = g.size();
   ```
   - A `queue` is initialized to perform a BFS for the first phase. We will store the coordinates of cells and their corresponding distances to the nearest obstacle.
   - The `dir` array represents the four possible movement directions: down, right, up, and left (clockwise).
   - `n` stores the size of the grid (`n x n`), where `n` is the number of rows or columns.

2. **Multi-source BFS to Calculate Minimum Distances**:
   ```cpp
   for (int i = 0; i < n; ++i)
       for (int j = 0; j < n; ++j)
           if (g[i][j])
               q.push({i, j});
   ```
   - The outer loop iterates through all the cells in the grid. If a cell contains an obstacle (`g[i][j] == 1`), we add it to the queue as a starting point for the BFS.

   ```cpp
   while (!q.empty()) {
       auto [i, j] = q.front(); q.pop();
       for (int d = 0; d < 4; ++d) {
           int x = i + dir[d], y = j + dir[d + 1];
           if (min(x, y) >= 0 && max(x, y) < n && g[x][y] == 0) {
               g[x][y] = g[i][j] + 1;
               q.push({x, y});
           }
       }
   }
   ```
   - We perform BFS, where for each obstacle cell, we propagate the distance to its neighboring empty cells. The grid `g` is updated in-place to store the minimum distance to the nearest obstacle for each empty cell.
   - For each neighboring cell, we ensure it is within bounds and has not already been visited (indicated by `g[x][y] == 0`).

3. **Dijkstra-like Algorithm to Find Safeness Factor**:
   ```cpp
   priority_queue<array<int, 3>> pq;
   pq.push({g[0][0], 0, 0});
   ```
   - We initialize a max-priority queue (`pq`) to process cells based on their safeness factor (minimum distance to an obstacle). The priority queue stores tuples of the form `(safeness factor, x, y)` where `safeness factor` represents the minimum distance to an obstacle along the path to that cell.
   - We push the starting cell (top-left corner) into the queue with its calculated safeness factor (`g[0][0]`).

4. **Process Cells to Maximize Safeness Factor**:
   ```cpp
   while (pq.top()[1] < n - 1 || pq.top()[2] < n - 1) {
       auto [sf, i, j] = pq.top(); pq.pop();
       for (int d = 0; d < 4; ++d) {
           int x = i + dir[d], y = j + dir[d + 1];
           if (min(x, y) >= 0 && max(x, y) < n && g[x][y] > 0) {
               pq.push({min(sf, g[x][y]), x, y});
               g[x][y] *= -1;
           }
       }
   }
   ```
   - We process the cells in the priority queue, starting from the top-left corner. The goal is to maximize the minimum safeness factor along the path.
   - For each current cell, we examine its neighbors, updating their safeness factor by considering the minimum distance between the current cell’s safeness factor and the neighboring cell’s distance to the nearest obstacle.
   - Once a neighboring cell is processed, we mark it as visited by multiplying its value by `-1`.

5. **Return the Result**:
   ```cpp
   return pq.top()[0] - 1;
   ```
   - After the loop completes, the safeness factor for the bottom-right corner is stored in `pq.top()[0]`. Since we have tracked the safeness factor during the traversal, we return the final value, subtracting `1` as the last step ensures the correct output format.

### Complexity

1. **Time Complexity**:
   - **Phase 1 (BFS)**: The BFS processes each cell once, and each operation involves examining up to 4 neighboring cells. Hence, the time complexity of this phase is **O(n^2)**, where `n` is the size of the grid.
   - **Phase 2 (Dijkstra-like Algorithm)**: The priority queue processes each cell, and for each cell, we examine its 4 neighbors. Each insertion and extraction from the priority queue takes **O(log n)** time, but since we process each cell only once, the overall time complexity is **O(n^2 log n)**.

   Therefore, the overall time complexity of the algorithm is **O(n^2 log n)**.

2. **Space Complexity**:
   - The space complexity is determined by the data structures used. The queue and priority queue store up to `n^2` elements, so the space complexity is **O(n^2)**.

### Conclusion

This solution effectively solves the problem by using two key strategies:
- A **multi-source BFS** to compute the minimum distance to the nearest obstacle for every cell.
- A **Dijkstra-like algorithm** to find the path that maximizes the safeness factor from the top-left to the bottom-right corner.

The algorithm is efficient and handles large grids well, with a time complexity of **O(n^2 log n)**, which is suitable for typical input sizes. The approach ensures that we maximize the safeness factor while navigating through the grid, effectively solving the problem within the given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-safest-path-in-a-grid/description/)

---
{{< youtube -5mQcNiVWTs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
