
+++
authors = ["grid47"]
title = "Leetcode 2923: Find Champion I"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2923: Find Champion I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Matrix"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "23vlLuh_v6c"
youtube_upload_date="2023-11-05"
youtube_thumbnail="https://i.ytimg.com/vi/23vlLuh_v6c/maxresdefault.jpg"
comments = true
+++



---
In a tournament, there are 'n' teams, each represented by an index from 0 to n-1. You are given a 2D boolean matrix grid of size n x n, where the value at grid[i][j] is 1 if team 'i' is stronger than team 'j', and 0 otherwise. Your task is to determine the champion team, which is the team that no other team is stronger than.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D boolean matrix grid where grid[i][j] indicates if team 'i' is stronger than team 'j'.
- **Example:** `For input grid = [[0, 1], [0, 0]], the result is 0.`
- **Constraints:**
	- 2 <= n <= 100
	- grid[i][j] is either 0 or 1
	- grid[i][i] == 0
	- For all i != j, grid[i][j] != grid[j][i]

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the team that is the champion, or -1 if no such team exists.
- **Example:** `For input grid = [[0, 1], [0, 0]], the output is 0.`
- **Constraints:**
	- The output will always be a valid team index or -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the team that no other team can beat, i.e., the team that has a '1' in every column of the matrix corresponding to the teams that it is stronger than.

- Iterate through each row of the matrix.
- Sum the values in the row (excluding the diagonal).
- If the sum of a row equals n-1, that team is the champion.
{{< dots >}}
### Problem Assumptions ✅
- The grid matrix will always be valid and well-formed.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: grid = [[0, 1], [0, 0]]`  \
  **Explanation:** Here, team 0 is stronger than team 1, and there are only two teams. Thus, team 0 will be the champion.

- **Input:** `Example 2: grid = [[0, 0, 1], [1, 0, 1], [0, 0, 0]]`  \
  **Explanation:** In this case, team 1 is stronger than both team 0 and team 2, making team 1 the champion.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to identify the team that no other team can defeat. We can do this by summing the rows of the grid and checking if a row contains 'n-1' 1's.

### Initial Thoughts 💭
- The matrix represents a directed graph where each node (team) has directed edges (victories) to other teams.
- We are looking for a team that has outgoing edges to all other teams, and no other team has an outgoing edge to it.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty.
- The algorithm must handle the grid size up to 100 x 100.
- When n = 2, there will be exactly one possible champion.
- The grid will always follow the rules as described in the problem.
{{< dots >}}
## Code 💻
```cpp
int findChampion(vector<vector<int>>& g) {
    for (int i = 0; i < g.size(); ++i)
        if (accumulate(begin(g[i]), end(g[i]), 0) == g.size() - 1)
            return i;
    return -1;
}
```

This function identifies the 'champion' in a directed graph represented as an adjacency matrix. The champion is the node that is directed to by all other nodes but does not direct to any other node. The function returns the index of the champion node or -1 if no champion exists.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findChampion(vector<vector<int>>& g) {
	```
	Defines the function 'findChampion' that takes a 2D vector 'g', which represents a directed graph, and returns the index of the champion node.

2. **Loop Over Graph**
	```cpp
	    for (int i = 0; i < g.size(); ++i)
	```
	Iterates through each row of the adjacency matrix 'g'. Each row represents a node in the graph, and we are checking if it is a potential champion.

3. **Check Champion Condition**
	```cpp
	        if (accumulate(begin(g[i]), end(g[i]), 0) == g.size() - 1)
	```
	Uses the 'accumulate' function to sum up the values in the current row of the matrix. A champion node should have all other nodes pointing to it, so the sum must be equal to 'g.size() - 1', indicating that all other nodes point to this node.

4. **Return Champion**
	```cpp
	            return i;
	```
	If the current node satisfies the champion condition, the function returns its index as the champion.

5. **Return No Champion**
	```cpp
	    return -1;
	```
	If no champion node is found after checking all rows, the function returns -1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we will need to iterate through all teams and check each of their victories in the grid, leading to a time complexity of O(n^2).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

We are storing the entire grid, which requires O(n^2) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-champion-i/description/)

---
{{< youtube 23vlLuh_v6c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
