
+++
authors = ["grid47"]
title = "Leetcode 2685: Count the Number of Complete Components"
date = "2024-02-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2685: Count the Number of Complete Components in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "J43LjwWYch4"
youtube_upload_date="2023-05-14"
youtube_thumbnail="https://i.ytimg.com/vi/J43LjwWYch4/maxresdefault.jpg"
comments = true
+++



---
You are given a graph with `n` vertices, numbered from `0` to `n-1`. The graph contains undirected edges described in a 2D array `edges`, where each element `edges[i] = [ai, bi]` indicates that there is an undirected edge between vertices `ai` and `bi`. A connected component is a subgraph in which there is a path between any two vertices, and no vertex is connected to vertices outside of the subgraph. A connected component is said to be complete if there is an edge between every pair of vertices in that component. Your task is to return the number of complete connected components in the graph.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `n`, representing the number of vertices in the graph, and a list `edges` where each element is an edge connecting two vertices.
- **Example:** `Input: n = 6, edges = [[0,1], [0,2], [1,2], [3,4]]`
- **Constraints:**
	- 1 <= n <= 50
	- 0 <= edges.length <= n * (n - 1) / 2
	- edges[i].length == 2
	- 0 <= ai, bi <= n - 1
	- ai != bi
	- There are no repeated edges.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of complete connected components in the graph.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be a single integer representing the number of complete connected components.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of complete connected components in the graph, where each component must have an edge between every pair of its vertices.

- Step 1: Initialize a Union-Find (disjoint-set) data structure to track the connected components in the graph.
- Step 2: Process each edge and union the vertices that are connected by that edge.
- Step 3: For each connected component, check if it is complete by comparing the number of edges in the component with the expected number of edges for a complete graph (n*(n-1)/2).
- Step 4: Count how many of the connected components are complete and return that count.
{{< dots >}}
### Problem Assumptions ✅
- The graph may have disconnected components.
- The graph may have some incomplete components where not every pair of vertices is connected by an edge.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 6, edges = [[0,1], [0,2], [1,2], [3,4]]`  \
  **Explanation:** In this graph, there are 3 connected components. The first component, consisting of vertices 0, 1, and 2, is complete because there are edges between every pair. The second component, consisting of vertex 3 and 4, is also complete. The third component is just a single vertex, which is trivially complete. Thus, the output is 3.

- **Input:** `Input: n = 6, edges = [[0,1], [0,2], [1,2], [3,4], [3,5]]`  \
  **Explanation:** The first component, consisting of vertices 0, 1, and 2, is complete. However, the second component, consisting of vertices 3, 4, and 5, is not complete because there is no edge between vertices 4 and 5. Thus, the output is 1.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves using the Union-Find data structure to efficiently group connected vertices, and then checking if each component forms a complete graph.

### Initial Thoughts 💭
- We need to process the edges to group the vertices into connected components.
- For each component, we need to verify if it's complete by checking if it has the correct number of edges.
- Union-Find with path compression and union by rank is a good choice for efficiently managing the connected components.
{{< dots >}}
### Edge Cases 🌐
- If the graph has no edges, each vertex is its own component, and all components are trivially complete.
- For larger graphs with a large number of edges, the algorithm should efficiently handle them within the time limits.
- If the graph contains only one vertex, it is trivially a complete component.
- Ensure the solution works for the upper limits of the constraints, with n up to 50.
{{< dots >}}
## Code 💻
```cpp
int countCompleteComponents(int n, vector<vector<int>>& edges) {
    UF uf = UF(n);
    for(auto e: edges) {
        uf.join(e[0], e[1]);
    }
    set<int> pk;
    int res = 0;
        // cout << "edges membercnt edgescal \n";         
    for(int i = 0; i < n; i++) {
        int par = uf.find(i);
        if(pk.count(par)) continue;
        pk.insert(par);
        int cnt = uf.edge[par];
        // cout << cnt << " " << uf.rnk[par] << " " << uf.rnk[par] * (uf.rnk[par] - 1) / 2 << "\n";
        if(uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
    }
    return res;
}
```

The code defines a function `countCompleteComponents` that calculates the number of complete components in an undirected graph, represented by `n` nodes and an edge list `edges`. The function uses a Union-Find data structure to group connected nodes and checks whether each component satisfies the conditions of being complete.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int countCompleteComponents(int n, vector<vector<int>>& edges) {
	```
	This line declares the function `countCompleteComponents`, which takes in an integer `n` (number of nodes) and a reference to a 2D vector `edges` (edge list).

2. **Union-Find Setup**
	```cpp
	    UF uf = UF(n);
	```
	An instance of the Union-Find (UF) class is created with `n` elements. The UF class helps in efficiently managing the merging of nodes and finding their representative leaders.

3. **Edge Processing**
	```cpp
	    for(auto e: edges) {
	```
	A loop is initiated to iterate through each edge in the `edges` list.

4. **Union Operation**
	```cpp
	        uf.join(e[0], e[1]);
	```
	The `join` method of the Union-Find structure is called to merge the two nodes `e[0]` and `e[1]` of the current edge.

5. **Set Initialization**
	```cpp
	    set<int> pk;
	```
	A set `pk` is initialized to store unique parent nodes that are found during the traversal of the graph.

6. **Result Initialization**
	```cpp
	    int res = 0;
	```
	A variable `res` is initialized to 0. It will hold the count of complete components.

7. **Loop Through Nodes**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop is initiated to traverse all `n` nodes.

8. **Find Operation**
	```cpp
	        int par = uf.find(i);
	```
	The `find` method is called on the Union-Find instance to get the parent of node `i`.

9. **Skip Already Processed Parents**
	```cpp
	        if(pk.count(par)) continue;
	```
	If the parent `par` has already been processed (i.e., it's in the set `pk`), the loop skips to the next node.

10. **Insert Parent**
	```cpp
	        pk.insert(par);
	```
	The parent `par` is inserted into the set `pk` to mark it as processed.

11. **Edge Count Retrieval**
	```cpp
	        int cnt = uf.edge[par];
	```
	The number of edges in the component represented by `par` is retrieved from the `edge` array of the Union-Find structure.

12. **Complete Component Check**
	```cpp
	        if(uf.rnk[par] * (uf.rnk[par] - 1) / 2 == cnt) res++;
	```
	This condition checks if the component represented by `par` is complete. If it is, the result `res` is incremented.

13. **Return Result**
	```cpp
	    return res;
	```
	The function returns the final count of complete components.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is linear in terms of the number of vertices `n` and edges `m` due to the Union-Find operations and the edge processing.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the Union-Find structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-complete-components/description/)

---
{{< youtube J43LjwWYch4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
