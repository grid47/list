
+++
authors = ["grid47"]
title = "Leetcode 114: Flatten Binary Tree to Linked List"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 114: Flatten Binary Tree to Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp"
youtube = "rKnD7rLT0lI"
youtube_upload_date="2021-09-16"
youtube_thumbnail="https://i.ytimg.com/vi/rKnD7rLT0lI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/114.webp" 
    alt="A soft tree smoothly transforming into a linear, glowing list of nodes, symbolizing a flattened structure."
    caption="Solution to LeetCode 114: Flatten Binary Tree to Linked List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, flatten the tree into a 'linked list' where each node's right pointer points to the next node in pre-order traversal, and the left pointer of all nodes is null. The 'linked list' should maintain the same order as a pre-order traversal of the binary tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree. The tree is represented as an array of node values, with null indicating missing nodes.
- **Example:** `Input: root = [3, 2, 5, 1, null, null, 6]`
- **Constraints:**
	- The number of nodes in the tree is between 0 and 2000.
	- Node values are between -100 and 100.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the flattened tree represented as a linked list, where each node points to the next node in pre-order traversal, and the left pointer of each node is null.
- **Example:** `Output: [3,null,2,null,1,null,5,null,6]`
- **Constraints:**
	- The right child pointer of each node should point to the next node in pre-order traversal.
	- The left child pointer of each node should be null.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to flatten the binary tree such that it behaves like a linked list, while maintaining the pre-order traversal order.

- Start from the root node and recursively flatten the left subtree.
- Rearrange the tree so that the right child points to the flattened left subtree.
- Set the left child of all nodes to null.
- Repeat the process for the right subtree.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [3,2,5,1,null,null,6]`  \
  **Explanation:** In pre-order traversal, the tree will be visited in this order: 3, 2, 1, 5, 6. The flattened tree should thus look like [3,null,2,null,1,null,5,null,6].

- **Input:** `Input: root = []`  \
  **Explanation:** If the input is an empty tree (root is null), the output should also be an empty list.

{{< dots >}}
## Approach 🚀
We can flatten the binary tree in-place using a depth-first traversal. At each node, we will adjust its right pointer to point to its left child (if any), and then recursively flatten the right subtree.

### Initial Thoughts 💭
- We can achieve this using a recursive depth-first search.
- The solution can be implemented without using extra space by flattening the tree in-place.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty (root is null), the output should be an empty list.
- The solution should efficiently handle large trees, up to 2000 nodes.
- Handle trees where the left and right subtrees are null, as well as trees where all nodes are on the left or right side.
- The tree can have up to 2000 nodes.
{{< dots >}}
## Code 💻
```cpp
void flatten(TreeNode* root) {

    if( root == NULL) return;

    TreeNode* tmp = root->right;
    root->right = root->left;
    root->left = nullptr;

    TreeNode* node = root;
    while(node->right) node = node->right;

    node->right = tmp;
    flatten(root->right); 

}
```

This function transforms a binary tree into a flattened linked list using in-place modifications. The right pointers represent the list structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void flatten(TreeNode* root) {
	```
	Declare the function to flatten the binary tree into a linked list.

2. **Base Case**
	```cpp
	    if( root == NULL) return;
	```
	Handle the base case where the root is null.

3. **Temporary Storage**
	```cpp
	    TreeNode* tmp = root->right;
	```
	Store the original right subtree temporarily.

4. **Pointer Update**
	```cpp
	    root->right = root->left;
	```
	Assign the left subtree to the right pointer.

5. **Pointer Update**
	```cpp
	    root->left = nullptr;
	```
	Set the left pointer to null.

6. **Node Traversal**
	```cpp
	    TreeNode* node = root;
	```
	Initialize a pointer to traverse the right subtree.

7. **Node Traversal**
	```cpp
	    while(node->right) node = node->right;
	```
	Traverse to the last node of the current right subtree.

8. **Pointer Update**
	```cpp
	    node->right = tmp;
	```
	Reconnect the stored right subtree to the end of the current subtree.

9. **Recursive Call**
	```cpp
	    flatten(root->right); 
	```
	Recursively flatten the right subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, each node is visited once, so the time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursion stack. In the worst case (a skewed tree), h can be O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)

---
{{< youtube rKnD7rLT0lI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
