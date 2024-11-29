
+++
authors = ["grid47"]
title = "Leetcode 1267: Count Servers that Communicate"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1267: Count Servers that Communicate in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Breadth-First Search","Union Find","Matrix","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a 2D grid where each cell is either 1 (indicating a server) or 0 (no server). Two servers are said to communicate if they are in the same row or column. The task is to find the number of servers that can communicate with at least one other server.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A 2D grid of size m x n where each cell is either 1 (server) or 0 (no server).
- **Example:** `grid = [[1,0],[0,1]]`
- **Constraints:**
	- 1 <= m <= 250
	- 1 <= n <= 250
	- grid[i][j] == 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of servers that can communicate with at least one other server.
- **Example:** `Output: 0`
- **Constraints:**
	- The returned number should be an integer representing the number of servers that can communicate with another server.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count how many servers can communicate with at least one other server by checking the row and column of each server.

- 1. Iterate through each row and column of the grid, counting the number of servers in each row and column.
- 2. After counting, iterate again to check for servers that have more than one server in their row or column.
- 3. Return the count of servers that can communicate with another server.
{{< dots >}}
### Problem Assumptions ✅
- The grid will contain only 0s and 1s.
{{< dots >}}
## Examples 🧩
- **Input:** `grid = [[1,0],[0,1]]`  \
  **Explanation:** This is a simple case with two servers that cannot communicate with each other because they are not in the same row or column.

- **Input:** `grid = [[1,0],[1,1]]`  \
  **Explanation:** In this case, all three servers can communicate with at least one other server.

{{< dots >}}
## Approach 🚀
We need to count how many servers can communicate with other servers. The most efficient way is to check each server’s row and column to see if there are other servers present.

### Initial Thoughts 💭
- We need to check the row and column of each server to determine if it has another server it can communicate with.
- The approach involves counting the number of servers in each row and each column. Then we can check for each server if it belongs to a row or column that has more than one server.
{{< dots >}}
### Edge Cases 🌐
- If the grid has no servers (all 0s), the result will be 0.
- The solution should be optimized to handle grids of size up to 250x250.
- If a server is isolated (its row and column have no other servers), it cannot communicate with any other server.
- The solution must handle grids up to the maximum constraint of 250x250 efficiently.
{{< dots >}}
## Code 💻
```cpp
int countServers(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> row(m, 0), col(n, 0);
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 1) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if((grid[i][j] == 1) && ((row[i] > 1) || (col[j] > 1))) {
                res++;
            }
        }
    }
    
    return res;
}
```

This code defines a function `countServers` that counts how many servers are in a grid where each server can communicate with at least one other server either in the same row or the same column.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countServers(vector<vector<int>>& grid) {
	```
	This defines the function `countServers` that takes a 2D grid `grid` of size `m x n`, where each element indicates whether there's a server (1) or not (0). The function returns the total number of servers that can communicate with at least one other server.

2. **Grid Dimensions**
	```cpp
	    int m = grid.size(), n = grid[0].size();
	```
	This line calculates the number of rows (`m`) and columns (`n`) in the grid.

3. **Row and Column Tracking**
	```cpp
	    vector<int> row(m, 0), col(n, 0);
	```
	This initializes two vectors, `row` and `col`, to track the number of servers in each row and each column, respectively.

4. **Nested Loops (Grid Iteration)**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This outer loop iterates over each row in the grid.

5. **Nested Loops (Inner Grid Iteration)**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	This inner loop iterates over each column in the current row of the grid.

6. **Incrementing Row and Column Counts**
	```cpp
	            if(grid[i][j] == 1) {
	```
	This checks if there's a server at position (i, j) in the grid.

7. **Update Row and Column Servers**
	```cpp
	                row[i]++;
	```
	If there is a server in the current cell, it increments the count of servers in the `i`-th row.

8. **Update Row and Column Servers**
	```cpp
	                col[j]++;
	```
	It also increments the count of servers in the `j`-th column.

9. **Result Initialization**
	```cpp
	    int res = 0;
	```
	This initializes a variable `res` to 0, which will store the count of servers that can communicate with at least one other server.

10. **Nested Loops (Second Grid Iteration)**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	This loop iterates again over the rows of the grid.

11. **Nested Loops (Inner Grid Iteration)**
	```cpp
	        for(int j = 0; j < n; j++) {
	```
	This inner loop iterates over each column in the current row again.

12. **Check Communication Condition**
	```cpp
	            if((grid[i][j] == 1) && ((row[i] > 1) || (col[j] > 1))) {
	```
	This checks if there's a server at position (i, j) and if the server can communicate with another server in the same row or column.

13. **Increment Result**
	```cpp
	                res++;
	```
	If the server can communicate with another, it increments the result `res`.

14. **Return Statement**
	```cpp
	    return res;
	```
	This returns the total count of servers that can communicate with at least one other server.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n) because we iterate through the entire grid twice.

### Space Complexity 💾
- **Best Case:** O(m + n)
- **Worst Case:** O(m + n)

The space complexity is O(m + n) because we store counts for rows and columns.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-servers-that-communicate/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
