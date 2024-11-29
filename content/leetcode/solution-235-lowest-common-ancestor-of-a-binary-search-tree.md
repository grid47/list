
+++
authors = ["grid47"]
title = "Leetcode 235: Lowest Common Ancestor of a Binary Search Tree"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 235: Lowest Common Ancestor of a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/235.webp"
youtube = "ML6vGnziUaI"
youtube_upload_date="2023-02-11"
youtube_thumbnail="https://i.ytimg.com/vi/ML6vGnziUaI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/235.webp" 
    alt="Two paths glowing brightly as they meet at the lowest common ancestor in a binary search tree."
    caption="Solution to LeetCode 235: Lowest Common Ancestor of a Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a Binary Search Tree (BST), find the lowest common ancestor (LCA) of two given nodes. The lowest common ancestor is the deepest node that is an ancestor of both nodes. An ancestor of a node is a node itself or any node in its path up to the root.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of the binary search tree and two target nodes p and q.
- **Example:** `Input: root = [5, 3, 8, 2, 4, 7, 9], p = 3, q = 4`
- **Constraints:**
	- The number of nodes in the tree is between 2 and 10^5.
	- Node values are unique.
	- The values of p and q are distinct, and both p and q are guaranteed to exist in the tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the node that represents the lowest common ancestor of nodes p and q.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the lowest common ancestor (LCA) in a binary search tree by leveraging the BST property that the left child is smaller and the right child is greater.

- If the current node's value is less than both p and q, move to the right subtree.
- If the current node's value is greater than both p and q, move to the left subtree.
- If one of the nodes is smaller and the other is larger, the current node is the LCA.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary search tree.
- The nodes p and q are distinct and guaranteed to exist in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5, 3, 8, 2, 4, 7, 9], p = 3, q = 4`  \
  **Explanation:** In this tree, the LCA of nodes 3 and 4 is 3 because node 3 is an ancestor of node 4.

- **Input:** `Input: root = [6, 2, 8, 0, 4, 7, 9], p = 2, q = 8`  \
  **Explanation:** In this tree, the LCA of nodes 2 and 8 is 6, as 6 is the ancestor of both 2 and 8.

{{< dots >}}
## Approach 🚀
We can solve this problem efficiently using the properties of the Binary Search Tree. Starting from the root, we compare the values of the nodes p and q with the current node's value and decide whether to move left or right.

### Initial Thoughts 💭
- A Binary Search Tree (BST) allows us to quickly decide whether to move to the left or right subtree based on the node values.
- The problem becomes easier because we know that for any node, all values in its left subtree are smaller, and all values in its right subtree are larger.
- We need to find the first node that satisfies the condition where one of the nodes is smaller and the other is larger, or if one of the nodes is the current node itself.
{{< dots >}}
### Edge Cases 🌐
- The tree will not be empty, as p and q are guaranteed to exist.
- Ensure that the solution efficiently handles trees with up to 10^5 nodes.
- If one of the nodes is the root, it will be the LCA if the other node is its descendant.
- The solution must be efficient, ideally with a time complexity of O(log n) in a balanced BST.
{{< dots >}}
## Code 💻
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    if(root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    return root;
}
```

This function finds the lowest common ancestor of two nodes in a binary search tree (BST). It recursively traverses the tree, comparing node values to determine whether to move to the left or right subtree, and returns the root node when the common ancestor is found.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	```
	Defines the `lowestCommonAncestor` function, which takes the root node of the BST and two target nodes (`p` and `q`) as input and returns the lowest common ancestor.

2. **Left Subtree Check**
	```cpp
	    if(root->val < p->val && root->val < q->val)
	```
	Checks if both target nodes (`p` and `q`) are located in the right subtree of the current node (`root`). If so, the function recursively calls itself on the right child of `root`.

3. **Right Subtree Check**
	```cpp
	        return lowestCommonAncestor(root->right, p, q);
	```
	Recursively calls `lowestCommonAncestor` on the right subtree of `root` if both `p` and `q` are greater than `root`.

4. **Right Subtree Check (Alternative)**
	```cpp
	    if(root->val > p->val && root->val > q->val)
	```
	Checks if both target nodes (`p` and `q`) are located in the left subtree of the current node (`root`). If so, the function recursively calls itself on the left child of `root`.

5. **Left Subtree Check (Alternative)**
	```cpp
	        return lowestCommonAncestor(root->left, p, q);
	```
	Recursively calls `lowestCommonAncestor` on the left subtree of `root` if both `p` and `q` are smaller than `root`.

6. **Ancestor Return**
	```cpp
	    return root;
	```
	Returns `root` when the current node is the lowest common ancestor, meaning one node is in the left subtree and the other is in the right, or one of the nodes is `root` itself.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) in a balanced BST, where n is the number of nodes.
- **Average Case:** O(log n), assuming the tree is balanced.
- **Worst Case:** O(n) in the case of a skewed tree (e.g., a degenerate tree resembling a linked list).

The time complexity depends on the height of the tree, which can be log n for a balanced BST.

### Space Complexity 💾
- **Best Case:** O(1), if we use an iterative approach instead of recursion.
- **Worst Case:** O(h), where h is the height of the tree (due to recursion).

The space complexity is proportional to the height of the tree due to the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/)

---
{{< youtube ML6vGnziUaI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
