
+++
authors = ["grid47"]
title = "Leetcode 807: Max Increase to Keep City Skyline"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 807: Max Increase to Keep City Skyline in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/807.webp"
youtube = "uVPkYy5jzRo"
youtube_upload_date="2023-02-06"
youtube_thumbnail="https://i.ytimg.com/vi/uVPkYy5jzRo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/807.webp" 
    alt="A skyline of buildings with the maximum increase calculated, glowing softly as each increase is added."
    caption="Solution to LeetCode 807: Max Increase to Keep City Skyline Problem"
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
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> row(n, 0), col(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            res += min(row[i], col[j]) - grid[i][j];
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement
In this problem, you are given a 2D grid representing a cityscape, where each value in the grid represents the height of a building at a particular position. Your task is to find the maximum total increase in the height of the buildings such that the skyline (viewed from the top, in both the horizontal and vertical directions) remains the same.

The **skyline** of a city refers to the highest building visible from any row or column. This problem asks for the maximum possible increase in building heights that can occur without changing the skyline.

### Approach
To solve this problem, the key idea is that the height of each building can be increased only to the minimum of the maximum height in its row and the maximum height in its column. By iterating through the grid and determining the highest possible building height for each cell based on these constraints, we can compute the total increase in building heights.

The approach can be broken down into the following steps:

1. **Compute Maximum Heights**:
   - First, for each row and column, we need to find the maximum building height. This is necessary because the maximum height for a building in any given row or column cannot exceed the maximum height in that row or column when considering the skyline.

2. **Calculate Possible Increase**:
   - For each building, the new possible height is the minimum of the maximum height in the corresponding row and column.
   - The difference between this new height and the current height of the building will give the increase in height for that building.

3. **Accumulate the Increase**:
   - Sum all the increases for all buildings to get the total increase in the height of the buildings while maintaining the same skyline.

### Code Breakdown (Step by Step)

#### Step 1: Initialization
```cpp
int n = grid.size();
vector<int> row(n, 0), col(n, 0);
```
- **`n`**: This variable represents the size of the grid (i.e., the number of rows and columns in the square grid).
- **`row`**: This vector will store the maximum height for each row.
- **`col`**: This vector will store the maximum height for each column.

#### Step 2: Find Maximum Heights for Each Row and Column
```cpp
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
        row[i] = max(row[i], grid[i][j]);
        col[j] = max(col[j], grid[i][j]);
    }
}
```
- This nested loop iterates over the entire grid. For each cell `(i, j)`:
  - **`row[i] = max(row[i], grid[i][j])`**: Updates the maximum building height for row `i`.
  - **`col[j] = max(col[j], grid[i][j])`**: Updates the maximum building height for column `j`.

At the end of these loops, `row[i]` contains the maximum height of the buildings in row `i`, and `col[j]` contains the maximum height of the buildings in column `j`.

#### Step 3: Calculate the Maximum Possible Increase
```cpp
int res = 0;
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
        res += min(row[i], col[j]) - grid[i][j];
    }
```
- We initialize the variable `res` to store the total increase in height.
- This double loop iterates over every building in the grid. For each building at position `(i, j)`:
  - **`min(row[i], col[j])`**: This determines the maximum possible height for the building at `(i, j)` without altering the skyline. It ensures that the building's new height will not exceed the maximum height in either its row or column.
  - **`min(row[i], col[j]) - grid[i][j]`**: This calculates the increase in height for the building by subtracting the current height from the maximum allowable height.
  - We accumulate this increase in the variable `res`.

#### Step 4: Return the Total Increase
```cpp
return res;
```
- Finally, after summing up the increases for all the buildings, we return the result, which represents the total increase in height that can be made without altering the skyline.

### Complexity

#### Time Complexity:
The time complexity of the solution is **O(n^2)**, where:
- **`n`** is the number of rows (or columns) in the grid (since the grid is square).
- **First Loop**: The first loop calculates the maximum heights for each row and column, which takes **O(n^2)** time as it iterates over every cell in the grid.
- **Second Loop**: The second loop calculates the total increase, which also involves iterating over every cell in the grid, contributing another **O(n^2)** time.

Thus, the overall time complexity is **O(n^2)**, which is efficient for grid sizes typically encountered in problems of this type.

#### Space Complexity:
The space complexity is **O(n)**, where:
- **`row`** and **`col`** are both vectors of size `n`, each requiring **O(n)** space.
- The space used for storing the grid itself is not included in the space complexity, as it is assumed to be provided as input.

Therefore, the space complexity is linear in terms of the size of the grid, i.e., **O(n)**.

### Conclusion

This solution efficiently computes the maximum increase in building heights while maintaining the skyline, using a straightforward approach involving two passes over the grid. The first pass calculates the maximum heights for each row and column, and the second pass computes the total increase in height by ensuring that each building's new height does not violate the skyline constraints.

The algorithm runs in **O(n^2)** time, making it efficient for typical grid sizes, and requires **O(n)** space for storing the row and column maximums. This approach is optimal for solving the problem within the constraints of typical input sizes, and it provides a clean, easy-to-understand solution for maximizing the building heights while keeping the skyline intact.

[`Link to LeetCode Lab`](https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/)

---
{{< youtube uVPkYy5jzRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
