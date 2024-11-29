
+++
authors = ["grid47"]
title = "Leetcode 1123: Lowest Common Ancestor of Deepest Leaves"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1123: Lowest Common Ancestor of Deepest Leaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yVw0Q8QknJg"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yVw0Q8QknJg/maxresdefault.webp"
comments = true
+++



---
Given the root of a binary tree, your task is to return the lowest common ancestor (LCA) of its deepest leaf nodes. The LCA of a set of nodes is the deepest node that is an ancestor of all the nodes in the set. A leaf node is one that does not have any children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree, represented as an array. The array is a level-order traversal of the tree, where null represents the absence of a node. The number of nodes in the tree is between 1 and 1000.
- **Example:** `Input: root = [4,2,6,1,3,5,7]`
- **Constraints:**
	- The number of nodes in the tree will be between 1 and 1000.
	- Each node value is a unique integer between 0 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return the value of the node representing the lowest common ancestor of the deepest leaf nodes. If there are multiple deepest leaves, return their common ancestor.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be the value of the lowest common ancestor.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the deepest leaf nodes in the binary tree and then return their lowest common ancestor.

- Traverse the tree to calculate the depth of each node.
- Track the deepest level while traversing the tree.
- Once the deepest level is reached, identify the common ancestor of all deepest nodes.
{{< dots >}}
### Problem Assumptions ✅
- Each node in the tree is unique.
- The binary tree is represented as an array (level-order traversal).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [3,5,1,6,2,0,8,null,null,7,4]`  \
  **Explanation:** In this example, the deepest leaves are nodes 7 and 4 (at depth 3), and their lowest common ancestor is node 2.

- **Input:** `Input: root = [1]`  \
  **Explanation:** In this case, the only node in the tree is the root, which is the deepest node and the lowest common ancestor of itself.

{{< dots >}}
## Approach 🚀
To solve the problem, we will perform a depth-first traversal to calculate the depth of each node and keep track of the deepest nodes. During traversal, we will find the common ancestor of the deepest nodes.

### Initial Thoughts 💭
- The lowest common ancestor of the deepest leaves can be found by examining the depths of the nodes.
- By recursively traversing the tree and comparing depths, we can identify the deepest leaves and their LCA.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return NULL.
- The algorithm must efficiently handle trees with up to 1000 nodes.
- If there is only one node in the tree, it is the deepest node and the lowest common ancestor.
- The solution should not exceed O(n) time complexity, where n is the number of nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return helper(root).first;
}

pair<TreeNode*, int> helper(TreeNode* root) {
    if(root == NULL) return {NULL, 0};
    auto left = helper(root->left);
    auto right = helper(root->right);
    if(left.second > right.second)
    return {left.first, left.second + 1};
    else if(left.second < right.second)
    return {right.first, right.second + 1};
    return {root, left.second + 1};
}
```

This code defines two functions, `lcaDeepestLeaves` and `helper`, to find the Lowest Common Ancestor (LCA) of the deepest leaves in a binary tree. The function `helper` recursively calculates the depth of each subtree and returns the LCA along with the depth. The `lcaDeepestLeaves` function calls `helper` to retrieve the LCA of the deepest leaves.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	TreeNode* lcaDeepestLeaves(TreeNode* root) {
	```
	Declares the function `lcaDeepestLeaves`, which takes the root of a binary tree as input and returns a pointer to the Lowest Common Ancestor (LCA) of the deepest leaves.

2. **Return Statement**
	```cpp
	    return helper(root).first;
	```
	Calls the helper function, which computes the LCA and depth of the deepest leaves, and returns the LCA (`first` element of the pair).

3. **Function End**
	```cpp
	}
	```
	Marks the end of the `lcaDeepestLeaves` function.

4. **Helper Function Declaration**
	```cpp
	
	```
	The helper function is used to recursively calculate the LCA of the deepest leaves and their depth.

5. **Function Declaration**
	```cpp
	pair<TreeNode*, int> helper(TreeNode* root) {
	```
	Declares the helper function, which takes a tree node as input and returns a pair containing the LCA and the depth of the subtree.

6. **Base Case**
	```cpp
	    if(root == NULL) return {NULL, 0};
	```
	Handles the base case where the root is NULL. It returns a pair of NULL (no ancestor) and depth 0.

7. **Recursive Call (Left Subtree)**
	```cpp
	    auto left = helper(root->left);
	```
	Recursively calls `helper` on the left child of the current node to compute the LCA and depth for the left subtree.

8. **Recursive Call (Right Subtree)**
	```cpp
	    auto right = helper(root->right);
	```
	Recursively calls `helper` on the right child of the current node to compute the LCA and depth for the right subtree.

9. **Comparison (Left Deeper)**
	```cpp
	    if(left.second > right.second)
	```
	Compares the depths of the left and right subtrees. If the left subtree is deeper, it returns the LCA and depth from the left subtree.

10. **Return Left Subtree**
	```cpp
	    return {left.first, left.second + 1};
	```
	If the left subtree is deeper, it returns the LCA from the left subtree along with the depth incremented by 1.

11. **Comparison (Right Deeper)**
	```cpp
	    else if(left.second < right.second)
	```
	If the right subtree is deeper, it returns the LCA and depth from the right subtree.

12. **Return Right Subtree**
	```cpp
	    return {right.first, right.second + 1};
	```
	If the right subtree is deeper, it returns the LCA from the right subtree along with the depth incremented by 1.

13. **Equal Depths**
	```cpp
	    return {root, left.second + 1};
	```
	If the left and right subtrees have the same depth, it returns the current node as the LCA along with the depth incremented by 1.

14. **Function End**
	```cpp
	}
	```
	Marks the end of the `helper` function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we need to visit each node in the tree once to calculate the depths and identify the LCA.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h) due to the space used by the recursion stack, where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

---
{{< youtube yVw0Q8QknJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
