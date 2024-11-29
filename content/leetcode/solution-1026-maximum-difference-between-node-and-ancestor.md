
+++
authors = ["grid47"]
title = "Leetcode 1026: Maximum Difference Between Node and Ancestor"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1026: Maximum Difference Between Node and Ancestor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f37BCBHGFGA"
youtube_upload_date="2020-07-07"
youtube_thumbnail="https://i.ytimg.com/vi/f37BCBHGFGA/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree. Your task is to find the maximum absolute difference between the values of two nodes, where one node is an ancestor of the other. Specifically, you need to find the largest value of |a.val - b.val|, where node a is an ancestor of node b.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree, where each node contains a value representing an integer.
- **Example:** `root = [5, 3, 8, 1, 4, null, 9]`
- **Constraints:**
	- 2 <= number of nodes <= 5000
	- 0 <= Node.val <= 105

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the maximum absolute difference between the values of two nodes, where one is an ancestor of the other.
- **Example:** `Output: 8`
- **Constraints:**
	- The absolute difference is calculated between two nodes, where one node is an ancestor of the other.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum difference between values of two nodes in a binary tree where one is an ancestor of the other. This can be done by recursively traversing the tree and tracking the minimum and maximum values encountered along the path.

- 1. Start by recursively visiting each node of the tree.
- 2. Track the minimum and maximum values encountered on the path from the root to the current node.
- 3. Calculate the difference between the current node's value and the tracked minimum and maximum values.
- 4. Return the maximum difference found.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree with at least two nodes.
- Each node has a value between 0 and 105.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5, 3, 8, 1, 4, null, 9]`  \
  **Explanation:** In this example, the maximum difference occurs between nodes 5 and 1, yielding a difference of 8. Hence, the output is 8.

- **Input:** `Input: root = [10, 5, 15, 3, 7, null, 20]`  \
  **Explanation:** In this case, the maximum difference is between nodes 10 and 3, yielding a difference of 7. Thus, the output is 7.

{{< dots >}}
## Approach 🚀
The approach uses a depth-first search (DFS) strategy to traverse the tree while keeping track of the maximum and minimum values encountered along the path from the root to each node.

### Initial Thoughts 💭
- The problem involves traversing a binary tree and calculating the maximum and minimum differences for every path.
- A depth-first search approach is appropriate because it allows us to visit all nodes while keeping track of necessary values (min and max).
{{< dots >}}
### Edge Cases 🌐
- If the tree has fewer than two nodes, return 0 (this case is assumed to be invalid per problem constraints).
- The algorithm should efficiently handle trees with up to 5000 nodes.
- Ensure that the solution handles cases where all node values are the same (resulting in a difference of 0).
- The tree must be valid, and each node must have a value between 0 and 105.
{{< dots >}}
## Code 💻
```cpp
int maxAncestorDiff(TreeNode* root) {
    return helper(root, root->val, root->val);
}
int helper(TreeNode* node, int mx, int mn) {
    if(!node) return mx - mn;
    mx = max(mx, node->val);
    mn = min(mn, node->val);
    
    return max(helper(node->left, mx, mn), helper(node->right, mx, mn));
}
```

This function calculates the maximum difference between the values of any ancestor node and descendant node in a binary tree. It uses a helper function to traverse the tree while keeping track of the maximum and minimum values along the path.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxAncestorDiff(TreeNode* root) {
	```
	Define the function `maxAncestorDiff` which takes the root of the tree and calculates the maximum ancestor-descendant difference.

2. **Function Call**
	```cpp
	    return helper(root, root->val, root->val);
	```
	Call the helper function with the root node and initialize both the maximum (`mx`) and minimum (`mn`) values to the root's value.

3. **Helper Function Definition**
	```cpp
	int helper(TreeNode* node, int mx, int mn) {
	```
	Define the helper function which recursively traverses the tree, updating the maximum and minimum values and computing the maximum difference.

4. **Base Case**
	```cpp
	    if(!node) return mx - mn;
	```
	If the current node is null, return the difference between the maximum and minimum values encountered so far.

5. **Update Maximum**
	```cpp
	    mx = max(mx, node->val);
	```
	Update the maximum value (`mx`) with the current node's value if it is larger.

6. **Update Minimum**
	```cpp
	    mn = min(mn, node->val);
	```
	Update the minimum value (`mn`) with the current node's value if it is smaller.

7. **Recursive Traversal**
	```cpp
	    return max(helper(node->left, mx, mn), helper(node->right, mx, mn));
	```
	Recursively calculate the maximum difference for the left and right subtrees, and return the maximum of the two results.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree, since we visit each node once during the DFS traversal.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the space used by the recursion stack. In the worst case (unbalanced tree), h can be O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

---
{{< youtube f37BCBHGFGA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
