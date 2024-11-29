
+++
authors = ["grid47"]
title = "Leetcode 684: Redundant Connection"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 684: Redundant Connection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp"
youtube = "FXWRE67PLL0"
youtube_upload_date="2021-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/FXWRE67PLL0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/684.webp" 
    alt="A graph where redundant connections are detected and softly glowing to indicate the loop."
    caption="Solution to LeetCode 684: Redundant Connection Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a graph that started as a tree with n nodes. One additional edge has been added, creating a cycle. Your task is to find and return the redundant edge that, when removed, would turn the graph back into a tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of edges in a graph, where each edge connects two nodes. The graph has one extra edge added, causing a cycle.
- **Example:** `[[1,2],[1,3],[2,3]]`
- **Constraints:**
	- 3 <= n <= 1000
	- edges[i].length == 2
	- 1 <= ai < bi <= edges.length
	- ai != bi
	- There are no repeated edges.
	- The graph is connected.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the redundant edge that can be removed to make the graph a valid tree.
- **Example:** `[2, 3]`
- **Constraints:**
	- The output will be a pair of nodes representing the redundant edge.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the redundant edge that, when removed, removes the cycle and returns the graph to a tree structure.

- 1. Traverse the list of edges.
- 2. For each edge, check if adding it forms a cycle.
- 3. If a cycle is formed, return the current edge as the redundant one.
{{< dots >}}
### Problem Assumptions ✅
- The graph is initially a tree, and only one extra edge is added to form a cycle.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1,2],[1,3],[2,3]]`  \
  **Explanation:** In this example, adding the edge [2,3] forms a cycle, and removing this edge restores the graph to a tree.

- **Input:** `[[1,2],[2,3],[3,4],[1,4],[1,5]]`  \
  **Explanation:** Here, the edge [1,4] is redundant because its addition creates a cycle between nodes 1, 2, 3, and 4.

{{< dots >}}
## Approach 🚀
We can use the Union-Find algorithm to detect cycles and identify the redundant edge.

### Initial Thoughts 💭
- We need to detect if adding an edge creates a cycle, which is the point at which we find the redundant edge.
- The Union-Find algorithm helps efficiently determine if two nodes are already connected, which helps us find the redundant edge.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least three nodes and one extra edge.
- The algorithm needs to handle up to 1000 edges efficiently.
- A graph with the minimum number of nodes (3) will still have one extra edge causing a cycle.
- The Union-Find approach works efficiently under the given constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UF* uf = new UF(n);
    for(int i = 0; i < n; i++)
        if(!uf->uni(edges[i][0], edges[i][1])) {
            return edges[i];
        }
    return edges[0];
}
```

This method identifies the redundant connection in an undirected graph using the Union-Find (UF) data structure. It iterates through the edges, checking if adding an edge forms a cycle. If so, the edge is redundant and is returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. ****
	```cpp
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	```
	Define the method 'findRedundantConnection' that accepts a list of edges and returns the redundant edge that creates a cycle in the graph.

2. ****
	```cpp
	    int n = edges.size();
	```
	Initialize the variable 'n' with the size of the 'edges' vector, representing the number of edges in the graph.

3. ****
	```cpp
	    UF* uf = new UF(n);
	```
	Create a new instance of the Union-Find data structure, initialized with 'n' elements, to track the connected components in the graph.

4. ****
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Start a loop that iterates through each edge in the graph.

5. ****
	```cpp
	        if(!uf->uni(edges[i][0], edges[i][1])) {
	```
	Check if the two nodes connected by the current edge are already in the same component using the 'uni' method from the Union-Find class.

6. ****
	```cpp
	            return edges[i];
	```
	If the nodes are already connected (forming a cycle), return the current edge as the redundant edge.

7. ****
	```cpp
	    return edges[0];
	```
	If no redundant edge is found, return the first edge in the list by default.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The algorithm runs in O(n) time due to the efficient union-find operations.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage of the Union-Find data structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/redundant-connection/description/)

---
{{< youtube FXWRE67PLL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
