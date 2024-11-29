
+++
authors = ["grid47"]
title = "Leetcode 226: Invert Binary Tree"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 226: Invert Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/226.webp"
youtube = "JUyhWTDT2YI"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi/JUyhWTDT2YI/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/226.webp" 
    alt="A tree slowly flipping upside down, with nodes glowing as they invert."
    caption="Solution to LeetCode 226: Invert Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, invert the tree by swapping the left and right subtrees of every node, and return its root.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree, where each node contains an integer value and references to its left and right children.
- **Example:** `Input: root = [3,1,4,null,2,null,5]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 100].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the root of the inverted binary tree, where the left and right subtrees of every node are swapped.
- **Example:** `Output: [3,4,1,5,null,null,2]`
- **Constraints:**
	- The structure of the tree must maintain binary tree properties during inversion.

{{< dots >}}
### Core Logic 🔍
**Goal:** Swap the left and right subtrees recursively for every node in the binary tree.

- Base Case: If the current node is null, return null.
- Recursively invert the left subtree.
- Recursively invert the right subtree.
- Swap the left and right children of the current node.
- Return the root node.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is well-formed and adheres to binary tree properties.
- Node values can include negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5,3,8,1,4,7,9]`  \
  **Explanation:** The tree is inverted by swapping the left and right children of each node. Output: [5,8,3,9,7,4,1]

- **Input:** `Input: root = []`  \
  **Explanation:** An empty tree remains empty after inversion. Output: []

{{< dots >}}
## Approach 🚀
The approach uses a recursive algorithm to traverse the binary tree and swap the left and right subtrees of every node.

### Initial Thoughts 💭
- Inverting a tree requires swapping child nodes at each level.
- A depth-first traversal is suitable for recursive inversion.
- Recursion is a natural fit for this problem as it aligns with the tree structure.
- Handling the base case (null nodes) ensures no invalid accesses occur.
{{< dots >}}
### Edge Cases 🌐
- An input tree with no nodes.
- A complete binary tree with 100 nodes.
- A tree where all nodes have the same value.
- A tree with only left or right subtrees.
- Ensure the function works with nodes containing the minimum and maximum possible values.
{{< dots >}}
## Code 💻
```cpp
TreeNode* invertTree(TreeNode* root) {
    if(!root) return NULL;
    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}
```

This function recursively inverts a binary tree by swapping the left and right children of each node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* invertTree(TreeNode* root) {
	```
	Defines the `invertTree` function, which takes the root of a binary tree and returns the root of the inverted tree.

2. **Base Case**
	```cpp
	    if(!root) return NULL;
	```
	Checks if the root is NULL (base case for recursion). If it is NULL, the function returns NULL, ending the recursion.

3. **Temporary Variable**
	```cpp
	    TreeNode* tmp = root->left;
	```
	Stores the left child of the current node in a temporary variable `tmp` to facilitate swapping the left and right children.

4. **Recursive Call 1**
	```cpp
	    root->left = invertTree(root->right);
	```
	Recursively inverts the right subtree of the current node and assigns it to the left child of the current node.

5. **Recursive Call 2**
	```cpp
	    root->right = invertTree(tmp);
	```
	Recursively inverts the left subtree (stored in `tmp`) and assigns it to the right child of the current node.

6. **Return Inverted Tree**
	```cpp
	    return root;
	```
	Returns the root node of the inverted tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each node is visited exactly once during the inversion process.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is determined by the recursion stack, which is O(h), where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/invert-binary-tree/description/)

---
{{< youtube JUyhWTDT2YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
