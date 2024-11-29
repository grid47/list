
+++
authors = ["grid47"]
title = "Leetcode 872: Leaf-Similar Trees"
date = "2024-08-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 872: Leaf-Similar Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Nr8dbnL0_cM"
youtube_upload_date="2024-01-09"
youtube_thumbnail="https://i.ytimg.com/vi/Nr8dbnL0_cM/maxresdefault.jpg"
comments = true
+++



---
Given two binary trees, determine if their leaf value sequences are identical. A binary tree's leaf value sequence is the sequence of values of its leaves, from left to right, following the in-order traversal. Two trees are considered leaf-similar if the leaf values in both trees appear in the same order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two binary trees represented by their root nodes, `root1` and `root2`.
- **Example:** `Input: root1 = [1, 3, 4, null, null, 5, 6], root2 = [1, 2, 3, null, 4, 6, 5]`
- **Constraints:**
	- The number of nodes in each tree is between 1 and 200.
	- The values of the nodes are between 0 and 200.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return `true` if the two trees have identical leaf value sequences, otherwise return `false`.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean indicating whether the trees' leaf value sequences are identical.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse both trees and compare their leaf sequences.

- Perform a depth-first search (DFS) on both trees to collect the leaf values.
- Compare the leaf value sequences of both trees. If they are identical, return `true`; otherwise, return `false`.
{{< dots >}}
### Problem Assumptions ✅
- The input trees are binary trees.
- The leaf nodes are the nodes without any children.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root1 = [1, 3, 4, null, null, 5, 6], root2 = [1, 2, 3, null, 4, 6, 5]`  \
  **Explanation:** Both trees have the same leaf value sequence [5, 6], so the output is `true`.

- **Input:** `Input: root1 = [1, 2, 3], root2 = [1, 3, 2]`  \
  **Explanation:** The leaf value sequences for root1 are [2, 3] and for root2 are [3, 2], which are not identical, so the output is `false`.

{{< dots >}}
## Approach 🚀
We can solve this problem by performing a DFS traversal on both trees to extract their leaf values and then compare the sequences.

### Initial Thoughts 💭
- The leaf value sequence of a tree can be obtained through a depth-first search (DFS).
- Both trees need to be traversed in the same way to ensure the sequences are compared correctly.
- A DFS approach is efficient for this problem since it allows us to directly extract the leaf values in order.
{{< dots >}}
### Edge Cases 🌐
- If either tree is empty, the result should be `false` since leaf sequences can't match.
- For large inputs (trees with 200 nodes), the algorithm should efficiently handle the traversal and comparison.
- If both trees have only one node each, the result depends on whether the nodes are leaves and have the same value.
- The solution must handle trees with a maximum of 200 nodes and node values within the specified range.
{{< dots >}}
## Code 💻
```cpp
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    s1.push(root1), s2.push(root2);
    while(!s1.empty() && !s2.empty())
        if(dfs(s1) != dfs(s2)) return false;
    return s1.empty() && s2.empty();
}

int dfs(stack<TreeNode*> &stk) {
    while(true) {
        TreeNode* node = stk.top(); stk.pop();
        if(node->left) stk.push(node->left);
        if(node->right) stk.push(node->right);
        if(!node->left && !node->right) return node->val;
    }
}
```

The function `leafSimilar` checks if two binary trees have the same leaf sequence using depth-first search (DFS) with a stack. The `dfs` function traverses the tree and returns the value of a leaf node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	```
	Defines the function `leafSimilar` that compares the leaf nodes of two binary trees for similarity.

2. **Stack Initialization**
	```cpp
	    stack<TreeNode*> s1, s2;
	```
	Initializes two stacks, `s1` and `s2`, to hold nodes for depth-first traversal of `root1` and `root2`.

3. **Push Roots**
	```cpp
	    s1.push(root1), s2.push(root2);
	```
	Pushes the root nodes of both `root1` and `root2` onto their respective stacks.

4. **Loop Setup**
	```cpp
	    while(!s1.empty() && !s2.empty())
	```
	Starts a loop to traverse both trees as long as neither stack is empty.

5. **Leaf Comparison**
	```cpp
	        if(dfs(s1) != dfs(s2)) return false;
	```
	Compares the leaf nodes of both trees by calling the `dfs` function on each stack. If the leaf values don't match, it returns `false`.

6. **Return Comparison Result**
	```cpp
	    return s1.empty() && s2.empty();
	```
	Returns `true` if both stacks are empty, indicating that both trees had the same leaf sequence.

7. **DFS Function Definition**
	```cpp
	int dfs(stack<TreeNode*> &stk) {
	```
	Defines the `dfs` function that performs depth-first search on the tree using a stack and returns the value of the leaf node.

8. **Infinite Loop**
	```cpp
	    while(true) {
	```
	Starts an infinite loop to keep processing nodes from the stack.

9. **Pop Node**
	```cpp
	        TreeNode* node = stk.top(); stk.pop();
	```
	Pops the top node from the stack for processing.

10. **Push Child Nodes**
	```cpp
	        if(node->left) stk.push(node->left);
	```
	Pushes the left child of the current node onto the stack if it exists.

11. **Push Right Child**
	```cpp
	        if(node->right) stk.push(node->right);
	```
	Pushes the right child of the current node onto the stack if it exists.

12. **Return Leaf Value**
	```cpp
	        if(!node->left && !node->right) return node->val;
	```
	If the current node is a leaf (both left and right children are null), return its value.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the number of nodes, as each tree is traversed once to collect the leaf values.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space is required for storing the leaf values during the DFS traversal, resulting in O(n) space complexity.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/leaf-similar-trees/description/)

---
{{< youtube Nr8dbnL0_cM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
