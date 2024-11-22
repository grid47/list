
+++
authors = ["grid47"]
title = "Leetcode 889: Construct Binary Tree from Preorder and Postorder Traversal"
date = "2024-08-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 889: Construct Binary Tree from Preorder and Postorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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
    int preIdx = 0, postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        if(root->val  != postorder[postIdx])
            root->left = constructFromPrePost(preorder, postorder);

        if(root->val  != postorder[postIdx])
            root->right = constructFromPrePost(preorder, postorder);

        postIdx++;
        return root;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to reconstruct a binary tree from two traversal sequences: **preorder** and **postorder**. Given two arrays `preorder` and `postorder`, the task is to construct the binary tree. The tree nodes are represented by a structure `TreeNode` that contains a `val` (node value), a `left` pointer to the left child, and a `right` pointer to the right child.

- **Preorder Traversal**: A type of depth-first traversal where the root node is visited first, followed by the left subtree, and then the right subtree.
  
- **Postorder Traversal**: A type of depth-first traversal where the left subtree is visited first, followed by the right subtree, and then the root node.

Given these two traversal sequences, the objective is to reconstruct the binary tree uniquely. The challenge lies in leveraging both traversals to efficiently reconstruct the tree structure.

### Approach

The approach used to solve this problem revolves around recursive tree construction using the **preorder** and **postorder** traversals. The key observations for solving the problem are:
1. **Preorder traversal** gives the root of the tree (or subtrees) first.
2. **Postorder traversal** gives the root of the tree (or subtrees) last.

#### Steps:
1. **First Step (Preorder root)**: From the **preorder** traversal, the first element corresponds to the root of the current subtree (or the entire tree if we are starting from the root).
2. **Recursive Subtrees**: After identifying the root node, we recursively build the left and right subtrees by identifying the respective elements in the **preorder** and **postorder** arrays.
3. **Postorder Consistency**: In **postorder** traversal, the root of a subtree is always the last element. As we build the left and right subtrees recursively, we ensure that the subtrees' root nodes are correctly matched by the postorder traversal.

The solution is designed to traverse both arrays (preorder and postorder) and build the binary tree recursively while maintaining consistency between the two traversal sequences.

### Code Breakdown (Step by Step)

1. **TreeNode Structure**:
   The `TreeNode` struct represents the binary tree node and is defined as follows:
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
   The `TreeNode` contains:
   - `val`: The integer value of the node.
   - `left`: A pointer to the left child node.
   - `right`: A pointer to the right child node.

2. **Recursive Tree Construction**:
   ```cpp
   TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       TreeNode* root = new TreeNode(preorder[preIdx++]);  // Step 1: Get the root node
   ```
   - A new root node is created using the first element from the `preorder` array (i.e., the current root).
   - We increment the `preIdx` to move to the next element in the `preorder` array for subsequent recursive calls.

3. **Constructing Left Subtree**:
   ```cpp
   if(root->val != postorder[postIdx])  // Ensure left subtree exists
       root->left = constructFromPrePost(preorder, postorder);
   ```
   - The condition checks if the value of the current root node (from `preorder`) is not equal to the current value in `postorder` (tracked by `postIdx`). If this is true, the left subtree exists, and we proceed to recursively construct it.

4. **Constructing Right Subtree**:
   ```cpp
   if(root->val != postorder[postIdx])  // Ensure right subtree exists
       root->right = constructFromPrePost(preorder, postorder);
   ```
   - Similarly, if the root node value is not equal to the current value in `postorder`, we recursively construct the right subtree.

5. **Postorder Completion**:
   ```cpp
   postIdx++;  // Move to the next postorder element
   return root;  // Return the constructed root node
   ```
   - After constructing both subtrees (left and right), we increment `postIdx` to track the next element in the `postorder` traversal and return the constructed tree.

6. **Global Indices**:
   - The indices `preIdx` and `postIdx` are used to keep track of the current position in the `preorder` and `postorder` arrays. These indices are global to ensure that the recursive calls can access and update them properly.

### Complexity

#### Time Complexity:
- The solution performs a single pass over both `preorder` and `postorder` arrays, with each element being processed exactly once. For each recursive call, we update the indices and create nodes. Thus, the time complexity is **O(N)**, where `N` is the number of nodes in the tree (which is also the length of the `preorder` or `postorder` array).

#### Space Complexity:
- The space complexity is **O(N)** due to the recursion stack and the space required to store the binary tree. We use additional space to store the tree nodes (`N` nodes in total), and the recursion stack depth can also go up to `N` in the worst case (if the tree is skewed).

### Conclusion

This solution efficiently reconstructs a binary tree from the given **preorder** and **postorder** traversals using a recursive approach. The key to solving this problem is the relationship between the root and the order of nodes in the two traversal sequences. By keeping track of the current root in **preorder** and ensuring consistency with the last element in **postorder**, the binary tree is reconstructed step by step.

The solution is optimal in both time and space, with a linear time complexity of **O(N)**, making it suitable for large input sizes. This approach ensures that the tree is reconstructed correctly and efficiently, leveraging both the **preorder** and **postorder** traversal properties.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
