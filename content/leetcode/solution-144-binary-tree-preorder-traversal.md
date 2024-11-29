
+++
authors = ["grid47"]
title = "Leetcode 144: Binary Tree Preorder Traversal"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 144: Binary Tree Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/144.webp"
youtube = "WIfjmUTXnlE"
youtube_upload_date="2022-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/WIfjmUTXnlE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/144.webp" 
    alt="A tree with nodes glowing sequentially from root to leaf, following a smooth, glowing path."
    caption="Solution to LeetCode 144: Binary Tree Preorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. The task is to return the preorder traversal of the tree. Preorder traversal means visiting the root node first, followed by the left subtree, and then the right subtree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by its root node, where each node has a value, a left child, and a right child.
- **Example:** `Input: root = [10, null, 20, 30]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 100].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of node values representing the preorder traversal of the binary tree.
- **Example:** `Output: [10, 20, 30]`
- **Constraints:**
	- The output should be a list of integers representing the node values in the correct preorder traversal order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to return a list of node values in preorder traversal order, where each node is visited starting with the root node, followed by the left subtree, and then the right subtree.

- 1. Start at the root of the tree.
- 2. Add the value of the current node to the result list.
- 3. Traverse the left subtree recursively.
- 4. Traverse the right subtree recursively.
{{< dots >}}
### Problem Assumptions ✅
- The tree may be empty (i.e., root is null).
- The tree contains nodes with values between -100 and 100.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10, null, 20, 30]`  \
  **Explanation:** The tree is: 10 -> 20 -> 30. The preorder traversal visits the root (10), then the right child (20), and its right child (30), resulting in the output [10, 20, 30].

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a recursive approach where we first visit the root, then recursively visit the left and right subtrees.

### Initial Thoughts 💭
- A simple recursive solution can be used to achieve the preorder traversal.
- While the recursive solution is simple, an iterative solution using a stack can also be implemented to avoid recursion.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty (root is null), return an empty list.
- For larger trees, the solution should efficiently handle all nodes within the time complexity of O(n).
- Handle trees with negative node values, as node values can range from -100 to 100.
- The solution must operate in linear time, O(n), where n is the number of nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
void pre(TreeNode* root, vector<int> &ans) {
    if(!root) return;
    ans.push_back(root->val);
    pre(root->left, ans);
    pre(root->right, ans);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    pre(root, ans);
    return ans;
}
```

This function implements a preorder tree traversal. It recursively visits the root node first, then the left subtree, followed by the right subtree, collecting node values along the way.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	void pre(TreeNode* root, vector<int> &ans) {
	```
	This defines a helper function `pre` that performs a recursive preorder traversal of a binary tree, storing the visited node values in the `ans` vector.

2. **Base Case**
	```cpp
	    if(!root) return;
	```
	Checks if the current node is null. If it is, the function returns immediately, ending the current recursive branch.

3. **Visit Node**
	```cpp
	    ans.push_back(root->val);
	```
	Adds the value of the current node (`root->val`) to the `ans` vector, which stores the result of the preorder traversal.

4. **Recurse Left Subtree**
	```cpp
	    pre(root->left, ans);
	```
	Recursively calls the `pre` function on the left child of the current node to traverse the left subtree.

5. **Recurse Right Subtree**
	```cpp
	    pre(root->right, ans);
	```
	Recursively calls the `pre` function on the right child of the current node to traverse the right subtree.

6. **Main Function Definition**
	```cpp
	vector<int> preorderTraversal(TreeNode* root) {
	```
	Defines the main function `preorderTraversal`, which initializes the result container (`ans`) and calls the helper function `pre` to start the traversal.

7. **Initialize Result Container**
	```cpp
	    vector<int> ans;
	```
	Initializes the vector `ans`, which will store the result of the preorder traversal.

8. **Call Helper Function**
	```cpp
	    pre(root, ans);
	```
	Calls the `pre` helper function, passing the root of the tree and the `ans` vector to begin the preorder traversal.

9. **Return Result**
	```cpp
	    return ans;
	```
	Returns the `ans` vector containing the node values collected during the preorder traversal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), when the tree has no empty branches.
- **Average Case:** O(n), the tree is traversed once.
- **Worst Case:** O(n), the tree will always need to be fully traversed.

The time complexity is O(n) because each node in the tree is visited once during the preorder traversal.

### Space Complexity 💾
- **Best Case:** O(1), if an iterative solution is used with a stack.
- **Worst Case:** O(h), where h is the height of the tree, due to the recursive call stack.

The space complexity depends on the recursion depth (height of the tree), or the space used by the stack in the iterative approach.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-preorder-traversal/description/)

---
{{< youtube WIfjmUTXnlE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
