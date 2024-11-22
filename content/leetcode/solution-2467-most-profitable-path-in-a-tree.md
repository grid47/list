
+++
authors = ["grid47"]
title = "Leetcode 2467: Most Profitable Path in a Tree"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2467: Most Profitable Path in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Tree","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MCp9k0kKQqc"
youtube_upload_date="2022-11-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MCp9k0kKQqc/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> par, dis;
    
    void dfs(int u, int p = 0, int d = 0) {
        dis[u] = d;
        par[u] = p;
        for(int v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, d +1);
        }
    }
    
     
    int dfs2(int u,vector<int>&amount,int p= 0){

        int ret = amount[u];

        int mxc = -INT_MAX;

        for(int v:adj[u]){

            if(v!=p){

                mxc= max(mxc,dfs2(v,amount,u));

            }

        }

		//if the node is leaf we just return its amount

        if(mxc==-INT_MAX)return ret;

        else return ret+mxc;

    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int cur = bob;
        int bob_dis = 0;
		//update the path of from Bob to 0
        while(cur!=0){
            if(dis[cur]>bob_dis){
                amount[cur] = 0;
            }else if(dis[cur]==bob_dis){
                amount[cur]/=2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0,amount);
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem is to find the most profitable path in a tree graph where each node has an associated profit (or loss). You are given a tree represented by an undirected graph, and you need to compute the path that maximizes the total profit, taking into account that one of the participants, Bob, will affect the profit on his path.

### Problem Understanding:
1. You are given a tree with `n` nodes where each node has an associated profit (or loss).
2. Bob starts from a particular node and moves to the root node (node 0). During this journey, he affects the profit at each node he visits:
   - If Bob visits a node at an even distance from the root, the profit is halved.
   - If Bob visits a node at an odd distance, the profit becomes 0.
3. You need to compute the path that maximizes the total profit, considering the modifications caused by Bob’s journey.

### Approach

To solve the problem, we will use a depth-first search (DFS) approach. The general idea is to perform DFS from the root node, keeping track of:
- The parent node for each node.
- The distance from the root for each node.
- The updated profit at each node after accounting for Bob’s journey.

**Steps**:
1. **DFS Traversal**: Start by performing DFS from the root to compute the parent and distance for each node.
2. **Bob’s Influence**: Modify the profit values for each node according to Bob's path. For nodes Bob visits:
   - At even distances, divide the profit by 2.
   - At odd distances, set the profit to 0.
3. **Profit Calculation**: Once the profits have been adjusted, perform a second DFS to calculate the total profit of the most profitable path, taking into account the modified profits.

### Code Breakdown

#### 1. **Initialization**:
```cpp
vector<vector<int>> adj;
vector<int> par, dis;
```
- `adj`: Adjacency list to store the tree structure (edges between nodes).
- `par`: A vector that stores the parent of each node. It will be used during DFS to backtrack and compute Bob’s influence.
- `dis`: A vector to store the distance from the root node (node 0) for each node.

#### 2. **DFS Function to Compute Parent and Distance**:
```cpp
void dfs(int u, int p = 0, int d = 0) {
    dis[u] = d;
    par[u] = p;
    for(int v : adj[u]) {
        if (v == p) continue; // Skip the parent node to avoid cycle
        dfs(v, u, d + 1);
    }
}
```
- This function performs a DFS traversal starting from node `u`. It computes:
  - `dis[u]`: The distance of node `u` from the root.
  - `par[u]`: The parent of node `u`.
  - The function iterates through all adjacent nodes (`v`) and recursively explores them.
  
#### 3. **DFS Function to Calculate the Maximum Profitable Path**:
```cpp
int dfs2(int u, vector<int>& amount, int p = 0) {
    int ret = amount[u]; // Start with the profit of the current node
    int mxc = -INT_MAX; // Initialize a variable to track the maximum subpath profit

    for(int v : adj[u]) {
        if(v != p) { // Avoid traversing back to the parent
            mxc = max(mxc, dfs2(v, amount, u)); // Calculate the maximum profit from each child
        }
    }

    if(mxc == -INT_MAX) return ret; // If no child was found, return the current node's profit
    else return ret + mxc; // Otherwise, return the current profit plus the max subpath profit
}
```
- This function calculates the maximum profit that can be achieved starting from node `u`. It recursively explores all child nodes and returns the profit of the most profitable path in the subtree rooted at `u`.

#### 4. **Main Function to Find the Most Profitable Path**:
```cpp
int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int n = amount.size();
    adj.resize(n, vector<int>()); // Resize the adjacency list to accommodate all nodes
    for(auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    par.resize(n); // Resize the parent array
    dis.resize(n); // Resize the distance array
    dfs(0); // Perform DFS from the root node (node 0)
    
    int cur = bob; // Start from Bob's initial position
    int bob_dis = 0; // Bob's current distance from the root
    
    // Update the path from Bob to the root (node 0) based on his journey
    while(cur != 0) {
        if(dis[cur] > bob_dis) {
            amount[cur] = 0; // Set profit to 0 for odd distances from the root
        } else if(dis[cur] == bob_dis) {
            amount[cur] /= 2; // Halve the profit for even distances from the root
        }
        cur = par[cur]; // Move Bob to the parent node
        bob_dis++; // Increment Bob's distance
    }
    
    // Finally, compute and return the maximum profitable path starting from the root
    return dfs2(0, amount);
}
```
- **Graph Construction**: First, we construct the adjacency list `adj` for the tree from the input edges.
- **DFS Initialization**: We perform a DFS traversal starting from the root node (node 0) to populate the `par` and `dis` arrays, which store the parent and distance for each node, respectively.
- **Bob’s Path Modification**: We update the profits of the nodes that Bob visits:
  - If Bob visits a node at an odd distance from the root, the profit is set to 0.
  - If Bob visits a node at an even distance from the root, the profit is halved.
- **Max Profit Calculation**: After modifying the profits, we perform another DFS (`dfs2`) to compute the maximum profit path starting from the root.

### Complexity Analysis

1. **Time Complexity**:
   - Constructing the adjacency list takes \(O(E)\), where \(E\) is the number of edges (which is \(n - 1\) for a tree with \(n\) nodes).
   - The first DFS (`dfs`) runs in \(O(n)\), since each node is visited once.
   - The second DFS (`dfs2`) also runs in \(O(n)\).
   - Therefore, the overall time complexity is \(O(n)\), where \(n\) is the number of nodes in the tree.

2. **Space Complexity**:
   - The adjacency list `adj` requires \(O(n)\) space.
   - The `par` and `dis` arrays also require \(O(n)\) space each.
   - Therefore, the space complexity is \(O(n)\).

### Conclusion

The solution efficiently solves the problem using DFS with memoization to compute the most profitable path in the tree, accounting for the influence of Bob's journey. By performing two DFS traversals—one for calculating distances and parent-child relationships and another for calculating the maximum profit—the solution is both time-efficient and space-efficient, with a time complexity of \(O(n)\). The solution can handle large inputs with up to \(10^5\) nodes in a tree.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-profitable-path-in-a-tree/description/)

---
{{< youtube MCp9k0kKQqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
