
+++
authors = ["grid47"]
title = "Leetcode 1971: Find if Path Exists in Graph"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1971: Find if Path Exists in Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "knLFe7hEp3Y"
youtube_upload_date="2024-05-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/knLFe7hEp3Y/maxresdefault.webp"
comments = true
+++



---
You are given a graph with `n` vertices labeled from 0 to `n-1` (inclusive) and edges connecting pairs of vertices. Your task is to determine if there exists a valid path from a given source vertex to a destination vertex. The graph is undirected, and each pair of vertices is connected by at most one edge. The vertices are connected by edges as given in the input.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following components: an integer `n`, representing the number of vertices, a 2D array `edges` representing the edges between vertices, and two integers `source` and `destination` which are the starting and ending vertices respectively.
- **Example:** `n = 4, edges = [[0,1],[1,2],[2,3]], source = 0, destination = 3`
- **Constraints:**
	- 1 <= n <= 2 * 10^5
	- 0 <= edges.length <= 2 * 10^5
	- edges[i].length == 2
	- 0 <= ui, vi <= n - 1
	- ui != vi
	- 0 <= source, destination <= n - 1
	- There are no duplicate edges.
	- There are no self edges.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value, `true` if there is a valid path from the source to the destination vertex, and `false` otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The solution must be able to handle large graphs efficiently.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if a valid path exists from the source to the destination vertex by performing a breadth-first search (BFS) or depth-first search (DFS) in the graph.

- Step 1: Represent the graph using an adjacency list where each vertex points to a list of connected vertices.
- Step 2: Use BFS (or DFS) starting from the source vertex to explore all reachable vertices.
- Step 3: If the destination vertex is found during the traversal, return `true`.
- Step 4: If the traversal completes without visiting the destination vertex, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The graph is connected and there may be multiple paths from source to destination.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2`  \
  **Explanation:** In this case, there is a direct path from vertex 0 to vertex 2, or a path through vertex 1 (0 -> 1 -> 2), so the output is `true`.

- **Input:** `Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5`  \
  **Explanation:** In this case, there is no path from vertex 0 to vertex 5, so the output is `false`.

{{< dots >}}
## Approach 🚀
We can approach this problem by performing a graph traversal (BFS or DFS) to check if a path exists between the source and destination vertices. The traversal should explore all connected vertices from the source and check if the destination is reachable.

### Initial Thoughts 💭
- The problem can be efficiently solved using BFS or DFS to traverse the graph.
- The BFS approach will ensure we explore all possible paths from the source to the destination vertex in the shortest way possible.
{{< dots >}}
### Edge Cases 🌐
- If there are no edges, and the source is not equal to the destination, the result will be `false`.
- For large inputs with up to 200,000 vertices, we need to ensure the solution uses efficient graph traversal.
- When the source and destination vertices are the same, the answer is trivially `true`.
- Ensure that the graph traversal does not exceed time limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    unordered_map<int,vector<int>> graph; 
    for(auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<bool> visited(n,0);        
    queue<int> q;
    q.push(start);
    visited[start] = 1; 
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr == end)
            return 1; 
        for(auto &node : graph[curr]){
            if(!visited[node]){
                visited[node] = 1; 
                q.push(node);
            }
        }
    }
    
    return false;
}
```

This function determines if there is a valid path between the 'start' and 'end' nodes in a graph represented by edges. It uses breadth-first search (BFS) to traverse the graph.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
	```
	This is the function signature, defining a function 'validPath' that takes the number of nodes (n), a vector of edges, and two nodes (start, end) to check if a path exists between them.

2. **Graph Construction**
	```cpp
	    unordered_map<int,vector<int>> graph; 
	```
	Here, an unordered map 'graph' is created to store the adjacency list of the graph, where each node maps to a list of its connected nodes.

3. **Edge Processing**
	```cpp
	    for(auto e : edges) {
	```
	This loop iterates through each edge in the input 'edges' list to populate the adjacency list 'graph'.

4. **Add Edge to Graph**
	```cpp
	        graph[e[0]].push_back(e[1]);
	```
	This line adds a directed edge from node e[0] to node e[1] in the graph.

5. **Add Edge to Graph**
	```cpp
	        graph[e[1]].push_back(e[0]);
	```
	This line adds the reverse edge from node e[1] to node e[0] because the graph is undirected.

6. **Visited Initialization**
	```cpp
	    vector<bool> visited(n,0);        
	```
	A 'visited' vector of size n is initialized to track whether a node has been visited during traversal.

7. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue is initialized to implement breadth-first search (BFS).

8. **Queue Push Start Node**
	```cpp
	    q.push(start);
	```
	The 'start' node is added to the queue to begin BFS.

9. **Mark Start Node as Visited**
	```cpp
	    visited[start] = 1; 
	```
	The 'start' node is marked as visited.

10. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	The while loop continues as long as there are nodes in the queue to process.

11. **Queue Pop**
	```cpp
	        int curr = q.front();
	```
	The node at the front of the queue is assigned to 'curr' for processing.

12. **Queue Pop**
	```cpp
	        q.pop();
	```
	The node is removed from the queue after being processed.

13. **Check for End Node**
	```cpp
	        if(curr == end)
	```
	If the current node is the 'end' node, a valid path has been found.

14. **Return Path Found**
	```cpp
	            return 1; 
	```
	Return 1 to indicate that a valid path was found between 'start' and 'end'.

15. **Node Traversal**
	```cpp
	        for(auto &node : graph[curr]){
	```
	This loop iterates through all adjacent nodes of the current node.

16. **Check if Node is Visited**
	```cpp
	            if(!visited[node]){
	```
	Check if the adjacent node has not been visited yet.

17. **Mark Node as Visited**
	```cpp
	                visited[node] = 1; 
	```
	Mark the adjacent node as visited.

18. **Queue Push Node**
	```cpp
	                q.push(node);
	```
	Add the adjacent node to the queue to continue BFS.

19. **Return No Path**
	```cpp
	    return false;
	```
	Return false to indicate that no valid path was found between 'start' and 'end'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m), where `n` is the number of vertices and `m` is the number of edges
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity of BFS or DFS is O(n + m), where `n` is the number of vertices and `m` is the number of edges.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m) due to the adjacency list and the visited array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-if-path-exists-in-graph/description/)

---
{{< youtube knLFe7hEp3Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
