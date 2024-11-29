
+++
authors = ["grid47"]
title = "Leetcode 669: Trim a Binary Search Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 669: Trim a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/669.webp"
youtube = "jwt5mTjEXGc"
youtube_upload_date="2021-10-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jwt5mTjEXGc/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/669.webp" 
    alt="A binary search tree where the tree is trimmed to fit a given range, with each trimmed node softly glowing."
    caption="Solution to LeetCode 669: Trim a Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary search tree (BST) and two integer values `low` and `high`. Trim the tree such that all its elements lie within the inclusive range `[low, high]`. The tree's relative structure should remain unchanged, and the root may change depending on the given bounds.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary search tree and two integer values `low` and `high`, representing the boundaries within which all elements of the tree should lie.
- **Example:** `root = [4,2,6,1,3,5,7], low = 3, high = 6`
- **Constraints:**
	- 1 <= Number of nodes <= 10^4
	- 0 <= Node.val <= 10^4
	- low <= high <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the trimmed binary search tree. The structure of the tree must remain intact, with nodes lying within the range `[low, high]`.
- **Example:** `[4,3,6,null,null,5]`
- **Constraints:**
	- The output tree must have the same structure as the input tree, but with only the nodes that fall within the specified range.

{{< dots >}}
### Core Logic 🔍
**Goal:** Trim the binary search tree by removing nodes that fall outside the range [low, high]. The relative structure of the tree should be maintained.

- 1. Check if the current node’s value is less than low, in which case we only need to trim the right subtree.
- 2. If the current node’s value is greater than high, trim the left subtree.
- 3. If the current node's value lies within the range [low, high], recursively trim both the left and right subtrees.
{{< dots >}}
### Problem Assumptions ✅
- The binary search tree is valid and follows the properties of a BST.
- The node values are unique, ensuring there is only one possible valid trimming of the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [4,2,6,1,3,5,7], low = 3, high = 6`  \
  **Explanation:** After trimming, the tree only contains nodes with values between 3 and 6. The final tree is [4,3,6,null,null,5].

- **Input:** `root = [10,5,15,3,7,null,18], low = 5, high = 15`  \
  **Explanation:** After trimming, the tree contains nodes with values between 5 and 15. The final tree is [10,5,null,null,7].

{{< dots >}}
## Approach 🚀
To solve this problem, recursively trim the binary search tree by ensuring each node falls within the given range. Nodes outside the range should be removed, and the structure should be preserved.

### Initial Thoughts 💭
- The problem requires a modification of the tree structure while maintaining the order of the remaining nodes.
- The key observation is that trimming a BST can be done using a simple recursive approach by comparing each node's value with the given range.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one node in the tree, so no need to handle empty tree cases.
- For large trees with up to 10^4 nodes, ensure the solution handles recursion efficiently.
- Ensure that nodes with values at the boundaries of the range [low, high] are correctly included.
- The tree is a valid BST with unique node values.
{{< dots >}}
## Code 💻
```cpp
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(root == NULL) return NULL;

   if(root->val < low) {
       return trimBST(root->right, low, high);
   } else if(root->val > high) {
        return trimBST(root->left, low, high);
   }

    root->left = trimBST(root->left, low, high);
    root->right= trimBST(root->right, low, high);
    return root;
}
```

This function trims a binary search tree (BST) such that all nodes with values outside the given range `[low, high]` are removed, and the tree is returned with the remaining nodes within the range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* trimBST(TreeNode* root, int low, int high) {
	```
	This is the function definition for `trimBST`, which trims a binary search tree (BST) such that only nodes with values within the specified range `[low, high]` are kept.

2. **Base Case**
	```cpp
	    if(root == NULL) return NULL;
	```
	If the root is `NULL`, return `NULL` as there is no tree to trim.

3. **Left Subtree Trimming**
	```cpp
	   if(root->val < low) {
	```
	If the value of the current node is smaller than `low`, this node and everything in its left subtree should be discarded, so we recursively call `trimBST` on the right child.

4. **Trim Right Subtree**
	```cpp
	       return trimBST(root->right, low, high);
	```
	Return the result of recursively trimming the right subtree, as all values in the left subtree are too small.

5. **Right Subtree Trimming Check**
	```cpp
	   } else if(root->val > high) {
	```
	If the value of the current node is greater than `high`, this node and everything in its right subtree should be discarded, so we recursively call `trimBST` on the left child.

6. **Trim Left Subtree**
	```cpp
	        return trimBST(root->left, low, high);
	```
	Return the result of recursively trimming the left subtree, as all values in the right subtree are too large.

7. **Trim Left Subtree Call**
	```cpp
	    root->left = trimBST(root->left, low, high);
	```
	Recursively call `trimBST` to trim the left child of the current node, ensuring the left subtree only contains nodes within the range.

8. **Right Subtree Recursion**
	```cpp
	    root->right= trimBST(root->right, low, high);
	```
	Recursively call `trimBST` to trim the right child of the current node, ensuring the right subtree only contains nodes within the range.

9. **Return Root**
	```cpp
	    return root;
	```
	Return the current node (root) after its left and right subtrees have been trimmed, ensuring all nodes in the subtree are within the given range.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we may need to visit every node in the tree once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to recursive calls on the call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/trim-a-binary-search-tree/description/)

---
{{< youtube jwt5mTjEXGc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
