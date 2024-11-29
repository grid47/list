
+++
authors = ["grid47"]
title = "Leetcode 1557: Minimum Number of Vertices to Reach All Nodes"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1557: Minimum Number of Vertices to Reach All Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oEy0bzfioG4"
youtube_upload_date="2023-05-18"
youtube_thumbnail="https://i.ytimg.com/vi/oEy0bzfioG4/maxresdefault.jpg"
comments = true
+++



---
In a directed acyclic graph with n vertices, find the smallest set of vertices from which all nodes in the graph are reachable.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the number of vertices n and an array of directed edges.
- **Example:** `n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]`
- **Constraints:**
	- 2 <= n <= 10^5
	- 1 <= edges.length <= min(10^5, n * (n - 1) / 2)
	- edges[i].length == 2
	- 0 <= fromi, toi < n
	- All pairs (fromi, toi) are distinct

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest set of vertices from which all nodes in the graph are reachable.
- **Example:** `Output: [0, 2, 3]`
- **Constraints:**
	- The output should be a list of vertices.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest set of vertices that can reach all the nodes in the graph.

- 1. Initialize an array to track the number of incoming edges for each vertex.
- 2. Traverse the edges to update the number of incoming edges for each vertex.
- 3. Identify vertices that have no incoming edges (i.e., vertices that must be included in the set).
- 4. Return the list of these vertices.
{{< dots >}}
### Problem Assumptions ✅
- The graph is a directed acyclic graph (DAG).
- There is always a unique solution.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6, edges = [[0, 1], [0, 2], [2, 5], [3, 4], [4, 2]]`  \
  **Explanation:** From vertex 0, we can reach nodes [0, 1, 2, 5], and from vertex 3, we can reach nodes [3, 4, 2, 5]. Therefore, the smallest set of vertices is [0, 3].

- **Input:** `n = 5, edges = [[0, 1], [2, 1], [3, 1], [1, 4], [2, 4]]`  \
  **Explanation:** The vertices 0, 2, and 3 are not reachable from any other node, so they must be included in the set. Any of these vertices can reach nodes 1 and 4.

{{< dots >}}
## Approach 🚀
The approach involves identifying vertices with no incoming edges, as these must be included in the smallest set of vertices that can reach all nodes.

### Initial Thoughts 💭
- The smallest set of vertices will be those that are not reachable from other vertices.
- By counting the number of incoming edges for each vertex, we can identify those vertices that must be included in the solution.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as n >= 2.
- The solution must efficiently handle large inputs with n up to 10^5.
- The graph is guaranteed to have a unique solution.
- The graph is a directed acyclic graph (DAG).
{{< dots >}}
## Code 💻
```cpp
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<int> ca(n, 0);
    vector<int> ans;
    for(auto e: edges) {
        ca[e[1]]++;
    }
    for(int i = 0; i< n ; i++)
    if(ca[i] == 0) ans.push_back(i);
    return ans;
}
```

This function `findSmallestSetOfVertices` takes in two parameters: an integer `n` (the number of vertices) and a 2D vector `edges` representing directed edges between vertices. It returns a vector containing the vertices that cannot be reached by any other vertex, also known as the smallest set of vertices that can reach all others in the graph.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
	```
	This is the function definition for `findSmallestSetOfVertices`, which takes in the number of vertices `n` and a 2D vector `edges` that represents directed edges between vertices. It returns a vector containing the smallest set of vertices that can reach all other vertices in the graph.

2. **Variable Initialization**
	```cpp
	    vector<int> ca(n, 0);
	```
	This line initializes a vector `ca` of size `n` with all values set to 0. It will be used to count the incoming edges for each vertex.

3. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	This line initializes an empty vector `ans` to store the vertices that are part of the smallest set of vertices.

4. **Loop Iteration**
	```cpp
	    for(auto e: edges) {
	```
	This for-each loop iterates over each edge in the `edges` vector, where `e` represents each directed edge in the form of a 2-element vector (source, destination).

5. **Edge Processing**
	```cpp
	        ca[e[1]]++;
	```
	For each edge, the count of incoming edges for the destination vertex (`e[1]`) is incremented in the `ca` vector.

6. **Loop Iteration**
	```cpp
	    for(int i = 0; i< n ; i++)
	```
	This for loop iterates through all vertices from 0 to `n-1` to check which vertices have no incoming edges.

7. **Condition Check**
	```cpp
	    if(ca[i] == 0) ans.push_back(i);
	```
	If a vertex `i` has no incoming edges (i.e., `ca[i] == 0`), it is added to the `ans` vector as it is part of the smallest set of vertices.

8. **Return Statement**
	```cpp
	    return ans;
	```
	The function returns the `ans` vector, which contains the smallest set of vertices that can reach all other vertices.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m) where n is the number of vertices and m is the number of edges.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the incoming edges count and the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/)

---
{{< youtube oEy0bzfioG4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
