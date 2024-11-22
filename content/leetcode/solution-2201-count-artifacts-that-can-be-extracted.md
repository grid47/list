
+++
authors = ["grid47"]
title = "Leetcode 2201: Count Artifacts That Can Be Extracted"
date = "2024-03-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2201: Count Artifacts That Can Be Extracted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "neXgYvigRcI"
youtube_upload_date="2022-03-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/neXgYvigRcI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        
        
        vector<vector<int>> grid(n, vector<int>(n, -1));
        
        int k = 0;
        for(auto it: artifacts) {
            k++;
            for(int i = it[0]; i <= it[2]; i++)
            for(int j = it[1]; j <= it[3]; j++)
                grid[i][j] = k;

        }
        
        set<int> cnt;
        for(auto it: dig)
            grid[it[0]][it[1]] = -1;
        
        for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] != -1)
                cnt.insert(grid[i][j]);
        
        return k - cnt.size();
    }
};
{{< /highlight >}}
---

### Problem Statement
The problem involves a grid representing a collection of artifacts, each defined by a rectangular area within the grid. Some of the cells in the grid have been "dug," meaning the artifacts located at those positions are no longer intact. The task is to determine how many distinct artifacts remain completely undug after the excavation.

Given:
1. `n`: the size of the grid (n x n).
2. `artifacts`: a list of rectangles, where each rectangle specifies the coordinates (x1, y1, x2, y2) representing the upper-left and bottom-right corners of an artifact in the grid.
3. `dig`: a list of coordinates of cells that have been dug.

The goal is to find out how many artifacts remain fully intact after the excavation, meaning no part of the artifact has been dug.

### Approach
The approach revolves around simulating the excavation and marking the artifacts that have been affected by the digging. The plan is as follows:

1. **Grid Representation**:
   We represent the grid using a 2D array where each cell stores an identifier for the artifact it belongs to. If a cell is not part of any artifact, it is initialized to `-1`.

2. **Marking Artifacts**:
   For each artifact, we iterate through its defined area and assign a unique artifact ID to the cells within that area. This allows us to track which artifact occupies which grid cells.

3. **Simulating the Digging Process**:
   We then process the list of dug cells, marking them as “dug” (i.e., setting the corresponding grid cell to `-1`). This indicates that any artifact occupying that cell is no longer intact.

4. **Counting Remaining Artifacts**:
   After processing the digging, we scan the grid and check which artifact IDs remain. If an artifact ID appears in the grid and none of its cells have been dug, the artifact remains intact.

5. **Result Calculation**:
   Finally, the number of intact artifacts is calculated by subtracting the number of distinct dug artifacts from the total number of artifacts.

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Grid
```cpp
vector<vector<int>> grid(n, vector<int>(n, -1));
```
- A 2D grid of size `n x n` is initialized. Each cell in the grid is initially set to `-1`, indicating that it does not belong to any artifact.

#### Step 2: Assign Artifact IDs to Grid Cells
```cpp
int k = 0;
for(auto it: artifacts) {
    k++;
    for(int i = it[0]; i <= it[2]; i++)
        for(int j = it[1]; j <= it[3]; j++)
            grid[i][j] = k;
}
```
- We iterate over each artifact in the `artifacts` list. For each artifact, we assign a unique artifact ID (incremented by `k` for each artifact).
- For the current artifact, we iterate through all the cells in the rectangle defined by its corners `(x1, y1)` and `(x2, y2)`. Each cell in the artifact's area is assigned the artifact's ID in the `grid`.

#### Step 3: Mark the Dug Cells
```cpp
set<int> cnt;
for(auto it: dig)
    grid[it[0]][it[1]] = -1;
```
- We use the `dig` list to mark the cells that have been dug. For each dug cell `(x, y)`, we set `grid[x][y] = -1`, indicating that the artifact at that position has been dug up.

#### Step 4: Count the Remaining Artifacts
```cpp
for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] != -1)
            cnt.insert(grid[i][j]);
```
- After marking the dug cells, we iterate through the entire grid and insert the artifact IDs that remain intact (i.e., those cells that have not been set to `-1`) into a set `cnt`. A set is used to ensure that each artifact ID is counted only once, even if multiple cells of the same artifact remain intact.

#### Step 5: Return the Result
```cpp
return k - cnt.size();
```
- The result is the total number of artifacts (`k`) minus the number of distinct artifacts that were affected by digging (i.e., the size of `cnt`).
- The difference gives the number of artifacts that remain completely undug.

### Complexity

#### Time Complexity:
- **O(n^2 + m)**, where `n` is the grid size (n x n) and `m` is the number of artifacts. 
  - The first part of the time complexity (`O(n^2)`) comes from the grid initialization and processing the artifacts, where for each artifact, we mark its corresponding cells on the grid.
  - The second part (`O(m)`) comes from processing the dug cells, which involves checking and marking each dug cell in the grid.
  - Finally, the step where we count the remaining artifacts also takes `O(n^2)` in the worst case, since we are iterating over all cells in the grid.

#### Space Complexity:
- **O(n^2)**, since we are using a 2D grid of size `n x n` to store artifact IDs and the marked dug cells.

### Conclusion
This solution efficiently solves the problem of determining how many artifacts remain undug after a series of digs. The key steps involve:
1. Initializing a grid to represent the artifact areas.
2. Iterating over the grid and marking cells as dug.
3. Counting the number of artifacts that remain fully intact.

The algorithm is efficient with a time complexity of **O(n^2)** and a space complexity of **O(n^2)**, which makes it scalable for moderately large grid sizes. The use of a set to track distinct artifacts ensures that we count only unique artifacts that are not affected by the dig.

This solution can be applied to similar problems involving grid-based tracking, where we need to manage and update areas or regions affected by specific actions (e.g., digging, marking, etc.).

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/)

---
{{< youtube neXgYvigRcI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
