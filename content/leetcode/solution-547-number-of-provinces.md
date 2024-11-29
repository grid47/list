
+++
authors = ["grid47"]
title = "Leetcode 547: Number of Provinces"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 547: Number of Provinces in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/547.webp"
youtube = "p5Ocm71wB0E"
youtube_upload_date="2021-02-07"
youtube_thumbnail="https://i.ytimg.com/vi/p5Ocm71wB0E/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/547.webp" 
    alt="A map of regions where provinces are counted and highlighted, each province glowing softly."
    caption="Solution to LeetCode 547: Number of Provinces Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a matrix where each element indicates if two cities are directly connected. Your task is to determine the number of provinces formed by the cities. A province is a group of directly or indirectly connected cities.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is an n x n matrix 'isConnected' where 'isConnected[i][j]' is 1 if city 'i' is connected directly to city 'j', and 0 otherwise.
- **Example:** `Input: isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]`
- **Constraints:**
	- 1 <= n <= 200
	- n == isConnected.length
	- n == isConnected[i].length
	- isConnected[i][j] is 1 or 0.
	- isConnected[i][i] == 1
	- isConnected[i][j] == isConnected[j][i]

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of provinces in the network of cities.
- **Example:** `Output: 2`
- **Constraints:**
	- The output is an integer representing the total number of provinces.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the number of provinces by grouping cities that are connected directly or indirectly.

- Use a depth-first search (DFS) or union-find approach to group cities that are directly or indirectly connected.
- Track the groups of cities and count how many separate groups (provinces) there are.
{{< dots >}}
### Problem Assumptions ✅
- The input matrix is always valid and satisfies the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]`  \
  **Explanation:** In this example, there are two provinces: one consisting of city 1 and city 2, and the second consisting only of city 3.

{{< dots >}}
## Approach 🚀
We can solve this problem using either Depth-First Search (DFS) or Union-Find algorithms. Both approaches will allow us to group cities that are connected either directly or indirectly.

### Initial Thoughts 💭
- We need to find groups of connected cities.
- This can be done by either performing DFS for each unvisited city or by using union-find to group connected cities.
- Using DFS, we can traverse the matrix and mark all connected cities as visited for each unvisited city, which will allow us to count the number of provinces.
{{< dots >}}
### Edge Cases 🌐
- The input matrix will always contain at least one city, so there will never be an empty input.
- The algorithm should efficiently handle matrices up to 200 x 200 in size.
- If all cities are isolated (no connections), each city forms its own province.
- Ensure the algorithm handles the matrix dimensions efficiently for the upper limit of 200 cities.
{{< dots >}}
## Code 💻
```cpp
int findCircleNum(vector<vector<int>>& grid) {
    int n = grid.size();
    UnionFind* uf = new UnionFind(n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
        if(grid[i][j] == 1) uf->join(i, j);
    
    return uf->grp;
}
```

This function finds the number of connected components (or friend circles) in a given 2D grid, where each cell represents a person, and a value of 1 indicates a friendship. The function uses Union-Find (Disjoint Set Union) to merge connected people and returns the number of disjoint sets (friend circles).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findCircleNum(vector<vector<int>>& grid) {
	```
	Defines the function `findCircleNum`, which calculates the number of connected components (friend circles) in the given `grid`.

2. **Matrix Size Calculation**
	```cpp
	    int n = grid.size();
	```
	Calculates the size of the grid (number of rows/columns) and stores it in variable `n`.

3. **UnionFind Initialization**
	```cpp
	    UnionFind* uf = new UnionFind(n);
	```
	Creates a new instance of the `UnionFind` class, initializing it with the grid size `n`. This object will be used to manage the union and find operations for the friend circles.

4. **Outer Loop (Row Traversal)**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts the outer loop to traverse each row in the grid.

5. **Inner Loop (Column Traversal)**
	```cpp
	    for(int j = 0; j < n; j++)
	```
	Starts the inner loop to traverse each column in the current row of the grid.

6. **Union Operation**
	```cpp
	        if(grid[i][j] == 1) uf->join(i, j);
	```
	Checks if there is a friendship (grid[i][j] == 1). If true, performs a `union` operation to merge the sets of `i` and `j` using the `join` method of the `UnionFind` class.

7. **Return Statement**
	```cpp
	    return uf->grp;
	```
	Returns the number of distinct groups (friend circles) found in the grid, which is stored in the `grp` attribute of the `UnionFind` object.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Since we need to process each entry in the matrix to determine connectivity, the time complexity is O(n^2).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is O(n) for the visited array, and O(n^2) for storing the matrix.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-provinces/description/)

---
{{< youtube p5Ocm71wB0E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
