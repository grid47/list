
+++
authors = ["grid47"]
title = "Leetcode 802: Find Eventual Safe States"
date = "2024-08-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 802: Find Eventual Safe States in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp"
youtube = "Re_v0j0CRsg"
youtube_upload_date="2022-04-09"
youtube_thumbnail="https://i.ytimg.com/vi/Re_v0j0CRsg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/802.webp" 
    alt="A graph with nodes marked as safe, glowing softly as they are identified."
    caption="Solution to LeetCode 802: Find Eventual Safe States Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a directed graph where each node represents a point, and edges represent possible transitions between nodes. A node is considered terminal if it has no outgoing edges. A node is deemed safe if every path starting from it leads either to a terminal node or another safe node. Your task is to identify all the safe nodes in the graph and return them in ascending order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a graph represented as a 2D array, where each node's adjacency list is provided, followed by the conditions of the graph's nodes.
- **Example:** `Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]`
- **Constraints:**
	- n == graph.length
	- 1 <= n <= 10^4
	- 0 <= graph[i].length <= n
	- 0 <= graph[i][j] <= n - 1
	- graph[i] is sorted in a strictly increasing order

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers representing the safe nodes in the graph, sorted in ascending order.
- **Example:** `Output: [2,4,5,6]`
- **Constraints:**
	- The returned array should be sorted in ascending order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To identify and return the safe nodes in the graph by using depth-first search (DFS) to track nodes that lead to terminal or safe nodes.

- Perform a depth-first search (DFS) to determine which nodes are safe.
- Track the visiting status of nodes (unvisited, visiting, or safe) to avoid cycles.
- Return all nodes that are identified as safe, ensuring they are in ascending order.
{{< dots >}}
### Problem Assumptions ✅
- The graph may contain self-loops or cycles, but the traversal will ensure safe nodes are correctly identified.
- Each node is either part of a cycle or leads to a terminal node or a safe node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]`  \
  **Explanation:** In this graph, nodes 5 and 6 are terminal nodes because they have no outgoing edges. Nodes 2, 4, 5, and 6 are safe since all paths starting from these nodes lead either to a terminal node or another safe node.

- **Input:** `Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]`  \
  **Explanation:** In this case, node 4 is the only terminal node, and it is safe. The paths starting at node 4 always lead to itself, making it a safe node.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a depth-first search (DFS) approach to explore each node and determine if it is safe based on its outgoing edges and the nodes it leads to.

### Initial Thoughts 💭
- Safe nodes can be identified by ensuring all paths from them eventually lead to terminal nodes or other safe nodes.
- We will perform DFS from each node, tracking its status as either visiting, visited, or safe. Nodes that are part of cycles or lead to unsafe paths will not be marked as safe.
{{< dots >}}
### Edge Cases 🌐
- If the graph has no nodes, there are no safe nodes to return.
- For large inputs, ensure the DFS algorithm is optimized to handle up to 10^4 nodes efficiently.
- If the graph contains self-loops, treat them carefully by marking the node as unsafe if it leads to itself in a cycle.
- Ensure that the solution is efficient given the graph constraints, particularly the number of nodes and edges.
{{< dots >}}
## Code 💻
```cpp
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    vector<int> res;

    int n = graph.size();

    if(n == 0) return res;

    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++)
        if(dfs(graph, i, vis)) res.push_back(i);

    return res;
}

int dfs(vector<vector<int>>& graph, int cur, vector<int> &vis) {

    if(vis[cur] != 0) return vis[cur] == 2;

    vis[cur] = 1;
    for(auto nxt: graph[cur])
        if(!dfs(graph, nxt, vis)) return false;

    vis[cur] = 2;

    return true;
}

```

This code finds all the eventual safe nodes in a directed graph represented as an adjacency list. A node is considered safe if there is no cycle that leads to it. The DFS approach is used to explore the graph, marking nodes as visited and checking for cycles.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	```
	This is the function signature that defines the main function, `eventualSafeNodes`, which takes a graph (a vector of vectors of integers) as input and returns a vector of integers representing the safe nodes.

2. **Variable Declaration**
	```cpp
	    vector<int> res;
	```
	A vector `res` is declared to store the eventual safe nodes that will be found during the DFS traversal.

3. **Variable Declaration**
	```cpp
	    int n = graph.size();
	```
	The variable `n` is initialized to store the size of the graph (i.e., the number of nodes).

4. **Condition**
	```cpp
	    if(n == 0) return res;
	```
	If the graph is empty (n == 0), an empty vector `res` is returned as there are no nodes to process.

5. **Variable Initialization**
	```cpp
	    vector<int> vis(n, 0);
	```
	A `vis` vector is initialized with zeroes, where each element represents the visitation state of a node (0 = not visited, 1 = visiting, 2 = visited).

6. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A for loop is used to iterate over all the nodes in the graph, starting from node 0 to node n-1.

7. **Conditional**
	```cpp
	        if(dfs(graph, i, vis)) res.push_back(i);
	```
	For each node, the DFS function is called to check if it's an eventual safe node. If the node is safe (DFS returns true), it is added to the result vector `res`.

8. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the vector `res`, which contains all the safe nodes found during the DFS traversal.

9. **Function**
	```cpp
	int dfs(vector<vector<int>>& graph, int cur, vector<int> &vis) {
	```
	This is the helper function `dfs` that performs depth-first search to explore the graph from a given node `cur`.

10. **Condition**
	```cpp
	    if(vis[cur] != 0) return vis[cur] == 2;
	```
	If the node `cur` has already been visited (its state is not 0), the function returns whether the node is safe (state 2 means safe).

11. **Mark Node as Visiting**
	```cpp
	    vis[cur] = 1;
	```
	The node `cur` is marked as visiting (state 1) to indicate that it's being explored.

12. **Loop**
	```cpp
	    for(auto nxt: graph[cur])
	```
	The function iterates over all the neighboring nodes (`nxt`) of the current node `cur`.

13. **Conditional**
	```cpp
	        if(!dfs(graph, nxt, vis)) return false;
	```
	For each neighboring node `nxt`, the DFS function is called recursively. If any neighbor leads to a cycle (DFS returns false), the current node is not safe, and the function returns false.

14. **Mark Node as Safe**
	```cpp
	    vis[cur] = 2;
	```
	Once all the neighbors have been processed and no cycle is detected, the current node `cur` is marked as safe (state 2).

15. **Return Statement**
	```cpp
	    return true;
	```
	The function returns true, indicating that the current node `cur` is safe.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + e), where n is the number of nodes and e is the number of edges in the graph.
- **Average Case:** O(n + e), as DFS will visit each node and edge at most once.
- **Worst Case:** O(n + e), since each node and edge must be processed during DFS traversal.

The time complexity is linear in terms of the number of nodes and edges in the graph.

### Space Complexity 💾
- **Best Case:** O(n), since the space needed to store node status and recursion stack is proportional to the number of nodes.
- **Worst Case:** O(n), as we need to store the status of each node during the DFS traversal.

The space complexity is linear with respect to the number of nodes in the graph.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-eventual-safe-states/description/)

---
{{< youtube Re_v0j0CRsg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
