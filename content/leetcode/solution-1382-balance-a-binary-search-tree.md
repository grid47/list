
+++
authors = ["grid47"]
title = "Leetcode 1382: Balance a Binary Search Tree"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1382: Balance a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Divide and Conquer","Greedy","Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "0KGdtzgL9Ec"
youtube_upload_date="2021-01-28"
youtube_thumbnail="https://i.ytimg.com/vi/0KGdtzgL9Ec/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary search tree (BST), return a balanced BST containing the same node values. A balanced BST is one where the depth of the left and right subtrees of every node never differ by more than 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary search tree (BST) represented as an array where each element is a node of the tree.
- **Example:** `Input: root = [1, null, 2, null, 3, null, 4]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 10,000.
	- The value of each node is between 1 and 100,000.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a balanced binary search tree (BST) containing the same node values from the input tree. The tree should be balanced in such a way that the difference in height between the left and right subtrees of any node is at most 1.
- **Example:** `Output: [2, 1, 3, null, null, null, 4]`
- **Constraints:**
	- The tree must be balanced according to the problem definition.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to return a balanced BST that contains the same node values as the input BST.

- 1. Perform an inorder traversal on the BST to get the nodes in sorted order.
- 2. Use the sorted nodes to construct a balanced BST by recursively selecting the middle node as the root and dividing the remaining nodes into left and right subtrees.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a binary search tree (BST).
- A balanced BST is defined as a tree where the height difference between the left and right subtrees of every node is at most 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, null, 2, null, 3, null, 4]`  \
  **Explanation:** The input tree is right-skewed. To balance it, we first extract the nodes in sorted order: [1, 2, 3, 4]. We then construct a new tree with the middle element (2) as the root, and recursively build left and right subtrees from the remaining nodes.

{{< dots >}}
## Approach 🚀
The approach involves converting the input BST to an inorder array and then using this sorted array to build a balanced BST by recursively selecting the middle element as the root of each subtree.

### Initial Thoughts 💭
- The tree is unbalanced, and we need to rearrange it to create a balanced structure.
- Inorder traversal of a BST results in a sorted list of node values.
- Once we have the sorted array of nodes, we can use it to recursively build a balanced tree.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return null.
- Ensure that the solution handles large trees (up to 10,000 nodes) efficiently.
- The values of the nodes are between 1 and 100,000, which means that balancing the tree should not depend on specific values.
- The solution should not exceed time limits for large trees with up to 10,000 nodes.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> arr;
public:
TreeNode* balanceBST(TreeNode* root) {
    inorder (root);
    return reform(0, arr.size()-1);
}

void inorder (TreeNode* root) {
    if(root == NULL ) return;
    inorder (root->left);
    arr.push_back(root->val);
    inorder (root->right);
}

 TreeNode* reform(int l, int r) {
    if (l > r) return NULL;
 int mid = (l + r)/2;
 TreeNode* node = new TreeNode(arr[mid]);
 node->left = reform (l, mid -1);
 node->right= reform (mid +1, r);
 return node;
}
```

This solution provides a balanced binary search tree (BST) by performing an in-order traversal to store the values of the original tree in a vector. It then reuses the sorted values to construct a balanced tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Define a class Solution where the main logic for balancing the BST will be implemented.

2. **Data Structures**
	```cpp
	vector<int> arr;
	```
	A vector is used to store the elements of the BST during the in-order traversal.

3. **Access Modifiers**
	```cpp
	public:
	```
	The public section of the class where the methods will be defined for solving the problem.

4. **Function Definition**
	```cpp
	TreeNode* balanceBST(TreeNode* root) {
	```
	The balanceBST function receives the root of the tree and balances the BST by calling inorder and reform functions.

5. **Traversal**
	```cpp
	    inorder (root);
	```
	Call the inorder function to perform an in-order traversal of the binary tree and store its values.

6. **Return Statement**
	```cpp
	    return reform(0, arr.size()-1);
	```
	Invoke the reform function to build a balanced BST using the values stored in arr.

7. **Function Definition**
	```cpp
	void inorder (TreeNode* root) {
	```
	The inorder function is used to traverse the tree in in-order fashion and store the values in the arr vector.

8. **Base Case**
	```cpp
	    if(root == NULL ) return;
	```
	Base case for the recursion: if the node is NULL, return immediately.

9. **Traversal**
	```cpp
	    inorder (root->left);
	```
	Recursive call to traverse the left subtree of the node.

10. **Store Data**
	```cpp
	    arr.push_back(root->val);
	```
	Store the value of the current node in the arr vector.

11. **Traversal**
	```cpp
	    inorder (root->right);
	```
	Recursive call to traverse the right subtree of the node.

12. **Function Definition**
	```cpp
	 TreeNode* reform(int l, int r) {
	```
	The reform function recursively builds a balanced binary tree using the sorted values stored in arr.

13. **Base Case**
	```cpp
	    if (l > r) return NULL;
	```
	Base case for recursion: if the left index exceeds the right, return NULL (no more nodes to add).

14. **Calculate Middle**
	```cpp
	 int mid = (l + r)/2;
	```
	Find the middle index of the current range to select the root of the subtree.

15. **Node Creation**
	```cpp
	 TreeNode* node = new TreeNode(arr[mid]);
	```
	Create a new tree node with the middle value from the arr vector.

16. **Recursive Call**
	```cpp
	 node->left = reform (l, mid -1);
	```
	Recursively build the left subtree with the values between the current left index and mid-1.

17. **Recursive Call**
	```cpp
	 node->right= reform (mid +1, r);
	```
	Recursively build the right subtree with the values between mid+1 and the current right index.

18. **Return Statement**
	```cpp
	 return node;
	```
	Return the newly created node as the root of the subtree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the tree. This occurs because both the inorder traversal and the tree-building steps require O(n) time.
- **Average Case:** O(n) in most cases.
- **Worst Case:** O(n) in all cases.

Both the inorder traversal and the tree reconstruction steps have a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(n) in all cases.
- **Worst Case:** O(n), where n is the number of nodes in the tree. This is due to the storage required for the sorted array of node values.

The space complexity is O(n) due to the space needed for storing the node values during the inorder traversal and the recursive calls.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/balance-a-binary-search-tree/description/)

---
{{< youtube 0KGdtzgL9Ec >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
