
+++
authors = ["grid47"]
title = "Leetcode 133: Clone Graph"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 133: Clone Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/133.webp"
youtube = "mQeF6bN8hMk"
youtube_upload_date="2021-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/mQeF6bN8hMk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/133.webp" 
    alt="A graph with nodes gently duplicating and glowing, forming an identical copy with soft edges."
    caption="Solution to LeetCode 133: Clone Graph Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a reference to a node in a connected, undirected graph. Each node in the graph contains a value (integer) and a list of its neighbors. Your task is to return a deep copy of the entire graph starting from the given node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a graph represented by an adjacency list, where each list describes the neighbors of a node.
- **Example:** `[[2,4],[1,3],[2,4],[1,3]]`
- **Constraints:**
	- 0 <= adjList.length <= 100
	- Each node in the graph is unique.
	- There are no repeated edges or self-loops in the graph.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the deep copy of the graph starting from the given node.
- **Example:** `[[2,4],[1,3],[2,4],[1,3]]`
- **Constraints:**
	- The output will be the same structure as the input graph, but with distinct node objects.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to create a deep copy of the graph by copying each node and its neighbors while ensuring that no node is visited more than once.

- 1. Create a hashmap to store copies of each node as they are encountered.
- 2. Use a recursive approach to visit each node and copy it.
- 3. For each node, create a new copy and recursively copy its neighbors.
{{< dots >}}
### Problem Assumptions ✅
- The graph is always connected.
- There are no duplicate edges or self-loops.
{{< dots >}}
## Examples 🧩
- **Input:** `[[2,4],[1,3],[2,4],[1,3]]`  \
  **Explanation:** The graph has 4 nodes and 4 edges, where each node is connected to its respective neighbors.

- **Input:** `[[]]`  \
  **Explanation:** This graph consists of a single node with no neighbors.

{{< dots >}}
## Approach 🚀
The solution uses a depth-first search (DFS) approach, leveraging recursion and a hashmap to track visited nodes and avoid revisiting nodes during the copy process.

### Initial Thoughts 💭
- We need to create a new node for each existing node in the graph.
- We need to ensure that we don't revisit nodes that have already been copied.
- A recursive DFS approach will be efficient for this problem as we need to traverse the entire graph and copy each node and its neighbors.
{{< dots >}}
### Edge Cases 🌐
- If the input graph is empty, return an empty list.
- The solution should handle up to 100 nodes and avoid stack overflow or memory issues.
- If the graph contains only one node, return a copy of that single node with no neighbors.
- The graph is always connected, so no need to handle disconnected graphs.
{{< dots >}}
## Code 💻
```cpp
map<int, Node*> mp;
Node* cloneGraph(Node* node) {
    if(node == NULL) return node;
    Node * ans;
    ans = copy(node);
    return ans;
}

Node* copy(Node* node) {
    if(mp.count(node->val)) return mp[node->val];
    Node* ans = new Node(node->val);
    mp[node->val] = ans;
    for(auto it: node->neighbors) {
        Node* n = copy(it);
        ans->neighbors.push_back(n);
    }
    return ans;
}
```

This is a solution to clone a graph. The graph is represented using a Node class that has a value and a list of neighbors. A map is used to store previously copied nodes to avoid infinite loops and redundant copying.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Map Insertion**
	```cpp
	map<int, Node*> mp;
	```
	Declare a map to store the copied nodes. The key is the node's value, and the value is the node object itself.

2. **Function Definition**
	```cpp
	Node* cloneGraph(Node* node) {
	```
	Define the function `cloneGraph` that takes a `Node` pointer and returns a cloned graph.

3. **Null Check**
	```cpp
	    if(node == NULL) return node;
	```
	Check if the input node is NULL. If it is, return NULL as there is nothing to clone.

4. **Variable Declaration**
	```cpp
	    Node * ans;
	```
	Declare a pointer `ans` which will store the cloned graph.

5. **Function Call**
	```cpp
	    ans = copy(node);
	```
	Call the helper function `copy` to clone the graph starting from the given node.

6. **Return Statement**
	```cpp
	    return ans;
	```
	Return the cloned graph.

7. **Helper Function Definition**
	```cpp
	Node* copy(Node* node) {
	```
	Define the helper function `copy` that clones the graph recursively.

8. **Map Lookup**
	```cpp
	    if(mp.count(node->val)) return mp[node->val];
	```
	Check if the node has already been cloned (present in the map). If it is, return the existing clone.

9. **Node Creation**
	```cpp
	    Node* ans = new Node(node->val);
	```
	Create a new node with the same value as the input node.

10. **Map Insertion**
	```cpp
	    mp[node->val] = ans;
	```
	Insert the new node into the map to store it for future reference.

11. **Graph Traversal**
	```cpp
	    for(auto it: node->neighbors) {
	```
	Loop through each neighbor of the current node to clone them.

12. **Recursive Call**
	```cpp
	        Node* n = copy(it);
	```
	Recursively call `copy` on each neighbor to clone it.

13. **List Insertion**
	```cpp
	        ans->neighbors.push_back(n);
	```
	Add the cloned neighbor to the `neighbors` list of the current cloned node.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Return the cloned node after its neighbors have been cloned and added.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of nodes in the graph.
- **Average Case:** O(N + E), where E is the number of edges in the graph, as every edge needs to be visited once.
- **Worst Case:** O(N + E), where N is the number of nodes and E is the number of edges.

The time complexity is linear in terms of nodes and edges because we traverse each node and each edge once.

### Space Complexity 💾
- **Best Case:** O(N), as we store a copy of each node in the hashmap.
- **Worst Case:** O(N), where N is the number of nodes, for the space used by the recursive stack and the hashmap storing copies of the nodes.

The space complexity is O(N) due to the storage requirements for the copied nodes and the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/clone-graph/description/)

---
{{< youtube mQeF6bN8hMk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
