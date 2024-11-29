
+++
authors = ["grid47"]
title = "Leetcode 1448: Count Good Nodes in Binary Tree"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1448: Count Good Nodes in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2AdOBLcj2wk"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/2AdOBLcj2wk/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary tree, a node is considered 'good' if in the path from the root to that node, there are no nodes with a value greater than the node itself. Return the total number of good nodes in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The binary tree is represented by its root node. Each node contains a value and pointers to its left and right child nodes.
- **Example:** `Input: root = [4, 2, 7, 1, 3, 6, 9]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^5].
	- Each node's value lies in the range [-10^4, 10^4].

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the total count of good nodes in the tree.
- **Example:** `Output: 5`
- **Constraints:**
	- The count must include the root node since it is always considered 'good'.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of nodes in the tree that are 'good' as per the defined criteria.

- Traverse the tree using Depth-First Search (DFS).
- At each node, check if its value is greater than or equal to the maximum value encountered so far along the path from the root.
- If the node satisfies the condition, increment the count of good nodes.
- Update the maximum value encountered so far and recursively traverse the left and right subtrees.
{{< dots >}}
### Problem Assumptions ✅
- The tree is non-empty and has at least one node (the root).
- Node values are integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5, 3, 8, 2, 4, 7, 9]`  \
  **Explanation:** Output: 5. Nodes 5, 8, 9, 3, and 4 are good. The path from the root to each of these nodes does not contain a value greater than the node.

- **Input:** `Input: root = [10, 9, 11]`  \
  **Explanation:** Output: 3. All nodes are good as there are no values greater than themselves in their respective paths.

- **Input:** `Input: root = [6, 2, 8, 1, 4]`  \
  **Explanation:** Output: 4. Nodes 6, 8, 4, and 1 are good. Node 2 is not good as 6 is greater than 2 in the path.

{{< dots >}}
## Approach 🚀
Use a recursive Depth-First Search (DFS) algorithm to traverse the binary tree and count the good nodes.

### Initial Thoughts 💭
- The root node is always good.
- The condition for a node being good depends on the maximum value seen along the path from the root.
- A recursive traversal is suitable to track the path's maximum value dynamically.
- Using DFS ensures that we visit each node and evaluate its goodness efficiently.
{{< dots >}}
### Edge Cases 🌐
- Input: root = null -> Output: 0. An empty tree has no good nodes.
- Input: A tree with 10^5 nodes -> Should handle efficiently within O(n) time complexity.
- Input: root = [1] -> Output: 1. The single node is good by default.
- Input: root = [3, 3, null, 4, 2] -> Special case where some nodes are not good due to a greater ancestor node.
- Tree depth is large; ensure no stack overflow occurs with recursion.
{{< dots >}}
## Code 💻
```cpp
int goodNodes(TreeNode* root) {
    return good(root, -100000);
}

int good(TreeNode* node, int mx) {
    if(node == NULL) return 0;
    int res = (node->val >= mx) ? 1: 0;
    res += good(node->left, max(mx, node->val));
    res += good(node->right, max(mx, node->val));
    return res;
}
```

This function computes the number of good nodes in a binary tree. A good node is a node whose value is greater than or equal to all the values in the path from the root to that node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int goodNodes(TreeNode* root) {
	```
	This is the function header where the return type is an integer, and the parameter is a pointer to a TreeNode (the root of the tree).

2. **Function Call**
	```cpp
	    return good(root, -100000);
	```
	This line calls the helper function 'good' with the root node and an initial value for 'mx' as a very low value (-100000) to start the comparison.

3. **Helper Function Declaration**
	```cpp
	int good(TreeNode* node, int mx) {
	```
	This is the helper function 'good' that recursively counts the good nodes in the tree. It takes a TreeNode pointer (node) and an integer (mx) which keeps track of the maximum value encountered along the path from the root.

4. **Conditional Check**
	```cpp
	    if(node == NULL) return 0;
	```
	This is the base case for the recursion. If the current node is NULL (i.e., we've reached a leaf's child), return 0, meaning no good node here.

5. **Conditional Assignment**
	```cpp
	    int res = (node->val >= mx) ? 1: 0;
	```
	Check if the current node's value is greater than or equal to the maximum value ('mx') encountered so far. If true, it is a good node, so set 'res' to 1, otherwise set it to 0.

6. **Recursive Call**
	```cpp
	    res += good(node->left, max(mx, node->val));
	```
	Recursively call the 'good' function for the left child, passing the maximum of the current node's value and 'mx' to ensure the path's maximum value is updated.

7. **Recursive Call**
	```cpp
	    res += good(node->right, max(mx, node->val));
	```
	Recursively call the 'good' function for the right child, again updating the maximum value encountered along the path.

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the total count of good nodes found in the current subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each node is visited once, leading to linear time complexity relative to the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is determined by the recursion stack, which depends on the height of the tree (`h`). In the worst case (skewed tree), it could be O(n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)

---
{{< youtube 2AdOBLcj2wk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
