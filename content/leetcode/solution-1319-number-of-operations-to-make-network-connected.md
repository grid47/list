
+++
authors = ["grid47"]
title = "Leetcode 1319: Number of Operations to Make Network Connected"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1319: Number of Operations to Make Network Connected in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Depth-First Search","Breadth-First Search","Union Find","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vyXBp3S6-y4"
youtube_upload_date="2023-03-24"
youtube_thumbnail="https://i.ytimg.com/vi/vyXBp3S6-y4/maxresdefault.jpg"
comments = true
+++



---
You are given a network of computers, each labeled from 0 to n-1, and a list of direct connections between these computers. The network is initially connected in some way, but some computers are not directly connected. You can remove cables from existing direct connections and reconnect them between disconnected computers to minimize the number of operations required to make the entire network fully connected. The task is to determine the minimum number of operations needed. If it's not possible to connect all the computers, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parts: the number of computers n, and a list of connections between computers. Each connection is represented as a pair of integers, where each pair [ai, bi] indicates that computer ai is directly connected to computer bi.
- **Example:** `For n = 5 and connections = [[0,1], [0,2], [3,4]], we have a network with 5 computers, and only the first three computers are connected directly.`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= connections.length <= min(n * (n - 1) / 2, 10^5)
	- connections[i].length == 2
	- 0 <= ai, bi < n
	- ai != bi
	- There are no repeated connections.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum number of cable reconfigurations needed to make the entire network connected. If it is impossible, return -1.
- **Example:** `For n = 5, connections = [[0,1], [0,2], [3,4]], the output would be 1, as we can move one cable between disconnected components to connect all the computers.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if all computers can be connected with the given cables, and if so, calculate the minimum number of moves needed to achieve full connectivity.

- 1. Use a union-find (disjoint-set) data structure to track the connected components.
- 2. Iterate through the given connections and join the connected computers.
- 3. Count the number of disconnected components.
- 4. If there are fewer connections than the number of components minus one, return -1 (impossible to connect).
- 5. Otherwise, return the number of reconfigurations required, which is the number of additional cables needed to connect all components.
{{< dots >}}
### Problem Assumptions ✅
- The network may initially have some connected components, and you need to figure out how to connect them all.
- You can freely remove and place cables between disconnected computers.
{{< dots >}}
## Examples 🧩
- **Input:** `For n = 4 and connections = [[0,1], [0,2], [1,2]], the output is 1.`  \
  **Explanation:** There are 4 computers, and the given connections form 3 connected components: {0, 1, 2}, {3}. You need to add one cable to connect computer 3 to the existing network.

- **Input:** `For n = 6 and connections = [[0,1], [0,2], [0,3], [1,2], [1,3]], the output is 2.`  \
  **Explanation:** There are 6 computers, and the given connections form 1 connected component for computers {0, 1, 2, 3}, leaving computers {4, 5} disconnected. You need 2 additional connections to make the network fully connected.

- **Input:** `For n = 6 and connections = [[0,1], [0,2], [0,3], [1,2]], the output is -1.`  \
  **Explanation:** The given connections only form 4 connected computers, leaving 2 disconnected computers. Since there are not enough cables to connect them, it is impossible to connect the entire network.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we'll use the union-find (disjoint-set) data structure to keep track of connected components and determine the number of reconfigurations required.

### Initial Thoughts 💭
- The problem asks us to connect all computers using the minimum number of cable reconfigurations.
- The union-find data structure can help track and merge connected components efficiently.
- We need to check if the number of connections is sufficient to connect all components and count the number of moves needed.
{{< dots >}}
### Edge Cases 🌐
- There should always be valid input values with n >= 1 and at least one connection.
- The solution needs to handle large inputs up to 10^5 efficiently.
- If there are fewer connections than n - 1, it is impossible to connect all computers.
- The constraints ensure that no two computers are connected by more than one cable, and there are no redundant connections.
{{< dots >}}
## Code 💻
```cpp
int makeConnected(int n, vector<vector<int>>& grid) {
    UF* uf = new UF(n);
    for(int i = 0; i < grid.size(); i++)
        uf->uni(grid[i][0], grid[i][1]);
    return grid.size() < n - 1? -1:uf->cnt - 1;
}
```

This function aims to determine the minimum number of operations required to connect all nodes in a graph, represented by a grid of edges. It uses a union-find data structure to merge nodes into connected components and returns the number of operations needed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int makeConnected(int n, vector<vector<int>>& grid) {
	```
	The function 'makeConnected' is declared. It takes an integer 'n' representing the number of nodes and a 2D vector 'grid' representing the edges between nodes.

2. **Union-Find Initialization**
	```cpp
	    UF* uf = new UF(n);
	```
	An instance of the Union-Find (UF) class is created with 'n' nodes. This data structure is used to efficiently track and merge connected components of the graph.

3. **Loop Start**
	```cpp
	    for(int i = 0; i < grid.size(); i++)
	```
	A loop is set up to iterate over all the edges in the 'grid' array. Each edge connects two nodes in the graph.

4. **Union Operation**
	```cpp
	        uf->uni(grid[i][0], grid[i][1]);
	```
	For each edge in the grid, the 'uni' method is called to unify the two nodes connected by the edge. This merges their respective connected components in the Union-Find structure.

5. **Return Statement**
	```cpp
	    return grid.size() < n - 1? -1:uf->cnt - 1;
	```
	The function checks if there are fewer edges than required to connect all nodes (n-1 edges for n nodes). If so, it returns -1 indicating it’s not possible to connect all nodes. Otherwise, it returns the number of connected components minus one.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + m)
- **Average Case:** O(n + m)
- **Worst Case:** O(n + m)

The time complexity is O(n + m), where n is the number of computers and m is the number of connections. Each union/find operation is near constant time (amortized O(α(n))) with path compression and union by rank.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the union-find data structure, where n is the number of computers.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/)

---
{{< youtube vyXBp3S6-y4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
