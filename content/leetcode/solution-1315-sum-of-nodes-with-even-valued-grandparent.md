
+++
authors = ["grid47"]
title = "Leetcode 1315: Sum of Nodes with Even-Valued Grandparent"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1315: Sum of Nodes with Even-Valued Grandparent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
Given the root of a binary tree, return the sum of the values of the nodes that have an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0. A grandparent is defined as the parent of a node’s parent, if it exists.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by its root node. The binary tree nodes have integer values, and the structure of the tree is given in a nested manner (e.g., left and right children of nodes).
- **Example:** `For the tree [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5], the root node is 6.`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 10^4.
	- Each node’s value is an integer between 1 and 100.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the sum of values of nodes that have an even-valued grandparent.
- **Example:** `For the tree [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5], the output is 18.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the tree and for each node, check if its grandparent has an even value. If so, add its value to the result.

- 1. Traverse the binary tree using a depth-first search (DFS) approach.
- 2. For each node, check if its grandparent exists and if its value is even.
- 3. If the grandparent has an even value, add the current node’s value to the result.
- 4. Return the final sum after traversing the entire tree.
{{< dots >}}
### Problem Assumptions ✅
- The input binary tree is valid and has at least one node.
- Node values are positive integers within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `For the tree [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5], the sum of the values of the nodes with even-valued grandparents is 18. These nodes are 2, 1, and 5, where the grandparent node values are 6 (even).`  \
  **Explanation:** The even-valued grandparents are 6, and the nodes with even-valued grandparents are 2, 1, and 5. The sum of their values is 2 + 1 + 5 = 18.

{{< dots >}}
## Approach 🚀
We use a depth-first traversal approach to explore the binary tree. For each node, we pass the values of its parent and grandparent to help determine if it should be included in the sum.

### Initial Thoughts 💭
- We need to check the grandparent node for each node during traversal.
- A recursive or DFS approach would work well for traversing the tree.
- We will recursively traverse the tree and track the parent and grandparent of each node. If the grandparent’s value is even, we add the node’s value to the result.
{{< dots >}}
### Edge Cases 🌐
- An empty tree (null root) should return a sum of 0.
- The tree could have a large number of nodes, up to 10^4, and the solution should efficiently handle these cases.
- All nodes in the tree could have the same value, and the solution should still work correctly.
- The binary tree must be a valid structure with at least one node.
{{< dots >}}
## Code 💻
```cpp
int sumEvenGrandparent(TreeNode* root) {
    return helper(root, 1, 1);
}

int helper(TreeNode* node, int p, int gp) {
    if (!node) return 0;
    return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val: 0);
}
```

This function calculates the sum of all nodes' values where the grandparent node's value is even. It utilizes a helper function that recursively traverses the binary tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int sumEvenGrandparent(TreeNode* root) {
	```
	The function 'sumEvenGrandparent' is declared. It takes a pointer to the root of a binary tree as input and calls a helper function to calculate the sum based on the condition.

2. **Recursive Call**
	```cpp
	    return helper(root, 1, 1);
	```
	The function calls the helper function with the root node, a parent value of 1, and a grandparent value of 1 (since the root has no parent or grandparent).

3. **Helper Function Declaration**
	```cpp
	int helper(TreeNode* node, int p, int gp) {
	```
	The helper function is declared. It takes a node, the parent node's value (p), and the grandparent node's value (gp) as input.

4. **Base Case**
	```cpp
	    if (!node) return 0;
	```
	This is the base case for the recursion. If the node is null, the function returns 0.

5. **Recursive Calculation**
	```cpp
	    return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val: 0);
	```
	The function recursively calls itself for the left and right children of the current node, passing the current node's value as the new parent value. If the grandparent's value (gp) is even, the current node's value is added to the sum.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we visit each node exactly once during the DFS traversal.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursion stack in the DFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
