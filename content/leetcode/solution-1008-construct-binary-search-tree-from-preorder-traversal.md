
+++
authors = ["grid47"]
title = "Leetcode 1008: Construct Binary Search Tree from Preorder Traversal"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1008: Construct Binary Search Tree from Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Tree","Binary Search Tree","Monotonic Stack","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "30WqiTVp8Kc"
youtube_upload_date="2020-04-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/30WqiTVp8Kc/maxresdefault.webp"
comments = true
+++



---
You are given an array representing the preorder traversal of a binary search tree (BST). Your task is to construct the BST from this preorder traversal and return the root of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers representing the preorder traversal of a BST. The array will have a length of at least 1 and at most 100, with each integer between 1 and 1000.
- **Example:** `preorder = [10, 5, 1, 7, 15, 12]`
- **Constraints:**
	- 1 <= preorder.length <= 100
	- 1 <= preorder[i] <= 1000
	- All elements in the preorder array are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the binary search tree constructed from the given preorder traversal.
- **Example:** `Output: [10,5,15,1,7,null,12]`
- **Constraints:**
	- The output is the root of the binary search tree in level-order traversal.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to construct a binary search tree from the preorder traversal. Each node in the tree should satisfy the BST property where the left child is less than the parent and the right child is greater than the parent.

- Start with the first element of the preorder array as the root of the tree.
- For each subsequent element, place it in the correct position in the tree following the BST rules.
- Continue this process until all elements are placed in the tree.
{{< dots >}}
### Problem Assumptions ✅
- The preorder array contains unique values and forms a valid BST.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: preorder = [10, 5, 1, 7, 15, 12]`  \
  **Explanation:** In this case, we can construct the following BST: [10, 5, 15, 1, 7, null, 12]. The first element 10 becomes the root, then 5 goes to the left of 10, 1 goes to the left of 5, and so on.

- **Input:** `Input: preorder = [15, 10, 5, 12, 20, 17]`  \
  **Explanation:** For this input, the BST would look like [15, 10, 20, 5, 12, null, 17]. Starting with 15 as the root, 10 goes to the left, 20 goes to the right, and so on.

{{< dots >}}
## Approach 🚀
We can use the preorder traversal of a BST to reconstruct the tree. We start with the first element as the root and use the properties of BSTs to place each subsequent element in the correct position.

### Initial Thoughts 💭
- We need to ensure that each element is inserted in the correct position based on the BST rules.
- The key idea is to use a recursive approach to insert nodes into the tree while maintaining the BST property.
{{< dots >}}
### Edge Cases 🌐
- The input array will never be empty, as per the problem constraints.
- The solution should be optimized to handle the maximum input size (up to 100 elements).
- If all values are large (e.g., all greater than 500), the BST structure should still be correct.
- The input array will always contain unique values, so there is no need to handle duplicates.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int i = 0;
public:
TreeNode* bstFromPreorder(vector<int>& pre, int bound = INT_MAX) {
    if(i == pre.size() || pre[i] > bound) return NULL;
    
    TreeNode* root = new TreeNode(pre[i++]);
    root->left = bstFromPreorder(pre, root->val);
    root->right = bstFromPreorder(pre, bound);
    return root;
}


```

This function builds a Binary Search Tree (BST) from the given preorder traversal of the tree. It recursively constructs the tree nodes by following the preorder traversal rules.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Declares a Solution class to house the method for building the BST from the preorder traversal.

2. **Variable Initialization**
	```cpp
	int i = 0;
	```
	Initializes a class member variable i to track the current index in the preorder vector while recursively constructing the BST.

3. **Access Specifier**
	```cpp
	public:
	```
	Specifies that the following members are public and can be accessed from outside the class.

4. **Function Declaration**
	```cpp
	TreeNode* bstFromPreorder(vector<int>& pre, int bound = INT_MAX) {
	```
	Declares the function `bstFromPreorder` which takes a vector of integers `pre` (representing the preorder traversal of a BST) and an optional `bound` parameter to limit node values during recursion.

5. **Base Case**
	```cpp
	    if(i == pre.size() || pre[i] > bound) return NULL;
	```
	Checks if the current index has reached the end of the preorder vector or if the current node value exceeds the allowed bound, indicating that no more nodes can be added under this subtree.

6. **Node Creation**
	```cpp
	    TreeNode* root = new TreeNode(pre[i++]);
	```
	Creates a new TreeNode with the current value from the preorder vector and increments the index i.

7. **Left Subtree Construction**
	```cpp
	    root->left = bstFromPreorder(pre, root->val);
	```
	Recursively constructs the left subtree by passing the current node's value as the new bound, ensuring that the left child is smaller than the current node.

8. **Right Subtree Construction**
	```cpp
	    root->right = bstFromPreorder(pre, bound);
	```
	Recursively constructs the right subtree with the original bound, ensuring that the right child is larger than the current node.

9. **Return Statement**
	```cpp
	    return root;
	```
	Returns the root of the current subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n^2)

The time complexity is O(n) in the best case when the tree is balanced, but it can be O(n^2) in the worst case when the tree is skewed (e.g., a sorted array).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and the space used to store the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/)

---
{{< youtube 30WqiTVp8Kc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
