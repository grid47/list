
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
+++



---
**Code:**

{{< highlight cpp >}}
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to count the number of occurrences of each character in the subtree of a tree structure where each node is labeled with a character. Given the number of nodes, the edges connecting them, and a string of labels corresponding to each node, the task is to return an array where each index `i` holds the count of the label present at node `i` within the subtree rooted at `i`.

### Approach

To efficiently solve this problem, we will utilize a Depth-First Search (DFS) strategy. The main idea is to traverse the tree, starting from the root node (usually node 0), and for each node, we will calculate the frequency of its corresponding label in its subtree.

#### Key Steps in the Approach:

1. **Graph Representation**: Use an adjacency list to represent the tree structure. Each node points to its neighbors, allowing easy traversal.

2. **DFS Traversal**: Perform a DFS starting from the root node:
   - For each node, we maintain a frequency count of each character in the subtree.
   - When visiting a node, we call the DFS recursively for its unvisited neighbors.
   - After returning from the DFS call for a child node, we update the frequency counts of the current node's label.

3. **Count Update**: For each node, after calculating the frequencies from its children, we increment the count for the node's label and store this value in the result array.

4. **Result Compilation**: After the DFS completes, the result array will contain the desired counts for each node.

### Code Breakdown (Step by Step)

Here's a detailed explanation of the provided code:

```cpp
class Solution {
    vector<int> ans;
    vector<int> vst;
```
- We define a class `Solution` with two member variables:
  - `ans`: This vector will store the result counts for each node.
  - `vst`: This vector tracks whether a node has been visited during DFS.

```cpp
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 1);
        vst.resize(n, 0);
```
- The public method `countSubTrees` initializes the `ans` vector to size `n` with all values set to 1 (to account for the node itself), and the `vst` vector is initialized to track visits.

```cpp
        vector<vector<int>> adj(n);
        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
```
- We create an adjacency list `adj` to represent the tree. Each edge connects two nodes bidirectionally.

```cpp
        vst[0] = 1;
        dfs(n, 0, adj, labels);
        return ans;
    }
```
- We mark the root node (node 0) as visited and start the DFS traversal. Finally, we return the `ans` vector containing the counts for each node.

```cpp
    vector<int> dfs(int n, int u, vector<vector<int>>& adj, string &labels) {
        vector<int> cnt(26, 0);
```
- The `dfs` method takes the current node `u` and initializes a count vector `cnt` of size 26 (for each letter in the alphabet) to zero.

```cpp
        for(auto v: adj[u]) {
            if(vst[v]) continue;
```
- We iterate over each neighbor `v` of the current node `u`. If `v` has already been visited, we skip it.

```cpp
            vst[v] = 1;
            vector<int> sub = dfs(n, v, adj, labels);
```
- If `v` is unvisited, we mark it as visited and recursively call `dfs` for `v`, storing the result in `sub`.

```cpp
            for(int i = 0; i < 26; i++)
                cnt[i] += sub[i];
```
- After returning from the DFS call, we update our count vector `cnt` by adding the counts from the child node's subtree to the current node's count.

```cpp
        cnt[labels[u] - 'a']++;
        ans[u] = cnt[labels[u] - 'a'];
```
- We increment the count for the current node's label and store this value in the `ans` vector at index `u`.

```cpp
        return cnt;
    }
};
```
- Finally, we return the updated count vector for the current node.

### Complexity

#### Time Complexity
- The time complexity of this solution is \(O(n)\), where \(n\) is the number of nodes. Each node and edge is processed exactly once during the DFS traversal.

#### Space Complexity
- The space complexity is also \(O(n)\) due to the storage used for the adjacency list and the `vst` and `cnt` vectors.

### Conclusion

This implementation efficiently counts the occurrences of each label in the subtree of a tree using a depth-first search approach. 

**Key Insights**:
- **Tree Traversal**: The depth-first search strategy allows us to explore all nodes in a structured manner, ensuring that we correctly aggregate counts from child nodes to parent nodes.
- **Space Optimization**: The use of a count vector of fixed size (26) for characters makes the algorithm efficient and easy to manage.

This approach is well-suited for problems involving tree structures, especially when character frequencies or similar calculations are required for subtrees. The method can be adapted to various scenarios where tree traversal and counting are needed.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/)

---
{{< youtube 1vni2K0FIg8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
