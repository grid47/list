
+++
authors = ["grid47"]
title = "Leetcode 2385: Amount of Time for Binary Tree to Be Infected"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2385: Amount of Time for Binary Tree to Be Infected in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lcaz9lw448"
youtube_upload_date="2022-08-21"
youtube_thumbnail="https://i.ytimg.com/vi/3lcaz9lw448/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, vector<int>> mp;
public:
    int amountOfTime(TreeNode* root, int start) {
        graph(root);

        queue<int> q;
        q.push(start);
        unordered_map<int, bool> seen;
        seen[start] = true;
        int timer = 0;
        for(; q.size(); timer++) {
            int n = q.size();
            while(n--) {
                auto node = q.front();
                q.pop();
                for(int i: mp[node]) {
                    if(!seen[i]) {
                        seen[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        
        return timer-1;
    }

    void graph(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            if(parent != -1) {
                mp[parent].push_back(node->val);
                mp[node->val].push_back(parent);
            }
            if(node->left) q.push({node->left, node->val});
            if(node->right) q.push({node->right, node->val});
        }
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine how long it takes for an entire binary tree to be infected, starting from a specific node. The tree nodes represent individuals, and once an individual is infected, it can spread the infection to its neighboring individuals (nodes). We are given a binary tree where each node has a value, and the infection spreads from a starting node to its neighboring nodes in the tree.

You are tasked with returning the amount of time (in terms of number of rounds or steps) it takes for the infection to spread to the entire tree. The infection spreads through the tree such that at each step, all neighboring nodes of infected nodes become infected.

### Approach

To solve this problem, we can transform the binary tree into an **undirected graph** and use a **Breadth-First Search (BFS)** traversal to model the infection spreading process. Here's the step-by-step breakdown of the approach:

1. **Transform the Tree to a Graph**:
   - A binary tree is inherently a tree structure, but to efficiently traverse and simulate the infection spreading process, we will first represent the tree as an undirected graph. Each node in the binary tree will be connected to its neighbors (both its left and right children) in this graph.
   - We'll create an adjacency list to store the tree in graph form. This will allow easy access to a node's neighbors during BFS traversal.

2. **Breadth-First Search (BFS)**:
   - Starting from the given node, we use BFS to simulate the infection spreading. At each level of BFS, the infection spreads to all the neighboring nodes that have not been infected already.
   - We maintain a queue that tracks the nodes to be processed. As we process each node, we add its unvisited neighbors to the queue for the next round.

3. **Track the Number of Rounds**:
   - As we perform the BFS, we keep track of how many rounds it takes for the infection to reach all nodes in the tree. The result will be the number of rounds minus one (because we start counting from the initial infection).

### Code Breakdown (Step by Step)

1. **TreeNode Definition**:
    ```cpp
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    ```
    - The `TreeNode` struct represents a node in the binary tree, with `val` as its value, and `left` and `right` pointers representing the left and right children.

2. **Main Solution Class**:
    ```cpp
    class Solution {
        unordered_map<int, vector<int>> mp;
    public:
        int amountOfTime(TreeNode* root, int start) {
            graph(root);
    
            queue<int> q;
            q.push(start);
            unordered_map<int, bool> seen;
            seen[start] = true;
            int timer = 0;
            for(; q.size(); timer++) {
                int n = q.size();
                while(n--) {
                    auto node = q.front();
                    q.pop();
                    for(int i: mp[node]) {
                        if(!seen[i]) {
                            seen[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
            
            return timer-1;
        }
    ```
    - **graph(root)**: This function is used to convert the binary tree into an undirected graph.
    - **amountOfTime(root, start)**: This function is the main BFS loop that simulates the infection process and calculates the number of rounds it takes for the infection to spread throughout the tree.
    
    The key variables in the method are:
    - `q`: The queue stores the nodes that need to be processed during each round of infection.
    - `seen`: This map tracks whether a node has already been infected or visited.
    - `timer`: This variable tracks how many rounds it takes for the infection to spread to all nodes.
    
3. **Graph Construction**:
    ```cpp
        void graph(TreeNode* root) {
            queue<pair<TreeNode*, int>> q;
            q.push({root, -1});
            while(!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();
                if(parent != -1) {
                    mp[parent].push_back(node->val);
                    mp[node->val].push_back(parent);
                }
                if(node->left) q.push({node->left, node->val});
                if(node->right) q.push({node->right, node->val});
            }
        }
    ```
    - **graph(root)** converts the binary tree into an adjacency list representation of an undirected graph.
    - It uses a **queue** to perform a level-order traversal of the tree, where each node is processed along with its parent node.
    - For each node, it adds an edge between the node and its parent to the adjacency list. If the node has left or right children, they are added to the queue for further processing.
    - The result is an adjacency list (`mp`) where each key is a node value, and the corresponding value is a vector of neighboring node values.

4. **BFS Traversal**:
    ```cpp
            queue<int> q;
            q.push(start);
            unordered_map<int, bool> seen;
            seen[start] = true;
            int timer = 0;
            for(; q.size(); timer++) {
                int n = q.size();
                while(n--) {
                    auto node = q.front();
                    q.pop();
                    for(int i: mp[node]) {
                        if(!seen[i]) {
                            seen[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
    ```
    - The BFS starts with the `start` node, marking it as visited (`seen[start] = true`).
    - At each level (round), the algorithm processes all nodes in the queue. For each node, it checks all its neighbors in the graph. If a neighbor has not been visited, it is added to the queue for processing in the next round.
    - The variable `timer` increments after processing each round, and once all nodes are processed, the function returns `timer - 1`, which gives the number of rounds it took for the infection to spread completely.

### Complexity

1. **Time Complexity**:
    - Constructing the graph takes **O(n)** time, where `n` is the number of nodes in the binary tree.
    - BFS traversal also takes **O(n)** time, as each node is processed exactly once, and we check all its neighbors (which, in the worst case, is constant since each node has at most two neighbors).
    
    Thus, the total time complexity is **O(n)**, where `n` is the number of nodes in the tree.

2. **Space Complexity**:
    - The adjacency list (`mp`) requires **O(n)** space to store the graph representation.
    - The `seen` map and the queue used in BFS also require **O(n)** space.
    
    Therefore, the space complexity is **O(n)**.

### Conclusion

The problem is efficiently solved using the **Breadth-First Search (BFS)** algorithm. By first converting the binary tree into an undirected graph and using BFS to simulate the infection process, we can calculate the number of rounds it takes for the infection to spread to the entire tree. The solution has optimal time and space complexity of **O(n)**, making it suitable for large trees. The BFS approach is well-suited to simulate this type of process, where the infection spreads level by level through the tree's nodes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/)

---
{{< youtube 3lcaz9lw448 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
