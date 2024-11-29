
+++
authors = ["grid47"]
title = "Leetcode 886: Possible Bipartition"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 886: Possible Bipartition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "WIJa0GAC9Cg"
youtube_upload_date="2020-05-27"
youtube_thumbnail="https://i.ytimg.com/vi/WIJa0GAC9Cg/maxresdefault.jpg"
comments = true
+++



---
You are given a group of n people, labeled from 1 to n. Each person may dislike other people, and they should not be placed in the same group. Your task is to determine if it is possible to split the group of people into two subgroups, such that no one in the same group dislikes each other. Each pair of dislikes is represented by an array of two people who cannot be in the same group. Return true if such a split is possible, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer n, representing the number of people, and an array dislikes, where each element is a pair [ai, bi], indicating that person ai dislikes person bi.
- **Example:** `Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]`
- **Constraints:**
	- 1 <= n <= 2000
	- 0 <= dislikes.length <= 10^4
	- dislikes[i].length == 2
	- 1 <= ai < bi <= n
	- All the pairs of dislikes are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to split the people into two groups such that no one dislikes anyone in the same group. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating whether the split is possible.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if the graph representing the dislikes is bipartite, meaning the people can be split into two groups such that no two people in the same group dislike each other.

- Represent the dislikes as a graph where each person is a node, and an edge between two nodes means they dislike each other.
- Use a graph traversal algorithm (like DFS or BFS) to check if the graph can be colored with two colors (representing two groups) such that no two adjacent nodes (people) have the same color.
{{< dots >}}
### Problem Assumptions ✅
- Each pair of dislikes represents a mutual dislike between two people.
- It is assumed that there are no other relationships besides dislikes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]`  \
  **Explanation:** In this case, the dislikes form a bipartite graph, meaning we can split the people into two groups. Group 1 can be [1, 4], and Group 2 can be [2, 3]. No one in the same group dislikes each other.

- **Input:** `Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]`  \
  **Explanation:** In this case, it is impossible to split the people into two groups, because person 1 dislikes both person 2 and person 3, and person 2 and person 3 also dislike each other. Therefore, more than two groups are needed.

{{< dots >}}
## Approach 🚀
To solve this problem, we will model the people and their dislikes as a graph and check if the graph is bipartite. A bipartite graph is one where we can divide the set of nodes into two disjoint sets such that no two adjacent nodes belong to the same set.

### Initial Thoughts 💭
- This is a classic graph problem where we need to check for bipartiteness using graph traversal techniques.
- Using BFS or DFS, we can attempt to color the nodes and check if we encounter any conflicts where two connected nodes end up with the same color.
{{< dots >}}
### Edge Cases 🌐
- If there are no dislikes, it's trivially possible to split the people into two groups.
- Ensure the solution handles cases where n is large (up to 2000) and dislikes can be up to 10^4.
- If dislikes are sparse (few pairs), the problem is easier to solve, as fewer constraints are placed on the groups.
- Be mindful of the time complexity, as a solution with O(n + m) complexity will be efficient enough for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool possibleBipartition(int n, vector<vector<int>>& dlk) {
    UF* uf = new UF(n + 1);
    vector<vector<int>> gph(n + 1);
    for(int i = 0; i < dlk.size(); i++) {
        gph[dlk[i][0]].push_back(dlk[i][1]);
        gph[dlk[i][1]].push_back(dlk[i][0]);            
    }

    for(int i = 1; i <= n; i++) {
        for(int x: gph[i]) {
            if(uf->find(x) == uf->find(i)) return false;
            uf->uni(gph[i][0], x);
        }
    }
    return true;
}
```

This is the complete implementation of the algorithm to determine if it's possible to bipartition a graph. It uses union-find (UF) to manage disjoint sets and iterates through the graph to check for conflicts in the bipartition.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	bool possibleBipartition(int n, vector<vector<int>>& dlk) {
	```
	Define the function that checks if the graph can be bipartitioned into two sets. It takes the number of nodes and a list of edges.

2. **Data Initialization**
	```cpp
	    UF* uf = new UF(n + 1);
	```
	Create a new union-find (UF) structure to manage the connected components. The size is n + 1 to accommodate 1-based indexing.

3. **Data Initialization**
	```cpp
	    vector<vector<int>> gph(n + 1);
	```
	Initialize an adjacency list (graph) to store the edges. Each node will have a list of nodes it's connected to.

4. **Edge Processing**
	```cpp
	    for(int i = 0; i < dlk.size(); i++) {
	```
	Loop through all edges in the input list (dlk) to build the graph.

5. **Edge Processing**
	```cpp
	        gph[dlk[i][0]].push_back(dlk[i][1]);
	```
	For each edge, add the connection from the first node to the second node in the adjacency list.

6. **Edge Processing**
	```cpp
	        gph[dlk[i][1]].push_back(dlk[i][0]);
	```
	Add the reverse connection from the second node to the first node, since the graph is undirected.

7. **Bipartition Check**
	```cpp
	    for(int i = 1; i <= n; i++) {
	```
	Loop through each node to check its connections and determine if the graph can be bipartitioned.

8. **Bipartition Check**
	```cpp
	        for(int x: gph[i]) {
	```
	For each connected node, check if it conflicts with the current node's partition.

9. **Bipartition Check**
	```cpp
	            if(uf->find(x) == uf->find(i)) return false;
	```
	If both nodes belong to the same set, return false, as this indicates a conflict in the bipartition.

10. **Union Operation**
	```cpp
	            uf->uni(gph[i][0], x);
	```
	Union the current node with the connected node, indicating they belong to the same set.

11. **Return**
	```cpp
	    return true;
	```
	If no conflicts were found, return true, indicating that the graph can be bipartitioned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

In the worst case, we traverse all the nodes and edges of the graph once, which takes O(n + m) time.

### Space Complexity 💾
- **Best Case:** O(n + m)
- **Worst Case:** O(n + m)

The space complexity is O(n + m) because we need to store the graph and color information for each person.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/possible-bipartition/description/)

---
{{< youtube WIJa0GAC9Cg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
