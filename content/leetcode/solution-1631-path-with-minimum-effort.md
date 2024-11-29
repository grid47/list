
+++
authors = ["grid47"]
title = "Leetcode 1631: Path With Minimum Effort"
date = "2024-05-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1631: Path With Minimum Effort in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Depth-First Search","Breadth-First Search","Union Find","Heap (Priority Queue)","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XQlxCCx2vI4"
youtube_upload_date="2023-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/XQlxCCx2vI4/maxresdefault.jpg"
comments = true
+++



---
You are a hiker navigating a terrain represented by a 2D grid of heights. Your goal is to find the path from the top-left corner to the bottom-right corner that minimizes the maximum height difference between any two consecutive cells.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array `heights` of size `rows x columns`, where `heights[i][j]` represents the height at position `(i, j).`
- **Example:** `heights = [[2, 3, 1], [5, 6, 4], [7, 8, 3]]`
- **Constraints:**
	- 1 <= rows, columns <= 100
	- 1 <= heights[i][j] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the minimum possible effort to travel from the top-left to the bottom-right cell.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the minimum possible effort to travel from the top-left to the bottom-right cell.

- Use a priority queue to explore the grid.
- At each cell, track the maximum difference in heights from the previous cell.
- Keep track of the smallest maximum difference encountered and return that as the result.
{{< dots >}}
### Problem Assumptions ✅
- You can move in four directions (up, down, left, right).
- The top-left cell is always your starting point and the bottom-right cell is always your destination.
{{< dots >}}
## Examples 🧩
- **Input:** `heights = [[2, 3, 1], [5, 6, 4], [7, 8, 3]]`  \
  **Explanation:** The optimal path involves moving from 2 -> 5 -> 6 -> 4 -> 3, with the largest height difference between two consecutive cells being 2.

{{< dots >}}
## Approach 🚀
The approach leverages a priority queue to explore the grid cells, calculating the minimum possible maximum height difference encountered along the path.

### Initial Thoughts 💭
- We need to explore the grid and calculate the maximum height difference between consecutive cells along the path.
- A priority queue can help efficiently explore the grid and maintain the smallest possible maximum difference.
{{< dots >}}
### Edge Cases 🌐
- No empty grids are expected in the input.
- The solution must efficiently handle grids with up to 100 rows and columns.
- The solution should handle cases where all heights are the same, resulting in zero effort.
- The height values are constrained between 1 and 10^6, ensuring the differences are manageable.
{{< dots >}}
## Code 💻
```cpp
class Solution {

public:
int minimumEffortPath(vector<vector<int>>& h) {
    int dir[] = {0, 1, 0, -1, 0};
    int m = h.size(), n = h[0].size();
    vector<vector<int>> sz(m, vector<int>(n, INT_MAX));
    priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> pq;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        array<int, 3> r = pq.top();
        pq.pop();
        int i = r[0], j = r[1], d = r[2];
        //cout << i << ' ' << j << ' ' << d << endl;
        if(d > sz[i][j]) continue;
        if((i == (m - 1)) && (j == (n - 1))) return d;
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k], nj = j + dir[k + 1];
            if(min(ni, nj) < 0 || ni >= m || nj >= n) continue;

            int nxt = sz[ni][nj];
            int nd  = max(abs(h[i][j] - h[ni][nj]), d);
            if (nxt > nd) {
                sz[ni][nj] = nd;
                pq.push({ni, nj, nd});
            }
        }
    }
    return 0;
}
```

This function calculates the minimum effort required to travel from the top-left to the bottom-right corner of a grid, where each cell has an elevation. It uses a priority queue to perform a Dijkstra-like algorithm, minimizing the maximum elevation difference encountered during the path traversal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Define the 'Solution' class that encapsulates the method for solving the problem.

2. **Access Modifier**
	```cpp
	public:
	```
	Declare the public section of the class where the method 'minimumEffortPath' will be defined.

3. **Method Definition**
	```cpp
	int minimumEffortPath(vector<vector<int>>& h) {
	```
	Define the 'minimumEffortPath' method, which takes a 2D vector 'h' representing the grid of elevations as input.

4. **Variable Initialization**
	```cpp
	    int dir[] = {0, 1, 0, -1, 0};
	```
	Initialize the 'dir' array, which contains the four possible movement directions (right, down, left, and up) for traversal.

5. **Variable Initialization**
	```cpp
	    int m = h.size(), n = h[0].size();
	```
	Determine the dimensions of the grid, 'm' for rows and 'n' for columns.

6. **Matrix Initialization**
	```cpp
	    vector<vector<int>> sz(m, vector<int>(n, INT_MAX));
	```
	Create a 2D vector 'sz' initialized with 'INT_MAX' to store the minimum effort required to reach each cell.

7. **Priority Queue Initialization**
	```cpp
	    priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> pq;
	```
	Initialize a priority queue 'pq' that will store the current state of traversal (row, column, and effort). The queue is ordered by the effort required to reach each cell.

8. **Queue Push**
	```cpp
	    pq.push({0, 0, 0});
	```
	Push the initial position (0,0) with an effort of 0 into the priority queue.

9. **Loop Constructs**
	```cpp
	    while(!pq.empty()) {
	```
	Start a while loop to process each element in the priority queue until it is empty.

10. **Queue Operations**
	```cpp
	        array<int, 3> r = pq.top();
	```
	Get the top element from the priority queue, which contains the current row, column, and effort.

11. **Queue Operations**
	```cpp
	        pq.pop();
	```
	Remove the top element from the priority queue.

12. **Variable Assignment**
	```cpp
	        int i = r[0], j = r[1], d = r[2];
	```
	Assign the row index 'i', column index 'j', and the current effort 'd' from the top element.

13. **Conditional Check**
	```cpp
	        if(d > sz[i][j]) continue;
	```
	Check if the current effort 'd' is greater than the already stored effort for cell (i, j). If so, skip the current iteration.

14. **Termination Condition**
	```cpp
	        if((i == (m - 1)) && (j == (n - 1))) return d;
	```
	If the current position is the bottom-right corner of the grid, return the current effort 'd' as the result.

15. **Loop Constructs**
	```cpp
	        for(int k = 0; k < 4; k++) {
	```
	Start a for loop to explore the four possible directions (right, down, left, and up) from the current cell.

16. **Coordinate Update**
	```cpp
	            int ni = i + dir[k], nj = j + dir[k + 1];
	```
	Calculate the new coordinates (ni, nj) based on the current direction.

17. **Boundary Check**
	```cpp
	            if(min(ni, nj) < 0 || ni >= m || nj >= n) continue;
	```
	Check if the new coordinates (ni, nj) are out of bounds. If so, skip the current iteration.

18. **Effort Calculation**
	```cpp
	            int nxt = sz[ni][nj];
	```
	Get the current minimum effort stored for the neighboring cell (ni, nj).

19. **Effort Calculation**
	```cpp
	            int nd  = max(abs(h[i][j] - h[ni][nj]), d);
	```
	Calculate the new effort 'nd' required to move from the current cell to the neighboring cell, which is the maximum of the absolute elevation difference and the current effort.

20. **Conditional Check**
	```cpp
	            if (nxt > nd) {
	```
	If the new calculated effort 'nd' is smaller than the previously recorded effort for the neighboring cell, proceed to update it.

21. **State Update**
	```cpp
	                sz[ni][nj] = nd;
	```
	Update the minimum effort for the neighboring cell to the newly calculated effort.

22. **Queue Push**
	```cpp
	                pq.push({ni, nj, nd});
	```
	Push the updated state (ni, nj, nd) into the priority queue for further processing.

23. **Return Statement**
	```cpp
	    return 0;
	```
	Return 0 as a default value if no valid path is found (although this case should not occur with a valid input).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(rows * columns * log(rows * columns))
- **Average Case:** O(rows * columns * log(rows * columns))
- **Worst Case:** O(rows * columns * log(rows * columns))

The time complexity is dominated by the priority queue operations, which take log(rows * columns) time.

### Space Complexity 💾
- **Best Case:** O(rows * columns)
- **Worst Case:** O(rows * columns)

The space complexity is determined by the size of the priority queue and the auxiliary storage for visited cells.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-with-minimum-effort/description/)

---
{{< youtube XQlxCCx2vI4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
