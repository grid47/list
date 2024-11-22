
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to determine if there exists a valid path between two nodes in an undirected graph. The graph is represented using edges, and we need to check if a path exists from a starting node to a target node. This problem can be commonly encountered in scenarios involving network connectivity, pathfinding in mazes, or navigating social networks.

### Approach

To solve this problem, we will utilize a breadth-first search (BFS) algorithm. BFS is particularly suitable for this task because it explores all neighbors at the present depth before moving on to nodes at the next depth level. This guarantees that we will find the shortest path if one exists.

Here’s a breakdown of the steps we will take:

1. **Graph Representation**: We will represent the graph using an adjacency list. Each node will have a list of its neighboring nodes.

2. **BFS Initialization**: We will use a queue to facilitate the BFS traversal. A boolean array will keep track of visited nodes to prevent revisiting and entering into infinite loops.

3. **Traversal Logic**: We will start the BFS from the `start` node and explore its neighbors. If we encounter the `end` node during our traversal, we return `true`. If the queue is exhausted and we haven’t found the `end` node, we return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
```
This line begins the definition of the `validPath` function, which takes the number of nodes `n`, a list of edges, and the start and end nodes as arguments.

```cpp
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
```
Here, we create an adjacency list representation of the graph using an unordered map. For each edge, we add the connection in both directions since the graph is undirected.

```cpp
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
```
We initialize a boolean vector `visited` to track which nodes have been explored. We then create a queue and enqueue the starting node, marking it as visited.

```cpp
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == end)
                return 1; 
```
We enter a loop that continues until there are no more nodes in the queue. We retrieve the front node and check if it matches the `end` node. If it does, we return `true`, indicating that a valid path exists.

```cpp
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
```
For each neighboring node of the current node, we check if it has already been visited. If not, we mark it as visited and add it to the queue for further exploration.

```cpp
        return false;
    }
};
```
If we exit the while loop without finding the `end` node, we return `false`, indicating that no valid path exists.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(V + E)\), where \(V\) is the number of vertices (or nodes) in the graph and \(E\) is the number of edges. This is because, in the worst case, we might need to explore all nodes and edges.

- **Space Complexity**: The space complexity is also \(O(V + E)\) for storing the graph in the adjacency list and the visited array, as well as the queue used for BFS.

### Conclusion

This BFS-based solution effectively determines whether a valid path exists between two nodes in an undirected graph. The use of an adjacency list allows for efficient storage and retrieval of neighbor information, while BFS ensures that all possible paths are explored in a systematic manner.

### Key Features

1. **Efficiency**: The algorithm runs in linear time relative to the number of nodes and edges, making it suitable for large graphs.

2. **Simplicity**: The use of an adjacency list and a queue for BFS keeps the implementation straightforward and easy to understand.

3. **Scalability**: This approach can easily be adapted to handle various graph-related problems, such as finding all connected components or detecting cycles.

### Example Usage

Here’s an example of how to use the `validPath` function:

```cpp
Solution sol;
vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
int n = 5; // Number of nodes
int start = 0;
int end = 4;
bool result = sol.validPath(n, edges, start, end);
cout << "Path exists: " << (result ? "Yes" : "No") << endl;
```

In this example, the `validPath` function is called with a specific set of edges and nodes. The output indicates whether there is a valid path from the start node to the end node.

### Potential Improvements and Variations

1. **Bidirectional Search**: For very large graphs, a bidirectional search can be more efficient. This approach simultaneously explores from both the start and end nodes.

2. **DFS Alternative**: While BFS is used here, depth-first search (DFS) could also be implemented for pathfinding, depending on the specific requirements of the problem.

3. **Weighted Graphs**: If the graph is weighted, we could adapt the solution to use Dijkstra’s algorithm or A* search algorithm for shortest pathfinding.

This solution not only provides a method for checking connectivity in graphs but also serves as a foundation for tackling more complex graph algorithms and problems in computer science.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-if-path-exists-in-graph/description/)

---
{{< youtube knLFe7hEp3Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
