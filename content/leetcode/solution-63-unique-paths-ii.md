
+++
authors = ["grid47"]
title = "Leetcode 63: Unique Paths II"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 63: Unique Paths II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/63.webp"
youtube = "d3UOz7zdE4I"
youtube_upload_date="2023-02-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d3UOz7zdE4I/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/63.webp" 
    alt="A more intricate, glowing path system with a few obstacles, showing varied routes to the goal."
    caption="Solution to LeetCode 63: Unique Paths II Problem"
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
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = grid[0][0] == 1? 0: 1;
        
        for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            
            if(grid[i][j] != 1) {
                dp[i][j] += ((i > 0 && grid[i - 1][j] == 0)? dp[i - 1][j]: 0) +
                        ((j > 0 && grid[i][j - 1] == 0)? dp[i][j - 1]: 0);
            }
            
        }
        return dp[m - 1][n - 1];
    }
};
{{< /highlight >}}
---

### 🚶‍♂️ **Unique Paths with Obstacles**

The problem is to find the total number of unique paths in an `m x n` grid from the top-left corner `(0, 0)` to the bottom-right corner `(m-1, n-1)`, while avoiding obstacles. In this grid:
- Cells with obstacles are represented by `1`s and cannot be traversed.
- Cells without obstacles are represented by `0`s and are free to move through.
- Movement is restricted to either moving down or right at each step.

### 🧠 **Approach**

This problem is solved using **dynamic programming (DP)** while considering obstacles in the grid.

#### Key Observations:

1. **Starting Point**:
   - If the starting cell `(0, 0)` contains an obstacle, there are `0` ways to reach any destination, so the function immediately returns `0` paths.

2. **DP Initialization**:
   - We create a `dp` table where `dp[i][j]` represents the number of unique ways to reach cell `(i, j)` from the starting point `(0, 0)`.

3. **Base Cases**:
   - If the starting cell `(0, 0)` is free of obstacles, initialize it to `1` in `dp`, indicating one way to start at that position.
   - For cells in the first row and the first column, they can only be reached if there are no obstacles in their respective rows or columns. If any cell has an obstacle, all subsequent cells in that row or column will have `0` paths.

4. **Filling the DP Table**:
   - For each cell `(i, j)`, if it is free of obstacles (i.e., `grid[i][j] == 0`), the value of `dp[i][j]` is the sum of the values from the top cell `(i-1, j)` and the left cell `(i, j-1)`, as these are the only two directions from which you can arrive.
   - If a cell contains an obstacle (`grid[i][j] == 1`), then `dp[i][j]` is set to `0` since it is not reachable.

### 🔍 **Code Breakdown**

#### Step 1: Initialize DP Table

```cpp
vector<vector<int>> dp(m, vector<int>(n, 0));
```

- A 2D `dp` table of size `m x n` is initialized with `0`s, representing the paths to each cell.

#### Step 2: Set the Starting Point

```cpp
dp[0][0] = grid[0][0] == 1 ? 0 : 1;
```

- The top-left corner `dp[0][0]` is set to `1` if there’s no obstacle; otherwise, it is set to `0`, as no paths are possible.

#### Step 3: Fill the DP Table

```cpp
for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
        if(grid[i][j] != 1) {
            dp[i][j] += ((i > 0 && grid[i - 1][j] == 0) ? dp[i - 1][j] : 0) +
                        ((j > 0 && grid[i][j - 1] == 0) ? dp[i][j - 1] : 0);
        }
    }
```

- For each cell `(i, j)`:
  - If there is no obstacle, the number of ways to reach that cell is the sum of the ways from the top (`dp[i - 1][j]`) and from the left (`dp[i][j - 1]`), if those cells are also free of obstacles.
  - If a cell contains an obstacle (`grid[i][j] == 1`), the value for that cell in the DP table is set to `0`, indicating it is not reachable.

#### Step 4: Return the Final Answer

```cpp
return dp[m - 1][n - 1];
```

- The final result at `dp[m-1][n-1]` contains the total number of unique paths to the destination, considering any obstacles in the grid.

### 📊 **Complexity Analysis**

#### Time Complexity:
- **O(m * n):** We iterate through every cell in the `m x n` grid once, resulting in a time complexity of `O(m * n)`.

#### Space Complexity:
- **O(m * n):** The `dp` table requires `O(m * n)` space to store the number of unique paths for each cell.

### 🌟 **Conclusion**

This dynamic programming solution efficiently calculates the number of unique paths from the top-left to the bottom-right of a grid, while considering obstacles. By using previously computed paths, the solution avoids redundant calculations, ensuring optimal performance even for grids with obstacles. This approach dynamically adapts based on obstacle positions, providing a robust solution for pathfinding in grid-based problems.

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/unique-paths-ii/description/)

---
{{< youtube d3UOz7zdE4I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
