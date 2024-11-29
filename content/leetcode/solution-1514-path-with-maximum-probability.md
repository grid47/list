
+++
authors = ["grid47"]
title = "Leetcode 1514: Path with Maximum Probability"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1514: Path with Maximum Probability in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Graph","Heap (Priority Queue)","Shortest Path"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kPsDTGcrzGM"
youtube_upload_date="2023-02-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/kPsDTGcrzGM/maxresdefault.webp"
comments = true
+++



---
You are given an undirected, weighted graph of `n` nodes, represented by an edge list, where each edge connects two nodes with a given success probability. Given two nodes, `start` and `end`, find the path with the maximum probability of success to go from `start` to `end`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, an edge list `edges`, an array `succProb` of success probabilities for each edge, and two integers `start` and `end`, representing the nodes to traverse from and to.
- **Example:** `n = 4, edges = [[0,1],[1,2],[0,2],[2,3]], succProb = [0.9, 0.8, 0.5, 0.7], start = 0, end = 3`
- **Constraints:**
	- 2 <= n <= 10^4
	- 0 <= start, end < n
	- start != end
	- 0 <= a, b < n
	- a != b
	- 0 <= succProb.length == edges.length <= 2*10^4
	- 0 <= succProb[i] <= 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum probability of success of the path from `start` to `end`.
- **Example:** `0.31500`
- **Constraints:**
	- The answer must be accurate within a relative or absolute error of (10^{-5}).

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the path from `start` to `end` with the highest probability. This can be done using a modified Dijkstra's algorithm, where instead of finding the shortest path, we maximize the product of probabilities.

- Step 1: Build a graph representation where each edge has a success probability.
- Step 2: Use a priority queue to perform a modified Dijkstra's algorithm, where at each step, you explore the node with the maximum success probability.
- Step 3: Update the probability of reaching each neighboring node and continue until you reach the `end` node.
{{< dots >}}
### Problem Assumptions ✅
- The graph is connected, meaning there is at least one path from `start` to `end` unless otherwise stated.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4, edges = [[0,1],[1,2],[0,2],[2,3]], succProb = [0.9, 0.8, 0.5, 0.7], start = 0, end = 3`  \
  **Explanation:** The problem can be visualized as finding the best route from `0` to `3` by maximizing the product of success probabilities. The highest probability path is through `0 -> 1 -> 2 -> 3`, yielding a success probability of 0.504.

- **Input:** `n = 3, edges = [[0,1],[1,2]], succProb = [0.5, 0.5], start = 0, end = 2`  \
  **Explanation:** In this case, the only available path is `0 -> 1 -> 2`, and the success probability is `0.5 * 0.5 = 0.25`.

{{< dots >}}
## Approach 🚀
To solve this problem, we will use a priority queue to implement a variant of Dijkstra’s algorithm. Instead of minimizing the total weight, we will maximize the product of probabilities to reach the `end` node.

### Initial Thoughts 💭
- We need to maximize the product of probabilities to find the path with the highest probability of success.
- We will use a priority queue to explore nodes with the highest probability first, updating the probability of reaching neighboring nodes along the way.
{{< dots >}}
### Edge Cases 🌐
- The graph will never be empty as n >= 2.
- Ensure the algorithm works efficiently even for large inputs where n can be as large as 10^4 and edges as many as 2 * 10^4.
- Handle cases where there is no path from `start` to `end`.
- The solution must run in O(n log n) time to handle large graphs efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<vector<pair<int, double>>> grid;
vector<bool> vis;
double ans = 0;
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
    grid.resize(n);
    for(int i = 0; i < edges.size(); i++) {
        grid[edges[i][1]].push_back({edges[i][0], prob[i]});            
        grid[edges[i][0]].push_back({edges[i][1], prob[i]});
    }
    
    priority_queue<pair<double, int>> pq;

    vector<double> mx(n, 0);
    mx[start] = 1;
    vis.resize(n, false);
    // vis[start] = true;
    pq.push({1.0, start});
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        if(!vis[it.second]) {
            vis[it.second] = true;
            for(auto x: grid[it.second]) {
                if(mx[x.first] < it.first * x.second) {
                    mx[x.first] = it.first * x.second;
                    pq.push({it.first * x.second, x.first});
                }
            }
        }
    }
    return mx[end];
}
```

This function, `maxProbability`, calculates the maximum probability of reaching the end node in a graph, given a set of edges and their corresponding probabilities. The graph is modeled as a weighted undirected graph, and a priority queue is used for efficient processing of nodes with the highest probabilities.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<vector<pair<int, double>>> grid;
	```
	Declares a 2D vector `grid` to store the graph, where each element represents a node and a pair consisting of an adjacent node and the probability of traveling to that node.

2. **Variable Declaration**
	```cpp
	vector<bool> vis;
	```
	Declares a vector `vis` to track whether each node has been visited during the process.

3. **Variable Initialization**
	```cpp
	double ans = 0;
	```
	Declares a variable `ans` to store the final result, which will hold the maximum probability of reaching the destination node.

4. **Function Definition**
	```cpp
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& prob, int start, int end) {
	```
	Defines the function `maxProbability` which takes the number of nodes `n`, the list of edges `edges`, the list of probabilities `prob`, and the start and end nodes as input parameters. It returns the maximum probability of reaching the destination node.

5. **Graph Initialization**
	```cpp
	    grid.resize(n);
	```
	Resizes the `grid` to accommodate `n` nodes, ensuring each node has an associated adjacency list.

6. **Edge Processing**
	```cpp
	    for(int i = 0; i < edges.size(); i++) {
	```
	Iterates over the edges and processes each one to add connections to the adjacency list in `grid`.

7. **Edge Insertion**
	```cpp
	        grid[edges[i][1]].push_back({edges[i][0], prob[i]});
	```
	Adds an edge to the adjacency list of node `edges[i][1]`, connecting it to node `edges[i][0]` with the probability `prob[i]`.

8. **Edge Insertion**
	```cpp
	        grid[edges[i][0]].push_back({edges[i][1], prob[i]});
	```
	Adds an edge to the adjacency list of node `edges[i][0]`, connecting it to node `edges[i][1]` with the probability `prob[i]`. This ensures the graph is undirected.

9. **Priority Queue Declaration**
	```cpp
	    priority_queue<pair<double, int>> pq;
	```
	Declares a priority queue `pq` to process nodes with the highest probability first. The queue stores pairs of probabilities and node indices.

10. **Array Initialization**
	```cpp
	    vector<double> mx(n, 0);
	```
	Declares and initializes a vector `mx` to store the maximum probability of reaching each node. Initially, all probabilities are set to 0.

11. **Initial Probability Assignment**
	```cpp
	    mx[start] = 1;
	```
	Sets the probability of reaching the `start` node to 1, as the probability of starting at the start node is always 1.

12. **Visited Array Initialization**
	```cpp
	    vis.resize(n, false);
	```
	Resizes the `vis` vector to store `n` boolean values, initialized to `false`, to track whether each node has been visited.

13. **Priority Queue Insertion**
	```cpp
	    pq.push({1.0, start});
	```
	Pushes the `start` node into the priority queue with an initial probability of 1.0.

14. **While Loop Start**
	```cpp
	    while(!pq.empty()) {
	```
	Starts a while loop that continues as long as the priority queue `pq` is not empty.

15. **Pop from Priority Queue**
	```cpp
	        auto it = pq.top();
	```
	Extracts the top element from the priority queue, which is the node with the highest probability.

16. **Pop from Priority Queue**
	```cpp
	        pq.pop();
	```
	Removes the top element from the priority queue after it has been processed.

17. **Condition Check**
	```cpp
	        if(!vis[it.second]) {
	```
	Checks if the current node has not been visited. If it has not, the code proceeds to process it.

18. **Mark as Visited**
	```cpp
	            vis[it.second] = true;
	```
	Marks the current node as visited to avoid revisiting it in subsequent iterations.

19. **Loop Over Adjacent Nodes**
	```cpp
	            for(auto x: grid[it.second]) {
	```
	Loops through the adjacent nodes of the current node `it.second`.

20. **Condition Check**
	```cpp
	                if(mx[x.first] < it.first * x.second) {
	```
	Checks if the probability of reaching the adjacent node `x.first` is less than the current probability multiplied by the edge's probability `x.second`.

21. **Probability Update**
	```cpp
	                    mx[x.first] = it.first * x.second;
	```
	Updates the maximum probability for the adjacent node `x.first` if a higher probability path is found.

22. **Push to Priority Queue**
	```cpp
	                    pq.push({it.first * x.second, x.first});
	```
	Pushes the adjacent node `x.first` with the updated probability into the priority queue.

23. **Return Statement**
	```cpp
	    return mx[end];
	```
	Returns the maximum probability of reaching the destination node `end`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst case occurs when the priority queue has to process all the nodes, each requiring log n operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store probabilities for each node and the graph structure, leading to a space complexity of O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-with-maximum-probability/description/)

---
{{< youtube kPsDTGcrzGM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
