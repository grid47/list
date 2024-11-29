
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
comments = true
+++



---
In a tree with n nodes labeled from 0 to n - 1, each node has a gate with a price to open. Alice starts at node 0 and Bob starts at node bob. Alice moves towards a leaf node, and Bob moves towards node 0. At every node, both Alice and Bob either pay the price to open the gate, or they receive a reward. If they reach a node simultaneously, they share the price/reward equally. Return the maximum net income Alice can achieve if she travels towards the optimal leaf node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the tree as a 2D integer array edges, a starting position bob for Bob, and an array amount where amount[i] gives the cost or reward at node i. The value is negative for a cost and positive for a reward. Alice starts at node 0, and both Alice and Bob move towards their respective destinations in each second.
- **Example:** `edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]`
- **Constraints:**
	- 2 <= n <= 105
	- edges.length == n - 1
	- 0 <= ai, bi < n
	- ai != bi
	- edges represents a valid tree
	- 1 <= bob < n
	- amount[i] is an even integer in the range [-104, 104]

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum net income Alice can have by traveling towards the optimal leaf node.
- **Example:** `For edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, and amount = [-2,4,2,-4,6], the output is 6.`
- **Constraints:**
	- The answer is an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum net income Alice can get while traveling towards the best leaf node.

- Build an adjacency list to represent the tree.
- Use depth-first search (DFS) to determine the distances and parent nodes of all nodes in the tree.
- Simulate Bob's path towards node 0, updating the gates along his path.
- Simulate Alice's path towards the optimal leaf node, while considering Bob's path and any shared gates.
- Return the maximum net income Alice can achieve by following the optimal path.
{{< dots >}}
### Problem Assumptions ✅
- The tree is rooted at node 0, and the game proceeds in discrete steps.
{{< dots >}}
## Examples 🧩
- **Input:** `For edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, and amount = [-2,4,2,-4,6]`  \
  **Explanation:** Alice and Bob start at nodes 0 and 3, respectively. As they move, Alice and Bob both pay or receive rewards as they pass through nodes. The goal is to compute the maximum net income Alice can achieve. In this example, Alice’s optimal path is through nodes 0 -> 1 -> 3 -> 4, where her net income becomes 6.

{{< dots >}}
## Approach 🚀
We use a depth-first search (DFS) to explore the tree and simulate Alice's and Bob's movements. By updating the gates along Bob's path, we can compute the maximum possible net income for Alice.

### Initial Thoughts 💭
- This problem involves simulating the movements of Alice and Bob in a tree structure, with careful handling of shared gates and net income.
- Using DFS to determine paths for both Alice and Bob is a natural approach for solving this problem. The challenge lies in maximizing Alice's net income by considering the rewards and costs along the way.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees valid inputs, so no need to handle empty inputs.
- Ensure that the algorithm handles large inputs efficiently, especially when the number of nodes reaches the upper limit of 100,000.
- If the gates at all nodes are negative, Alice will always end up with a loss, and the solution should return the least negative value.
- The tree must be connected, and the graph structure must not contain cycles.
{{< dots >}}
## Code 💻
```cpp

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

```

The code defines a solution for finding the most profitable path in a tree graph, with recursive DFS (Depth First Search) functions for traversal and path calculations. The `dfs` function calculates distances and parent relationships, while `dfs2` computes the maximum value on the path from root to leaves with certain profit adjustments for a character named Bob.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Graph Initialization**
	```cpp
	vector<vector<int>> adj;
	```
	Here, we declare a 2D vector `adj` to represent the adjacency list of the graph, where each node has a list of connected nodes.

2. **Variable Initialization**
	```cpp
	vector<int> par, dis;
	```
	Two vectors `par` (for parent tracking) and `dis` (for distance tracking) are declared to assist in the traversal of the graph.

3. **DFS Function**
	```cpp
	void dfs(int u, int p = 0, int d = 0) {
	```
	This is the start of the DFS function, where `u` is the current node, `p` is its parent node, and `d` is the current depth or distance.

4. **Distance Update**
	```cpp
	    dis[u] = d;
	```
	The distance for the current node `u` is updated to `d`.

5. **Parent Tracking**
	```cpp
	    par[u] = p;
	```
	The parent of the current node `u` is stored in `par[u]`.

6. **Traversal**
	```cpp
	    for(int v : adj[u]) {
	```
	For each adjacent node `v` of the current node `u`, the algorithm will check whether it is already visited or is its parent.

7. **Edge Case Handling**
	```cpp
	        if (v == p) continue;
	```
	This ensures that the algorithm does not revisit the parent node.

8. **Recursive DFS**
	```cpp
	        dfs(v, u, d +1);
	```
	The DFS function is recursively called for each unvisited adjacent node, with the depth increased by 1.

9. **Recursive Profit Calculation**
	```cpp
	int dfs2(int u,vector<int>&amount,int p= 0){
	```
	The `dfs2` function computes the maximum possible profit starting from node `u`, considering the amount for each node and its children.

10. **Profit Calculation**
	```cpp
	    int ret = amount[u];
	```
	We initialize the return value `ret` with the amount at the current node `u`.

11. **Max Calculation**
	```cpp
	    int mxc = -INT_MAX;
	```
	This initializes `mxc` to track the maximum profit that can be gained from the child nodes.

12. **Traversal**
	```cpp
	    for(int v:adj[u]){
	```
	We iterate through the adjacent nodes of the current node `u`.

13. **Edge Case Handling**
	```cpp
	        if(v!=p){
	```
	We ensure that we do not revisit the parent node.

14. **Recursive Call**
	```cpp
	            mxc= max(mxc,dfs2(v,amount,u));
	```
	We recursively calculate the maximum profit for the child node `v` and update `mxc` with the maximum value.

15. **Leaf Node Check**
	```cpp
			//if the node is leaf we just return its amount
	```
	If the node is a leaf (no further children), we return its amount.

16. **Return Calculation**
	```cpp
	    if(mxc==-INT_MAX)return ret;
	```
	If no valid child is found, the function returns the value of the current node `ret`.

17. **Final Return**
	```cpp
	    else return ret+mxc;
	```
	If a valid child exists, the maximum profit is returned by adding the `ret` value with `mxc`.

18. **Main Function**
	```cpp
	int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
	```
	This function initializes the graph, calls the DFS functions, and computes the most profitable path.

19. **Adjacency List Setup**
	```cpp
	    int n = amount.size();
	    adj.resize(n,vector<int>());
	```
	The adjacency list is set up based on the input edges, and the graph is resized to fit the number of nodes.

20. **Edge Setup**
	```cpp
	    for(auto&e:edges){
	        adj[e[0]].push_back(e[1]);
	        adj[e[1]].push_back(e[0]);
	    }
	```
	The adjacency list is populated with the given edges, ensuring bidirectional connections.

21. **DFS Initialization**
	```cpp
	    par.resize(n);
	    dis.resize(n);
	```
	The `par` and `dis` vectors are resized to fit the number of nodes.

22. **DFS Call**
	```cpp
	    dfs(0);
	```
	The DFS function is called starting from the root node (node 0).

23. **Bob Path Update**
	```cpp
	    int cur = bob;
	    int bob_dis = 0;
	```
	We initialize Bob's current position and distance.

24. **Amount Adjustment**
	```cpp
	    while(cur!=0){
	        if(dis[cur]>bob_dis){
	            amount[cur] = 0;
	        }else if(dis[cur]==bob_dis){
	            amount[cur]/=2;
	        }
	        cur = par[cur];
	        bob_dis++;
	```
	Bob's path is updated, adjusting the amounts based on his distance from the root.

25. **Result Return**
	```cpp
	    return dfs2(0,amount);
	```
	Finally, the function returns the result from `dfs2`, which calculates the most profitable path.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes.
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear with respect to the number of nodes in the tree, as we perform DFS and simulate the movements of Alice and Bob.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the adjacency list, parent and distance arrays, and recursion stack during DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/most-profitable-path-in-a-tree/description/)

---
{{< youtube MCp9k0kKQqc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
