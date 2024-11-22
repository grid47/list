
+++
authors = ["grid47"]
title = "Leetcode 542: 01 Matrix"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 542: 01 Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp"
youtube = "1xuLfxgT7yo"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/1xuLfxgT7yo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/542.webp" 
    alt="A matrix where cells of 1s and 0s are arranged, with the shortest distance for 1s to 0s glowing softly."
    caption="Solution to LeetCode 542: 01 Matrix Problem"
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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(mat[i][j] == 0)
            q.push({i, j});
        
        int dis = 0;
        vector<vector<int>> vis;
        vis.resize(m, vector<int>(n, 0));
        int dir[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto it = q.front();
                q.pop();                
                if(vis[it[0]][it[1]]) continue;
                mat[it[0]][it[1]] = dis;
                vis[it[0]][it[1]] = 1;

                for(int i = 0; i < 4; i++) {
                    int x = it[0] + dir[i], y = it[1] + dir[i + 1];
                    if(x < 0 || y < 0 || x == m || y == n)
                        continue;
                    if(!vis[x][y])
                        q.push({x, y});
                }
            }
            dis++;
        }
        return mat;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to update a matrix of `0`s and `1`s such that each cell in the matrix contains the shortest distance to the nearest `0`. You are given a binary matrix where `0` represents a cell with no obstacle, and `1` represents a cell that needs to be updated with the shortest distance to the nearest `0`. This problem is commonly known as the "01 Matrix" problem.

### Approach

The best way to solve this problem is by using **Breadth-First Search (BFS)**, which works efficiently when searching for the shortest path in an unweighted grid-like structure. Here's a breakdown of the approach:

1. **Grid Setup**: 
   - We are given a matrix of size `m x n`, where `m` is the number of rows, and `n` is the number of columns.
   - The goal is to calculate the shortest distance from each cell containing `1` to the nearest cell containing `0`.

2. **Initial Conditions**:
   - Cells containing `0` already have a distance of `0` since they are the nearest to themselves.
   - We can start from all `0` cells simultaneously and use BFS to propagate the shortest distance to all `1` cells.

3. **BFS Propagation**:
   - We will use a queue to manage the BFS process. We start by pushing all cells that contain `0` into the queue.
   - We will explore each direction (up, down, left, right) from each `0` and update the distance of the `1` cells.
   - We will continue this process until all cells have been updated with their shortest distance to a `0`.

4. **Efficiency**: 
   - BFS is ideal for this problem because it processes nodes level by level, ensuring that the first time a node (cell) is processed, it is done with the shortest possible distance from a `0`. This guarantees that the distance calculation is optimal.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the BFS Queue

```cpp
queue<vector<int>> q;
int m = mat.size(), n = mat[0].size();
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        if (mat[i][j] == 0)
            q.push({i, j});
```

- We start by creating a queue (`q`) to hold the coordinates of the cells that contain `0`.
- We then iterate over the matrix. For each cell, if the value is `0`, we push its coordinates (row `i`, column `j`) into the queue. These cells will be the starting points for the BFS.

#### Step 2: Initialize Direction Array and Visited Matrix

```cpp
int dis = 0;
vector<vector<int>> vis;
vis.resize(m, vector<int>(n, 0));
int dir[] = {0, 1, 0, -1, 0};
```

- `dis` is the distance variable, which starts at `0` and will increment as we move further from the initial `0` cells.
- We initialize a `visited` matrix (`vis`) of size `m x n` to track the cells that have already been processed. Initially, all cells are set to `0` (not visited).
- The `dir` array is used to simplify the navigation of four directions: right (1), left (-1), down (1), and up (-1).

#### Step 3: BFS Loop for Distance Propagation

```cpp
while (!q.empty()) {
    int sz = q.size();
    while (sz--) {
        auto it = q.front();
        q.pop();                
        if (vis[it[0]][it[1]]) continue;
        mat[it[0]][it[1]] = dis;
        vis[it[0]][it[1]] = 1;

        for (int i = 0; i < 4; i++) {
            int x = it[0] + dir[i], y = it[1] + dir[i + 1];
            if (x < 0 || y < 0 || x == m || y == n)
                continue;
            if (!vis[x][y])
                q.push({x, y});
        }
    }
    dis++;
}
```

- We start by processing the cells in the queue using BFS. The outer `while` loop continues as long as there are cells in the queue.
- Inside the loop, we process all cells at the current distance (`dis`), indicated by the size of the queue (`sz`). For each cell, we check if it has been visited. If it has, we skip it. If not, we:
  - Set its value to the current distance (`dis`), as this is the shortest distance from the nearest `0`.
  - Mark it as visited by setting `vis[it[0]][it[1]] = 1`.
  - For each of the four directions, we check if moving in that direction leads to a valid cell (within bounds and not yet visited). If valid, we push the new cell into the queue.
- After processing all cells at the current distance, we increment `dis` to propagate further.

#### Step 4: Return the Updated Matrix

```cpp
return mat;
```

- Once BFS completes, the matrix `mat` will have the shortest distances from each `1` to the nearest `0`. We return this matrix as the result.

### Complexity

#### Time Complexity:

- **BFS Traversal**: We visit every cell in the matrix exactly once. For each cell, we check its four neighbors. Therefore, the time complexity is **O(m * n)**, where `m` is the number of rows and `n` is the number of columns in the matrix.
  
#### Space Complexity:

- **Queue**: In the worst case, the queue can hold all cells in the matrix. Therefore, the space complexity for the queue is **O(m * n)**.
- **Visited Matrix**: We use a `visited` matrix to keep track of visited cells, which also requires **O(m * n)** space.
- Overall, the space complexity is **O(m * n)**.

### Conclusion

This solution efficiently solves the problem of updating the matrix with the shortest distance to the nearest `0` by leveraging **Breadth-First Search (BFS)**. BFS ensures that each cell is updated with the shortest possible distance from the nearest `0`. The time and space complexities are both **O(m * n)**, making this solution optimal for large grids. The approach is simple, easy to understand, and efficient in solving this type of shortest-path problem on a grid.

[`Link to LeetCode Lab`](https://leetcode.com/problems/01-matrix/description/)

---
{{< youtube 1xuLfxgT7yo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
