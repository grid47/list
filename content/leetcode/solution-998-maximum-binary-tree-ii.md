
+++
authors = ["grid47"]
title = "Leetcode 998: Maximum Binary Tree II"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 998: Maximum Binary Tree II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9Mr8YfV6hA4"
youtube_upload_date="2024-01-21"
youtube_thumbnail="https://i.ytimg.com/vi/9Mr8YfV6hA4/maxresdefault.jpg"
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root != NULL && root->val > val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given the root of a **maximum binary tree** and a value `val`. The task is to **insert** the given value into the binary tree such that the resulting tree is still a valid **maximum binary tree**.

A **maximum binary tree** is defined as follows:
1. The root is the maximum value in the tree.
2. The left subtree is a maximum binary tree of all the values smaller than the root.
3. The right subtree is a maximum binary tree of all the values greater than the root.

### Problem Understanding

Given the structure of a maximum binary tree, if you are asked to insert a new value `val`, you need to ensure that:
- The new value is inserted while maintaining the max-heap-like property of the binary tree.
- The tree should remain balanced such that the new value `val` becomes the new root if it is greater than the current root. Otherwise, it should be placed as the right child of the tree's root or somewhere further down.

### Approach

The key insight to solving this problem is to recognize how the **maximum binary tree structure** behaves:
- If the value `val` is larger than the current root, it should become the new root, and the original tree becomes its left subtree.
- If `val` is smaller than the current root, the insertion process should proceed recursively down the right child of the tree.

This leads us to the following steps for solving the problem:
1. If the value `val` is greater than the current node's value, `val` should become the new root, and the current tree becomes its left subtree.
2. Otherwise, if `val` is smaller, recursively move to the right subtree to continue the insertion process, since the right subtree of any node in a max-heap should contain values that are smaller than the node itself.

This recursive approach ensures that we insert the new value into the tree while preserving the properties of the maximum binary tree.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
```

- **Function Definition**: The function `insertIntoMaxTree` is defined as a member function of the `Solution` class, which takes the root of the binary tree and the value `val` to be inserted as arguments. It returns a pointer to the root of the modified binary tree.

```cpp
        if(root != NULL && root->val > val) {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
```

- **Base Case and Recursive Call**:
  - If the current node `root` is not `NULL` and its value is greater than the value `val` to be inserted, the following happens:
    - We proceed to insert `val` in the right subtree of the current node. This is done by making a recursive call `insertIntoMaxTree(root->right, val)`.
    - After the recursive call, the right child of the current node will be updated with the result of the insertion. This keeps the tree structure intact.
    - The current node is then returned as the root of the modified subtree.
  - This step ensures that the value `val` is inserted into the right subtree of nodes where `val` is smaller than the node's value.

```cpp
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }
};
```

- **Insertion Case**:
  - If the current node `root` is either `NULL` or its value is smaller than `val`, then `val` becomes the new root of the tree.
  - A new node is created with the value `val`, and the original root is set as the left child of this new node. This is because, in the max binary tree, any node larger than its parent should become the new root, and the old root becomes its left child.
  - Finally, the new node is returned, which will be the new root of the tree or subtree.
  
This process of recursive insertion guarantees that the tree will remain a valid maximum binary tree after the insertion.

### Complexity

- **Time Complexity**: The time complexity of the solution is **O(h)**, where `h` is the height of the binary tree. In the worst case, we may need to traverse from the root to a leaf, which requires visiting every node along the path. Since the tree is a binary tree, the height is logarithmic in the best case (`O(log n)` for balanced trees) but can be linear (`O(n)`) in the worst case if the tree is skewed.
  
- **Space Complexity**: The space complexity is **O(h)**, which is the space required for the recursion stack. In the worst case, if the tree is skewed, the height of the tree is `O(n)`, and thus the recursion stack will also require `O(n)` space. In the best case (balanced tree), the recursion depth is `O(log n)`.

### Conclusion

This solution provides a simple yet efficient method for inserting a new value into a maximum binary tree. The recursive approach ensures that the properties of the tree are maintained, with the new value becoming the root if it is larger than the current root, and otherwise being inserted into the right subtree. By leveraging the natural structure of the maximum binary tree, this approach works efficiently even with large trees.

The time complexity is proportional to the height of the tree, and the space complexity depends on the recursion depth. The solution is both time-efficient and space-efficient for the given problem constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-binary-tree-ii/description/)

---
{{< youtube 9Mr8YfV6hA4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
