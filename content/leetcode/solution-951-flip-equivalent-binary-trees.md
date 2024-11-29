
+++
authors = ["grid47"]
title = "Leetcode 951: Flip Equivalent Binary Trees"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 951: Flip Equivalent Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "izRDc1il9Pk"
youtube_upload_date="2021-08-14"
youtube_thumbnail="https://i.ytimg.com/vi/izRDc1il9Pk/maxresdefault.jpg"
comments = true
+++



---
You are given the roots of two binary trees. A flip operation consists of choosing any node and swapping its left and right child subtrees. A tree X is flip equivalent to tree Y if and only if we can make tree X equal to tree Y by performing some flip operations on X. Your task is to determine if the two trees are flip equivalent.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the roots of two binary trees, represented as TreeNode objects.
- **Example:** `Input: root1 = [3,5,6,7,8], root2 = [3,8,5,6,7]`
- **Constraints:**
	- The number of nodes in each tree is in the range [0, 100].
	- Each tree will have unique node values in the range [0, 99].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value indicating whether the two trees are flip equivalent.
- **Example:** `Output: true`
- **Constraints:**
	- The output will be a boolean: true if the trees are flip equivalent, false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if two binary trees are flip equivalent, we need to recursively compare both trees while considering the possibility of flipping subtrees.

- 1. Compare the root values of both trees. If they are not equal, return false.
- 2. Recursively check if both left and right subtrees are flip equivalent, either in the original order or after flipping them.
- 3. If either of these conditions hold true, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The input trees are binary trees with unique node values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root1 = [1,2,3,4,5,6], root2 = [1,3,2,5,6,4]`  \
  **Explanation:** Both trees are flip equivalent because we can perform flip operations at nodes with values 1 and 3 to make the structures of the two trees identical.

- **Input:** `Input: root1 = [1,2,3], root2 = [1,3,2]`  \
  **Explanation:** The trees are flip equivalent because we can swap the left and right subtrees of node 1.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves a recursive check on the binary trees. At each node, we will compare the left and right subtrees, considering both the possibility of no flip and a flip operation.

### Initial Thoughts 💭
- This problem can be solved by comparing trees recursively while considering both the direct and flipped structures.
- The recursive approach will allow us to break down the problem by comparing smaller subtrees at each level.
{{< dots >}}
### Edge Cases 🌐
- If both trees are empty, return true since two empty trees are trivially flip equivalent.
- For large trees with up to 100 nodes, the solution must work efficiently within the problem's constraints.
- If one tree is empty and the other is not, the trees are not flip equivalent.
- The solution must handle trees with at most 100 nodes efficiently.
{{< dots >}}
## Code 💻
```cpp
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if(root1 == NULL || root2 == NULL) 
        return root1 == root2;

    return (root1->val == root2->val) && 
(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

}
```

This function checks if two binary trees are flip equivalent, meaning that one tree can be transformed into the other by swapping left and right subtrees. The function compares nodes recursively to determine if the trees are equivalent in structure and value, allowing for subtree flipping.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
	```
	The function `flipEquiv` takes two binary tree roots, `root1` and `root2`, and returns `true` if the two trees are flip equivalent, otherwise `false`.

2. **Base Case Check**
	```cpp
	    if(root1 == NULL || root2 == NULL) 
	```
	Check if either of the trees is empty. If one is empty and the other is not, return `false`. If both are `NULL`, return `true`.

3. **Base Case Result**
	```cpp
	        return root1 == root2;
	```
	Return `true` if both trees are `NULL` or `false` if one is `NULL` and the other is not.

4. **Recursive Check Start**
	```cpp
	
	```
	Proceed to recursively compare the subtrees of both trees, considering both possible scenarios (subtrees are in the same order or flipped).

5. **Value Comparison**
	```cpp
	    return (root1->val == root2->val) && 
	```
	First, check if the values at the current nodes of `root1` and `root2` are equal. If they are not equal, the trees cannot be flip equivalent.

6. **Recursive Left-Right Comparison**
	```cpp
	(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
	```
	Recursively check if the left subtree of `root1` is flip equivalent to the left subtree of `root2`, and if the right subtrees match as well.

7. **Recursive Flipped Left-Right Comparison**
	```cpp
	flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
	```
	Alternatively, check if the left subtree of `root1` is flip equivalent to the right subtree of `root2`, and vice versa, indicating a flip of subtrees.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, O(n), where n is the number of nodes in the tree. This is because we traverse each node once.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-equivalent-binary-trees/description/)

---
{{< youtube izRDc1il9Pk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
