
+++
authors = ["grid47"]
title = "Leetcode 236: Lowest Common Ancestor of a Binary Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 236: Lowest Common Ancestor of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/236.webp"
youtube = "gRHnWbKiUIE"
youtube_upload_date="2021-01-23"
youtube_thumbnail="https://i.ytimg.com/vi/gRHnWbKiUIE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/236.webp" 
    alt="Similar to the previous idea, with paths gently intersecting to show the common ancestor in a non-search tree."
    caption="Solution to LeetCode 236: Lowest Common Ancestor of a Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes. The lowest common ancestor is defined as the lowest node that is an ancestor of both nodes p and q. A node can be a descendant of itself.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of the binary tree and two nodes, p and q, whose lowest common ancestor is to be found.
- **Example:** `Input: root = [4, 2, 6, 1, 3, 5, 7], p = 2, q = 6`
- **Constraints:**
	- The number of nodes in the tree is between 2 and 10^5.
	- Node values are unique.
	- Both p and q exist in the tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the node that represents the lowest common ancestor of nodes p and q.
- **Example:** `Output: 4`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the lowest common ancestor (LCA) of nodes p and q in the binary tree using a recursive approach.

- Start from the root node.
- If the current node is null, return null.
- If the current node is equal to either p or q, return that node.
- Recursively search the left and right subtrees for p and q.
- If both left and right subtrees return non-null values, the current node is the LCA.
- If only one of the subtrees returns a non-null value, return that node.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree.
- The nodes p and q are distinct and exist in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [4, 2, 6, 1, 3, 5, 7], p = 2, q = 6`  \
  **Explanation:** In this tree, the LCA of nodes 2 and 6 is 4, as 4 is the ancestor of both nodes.

- **Input:** `Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4`  \
  **Explanation:** In this tree, the LCA of nodes 5 and 4 is 5, as 5 is the ancestor of node 4.

{{< dots >}}
## Approach 🚀
The problem can be solved using a recursive approach to find the lowest common ancestor in a binary tree by checking the presence of nodes p and q in the left and right subtrees.

### Initial Thoughts 💭
- The binary tree structure allows us to search in both the left and right subtrees for the target nodes.
- We can use recursion to traverse the tree and identify the common ancestor.
- The key observation is that the LCA is found where one node is in the left subtree, and the other is in the right subtree, or when one of the nodes is the current node.
{{< dots >}}
### Edge Cases 🌐
- The tree cannot be empty, as both p and q must exist in the tree.
- Ensure that the solution can handle trees with up to 10^5 nodes efficiently.
- If one of the nodes is the root node, the root itself is the LCA if the other node is in its subtree.
- The solution should be efficient and handle the recursion stack well for large inputs.
{{< dots >}}
## Code 💻
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    
    return !left? right: !right? left : root;
}
```

This recursive function finds the lowest common ancestor of two nodes `p` and `q` in a binary tree. It traverses the tree and returns the common ancestor when the nodes are found. The function checks for the base cases first, and then recursively searches in the left and right subtrees.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	```
	Defines the `lowestCommonAncestor` function, which takes the root of the tree and two target nodes (`p` and `q`) as input and returns their lowest common ancestor.

2. **Base Case Check**
	```cpp
	    if(!root || root == p || root == q) return root;
	```
	Checks for the base case: if the root is `null`, or if the root is one of the target nodes (`p` or `q`), then it returns the root as the lowest common ancestor.

3. **Left Subtree Search**
	```cpp
	    TreeNode* left = lowestCommonAncestor(root->left, p, q);
	```
	Recursively calls `lowestCommonAncestor` on the left subtree of the current root. It searches for the common ancestor in the left subtree.

4. **Right Subtree Search**
	```cpp
	    TreeNode* right = lowestCommonAncestor(root->right, p, q);
	```
	Recursively calls `lowestCommonAncestor` on the right subtree of the current root. It searches for the common ancestor in the right subtree.

5. **Return Result**
	```cpp
	    return !left? right: !right? left : root;
	```
	If one of the subtrees is `null`, it returns the non-null subtree (either `left` or `right`). If both subtrees are non-null, it means the current root is the lowest common ancestor, so it returns `root`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for a balanced tree, where n is the number of nodes.
- **Average Case:** O(log n) assuming the tree is balanced.
- **Worst Case:** O(n) for a skewed tree, where n is the number of nodes.

The time complexity is determined by the depth of the tree, which can be log n for a balanced tree or n for a skewed tree.

### Space Complexity 💾
- **Best Case:** O(1) if we use an iterative approach.
- **Worst Case:** O(h), where h is the height of the tree (due to recursion stack).

The space complexity depends on the height of the tree because of the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/)

---
{{< youtube gRHnWbKiUIE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
