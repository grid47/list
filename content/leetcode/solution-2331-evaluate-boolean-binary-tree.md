
+++
authors = ["grid47"]
title = "Leetcode 2331: Evaluate Boolean Binary Tree"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2331: Evaluate Boolean Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9a_cP54jn8Q"
youtube_upload_date="2024-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/9a_cP54jn8Q/maxresdefault.jpg"
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
    bool evaluateTree(TreeNode* root) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val;
        
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
      else

return evaluateTree(root->left) && evaluateTree(root->right);        
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to evaluate a binary tree that represents a logical expression. Each node of the tree can either be a leaf node or an internal node. The leaf nodes have values of either `0` or `1`, representing logical `false` and `true`, respectively. The internal nodes represent logical operators:

- A node with a value of `2` represents the logical OR operation (`||`).
- A node with a value of `3` represents the logical AND operation (`&&`).

Given a binary tree with these properties, the goal is to evaluate the tree and return the final result (`true` or `false`) based on the logical expressions formed by traversing the tree.

### Approach

To solve this problem, we can perform a **recursive traversal** of the tree. The traversal will evaluate the logical expression represented by the binary tree. We need to process each node according to its value:

1. **Leaf Nodes**: If a node is a leaf (it has no left or right child), its value directly determines the result. If the value is `1`, it means `true`, and if it is `0`, it means `false`.
   
2. **Internal Nodes (OR and AND operations)**: For internal nodes, the value determines the type of logical operation:
   - If the node’s value is `2`, it represents an OR operation (`||`). The result is `true` if either the left or the right child evaluates to `true`.
   - If the node’s value is `3`, it represents an AND operation (`&&`). The result is `true` only if both the left and right children evaluate to `true`.

The algorithm recursively computes the result of the subtrees, applying the corresponding logical operation at each internal node, and finally returns the result at the root.

### Code Breakdown (Step by Step)

#### Step 1: Function Definition

```cpp
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
```
- The `evaluateTree` function takes the root of a binary tree as input. The result is a boolean value indicating whether the logical expression represented by the tree evaluates to `true` or `false`.

#### Step 2: Base Case: Null Node

```cpp
        if(!root) return false;
```
- The first check handles the base case where the tree node is null. This could be a safeguard, though in a well-formed binary tree, the root node should never be null when the tree is given as input. If we encounter a null node, we return `false` as an indicator of an invalid or non-existent node.

#### Step 3: Leaf Node Check

```cpp
        if(!root->left && !root->right) return root->val;
```
- The next step checks if the current node is a leaf node, which means it has no left or right child. A leaf node’s value will either be `0` or `1`, representing logical `false` or `true`, respectively. Therefore, we return the value of the node as the result.

#### Step 4: Internal Node Handling (OR and AND operations)

```cpp
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
      else
            return evaluateTree(root->left) && evaluateTree(root->right);
```
- For internal nodes:
  - If the node's value is `2`, it represents the logical OR (`||`) operation. We recursively evaluate both the left and right subtrees and return `true` if either subtree evaluates to `true`.
  - If the node’s value is `3`, it represents the logical AND (`&&`) operation. We recursively evaluate both the left and right subtrees and return `true` only if both subtrees evaluate to `true`.

The `evaluateTree` function is called recursively on the left and right subtrees, and the logical operation is applied based on the current node's value.

#### Step 5: Final Return Value

```cpp
    }
};
```
- Once the recursive calls finish, the function returns the final boolean result for the logical expression rooted at the given node. The recursive calls propagate back up to the root, and the final result is returned to the caller.

### Complexity

#### Time Complexity:
The time complexity of the algorithm is **O(N)**, where `N` is the number of nodes in the binary tree. This is because we visit each node exactly once during the recursive traversal. Each recursive call processes a node and its children, and since there are `N` nodes, the total time complexity is linear in terms of the number of nodes.

#### Space Complexity:
The space complexity is **O(H)**, where `H` is the height of the binary tree. This is the space required for the recursion stack. In the worst case, the height of the tree is `N` (if the tree is skewed), and the space complexity would be `O(N)`. However, for a balanced tree, the height would be `log(N)`, resulting in a space complexity of `O(log(N))`.

### Conclusion

This solution uses a simple recursive approach to evaluate the logical expression represented by a binary tree. Each node in the tree represents either a logical value (`0` or `1`) or a logical operation (`OR` or `AND`). The recursive traversal computes the result by evaluating subtrees and applying the appropriate logical operations at each internal node.

- **Time Complexity**: The algorithm runs in linear time, i.e., **O(N)**, where `N` is the number of nodes in the tree.
- **Space Complexity**: The space complexity is proportional to the height of the tree, i.e., **O(H)**, where `H` is the height of the tree.

This approach is efficient and easy to implement, making it a suitable solution for evaluating logical expressions represented by binary trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-boolean-binary-tree/description/)

---
{{< youtube 9a_cP54jn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
