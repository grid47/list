
+++
authors = ["grid47"]
title = "Leetcode 1443: Minimum Time to Collect All Apples in a Tree"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1443: Minimum Time to Collect All Apples in a Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Xdt5Z583auM"
youtube_upload_date="2023-01-11"
youtube_thumbnail="https://i.ytimg.com/vi/Xdt5Z583auM/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    map<int, vector<int>> gph;
    map<int, int> visited;
    vector<bool> hasApple;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        this->hasApple = hasApple;
        for(auto x: edges) {
            gph[x[0]].push_back(x[1]);
            gph[x[1]].push_back(x[0]);
        }
        
        return dfs(0, 0);
    }
    
    int dfs(int mycost, int node) {
        if(visited[node]) return 0;
        visited[node] = true;
        int childcost = 0;
        for(int x: gph[node]) {
            childcost += dfs(2, x);
        }
        if(childcost == 0 && hasApple[node] == false)
            return 0;
        
        return childcost + mycost;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the minimum time required to collect all the apples from a tree-like structure represented by a graph. Each node in the graph represents a location (like a branch of a tree), and the edges represent paths between these locations. Some of these locations contain apples, and we want to find out how much time it would take to collect all apples by starting from the root node (node 0). The cost to traverse from one node to another is given as 2 units of time for each edge traversed.

### Approach

To solve this problem, we will use Depth First Search (DFS) to traverse the graph. The steps involved in the solution are:

1. **Graph Construction**: Build an undirected graph using an adjacency list representation from the provided edges.

2. **DFS Traversal**: Use DFS to traverse the graph starting from the root node (node 0). During traversal, accumulate the cost of moving through nodes. 

3. **Apple Collection Logic**: For each node, check if:
   - It has an apple.
   - It has children nodes from which apples can be collected. If a node has no children and does not have an apple, then it does not contribute to the total cost.

4. **Cost Calculation**: Keep track of the total cost incurred to collect all apples while ensuring we only count the cost of edges that lead to nodes with apples.

### Code Breakdown (Step by Step)

Let’s break down the code provided step by step:

1. **Class Declaration**:
   ```cpp
   class Solution {
   ```

   - We define a class named `Solution` which contains the method to calculate the minimum time to collect apples.

2. **Member Variables**:
   ```cpp
   map<int, vector<int>> gph;
   map<int, int> visited;
   vector<bool> hasApple;
   ```

   - We declare a map `gph` to represent the graph as an adjacency list.
   - The `visited` map keeps track of whether a node has been visited during the DFS traversal.
   - The vector `hasApple` stores information about which nodes have apples.

3. **Function Declaration**:
   ```cpp
   int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
   ```

   - The function `minTime` takes three parameters: the number of nodes \(n\), the edges of the graph, and a boolean vector indicating the presence of apples at each node.

4. **Graph Initialization**:
   ```cpp
   this->hasApple = hasApple;
   for(auto x: edges) {
       gph[x[0]].push_back(x[1]);
       gph[x[1]].push_back(x[0]);
   }
   ```

   - We initialize the `hasApple` member variable.
   - We construct the graph from the `edges` list, where each edge connects two nodes bidirectionally.

5. **Calling DFS**:
   ```cpp
   return dfs(0, 0);
   ```

   - We initiate the DFS traversal from the root node (node 0) with an initial cost of 0.

6. **DFS Function**:
   ```cpp
   int dfs(int mycost, int node) {
   ```

   - The `dfs` function is responsible for traversing the graph. It takes two parameters: the current cost to reach a node and the current node.

7. **Base Case Check**:
   ```cpp
   if(visited[node]) return 0;
   visited[node] = true;
   ```

   - If the current node has already been visited, we return 0 to prevent counting the same node multiple times. Otherwise, we mark it as visited.

8. **Child Cost Calculation**:
   ```cpp
   int childcost = 0;
   for(int x: gph[node]) {
       childcost += dfs(2, x);
   }
   ```

   - We initialize a variable `childcost` to track the total cost incurred to collect apples from child nodes.
   - We iterate through all adjacent nodes of the current node and call `dfs` recursively, adding the result to `childcost`. Each traversal to a child node incurs a cost of 2.

9. **Condition for No Apples**:
   ```cpp
   if(childcost == 0 && hasApple[node] == false)
       return 0;
   ```

   - If the cumulative cost from the child nodes is zero and the current node does not have an apple, we return 0, indicating that this node does not contribute to the total time.

10. **Return Total Cost**:
   ```cpp
   return childcost + mycost;
   ```

   - Finally, we return the total cost, which is the sum of the child costs and the cost to reach the current node.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the number of nodes. Each node is visited once during the DFS traversal.

- **Space Complexity**: The space complexity is also \(O(n)\) due to the space used by the adjacency list for the graph representation and the `visited` map.

### Conclusion

This solution effectively calculates the minimum time required to collect all apples from a tree represented as a graph using DFS. By constructing an adjacency list and traversing the graph while checking for apples, we can efficiently accumulate the total cost of traversal.

#### Key Takeaways:

1. **Graph Representation**: Using an adjacency list is a standard way to represent a graph, allowing efficient traversal of nodes.

2. **Depth First Search**: DFS is a powerful algorithm for exploring graphs and can be adapted for various problems, including those involving costs and constraints.

3. **Condition Checking**: Ensuring that we only count the cost of traversing to nodes with apples is crucial to solving the problem optimally.

In summary, the code presented provides a clear and efficient solution to the problem of collecting apples from a graph, making use of fundamental graph traversal techniques and properties of DFS.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/)

---
{{< youtube Xdt5Z583auM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
