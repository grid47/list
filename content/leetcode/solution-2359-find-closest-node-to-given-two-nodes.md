
+++
authors = ["grid47"]
title = "Leetcode 2359: Find Closest Node to Given Two Nodes"
date = "2024-03-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2359: Find Closest Node to Given Two Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AZA8orksO4w"
youtube_upload_date="2023-01-25"
youtube_thumbnail="https://i.ytimg.com/vi/AZA8orksO4w/maxresdefault.jpg"
comments = true
+++



---
You are given a directed graph with n nodes, where each node can have at most one outgoing edge. You are provided with an array `edges` representing the graph, where `edges[i]` indicates a directed edge from node `i` to node `edges[i]` (or -1 if there is no outgoing edge). You are also given two nodes `node1` and `node2`. The task is to return the node that is reachable from both `node1` and `node2`, such that the maximum of the distances from `node1` and `node2` to that node is minimized. If there are multiple such nodes, return the smallest index, or return `-1` if no such node exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the following elements: an array `edges` of size n (1 <= n <= 10^5) representing the graph, and two integers `node1` and `node2` (0 <= node1, node2 < n).
- **Example:** `edges = [1, 2, -1], node1 = 0, node2 = 2`
- **Constraints:**
	- 2 <= n <= 10^5
	- -1 <= edges[i] < n
	- edges[i] != i
	- 0 <= node1, node2 < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index of the node that can be reached from both `node1` and `node2` with the minimized maximum distance, or -1 if no such node exists.
- **Example:** `Output: 2`
- **Constraints:**
	- Return the node index with the smallest maximum distance.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the node that minimizes the maximum distance from both `node1` and `node2` to that node.

- Perform Depth-First Search (DFS) to calculate the distance from `node1` and `node2` to all other nodes.
- Iterate through all nodes, calculate the maximum distance for each node, and track the smallest such maximum.
{{< dots >}}
### Problem Assumptions ✅
- The graph may contain cycles, but each node has at most one outgoing edge.
- There is no self-loop (edges[i] != i).
{{< dots >}}
## Examples 🧩
- **Input:** `edges = [2, 2, 3, -1], node1 = 0, node2 = 1`  \
  **Explanation:** The possible distances to nodes from `node1` and `node2` are compared. The maximum of the distances to each node is calculated, and node 2 minimizes this value.

{{< dots >}}
## Approach 🚀
We can use DFS to calculate the distances from both `node1` and `node2` to all other nodes, and then find the node that minimizes the maximum distance.

### Initial Thoughts 💭
- We need to calculate the distance from `node1` and `node2` to each other node in the graph.
- The maximum of these two distances for each node should be minimized.
- The distance for a node can be computed with a DFS traversal. By storing the distances from both `node1` and `node2`, we can easily compute the desired result.
{{< dots >}}
### Edge Cases 🌐
- Empty graph (n = 0) is not possible due to constraints.
- Ensure the solution is efficient for large graphs with up to 10^5 nodes.
- Cycles in the graph may cause nodes to be revisited multiple times.
- Make sure to handle graphs with cycles and ensure that DFS terminates properly in such cases.
{{< dots >}}
## Code 💻
```cpp

void dfs(int node, vector<int> &edge, vector<int> &vis, int x) {
    vis[node] = x;
    if(edge[node] != -1 && vis[edge[node]] == -1)
        dfs(edge[node], edge, vis, x + 1);
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, -1);
    dfs(node1, edges, dist1, 0);
    vector<int> dist2(n, -1);
    dfs(node2, edges, dist2, 0);
    
    int dist, ans = -1, sol = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(dist1[i] == -1 || dist2[i] == -1)
            continue;
        else
            dist = max(dist1[i], dist2[i]);
        
        if(dist < sol) {
            sol = dist;
            ans = i;
        }
    }
    
    return ans;
}
```

The solution uses Depth-First Search (DFS) to calculate the shortest distance for both nodes to all other nodes in the graph. Then, it finds the closest meeting point between the two nodes by comparing their distances from each node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void dfs(int node, vector<int> &edge, vector<int> &vis, int x) {
	```
	This function performs a DFS traversal starting from the given node. It marks each node with a distance value 'x' to track the distance from the starting node.

2. **Action**
	```cpp
	    vis[node] = x;
	```
	Mark the current node with the distance 'x' in the visitation array.

3. **Condition**
	```cpp
	    if(edge[node] != -1 && vis[edge[node]] == -1)
	```
	If the current node has a neighbor and the neighbor has not been visited yet, perform DFS on that neighbor.

4. **Recursive Call**
	```cpp
	        dfs(edge[node], edge, vis, x + 1);
	```
	Recursively call DFS for the neighbor node, incrementing the distance 'x' by 1.

5. **Function Definition**
	```cpp
	int closestMeetingNode(vector<int>& edges, int node1, int node2) {
	```
	This function finds the closest node where both node1 and node2 can meet by calculating their respective distances from every other node.

6. **Variable Initialization**
	```cpp
	    int n = edges.size();
	```
	Store the size of the edges array, which represents the number of nodes in the graph.

7. **Variable Initialization**
	```cpp
	    vector<int> dist1(n, -1);
	```
	Create an array to store the distances for node1, initializing all values to -1 (indicating that no nodes have been visited yet).

8. **Function Call**
	```cpp
	    dfs(node1, edges, dist1, 0);
	```
	Call the DFS function for node1 to calculate its distance to all other nodes.

9. **Variable Initialization**
	```cpp
	    vector<int> dist2(n, -1);
	```
	Create an array to store the distances for node2, initializing all values to -1.

10. **Function Call**
	```cpp
	    dfs(node2, edges, dist2, 0);
	```
	Call the DFS function for node2 to calculate its distance to all other nodes.

11. **Variable Initialization**
	```cpp
	    int dist, ans = -1, sol = INT_MAX;
	```
	Initialize variables to store the maximum distance ('dist') and the node with the smallest distance ('ans').

12. **Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over all nodes to find the closest meeting node.

13. **Condition**
	```cpp
	        if(dist1[i] == -1 || dist2[i] == -1)
	```
	Skip nodes that are not reachable by either node1 or node2.

14. **Action**
	```cpp
	            continue;
	```
	If a node is unreachable by either of the nodes, continue to the next iteration.

15. **Else Block**
	```cpp
	        else
	```
	If the node is reachable by both node1 and node2.

16. **Distance Calculation**
	```cpp
	            dist = max(dist1[i], dist2[i]);
	```
	Calculate the maximum of the two distances (the furthest distance for each node) to determine the meeting point.

17. **Condition**
	```cpp
	        if(dist < sol) {
	```
	If the calculated distance is smaller than the previous solution, update the solution.

18. **Action**
	```cpp
	            sol = dist;
	```
	Update the smallest distance.

19. **Action**
	```cpp
	            ans = i;
	```
	Store the current node as the best meeting point.

20. **Return Statement**
	```cpp
	    return ans;
	```
	Return the node with the smallest maximum distance, which is the closest meeting point.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each DFS traversal takes O(n), and iterating through the nodes also takes O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We need O(n) space to store the distances from both `node1` and `node2`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/)

---
{{< youtube AZA8orksO4w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
