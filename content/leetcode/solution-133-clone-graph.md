
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
**Code:**

{{< highlight cpp >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
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
};
{{< /highlight >}}
---

### 📝 **Problem Statement**

The problem asks us to **clone a graph**, where each node has an integer value and a list of neighbors (edges). The goal is to create a **deep copy** (or clone) of the graph, ensuring that each node's value is preserved, and all edges are correctly replicated.

We are provided with a graph where each node is represented by a `Node` class, and the graph can contain cycles. The task is to construct an identical graph where each node is a new instance, and no references point to the original nodes.

---

### 💡 **Approach**

To solve the problem of cloning a graph, we need to ensure:
1. Each node's value is copied correctly.
2. The edges (connections to neighbors) are also replicated, but without referencing the original nodes.
3. We handle cycles properly by avoiding revisiting nodes and preventing infinite recursion.

We'll use a **depth-first search (DFS)** approach to traverse and clone each node. A **map** (or dictionary) will track which nodes have already been cloned to prevent revisiting and infinite recursion.

---

### 🔨 **Code Breakdown (Step by Step)**

#### 1️⃣ **Node Class Definition**
We begin by defining the `Node` class, which represents each node in the graph. Each node contains:
- `val`: The value of the node.
- `neighbors`: A list of adjacent nodes (neighbors).

The constructors allow creating nodes with default or specified values and neighbors.

```cpp
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
```

---

#### 2️⃣ **Main Solution Class**
The main `Solution` class contains the method `cloneGraph`, which is responsible for cloning the graph.

```cpp
class Solution {
public:
    map<int, Node*> mp; // Maps node value to its cloned node
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;  // Handle the edge case where the node is NULL
        Node * ans;
        ans = copy(node);  // Start the graph cloning process by calling the copy function
        return ans;  // Return the cloned graph
    }
};
```

- **cloneGraph Function**:
  - Accepts a pointer to a node (`Node* node`).
  - If the node is `NULL`, it directly returns `NULL`.
  - Calls the helper method `copy(node)` to initiate the cloning process and returns the root of the cloned graph.

---

#### 3️⃣ **Recursive Copy Function**
The recursive `copy` function is responsible for copying each node and its neighbors.

```cpp
Node* copy(Node* node) {
    if(mp.count(node->val)) return mp[node->val];  // Return the already cloned node if it exists in the map
    Node* ans = new Node(node->val);  // Create a new node for the clone
    mp[node->val] = ans;  // Store the cloned node in the map using its value as the key
    for(auto it: node->neighbors) {  // Recursively clone each neighbor of the current node
        Node* n = copy(it);  // Call copy for each neighbor
        ans->neighbors.push_back(n);  // Add the cloned neighbor to the current node's neighbors list
    }
    return ans;  // Return the cloned node
}
```

- **Base Case**: 
  - If the node has already been cloned (exists in the `mp` map), return the cloned node to avoid infinite recursion.
  
- **Cloning the Node**: 
  - If the node hasn't been cloned, create a new node with the same value as the original node.
  - Store the cloned node in the map (`mp`) using its value as the key.
  
- **Recursively Cloning Neighbors**:
  - For each neighbor, recursively call `copy` to clone them.
  - Add the cloned neighbor to the current node’s neighbors list.

- **Return the Cloned Node**: 
  - After cloning the node and its neighbors, return the cloned node.

---

### ⏱️ **Complexity Analysis**

#### 🧮 **Time Complexity**:
- **Time to Clone Each Node**: Each node is visited once, and for each node, we examine all of its neighbors.
- **Time to Clone Each Neighbor**: Recursion is called for each neighbor.
- Overall, the time complexity is **O(V + E)**, where `V` is the number of nodes and `E` is the number of edges. Each node and edge is processed at most once.

#### 💾 **Space Complexity**:
- **Map for Cloned Nodes**: The `map<int, Node*>` stores each node’s value and its corresponding cloned node. This requires **O(V)** space.
- **Recursive Call Stack**: The recursive calls on the graph nodes can lead to a call stack depth of **O(V)** in the worst case (for graphs that are essentially long chains).
- Thus, the overall space complexity is **O(V)**.

---

### ✅ **Conclusion**

This solution efficiently clones an undirected graph using a **depth-first search (DFS)** approach with recursion. The `map` ensures that each node is cloned only once, and the graph's structure is correctly preserved. The solution handles cycles effectively by avoiding revisiting already cloned nodes. The time complexity is linear in terms of the number of nodes and edges, making this approach suitable for large graphs.

This method can be adapted for other graph-related problems that involve creating deep copies or performing graph traversals. The use of recursion and mapping nodes ensures that the cloned graph is a valid copy with the correct structure and no infinite loops.

--- 

[`Link to LeetCode Lab`](https://leetcode.com/problems/clone-graph/description/)

---
{{< youtube mQeF6bN8hMk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
