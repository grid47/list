
+++
authors = ["grid47"]
title = "Leetcode 513: Find Bottom Left Tree Value"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 513: Find Bottom Left Tree Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp"
youtube = "u_by_cTsNJA"
youtube_upload_date="2021-11-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/u_by_cTsNJA/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp" 
    alt="A tree with a glowing bottom-left node, showing the value of the deepest leftmost node in the binary tree."
    caption="Solution to LeetCode 513: Find Bottom Left Tree Value Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = q.front()->val;
        while(!q.empty()) {
            int sz = q.size();
            res = q.front()->val;
            while(sz-- > 0) {
                root = q.front();
                q.pop();
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);                
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the bottom-left value in a binary tree. More specifically, we need to find the leftmost node at the deepest level of the tree. The bottom-left value is the first node encountered when performing a level-order traversal (BFS) from left to right, starting from the deepest level.

### Approach

To solve this problem, we will use a **Breadth-First Search (BFS)** approach, which is typically used to traverse a tree level by level. The BFS approach uses a queue to explore all nodes at a given level before moving on to the next level.

The algorithm follows these key steps:

1. **Initialize a Queue**: A queue is used to store the nodes at each level of the tree. We begin by enqueueing the root node of the tree.
  
2. **Level-order Traversal**: Process the tree level by level. For each level, we store the leftmost node of that level.
  
3. **Update the Result**: Each time we process a new level, we update the result with the value of the leftmost node in the current level. Since the BFS explores the tree from left to right, the first node processed at each level will always be the leftmost node.
  
4. **Termination**: The process continues until all levels of the tree are processed. By the end of the BFS, the result will hold the value of the leftmost node at the deepest level of the tree.

### Code Breakdown (Step by Step)

```cpp
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;      // Initialize a queue to store nodes for BFS
    q.push(root);            // Enqueue the root node
    int res = q.front()->val; // Initialize result with the root's value
    
    while(!q.empty()) {        // Start level-order traversal
        int sz = q.size();     // Get the number of nodes at the current level
        res = q.front()->val;  // The leftmost node at the current level is the first node in the queue
        
        while(sz-- > 0) {      // Process all nodes at the current level
            root = q.front();  // Get the front node from the queue
            q.pop();            // Dequeue the node
            if(root->left)  q.push(root->left);   // Enqueue left child, if exists
            if(root->right) q.push(root->right);  // Enqueue right child, if exists
        }
    }
    return res;                 // Return the leftmost value at the deepest level
}
```

#### Step 1: Initialize a Queue
```cpp
queue<TreeNode*> q;
q.push(root);
```
- A queue `q` is used to store nodes as they are processed in BFS. Initially, the root of the tree is added to the queue.

#### Step 2: Track Leftmost Node
```cpp
int res = q.front()->val;
```
- The variable `res` will store the leftmost node value at the deepest level. Initially, it is set to the value of the root node.

#### Step 3: Process the Tree Level by Level
```cpp
while(!q.empty()) {
    int sz = q.size();
    res = q.front()->val;
    while(sz-- > 0) {
        root = q.front();
        q.pop();
        if(root->left)  q.push(root->left);
        if(root->right) q.push(root->right);
    }
}
```
- We use a `while` loop to process each level of the tree.
- At the start of each level, we update `res` to store the value of the leftmost node at that level (`q.front()->val`).
- We then process each node at the current level. If the node has a left child, it is added to the queue, followed by the right child if it exists.
- This ensures that nodes are processed level by level, and the leftmost node at each level is always processed first.

#### Step 4: Return the Bottom-Left Value
```cpp
return res;
```
- After processing all levels of the tree, the variable `res` will contain the value of the leftmost node at the deepest level of the tree, which is our desired result.

### Complexity

#### Time Complexity:
- **BFS Traversal**: Each node in the tree is processed exactly once, and each operation inside the loop is constant time (O(1)). Therefore, the overall time complexity is `O(N)`, where `N` is the number of nodes in the binary tree.

#### Space Complexity:
- **Queue**: The space complexity is determined by the maximum number of nodes that can be stored in the queue at any given time. In the worst case, this is the number of nodes at the last level of the tree. For a complete binary tree, the maximum number of nodes in the queue will be `O(N / 2)`, which simplifies to `O(N)`.
  
Thus, the space complexity is `O(N)` due to the space needed to store the nodes in the queue.

### Conclusion

In conclusion, the **BFS approach** efficiently solves the problem of finding the bottom-left value in a binary tree. By performing a level-order traversal and always tracking the leftmost node at each level, we ensure that the final result corresponds to the leftmost node at the deepest level of the tree.

This solution has optimal time and space complexity, both of which are linear with respect to the number of nodes in the tree (`O(N)`), making it suitable for large trees.

Key Points:
- **Time Complexity**: `O(N)`
- **Space Complexity**: `O(N)`
- **Approach**: Breadth-First Search (BFS) with a queue

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

---
{{< youtube u_by_cTsNJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
