
+++
authors = ["grid47"]
title = "Leetcode 2497: Maximum Star Sum of a Graph"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2497: Maximum Star Sum of a Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Graph","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fmTiTN7Raek"
youtube_upload_date="2022-12-10"
youtube_thumbnail="https://i.ytimg.com/vi/fmTiTN7Raek/maxresdefault.jpg"
comments = true
+++



---
Given a graph with n nodes, each node having a value, and a list of edges connecting the nodes, your task is to determine the maximum star sum that can be obtained. A star graph is a subgraph where all edges are connected to a central node. The star sum is the sum of the values of the central node and the nodes connected by edges to it. You are allowed to include at most k edges in the star graph.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array vals representing the values of the nodes, a 2D integer array edges representing the undirected edges, and an integer k representing the maximum number of edges that can be included in the star graph.
- **Example:** `Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2`
- **Constraints:**
	- 1 <= n <= 10^5
	- -10^4 <= vals[i] <= 10^4
	- 0 <= edges.length <= min(n * (n - 1) / 2, 10^5)
	- edges[i].length == 2
	- 0 <= ai, bi <= n - 1
	- ai != bi
	- 0 <= k <= n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum star sum that can be obtained from any star graph in the input graph, with at most k edges.
- **Example:** `Output: 16`
- **Constraints:**
	- The sum should include the value of the central node and the values of the nodes connected by at most k edges.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the maximum possible sum of a star graph, centered at any node, using at most k edges.

- 1. Initialize a priority queue for each node to store the values of its neighbors.
- 2. Iterate over the nodes and calculate the sum of the node's value and the maximum values from the neighbors' values, considering at most k neighbors.
- 3. For each node, compute the net sum and update the maximum star sum encountered.
- 4. Return the maximum star sum after processing all nodes.
{{< dots >}}
### Problem Assumptions ✅
- The input graph is connected and the values of nodes and edges are within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2`  \
  **Explanation:** In this case, the star graph with the maximum sum is centered at node 3, with neighbors 1 and 4. The sum is 4 (value of node 3) + 2 (value of node 1) + 10 (value of node 4) = 16.

- **Input:** `Input: vals = [-5], edges = [], k = 0`  \
  **Explanation:** Here, the only possible star graph is the node itself (node 0). Since there are no edges and k = 0, the star sum is just the value of node 0, which is -5.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we need to use a greedy approach where we consider each node as the center of a potential star graph and evaluate the maximum possible sum by selecting at most k neighboring nodes with the highest values.

### Initial Thoughts 💭
- We need to prioritize nodes with higher values in order to maximize the star sum.
- A priority queue can help us efficiently select the highest values from a node's neighbors.
{{< dots >}}
### Edge Cases 🌐
- If there are no edges in the graph, the maximum star sum is just the value of any single node.
- For large graphs with up to 100,000 nodes, the algorithm must be efficient in handling edge cases and ensuring the process runs within time limits.
- Handle cases where nodes have negative values effectively, ensuring that the star sum is correctly calculated even when all nodes have negative values.
- Ensure that the algorithm respects the constraint of selecting at most k neighbors for the star graph.
{{< dots >}}
## Code 💻
```cpp
int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    int n = vals.size();
    vector<priority_queue<int>> grid(n);
    
    for(auto it: edges) {
        grid[it[0]].push(vals[it[1]]);
        grid[it[1]].push(vals[it[0]]);
    }
    
    int sum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int net = vals[i];
        int tmp = k;
        sum = max(net, sum);            
        while(tmp-- && !grid[i].empty()) {
            net += grid[i].top();
            grid[i].pop();
            sum = max(net, sum);                
        }
    }
    return sum;
}
```

The code defines a function `maxStarSum` that computes the maximum possible sum for a node in a graph where each node has a value, and edges connect them. The function considers up to `k` highest values from the neighbors of each node to maximize the sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
	```
	Defines the function `maxStarSum` which accepts a vector of integers `vals`, a 2D vector `edges`, and an integer `k` representing the maximum number of neighboring node values to add to the sum.

2. **Array Operations**
	```cpp
	    int n = vals.size();
	```
	Gets the size of the `vals` vector, which represents the number of nodes in the graph.

3. **Data Structure Initialization**
	```cpp
	    vector<priority_queue<int>> grid(n);
	```
	Initializes a vector of priority queues to store the neighboring node values for each node. The priority queue will help to easily fetch the highest values.

4. **Looping**
	```cpp
	    for(auto it: edges) {
	```
	Iterates through each edge in the `edges` list, where each edge is a pair of connected nodes.

5. **Priority Queue Operations**
	```cpp
	        grid[it[0]].push(vals[it[1]]);
	```
	For each edge, pushes the value of the neighboring node (`it[1]`) into the priority queue of the first node (`it[0]`).

6. **Priority Queue Operations**
	```cpp
	        grid[it[1]].push(vals[it[0]]);
	```
	Similarly, for the reverse direction of the edge, pushes the value of the first node (`it[0]`) into the priority queue of the second node (`it[1]`).

7. **Variable Initialization**
	```cpp
	    int sum = INT_MIN;
	```
	Initializes `sum` to the smallest possible integer value to track the maximum sum encountered during the calculations.

8. **Looping**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Starts a loop to process each node in the graph.

9. **Variable Initialization**
	```cpp
	        int net = vals[i];
	```
	Initializes `net` with the value of the current node (`vals[i]`). This variable will store the sum for the current node.

10. **Variable Initialization**
	```cpp
	        int tmp = k;
	```
	Initializes `tmp` to `k`, which tracks the remaining number of neighboring nodes to consider for the sum.

11. **Mathematical Operations**
	```cpp
	        sum = max(net, sum);            
	```
	Compares the current node's value (`net`) with the overall `sum` and updates `sum` with the larger value.

12. **Looping**
	```cpp
	        while(tmp-- && !grid[i].empty()) {
	```
	Enters a while loop to add the largest neighbor values to `net`, as long as there are remaining neighbors (`tmp--`) and the priority queue for the node is not empty.

13. **Priority Queue Operations**
	```cpp
	            net += grid[i].top();
	```
	Adds the largest value from the current node's priority queue to `net`.

14. **Priority Queue Operations**
	```cpp
	            grid[i].pop();
	```
	Removes the largest value from the current node's priority queue after it has been added to `net`.

15. **Mathematical Operations**
	```cpp
	            sum = max(net, sum);                
	```
	Updates the `sum` to the larger value between `net` and the previous `sum`.

16. **Return Statement**
	```cpp
	    return sum;
	```
	Returns the final maximum sum after processing all nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is O(n log n) because we process each node and each edge, and the priority queue operations take logarithmic time.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) as we store a priority queue for each node, which can store up to n neighbor values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/)

---
{{< youtube fmTiTN7Raek >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
