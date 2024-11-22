
+++
authors = ["grid47"]
title = "Leetcode 919: Complete Binary Tree Inserter"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 919: Complete Binary Tree Inserter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Design","Binary Tree"]
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
class CBTInserter {
    vector<TreeNode*> tree;
public:
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i]->left) tree.push_back(tree[i]->left);
            if(tree[i]->right) tree.push_back(tree[i]->right);
        }
    }
    
    int insert(int val) {
        int N = tree.size();
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if(N%2) tree[(N-1)/2]->left = node;
        else    tree[(N-1)/2]->right= node;
        return tree[(N-1)/2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
{{< /highlight >}}
---

### Problem Statement

The goal of this problem is to design a data structure that supports the insertion of nodes in a **Complete Binary Tree (CBT)**. In a complete binary tree, all levels are completely filled except possibly the last level, which is filled from left to right. The data structure should provide methods to:
1. Insert a new node in the tree such that the resulting tree remains a complete binary tree.
2. Return the root node of the complete binary tree.

### Approach

This solution uses an array (vector) to store and represent the complete binary tree (CBT). We leverage the properties of an array representation of binary trees, where:
- For any node at index `i`, its left child is located at index `2*i + 1` and its right child at index `2*i + 2`.
- Using a vector to store nodes helps us achieve an efficient level-order traversal and insertion in the CBT.

Here's a breakdown of how this approach works:

1. **Tree Initialization in CBTInserter Constructor**:
   - When a `CBTInserter` object is created with a given tree root, the constructor performs a level-order traversal of the tree. It stores the nodes in a vector `tree`, which allows us to access any node directly by index.
   - By using level-order traversal, the constructor ensures that nodes in `tree` are stored from top to bottom, left to right, thus aligning with the properties of a CBT.

2. **Insert Method**:
   - To insert a new value, we create a new node with that value.
   - The index of the new node is `N`, where `N` is the current size of the `tree` vector.
   - We determine the parent of this new node by its index:
     - If `N` is odd, the new node is the left child of the parent at index `(N - 1) / 2`.
     - If `N` is even, the new node is the right child of the parent at index `(N - 1) / 2`.
   - Finally, we return the value of the parent node after inserting the new node.

3. **Get Root Method**:
   - This method simply returns the root of the tree, which is the first element in the `tree` vector.

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
   - This structure defines a binary tree node with a value (`val`) and pointers to left and right children.

2. **CBTInserter Class Declaration**:
   ```cpp
   class CBTInserter {
       vector<TreeNode*> tree;
   ```
   - We declare a vector `tree` to store the nodes in level-order.

3. **CBTInserter Constructor**:
   ```cpp
   CBTInserter(TreeNode* root) {
       tree.push_back(root);
       for(int i = 0; i < tree.size(); i++) {
           if(tree[i]->left) tree.push_back(tree[i]->left);
           if(tree[i]->right) tree.push_back(tree[i]->right);
       }
   }
   ```
   - The constructor initializes the `tree` vector by adding the `root` node and performing level-order traversal to add all nodes to `tree` in the required order.

4. **Insert Method**:
   ```cpp
   int insert(int val) {
       int N = tree.size();
       TreeNode* node = new TreeNode(val);
       tree.push_back(node);
       if(N % 2) tree[(N - 1) / 2]->left = node;
       else      tree[(N - 1) / 2]->right = node;
       return tree[(N - 1) / 2]->val;
   }
   ```
   - We add the new node with value `val` to `tree` and determine its parent based on its index.
   - If the index is odd, the new node becomes the left child; if even, it becomes the right child.
   - The method returns the value of the parent node of the inserted node.

5. **Get Root Method**:
   ```cpp
   TreeNode* get_root() {
       return tree[0];
   }
   ```
   - This method simply returns the root node of the CBT, which is the first element in `tree`.

### Complexity

1. **Time Complexity**:
   - **Insertion**: The `insert` method runs in constant time, **O(1)**, because accessing and inserting elements at the end of the vector takes constant time.
   - **Get Root**: This operation is also **O(1)** because it involves accessing the first element of the vector.

2. **Space Complexity**:
   - The space complexity is **O(n)**, where `n` is the number of nodes in the tree. This is because we store a reference to each node in the `tree` vector.

### Conclusion

This solution efficiently manages insertions and retrievals of the root node for a complete binary tree. By using an array-based structure, it leverages the properties of CBTs to ensure that each insertion is quick and the tree remains complete. The approach is space-efficient and ideal for use cases where frequent insertions are required. This implementation is straightforward, minimizing complexity and achieving O(1) insertion time, making it suitable for dynamic CBT operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/complete-binary-tree-inserter/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
