
+++
authors = ["grid47"]
title = "Leetcode 1443: Minimum Time to Collect All Apples in a Tree"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1443: Minimum Time to Collect All Apples in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xdt5Z583auM"
youtube_upload_date="2023-01-11"
youtube_thumbnail="https://i.ytimg.com/vi/Xdt5Z583auM/maxresdefault.jpg"
comments = true
+++



---
You are given an undirected tree with `n` vertices numbered from `0` to `n-1`. Some vertices in this tree contain apples. Each edge in the tree requires `1 second` to traverse. Starting at vertex `0`, determine the minimum time required to collect all apples and return to vertex `0`. The tree structure is described by the array `edges`, where `edges[i] = [ai, bi]` indicates an edge between vertices `ai` and `bi`. Additionally, the array `hasApple` specifies whether a vertex contains an apple (`true`) or not (`false`).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The number of vertices `n`, the list of edges representing the tree, and the boolean array `hasApple`.
- **Example:** `Input: n = 5, edges = [[0,1],[0,2],[1,3],[1,4]], hasApple = [false,true,true,false,false]`
- **Constraints:**
	- 1 <= n <= 10^5
	- edges.length == n - 1
	- 0 <= ai, bi < n
	- Each vertex is part of exactly one connected component.
	- hasApple.length == n

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the minimum time in seconds to collect all apples and return to vertex `0`.
- **Example:** `Output: 6`
- **Constraints:**
	- The output must be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum traversal time to collect all apples and return to the starting point.

- Construct a graph from the edges.
- Use a Depth-First Search (DFS) to traverse the tree starting from vertex `0`.
- For each subtree, calculate the time required to collect apples.
- Avoid unnecessary traversal if no apples are present in a subtree.
{{< dots >}}
### Problem Assumptions ✅
- The tree is connected and acyclic.
- The input tree has exactly `n-1` edges.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, edges = [[0,1],[0,2],[1,3],[2,4],[2,5]], hasApple = [false,false,true,false,true,true]`  \
  **Explanation:** The optimal path involves visiting vertices 2, 4, and 5. The total time is `8` seconds.

- **Input:** `Input: n = 4, edges = [[0,1],[0,2],[1,3]], hasApple = [false,false,false,false]`  \
  **Explanation:** No apples exist, so the output is `0`.

{{< dots >}}
## Approach 🚀
Use Depth-First Search (DFS) to traverse the tree and calculate the minimal traversal time.

### Initial Thoughts 💭
- Traversing unnecessary paths increases the time.
- Each edge should only be traversed if it leads to an apple.
- Using DFS ensures that we only traverse relevant subtrees containing apples.
{{< dots >}}
### Edge Cases 🌐
- Input: n = 1, edges = [], hasApple = [false] -> Output: 0
- Input: n = 10^5 with a sparse distribution of apples -> Should run within time constraints.
- Input: All vertices have apples -> Every edge will be traversed.
- Ensure no cycles exist in the graph structure.
{{< dots >}}
## Code 💻
```cpp
class Solution {
map<int, vector<int>> gph;
map<int, int> visited;
vector<bool> hasApple;
public:
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    this->hasApple = hasApple;
    for(auto x: edges) {
        gph[x[0]].push_back(x[1]);
        gph[x[1]].push_back(x[0]);
    }
    
    return dfs(0, 0);
}

int dfs(int mycost, int node) {
    if(visited[node]) return 0;
    visited[node] = true;
    int childcost = 0;
    for(int x: gph[node]) {
        childcost += dfs(2, x);
    }
    if(childcost == 0 && hasApple[node] == false)
        return 0;
    
    return childcost + mycost;
}
```

The `minTime` function calculates the minimum time required to collect all apples in a tree-like structure using depth-first search (DFS). It uses a graph to represent the tree and performs DFS from the root to accumulate the cost for each node that has an apple.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Defines the `Solution` class that will contain the logic for the problem, including the graph representation and the depth-first search function.

2. **Graph Initialization**
	```cpp
	map<int, vector<int>> gph;
	```
	Declares a map `gph` to store the graph as an adjacency list, where each node points to a list of connected nodes (edges).

3. **Visited Nodes**
	```cpp
	map<int, int> visited;
	```
	Declares a map `visited` to keep track of the nodes that have been visited during the DFS traversal to avoid reprocessing the same node.

4. **Apple Nodes**
	```cpp
	vector<bool> hasApple;
	```
	Declares a vector `hasApple` to track whether a node contains an apple, where each element in the vector corresponds to a node.

5. **Access Control**
	```cpp
	public:
	```
	Marks the beginning of the public section of the class, where methods can be accessed by other parts of the program.

6. **minTime Method**
	```cpp
	int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
	```
	Defines the `minTime` method, which calculates the minimum time to collect all apples. It takes the number of nodes, a list of edges, and a list of boolean values representing nodes with apples.

7. **Apple Assignment**
	```cpp
	    this->hasApple = hasApple;
	```
	Assigns the `hasApple` parameter to the class's `hasApple` member variable, enabling access to the apple information for each node.

8. **Graph Construction**
	```cpp
	    for(auto x: edges) {
	```
	Iterates over each edge in the `edges` list to build the graph (adjacency list). Each edge connects two nodes, represented by `x[0]` and `x[1]`.

9. **Graph Population**
	```cpp
	        gph[x[0]].push_back(x[1]);
	```
	Adds the second node `x[1]` to the adjacency list of the first node `x[0]`, establishing an undirected connection.

10. **Graph Population**
	```cpp
	        gph[x[1]].push_back(x[0]);
	```
	Adds the first node `x[0]` to the adjacency list of the second node `x[1]`, completing the undirected connection between the two nodes.

11. **DFS Call**
	```cpp
	    return dfs(0, 0);
	```
	Calls the `dfs` method starting from node 0 (the root) with an initial cost of 0 and returns the total time required to collect all apples.

12. **DFS Method**
	```cpp
	int dfs(int mycost, int node) {
	```
	Defines the `dfs` method, which performs a depth-first search to calculate the total time for collecting apples from a given node. It takes the current cost (`mycost`) and the node to explore (`node`).

13. **Visited Check**
	```cpp
	    if(visited[node]) return 0;
	```
	Checks if the current node has already been visited. If it has, returns 0 to avoid redundant calculations.

14. **Mark as Visited**
	```cpp
	    visited[node] = true;
	```
	Marks the current node as visited to prevent revisiting it in future DFS calls.

15. **Child Cost Initialization**
	```cpp
	    int childcost = 0;
	```
	Initializes a variable `childcost` to accumulate the cost of traversing the child nodes.

16. **Child Node Exploration**
	```cpp
	    for(int x: gph[node]) {
	```
	Iterates over all the child nodes of the current node (`node`) in the graph.

17. **Recursive DFS Call**
	```cpp
	        childcost += dfs(2, x);
	```
	Makes a recursive call to `dfs` for each child node, with a cost of 2 (the fixed cost to move to a child node) and accumulates the returned `childcost`.

18. **Apple Check**
	```cpp
	    if(childcost == 0 && hasApple[node] == false)
	```
	Checks if the current node has no child nodes contributing to the cost and does not contain an apple. If true, it returns 0 to indicate no further action is needed for this node.

19. **Return Zero**
	```cpp
	        return 0;
	```
	Returns 0 when the current node has no apple and no child nodes contributing to the cost.

20. **Return Total Cost**
	```cpp
	    return childcost + mycost;
	```
	Returns the total accumulated cost of traversing from the current node, including the cost of its child nodes and the fixed cost (`mycost`) for visiting the node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each vertex and edge is visited at most once during DFS.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The adjacency list and recursion stack require linear space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

---
{{< youtube Xdt5Z583auM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
