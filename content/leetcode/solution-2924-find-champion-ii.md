
+++
authors = ["grid47"]
title = "Leetcode 2924: Find Champion II"
date = "2024-01-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2924: Find Champion II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "axwSqMVQ1x4"
youtube_upload_date="2023-11-05"
youtube_thumbnail="https://i.ytimg.com/vi/axwSqMVQ1x4/maxresdefault.jpg"
comments = true
+++



---
In a tournament, there are 'n' teams numbered from 0 to n-1, where each team is represented as a node in a Directed Acyclic Graph (DAG). You are given an integer 'n' and a 2D integer array 'edges', where each element edges[i] = [ui, vi] indicates a directed edge from team 'ui' to team 'vi', meaning team 'ui' is stronger than team 'vi'. A team will be the champion of the tournament if no other team is stronger than it. If there is exactly one champion, return its index; otherwise, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two inputs: an integer 'n' representing the number of teams, and a 2D integer array 'edges' where each element defines a directed edge between two teams.
- **Example:** `For n = 3 and edges = [[0, 1], [1, 2]], the result will be 0.`
- **Constraints:**
	- 1 <= n <= 100
	- m == edges.length
	- 0 <= m <= n * (n - 1) / 2
	- edges[i].length == 2
	- 0 <= edge[i][j] <= n - 1
	- edges[i][0] != edges[i][1]
	- The input is generated such that there are no cycles in the graph.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the champion team if there is exactly one champion; otherwise, return -1.
- **Example:** `For n = 4 and edges = [[0, 2], [1, 3], [1, 2]], the output will be -1.`
- **Constraints:**
	- The output will either be a valid team index or -1 if no unique champion exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the team that has no incoming edges, meaning no other team is stronger than it. If more than one team has no incoming edges, return -1.

- Compute the indegree (number of incoming edges) for each team.
- Check how many teams have zero indegree.
- If exactly one team has zero indegree, that is the champion. Otherwise, return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input will be valid and follow the constraints specified.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 3, edges = [[0, 1], [1, 2]]`  \
  **Explanation:** In this case, team 0 is stronger than team 1, and team 1 is stronger than team 2. Therefore, team 0 is the champion because it has no incoming edges.

- **Input:** `Example 2: n = 4, edges = [[0, 2], [1, 3], [1, 2]]`  \
  **Explanation:** Here, both teams 0 and 1 have no incoming edges, meaning there is no unique champion. Therefore, the result is -1.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the team that no other team is stronger than. We can do this by calculating the indegree of each team and determining if there is exactly one team with zero indegree.

### Initial Thoughts 💭
- The problem is based on identifying the root node(s) in a DAG, where the root node has no incoming edges.
- We need to keep track of the indegrees for each team and check if there is exactly one team with an indegree of zero.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty since there is always at least one team.
- The algorithm should efficiently handle the upper limit where n = 100.
- When n = 1, the only team will be the champion.
- The graph will always be acyclic, and no team will be stronger than itself.
{{< dots >}}
## Code 💻
```cpp
int findChampion(int n, vector<vector<int>>& edges) {
    int ans = -1, count = 0;
    vector<int> indegree(n, 0);
    for(auto e: edges) indegree[e[1]]++;
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0) {count++; ans = i; }
    }
    return count > 1?-1:ans;
}
```

This function identifies the champion (or leader) in a directed graph represented by the edges list. The champion is a node that has no incoming edges (indegree 0) and is the only one with this property. The function returns the index of the champion, or -1 if there is no unique champion.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findChampion(int n, vector<vector<int>>& edges) {
	```
	Defines the 'findChampion' function, which takes the number of nodes 'n' and a list of directed edges 'edges' as input, returning the index of the champion or -1 if there is no unique champion.

2. **Variable Initialization**
	```cpp
	    int ans = -1, count = 0;
	```
	Initializes variables: 'ans' to store the champion node (default is -1), and 'count' to track how many nodes have indegree 0.

3. **Indegree Array Setup**
	```cpp
	    vector<int> indegree(n, 0);
	```
	Creates a vector 'indegree' of size 'n' to store the indegree of each node. Initially, all values are set to 0.

4. **Indegree Calculation**
	```cpp
	    for(auto e: edges) indegree[e[1]]++;
	```
	Iterates over the list of directed edges, incrementing the indegree of the destination node 'e[1]' for each edge.

5. **Loop Over Nodes**
	```cpp
	    for(int i = 0; i < n; ++i) {
	```
	Iterates over all nodes in the graph to check which node has indegree 0.

6. **Champion Detection**
	```cpp
	        if(indegree[i] == 0) {count++; ans = i; }
	```
	If a node has indegree 0 (no incoming edges), it is a potential champion. The 'count' is incremented, and 'ans' is set to the current node index 'i'.

7. **Return Result**
	```cpp
	    return count > 1?-1:ans;
	```
	Returns the champion node if exactly one node has indegree 0, otherwise returns -1 if there are multiple such nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(m + n)
- **Worst Case:** O(m + n)

The time complexity depends on the number of teams (n) and edges (m). In the worst case, we iterate through all edges and teams.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n + m)

We need space for the indegree array and the input edges.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-champion-ii/description/)

---
{{< youtube axwSqMVQ1x4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
