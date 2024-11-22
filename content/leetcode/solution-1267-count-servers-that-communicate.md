
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---



### Problem Statement
In a 2D grid representing a network of servers, a server is represented by a value of `1`, and an empty space is represented by a value of `0`. A server is considered "active" if it can communicate with at least one other server in the same row or column. The objective is to determine the total number of active servers in the grid.

Given a grid of dimensions \( m \times n \), your task is to count the number of servers that can communicate with at least one other server. This involves examining each server and checking the count of servers in its corresponding row and column.

### Approach
To solve this problem efficiently, we can utilize the following approach:

1. **Count Servers in Rows and Columns**: We traverse the grid to count the number of servers present in each row and each column.
2. **Determine Active Servers**: In a second traversal of the grid, we check each server. A server is considered active if:
   - It is present in a row that contains more than one server, or
   - It is present in a column that contains more than one server.
3. **Accumulate Results**: We maintain a counter to keep track of the total number of active servers.

This approach allows us to reduce the complexity of checking for active servers significantly, making it more efficient than checking each server individually.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
```
- **Line 1-3**: The `Solution` class is defined, containing the public member function `countServers`, which takes a 2D vector `grid` representing the network of servers.

```cpp
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0), col(n, 0);
```
- **Line 4-5**: We first determine the number of rows (`m`) and columns (`n`) in the grid. Then, we initialize two vectors, `row` and `col`, to store the count of servers for each row and each column, respectively.

```cpp
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
```
- **Line 6-11**: We perform a nested loop through the grid to count the servers:
  - The outer loop iterates through each row \(i\).
  - The inner loop iterates through each column \(j\).
  - If a cell contains a server (`grid[i][j] == 1`), we increment the respective counts in the `row` and `col` arrays.

```cpp
        int res = 0;
```
- **Line 12**: We initialize an integer variable `res` to zero. This variable will store the total count of active servers.

```cpp
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if((grid[i][j] == 1) && ((row[i] > 1) || (col[j] > 1))) {
                    res++;
                }
            }
        }
```
- **Line 13-19**: We conduct a second nested loop through the grid to determine which servers are active:
  - For each cell, we check if it contains a server.
  - We then check if either the count of servers in its row or the count in its column is greater than one.
  - If either condition is true, we increment the `res` counter.

```cpp
        return res;
    }
};
```
- **Line 20**: Finally, we return the value of `res`, which represents the total number of active servers in the grid.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity of this solution is \(O(m \times n)\), where \(m\) is the number of rows and \(n\) is the number of columns in the grid. We make two complete passes over the grid: one for counting the servers and another for determining active servers.

2. **Space Complexity**:
   - The space complexity is \(O(m + n)\) due to the use of two additional arrays (`row` and `col`) to store the counts of servers for each row and column.

### Conclusion
The `countServers` function provides an efficient solution for determining the number of active servers in a given grid. By utilizing a two-pass approach, the function effectively counts the servers and evaluates their communication capabilities without redundant checks. This algorithm is particularly advantageous for larger grids, as it maintains a linear relationship between the input size and execution time.

In summary, this solution illustrates the effectiveness of organizing data into counts for improved computational efficiency. By focusing on the relationships between the servers in the grid rather than individual comparisons, the function elegantly solves the problem with optimal performance. Such techniques can be applied to various grid-related problems, making them a valuable tool in algorithmic problem-solving.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-servers-that-communicate/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
