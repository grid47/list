
+++
authors = ["grid47"]
title = "Leetcode 572: Subtree of Another Tree"
date = "2024-09-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 572: Subtree of Another Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","String Matching","Binary Tree","Hash Function"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/572.webp"
youtube = "Qk7_vGWUMMQ"
youtube_upload_date="2022-06-28"
youtube_thumbnail="https://i.ytimg.com/vi/Qk7_vGWUMMQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/572.webp" 
    alt="A tree being checked for its subtree, with the subtree softly glowing as it is found."
    caption="Solution to LeetCode 572: Subtree of Another Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the roots of two binary trees, root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise. A subtree of a binary tree consists of a node in the tree and all of this node's descendants.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two binary trees, represented by their root nodes.
- **Example:** `Input: root = [1, 2, 3, 4, 5], subRoot = [2, 4, 5]`
- **Constraints:**
	- 1 <= Number of nodes in root <= 2000
	- 1 <= Number of nodes in subRoot <= 1000
	- -10^4 <= node values <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: true if a subtree of root matches subRoot, false otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The result should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if any subtree in root matches subRoot in both structure and values.

- Start by checking if the root node matches the subRoot tree using a helper function to compare the trees.
- If the root node doesn't match, recursively check the left and right subtrees of root.
- If a match is found, return true; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- Both root and subRoot are valid binary trees with integer values.
- The function should handle large trees up to the input size limits efficiently.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, 2, 3, 4, 5], subRoot = [2, 4, 5]`  \
  **Explanation:** The subtree rooted at node 2 in root matches the structure and values of subRoot, so the output is true.

- **Input:** `Input: root = [1, 2, 3, 4, 5], subRoot = [2, 3, 5]`  \
  **Explanation:** There is no subtree of root that matches subRoot exactly, so the output is false.

{{< dots >}}
## Approach 🚀
The approach is to recursively traverse the root tree and for each node, check if it matches the structure and node values of subRoot.

### Initial Thoughts 💭
- To solve this, we need to check for every node in root if it is the root of a subtree that matches subRoot.
- We will define a helper function to compare two trees. If the current node matches, we'll further check its left and right subtrees.
{{< dots >}}
### Edge Cases 🌐
- The input trees will always have at least one node due to the problem constraints.
- The function should efficiently handle large trees up to the input size limits.
- Both root and subRoot might contain negative values, but this doesn't affect the logic.
- The solution should be optimized for large input sizes.
{{< dots >}}
## Code 💻
```cpp
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return false;
    if(match(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
}

bool match(TreeNode* r1, TreeNode* r2) {
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;
    if(r1->val != r2->val) return false;
    return match(r1->left, r2->left) &&
        match(r1->right, r2->right);
}
```

The `isSubtree` function checks if a binary tree `subRoot` is a subtree of another binary tree `root`. The helper function `match` checks whether two trees are identical, node by node.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	```
	Defines the function `isSubtree` which checks if `subRoot` is a subtree of `root`. It returns `true` if `subRoot` is a subtree, otherwise `false`.

2. **Base Case - Null Root**
	```cpp
	    if(!root) return false;
	```
	Checks if the root of the tree is `null`. If it is, the function returns `false` because an empty tree can't contain any subtree.

3. **Check for Match**
	```cpp
	    if(match(root, subRoot)) return true;
	```
	Calls the `match` function to check if the current node of `root` and `subRoot` match. If they do, the function returns `true`, indicating `subRoot` is a subtree starting at the current node.

4. **Recursion - Check Left Subtree**
	```cpp
	    return isSubtree(root->left, subRoot) ||
	```
	Recursively checks if `subRoot` is a subtree of the left child of `root`. If the left subtree contains `subRoot`, the function will return `true`.

5. **Recursion - Check Right Subtree**
	```cpp
	            isSubtree(root->right, subRoot);
	```
	Recursively checks if `subRoot` is a subtree of the right child of `root`. If the right subtree contains `subRoot`, the function will return `true`.

6. **Function Definition**
	```cpp
	bool match(TreeNode* r1, TreeNode* r2) {
	```
	Defines the helper function `match`, which checks if two binary trees `r1` and `r2` are identical.

7. **Base Case - Both Null**
	```cpp
	    if(!r1 && !r2) return true;
	```
	Checks if both nodes `r1` and `r2` are `null`. If both are `null`, the trees are considered identical (both empty).

8. **Base Case - One Null**
	```cpp
	    if(!r1 || !r2) return false;
	```
	Checks if only one of the nodes is `null`. If one node is `null` and the other is not, the trees are not identical.

9. **Node Value Comparison**
	```cpp
	    if(r1->val != r2->val) return false;
	```
	Compares the values of the current nodes `r1` and `r2`. If the values are different, the trees are not identical.

10. **Recursive Check for Left and Right Subtrees**
	```cpp
	    return match(r1->left, r2->left) &&
	```
	Recursively checks if the left children of `r1` and `r2` are identical. The function returns `true` if both left subtrees are identical.

11. **Recursive Check for Right Subtrees**
	```cpp
	        match(r1->right, r2->right);
	```
	Recursively checks if the right children of `r1` and `r2` are identical. The function returns `true` if both right subtrees are identical.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n * m)

In the worst case, we check every node in root, and for each node, we compare subRoot, resulting in a time complexity of O(n * m), where n is the number of nodes in root and m is the number of nodes in subRoot.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h) due to the recursion stack, where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subtree-of-another-tree/description/)

---
{{< youtube Qk7_vGWUMMQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
