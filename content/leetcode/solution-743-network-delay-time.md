
+++
authors = ["grid47"]
title = "Leetcode 743: Network Delay Time"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 743: Network Delay Time in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/743.webp"
youtube = "Bp7STMWMMQw"
youtube_upload_date="2024-05-23"
youtube_thumbnail="https://i.ytimg.com/vi/Bp7STMWMMQw/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/743.webp" 
    alt="A network of nodes where the delay time is calculated, with the shortest delay glowing softly as it’s found."
    caption="Solution to LeetCode 743: Network Delay Time Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, map<int, int>> mp;
        
        for(int i = 0; i < times.size(); i++) {
            mp[times[i][0]][times[i][1]] = times[i][2];
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n + 1, 0);
        pq.push(make_pair(0, k));
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if(vis[it.second]) continue;
            vis[it.second] = true;
            n--;
            if(n == 0) return it.first;
            
            if(mp.count(it.second))
                for(auto [key, val]: mp[it.second]) {
                    pq.push(make_pair(val + it.first, key));
                }
        }
        return -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand asks us to determine the **network delay time** in a directed graph, where each edge represents the time it takes for a signal to travel from one node to another. You are given:
- A directed graph in the form of a list of edges where each edge is represented by `[u, v, w]`, which means there is a directed edge from node `u` to node `v` with a travel time of `w`.
- A number `n` representing the total number of nodes in the graph.
- A starting node `k` from where the signal starts to travel.

The goal is to compute the time it will take for a signal to reach all nodes from the starting node `k`, or return `-1` if some nodes cannot be reached.

### Approach

To solve this problem efficiently, we can apply **Dijkstra's Algorithm** — a well-known algorithm for finding the shortest paths from a source node to all other nodes in a graph with non-negative weights. The idea behind Dijkstra’s Algorithm is to always choose the node with the shortest known path to expand next. We will use a **priority queue** (or min-heap) to implement this behavior.

#### Key Steps:
1. **Graph Representation**: We need a way to store the graph. The problem specifies that it’s a directed graph, and the weights (times) are given for each edge. We can use a **map of maps** to represent the graph efficiently. Each node will point to another map, which maps the neighboring nodes to the edge weights.
   
2. **Priority Queue (Min-Heap)**: Dijkstra’s algorithm relies on a priority queue to ensure we always process the node with the smallest current distance. In this case, we will use a **min-heap** (implemented with `priority_queue` in C++) to store pairs of `(time, node)` where `time` represents the current known shortest time to reach `node`.

3. **Visited Set**: To avoid processing the same node more than once, we will maintain a visited set to mark the nodes that have already been processed.

4. **Processing Nodes**: We start by pushing the source node `k` into the priority queue with a time of `0`. Then, we repeatedly extract the node with the smallest time from the priority queue and update the times of its neighbors. If a shorter path to a neighbor is found, it is pushed into the queue.

5. **Termination**: The algorithm terminates when all nodes are visited, or if some nodes are unreachable (in which case we return `-1`).

### Code Breakdown (Step by Step)

#### Step 1: Initialize the Graph

We represent the graph using a map of maps where each key-value pair consists of:
- The outer map's key represents a source node.
- The inner map's key represents a destination node.
- The inner map's value represents the weight (time) of the edge between the two nodes.

```cpp
map<int, map<int, int>> mp;
for (int i = 0; i < times.size(); i++) {
    mp[times[i][0]][times[i][1]] = times[i][2];
}
```

#### Step 2: Initialize the Priority Queue

We initialize the priority queue with the source node `k` and set its initial travel time to `0`. We also initialize a visited array to keep track of whether a node has been processed.

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> vis(n + 1, 0);
pq.push(make_pair(0, k));  // Starting node k with time 0
```

#### Step 3: Process Nodes Using the Priority Queue

While the priority queue is not empty, we extract the node with the smallest time from the queue and check if it has already been processed (i.e., if it's in the visited set). If it has, we continue to the next iteration. If not, we mark it as visited and decrease the number of nodes we need to visit.

If all nodes are processed (i.e., `n == 0`), we return the current time of the top of the queue, which represents the latest time it took for all nodes to be visited.

```cpp
while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (vis[it.second]) continue;  // Skip already visited nodes
    vis[it.second] = true;
    n--;  // Decrement the remaining nodes
    if (n == 0) return it.first;  // If all nodes are visited, return the current time
    
    // Explore neighbors
    if (mp.count(it.second))
        for (auto [key, val] : mp[it.second]) {
            pq.push(make_pair(val + it.first, key));  // Push the new path with updated time
        }
}
```

#### Step 4: Handle Unreachable Nodes

If after processing all nodes, not all nodes have been visited (i.e., some nodes are still unreachable), we return `-1`.

```cpp
return -1;
```

### Complexity

#### Time Complexity:
- **O((E + V) log V)**, where `E` is the number of edges and `V` is the number of nodes.
  - `E` comes from processing each edge once.
  - `V` comes from processing each node once, and the `log V` factor arises from the operations on the priority queue (inserting and extracting nodes).

#### Space Complexity:
- **O(V + E)**, where `V` is the number of nodes and `E` is the number of edges.
  - We store the graph using a map of maps, which takes **O(E)** space.
  - The priority queue and visited array also take **O(V)** space.

### Conclusion

This solution uses a priority queue (min-heap) to efficiently find the shortest path from a starting node to all other nodes in the graph, making it an optimal solution to the network delay problem. By applying Dijkstra's Algorithm, we ensure that we can calculate the minimum time for a signal to reach all nodes or determine that some nodes are unreachable. The solution is efficient with a time complexity of **O((E + V) log V)**, making it suitable for large graphs, and provides an accurate and optimal result for the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/network-delay-time/description/)

---
{{< youtube Bp7STMWMMQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
