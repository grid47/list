
+++
authors = ["grid47"]
title = "Leetcode 1038: Binary Search Tree to Greater Sum Tree"
date = "2024-07-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1038: Binary Search Tree to Greater Sum Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FiGdEA4herM"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi/FiGdEA4herM/maxresdefault.jpg"
comments = true
+++



---
Given the root of a Binary Search Tree (BST), convert it into a Greater Tree where each node's value is updated to the sum of its original value and all the values greater than it in the BST. The transformation should preserve the BST structure.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are provided with the root of a Binary Search Tree. The nodes of the tree are distinct integers, and the task is to transform the tree as described.
- **Example:** `Input: root = [5,3,8,1,4,7,10]`
- **Constraints:**
	- 1 <= number of nodes <= 100
	- 0 <= Node.val <= 100
	- All node values are distinct

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the Greater Tree after transformation.
- **Example:** `Output: [30,36,21,36,35,26,15]`
- **Constraints:**
	- The tree should be transformed such that each node's value is the sum of its original value and all greater values in the BST.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to transform the BST into a Greater Tree by accumulating the sum of all values greater than a node's value.

- 1. Perform a reverse in-order traversal of the BST, starting from the rightmost node.
- 2. Accumulate the sum of nodes encountered during the traversal, updating each node's value.
- 3. Continue the traversal until all nodes are visited.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid Binary Search Tree (BST) with unique values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]`  \
  **Explanation:** After converting the BST to a Greater Tree, the new root tree will be [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8], where each node is updated to the sum of its original value and the values greater than it.

- **Input:** `Input: root = [0,null,1]`  \
  **Explanation:** After the transformation, the tree becomes [1,null,1], where the only non-zero transformation is at the root node.

{{< dots >}}
## Approach 🚀
The approach uses reverse in-order traversal to accumulate the sum of nodes in the BST and transform it into the Greater Tree.

### Initial Thoughts 💭
- This problem requires a depth-first traversal of the tree, visiting the nodes in descending order (right to left).
- By accumulating the values as we traverse, we can transform each node to include the sum of greater nodes.
- A reverse in-order traversal works efficiently for this task because it visits nodes in decreasing order, allowing us to accumulate the sum of greater values before updating each node.
{{< dots >}}
### Edge Cases 🌐
- An empty tree (root is null) should simply return null.
- For large trees (close to 100 nodes), the algorithm should still function efficiently due to the O(n) time complexity of the traversal.
- The algorithm handles trees with nodes having values from 0 to 100.
- Ensure the tree structure remains a valid BST after transformation.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int pre;
public:
TreeNode* bstToGst(TreeNode* root) {
    if(root->right) bstToGst(root->right);
    pre = root->val = pre + root->val;
    if(root->left) bstToGst(root->left);
    return root;
}
```

This is the code for converting a Binary Search Tree (BST) to a Greater Sum Tree (GST), where each node contains the sum of all nodes greater than or equal to itself.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Define a class 'Solution' to implement the function for converting a BST to a GST.

2. **Variable Declaration**
	```cpp
	int pre;
	```
	Declare an integer 'pre' that will store the cumulative sum of node values during the tree traversal.

3. **Access Modifier**
	```cpp
	public:
	```
	Define the public section of the class, where the function 'bstToGst' will be declared.

4. **Function Definition**
	```cpp
	TreeNode* bstToGst(TreeNode* root) {
	```
	Define the function 'bstToGst' which will traverse the BST in reverse in-order and modify each node to store the GST value.

5. **Right Subtree Traversal**
	```cpp
	    if(root->right) bstToGst(root->right);
	```
	Recursively traverse the right subtree of the node, ensuring the largest nodes are processed first.

6. **Node Value Update**
	```cpp
	    pre = root->val = pre + root->val;
	```
	Update the node's value by adding the current value of 'pre' (which holds the cumulative sum) and assign it to 'pre'. This ensures the node gets the sum of all greater nodes.

7. **Left Subtree Traversal**
	```cpp
	    if(root->left) bstToGst(root->left);
	```
	Recursively traverse the left subtree after updating the current node, ensuring all nodes are visited.

8. **Return Root**
	```cpp
	    return root;
	```
	Return the modified root node of the tree after all values have been updated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree. This is because we visit each node once during the traversal.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree. In the worst case, for a skewed tree, the height is O(n), but in a balanced tree, it is O(log n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/)

---
{{< youtube FiGdEA4herM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
