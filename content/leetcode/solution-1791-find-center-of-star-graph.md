
+++
authors = ["grid47"]
title = "Leetcode 1791: Find Center of Star Graph"
date = "2024-05-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1791: Find Center of Star Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jBD2_Eh4SlU"
youtube_upload_date="2021-03-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jBD2_Eh4SlU/maxresdefault.webp"
comments = true
+++



---
You are given an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a type of graph where one central node is connected to all other nodes. In this problem, you are given a list of edges where each edge represents a connection between two nodes. Your task is to find the center of the star graph, which is the node that is connected to every other node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D integer array, 'edges', where each element [u, v] represents an edge between nodes u and v.
- **Example:** `Input: edges = [[3, 4], [4, 2], [1, 4]]`
- **Constraints:**
	- 3 <= n <= 10^5
	- edges.length == n - 1
	- edges[i].length == 2
	- 1 <= ui, vi <= n
	- ui != vi

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the center of the star graph, which is the node that is connected to every other node.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To identify the central node of the star graph from the given edges.

- Check the first two edges and compare the nodes involved in them.
- The center node is the one that appears in both edges, as it connects to all other nodes.
{{< dots >}}
### Problem Assumptions ✅
- The given edges always represent a valid star graph with one center node.
{{< dots >}}
## Examples 🧩
- **Input:** `edges = [[3, 4], [4, 2], [1, 4]]`  \
  **Explanation:** Node 4 appears in all edges, so it is the center node.

- **Input:** `edges = [[1, 2], [5, 1], [1, 3], [1, 4]]`  \
  **Explanation:** Node 1 appears in all edges, so it is the center node.

{{< dots >}}
## Approach 🚀
To find the center of the star graph, we can use the fact that the center node will appear in multiple edges. By examining just the first two edges, we can easily determine the center node.

### Initial Thoughts 💭
- The center node is the one that connects to all other nodes.
- By checking only the first two edges, we can quickly identify the center node.
- Check which node appears in both edges and return it as the center.
{{< dots >}}
### Edge Cases 🌐
- There will never be empty input as per the problem constraints.
- The solution should efficiently handle up to 10^5 nodes.
- The star graph is always valid, so we don’t need to check for invalid graphs.
- The input always represents a valid star graph with exactly one center node.
{{< dots >}}
## Code 💻
```cpp
int findCenter(vector<vector<int>>& e) {
return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
}
```

This function finds the center of a star graph, where the center is the common node that appears in both of the edges. The function checks the first two edges in the input list `e` and returns the common node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findCenter(vector<vector<int>>& e) {
	```
	Define the function `findCenter`, which takes a reference to a vector of vectors `e` representing the edges of the graph. The function returns the center of the star graph.

2. **Condition Check**
	```cpp
	return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];
	```
	Check if the first element of the first edge (`e[0][0]`) is equal to the first or second element of the second edge (`e[1][0]` or `e[1][1]`). If it matches, return that element as the center. Otherwise, return the second element of the first edge (`e[0][1]`).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), when the center is found after checking the first two edges.
- **Average Case:** O(1), since we only need to check two edges to find the center.
- **Worst Case:** O(1), as we are only checking the first two edges.

The time complexity is constant since we only need to examine two edges.

### Space Complexity 💾
- **Best Case:** O(1), no additional space needed.
- **Worst Case:** O(1), as no extra space is required.

The space complexity is constant, as the solution does not require additional space that grows with input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-center-of-star-graph/description/)

---
{{< youtube jBD2_Eh4SlU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
