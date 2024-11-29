
+++
authors = ["grid47"]
title = "Leetcode 110: Balanced Binary Tree"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 110: Balanced Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/110.webp"
youtube = "BrnZDIoScEA"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/BrnZDIoScEA/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/110.webp" 
    alt="A tree where branches gently balance on either side, with glowing nodes symbolizing equilibrium."
    caption="Solution to LeetCode 110: Balanced Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if for every node, the height of the left and right subtrees differs by no more than one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree.
- **Example:** `root = [10, 5, 15, null, null, 12, 20]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 5000].
	- -10^4 <= Node.val <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a boolean value indicating whether the tree is height-balanced or not.
- **Example:** `true`
- **Constraints:**
	- The tree is height-balanced if the height difference between the left and right subtrees of every node is no more than 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the binary tree is balanced by verifying that the difference in heights of the left and right subtrees is at most 1 at each node.

- For each node in the tree, calculate the height of its left and right subtrees recursively.
- If at any point the height difference is greater than 1, return false.
- Otherwise, return true if all nodes satisfy the balanced condition.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5,3,8,2,4,7,9]`  \
  **Explanation:** The tree is balanced because the height difference between the left and right subtrees at each node is no more than 1.

- **Input:** `Input: root = [1,2,2,3,3,null,null,4,4]`  \
  **Explanation:** The tree is not balanced because the height difference between the left and right subtrees of node 2 is greater than 1.

{{< dots >}}
## Approach 🚀
To check if a binary tree is height-balanced, we need to traverse the tree and calculate the height of each subtree. If at any point the difference in height exceeds 1, we know the tree is not balanced.

### Initial Thoughts 💭
- We can perform a depth-first search (DFS) traversal of the tree while calculating the height of each subtree.
- A recursive approach is ideal because we can calculate the height of a subtree and check if it is balanced in a single pass.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty, it is considered balanced.
- The solution should handle trees with up to 5000 nodes efficiently.
- The solution should handle trees where all nodes are on one side (unbalanced) and trees with balanced structures.
- The algorithm should run efficiently within the constraints of up to 5000 nodes.
{{< dots >}}
## Code 💻
```cpp
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    int l = h(root->left);
    int r = h(root->right);
    return abs(l - r) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right);
}
int h(TreeNode* node) {
    if(node == NULL) return 0;
    int l = h(node->left);
    int r = h(node->right);
    return 1 + max(l, r);
}
```

This solution checks whether a binary tree is height-balanced by calculating the height of each subtree recursively and ensuring the height difference is within one.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isBalanced(TreeNode* root) {
	```
	Define the main function to determine if a tree is balanced.

2. **Base Case**
	```cpp
	    if(!root) return true;
	```
	Base case: If the tree is empty, it is balanced by definition.

3. **Recursive Call**
	```cpp
	    int l = h(root->left);
	```
	Calculate the height of the left subtree by calling the helper function.

4. **Recursive Call**
	```cpp
	    int r = h(root->right);
	```
	Calculate the height of the right subtree by calling the helper function.

5. **Condition Evaluation**
	```cpp
	    return abs(l - r) <= 1 &&
	```
	Check if the difference in heights of left and right subtrees is at most 1.

6. **Recursive Call**
	```cpp
	        isBalanced(root->left) &&
	```
	Recursively check if the left subtree is balanced.

7. **Recursive Call**
	```cpp
	        isBalanced(root->right);
	```
	Recursively check if the right subtree is balanced.

8. **Function Declaration**
	```cpp
	int h(TreeNode* node) {
	```
	Define a helper function to compute the height of a tree.

9. **Base Case**
	```cpp
	    if(node == NULL) return 0;
	```
	Base case: The height of an empty tree is 0.

10. **Recursive Call**
	```cpp
	    int l = h(node->left);
	```
	Recursively calculate the height of the left subtree.

11. **Recursive Call**
	```cpp
	    int r = h(node->right);
	```
	Recursively calculate the height of the right subtree.

12. **Height Calculation**
	```cpp
	    return 1 + max(l, r);
	```
	Return the height of the current node as 1 plus the maximum height of its subtrees.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we traverse all nodes of the tree once, making the time complexity O(n).

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/balanced-binary-tree/description/)

---
{{< youtube BrnZDIoScEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
