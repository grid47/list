
+++
authors = ["grid47"]
title = "Leetcode 1325: Delete Leaves With a Given Value"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1325: Delete Leaves With a Given Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FqAoYAwbwV8"
youtube_upload_date="2024-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FqAoYAwbwV8/maxresdefault.webp"
comments = true
+++



---
You are given the root of a binary tree and an integer target. Your task is to remove all leaf nodes that have the value equal to the target. Once you remove a leaf node with the target value, if its parent node becomes a leaf node and has the same value, it should also be removed. This process should continue until no more leaf nodes with the target value are present.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the binary tree root represented by a TreeNode object and an integer target. Each node in the binary tree contains a value, left, and right child pointers.
- **Example:** `For root = [1,2,3,2,null,2,4] and target = 2, the tree has nodes with values 1, 2, 3, and 4, and we need to remove all leaf nodes with the value 2.`
- **Constraints:**
	- 1 <= Node.val, target <= 1000
	- The number of nodes in the tree is in the range [1, 3000].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the root of the binary tree after removing all leaf nodes with the target value. The tree should still be valid after removal.
- **Example:** `For root = [1,2,3,2,null,2,4] and target = 2, the output is [1,null,3,null,4], as all the leaf nodes with value 2 are removed.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the binary tree and remove all leaf nodes with the target value. Once a node is removed, check if its parent node becomes a leaf with the target value and remove it as well.

- 1. Traverse the tree recursively.
- 2. At each node, check if it has left or right children.
- 3. If a node is a leaf (both children are null) and its value matches the target, remove it.
- 4. After removing a leaf, check if its parent has become a leaf and has the target value, and repeat the process.
- 5. Return the root of the modified tree.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree.
- The value of target is within the bounds of valid node values.
{{< dots >}}
## Examples 🧩
- **Input:** `For root = [1,2,3,2,null,2,4] and target = 2, the output is [1,null,3,null,4].`  \
  **Explanation:** The leaf nodes with value 2 are removed. After that, the parent nodes 1 and 3 are left as the final tree.

- **Input:** `For root = [1,3,3,3,2] and target = 3, the output is [1,3,null,null,2].`  \
  **Explanation:** Leaf nodes with value 3 are removed and the remaining tree is adjusted accordingly.

- **Input:** `For root = [1,2,null,2,null,2] and target = 2, the output is [1].`  \
  **Explanation:** All leaf nodes with value 2 are removed in a step-by-step manner, leaving only the root node 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we will perform a recursive traversal of the binary tree. At each node, we will check if it is a leaf node with the target value and delete it if necessary. After deleting a node, we will check if its parent becomes a leaf and repeat the process.

### Initial Thoughts 💭
- The problem requires multiple deletions that propagate up the tree, so a recursive approach is ideal.
- We need to perform the deletion and check for any new leaf nodes created at each level of recursion.
{{< dots >}}
### Edge Cases 🌐
- The tree is guaranteed to have at least one node, as the number of nodes is in the range [1, 3000].
- For large trees, ensure that the solution efficiently handles up to 3000 nodes.
- If all leaf nodes have the target value, the entire tree could be reduced to just the root.
- The binary tree must adhere to the constraints on node count and value range.
{{< dots >}}
## Code 💻
```cpp
TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(root->left) root->left = removeLeafNodes(root->left, target);
    if(root->right) root->right = removeLeafNodes(root->right, target);
    return root->left == root->right && root->val == target ? nullptr : root;
}
```

This function recursively removes leaf nodes from a binary tree where the node's value matches the given target. It ensures that leaf nodes that meet the condition are deleted, and the tree structure is adjusted accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
	```
	The function 'removeLeafNodes' is declared, which takes a pointer to the root node of a binary tree and an integer 'target' as its parameters. It returns a pointer to the modified tree.

2. **Left Subtree Recursion**
	```cpp
	    if(root->left) root->left = removeLeafNodes(root->left, target);
	```
	The function checks if the left child of the current node is non-null. If so, it recursively calls itself to remove leaf nodes from the left subtree.

3. **Right Subtree Recursion**
	```cpp
	    if(root->right) root->right = removeLeafNodes(root->right, target);
	```
	Similarly, the function checks if the right child of the current node is non-null. If so, it recursively calls itself to remove leaf nodes from the right subtree.

4. **Leaf Node Removal**
	```cpp
	    return root->left == root->right && root->val == target ? nullptr : root;
	```
	After checking both subtrees, the function determines if the current node is a leaf node (both left and right children are null) and if its value equals the target. If both conditions are true, it returns 'nullptr', effectively removing the node. Otherwise, it returns the current node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we visit each node once, which leads to a time complexity of O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursive stack. In the worst case, the tree could be unbalanced, and the height could be equal to the number of nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/)

---
{{< youtube FqAoYAwbwV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
