
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
+++



---
**Code:**

{{< highlight cpp >}}
#define ll long long
#define pll pair<ll, ll>

class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to count the number of distinct paths in a graph where each path has the minimum travel time. Given a number of nodes and a list of edges that represent roads between them along with their respective travel times, we need to determine how many different ways we can reach from the starting node (node 0) to the destination node (node n-1) while ensuring the travel time is minimized.

### Approach

To solve this problem efficiently, we can utilize Dijkstra’s algorithm, which is commonly used for finding the shortest paths in a graph. The steps involved in our approach are as follows:

1. **Graph Representation**: We will represent the graph using an adjacency list. Each node will have a list of pairs where each pair contains a neighboring node and the weight (travel time) of the edge leading to that neighbor.

2. **Initialization**: 
   - A priority queue will be used to always expand the node with the currently known shortest distance.
   - Two arrays will be maintained:
     - `ways` to count the number of ways to reach each node.
     - `dst` to store the minimum distance to each node.

3. **Dijkstra’s Algorithm**: 
   - Start from the source node (node 0) and initialize its distance to 0 and the number of ways to reach it to 1.
   - For each node, explore its neighbors. If a shorter path to a neighbor is found, update its distance and the number of ways to reach it.
   - If an alternative path to a neighbor has the same distance as the previously known shortest distance, increment the number of ways to reach that neighbor by the number of ways to reach the current node.

4. **Result**: Finally, return the count of distinct paths to the destination node (node n-1).

### Code Breakdown (Step by Step)

```cpp
#define ll long long
#define pll pair<ll, ll>
```
Here, we define `ll` as an alias for `long long` to handle large integer values and `pll` as a pair of long long integers for ease of use in the priority queue.

```cpp
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& rds) {
```
The main class `Solution` contains the method `countPaths`, which takes the number of nodes `n` and a vector of roads `rds` as parameters.

```cpp
        vector<vector<pll>> gph(n);
        for(vector<int> &e : rds) {
            int u = e[0], v = e[1], time = e[2];
            gph[u].push_back({v, time});
            gph[v].push_back({u, time});
        }
```
We initialize an adjacency list `gph` of size `n` and populate it with edges from the `rds` vector. Each edge connects two nodes and has a travel time.

```cpp
        vector<ll> ways(n, 0), dst(n, LLONG_MAX);
        ways[0] = 1;
        dst[0] = 0;
```
Two vectors are initialized:
- `ways` to count the number of paths to each node, initialized to zero, except for the starting node which is set to 1.
- `dst` to keep track of the shortest distance to each node, initialized to `LLONG_MAX` for all nodes except the starting node, which is set to 0.

```cpp
        priority_queue<pll, vector<pll>, greater<>> pq;
        pq.push({0, 0});
        int ans = 0;
```
A priority queue `pq` is initialized to facilitate Dijkstra’s algorithm. The starting node (0) with a distance of 0 is pushed onto the queue.

```cpp
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
```
The main loop continues as long as there are nodes in the priority queue. The node with the smallest distance is retrieved and removed from the queue.

```cpp
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
```
For each neighbor `nb` of the current node `u`, we check if a shorter path to `nxt` (the neighbor) can be established. If so:
- Update the shortest distance to `nxt`.
- Update the number of ways to reach `nxt` using the number of ways to reach `u`.
- Push the new distance and the neighbor onto the priority queue.
If the shortest distance to `nxt` is equal to the newly computed distance, it means we've found another way to reach `nxt`, and we add the number of ways to reach `u` to `ways[nxt]`.

```cpp
        return ways[n - 1];
    }
};
```
Finally, the method returns the number of distinct paths to reach the destination node (n-1).

### Complexity

- **Time Complexity**: The algorithm runs in \(O((V + E) \log V)\), where \(V\) is the number of vertices (nodes) and \(E\) is the number of edges. This is because each edge is processed at most once, and each insertion and extraction from the priority queue takes logarithmic time.

- **Space Complexity**: The space complexity is \(O(V + E)\) due to the adjacency list representation of the graph and the additional storage used for distances and paths.

### Conclusion

This solution effectively counts the number of distinct paths from the starting node to the destination node while ensuring the paths are the shortest possible. The use of Dijkstra’s algorithm combined with the maintenance of a count of distinct paths allows for an optimal and clear solution to the problem. The overall design is efficient and handles large inputs gracefully due to the use of appropriate data structures.

### Example Usage

Here’s an example of how to use the `countPaths` function:

```cpp
Solution sol;
vector<vector<int>> roads = {{0, 1, 2}, {0, 2, 5}, {1, 2, 1}};
int n = 3; // Number of nodes
int result = sol.countPaths(n, roads);
cout << "Number of distinct paths from node 0 to node " << n-1 << ": " << result << endl; // Example output
```

This example initializes a graph with roads and computes the number of distinct paths from node 0 to node n-1, providing a practical demonstration of the algorithm's functionality. 

### Potential Improvements and Variations

1. **Handling Large Graphs**: For extremely large graphs, consider using bidirectional Dijkstra’s algorithm to potentially speed up the search for shortest paths.

2. **Path Reconstruction**: This approach can be extended to not only count paths but also reconstruct the paths themselves if needed.

3. **Adaptability**: The core logic can be adapted for directed graphs or weighted graphs with different constraints.

This solution serves as an efficient and robust method for counting distinct shortest paths in a graph, showcasing effective algorithmic strategies and data structures in action.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/)

---
{{< youtube 1JCXqupyLoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
