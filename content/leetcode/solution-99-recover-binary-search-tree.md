
+++
authors = ["grid47"]
title = "Leetcode 99: Recover Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 99: Recover Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp"
youtube = "bJBwOMPhe6Y"
youtube_upload_date="2020-10-31"
youtube_thumbnail="https://i.ytimg.com/vi/bJBwOMPhe6Y/sddefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp" 
    alt="A tree softly rearranging its nodes, finding its balance and order."
    caption="Solution to LeetCode 99: Recover Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary search tree (BST), but two nodes in the tree were swapped by mistake. Your task is to recover the tree by swapping the two nodes back, without changing the structure of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of a binary search tree.
- **Example:** `Input: root = [2, 4, 3, 1]`
- **Constraints:**
	- The tree contains between 2 and 1000 nodes.
	- -2^31 <= Node.val <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the binary search tree after recovering the swapped nodes.
- **Example:** `Output: [3, 4, 2, 1]`
- **Constraints:**
	- The function should return the corrected BST.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the two swapped nodes and swap them back to restore the BST's validity.

- Perform an inorder traversal of the tree while keeping track of the previously visited node.
- Identify the two nodes that are out of order during the traversal.
- Once both swapped nodes are found, swap their values to restore the tree.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is a valid BST, except for the two swapped nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [2, 4, 3, 1]`  \
  **Explanation:** In this case, nodes 2 and 4 were swapped, so swapping them back will restore the binary search tree to [3, 4, 2, 1].

- **Input:** `Input: root = [3, 1, 4, null, null, 2]`  \
  **Explanation:** Here, nodes 2 and 3 were swapped. Swapping them back restores the binary search tree to [2, 1, 4, null, null, 3].

{{< dots >}}
## Approach 🚀
To recover the tree, we will perform an inorder traversal of the tree to identify the two nodes that are out of order and swap them back to their correct positions.

### Initial Thoughts 💭
- During an inorder traversal of a valid BST, the nodes should appear in increasing order.
- We need to identify the two nodes that are swapped and restore their positions by swapping their values.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this problem as the tree always contains at least 2 nodes.
- The solution should be efficient enough to handle trees with up to 1000 nodes.
- Ensure that node values are handled correctly even for extreme values such as -2^31 and 2^31 - 1.
- The tree must contain at least 2 nodes, and values must lie within the specified range.
{{< dots >}}
## Code 💻
```cpp
class Solution {
TreeNode *prv = NULL, * fst = NULL , *scd = NULL;
void inorder(TreeNode* node)
{
    if(!node) return;
    inorder(node->left);
    if (prv && node->val < prv->val) {
        if (!fst)  fst = prv;
        scd = node; 
    }
    prv = node;
    inorder(node->right);
}
public:
void recoverTree(TreeNode* node) {
    inorder(node);
    swap(fst->val, scd->val);
}
```

This code fixes a binary search tree (BST) where two nodes' values have been swapped. It uses an in-order traversal to detect and swap the nodes back.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	TreeNode *prv = NULL, * fst = NULL , *scd = NULL;
	```
	Here we declare three pointers: 'prv' (previous node), 'fst' (first wrong node), and 'scd' (second wrong node) to track the swapped nodes.

2. **Function Definition**
	```cpp
	void inorder(TreeNode* node)
	```
	We define the inorder function that will traverse the tree and detect swapped nodes.

3. **Base Case**
	```cpp
	    if(!node) return;
	```
	This is the base case. If the current node is null, we return from the function.

4. **Left Subtree Traversal**
	```cpp
	    inorder(node->left);
	```
	We recursively call the inorder function on the left child of the current node to traverse the left subtree.

5. **BST Violation Check**
	```cpp
	    if (prv && node->val < prv->val) {
	```
	We check if the current node's value is less than the previous node's value, indicating a violation of BST properties.

6. **Identify First Swapped Node**
	```cpp
	        if (!fst)  fst = prv;
	```
	If we haven't found the first swapped node yet, we set 'fst' to the previous node.

7. **Identify Second Swapped Node**
	```cpp
	        scd = node; 
	```
	We set 'scd' to the current node as it is the second wrong node.

8. **Update Previous Node**
	```cpp
	    prv = node;
	```
	We update the 'prv' pointer to the current node for future comparisons.

9. **Right Subtree Traversal**
	```cpp
	    inorder(node->right);
	```
	We recursively call the inorder function on the right child of the current node to continue the traversal.

10. **Tree Recovery Function**
	```cpp
	void recoverTree(TreeNode* node) {
	```
	We define the public method 'recoverTree' that will initiate the inorder traversal to detect swapped nodes.

11. **Recover Swapped Nodes**
	```cpp
	    inorder(node);
	```
	We call the inorder function to detect and set 'fst' and 'scd' as the swapped nodes.

12. **Swap Nodes**
	```cpp
	    swap(fst->val, scd->val);
	```
	We swap the values of the two detected swapped nodes to restore the BST.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree, because we need to traverse all nodes to identify the swapped nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the space complexity is O(n) due to the recursion stack. However, for an iterative approach, the space complexity can be reduced to O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/recover-binary-search-tree/description/)

---
{{< youtube bJBwOMPhe6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
