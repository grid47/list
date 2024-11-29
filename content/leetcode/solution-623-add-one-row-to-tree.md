
+++
authors = ["grid47"]
title = "Leetcode 623: Add One Row to Tree"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 623: Add One Row to Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/623.webp" 
    alt="A binary tree where a new row is being added, with the new row glowing as it is inserted."
    caption="Solution to LeetCode 623: Add One Row to Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree, and two integers val and depth. You need to add a row of nodes with value val at the given depth depth. The root node is considered to be at depth 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You will be given the root of a binary tree, along with the value val to be inserted at the given depth.
- **Example:** `root = [5,3,8,2,4,7,9], val = 10, depth = 2`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^4].
	- The depth of the tree is in the range [1, 10^4].
	- -100 <= Node.val <= 100.
	- -10^5 <= val <= 10^5.
	- 1 <= depth <= the depth of tree + 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the binary tree after adding the row at the specified depth.
- **Example:** `[5,10,10,3,8,2,4,7,9]`
- **Constraints:**
	- Return the modified tree structure after adding the row.

{{< dots >}}
### Core Logic 🔍
**Goal:** Insert nodes at the specified depth, ensuring that the left and right subtrees are properly connected.

- If depth == 1, create a new root node with value val, and make the original tree its left child.
- If depth > 1, traverse the tree to the parent nodes at depth-1 and insert new nodes with value val as their left and right children.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is well-formed and follows binary tree structure.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1,2,3,4,5], val = 6, depth = 3`  \
  **Explanation:** At depth 3, nodes with value `6` are inserted as the left and right children of the node `2`. The original left and right subtrees of `2` are attached to the new nodes.

{{< dots >}}
## Approach 🚀
We recursively traverse the tree, inserting new nodes at the specified depth, adjusting the tree structure accordingly.

### Initial Thoughts 💭
- The depth of the tree and the number of nodes can vary significantly.
- The solution requires efficient tree traversal and insertion at the specified depth.
{{< dots >}}
### Edge Cases 🌐
- An empty tree should be handled by directly returning the new root node.
- Ensure the algorithm handles large trees efficiently.
- When depth is 1, the new node becomes the root of the tree.
- The solution must handle up to 10^4 nodes and depths efficiently.
{{< dots >}}
## Code 💻
```cpp
TreeNode* addOneRow(TreeNode* root, int val, int d) {
    if (d == 1) {
        TreeNode* newroot = new TreeNode(val);
        newroot->left = root;
        return newroot;
    }
    if (d == 0) {
        TreeNode* newroot = new TreeNode(val);
        newroot->right = root;
        return newroot;
    }

    if(!root) return nullptr;
    else if(d == 2) {
        root->left  = addOneRow(root->left, val, 1);
        root->right = addOneRow(root->right, val, 0);            
        return root;
    } else if(d > 2) {
        root->left  = addOneRow(root->left, val, d - 1);
        root->right = addOneRow(root->right, val,d - 1);            
    }
    return root;
}
```

This code defines a function that adds a new row of nodes to a binary tree at a specified depth `d` with a given value `val`. The function handles different cases based on the depth `d`, such as adding a new root, adding a row at the first or second depth, and recursively adding nodes at deeper levels.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	TreeNode* addOneRow(TreeNode* root, int val, int d) {
	```
	This line declares the function `addOneRow`, which takes a root node, a value to be added, and the depth at which the row should be inserted. It returns the modified tree.

2. **Base Case for Depth 1**
	```cpp
	    if (d == 1) {
	```
	This condition checks if the row needs to be added at the root level (depth 1).

3. **Create New Root for Depth 1**
	```cpp
	        TreeNode* newroot = new TreeNode(val);
	```
	A new root node is created with the given value `val`.

4. **Set Left Child of New Root**
	```cpp
	        newroot->left = root;
	```
	The left child of the newly created root is set to the original root node.

5. **Return New Root**
	```cpp
	        return newroot;
	```
	The function returns the new root node with the added row.

6. **Base Case for Depth 0**
	```cpp
	    if (d == 0) {
	```
	This condition handles the case where the row needs to be added at the very bottom of the tree (depth 0).

7. **Create New Root for Depth 0**
	```cpp
	        TreeNode* newroot = new TreeNode(val);
	```
	A new root node is created with the given value `val`.

8. **Set Right Child of New Root**
	```cpp
	        newroot->right = root;
	```
	The right child of the newly created root is set to the original root node.

9. **Return New Root for Depth 0**
	```cpp
	        return newroot;
	```
	The function returns the new root node with the added row.

10. **Null Check**
	```cpp
	    if(!root) return nullptr;
	```
	This line ensures that if the current node is null (base case), the function returns null to prevent further recursion.

11. **Recursive Case for Depth 2**
	```cpp
	    else if(d == 2) {
	```
	This condition handles the case where the row needs to be added at depth 2.

12. **Recursive Add to Left Subtree**
	```cpp
	        root->left  = addOneRow(root->left, val, 1);
	```
	Recursively calls the function to add a new node to the left subtree at depth 1.

13. **Recursive Add to Right Subtree**
	```cpp
	        root->right = addOneRow(root->right, val, 0);
	```
	Recursively calls the function to add a new node to the right subtree at depth 0.

14. **Return Modified Root**
	```cpp
	        return root;
	```
	Returns the modified root node after adding the new row.

15. **Recursive Case for Deeper Depths**
	```cpp
	    } else if(d > 2) {
	```
	This condition handles the case for depths greater than 2, where recursion continues deeper into the tree.

16. **Recursive Add to Left Subtree at Deeper Depth**
	```cpp
	        root->left  = addOneRow(root->left, val, d - 1);
	```
	Recursively calls the function to continue adding rows in the left subtree at a decreased depth.

17. **Recursive Add to Right Subtree at Deeper Depth**
	```cpp
	        root->right = addOneRow(root->right, val,d - 1);
	```
	Recursively calls the function to continue adding rows in the right subtree at a decreased depth.

18. **Return Root at End**
	```cpp
	    return root;
	```
	Returns the root of the modified tree after adding the row.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we need to traverse all nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

Space complexity is proportional to the height of the tree due to recursion.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/add-one-row-to-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
