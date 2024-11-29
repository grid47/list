
+++
authors = ["grid47"]
title = "Leetcode 998: Maximum Binary Tree II"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 998: Maximum Binary Tree II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9Mr8YfV6hA4"
youtube_upload_date="2024-01-21"
youtube_thumbnail="https://i.ytimg.com/vi/9Mr8YfV6hA4/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a maximum binary tree and an integer val. The task is to insert val into the tree by constructing a new maximum binary tree with a list that contains val appended to the original list used to construct the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree root, which is constructed from a list a, and an integer val to be appended to this list to form a new binary tree.
- **Example:** `root = [10, 4, 7, null, null, 5], val = 12`
- **Constraints:**
	- 1 <= Node.val <= 100
	- 1 <= val <= 100
	- The number of nodes in the tree is between 1 and 100.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the newly constructed maximum binary tree after appending val to the original tree's list.
- **Example:** `Output: [12, 10, null, 4, 7, null, null, 5]`
- **Constraints:**
	- The tree must maintain the maximum binary tree property after insertion.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to create a new maximum binary tree by appending val to the original list and constructing a new tree following the properties of a maximum binary tree.

- Step 1: Append the new value val to the original list a.
- Step 2: Reconstruct the maximum binary tree using the updated list b.
- Step 3: Return the root of the newly constructed tree.
{{< dots >}}
### Problem Assumptions ✅
- The tree is always constructed from a unique set of values.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [10, 4, 7, null, null, 5], val = 12`  \
  **Explanation:** In this example, after appending 12 to the list [4, 10, 7, 5], the new tree has 12 as the root.

- **Input:** `root = [15, 8, 12, null, 10], val = 14`  \
  **Explanation:** In this case, after appending 14 to the list [8, 15, 12, 10], the new tree has 14 as the root.

{{< dots >}}
## Approach 🚀
The approach involves modifying the original list by appending val and then reconstructing the binary tree following the maximum binary tree rules.

### Initial Thoughts 💭
- We need to reconstruct the tree with a new root after appending val to the list.
- This approach is similar to the original tree construction, except we need to append the new value first.
{{< dots >}}
### Edge Cases 🌐
- The tree is never empty as per the constraints.
- Ensure that the solution works for trees with up to 100 nodes.
- If the value val is larger than any existing node values, it should become the root.
- All values in the tree are unique, so no duplicates will exist.
{{< dots >}}
## Code 💻
```cpp
TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if(root != NULL && root->val > val) {
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
    TreeNode* node = new TreeNode(val);
    node->left = root;
    return node;
}
```

This function inserts a new value into a max binary tree. If the new value is less than the root's value, it gets inserted in the right subtree. Otherwise, it becomes the new root of the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
	```
	Defines the function `insertIntoMaxTree`, which takes a root node of a binary tree and a value `val` to insert in the tree following max-heap properties.

2. **Condition Check**
	```cpp
	    if(root != NULL && root->val > val) {
	```
	Checks if the root is not null and its value is greater than the value to be inserted. This ensures that the value is placed in the right subtree if it’s smaller than the current root.

3. **Recursive Call**
	```cpp
	        root->right = insertIntoMaxTree(root->right, val);
	```
	Recursively calls the function on the right child of the root to insert the value into the correct position.

4. **Return Root**
	```cpp
	        return root;
	```
	Returns the root node after the insertion, maintaining the structure of the max tree.

5. **Node Creation**
	```cpp
	    TreeNode* node = new TreeNode(val);
	```
	Creates a new node with the given value `val`.

6. **Assign Left Child**
	```cpp
	    node->left = root;
	```
	Sets the newly created node’s left child to be the current root. This node becomes the new root of the tree.

7. **Return New Root**
	```cpp
	    return node;
	```
	Returns the newly created node as the new root of the tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - Constructing the tree from the list of n elements.
- **Average Case:** O(n) - Similar to the best case as we rebuild the tree from the updated list.
- **Worst Case:** O(n) - Even for the worst case, the complexity remains linear as we rebuild the tree.

Time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(n) - Even in the best case, space complexity remains linear.
- **Worst Case:** O(n) - The space complexity is proportional to the size of the tree.

The space complexity is linear in terms of the number of nodes in the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-binary-tree-ii/description/)

---
{{< youtube 9Mr8YfV6hA4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
