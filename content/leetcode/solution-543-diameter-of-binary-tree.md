
+++
authors = ["grid47"]
title = "Leetcode 543: Diameter of Binary Tree"
date = "2024-09-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 543: Diameter of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/543.webp"
youtube = "6lJZ_xj1mEo"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/6lJZ_xj1mEo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/543.webp" 
    alt="A binary tree where the longest path between two nodes is highlighted, glowing softly to show the tree's diameter."
    caption="Solution to LeetCode 543: Diameter of Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes, which may or may not pass through the root.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree, where each node is represented by a value and pointers to its left and right child nodes.
- **Example:** `Input: root = [1,2,3,4,5]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^4].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest path between any two nodes in the tree. The path is measured by the number of edges between the nodes.
- **Example:** `Output: 3`
- **Constraints:**
	- The output will be an integer representing the length of the longest path.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the diameter of the binary tree efficiently.

- Perform a depth-first search (DFS) to traverse the tree.
- For each node, compute the maximum depth of its left and right subtrees.
- Track the maximum sum of the depths of the left and right subtrees, which gives the diameter.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree.
- The input tree will contain at least one node.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,2,3,4,5]`  \
  **Explanation:** In this example, the tree has a longest path between node 4 and node 3 through node 2 and node 1, which has a length of 3 edges.

{{< dots >}}
## Approach 🚀
We can compute the diameter of the binary tree using a depth-first search (DFS) traversal. For each node, we calculate the maximum depth of its left and right subtrees and update the diameter based on the sum of the depths.

### Initial Thoughts 💭
- This is a classic depth-first search problem where we need to compute the maximum depth of subtrees and track the longest path.
- By using DFS, we can calculate the maximum depth from each node and compute the diameter by updating the result with the sum of the depths of the left and right subtrees.
{{< dots >}}
### Edge Cases 🌐
- The tree will not be empty as per the problem constraints.
- Ensure the solution works efficiently for trees with up to 10^4 nodes.
- Handle cases with only one node in the tree, where the diameter will be 0.
- The tree contains up to 10^4 nodes.
{{< dots >}}
## Code 💻
```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int d = 0;
    dep(d, root);
    return d;
}

int dep(int &d, TreeNode* node) {
    if(node == NULL) return 0;
    int l = dep(d, node->left);
    int r = dep(d, node->right);
    d = max(d, l + r);
    return 1 + max(l, r);
}
```

This function calculates the diameter of a binary tree, which is the length of the longest path between any two nodes in the tree. The helper function `dep` computes the depth of each node recursively while updating the diameter.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int diameterOfBinaryTree(TreeNode* root) {
	```
	Defines the `diameterOfBinaryTree` function, which takes the root of the binary tree as an argument and returns the diameter of the tree.

2. **Variable Initialization**
	```cpp
	    int d = 0;
	```
	Initializes a variable `d` to store the maximum diameter found during the traversal of the tree.

3. **Recursive Call**
	```cpp
	    dep(d, root);
	```
	Calls the helper function `dep` with `d` and the root of the tree to compute the depth of the tree and update the diameter.

4. **Return Statement**
	```cpp
	    return d;
	```
	Returns the computed diameter `d` of the binary tree.

5. **Function Definition**
	```cpp
	int dep(int &d, TreeNode* node) {
	```
	Defines the helper function `dep`, which calculates the depth of a node and updates the diameter based on the longest path from that node.

6. **Base Case**
	```cpp
	    if(node == NULL) return 0;
	```
	Base case for the recursion: if the node is `NULL`, return 0 as its depth.

7. **Recursive Call (Left Subtree)**
	```cpp
	    int l = dep(d, node->left);
	```
	Recursively calls `dep` for the left child of the current node to compute the depth of the left subtree.

8. **Recursive Call (Right Subtree)**
	```cpp
	    int r = dep(d, node->right);
	```
	Recursively calls `dep` for the right child of the current node to compute the depth of the right subtree.

9. **Update Diameter**
	```cpp
	    d = max(d, l + r);
	```
	Updates the diameter `d` if the sum of the left and right subtree depths (`l + r`) is larger than the current diameter.

10. **Return Depth**
	```cpp
	    return 1 + max(l, r);
	```
	Returns the depth of the current node as `1 + max(l, r)`, where `l` and `r` are the depths of the left and right subtrees, respectively.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because each node is visited once.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h) due to the recursive call stack, where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/diameter-of-binary-tree/description/)

---
{{< youtube 6lJZ_xj1mEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
