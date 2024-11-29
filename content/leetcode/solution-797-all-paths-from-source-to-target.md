
+++
authors = ["grid47"]
title = "Leetcode 797: All Paths From Source to Target"
date = "2024-08-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 797: All Paths From Source to Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp"
youtube = "MQU2IIWwaOg"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/MQU2IIWwaOg/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/797.webp" 
    alt="A graph where all paths are traced from source to target, with each path softly glowing as it is found."
    caption="Solution to LeetCode 797: All Paths From Source to Target Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a directed acyclic graph (DAG) with `n` nodes, labeled from 0 to n-1. Find all possible paths from node 0 to node n-1 and return these paths in any order. The graph is represented such that each node has a list of other nodes that can be visited directly from it.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of lists, where `graph[i]` contains all the nodes you can visit directly from node `i`.
- **Example:** `Input: graph = [[1, 2], [3], [3], []]`
- **Constraints:**
	- 2 <= n <= 15
	- 0 <= graph[i][j] < n
	- graph[i][j] != i (no self-loops)
	- All elements in graph[i] are unique
	- The input graph is guaranteed to be a DAG

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of all possible paths from node 0 to node n-1. Each path is represented as a list of nodes, starting from node 0 and ending at node n-1.
- **Example:** `Output: [[0, 1, 3], [0, 2, 3]]`
- **Constraints:**
	- The answer will be a list of lists, where each list represents a valid path from node 0 to node n-1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all paths starting from node 0 to node n-1, respecting the directed edges in the graph.

- Use a breadth-first search (BFS) or depth-first search (DFS) approach to explore the graph starting from node 0.
- For each node, explore all possible nodes it can lead to by following the directed edges.
- Once you reach node n-1, add the path to the result.
- If a node cannot lead to node n-1, backtrack and explore other paths.
{{< dots >}}
### Problem Assumptions ✅
- The graph is non-cyclic, meaning it does not contain any cycles.
- The graph has at least two nodes (i.e., node 0 and node n-1).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: graph = [[1, 2], [3], [3], []]`  \
  **Explanation:** In this graph, node 0 can reach nodes 1 and 2, node 1 can reach node 3, and node 2 can also reach node 3. The two possible paths from node 0 to node 3 are [0, 1, 3] and [0, 2, 3].

- **Input:** `Input: graph = [[4, 3, 1], [3, 2, 4], [3], [4], []]`  \
  **Explanation:** This graph has multiple paths from node 0 to node 4: [0, 4], [0, 3, 4], [0, 1, 3, 4], [0, 1, 2, 3, 4], and [0, 1, 4].

{{< dots >}}
## Approach 🚀
A depth-first search (DFS) approach is used to explore all possible paths from node 0 to node n-1. Starting from node 0, recursively visit each neighboring node, adding it to the current path. When node n-1 is reached, add the path to the result.

### Initial Thoughts 💭
- We need to explore all possible paths in the DAG from node 0 to node n-1.
- DFS or BFS can be used for exploring the graph, as both approaches allow us to find all paths.
{{< dots >}}
### Edge Cases 🌐
- If the graph is empty or contains no edges, no paths can be found.
- If the graph is very large, ensure the solution can handle it efficiently, particularly considering the constraint of n <= 15.
- If all nodes except for node 0 have no outgoing edges, there will be no paths from node 0 to node n-1.
- The graph must have at least two nodes (node 0 and node n-1).
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans;
    queue<pair<int, vector<int>>> q;
    q.push({0, {0}});
    while(!q.empty()) {
        int x = q.front().first;
        vector<int> t = q.front().second;
        q.pop();
        if(x == graph.size() - 1) ans.push_back(t);
        for(int k: graph[x]) {
            t.push_back(k);
            q.push({k, t});
            t.pop_back();
        }
    }
    return ans;
}
```

This function finds all paths from the source node (0) to the target node (graph.size() - 1) in a directed graph using a BFS approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	```
	The function starts by defining the return type as a 2D vector of integers, which will store all the possible paths from the source to the target.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	This line initializes a 2D vector 'ans' which will store the valid paths found from source to target.

3. **Queue Initialization**
	```cpp
	    queue<pair<int, vector<int>>> q;
	```
	A queue is initialized to facilitate BFS traversal. Each element in the queue is a pair consisting of a node index and a partial path leading up to that node.

4. **Initial Push**
	```cpp
	    q.push({0, {0}});
	```
	The starting node (0) is pushed onto the queue, along with an initial path that only contains the source node.

5. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	This while loop continues until the queue is empty, processing each node in the graph in a breadth-first manner.

6. **Extract Node**
	```cpp
	        int x = q.front().first;
	```
	The node index 'x' is extracted from the front of the queue.

7. **Extract Path**
	```cpp
	        vector<int> t = q.front().second;
	```
	The path leading to node 'x' is extracted from the front of the queue.

8. **Pop Queue**
	```cpp
	        q.pop();
	```
	The front element (node and path) is removed from the queue to continue processing the next element.

9. **Check Target**
	```cpp
	        if(x == graph.size() - 1) ans.push_back(t);
	```
	If the current node 'x' is the target node, the current path 't' is added to the result set 'ans'.

10. **For Loop**
	```cpp
	        for(int k: graph[x]) {
	```
	This for loop iterates over all the neighbors 'k' of the current node 'x'.

11. **Push Neighbor**
	```cpp
	            t.push_back(k);
	```
	The neighbor node 'k' is added to the current path 't'.

12. **Queue Push**
	```cpp
	            q.push({k, t});
	```
	The new pair, consisting of the neighbor 'k' and the updated path 't', is pushed onto the queue.

13. **Pop Last Node**
	```cpp
	            t.pop_back();
	```
	After processing the neighbor, the last node is removed from the path 't' to backtrack.

14. **Return Result**
	```cpp
	    return ans;
	```
	The function returns the 2D vector 'ans', which contains all the valid paths from the source to the target node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the graph.
- **Average Case:** O(2^n), considering that in the worst case, there can be an exponential number of paths.
- **Worst Case:** O(2^n), where n is the number of nodes, since each node could potentially lead to multiple paths.

The time complexity is exponential because we need to explore all possible paths from node 0 to node n-1.

### Space Complexity 💾
- **Best Case:** O(n), as the space used depends on the recursion depth and the number of paths stored.
- **Worst Case:** O(n), where n is the number of nodes, for storing the current path during DFS.

The space complexity is linear in the worst case, due to recursion and storing the paths.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-paths-from-source-to-target/description/)

---
{{< youtube MQU2IIWwaOg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
