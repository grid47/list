
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
comments = true
+++



---
You are given an `n x n` grid and a list of rectangular artifacts buried under it. Each artifact is represented by a list `[r1, c1, r2, c2]`, where `(r1, c1)` is the top-left corner and `(r2, c2)` is the bottom-right corner of the artifact. You are also given a list of `dig` coordinates representing cells in the grid where excavation occurs. Once all parts of an artifact are uncovered, you can extract it. Your task is to return the total number of artifacts that you can fully uncover and extract.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, representing the grid size, a 2D list `artifacts` where each element is a list `[r1, c1, r2, c2]` representing a rectangular artifact, and a 2D list `dig` representing the coordinates of cells to be excavated.
- **Example:** `n = 3, artifacts = [[0,0,0,0], [1,1,2,2]], dig = [[0,0], [0,1], [1,1], [2,1], [2,2]]`
- **Constraints:**
	- 1 <= n <= 1000
	- 1 <= artifacts.length, dig.length <= min(n^2, 10^5)
	- artifacts[i].length == 4
	- dig[i].length == 2
	- 0 <= r1i, c1i, r2i, c2i, ri, ci <= n - 1
	- r1i <= r2i
	- c1i <= c2i
	- No two artifacts will overlap.
	- The number of cells covered by an artifact is at most 4.
	- The entries of dig are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the total number of artifacts that can be fully extracted after performing all excavations.
- **Example:** `Output: 2`
- **Constraints:**
	- The output should be an integer representing the number of fully extracted artifacts.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the number of artifacts that can be fully uncovered after the given excavations.

- 1. Create a grid to represent all the artifacts buried under each cell.
- 2. Mark all the cells that are dug up as uncovered.
- 3. For each artifact, check if all its parts are uncovered by checking the corresponding cells in the grid.
- 4. Count the number of artifacts that are fully uncovered and return that count.
{{< dots >}}
### Problem Assumptions ✅
- No artifacts overlap in the grid.
- Each artifact can cover at most 4 cells.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 3, artifacts = [[0,0,0,0], [1,1,2,2]], dig = [[0,0], [0,1], [1,1], [2,1], [2,2]]`  \
  **Explanation:** In this case, both artifacts are fully uncovered by the specified dig operations, so the output is 2.

{{< dots >}}
## Approach 🚀
To solve this problem, you will iterate over the list of artifacts and mark the corresponding grid cells. Then, mark the excavated cells as uncovered and check which artifacts are fully uncovered.

### Initial Thoughts 💭
- The artifacts do not overlap, and no artifact covers more than 4 cells.
- Efficiently tracking the excavation process is key to solving this problem.
{{< dots >}}
### Edge Cases 🌐
- If no cells are dug, no artifact can be extracted.
- Ensure that the algorithm can handle up to 10^5 dig operations efficiently.
- If all the artifacts are covered by only 1 or 2 cells, ensure the logic works correctly for these smaller cases.
- Artifacts are guaranteed to not overlap, simplifying the grid setup.
{{< dots >}}
## Code 💻
```cpp
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
```

The function calculates the number of distinct artifacts that remain after performing the specified digs on the grid.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
	```
	Define the function `digArtifacts` with parameters `n`, `artifacts`, and `dig`.

2. **Set Initialization**
	```cpp
	    vector<vector<int>> grid(n, vector<int>(n, -1));
	```
	Initialize a grid of size `n x n` with all values set to -1, representing unprocessed cells.

3. **Variable Initialization**
	```cpp
	    int k = 0;
	```
	Initialize a counter variable `k` to track the artifact numbers.

4. **Iterate over Artifacts**
	```cpp
	    for(auto it: artifacts) {
	```
	Loop through each artifact in the `artifacts` list to mark the grid cells occupied by it.

5. **Increment Artifact Counter**
	```cpp
	        k++;
	```
	Increment the artifact counter `k` for each new artifact.

6. **Nested Loop for Grid Assignment**
	```cpp
	        for(int i = it[0]; i <= it[2]; i++)
	```
	Start an inner loop to iterate through the grid rows that the current artifact occupies.

7. **Nested Loop for Grid Assignment**
	```cpp
	        for(int j = it[1]; j <= it[3]; j++)
	```
	Start another inner loop to iterate through the grid columns that the current artifact occupies.

8. **Assign Artifact Number**
	```cpp
	            grid[i][j] = k;
	```
	Assign the artifact number `k` to the cells occupied by the artifact in the grid.

9. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	Initialize a set `cnt` to track the distinct artifact numbers that have been dug up.

10. **Iterate over Digs**
	```cpp
	    for(auto it: dig)
	```
	Loop through each dig in the `dig` list and mark the corresponding cells as dug up.

11. **Mark Digged Cells**
	```cpp
	        grid[it[0]][it[1]] = -1;
	```
	Set the value of the grid cell corresponding to the dig position to -1, indicating it has been dug up.

12. **Nested Loop for Grid Processing**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start an outer loop to iterate through all rows of the grid.

13. **Nested Loop for Grid Processing**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Start an inner loop to iterate through all columns of the grid.

14. **Check for Remaining Artifacts**
	```cpp
	        if(grid[i][j] != -1)
	```
	Check if the grid cell has not been dug up (i.e., its value is not -1).

15. **Insert Distinct Artifacts**
	```cpp
	            cnt.insert(grid[i][j]);
	```
	Insert the artifact number into the set `cnt` if the grid cell has not been dug up.

16. **Return Remaining Artifacts Count**
	```cpp
	    return k - cnt.size();
	```
	Return the number of remaining artifacts by subtracting the size of the set `cnt` from the total artifact count `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2), where n is the grid size.
- **Average Case:** O(n^2), where n is the grid size.
- **Worst Case:** O(n^2), where n is the grid size.

The time complexity is dominated by the grid size and the need to check each cell for excavation and artifact extraction.

### Space Complexity 💾
- **Best Case:** O(n^2), where n is the grid size.
- **Worst Case:** O(n^2), where n is the grid size.

The space complexity is O(n^2) due to the grid and the need to store artifact positions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/)

---
{{< youtube neXgYvigRcI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
