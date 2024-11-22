
+++
authors = ["grid47"]
title = "Leetcode 814: Binary Tree Pruning"
date = "2024-08-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 814: Binary Tree Pruning in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/814.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/814.webp" 
    alt="A binary tree where branches are pruned, with the pruned branches glowing softly as they are removed."
    caption="Solution to LeetCode 814: Binary Tree Pruning Problem"
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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left = pruneTree(root->left);
        root->right= pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0)
                return NULL;
        return root;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires pruning a binary tree based on certain conditions. Specifically, we are tasked with removing all subtrees that do not contain any `1`s. In the context of this problem, each node in the binary tree contains either a `0` or a `1`. A subtree is pruned if it only contains `0`s, and if a node itself is `0` and it has no children with a `1`, it should be removed. The pruning operation should ensure that only those nodes and subtrees that are necessary for the tree to have a `1` remain.

We are given the root of a binary tree and need to return the root of the pruned tree. If the root itself is pruned, we return `NULL`.

### Approach

This problem can be efficiently solved by using a **Depth First Search (DFS)** approach, combined with **recursion** to traverse the tree and prune the subtrees that do not contain any `1`s.

1. **DFS Traversal**: We start at the root of the binary tree and recursively prune both the left and right subtrees. 
2. **Prune Condition**: After pruning the left and right subtrees, we check whether the current node itself should be pruned. A node is pruned if:
   - It has no left or right child (i.e., both children are `NULL`).
   - The node's value is `0`.
3. **Post-Pruning**: If a node's value is `0` and both its left and right subtrees are `NULL`, the node is pruned (i.e., the function returns `NULL`).
4. **Return Pruned Tree**: If the node does not meet the pruning condition, we return it, either with or without a pruned subtree, depending on the result of the DFS traversal on its left and right children.

This ensures that all unnecessary subtrees are removed, and only those parts of the tree that contribute to the presence of `1` remain.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL) return root;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0)
                return NULL;
        return root;
    }
};
```

1. **Base Case**: 
   ```cpp
   if(root == NULL) return root;
   ```
   - This is the base case for the recursion. If the current node is `NULL` (i.e., it does not exist), we simply return `NULL` because there's nothing to prune.
   
2. **Recursive Calls**:
   ```cpp
   root->left = pruneTree(root->left);
   root->right = pruneTree(root->right);
   ```
   - These two lines recursively prune the left and right subtrees. We make recursive calls on the left and right children of the current node, which means that for each node in the tree, we prune its left and right subtrees first before evaluating whether the node itself should be pruned.
   
3. **Prune the Current Node**:
   ```cpp
   if(!root->left && !root->right && root->val == 0)
       return NULL;
   ```
   - This line checks if the current node itself should be pruned. The node should be pruned if:
     - It has no left or right children (`!root->left && !root->right`), meaning it is a leaf node.
     - Its value is `0` (`root->val == 0`).
   - If both of these conditions are true, we return `NULL`, effectively removing this node from the tree.

4. **Return Pruned Tree**:
   ```cpp
   return root;
   ```
   - If the current node is not pruned, we return it as is. This could be a node that either has a non-null child or contains a `1`. The recursion continues up the tree, ensuring all subtrees are pruned as necessary.

### Complexity

#### Time Complexity:
- The time complexity of this solution is **O(n)**, where `n` is the number of nodes in the binary tree. This is because we visit each node exactly once in a depth-first manner, performing constant time operations for each node (pruning and checking children).

#### Space Complexity:
- The space complexity is **O(h)**, where `h` is the height of the binary tree. This is due to the recursion stack. In the worst case, the height of the tree is equal to the number of nodes, leading to a space complexity of **O(n)**. However, in a balanced tree, the height would be **O(log n)**.

### Conclusion

This solution effectively solves the problem of pruning a binary tree by removing subtrees that do not contain any `1`s, ensuring that only the necessary parts of the tree remain. The use of DFS with recursion ensures that we traverse the tree in an efficient manner, pruning subtrees as we go. The time complexity of **O(n)** and space complexity of **O(h)** make this approach optimal for large trees.

#### Key Points:
- **DFS Traversal**: The algorithm uses depth-first search to traverse and prune the tree.
- **Pruning Logic**: The node is pruned if it’s a leaf node and has a value of `0`.
- **Efficiency**: The algorithm runs in **O(n)** time, where `n` is the number of nodes in the tree, and uses **O(h)** space, where `h` is the height of the tree.

This approach is both efficient and easy to understand, making it suitable for solving the problem of pruning a binary tree in an optimal way.

[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-pruning/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
