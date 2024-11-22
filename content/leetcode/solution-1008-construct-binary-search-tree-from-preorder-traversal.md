
+++
authors = ["grid47"]
title = "Leetcode 1008: Construct Binary Search Tree from Preorder Traversal"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1008: Construct Binary Search Tree from Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Tree","Binary Search Tree","Monotonic Stack","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "30WqiTVp8Kc"
youtube_upload_date="2020-04-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/30WqiTVp8Kc/maxresdefault.webp"
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
    int i = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& pre, int bound = INT_MAX) {
        if(i == pre.size() || pre[i] > bound) return NULL;
        
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = bstFromPreorder(pre, root->val);
        root->right = bstFromPreorder(pre, bound);
        return root;
    }
    
    
};
{{< /highlight >}}
---



### Problem Statement
The task is to construct a binary search tree (BST) from a given preorder traversal of its nodes. In a BST, for any given node:
- The left child must contain a value less than the node's value.
- The right child must contain a value greater than the node's value.

Given a sequence of integers that represent the preorder traversal of a BST, our goal is to reconstruct the tree structure. The preorder traversal is defined as visiting the root node first, followed by the left subtree and then the right subtree. 

### Approach
To solve this problem, we will utilize a recursive approach that exploits the properties of BSTs and the characteristics of preorder traversal. The strategy involves:
1. Iterating through the values in the preorder array while keeping track of the current index.
2. Using a bound to ensure that the values inserted into the left and right subtrees adhere to the BST properties.
3. Recursively constructing the left and right subtrees by calling the same function with updated bounds.

### Code Breakdown (Step by Step)

1. **TreeNode Definition**:
   - The code begins with a definition of the `TreeNode` structure, which contains an integer value (`val`), a pointer to the left child (`left`), and a pointer to the right child (`right`). This structure serves as the building block for our binary search tree.

2. **Solution Class Declaration**:
   - The `Solution` class encapsulates our method for constructing the BST. It maintains a class member variable `i` that tracks the current index in the preorder array as we build the tree.

3. **Function Declaration**:
   - The function `bstFromPreorder` is defined as a public member of the `Solution` class. It takes a vector of integers (`pre`) representing the preorder traversal of the BST and an optional `bound` parameter that defaults to `INT_MAX`.

4. **Base Case**:
   - The function begins by checking two conditions:
     - If `i` equals the size of the preorder array (`pre.size()`), it indicates that we have processed all nodes, and the function returns `NULL`.
     - If the current value `pre[i]` exceeds the provided `bound`, it means that the value cannot be placed in the current subtree (as it violates the BST property). In this case, the function also returns `NULL`.

5. **Creating a New Node**:
   - When both conditions are satisfied, we create a new `TreeNode` with the value `pre[i]`. After creating the node, we increment the index `i` to move to the next element in the preorder array.

6. **Recursive Calls for Subtrees**:
   - The function then recursively constructs the left subtree by calling `bstFromPreorder` with the updated bound set to the value of the current node (`root->val`). This ensures that all values in the left subtree will be less than the current node's value.
   - After the left subtree is constructed, the function constructs the right subtree by calling `bstFromPreorder` with the original bound. This ensures that all values in the right subtree are greater than the current node's value.

7. **Returning the Root**:
   - Finally, after constructing both subtrees, the function returns the root of the newly constructed BST.

### Complexity Analysis
- **Time Complexity**: The time complexity of this function is O(n), where `n` is the number of nodes in the input preorder array. Each node is processed exactly once, leading to a linear runtime.
- **Space Complexity**: The space complexity is O(h), where `h` is the height of the tree. This space is utilized by the call stack due to recursion. In the worst case (for a completely unbalanced tree), the height can be O(n). For a balanced tree, the height would be O(log n).

### Conclusion
The `bstFromPreorder` function provides an efficient and elegant solution for reconstructing a binary search tree from a preorder traversal. By leveraging recursion and the properties of BSTs, the function successfully builds the tree while maintaining the required constraints on node values. 

This approach highlights the utility of recursion in tree construction problems and demonstrates how properties of binary search trees can guide the reconstruction process. Understanding this method is beneficial for solving related problems in data structures and algorithms, especially those involving tree traversal and manipulation.

The implementation also underscores the importance of managing indices and bounds when working with recursive algorithms, allowing for clean and readable code. This technique can be adapted for various tree-related challenges, making it a versatile tool in algorithm design.

In summary, the `bstFromPreorder` function is a valuable contribution to the toolkit of anyone working with binary trees, enabling the efficient reconstruction of BSTs and facilitating further operations such as searching, insertion, and traversal in a structured manner.


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

---
{{< youtube 30WqiTVp8Kc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
