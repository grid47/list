
+++
authors = ["grid47"]
title = "Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph"
date = "2024-03-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2316: Count Unreachable Pairs of Nodes in an Undirected Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2FIK7F0Qs38"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi/2FIK7F0Qs38/maxresdefault.jpg"
comments = true
+++



---
You are given an undirected graph with n nodes and a list of edges connecting the nodes. The goal is to find the number of pairs of distinct nodes that are unreachable from each other.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n representing the number of nodes, followed by a list of edges where each edge is a pair of integers representing nodes connected by an edge.
- **Example:** `n = 4, edges = [[0,1],[1,2],[2,3]]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= edges.length <= 2 * 10^5
	- Each edge connects two different nodes, and there are no repeated edges.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of pairs of distinct nodes that are unreachable from each other.
- **Example:** `For n = 7 and edges = [[0,2],[0,5],[2,4],[1,6],[5,4]], the output is 14.`
- **Constraints:**
	- The output should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the number of unreachable pairs by finding the connected components in the graph and calculating how many pairs exist between nodes that do not belong to the same component.

- 1. Build an adjacency list representation of the graph.
- 2. Perform a DFS or BFS to find all connected components.
- 3. For each connected component, calculate the number of unreachable pairs.
- 4. Subtract the reachable pairs from the total possible pairs (n * (n-1) / 2).
{{< dots >}}
### Problem Assumptions ✅
- The graph is undirected.
- The nodes are numbered from 0 to n-1.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4, edges = [[0,1],[1,2],[2,3]]`  \
  **Explanation:** In this example, all nodes are connected, so there are no unreachable pairs. Hence, the output is 0.

{{< dots >}}
## Approach 🚀
The approach involves finding connected components and calculating unreachable pairs based on the sizes of those components.

### Initial Thoughts 💭
- The problem boils down to finding connected components in an undirected graph and counting how many node pairs belong to different components.
- We need to calculate the total possible pairs and subtract the pairs that belong to the same component, which are reachable.
{{< dots >}}
### Edge Cases 🌐
- If no edges are given, all nodes are isolated, and the number of unreachable pairs is the maximum number of pairs.
- The algorithm must handle graphs with up to 10^5 nodes and 2 * 10^5 edges efficiently.
- If there is only one node, no pairs exist, so the result is 0.
- Ensure that edge cases such as graphs with no edges or all nodes in one component are handled.
{{< dots >}}
## Code 💻
```cpp
class Solution {
typedef long long ll;
public:
long long countPairs(int n, vector<vector<int>>& es) {
    
    vector<vector<int>> g(n, vector<int>());
    for(vector<int> e: es){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
        
    }
    vector<bool> vis(n, false);
    ll res = (ll) n * (n - 1) /2;
        
    for(int i = 0; i < n; i++) {
        ll ret = 0;
  if(!vis[i])
  ret = dfs(i, g, vis);
  res -= (ret * (ret -1)/2);
    }
    
    return res;
    
}

ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
    
    if(vis[i]) return 0;
    vis[i] = true;
    ll res = 1;
    for(int v : g[i]) {
        res += dfs(v, g, vis);
    }
    return res;
}

```

This class provides a solution for counting the number of valid pairs in a graph. The function `countPairs` calculates the number of pairs that can be formed from nodes in the graph where no two nodes in a pair are connected by an edge. It uses Depth First Search (DFS) to identify connected components and subtracts invalid pairs formed within the same component.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Define the `Solution` class that contains the method to solve the problem of counting pairs in a graph.

2. **Type Alias**
	```cpp
	typedef long long ll;
	```
	Define a type alias `ll` for `long long` to simplify the code and make it more readable.

3. **Access Modifier**
	```cpp
	public:
	```
	Declare the following members of the class as public so that they can be accessed externally.

4. **Method Declaration**
	```cpp
	long long countPairs(int n, vector<vector<int>>& es) {
	```
	Declare the method `countPairs` which takes an integer `n` (the number of nodes) and a reference to a 2D vector `es` (representing the edges) and returns a `long long` value representing the count of valid pairs.

5. **Graph Initialization**
	```cpp
	    vector<vector<int>> g(n, vector<int>());
	```
	Initialize an adjacency list `g` of size `n`, where each element is a vector to store the nodes adjacent to each node.

6. **Edge Insertion**
	```cpp
	    for(vector<int> e: es){
	```
	Iterate through each edge `e` in the `es` list.

7. **Bidirectional Edge Creation**
	```cpp
	        g[e[0]].push_back(e[1]);
	```
	For each edge `e`, add the destination node `e[1]` to the adjacency list of the source node `e[0]`.

8. **Bidirectional Edge Creation**
	```cpp
	        g[e[1]].push_back(e[0]);
	```
	Similarly, add the source node `e[0]` to the adjacency list of the destination node `e[1]` to ensure bidirectional connectivity.

9. **Visited Array Initialization**
	```cpp
	    vector<bool> vis(n, false);
	```
	Initialize a `vis` array of size `n` to keep track of whether each node has been visited during the DFS.

10. **Total Pairs Calculation**
	```cpp
	    ll res = (ll) n * (n - 1) /2;
	```
	Calculate the total number of pairs that can be formed from the `n` nodes using the formula `n * (n - 1) / 2`.

11. **DFS Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Loop through each node `i` in the graph to perform DFS on unvisited nodes.

12. **Temporary Result Variable**
	```cpp
	        ll ret = 0;
	```
	Initialize a temporary variable `ret` to store the size of the connected component found by DFS.

13. **DFS Call**
	```cpp
	  if(!vis[i])
	```
	Check if the node `i` has not been visited yet.

14. **DFS Execution**
	```cpp
	  ret = dfs(i, g, vis);
	```
	If node `i` is not visited, perform DFS starting from node `i` to find all nodes in its connected component and store the result in `ret`.

15. **Invalid Pair Subtraction**
	```cpp
	  res -= (ret * (ret -1)/2);
	```
	Subtract the number of invalid pairs within the current connected component from the total valid pairs. This is calculated as `(ret * (ret - 1) / 2)`.

16. **Return Final Result**
	```cpp
	    return res;
	```
	Return the final count of valid pairs after subtracting invalid pairs from the total.

17. **DFS Method Declaration**
	```cpp
	ll dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
	```
	Declare the helper method `dfs` which performs Depth First Search (DFS) to find the size of a connected component starting from node `i`.

18. **DFS Base Case**
	```cpp
	    if(vis[i]) return 0;
	```
	If the node `i` has already been visited, return 0 to prevent reprocessing.

19. **Mark Node as Visited**
	```cpp
	    vis[i] = true;
	```
	Mark the node `i` as visited to avoid revisiting it during DFS.

20. **Result Initialization**
	```cpp
	    ll res = 1;
	```
	Initialize the result variable `res` to 1, as the starting node is counted as part of the connected component.

21. **DFS Recursion**
	```cpp
	    for(int v : g[i]) {
	```
	For each neighboring node `v` of node `i`, recursively perform DFS to explore the entire connected component.

22. **DFS Call**
	```cpp
	        res += dfs(v, g, vis);
	```
	Add the result of the DFS call on the neighboring node `v` to the total count `res`.

23. **Return DFS Result**
	```cpp
	    return res;
	```
	Return the size of the connected component found by DFS.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where n is the number of nodes and m is the number of edges, as we need to traverse all nodes and edges.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m), as we store the adjacency list and visited nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/description/)

---
{{< youtube 2FIK7F0Qs38 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
