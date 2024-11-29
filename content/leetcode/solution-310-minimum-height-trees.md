
+++
authors = ["grid47"]
title = "Leetcode 310: Minimum Height Trees"
date = "2024-10-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 310: Minimum Height Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Graph","Topological Sort"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/310.webp"
youtube = "wQGQnyv_9hI"
youtube_upload_date="2024-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/wQGQnyv_9hI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/310.webp" 
    alt="A series of tree structures, with each one growing taller or shorter as the minimum height tree is highlighted."
    caption="Solution to LeetCode 310: Minimum Height Trees Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a tree with 'n' nodes labeled from 0 to n-1, represented by 'n-1' edges. Your task is to find all roots that minimize the height of the tree. The height of a tree is defined as the number of edges in the longest downward path from the root to any leaf.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer 'n' and a list of 'n-1' edges that define the tree.
- **Example:** `n = 5, edges = [[1, 0], [1, 2], [2, 3], [2, 4]]`
- **Constraints:**
	- 1 <= n <= 20,000
	- edges.length == n - 1
	- 0 <= ai, bi < n
	- ai != bi
	- All pairs (ai, bi) are distinct
	- The input is guaranteed to be a valid tree

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of integers representing the nodes that minimize the height of the tree.
- **Example:** `[2]`
- **Constraints:**
	- The output list can have one or more nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the nodes that minimize the height of the tree by iterating from leaf nodes towards the center of the tree.

- Create an adjacency list representation of the tree.
- Track the degree of each node to identify leaf nodes.
- Remove leaf nodes iteratively to find the center(s) of the tree (or minimum height roots).
- Nodes remaining after iterating through the process are the minimum height tree roots.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is always valid and is guaranteed to contain no cycles.
- The input edges will always form a connected tree.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, edges = [[1, 0], [1, 2], [2, 3], [2, 4]]`  \
  **Explanation:** Rooting the tree at node 2 minimizes the height, as it is centrally located.

- **Input:** `n = 6, edges = [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]`  \
  **Explanation:** Nodes 3 and 4 minimize the height of the tree, resulting in a height of 2.

- **Input:** `n = 7, edges = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 5], [5, 6]]`  \
  **Explanation:** Node 3 minimizes the tree height as it is the center of this linear tree.

{{< dots >}}
## Approach 🚀
The problem can be solved by progressively removing leaf nodes until only the central nodes remain, which are the roots of the minimum height trees.

### Initial Thoughts 💭
- The tree is undirected and connected, which allows for a unique path between any two nodes.
- The height of the tree is minimized when the root is as central as possible, which can be found by peeling off leaf nodes.
{{< dots >}}
### Edge Cases 🌐
- There is no need to handle empty inputs, as the problem guarantees a valid tree with at least one node.
- The solution must efficiently handle the maximum constraint of n = 20,000.
- If the tree is a line (i.e., a path), the root is the middle node(s).
- Ensure the solution works in O(n) time to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if(n == 1) return {0};
    
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    for(auto e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
        if(degree[i] == 1)
            q.push(i);
    
    vector<int> res;
    
    while(!q.empty()) {
        res.clear();
        int sz = q.size();
        while(sz--) {
            int tmp = q.front();
            q.pop();
            res.push_back(tmp);
            for(auto nbr: adj[tmp]) {
                degree[nbr]--;
                if(degree[nbr] == 1)
                    q.push(nbr);
            }
        }
    }
    return res;
}
```

This function finds the minimum height trees in a given graph with `n` nodes and an array of edges. It uses a breadth-first search (BFS) to remove leaf nodes iteratively and find the nodes that form the center of the tree, which have the minimum height.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	```
	Define the function that accepts the number of nodes `n` and a vector of edges representing an undirected graph.

2. **Base Case**
	```cpp
	    if(n == 1) return {0};
	```
	If there is only one node, return it as the result since it's trivially the minimum height tree.

3. **Graph Initialization**
	```cpp
	    vector<vector<int>> adj(n);
	```
	Create an adjacency list to represent the graph, where each node points to its neighbors.

4. **Degree Initialization**
	```cpp
	    vector<int> degree(n, 0);
	```
	Initialize a degree array to keep track of the number of connections (edges) each node has.

5. **Graph Construction**
	```cpp
	    for(auto e: edges) {
	```
	Iterate over all edges to build the adjacency list and update the degree of each node.

6. **Edge Insertion**
	```cpp
	        adj[e[0]].push_back(e[1]);
	```
	For each edge, add the neighboring node to the adjacency list of the first node.

7. **Edge Insertion**
	```cpp
	        adj[e[1]].push_back(e[0]);
	```
	Similarly, add the neighboring node to the adjacency list of the second node.

8. **Degree Update**
	```cpp
	        degree[e[0]]++;
	```
	Increase the degree of the first node.

9. **Degree Update**
	```cpp
	        degree[e[1]]++;
	```
	Increase the degree of the second node.

10. **Queue Initialization**
	```cpp
	    queue<int> q;
	```
	Initialize a queue to perform a breadth-first search (BFS) from the leaf nodes.

11. **Queue Population**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Iterate through all the nodes to find those with only one connection (degree 1), which are leaves.

12. **Queue Population**
	```cpp
	        if(degree[i] == 1)
	```
	Check if the current node is a leaf node (degree 1).

13. **Queue Population**
	```cpp
	            q.push(i);
	```
	Push leaf nodes into the queue to start the BFS process.

14. **Result Initialization**
	```cpp
	    vector<int> res;
	```
	Initialize an empty result vector to store the nodes that will form the minimum height trees.

15. **BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop to process the leaf nodes and iteratively remove them.

16. **Clear Result**
	```cpp
	        res.clear();
	```
	Clear the result vector to store the next set of leaf nodes.

17. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Get the size of the current level of the BFS queue.

18. **BFS Inner Loop**
	```cpp
	        while(sz--) {
	```
	Process all the nodes at the current level.

19. **Queue Front**
	```cpp
	            int tmp = q.front();
	```
	Get the current node from the front of the queue.

20. **Queue Pop**
	```cpp
	            q.pop();
	```
	Remove the current node from the queue.

21. **Result Update**
	```cpp
	            res.push_back(tmp);
	```
	Add the current node to the result vector.

22. **Neighbor Processing**
	```cpp
	            for(auto nbr: adj[tmp]) {
	```
	Process all the neighbors of the current node.

23. **Degree Update**
	```cpp
	                degree[nbr]--;
	```
	Decrease the degree of the neighboring node.

24. **Leaf Detection**
	```cpp
	                if(degree[nbr] == 1)
	```
	Check if the neighboring node has become a leaf (degree 1).

25. **Queue Update**
	```cpp
	                    q.push(nbr);
	```
	Add the neighbor to the queue if it has become a leaf.

26. **BFS End**
	```cpp
	    }
	```
	End the main BFS loop.

27. **Return Result**
	```cpp
	    return res;
	```
	Return the list of nodes that form the minimum height trees.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as each node is processed at most once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the adjacency list and degree array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-height-trees/description/)

---
{{< youtube wQGQnyv_9hI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
