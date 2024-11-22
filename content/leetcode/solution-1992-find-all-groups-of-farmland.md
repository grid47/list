
+++
authors = ["grid47"]
title = "Leetcode 1992: Find All Groups of Farmland"
date = "2024-04-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1992: Find All Groups of Farmland in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R2mf-nBCWV4"
youtube_upload_date="2021-09-04"
youtube_thumbnail="https://i.ytimg.com/vi/R2mf-nBCWV4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int m, n;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(land[i][j] == 1) {
                vector<int> tmp = {i, j, i, j};
                dfs(land, i, j, tmp);
               ans.push_back(tmp); 
            }

        }
        return ans;
    }
    
    void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {

        if(land[i][j] != 1) return;
        
        land[i][j] = 0;
        
        tmp[2] = max(tmp[2], i);
        tmp[3] = max(tmp[3], j);
        
        if(j + 1 < n)
        dfs(land, i, j + 1, tmp);
            
        if(i + 1 < m)
        dfs(land, i + 1, j, tmp);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves identifying all farmland plots in a given 2D binary grid representation of land. Each cell in the grid can either be `1`, indicating farmland, or `0`, indicating non-farmland. The goal is to return a list of bounding rectangles for each contiguous block of farmland. Each rectangle is represented by four integers: `[top-left-row, top-left-column, bottom-right-row, bottom-right-column]`.

### Approach

To solve this problem, we can use a Depth-First Search (DFS) algorithm to explore each block of contiguous farmland starting from any cell containing a `1`. When we find a `1`, we will create a temporary vector to keep track of the boundaries of the farmland block. The key steps in our approach are as follows:

1. **Iterate Through Each Cell**: Loop through each cell in the grid. If we encounter a `1`, it indicates the start of a new farmland block.

2. **Initialize Boundaries**: For each new block of farmland found, initialize the boundaries of the rectangle with the current cell's coordinates.

3. **Perform DFS**: Call a recursive DFS function that marks the current cell as visited (by setting it to `0`) and expands the search to neighboring cells (right and down). During this process, we update the bottom-right corner of the rectangle as we traverse through the block.

4. **Store the Rectangle**: Once the entire block has been explored, store the rectangle defined by the boundaries in our result list.

5. **Return Results**: After processing all cells, return the list of rectangles.

### Code Breakdown (Step by Step)

Here's a detailed breakdown of the code:

```cpp
class Solution {
public:
    int m, n; // dimensions of the grid
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
```
We define a class `Solution` with a public method `findFarmland`, which accepts a 2D vector `land` as input.

```cpp
        m = land.size(), n = land[0].size();
        vector<vector<int>> ans;
```
We initialize `m` and `n` to hold the number of rows and columns in the grid, respectively. We also create a result vector `ans` to store the output rectangles.

```cpp
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(land[i][j] == 1) {
                vector<int> tmp = {i, j, i, j};
                dfs(land, i, j, tmp);
                ans.push_back(tmp); 
            }
        }
```
We loop through each cell in the grid. If a cell contains `1`, we create a temporary vector `tmp` initialized with the coordinates of that cell. We then call the `dfs` function to explore the farmland block, after which we add the rectangle to the `ans` vector.

```cpp
        return ans;
    }
```
Once all cells have been processed, we return the result vector containing all identified farmland rectangles.

#### DFS Function

```cpp
    void dfs(vector<vector<int>> &land, int i, int j, vector<int> &tmp) {
        if(land[i][j] != 1) return;
```
The `dfs` function takes the land grid, the current cell coordinates, and the temporary vector for the rectangle. If the current cell is not `1`, we return immediately.

```cpp
        land[i][j] = 0; // Mark as visited
```
We mark the current cell as visited by setting it to `0` to avoid counting it again in future DFS calls.

```cpp
        tmp[2] = max(tmp[2], i);
        tmp[3] = max(tmp[3], j);
```
We update the bottom-right corner of the rectangle in `tmp` by taking the maximum of the current indices.

```cpp
        if(j + 1 < n)
        dfs(land, i, j + 1, tmp);
        
        if(i + 1 < m)
        dfs(land, i + 1, j, tmp);
    }
};
```
We check if we can move right (to `j + 1`) and down (to `i + 1`). If the indices are within bounds, we call `dfs` recursively to continue exploring the farmland in that direction.

### Complexity

- **Time Complexity**: The time complexity of the solution is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the grid. This is because we traverse each cell exactly once.

- **Space Complexity**: The space complexity is \(O(m \times n)\) in the worst case due to the stack space used by the recursive DFS calls, though in practice it is usually much smaller since we only visit cells with `1`.

### Conclusion

The provided solution efficiently identifies and records the bounding rectangles for all contiguous blocks of farmland in a grid. By leveraging DFS, we are able to explore and mark each block while tracking its boundaries effectively. This approach ensures that all farmland areas are accounted for in an optimal manner.

### Example Usage

Here’s an example of how to use the `findFarmland` method:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution sol;
    vector<vector<int>> land = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 1, 1}
    };
    
    vector<vector<int>> result = sol.findFarmland(land);
    
    for (const auto& rect : result) {
        cout << "[" << rect[0] << ", " << rect[1] << ", " << rect[2] << ", " << rect[3] << "]" << endl;
    }
    return 0;
}
```

### Edge Cases to Consider

1. **Empty Grid**: If the input grid is empty, the output should be an empty vector.

2. **All Zeros**: If the grid contains only `0`s, the output should also be an empty vector since there is no farmland.

3. **Single Cell Farmland**: A grid with a single `1` should return a rectangle that matches that single cell.

### Potential Improvements

1. **Iterative DFS**: While recursion is simple to implement, an iterative approach using a stack could prevent potential stack overflow in very large grids.

2. **Optimized Memory Usage**: Instead of modifying the original `land` grid, we could maintain a separate visited grid to mark processed cells.

This solution is robust and effectively identifies farmland plots while managing complexity and performance.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-groups-of-farmland/description/)

---
{{< youtube R2mf-nBCWV4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
