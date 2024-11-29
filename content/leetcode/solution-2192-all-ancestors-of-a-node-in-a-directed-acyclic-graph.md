
+++
authors = ["grid47"]
title = "Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph"
date = "2024-04-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2192: All Ancestors of a Node in a Directed Acyclic Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "RdxsvhrTQ0A"
youtube_upload_date="2022-03-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RdxsvhrTQ0A/maxresdefault.webp"
comments = true
+++



---
You are given a directed acyclic graph (DAG) with `n` nodes, numbered from 0 to `n-1`. Along with this, you are given a list of directed edges where each edge `[fromi, toi]` indicates a directed edge from node `fromi` to node `toi`. For each node in the graph, you need to determine the list of all its ancestors. A node `u` is an ancestor of node `v` if there is a path from `u` to `v` through one or more directed edges. Return a list `answer` where `answer[i]` contains the sorted list of ancestors of the `i`-th node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` representing the number of nodes in the graph, followed by a list of edges describing the directed edges.
- **Example:** `n = 6, edgeList = [[0,1],[0,2],[1,3],[1,4],[2,5],[4,5]]`
- **Constraints:**
	- 1 <= n <= 1000
	- 0 <= edges.length <= min(2000, n * (n - 1) / 2)
	- edges[i].length == 2
	- 0 <= fromi, toi <= n - 1
	- fromi != toi
	- There are no duplicate edges
	- The graph is directed and acyclic

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list `answer` where `answer[i]` is the list of ancestors of the `i`-th node, sorted in ascending order.
- **Example:** `[[], [0], [0], [0, 1], [0, 1, 2], [0, 1, 2, 4]]`
- **Constraints:**
	- The list of ancestors for each node should be sorted in ascending order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the ancestors of each node in the graph efficiently.

- 1. Create a graph representation using adjacency lists for outgoing edges and maintain a count of incoming edges for each node.
- 2. Perform a topological sort using Kahn's algorithm to ensure that nodes are processed in the correct order.
- 3. For each node, use its ancestors (processed nodes) and propagate the ancestors through the graph, adding them to the current node's ancestor set.
{{< dots >}}
### Problem Assumptions ✅
- The graph is acyclic, so there will be no cycles.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6, edgeList = [[0,1],[0,2],[1,3],[1,4],[2,5],[4,5]]`  \
  **Explanation:** In this case, node 0 has no ancestors, node 1 has node 0 as an ancestor, node 3 has nodes 0 and 1 as ancestors, and so on.

{{< dots >}}
## Approach 🚀
To find the ancestors of each node, we use a topological sort approach to traverse the graph, propagating ancestors through the nodes.

### Initial Thoughts 💭
- Topological sorting is key to processing the nodes in the correct order.
- We need to track the ancestors of each node as we process the graph to ensure we capture all nodes that can reach the current node.
{{< dots >}}
### Edge Cases 🌐
- If there are no edges, each node will only have itself as an ancestor.
- The solution should efficiently handle cases where `n` is large and the graph has many edges.
- Handle edge cases like disconnected nodes where no edges lead to certain nodes.
- Ensure that no cycles are present as the graph is guaranteed to be acyclic.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<set<int>> dag(n);
    vector<vector<int>> grid(n), sol(n);
    vector<int> inward(n, 0);
    for(auto it: edges) {
        grid[it[0]].push_back(it[1]);
        inward[it[1]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(inward[i] == 0) q.push(i);
    
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int tmp = q.front();
            q.pop();
            for(auto it: grid[tmp]) {
                inward[it]--;
                dag[it].insert(tmp);
                for(int x: dag[tmp])
                    dag[it].insert(x);
                if(inward[it] == 0)
                    q.push(it);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(auto it: dag[i]) {
            sol[i].push_back(it);
        }
    }
    return sol;
}
```

This function calculates the ancestors for each node in a directed graph represented by edges. It uses a topological sorting approach and iterates through nodes to identify their ancestors based on the graph's structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
	```
	This defines the function that takes the number of nodes `n` and a list of directed edges as input, returning a vector of vectors that represents the ancestors for each node.

2. **Variable Declaration**
	```cpp
	    vector<set<int>> dag(n);
	```
	A vector of sets is initialized to keep track of the ancestors for each node.

3. **Variable Declaration**
	```cpp
	    vector<vector<int>> grid(n), sol(n);
	```
	These vectors store the adjacency list `grid` for each node and the `sol` vector which will hold the ancestors for each node.

4. **Variable Initialization**
	```cpp
	    vector<int> inward(n, 0);
	```
	This initializes the `inward` vector to keep track of the incoming degree (number of incoming edges) for each node.

5. **Looping**
	```cpp
	    for(auto it: edges) {
	```
	This loop iterates over each edge to build the graph and update the inward degree of the target node.

6. **Graph Construction**
	```cpp
	        grid[it[0]].push_back(it[1]);
	```
	Adds an edge from node `it[0]` to node `it[1]` in the adjacency list `grid`.

7. **Graph Construction**
	```cpp
	        inward[it[1]]++;
	```
	Increases the inward degree of node `it[1]` by 1, indicating that there is an incoming edge to this node.

8. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	A queue `q` is initialized to manage the nodes with no incoming edges (in-degree of 0).

9. **Looping**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop iterates through all nodes to find the nodes with no incoming edges.

10. **Queue Population**
	```cpp
	        if(inward[i] == 0) q.push(i);
	```
	If a node has no incoming edges, it is pushed into the queue `q` for processing.

11. **Looping**
	```cpp
	    while(!q.empty()) {
	```
	While the queue is not empty, nodes are processed to identify their ancestors.

12. **Queue Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Stores the size of the queue to process each node in the current level of the graph.

13. **Looping**
	```cpp
	        while(sz--) {
	```
	This loop processes each node in the queue.

14. **Queue Dequeue**
	```cpp
	            int tmp = q.front();
	```
	Pops the front node `tmp` from the queue.

15. **Queue Dequeue**
	```cpp
	            q.pop();
	```
	Removes the node from the queue after processing.

16. **Graph Traversal**
	```cpp
	            for(auto it: grid[tmp]) {
	```
	Traverses the neighbors of node `tmp` to identify the next nodes to process.

17. **Edge Processing**
	```cpp
	                inward[it]--;
	```
	Decreases the inward degree of the neighbor node `it`.

18. **Ancestor Tracking**
	```cpp
	                dag[it].insert(tmp);
	```
	Adds the current node `tmp` as an ancestor of node `it`.

19. **Ancestor Propagation**
	```cpp
	                for(int x: dag[tmp])
	```
	This loop propagates ancestors from node `tmp` to its neighbors.

20. **Ancestor Propagation**
	```cpp
	                    dag[it].insert(x);
	```
	Adds each ancestor of `tmp` to the set of ancestors of `it`.

21. **Queue Population**
	```cpp
	                if(inward[it] == 0)
	```
	If the inward degree of node `it` becomes zero, it is added to the queue.

22. **Queue Population**
	```cpp
	                    q.push(it);
	```
	Adds node `it` to the queue for further processing.

23. **Ancestor Assignment**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This loop iterates over each node to assign the ancestors for each node.

24. **Ancestor Assignment**
	```cpp
	        for(auto it: dag[i]) {
	```
	Iterates over the ancestors of node `i`.

25. **Ancestor Assignment**
	```cpp
	            sol[i].push_back(it);
	```
	Adds each ancestor `it` to the solution vector for node `i`.

26. **Return**
	```cpp
	    return sol;
	```
	Returns the solution vector, which contains the ancestors for each node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + e), where n is the number of nodes and e is the number of edges.
- **Average Case:** O(n + e)
- **Worst Case:** O(n + e)

The time complexity is linear in terms of nodes and edges, as we perform a topological sort and propagate ancestors.

### Space Complexity 💾
- **Best Case:** O(n + e)
- **Worst Case:** O(n + e)

The space complexity is also O(n + e) due to the storage of the graph and ancestor sets.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/)

---
{{< youtube RdxsvhrTQ0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
