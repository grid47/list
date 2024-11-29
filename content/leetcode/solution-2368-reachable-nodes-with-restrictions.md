
+++
authors = ["grid47"]
title = "Leetcode 2368: Reachable Nodes With Restrictions"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2368: Reachable Nodes With Restrictions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XMF3HhULMbM"
youtube_upload_date="2022-08-07"
youtube_thumbnail="https://i.ytimg.com/vi/XMF3HhULMbM/maxresdefault.jpg"
comments = true
+++



---
You are given a tree with n nodes and n - 1 edges, where nodes are labeled from 0 to n - 1. Additionally, a list of restricted nodes is provided. Your goal is to determine the maximum number of nodes that can be visited starting from node 0, without passing through any restricted node. Node 0 itself is not restricted.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the number of nodes n, a list of edges describing the tree, and a list of restricted nodes.
- **Example:** `n = 6, edges = [[0,1], [0,2], [2,3], [3,4], [4,5]], restricted = [2, 5]`
- **Constraints:**
	- 2 <= n <= 10^5
	- edges.length == n - 1
	- edges[i].length == 2
	- 0 <= ai, bi < n
	- ai != bi
	- edges represents a valid tree
	- 1 <= restricted.length < n
	- 1 <= restricted[i] < n
	- All restricted nodes are unique

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum number of nodes that can be reached from node 0 without passing through any restricted node.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum reachable nodes starting from node 0 while avoiding restricted nodes.

- Construct an adjacency list from the given edges.
- Mark all restricted nodes as visited.
- Perform a Depth First Search (DFS) or Breadth First Search (BFS) starting from node 0, skipping any restricted nodes.
- Count the number of nodes visited during the traversal.
{{< dots >}}
### Problem Assumptions ✅
- Node 0 will not be restricted.
- The given tree is valid, and each node can only have a unique set of neighbors.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, edges = [[0,1], [0,2], [2,3], [3,4], [4,5]], restricted = [2, 5]`  \
  **Explanation:** In this example, the nodes that can be visited from node 0 are 1, 3, and 4. Node 2 and node 5 are restricted, so they cannot be visited. Hence, the output is 3.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use DFS or BFS to traverse the tree from node 0, skipping the restricted nodes and counting how many nodes are reachable.

### Initial Thoughts 💭
- We need to traverse the tree while avoiding restricted nodes.
- The tree structure ensures no cycles, so DFS/BFS will suffice for traversal.
- This is a graph traversal problem where we need to avoid certain nodes while counting the reachable ones.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least 2 nodes, so empty inputs are not possible.
- For very large inputs (n up to 10^5), the solution should be efficient, ideally O(n) time complexity.
- If there is a large number of restricted nodes, the number of reachable nodes might be significantly reduced.
- Make sure the solution handles the upper limits of constraints effectively.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int ans;
public:
void solve(vector<vector<int>>& gph, vector<bool> &vis, int i) {
    vis[i] = true;
    for(int n: gph[i]) {
        if(!vis[n]) {
            ans++;
            vis[n] = true;
            solve(gph, vis, n);
        }
    }
}

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    ans = 1;
    vector<vector<int>> gph(n);
    for(auto e: edges) {
        int u = e[0], v = e[1];
        gph[u].push_back(v);
        gph[v].push_back(u);
    }

    vector<bool> vis(n, false);
    for(auto i: restricted) vis[i] = true;

    solve(gph, vis, 0);
    return ans;
}
```

This solution counts the number of reachable nodes in a graph starting from node 0, excluding restricted nodes. It uses depth-first search (DFS) to traverse the graph, marking visited nodes and incrementing the reachable node count.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the Solution class that encapsulates the logic for the problem.

2. **Variable Declaration**
	```cpp
	int ans;
	```
	Declares an integer variable 'ans' to keep track of the count of reachable nodes.

3. **Access Modifier**
	```cpp
	public:
	```
	Indicates the start of the public section where the function definitions are located.

4. **DFS Function Definition**
	```cpp
	void solve(vector<vector<int>>& gph, vector<bool> &vis, int i) {
	```
	Defines the 'solve' function which performs a depth-first search (DFS) to explore the graph.

5. **Mark Current Node as Visited**
	```cpp
	    vis[i] = true;
	```
	Marks the current node 'i' as visited to prevent revisiting it.

6. **Iterate Over Neighbors**
	```cpp
	    for(int n: gph[i]) {
	```
	Iterates over all the neighboring nodes of the current node 'i'.

7. **Check for Unvisited Neighbors**
	```cpp
	        if(!vis[n]) {
	```
	Checks if the neighboring node 'n' has not been visited yet.

8. **Increment Reachable Node Count**
	```cpp
	            ans++;
	```
	Increments the count of reachable nodes if the neighboring node is valid.

9. **Mark Neighbor as Visited**
	```cpp
	            vis[n] = true;
	```
	Marks the neighboring node 'n' as visited.

10. **Recursive DFS Call**
	```cpp
	            solve(gph, vis, n);
	```
	Recursively calls the 'solve' function for the unvisited neighbor 'n'.

11. **Main Function Definition**
	```cpp
	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
	```
	Defines the 'reachableNodes' function which is the main function that calculates the number of reachable nodes.

12. **Initialize Answer**
	```cpp
	    ans = 1;
	```
	Initializes 'ans' to 1, counting the starting node (node 0) as reachable.

13. **Graph Initialization**
	```cpp
	    vector<vector<int>> gph(n);
	```
	Initializes an adjacency list 'gph' to represent the graph with 'n' nodes.

14. **Build Graph**
	```cpp
	    for(auto e: edges) {
	```
	Iterates over the edges and builds the undirected graph by adding each edge to the adjacency list.

15. **Edge Processing**
	```cpp
	        int u = e[0], v = e[1];
	```
	Extracts the nodes 'u' and 'v' from the current edge 'e'.

16. **Add Edge to Graph**
	```cpp
	        gph[u].push_back(v);
	```
	Adds node 'v' to the adjacency list of node 'u', creating an undirected edge.

17. **Add Reverse Edge**
	```cpp
	        gph[v].push_back(u);
	```
	Adds node 'u' to the adjacency list of node 'v', ensuring the graph is undirected.

18. **Initialize Visited Vector**
	```cpp
	    vector<bool> vis(n, false);
	```
	Initializes a boolean vector 'vis' to track which nodes have been visited.

19. **Mark Restricted Nodes**
	```cpp
	    for(auto i: restricted) vis[i] = true;
	```
	Marks the restricted nodes as visited in the 'vis' vector.

20. **Start DFS Traversal**
	```cpp
	    solve(gph, vis, 0);
	```
	Starts the DFS traversal from node 0, passing the graph and visited vector.

21. **Return Result**
	```cpp
	    return ans;
	```
	Returns the count of reachable nodes, which is stored in 'ans'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Since we traverse all nodes once, the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the adjacency list and visited nodes array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reachable-nodes-with-restrictions/description/)

---
{{< youtube XMF3HhULMbM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
