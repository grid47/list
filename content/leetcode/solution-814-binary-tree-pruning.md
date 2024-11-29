
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
comments = true
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
You are given the root of a binary tree. Your task is to remove all subtrees in the tree that do not contain at least one node with the value 1. A subtree is defined as the node and all its descendants. Return the modified tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree. The tree is represented as a series of node values in a binary tree structure.
- **Example:** `Input: root = [1,null,0,0,1]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 200.
	- Node values are either 0 or 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the same binary tree where every subtree not containing a 1 has been removed. The returned tree should be in the same binary tree structure.
- **Example:** `Output: [1,null,0,null,1]`
- **Constraints:**
	- The tree should be returned as a binary tree structure.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to prune the binary tree such that every subtree that does not contain a 1 is removed.

- Traverse the tree in a post-order manner (visit left, right, then root).
- If a node's left and right subtrees do not contain any 1s, remove those subtrees.
- If the current node itself has a value of 0 and both subtrees are removed, prune the current node as well.
{{< dots >}}
### Problem Assumptions ✅
- The tree is valid and consists of integers either 0 or 1.
- Each node has at most two children.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,null,0,0,1]`  \
  **Explanation:** After pruning, the tree retains the root node with value 1, and only the right child containing a 1 remains. The left child is pruned because it does not contain any 1s.

{{< dots >}}
## Approach 🚀
The approach is to perform a post-order traversal on the tree. For each node, check its subtrees. If a subtree does not contain any 1s, it is pruned. This is achieved through recursion and modifying the left and right pointers of each node.

### Initial Thoughts 💭
- This problem is a typical tree traversal problem where pruning nodes is based on conditions.
- The pruning should happen in a bottom-up manner, meaning we should first prune the children before making decisions about the parent node.
{{< dots >}}
### Edge Cases 🌐
- A tree with only one node having a value of 0 should return null.
- The solution should efficiently handle trees with up to 200 nodes.
- Consider trees where all nodes have a value of 0 or where every node is a 1.
- Make sure the pruning does not break the tree structure for non-zero subtrees.
{{< dots >}}
## Code 💻
```cpp
TreeNode* pruneTree(TreeNode* root) {
    if(root == NULL) return root;
    root->left = pruneTree(root->left);
    root->right= pruneTree(root->right);
    if(!root->left && !root->right && root->val == 0)
            return NULL;
    return root;
}
```

This function prunes a binary tree by removing nodes that do not contribute to the tree (i.e., nodes that are leaves with a value of 0). It recursively checks both left and right subtrees and prunes accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	TreeNode* pruneTree(TreeNode* root) {
	```
	This is the function definition for pruneTree, which takes a TreeNode pointer (root) as an argument.

2. **Condition**
	```cpp
	    if(root == NULL) return root;
	```
	This checks if the root is NULL (base case). If the root is NULL, it simply returns NULL.

3. **Recursion**
	```cpp
	    root->left = pruneTree(root->left);
	```
	This recursively calls pruneTree on the left child of the current root.

4. **Recursion**
	```cpp
	    root->right= pruneTree(root->right);
	```
	This recursively calls pruneTree on the right child of the current root.

5. **Condition**
	```cpp
	    if(!root->left && !root->right && root->val == 0)
	```
	This checks if the current root node is a leaf node (no left or right child) and its value is 0. If true, it will be pruned (i.e., set to NULL).

6. **Return**
	```cpp
	            return NULL;
	```
	If the current node is a leaf with a value of 0, it is pruned by returning NULL.

7. **Return**
	```cpp
	    return root;
	```
	Returns the current root node after pruning its left and right children if necessary.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of nodes in the tree.
- **Average Case:** O(n) as each node is visited once in the post-order traversal.
- **Worst Case:** O(n) because every node is visited to check its subtrees.

The time complexity is linear, as each node in the tree is processed once.

### Space Complexity 💾
- **Best Case:** O(1) if the tree is a perfect binary tree and recursion is tail optimized.
- **Worst Case:** O(h) where h is the height of the tree due to recursion stack space.

Space complexity depends on the height of the tree due to the recursive calls.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-pruning/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
