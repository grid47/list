
+++
authors = ["grid47"]
title = "Leetcode 538: Convert BST to Greater Tree"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 538: Convert BST to Greater Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp"
youtube = "AFDxiYO9XzY"
youtube_upload_date="2023-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/AFDxiYO9XzY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/538.webp" 
    alt="A binary search tree where each node is gradually updated to a greater tree, with each transformation softly highlighted."
    caption="Solution to LeetCode 538: Convert BST to Greater Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a Binary Search Tree (BST), convert it into a Greater Tree where every node’s value is replaced by the sum of all greater node values in the BST plus its original value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each input consists of a binary search tree represented by its root. The nodes of the tree contain integer values.
- **Example:** `Input: root = [5, 2, 13]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 10^4].
	- Each node value is an integer within the range [-10^4, 10^4].
	- All node values are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the binary search tree after transforming it into the Greater Tree.
- **Example:** `Output: [18, 20, 13]`
- **Constraints:**
	- The output should be a valid Binary Search Tree where each node’s value is the sum of all greater node values plus its original value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the BST into a Greater Tree by updating each node's value.

- Perform a reverse inorder traversal (right, node, left) to access nodes in descending order.
- Accumulate the sum of node values greater than the current node’s value.
- Update the current node's value by adding the accumulated sum.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid Binary Search Tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5, 2, 13]`  \
  **Explanation:** In this example, after transforming the BST into a Greater Tree, the node with value 5 becomes 18, the node with value 2 becomes 20, and the node with value 13 stays the same.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to traverse the BST in descending order and update each node’s value with the sum of all greater node values.

### Initial Thoughts 💭
- We can solve this problem efficiently by using a reverse inorder traversal of the BST.
- In reverse inorder traversal, we visit the right child first, then the node itself, followed by the left child. This way, we encounter the largest nodes first.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty, return null.
- Ensure that the solution can handle trees with up to 10^4 nodes.
- Handle trees with negative node values correctly.
- The tree is guaranteed to be a valid binary search tree.
{{< dots >}}
## Code 💻
```cpp
class Solution {

int sum = 0;

public:

TreeNode* convertBST(TreeNode* root) {
    convert(root);
    return root;
}

void convert(TreeNode* root) {
    if(!root) return;
    convert(root->right);
    root->val += sum;
    sum = root->val;
    convert(root->left);
}

```

This code defines a solution for converting a Binary Search Tree (BST) into a Greater Tree, where each node's value is replaced by the sum of all values greater than or equal to the node's value in the original BST.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the `Solution` class which will contain the method to convert a BST to a Greater Tree.

2. **Variable Initialization**
	```cpp
	int sum = 0;
	```
	Declares an integer variable `sum` and initializes it to 0. This variable will store the cumulative sum during the traversal.

3. **Access Modifier**
	```cpp
	public:
	```
	Indicates the start of the public access modifier, making the following methods accessible from outside the class.

4. **Function Definition**
	```cpp
	TreeNode* convertBST(TreeNode* root) {
	```
	Defines the `convertBST` method which takes the root of a Binary Search Tree as input and returns the root of the converted Greater Tree.

5. **Function Call**
	```cpp
	    convert(root);
	```
	Calls the private helper method `convert` to perform the conversion on the BST.

6. **Return Statement**
	```cpp
	    return root;
	```
	Returns the root of the modified BST (now a Greater Tree) after the conversion.

7. **Function Definition**
	```cpp
	void convert(TreeNode* root) {
	```
	Defines the helper method `convert`, which is used to recursively traverse the tree and accumulate the sum of node values.

8. **Base Case**
	```cpp
	    if(!root) return;
	```
	Checks if the current node is null. If so, the function returns without doing anything.

9. **Recursive Call**
	```cpp
	    convert(root->right);
	```
	Recursively calls the `convert` method on the right subtree to process all nodes in the right subtree first (reverse inorder traversal).

10. **Node Value Update**
	```cpp
	    root->val += sum;
	```
	Adds the current value of `sum` to the node's value. This ensures each node's value is updated with the cumulative sum of all greater nodes.

11. **Sum Update**
	```cpp
	    sum = root->val;
	```
	Updates the `sum` variable to the current node's value, so it can be used by subsequent nodes in the traversal.

12. **Recursive Call**
	```cpp
	    convert(root->left);
	```
	Recursively calls the `convert` method on the left subtree to process all nodes in the left subtree after updating the current node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we perform a single traversal of the tree, visiting each node once.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree. This accounts for the recursive stack in a depth-first traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)

---
{{< youtube AFDxiYO9XzY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
