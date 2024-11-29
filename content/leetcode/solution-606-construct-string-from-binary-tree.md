
+++
authors = ["grid47"]
title = "Leetcode 606: Construct String from Binary Tree"
date = "2024-09-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 606: Construct String from Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/606.webp"
youtube = "b1WpYxnuebQ"
youtube_upload_date="2022-09-07"
youtube_thumbnail="https://i.ytimg.com/vi/b1WpYxnuebQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/606.webp" 
    alt="A binary tree where a string is being constructed by traversing the tree, with each character softly glowing."
    caption="Solution to LeetCode 606: Construct String from Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root node of a binary tree, generate a string representation of the tree following specific formatting rules based on a preorder traversal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root node of a binary tree, where each node is represented by its integer value. The tree can have any configuration of left and right children.
- **Example:** `Input: root = [1, 2, 3, null, 4]`
- **Constraints:**
	- The binary tree has at least one node.
	- Node values are integers in the range [-1000, 1000].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a string representing the binary tree following a preorder traversal, with proper parentheses indicating child nodes.
- **Example:** `Output: '1(2()(4))(3)'`
- **Constraints:**
	- The output is a string representation of the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** To convert a binary tree into a string format by recursively visiting each node in preorder and formatting it with parentheses for children.

- Perform a preorder traversal of the binary tree.
- For each node, if it has a left child, include it in parentheses.
- If the node has a right child but no left child, include empty parentheses '()' before the right child.
- Concatenate the node's value and the formatted strings of its children.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree with a single root node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, 2, 3, null, 4]`  \
  **Explanation:** In this case, node 1 has two children, node 2 and node 3. Node 2 itself has a right child (node 4), and node 3 has no children. The string representation is '1(2()(4))(3)' to reflect the structure.

{{< dots >}}
## Approach 🚀
The solution involves recursively traversing the binary tree in preorder and building the string representation based on the specified format.

### Initial Thoughts 💭
- Each node needs to be represented by its value, followed by parentheses enclosing its children (if any).
- Start with the root and recursively build the string for its left and right children. Ensure that empty parentheses are only added when necessary.
{{< dots >}}
### Edge Cases 🌐
- The input will always contain at least one node, so empty inputs are not an issue.
- The solution should handle up to 10,000 nodes efficiently.
- Ensure proper handling of trees with only left children, only right children, or no children at all.
- All nodes in the binary tree are valid integers within the specified range.
{{< dots >}}
## Code 💻
```cpp
string tree2str(TreeNode* root) {
    if(root == NULL) return "";
    string left  = tree2str(root->left);
    if(left!= "") left = '(' + left + ')';
    string right = tree2str(root->right);
    if(right != "") right = '(' + right + ')';
    if(left == "" && right != "") left = "()";
    // if(left != "" && right == "") right = "()";        
    return to_string(root->val)+left+right;
}
```

This code defines a recursive function `tree2str` that takes the root of a binary tree and returns its string representation. The function traverses the tree in pre-order and constructs the string by adding the value of the node along with its left and right children in parentheses.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string tree2str(TreeNode* root) {
	```
	Defines the function `tree2str` which takes a pointer to a TreeNode as input and returns a string representing the tree structure.

2. **Base Case**
	```cpp
	    if(root == NULL) return "";
	```
	Handles the base case of the recursion: if the current node is NULL, it returns an empty string.

3. **Recursive Call (Left Subtree)**
	```cpp
	    string left  = tree2str(root->left);
	```
	Recursively calls `tree2str` on the left child of the current node to get the string representation of the left subtree.

4. **Left Subtree Formatting**
	```cpp
	    if(left!= "") left = '(' + left + ')';
	```
	If the left subtree is not empty, formats it by surrounding the result with parentheses.

5. **Recursive Call (Right Subtree)**
	```cpp
	    string right = tree2str(root->right);
	```
	Recursively calls `tree2str` on the right child of the current node to get the string representation of the right subtree.

6. **Right Subtree Formatting**
	```cpp
	    if(right != "") right = '(' + right + ')';
	```
	If the right subtree is not empty, formats it by surrounding the result with parentheses.

7. **Handle Empty Left Subtree**
	```cpp
	    if(left == "" && right != "") left = "()";
	```
	If the left subtree is empty but the right subtree is not, adds `()` to represent the missing left child.

8. **Return Statement**
	```cpp
	    return to_string(root->val)+left+right;
	```
	Constructs the final string by concatenating the root's value with the string representations of the left and right subtrees.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the binary tree, since we perform a preorder traversal of all nodes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the string representation of the tree, which can be proportional to the number of nodes in the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-string-from-binary-tree/description/)

---
{{< youtube b1WpYxnuebQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
