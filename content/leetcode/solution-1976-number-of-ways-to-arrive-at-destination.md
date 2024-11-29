
+++
authors = ["grid47"]
title = "Leetcode 1976: Number of Ways to Arrive at Destination"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1976: Number of Ways to Arrive at Destination in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Graph","Topological Sort","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1JCXqupyLoQ"
youtube_upload_date="2021-08-31"
youtube_thumbnail="https://i.ytimg.com/vi/1JCXqupyLoQ/maxresdefault.jpg"
comments = true
+++



---
You are in a city with `n` intersections, and roads connecting them with specific travel times. Your task is to find the number of different ways you can travel from intersection 0 to intersection n-1 in the shortest time possible. Since the result could be large, return it modulo (10^9 + 7).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` (the number of intersections) and a 2D integer array `roads` where each road is represented by three integers `[u, v, time]`, indicating a road between intersection `u` and `v` that takes `time` minutes to travel.
- **Example:** `n = 4, roads = [[0, 1, 1], [1, 2, 1], [2, 3, 1], [0, 2, 2], [1, 3, 2]]`
- **Constraints:**
	- 1 <= n <= 200
	- n - 1 <= roads.length <= n * (n - 1) / 2
	- 0 <= ui, vi <= n - 1
	- 1 <= time <= 10^9
	- ui != vi
	- There is at most one road between any two intersections
	- You can reach any intersection from any other intersection

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, representing the number of different ways to travel from intersection 0 to intersection n-1 using the shortest time. The answer should be returned modulo (10^9 + 7).
- **Example:** `Output: 2`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the number of ways to travel from intersection 0 to intersection n-1 in the shortest time.

- Step 1: Build a graph where each node represents an intersection and each edge represents a road with a time cost.
- Step 2: Use Dijkstra's algorithm to find the shortest time to reach all intersections from intersection 0.
- Step 3: Track the number of ways to reach each intersection with the shortest time, updating the count whenever a shorter path is found or an equal-length path is discovered.
- Step 4: Return the number of ways to reach intersection n-1, modulo (10^9 + 7).
{{< dots >}}
### Problem Assumptions ✅
- The graph is connected, meaning there's always a path from intersection 0 to intersection n-1.
- There is only one road between any two intersections.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, roads = [[0, 1, 1], [1, 2, 1], [2, 3, 1], [0, 2, 2], [1, 3, 2]]`  \
  **Explanation:** In this case, the shortest time to go from intersection 0 to intersection 3 is 3 minutes, and there are two ways to achieve this: [0 -> 1 -> 2 -> 3] and [0 -> 2 -> 3].

- **Input:** `Input: n = 3, roads = [[0, 1, 5], [1, 2, 10]]`  \
  **Explanation:** In this case, the only possible way to go from intersection 0 to intersection 2 takes 15 minutes: [0 -> 1 -> 2].

{{< dots >}}
## Approach 🚀
The approach involves using Dijkstra's algorithm to find the shortest paths from intersection 0 to all other intersections, while keeping track of the number of ways to reach each intersection with the shortest time.

### Initial Thoughts 💭
- Dijkstra's algorithm is a natural fit for finding the shortest path in a graph with weighted edges.
- We need to track not only the shortest distances but also the number of ways to reach each node with those distances.
- We need to modify Dijkstra's algorithm to maintain the count of ways to reach each node in the shortest time.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that there is always at least one road connecting the intersections.
- Ensure the solution can handle the maximum number of roads and intersections, with up to 200 intersections.
- If the graph has only two nodes, the answer is always 1 because there's exactly one road between them.
- Ensure the result is calculated modulo (10^9 + 7).
{{< dots >}}
## Code 💻
```cpp
int countPaths(int n, vector<vector<int>>& rds) {
    vector<vector<pll>> gph(n);
    for(vector<int> &e : rds) {
        int u = e[0], v = e[1], time = e[2];
        gph[u].push_back({v, time});
        gph[v].push_back({u, time});
        
    }
    
    vector<ll> ways(n, 0), dst(n, LLONG_MAX);
    ways[0] = 1;
     dst[0] = 0;
    
    priority_queue<pll, vector<pll>, greater<>> pq;
    
    pq.push({0, 0});
    int ans = 0;
    
    while(!pq.empty()) {
        
      auto [d, u] = pq.top();
      pq.pop();
        
   for(pll nb : gph[u]) {
          int nxt = nb.first, t = nb.second;
   if(dst[nxt] > d + t) {
       
       dst[nxt] = d + t;
       ways[nxt] = ways[u];
       pq.push({d + t, nxt});
   } else if (dst[nxt] == d + t) {
       ways[nxt] = (ways[nxt] + ways[u]) % 1000000007;
   }
   
   }
        
    }
    
    return ways[n - 1];
}
```

This function implements a shortest-path algorithm using Dijkstra's approach with path counting. It computes the number of ways to reach the last node with the minimum distance.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countPaths(int n, vector<vector<int>>& rds) {
	```
	This line defines the function `countPaths`, which takes an integer `n` (number of nodes) and a 2D vector `rds` (edges and times) as input.

2. **Data Structures**
	```cpp
	    vector<vector<pll>> gph(n);
	```
	This initializes a graph `gph` represented as an adjacency list of pairs, where each pair holds a neighboring node and the edge's weight.

3. **Loop**
	```cpp
	    for(vector<int> &e : rds) {
	```
	This begins a loop over the input vector `rds`, which represents the edges of the graph, where each edge is described by a triplet (u, v, time).

4. **Variable Assignment**
	```cpp
	        int u = e[0], v = e[1], time = e[2];
	```
	For each edge `e`, the values of `u` (start node), `v` (end node), and `time` (edge weight) are extracted.

5. **Graph Construction**
	```cpp
	        gph[u].push_back({v, time});
	```
	This adds the edge (v, time) to the adjacency list of node `u`, indicating a directed edge from `u` to `v` with weight `time`.

6. **Graph Construction**
	```cpp
	        gph[v].push_back({u, time});
	```
	Similarly, this adds the edge (u, time) to the adjacency list of node `v`, making the graph undirected.

7. **Variable Initialization**
	```cpp
	    vector<ll> ways(n, 0), dst(n, LLONG_MAX);
	```
	Two vectors are initialized: `ways` to store the number of ways to reach each node, and `dst` to store the shortest distance to each node.

8. **Variable Assignment**
	```cpp
	    ways[0] = 1;
	```
	Set the number of ways to reach the starting node (node 0) to 1.

9. **Variable Assignment**
	```cpp
	     dst[0] = 0;
	```
	Set the distance to the starting node to 0.

10. **Priority Queue Initialization**
	```cpp
	    priority_queue<pll, vector<pll>, greater<>> pq;
	```
	A priority queue `pq` is initialized, which will be used to process nodes based on the shortest distance (min-heap).

11. **Priority Queue Push**
	```cpp
	    pq.push({0, 0});
	```
	Push the starting node (0) with distance 0 into the priority queue.

12. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize a variable `ans` to store the result.

13. **Main Loop**
	```cpp
	    while(!pq.empty()) {
	```
	Start a loop to process the nodes in the priority queue, which will always process the node with the smallest distance first.

14. **Priority Queue Operations**
	```cpp
	      auto [d, u] = pq.top();
	```
	Extract the node with the smallest distance from the priority queue.

15. **Priority Queue Operations**
	```cpp
	      pq.pop();
	```
	Pop the node from the priority queue.

16. **Graph Traversal**
	```cpp
	   for(pll nb : gph[u]) {
	```
	Traverse the neighbors of node `u` in the graph.

17. **Variable Assignment**
	```cpp
	          int nxt = nb.first, t = nb.second;
	```
	Extract the next node (`nxt`) and edge weight (`t`) from the neighbor pair.

18. **Condition Check**
	```cpp
	   if(dst[nxt] > d + t) {
	```
	Check if a shorter path to `nxt` is found.

19. **Update Distance and Path**
	```cpp
	       dst[nxt] = d + t;
	```
	Update the shortest distance to `nxt`.

20. **Update Path Count**
	```cpp
	       ways[nxt] = ways[u];
	```
	Set the number of ways to reach `nxt` to the number of ways to reach `u`.

21. **Push to Priority Queue**
	```cpp
	       pq.push({d + t, nxt});
	```
	Push the updated node `nxt` with its new distance to the priority queue.

22. **Path Count Update**
	```cpp
	   } else if (dst[nxt] == d + t) {
	```
	If the current path to `nxt` is equal to the best known distance, update the number of ways.

23. **Path Count Update**
	```cpp
	       ways[nxt] = (ways[nxt] + ways[u]) % 1000000007;
	```
	Add the number of ways to reach `u` to the number of ways to reach `nxt`, keeping it modulo 1000000007.

24. **Return Statement**
	```cpp
	    return ways[n - 1];
	```
	Return the number of ways to reach the last node (`n - 1`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O((n + m) log n), where n is the number of intersections and m is the number of roads.
- **Average Case:** O((n + m) log n)
- **Worst Case:** O((n + m) log n)

The time complexity is dominated by the priority queue operations in Dijkstra's algorithm.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m), where n is the number of intersections and m is the number of roads.

The space complexity is dominated by the storage required for the graph representation and the arrays used in Dijkstra's algorithm.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

---
{{< youtube 1JCXqupyLoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
