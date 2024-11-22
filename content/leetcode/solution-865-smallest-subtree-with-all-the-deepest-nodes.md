
+++
authors = ["grid47"]
title = "Leetcode 865: Smallest Subtree with all the Deepest Nodes"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 865: Smallest Subtree with all the Deepest Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QF7ZBH8mXHE"
youtube_upload_date="2020-04-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QF7ZBH8mXHE/maxresdefault.webp"
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
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return lcadn(root).first;
    }

    pair<TreeNode*, int> lcadn(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto lft = lcadn(root->left);
        auto rht = lcadn(root->right);
        if(lft.second < rht.second) {
            return {rht.first, rht.second + 1};
        } else if (lft.second > rht.second) {
            return {lft.first, lft.second + 1};            
        }
        return {root, lft.second + 1};
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the **smallest subtree** that contains all the deepest nodes in a binary tree. In other words, given a binary tree, you need to determine the node that is the root of the subtree that includes all the deepest nodes (nodes at the maximum depth). The deepest nodes are those at the greatest depth, and the subtree should be the smallest such subtree that includes all of them.

### Problem Explanation

We are given a binary tree, and we need to find a subtree that contains all the deepest nodes. A **subtree** is any node in the tree, along with all of its descendants. A node is considered a **deepest node** if it is at the greatest depth in the tree. 

To solve this problem, we must efficiently traverse the tree, calculate the depth of each node, and identify the deepest nodes. From there, we need to find the **lowest common ancestor** (LCA) of all the deepest nodes. The LCA of a set of nodes in a binary tree is the deepest node that is an ancestor of all of them.

### Approach

To approach this problem, the following steps are undertaken:
1. **Depth Calculation**: For each node, calculate the depth of its left and right subtrees.
2. **Comparison of Depths**: Compare the depths of the left and right subtrees at each node. The node will be part of the answer if the depths of its left and right children are equal and at the maximum depth.
3. **Lowest Common Ancestor (LCA)**: The solution leverages the concept of LCA to identify the smallest subtree that contains all the deepest nodes. The LCA of the deepest nodes is the root of this smallest subtree.

The algorithm involves:
- Recursively calculating the depths of each subtree.
- Tracking the node at each depth level.
- Returning the node that corresponds to the subtree containing all the deepest nodes.

### Code Breakdown (Step by Step)

#### Step 1: Define the Helper Function

The helper function `lcadn` calculates the **lowest common ancestor** (LCA) of the deepest nodes and also returns the depth of the deepest node.

```cpp
pair<TreeNode*, int> lcadn(TreeNode* root) {
    if (root == NULL) return {NULL, 0}; // Base case: if the node is NULL, the depth is 0
```

- We start with the base case: if the current node is `NULL`, it means we've reached a leaf's child, so we return `NULL` as the LCA and `0` as the depth.

#### Step 2: Recursively Calculate the LCA and Depth for Left and Right Subtrees

```cpp
    auto lft = lcadn(root->left);  // Recursively find the LCA and depth of the left subtree
    auto rht = lcadn(root->right); // Recursively find the LCA and depth of the right subtree
```

- We recursively call the helper function `lcadn` on the left and right children of the current node (`root->left` and `root->right`). This will allow us to calculate the LCA and the depth for each subtree.

#### Step 3: Compare the Depths of Left and Right Subtrees

```cpp
    if (lft.second < rht.second) {
        return {rht.first, rht.second + 1}; // If the right subtree is deeper, return the right subtree's LCA
    } else if (lft.second > rht.second) {
        return {lft.first, lft.second + 1}; // If the left subtree is deeper, return the left subtree's LCA
    }
```

- After obtaining the depths of the left and right subtrees, we compare them:
  - If the left subtree is deeper, we return the LCA from the left subtree and its depth.
  - If the right subtree is deeper, we return the LCA from the right subtree and its depth.

#### Step 4: Handle the Case Where Both Subtrees Have the Same Depth

```cpp
    return {root, lft.second + 1}; // If both subtrees have the same depth, the current node is the LCA
}
```

- If both the left and right subtrees have the same depth, it means that the current node is the lowest common ancestor of all the deepest nodes in its subtree.
- We return the current node (`root`) as the LCA and its depth (`lft.second + 1`, which is the depth of the current node).

#### Step 5: The Main Function to Get the Result

```cpp
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    return lcadn(root).first; // Return the LCA of the deepest nodes
}
```

- The main function `subtreeWithAllDeepest` calls the helper function `lcadn` on the root of the binary tree and returns the first element of the pair, which is the LCA of the deepest nodes. This node represents the root of the subtree containing all the deepest nodes.

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the number of nodes in the binary tree.
- The function `lcadn` is called once for each node, and each node is processed a constant number of times (once for left and right children).

#### Space Complexity:
- **O(h)**, where `h` is the height of the binary tree.
- The space complexity is due to the recursive calls on the function stack. In the worst case (unbalanced tree), the height could be equal to the number of nodes, so the space complexity is O(n). For a balanced tree, the height is O(log n), so the space complexity is O(log n).

### Conclusion

This solution efficiently solves the problem of finding the smallest subtree containing all the deepest nodes by utilizing the concept of the **lowest common ancestor (LCA)**. The recursive helper function calculates both the LCA and the depth of the deepest nodes in the tree. By comparing the depths of the left and right subtrees, the algorithm determines the correct subtree that contains all the deepest nodes, while maintaining an optimal time and space complexity. This approach is efficient and leverages the properties of binary trees and LCA to find the solution in a concise manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

---
{{< youtube QF7ZBH8mXHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
