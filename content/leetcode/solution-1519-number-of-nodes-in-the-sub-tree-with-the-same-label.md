
+++
authors = ["grid47"]
title = "Leetcode 1519: Number of Nodes in the Sub-Tree With the Same Label"
date = "2024-06-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1519: Number of Nodes in the Sub-Tree With the Same Label in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1vni2K0FIg8"
youtube_upload_date="2020-07-19"
youtube_thumbnail="https://i.ytimg.com/vi/1vni2K0FIg8/maxresdefault.jpg"
comments = true
+++



---
You are given a tree with `n` nodes, where each node has a label, and your task is to find the number of nodes in the subtree rooted at each node that have the same label as that node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n`, an array of edges, and a string of labels.
- **Example:** `n = 6, edges = [[0,1],[0,2],[1,3],[1,4],[2,5]], labels = 'abacba'`
- **Constraints:**
	- 1 <= n <= 10^5
	- edges.length == n - 1
	- 0 <= ai, bi < n
	- ai != bi
	- labels.length == n
	- labels consists only of lowercase English letters.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element `ans[i]` represents the number of nodes in the subtree rooted at node `i` that have the same label as node `i`.
- **Example:** `[2, 1, 1, 1, 1, 1]`
- **Constraints:**
	- The answer is an array of size `n`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the tree and, for each node, count how many nodes in its subtree have the same label.

- Step 1: Build the tree using an adjacency list from the edges.
- Step 2: Perform a Depth First Search (DFS) traversal from the root to visit each node.
- Step 3: For each node, count the number of nodes with the same label in its subtree, including itself.
- Step 4: Return the result as an array.
{{< dots >}}
### Problem Assumptions ✅
- The tree is rooted at node 0.
- Each node has a unique label.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 6, edges = [[0,1],[0,2],[1,3],[1,4],[2,5]], labels = 'abacba'`  \
  **Explanation:** Node 0 has label 'a', and its subtree contains node 2 with label 'a', making the count 2. Similarly, other nodes' subtrees are evaluated.

{{< dots >}}
## Approach 🚀
To solve the problem, a Depth First Search (DFS) is used to traverse the tree, and for each node, we count how many nodes in its subtree share its label.

### Initial Thoughts 💭
- The problem requires efficient subtree counting with respect to labels.
- We can use a DFS traversal and keep track of the counts of each label in the subtree of each node.
{{< dots >}}
### Edge Cases 🌐
- There are no empty trees, as n >= 1.
- Ensure the algorithm can handle up to 10^5 nodes efficiently.
- Handle cases where all nodes have the same label or all labels are unique.
- The solution must work efficiently for trees with a large number of nodes (up to 10^5).
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> ans;
vector<int> vst;
public:
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    ans.resize(n, 1);
    vst.resize(n, 0);
    vector<vector<int>> adj(n);
    for(auto &e: edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vst[0] = 1;
    dfs(n, 0, adj, labels);
    return ans;
}

vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
    vector<int> cnt(26, 0);
    for(auto v: adj[u]) {
        if(vst[v]) continue;

        vst[v] = 1;
        vector<int> sub = dfs(n, v, adj, labels);
        for(int i = 0; i < 26; i++)
            cnt[i] += sub[i];
    }

    cnt[labels[u] - 'a']++;
    ans[u] = cnt[labels[u] - 'a'];
    return cnt;
}
```

The solution uses depth-first search (DFS) to count the number of nodes in each subtree that have a specific label. The result for each node is stored in the `ans` array, which is returned after processing all nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This declares the class `Solution` which encapsulates the method for solving the problem of counting subtree labels.

2. **Variable Declaration**
	```cpp
	vector<int> ans;
	```
	Declares the vector `ans` which will hold the result of the number of nodes with the same label in each subtree.

3. **Variable Declaration**
	```cpp
	vector<int> vst;
	```
	Declares the vector `vst` which will be used to track whether a node has been visited during the DFS traversal.

4. **Access Specifier**
	```cpp
	public:
	```
	Defines the public section of the class, where the methods `countSubTrees` and `dfs` are declared.

5. **Function Definition**
	```cpp
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
	```
	Defines the `countSubTrees` function, which calculates the number of nodes in each subtree with the same label for each node.

6. **Variable Initialization**
	```cpp
	    ans.resize(n, 1);
	```
	Resizes the `ans` vector to have `n` elements, all initialized to 1, since every node initially counts itself as part of its subtree.

7. **Variable Initialization**
	```cpp
	    vst.resize(n, 0);
	```
	Resizes the `vst` vector to have `n` elements, all initialized to 0, indicating that no nodes have been visited initially.

8. **Adjacency List Initialization**
	```cpp
	    vector<vector<int>> adj(n);
	```
	Initializes the adjacency list `adj`, which will store the graph's edges. Each node will have a list of its adjacent nodes.

9. **Loop Start**
	```cpp
	    for(auto &e: edges) {
	```
	Iterates over all edges in the input `edges` list to build the adjacency list `adj`.

10. **Edge Insertion**
	```cpp
	        adj[e[0]].push_back(e[1]);
	```
	For each edge, this adds node `e[1]` to the adjacency list of node `e[0]`, representing the undirected edge.

11. **Edge Insertion**
	```cpp
	        adj[e[1]].push_back(e[0]);
	```
	Adds node `e[0]` to the adjacency list of node `e[1]` to complete the undirected graph representation.

12. **Visited Array Update**
	```cpp
	    vst[0] = 1;
	```
	Marks the starting node (node 0) as visited.

13. **DFS Call**
	```cpp
	    dfs(n, 0, adj, labels);
	```
	Calls the `dfs` function to start the depth-first search from node 0.

14. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the `ans` vector, which contains the results for each node after the DFS traversal.

15. **Function Definition**
	```cpp
	vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
	```
	Defines the `dfs` function, which performs depth-first search and returns the count of nodes in the subtree of each node `u` with the same label.

16. **Variable Declaration**
	```cpp
	    vector<int> cnt(26, 0);
	```
	Declares a vector `cnt` to store the counts of each label in the subtree. There are 26 possible labels ('a' to 'z').

17. **Loop Start**
	```cpp
	    for(auto v: adj[u]) {
	```
	Iterates through all adjacent nodes `v` of the current node `u`.

18. **Condition Check**
	```cpp
	        if(vst[v]) continue;
	```
	Skips the node `v` if it has already been visited to avoid revisiting nodes.

19. **Visited Array Update**
	```cpp
	        vst[v] = 1;
	```
	Marks the adjacent node `v` as visited.

20. **DFS Recursion**
	```cpp
	        vector<int> sub = dfs(n, v, adj, labels);
	```
	Recursively calls the `dfs` function for the adjacent node `v` and stores the result in the `sub` vector.

21. **Subtree Count Aggregation**
	```cpp
	        for(int i = 0; i < 26; i++)
	```
	Iterates through each of the 26 possible labels.

22. **Subtree Count Aggregation**
	```cpp
	            cnt[i] += sub[i];
	```
	Adds the counts from the `sub` vector (which contains the subtree counts for the adjacent node) to the current `cnt` vector.

23. **Label Count Update**
	```cpp
	    cnt[labels[u] - 'a']++;
	```
	Increments the count for the label at node `u` by 1.

24. **Result Update**
	```cpp
	    ans[u] = cnt[labels[u] - 'a'];
	```
	Updates the `ans` vector with the count of the label at node `u`.

25. **Return Statement**
	```cpp
	    return cnt;
	```
	Returns the `cnt` vector, which contains the count of each label in the subtree rooted at node `u`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we visit each node once and process each edge once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the adjacency list and the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)

---
{{< youtube 1vni2K0FIg8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
