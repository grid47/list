
+++
authors = ["grid47"]
title = "Leetcode 94: Binary Tree Inorder Traversal"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 94: Binary Tree Inorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/94.webp"
youtube = "g_S5WuasWUE"
youtube_upload_date="2022-03-12"
youtube_thumbnail="https://i.ytimg.com/vi/g_S5WuasWUE/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/94.webp" 
    alt="A glowing tree with nodes softly illuminating as the inorder traversal progresses."
    caption="Solution to LeetCode 94: Binary Tree Inorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return the values of its nodes as they appear in an inorder traversal. Inorder traversal visits nodes in the left subtree, the root, and then the right subtree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree where each node has a value and pointers to left and right child nodes.
- **Example:** `Input: root = [5,3,8,1,4,null,10]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 100].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of integers representing the inorder traversal of the binary tree.
- **Example:** `Output: [1,3,4,5,8,10]`
- **Constraints:**
	- The output list must contain the values of all nodes visited in correct inorder sequence.

{{< dots >}}
### Core Logic 🔍
**Goal:** Perform an inorder traversal of the binary tree and return the node values in the correct order.

- Traverse the left subtree recursively.
- Visit the root node and append its value to the result list.
- Traverse the right subtree recursively.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is binary (each node has at most two children).
- The input tree structure is well-formed, with nodes correctly linked.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [2,1,3]`  \
  **Explanation:** The inorder traversal visits nodes in the order: left (1), root (2), right (3). Output: [1,2,3].

- **Input:** `Input: root = [10,null,15,null,20]`  \
  **Explanation:** The inorder traversal visits nodes in the order: root (10), right child (15), right subtree (20). Output: [10,15,20].

- **Input:** `Input: root = []`  \
  **Explanation:** An empty tree has no nodes to traverse. Output: [].

- **Input:** `Input: root = [7]`  \
  **Explanation:** A single-node tree has only the root to traverse. Output: [7].

{{< dots >}}
## Approach 🚀
Perform an inorder traversal of the binary tree using both recursive and iterative methods.

### Initial Thoughts 💭
- Inorder traversal visits nodes in the order: left subtree, root, right subtree.
- A recursive implementation is straightforward but can be replaced with an iterative stack-based approach for better control over recursion depth.
- Iterative traversal avoids the function call stack and provides explicit stack management.
- Both methods result in the same output but vary in implementation style and use of memory.
{{< dots >}}
### Edge Cases 🌐
- An empty tree (root = null) should return an empty list.
- A tree with maximum nodes (100) with a balanced or unbalanced structure.
- All node values are the same, e.g., root = [5,5,5].
- All nodes are arranged in a single line (left-skewed or right-skewed tree).
- Ensure no extra nodes are added or skipped during traversal.
{{< dots >}}
## Code 💻
```cpp
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> todo;
    while (root || !todo.empty()) {
        while (root) {
            todo.push(root);
            root = root -> left;
        }
        root = todo.top();
        todo.pop();
        nodes.push_back(root -> val);
        root = root -> right;
    }
    return nodes;
}
```

This code performs an inorder traversal of a binary tree and returns a vector containing the node values in inorder sequence.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> inorderTraversal(TreeNode* root) {
	```
	Declares a function `inorderTraversal` that takes the root node of a binary tree as input and returns a vector containing the inorder traversal of the tree.

2. **Result Initialization**
	```cpp
	    vector<int> nodes;
	```
	Initializes an empty vector `nodes` to store the inorder traversal result.

3. **Stack Initialization**
	```cpp
	    stack<TreeNode*> todo;
	```
	Initializes an empty stack `todo` to keep track of nodes to be visited.

4. **Loop Iteration**
	```cpp
	    while (root || !todo.empty()) {
	```
	Iterates until both the `root` node and the `todo` stack are empty.

5. **Nested Loop Iteration**
	```cpp
	        while (root) {
	```
	While the current `root` node is not null, we keep pushing it onto the stack and moving to its left child.

6. **Stack Push**
	```cpp
	            todo.push(root);
	```
	Pushes the current `root` node onto the stack.

7. **Pointer Update**
	```cpp
	            root = root -> left;
	```
	Moves the `root` pointer to its left child.

8. **Stack Pop**
	```cpp
	        root = todo.top();
	```
	Pops the top node from the stack and assigns it to the `root`.

9. **Stack Pop**
	```cpp
	        todo.pop();
	```
	Removes the top node from the stack.

10. **Result Update**
	```cpp
	        nodes.push_back(root -> val);
	```
	Adds the value of the current `root` node to the `nodes` vector.

11. **Pointer Update**
	```cpp
	        root = root -> right;
	```
	Moves the `root` pointer to its right child.

12. **Return**
	```cpp
	    return nodes;
	```
	Returns the `nodes` vector containing the inorder traversal of the tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each node is visited exactly once during the traversal.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the stack stores all nodes (e.g., in a completely skewed tree).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

---
{{< youtube g_S5WuasWUE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
