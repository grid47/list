
+++
authors = ["grid47"]
title = "Leetcode 1129: Shortest Path with Alternating Colors"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1129: Shortest Path with Alternating Colors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VaW0deOb2aQ"
youtube_upload_date="2024-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/VaW0deOb2aQ/maxresdefault.jpg"
comments = true
+++



---
You are given a directed graph with n nodes, where each node is labeled from 0 to n-1. The graph contains edges that can be either red or blue. You are provided with two lists of edges: redEdges and blueEdges, where redEdges[i] = [ai, bi] indicates a directed red edge from node ai to node bi, and blueEdges[j] = [uj, vj] indicates a directed blue edge from node uj to node vj. Your goal is to find the shortest alternating path from node 0 to each node x. Return an array answer where each answer[x] is the length of the shortest alternating path from node 0 to node x, or -1 if no such path exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays representing red and blue edges in a directed graph. Each array consists of pairs of integers denoting the start and end nodes of the respective colored edges.
- **Example:** `Input: n = 4, redEdges = [[0,1],[1,2]], blueEdges = [[2,3]]`
- **Constraints:**
	- 1 <= n <= 100
	- 0 <= redEdges.length, blueEdges.length <= 400
	- redEdges[i].length == blueEdges[j].length == 2
	- 0 <= ai, bi, uj, vj < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array answer where answer[x] is the length of the shortest alternating path from node 0 to node x, or -1 if no such path exists.
- **Example:** `Output: [0, 1, 2, 3]`
- **Constraints:**
	- The array should have length n.
	- The value of each element should be either the shortest path length or -1 if no path exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the shortest alternating paths from node 0 to all other nodes, alternating between red and blue edges.

- Initialize a graph representation with two colors (red and blue).
- Use a BFS (Breadth-First Search) to explore the graph, alternating between red and blue edges.
- Track the shortest path to each node for both edge colors and ensure the paths alternate.
{{< dots >}}
### Problem Assumptions ✅
- The graph may contain self-loops and parallel edges.
- The input will always be valid according to the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, redEdges = [[0,1],[1,2]], blueEdges = [[2,3]]`  \
  **Explanation:** Starting from node 0, we first move to node 1 with a red edge, then to node 2 with a blue edge, and finally to node 3 with a red edge. This gives us the shortest alternating path to each node.

- **Input:** `Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]`  \
  **Explanation:** Starting from node 0, we can reach node 1 with a red edge, but node 2 is not reachable with an alternating path, so the answer for node 2 is -1.

{{< dots >}}
## Approach 🚀
Use a BFS algorithm to explore the graph while alternating between red and blue edges, updating the shortest path lengths for each node.

### Initial Thoughts 💭
- The problem is a shortest path problem with alternating edge colors, so a modified BFS is a suitable approach.
- We can use BFS to traverse the graph, but we'll need to alternate between the two edge colors during the traversal.
{{< dots >}}
### Edge Cases 🌐
- If both redEdges and blueEdges are empty, the result should be [0] since no paths exist except the starting node.
- The solution should efficiently handle large input sizes, up to 100 nodes and 400 edges.
- Handle cases where a node cannot be reached with an alternating path, returning -1 for such nodes.
- Ensure the BFS algorithm runs within the time limits for the maximum constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &greenEdges) {

    vector<vector<int>> gph(n);
    vector<vector<vector<int>>> grid(2, gph);

    for(int i = 0; i < redEdges.size(); i++)
        grid[0][redEdges[i][0]].push_back(redEdges[i][1]);

    for(int i = 0; i < greenEdges.size(); i++)
        grid[1][greenEdges[i][0]].push_back(greenEdges[i][1]);

    vector<vector<int>> len(2, vector<int>(n, 2 * n));

    queue<vector<int>> q;

    len[0][0] = 0;
    len[1][0] = 0;
    q.push({0, 0});
    q.push({0, 1});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        int node = it[0], color = it[1];
        for(int nxt: grid[1 - color][node]) {
            if(len[1 - color][nxt] == 2 * n) {
                len[1 - color][nxt] = len[color][node] + 1;
                q.push({nxt, 1 - color});
            }
        }
    }

    vector<int> res(n, 0);
    for(int i = 0; i < n; i++) {
        res[i] = min(len[0][i], len[1][i]);
        if(res[i] == 2 * n) res[i] = -1;
    }

    return res;
}
```

This function computes the shortest alternating paths in a graph where edges are either red or green. It uses BFS and two color queues to explore paths alternatively through red and green edges.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &greenEdges) {
	```
	This function initializes the parameters: the number of nodes `n`, and two sets of edges, `redEdges` and `greenEdges`, for the graph.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> gph(n);
	```
	This initializes a graph `gph`, represented as an adjacency list of size `n`.

3. **Grid Initialization**
	```cpp
	    vector<vector<vector<int>>> grid(2, gph);
	```
	A 3D grid is initialized, where `grid[0]` holds the red edges and `grid[1]` holds the green edges.

4. **Edge Insertion**
	```cpp
	    for(int i = 0; i < redEdges.size(); i++)
	```
	This loop iterates through the `redEdges` and populates the `grid[0]` with the red edges.

5. **Edge Insertion**
	```cpp
	        grid[0][redEdges[i][0]].push_back(redEdges[i][1]);
	```
	This line inserts a red edge into the graph by pushing it into `grid[0]`.

6. **Edge Insertion**
	```cpp
	    for(int i = 0; i < greenEdges.size(); i++)
	```
	This loop iterates through the `greenEdges` and populates the `grid[1]` with the green edges.

7. **Edge Insertion**
	```cpp
	        grid[1][greenEdges[i][0]].push_back(greenEdges[i][1]);
	```
	This line inserts a green edge into the graph by pushing it into `grid[1]`.

8. **Distance Array Initialization**
	```cpp
	    vector<vector<int>> len(2, vector<int>(n, 2 * n));
	```
	This initializes a `len` array to store the shortest path lengths for each color (red and green), initially set to a large value (2 * n).

9. **Queue Initialization**
	```cpp
	    queue<vector<int>> q;
	```
	A queue `q` is initialized to perform BFS traversal.

10. **Starting Point Setup**
	```cpp
	    len[0][0] = 0;
	```
	This sets the starting point for the red edges (color 0) to have a distance of 0.

11. **Starting Point Setup**
	```cpp
	    len[1][0] = 0;
	```
	This sets the starting point for the green edges (color 1) to have a distance of 0.

12. **Queue Push**
	```cpp
	    q.push({0, 0});
	```
	Push the starting point with color 0 (red) into the queue.

13. **Queue Push**
	```cpp
	    q.push({0, 1});
	```
	Push the starting point with color 1 (green) into the queue.

14. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop to explore the graph.

15. **Queue Pop**
	```cpp
	        auto it = q.front();
	```
	Pop an element from the front of the queue.

16. **Queue Pop**
	```cpp
	        q.pop();
	```
	Remove the front element from the queue.

17. **Node and Color Extraction**
	```cpp
	        int node = it[0], color = it[1];
	```
	Extract the node and color information from the queue element.

18. **Neighbor Traversal**
	```cpp
	        for(int nxt: grid[1 - color][node]) {
	```
	Traverse all the neighboring nodes in the opposite color (i.e., if the current node is reached by a red edge, now explore the green edges).

19. **Edge Relaxation**
	```cpp
	            if(len[1 - color][nxt] == 2 * n) {
	```
	If the neighbor node has not been visited, relax the edge and update its distance.

20. **Distance Update**
	```cpp
	                len[1 - color][nxt] = len[color][node] + 1;
	```
	Update the shortest path length for the neighbor node.

21. **Queue Push**
	```cpp
	                q.push({nxt, 1 - color});
	```
	Push the neighboring node and its associated edge color into the queue.

22. **Result Calculation**
	```cpp
	    vector<int> res(n, 0);
	```
	Initialize a result array to store the shortest alternating paths for each node.

23. **Path Assignment**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over each node to calculate the shortest alternating path.

24. **Path Assignment**
	```cpp
	        res[i] = min(len[0][i], len[1][i]);
	```
	For each node, select the minimum distance between red and green paths.

25. **Edge Case Handling**
	```cpp
	        if(res[i] == 2 * n) res[i] = -1;
	```
	If a node is unreachable, mark its result as -1.

26. **Return Result**
	```cpp
	    return res;
	```
	Return the result array with the shortest alternating paths for all nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where n is the number of nodes and m is the number of edges. We process each edge and node once during the BFS traversal.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m) due to the storage required for the adjacency list and the BFS queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/shortest-path-with-alternating-colors/description/)

---
{{< youtube VaW0deOb2aQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
