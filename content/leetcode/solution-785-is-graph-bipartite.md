
+++
authors = ["grid47"]
title = "Leetcode 785: Is Graph Bipartite?"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 785: Is Graph Bipartite? in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp"
youtube = "j69Of_2nfRA"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/j69Of_2nfRA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/785.webp" 
    alt="A graph where bipartiteness is checked, with the two sets glowing softly as they are separated."
    caption="Solution to LeetCode 785: Is Graph Bipartite? Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an undirected graph where each node is labeled between 0 and n - 1. The graph is represented as a 2D array, where graph[u] contains the nodes that are adjacent to node u. A graph is bipartite if its nodes can be divided into two sets such that every edge connects a node from one set to a node in the other set. Your task is to return true if the graph is bipartite, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array graph, where each graph[u] contains the nodes adjacent to node u.
- **Example:** `Input: graph = [[1, 2], [0, 2], [0, 1]]`
- **Constraints:**
	- 1 <= n <= 100
	- 0 <= graph[u].length < n
	- graph[u] contains unique nodes
	- If graph[u] contains v, graph[v] contains u

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: true if the graph is bipartite, false otherwise.
- **Example:** `Output: false`
- **Constraints:**
	- The function must return true if the graph is bipartite, false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if the graph can be divided into two independent sets such that every edge connects a node from one set to a node in the other set.

- Initialize a structure to represent the two sets.
- Traverse the graph using DFS or BFS, and assign nodes alternately to the two sets.
- If you find any edge connecting two nodes in the same set, return false. Otherwise, return true.
{{< dots >}}
### Problem Assumptions ✅
- There are no self-edges in the graph.
- There are no parallel edges between nodes.
- The graph may have disconnected components.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: Input: graph = [[1, 2], [0, 2], [0, 1]]`  \
  **Explanation:** In this example, the graph has 3 nodes, and no way exists to divide them into two independent sets where each edge connects a node from one set to a node from the other set.

- **Input:** `Example 2: Input: graph = [[1, 3], [0, 2], [1, 3], [0, 2]]`  \
  **Explanation:** In this case, the graph can be divided into two independent sets: {0, 2} and {1, 3}, such that every edge connects nodes between the sets.

{{< dots >}}
## Approach 🚀
We can use BFS or DFS to try to assign nodes to two sets. Starting from any node, we attempt to assign its neighbors to the opposite set. If at any point, a node is found to have a neighbor in the same set, we return false. If we can traverse the entire graph successfully, the graph is bipartite.

### Initial Thoughts 💭
- The graph may not be connected, so we need to perform a traversal for each disconnected component.
- We can check the bipartite property by coloring the graph using BFS/DFS, where two adjacent nodes should have different colors.
{{< dots >}}
### Edge Cases 🌐
- The graph will always contain at least one node.
- The function should handle up to 100 nodes efficiently.
- If the graph has only one node, it is trivially bipartite.
- The input graph will be within the problem's constraints (1 <= n <= 100).
{{< dots >}}
## Code 💻
```cpp
bool isBipartite(vector<vector<int>>& gph) {
    int n = gph.size();
      UF* uf = new UF(n);

    for(int i = 0; i < n; i++) {
        for(int x: gph[i]) {
            if(uf->find(x) == uf->find(i)) return false;
            uf->uni(gph[i][0], x);
        }
    }
    return true;      
}
```

This is the implementation of a function that checks whether a graph is bipartite using union-find (disjoint-set).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isBipartite(vector<vector<int>>& gph) {
	```
	This is the function signature for checking if a graph is bipartite. It takes a 2D vector 'gph' as input, representing the adjacency list of the graph.

2. **Variable Initialization**
	```cpp
	    int n = gph.size();
	```
	This line initializes 'n' as the number of nodes in the graph, based on the size of the adjacency list.

3. **Union-Find Initialization**
	```cpp
	      UF* uf = new UF(n);
	```
	A new union-find data structure is initialized with 'n' nodes. It is used to track connected components in the graph.

4. **Loop Over Nodes**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This starts a loop that iterates over each node in the graph.

5. **Loop Over Adjacent Nodes**
	```cpp
	        for(int x: gph[i]) {
	```
	This inner loop iterates over the adjacent nodes (neighbors) of node 'i'.

6. **Union-Find Check**
	```cpp
	            if(uf->find(x) == uf->find(i)) return false;
	```
	If the current node 'i' and its neighbor 'x' are in the same set (found by the union-find structure), the graph is not bipartite, so it returns 'false'.

7. **Union Operation**
	```cpp
	            uf->uni(gph[i][0], x);
	```
	If the nodes are not in the same set, a union operation is performed to connect them.

8. **Return True**
	```cpp
	    return true;      
	```
	If no conflicts are found, the graph is bipartite, and 'true' is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + e), where n is the number of nodes and e is the number of edges.
- **Average Case:** O(n + e), as each node and edge is visited once.
- **Worst Case:** O(n + e), as we must traverse all nodes and edges in the worst case.

The time complexity is linear in terms of the number of nodes and edges in the graph.

### Space Complexity 💾
- **Best Case:** O(n), as space is needed for the color array.
- **Worst Case:** O(n), where n is the number of nodes, for storing the color array.

The space complexity is linear in the number of nodes due to the color array used for BFS/DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/is-graph-bipartite/description/)

---
{{< youtube j69Of_2nfRA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
