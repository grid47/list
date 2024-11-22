
+++
authors = ["grid47"]
title = "Leetcode 1905: Count Sub Islands"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1905: Count Sub Islands in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mLpW3qfbNJ8"
youtube_upload_date="2021-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/mLpW3qfbNJ8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int m =grid2.size(), n = grid2[0].size();
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 1)
                dfs(grid2, i, j);
        
        int res = 0;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid2[i][j] == 2)
                res += find(grid1, grid2, i, j);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& grid2, int i, int j) {

        int m = grid2.size(), n = grid2[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;

        grid2[i][j] = 2;

        dfs(grid2, i, j + 1);
        dfs(grid2, i + 1, j);
        dfs(grid2, i - 1, j);
        dfs(grid2, i, j - 1);

    }

    bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        int m = grid2.size(), n = grid2[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;

        bool res = true;
        if (grid1[i][j] != 1) res = false;

        grid2[i][j] = 3;

        res &= find(grid1, grid2, i, j + 1);
        res &= find(grid1, grid2, i + 1, j);
        res &= find(grid1, grid2, i - 1, j);
        res &= find(grid1, grid2, i, j - 1);

        return res;
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem is to count the number of sub-islands that can be formed from a second grid (`grid2`) while ensuring that these sub-islands are completely contained within a first grid (`grid1`). A sub-island is defined as an island in `grid2` that corresponds to a land area (represented by `1`s) in `grid1`. The task is to identify these sub-islands in `grid2` and check if their land cells (1s) match with the land cells in `grid1`.

### Approach

To tackle this problem, we will use a depth-first search (DFS) strategy. The approach can be broken down into the following steps:

1. **Mark All Land Cells in Grid2**: Iterate through `grid2` to identify all connected land cells (1s) and mark them. We will use a DFS function to traverse all connected components starting from each unvisited land cell in `grid2`.

2. **Count Valid Sub-Islands**: After marking the cells in `grid2`, we will iterate through the marked cells (now represented as 2) and check if they form valid sub-islands by comparing them with `grid1`. This will be done using another DFS function that verifies if all corresponding cells in `grid1` are land cells (1s).

3. **Return the Count of Sub-Islands**: Finally, we will count and return the number of valid sub-islands identified.

### Code Breakdown (Step by Step)

Let’s analyze the provided code step by step to understand how the solution is implemented:

1. **Class Definition**: The solution is encapsulated within a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: The primary function `countSubIslands` takes two 2D vectors (`grid1` and `grid2`) and returns an integer count of the sub-islands.

   ```cpp
       int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
   ```

3. **Grid Size Initialization**: We initialize the dimensions of the grids `m` (number of rows) and `n` (number of columns).

   ```cpp
           int m = grid2.size(), n = grid2[0].size();
   ```

4. **DFS Traversal**: We iterate through each cell of `grid2`. If we encounter a land cell (1), we invoke the `dfs` function to mark all connected land cells.

   ```cpp
           for(int i = 0; i < m; i++)
               for(int j = 0; j < n; j++)
                   if(grid2[i][j] == 1)
                       dfs(grid2, i, j);
   ```

5. **Sub-Island Counting**: We initialize a counter `res` to zero. Then, we check for cells marked with 2 (previously land cells) and use the `find` function to determine if they form a valid sub-island in relation to `grid1`.

   ```cpp
           int res = 0;
           for(int i = 0; i < m; i++)
               for(int j = 0; j < n; j++)
                   if(grid2[i][j] == 2)
                       res += find(grid1, grid2, i, j);
   ```

6. **Returning the Result**: Finally, we return the count of valid sub-islands.

   ```cpp
           return res;
       }
   ```

7. **DFS Function**: The `dfs` function marks the connected land cells in `grid2` as 2. It takes the coordinates of the current cell and recursively marks adjacent land cells.

   ```cpp
       void dfs(vector<vector<int>>& grid2, int i, int j) {
           int m = grid2.size(), n = grid2[0].size();
           if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return;
           grid2[i][j] = 2;
           dfs(grid2, i, j + 1);
           dfs(grid2, i + 1, j);
           dfs(grid2, i - 1, j);
           dfs(grid2, i, j - 1);
       }
   ```

8. **Find Function**: The `find` function checks if all marked land cells in `grid2` correspond to land cells in `grid1`. If any corresponding cell in `grid1` is not a land cell (0), it returns false. It also marks processed cells as 3 to prevent revisiting.

   ```cpp
       bool find(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
           int m = grid2.size(), n = grid2[0].size();
           if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 2) return true;
           bool res = true;
           if (grid1[i][j] != 1) res = false;
           grid2[i][j] = 3;
           res &= find(grid1, grid2, i, j + 1);
           res &= find(grid1, grid2, i + 1, j);
           res &= find(grid1, grid2, i - 1, j);
           res &= find(grid1, grid2, i, j - 1);
           return res;
       }
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is O(m * n), where m is the number of rows and n is the number of columns in the grids. Each cell is visited a constant number of times during the DFS traversal.

- **Space Complexity**: The space complexity is O(m * n) in the worst case due to the recursion stack used by DFS and the potential need for auxiliary data structures to hold visited states.

### Conclusion

The `countSubIslands` function efficiently counts the number of valid sub-islands in `grid2` based on the structure of `grid1`. By utilizing depth-first search, the solution captures connected components in `grid2` and verifies their validity against `grid1`. This algorithm is optimal for solving the problem with a clear and concise approach.

### Use Cases

The functionality provided by this algorithm can be applied in several scenarios:

1. **Geographical Mapping**: In geographical information systems (GIS), the algorithm can be used to analyze the overlap of certain land areas (islands) between two datasets.

2. **Environmental Studies**: Researchers may use such algorithms to determine protected areas in relation to developed land, helping in conservation planning.

3. **Computer Graphics**: The concept of sub-islands can be applicable in rendering systems where certain areas need to be identified and manipulated separately.

4. **Game Development**: In games involving terrain and map design, this algorithm could assist in evaluating specific land features and their relationships with one another.

By integrating such functionality, applications can enhance their data processing capabilities while maintaining efficiency and clarity in the algorithms used. The depth-first search approach ensures comprehensive coverage of potential land configurations while validating conditions against the initial grid.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-sub-islands/description/)

---
{{< youtube mLpW3qfbNJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
