
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
comments = true
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
You are given a network of `n` nodes and a list of directed edges with travel times. You need to send a signal from a given node `k`. Return the minimum time it takes for all nodes to receive the signal, or return `-1` if it is impossible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a list of directed edges `times[i] = (ui, vi, wi)` representing the travel time from node `ui` to node `vi`, as well as the number of nodes `n` and the starting node `k`.
- **Example:** `times = [[1, 2, 1], [1, 3, 2], [3, 4, 1]], n = 4, k = 1`
- **Constraints:**
	- 1 <= k <= n <= 100
	- 1 <= times.length <= 6000
	- times[i].length == 3
	- 1 <= ui, vi <= n
	- ui != vi
	- 0 <= wi <= 100
	- All (ui, vi) pairs are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum time it takes for all `n` nodes to receive the signal, or return `-1` if it is impossible for all nodes to receive the signal.
- **Example:** `For times = [[1, 2, 1], [1, 3, 2], [3, 4, 1]], n = 4, k = 1, the output is 3.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the minimum time it takes for all nodes to receive the signal or determine if it is impossible.

- Use a graph representation to model the nodes and edges with the travel times.
- Use Dijkstra's algorithm to find the shortest path from the starting node `k` to all other nodes.
- If all nodes are reachable, return the maximum time taken by the farthest node.
- If any node is unreachable, return `-1`.
{{< dots >}}
### Problem Assumptions ✅
- The network will be represented as a directed graph with unique edges.
{{< dots >}}
## Examples 🧩
- **Input:** `For times = [[1, 2, 1], [1, 3, 2], [3, 4, 1]], n = 4, k = 1`  \
  **Explanation:** By using Dijkstra's algorithm, we can calculate the shortest time for the signal to reach each node, and we find that the signal reaches all nodes in 3 units of time.

{{< dots >}}
## Approach 🚀
This problem can be solved using Dijkstra's algorithm to find the shortest path from the starting node to all other nodes in the graph.

### Initial Thoughts 💭
- We need to find the shortest time for a signal to reach all nodes from the starting node.
- The problem can be modeled as a shortest path problem in a weighted directed graph.
- Since the graph can have up to 6000 edges, Dijkstra's algorithm with a priority queue should be efficient enough.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one node and one edge, so no empty graph cases.
- For large inputs (with up to 6000 edges), the solution should be optimized to handle the upper limits efficiently.
- If the starting node `k` is isolated or there are disconnected nodes, the function should return `-1`.
- Ensure that the algorithm works efficiently for graphs with up to 6000 edges.
{{< dots >}}
## Code 💻
```cpp
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
```

This is a C++ implementation of Dijkstra's algorithm to calculate the network delay time. It uses a priority queue to find the shortest time for all nodes to receive a signal starting from node k.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	```
	Function that computes the time it takes for all nodes to receive the signal starting from node 'k'.

2. **Variable Initialization**
	```cpp
	    map<int, map<int, int>> mp;
	```
	This map stores the network connections where each node is mapped to another node with its travel time.

3. **Loop Setup**
	```cpp
	    for(int i = 0; i < times.size(); i++) {
	```
	Loop to iterate through the 'times' array and populate the map with edges (nodes and weights).

4. **Map Update**
	```cpp
	        mp[times[i][0]][times[i][1]] = times[i][2];
	```
	Updating the map with the source node, destination node, and the travel time between them.

5. **Priority Queue Setup**
	```cpp
	    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	```
	A priority queue to always process the node with the smallest time first.

6. **Visited Nodes Setup**
	```cpp
	    vector<int> vis(n + 1, 0);
	```
	A vector to track which nodes have been visited.

7. **Push Initial Node**
	```cpp
	    pq.push(make_pair(0, k));
	```
	Push the starting node 'k' with an initial time of 0 into the priority queue.

8. **While Loop**
	```cpp
	    while(!pq.empty()) {
	```
	While the priority queue is not empty, process each node.

9. **Extract Minimum**
	```cpp
	        auto it = pq.top();
	```
	Extract the node with the smallest accumulated time from the priority queue.

10. **Pop from Queue**
	```cpp
	        pq.pop();
	```
	Remove the top element (current node) from the priority queue.

11. **Skip Visited**
	```cpp
	        if(vis[it.second]) continue;
	```
	Skip nodes that have already been visited to avoid unnecessary processing.

12. **Mark as Visited**
	```cpp
	        vis[it.second] = true;
	```
	Mark the current node as visited.

13. **Decrement Nodes**
	```cpp
	        n--;
	```
	Decrement the number of remaining nodes to be processed.

14. **Check Completion**
	```cpp
	        if(n == 0) return it.first;
	```
	If all nodes are visited, return the accumulated time to reach the farthest node.

15. **Edge Traversal Check**
	```cpp
	        if(mp.count(it.second))
	```
	Check if the current node has any outgoing edges.

16. **Process Neighbors**
	```cpp
	            for(auto [key, val]: mp[it.second]) {
	```
	Iterate over all neighboring nodes of the current node.

17. **Push Neighbors to Queue**
	```cpp
	                pq.push(make_pair(val + it.first, key));
	```
	Push the neighboring nodes into the priority queue with the updated accumulated time.

18. **Return Failure**
	```cpp
	    return -1;
	```
	Return -1 if it's not possible to visit all nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(E log V), where E is the number of edges and V is the number of nodes.
- **Average Case:** O(E log V), as each edge and node is processed once.
- **Worst Case:** O(E log V), where E is the number of edges and V is the number of nodes.

The time complexity is O(E log V), where E is the number of edges and V is the number of nodes, due to the priority queue operations in Dijkstra's algorithm.

### Space Complexity 💾
- **Best Case:** O(V + E), for storing the graph and the priority queue.
- **Worst Case:** O(V + E), where V is the number of nodes and E is the number of edges.

The space complexity is O(V + E) due to the storage required for the graph and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/network-delay-time/description/)

---
{{< youtube Bp7STMWMMQw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
