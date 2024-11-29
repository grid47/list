
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
comments = true
+++



---
Given the root of a binary tree, return the smallest subtree that contains all the nodes with the maximum depth in the tree. A node is considered the deepest if it has the greatest distance to the root among all nodes. The subtree of a node consists of the node itself and all its descendants.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree, represented as an array with level-order traversal.
- **Example:** `root = [4,3,5,null,7,6]`
- **Constraints:**
	- The binary tree contains between 1 and 500 nodes.
	- Each node in the tree has a unique value in the range [0, 500].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest subtree that includes all the deepest nodes in the tree, represented by the root of that subtree.
- **Example:** `Output: [7]`
- **Constraints:**
	- The subtree's root must include all nodes at the maximum depth.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the smallest subtree containing all the deepest nodes in the binary tree.

- Traverse the tree to find the maximum depth.
- For each node, recursively determine if its left and right subtrees contain nodes at the maximum depth.
- If both subtrees contain the deepest nodes, return the current node as the root of the subtree.
- If only one subtree contains the deepest nodes, propagate that subtree's root upwards.
{{< dots >}}
### Problem Assumptions ✅
- The tree is non-empty.
- The input is well-formed and represents a valid binary tree.
- All nodes have unique values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [4,3,5,null,7,6], Output: [7]`  \
  **Explanation:** The deepest node is 7. It is the only node at the maximum depth, so it forms the smallest subtree.

- **Input:** `Input: root = [2,4,8,null,null,6,10], Output: [8,6,10]`  \
  **Explanation:** The deepest nodes are 6 and 10. The smallest subtree containing both of them is rooted at node 8.

{{< dots >}}
## Approach 🚀
Use a recursive approach to calculate the depth of each node and find the lowest common ancestor of the deepest nodes.

### Initial Thoughts 💭
- The problem reduces to finding the lowest common ancestor of the deepest nodes.
- Using a recursive depth-first search (DFS), we can propagate depth information upwards.
- The depth information for the left and right children can determine the smallest subtree containing all deepest nodes.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, since the tree is guaranteed to have at least one node.
- Tree with the maximum allowed nodes (500).
- All nodes are at the same depth.
- The tree is a single path (linked list).
- Ensure the tree structure is correctly formed and all nodes are unique.
{{< dots >}}
## Code 💻
```cpp
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
```

This code implements a function to find the subtree that contains all the deepest nodes of a binary tree. The method relies on a helper function `lcadn` that calculates the deepest node and its depth.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
	```
	This is the function signature of `subtreeWithAllDeepest`, which takes the root of a binary tree as input and returns the subtree containing all the deepest nodes.

2. **Return Statement**
	```cpp
	    return lcadn(root).first;
	```
	The function calls `lcadn`, a helper function, on the root node and returns the first element of the pair, which is the subtree containing the deepest nodes.

3. **Helper Function Definition**
	```cpp
	pair<TreeNode*, int> lcadn(TreeNode* root) {
	```
	This is the function signature of `lcadn`, which is a helper function that returns a pair containing the deepest node and its depth.

4. **Base Case**
	```cpp
	    if(root == NULL) return {NULL, 0};
	```
	This is the base case where if the current node is `NULL`, it returns a pair with `NULL` for the node and `0` for the depth.

5. **Left Subtree Recursion**
	```cpp
	    auto lft = lcadn(root->left);
	```
	This line recursively calls `lcadn` on the left child of the current node and stores the result in the variable `lft`.

6. **Right Subtree Recursion**
	```cpp
	    auto rht = lcadn(root->right);
	```
	This line recursively calls `lcadn` on the right child of the current node and stores the result in the variable `rht`.

7. **Depth Comparison**
	```cpp
	    if(lft.second < rht.second) {
	```
	This checks if the depth of the left subtree (`lft.second`) is less than the depth of the right subtree (`rht.second`).

8. **Return Right Subtree**
	```cpp
	        return {rht.first, rht.second + 1};
	```
	If the right subtree is deeper, return the right subtree (`rht.first`) with its depth incremented by 1.

9. **Else Condition**
	```cpp
	    } else if (lft.second > rht.second) {
	```
	This checks if the depth of the left subtree (`lft.second`) is greater than the depth of the right subtree (`rht.second`).

10. **Return Left Subtree**
	```cpp
	        return {lft.first, lft.second + 1};
	```
	If the left subtree is deeper, return the left subtree (`lft.first`) with its depth incremented by 1.

11. **Equal Depths Return**
	```cpp
	    return {root, lft.second + 1};
	```
	If both subtrees are of equal depth, return the current node (`root`) as the subtree containing all the deepest nodes, with its depth incremented by 1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of nodes in the tree.
- **Average Case:** O(N), since each node is visited once.
- **Worst Case:** O(N), if the tree is skewed or has maximum depth.

Each node is visited once during the DFS traversal.

### Space Complexity 💾
- **Best Case:** O(1), if the tree height is minimal (single node).
- **Worst Case:** O(H), where H is the height of the tree (due to recursive stack).

Space complexity depends on the recursion depth, which is equal to the tree height.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/)

---
{{< youtube QF7ZBH8mXHE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
