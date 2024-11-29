
+++
authors = ["grid47"]
title = "Leetcode 1786: Number of Restricted Paths From First to Last Node"
date = "2024-05-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1786: Number of Restricted Paths From First to Last Node in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Graph","Topological Sort","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YmufKoAmthE"
youtube_upload_date="2021-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/YmufKoAmthE/maxresdefault.jpg"
comments = true
+++



---
You are given a connected, undirected, weighted graph with n nodes, labeled from 1 to n. An array 'edges' represents the edges in the graph where each element edges[i] = [ui, vi, weighti] indicates that there is an edge between nodes ui and vi with a weight of weighti. A path from node start to node end is a sequence of nodes [z0, z1, ..., zk] such that z0 = start, zk = end, and there is an edge between zi and zi+1 for each 0 <= i <= k-1.

The distance of a path is the sum of the weights of the edges along the path. A restricted path is a path where the distance from node 'n' to node zi is strictly greater than the distance from node 'n' to node zi+1 for each 0 <= i <= k-1.

You need to return the number of restricted paths from node 1 to node n, modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer n, representing the number of nodes in the graph. The second input is an array of edges, where each element is an array [ui, vi, weighti], representing an edge between nodes ui and vi with a weight of weighti.
- **Example:** `Example: n = 5, edges = [[1, 2, 3], [1, 3, 3], [2, 3, 1], [1, 4, 2], [5, 2, 2], [3, 5, 1], [5, 4, 10]]`
- **Constraints:**
	- 1 <= n <= 2 * 10^4
	- n - 1 <= edges.length <= 4 * 10^4
	- edges[i].length == 3
	- 1 <= ui, vi <= n
	- 1 <= weighti <= 10^5
	- There is at least one path between any two nodes.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer, representing the number of restricted paths from node 1 to node n modulo 10^9 + 7.
- **Example:** `Example: Output = 3`
- **Constraints:**
	- Return the number of restricted paths modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the number of restricted paths from node 1 to node n in the graph.

- 1. Build a graph using the given edges.
- 2. Use Dijkstra's algorithm to compute the shortest distances from node n to all other nodes.
- 3. Perform a Depth First Search (DFS) starting from node 1 to count the number of restricted paths to node n.
{{< dots >}}
### Problem Assumptions ✅
- The graph is connected, meaning there is always at least one path between any two nodes.
- The edge weights are positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: n = 5, edges = [[1, 2, 3], [1, 3, 3], [2, 3, 1], [1, 4, 2], [5, 2, 2], [3, 5, 1], [5, 4, 10]]`  \
  **Explanation:** The three restricted paths are: 1 -> 2 -> 5, 1 -> 2 -> 3 -> 5, and 1 -> 3 -> 5. These paths satisfy the condition that for any adjacent nodes on the path, the distance from node n to the current node is greater than the distance from node n to the next node.

- **Input:** `Example 2: n = 7, edges = [[1, 3, 1], [4, 1, 2], [7, 3, 4], [2, 5, 3], [5, 6, 1], [6, 7, 2], [7, 5, 3], [2, 6, 4]]`  \
  **Explanation:** The only restricted path in this example is: 1 -> 3 -> 7. The distance from node n (node 7) decreases as you move along this path from node 1 to node 7.

{{< dots >}}
## Approach 🚀
To solve this problem, we can follow a multi-step approach using Dijkstra's algorithm and a DFS traversal to count the restricted paths.

### Initial Thoughts 💭
- Dijkstra's algorithm is useful for finding the shortest paths in the graph, which will be crucial for verifying the restricted path condition.
- Once the shortest distances are calculated, we can traverse the graph and check each path to see if it satisfies the restricted path condition.
{{< dots >}}
### Edge Cases 🌐
- Empty graph or no edges (though not possible by the problem's constraints).
- The graph can have up to 40,000 edges, requiring an efficient implementation of both Dijkstra's and DFS.
- Graphs with multiple paths having the same shortest distance.
- The graph will always have a valid path between any two nodes.
{{< dots >}}
## Code 💻
```cpp
int countRestrictedPaths(int n, vector<vector<int>>& es) {
    
    vector<vector<pii>> gph(n + 1);
    for(int i = 0; i < es.size(); i++) {
        int u = es[i][0], v = es[i][1], d = es[i][2];
        gph[u].push_back({d, v});
        gph[v].push_back({d, u});

    }
    vector<int> dst(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, n});
    dst[n] = 0;
    while(!pq.empty()) {
        
        auto [d, u] = pq.top();
        pq.pop();
        
        for(auto & x: gph[u]) {
            int nxt = x.second, t = x.first;
            
           // if(t != dst[nxt]) continue;
            
            if(dst[nxt] > t + d) {
                dst[nxt] = t + d;
                pq.push({t + d, nxt});
            }
        }
        
    }
    vector<int> dp(n + 1, -1);
    return dfs(gph, dst, n, dp);
    
}

int dfs(vector<vector<pii>> &gph, vector<int> &dst, int s, vector<int> &dp) {
    
    if (s == 1) return 1;
    if (dp[s] != -1) return dp[s];
    
    int mod = 1e9 + 7;
    int sum = 0, w = 0, val = 0;
    for(auto &v : gph[s]) {
        
        w = dst[s];
        val = dst[v.second];
        if (val > w) {
            sum = (sum % mod+ dfs(gph, dst, v.second, dp) % mod) % mod;
        }
        
    }
    return dp[s] = sum % mod;
}
```

This code defines a solution to the problem of counting the restricted paths in a graph where each path has a restriction based on distance from the destination node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int countRestrictedPaths(int n, vector<vector<int>>& es) {
	```
	Define the function `countRestrictedPaths`, which takes the number of nodes `n` and an edge list `es` and returns the count of restricted paths from node `n` to node `1`.

2. **Variable Initialization**
	```cpp
	    
	```
	Placeholder for any required initialization or logic at the beginning of the function.

3. **Graph Construction**
	```cpp
	    vector<vector<pii>> gph(n + 1);
	```
	Initialize an adjacency list `gph` to store the graph where each node will have a list of pairs representing the distance and the connected node.

4. **Edge Iteration**
	```cpp
	    for(int i = 0; i < es.size(); i++) {
	```
	Loop through each edge in the edge list `es` to build the graph representation.

5. **Edge Assignment**
	```cpp
	        int u = es[i][0], v = es[i][1], d = es[i][2];
	```
	Extract the nodes `u` and `v` and the distance `d` for each edge in the graph.

6. **Graph Population**
	```cpp
	        gph[u].push_back({d, v});
	```
	Add the edge from node `u` to node `v` with distance `d` to the graph.

7. **Bidirectional Edge**
	```cpp
	        gph[v].push_back({d, u});
	```
	Add the reverse edge from node `v` to node `u` to make the graph bidirectional.

8. **Distance Initialization**
	```cpp
	    vector<int> dst(n + 1, INT_MAX);
	```
	Initialize a vector `dst` to store the shortest distances from node `n` to all other nodes, with all values set to infinity initially.

9. **Priority Queue Setup**
	```cpp
	    priority_queue<pii, vector<pii>, greater<>> pq;
	```
	Initialize a priority queue `pq` to store nodes based on their distances, ensuring that the smallest distance node is processed first.

10. **Start Node Initialization**
	```cpp
	    pq.push({0, n});
	```
	Push the destination node `n` into the priority queue with a distance of 0.

11. **Set Distance of Node n**
	```cpp
	    dst[n] = 0;
	```
	Set the distance to the destination node `n` to 0.

12. **Priority Queue Processing**
	```cpp
	    while(!pq.empty()) {
	```
	Start a while loop that processes nodes from the priority queue until it's empty.

13. **Node Extraction**
	```cpp
	        auto [d, u] = pq.top();
	```
	Extract the node `u` with the smallest distance `d` from the priority queue.

14. **Priority Queue Pop**
	```cpp
	        pq.pop();
	```
	Remove the node `u` from the priority queue.

15. **Neighbor Iteration**
	```cpp
	        for(auto & x: gph[u]) {
	```
	Iterate through the neighbors `x` of the current node `u`.

16. **Neighbor Extraction**
	```cpp
	            int nxt = x.second, t = x.first;
	```
	Extract the neighbor node `nxt` and the distance `t` for the edge from `u` to `nxt`.

17. **Distance Update**
	```cpp
	            if(dst[nxt] > t + d) {
	```
	Check if the current distance to the neighbor `nxt` is greater than the new distance `t + d`. If it is, update the distance.

18. **Distance Assignment**
	```cpp
	                dst[nxt] = t + d;
	```
	Update the distance of `nxt` to the new value `t + d`.

19. **Queue Push**
	```cpp
	                pq.push({t + d, nxt});
	```
	Push the updated node `nxt` with its new distance into the priority queue.

20. **Dynamic Programming Setup**
	```cpp
	    vector<int> dp(n + 1, -1);
	```
	Initialize a vector `dp` to store the number of restricted paths from each node to the destination node, with all values set to -1.

21. **DFS Call**
	```cpp
	    return dfs(gph, dst, n, dp);
	```
	Call the depth-first search function to compute the number of restricted paths from node `n` to node `1`.

22. **DFS Definition**
	```cpp
	int dfs(vector<vector<pii>> &gph, vector<int> &dst, int s, vector<int> &dp) {
	```
	Define the DFS function to recursively calculate the number of restricted paths from node `s` to node `1`.

23. **Base Case**
	```cpp
	    if (s == 1) return 1;
	```
	Base case: if the current node is `1`, return 1 as there is exactly one path from `1` to itself.

24. **Memoization Check**
	```cpp
	    if (dp[s] != -1) return dp[s];
	```
	Check if the result for the current node `s` is already computed. If so, return the stored value.

25. **Modulo Definition**
	```cpp
	    int mod = 1e9 + 7;
	```
	Define the modulo value to avoid overflow when calculating the number of restricted paths.

26. **Sum Calculation**
	```cpp
	    int sum = 0, w = 0, val = 0;
	```
	Initialize variables to calculate the total number of restricted paths from node `s`.

27. **Neighbor Iteration**
	```cpp
	    for(auto &v : gph[s]) {
	```
	Iterate through the neighbors of the current node `s`.

28. **Neighbor Check**
	```cpp
	        w = dst[s];
	        val = dst[v.second];
	```
	Extract the distances `w` and `val` for the current node and its neighbor.

29. **Restricted Path Check**
	```cpp
	        if (val > w) {
	```
	Check if the current path is restricted based on the distance values.

30. **Recursive Call**
	```cpp
	            sum = (sum % mod+ dfs(gph, dst, v.second, dp) % mod) % mod;
	```
	If the path is restricted, recursively call `dfs` for the neighbor `v.second` and add the result to the total sum.

31. **Return DP Result**
	```cpp
	    return dp[s] = sum % mod;
	```
	Store and return the result for the current node `s` modulo `1e9 + 7`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + e log n), where n is the number of nodes and e is the number of edges.
- **Average Case:** O(n log n + e log n)
- **Worst Case:** O(n log n + e log n)

The time complexity of Dijkstra's algorithm is O(n log n + e log n), and DFS runs in O(n + e) time.

### Space Complexity 💾
- **Best Case:** O(n + e)
- **Worst Case:** O(n + e)

The space complexity is determined by the storage needed for the graph and the auxiliary data structures (distances, dp table).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/)

---
{{< youtube YmufKoAmthE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
