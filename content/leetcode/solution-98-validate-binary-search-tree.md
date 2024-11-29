
+++
authors = ["grid47"]
title = "Leetcode 98: Validate Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 98: Validate Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp"
youtube = "s6ATEkipzow"
youtube_upload_date="2021-01-08"
youtube_thumbnail="https://i.ytimg.com/vi/s6ATEkipzow/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp" 
    alt="A glowing tree with balanced nodes, radiating a sense of order and validation."
    caption="Solution to LeetCode 98: Validate Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. Your task is to determine whether the tree is a valid binary search tree (BST). A binary search tree is valid if for every node in the tree, the value of all nodes in its left subtree are less than its own value, and the value of all nodes in its right subtree are greater than its own value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of a binary tree.
- **Example:** `Input: root = [3,2,4,1,5]`
- **Constraints:**
	- The tree contains between 1 and 10^4 nodes.
	- -2^31 <= Node.val <= 2^31 - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the tree is a valid binary search tree, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The function must return true if the tree is a valid BST, and false otherwise.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify if the binary tree satisfies the conditions of a binary search tree at every node.

- Traverse the tree in an inorder fashion.
- Check if the node values are in strictly increasing order. If any node violates this rule, return false.
- If the traversal completes without issues, return true.
{{< dots >}}
### Problem Assumptions ✅
- The tree is valid and can be represented in the form of a binary tree with integer values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [3,2,4,1,5]`  \
  **Explanation:** In this case, the tree is a valid binary search tree because the left subtree contains values less than 3, and the right subtree contains values greater than 3, with the same rule applying recursively to all nodes.

- **Input:** `Input: root = [5,1,4,null,null,3,6]`  \
  **Explanation:** In this case, the tree is not a valid binary search tree because the right child of node 5 is 4, which is less than 5, violating the BST rule.

{{< dots >}}
## Approach 🚀
We will use an inorder traversal to verify if the binary tree is a valid BST. In an inorder traversal of a BST, the values of nodes should appear in strictly increasing order. By comparing each node with the previously visited node, we can determine if the tree is a valid BST.

### Initial Thoughts 💭
- If the tree is a valid BST, an inorder traversal should yield a sorted list of node values.
- We will use a stack-based iterative inorder traversal to ensure we efficiently check all nodes of the tree.
{{< dots >}}
### Edge Cases 🌐
- An empty tree is considered a valid BST, so return true.
- For large trees with up to 10^4 nodes, the solution must be efficient and handle the constraints effectively.
- Ensure that nodes with extreme values (-2^31 and 2^31 - 1) are handled correctly.
- Ensure the solution works efficiently within the given constraints.
{{< dots >}}
## Code 💻
```cpp
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* node = root, *prv = NULL;
    // stk.push(root);
    while(!stk.empty() || node) {
        if(node) {
            stk.push(node);
            node = node->left;
        } else {
            node = stk.top();
            stk.pop();
            if(prv != NULL && prv -> val >= node->val)
                return false;
            prv = node;
            node = node->right;
        }
    }
    return true;
}
```

This code validates if a given binary tree is a Binary Search Tree (BST) using an iterative in-order traversal approach with a stack.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Stack Operations**
	```cpp
	bool isValidBST(TreeNode* root) {
	```
	Start of the function. We're defining a function to check if a binary tree is a valid Binary Search Tree (BST).

2. **Stack Initialization**
	```cpp
	    stack<TreeNode*> stk;
	```
	Here we initialize a stack to help with the iterative in-order traversal of the tree.

3. **Variable Initialization**
	```cpp
	    TreeNode* node = root, *prv = NULL;
	```
	We initialize two pointers: 'node' to traverse the tree and 'prv' to keep track of the previous node in the in-order traversal.

4. **While Loop**
	```cpp
	    while(!stk.empty() || node) {
	```
	We start a while loop that continues as long as there are nodes to process, either in the stack or in the 'node' variable.

5. **If Condition**
	```cpp
	        if(node) {
	```
	If the current node is not null, we process it by pushing it onto the stack.

6. **Stack Push**
	```cpp
	            stk.push(node);
	```
	We push the current node onto the stack to visit its left subtree next.

7. **Left Traversal**
	```cpp
	            node = node->left;
	```
	Move to the left child of the current node to continue the in-order traversal.

8. **Else Condition**
	```cpp
	        } else {
	```
	If there are no more left children to visit (i.e., node is null), we process the node at the top of the stack.

9. **Stack Top**
	```cpp
	            node = stk.top();
	```
	Retrieve the top node from the stack, which is the next node in the in-order traversal.

10. **Stack Pop**
	```cpp
	            stk.pop();
	```
	Pop the node from the stack after processing it.

11. **BST Validation**
	```cpp
	            if(prv != NULL && prv -> val >= node->val)
	```
	We check if the previous node's value is greater than or equal to the current node's value. If it is, the tree is not a valid BST.

12. **Return False**
	```cpp
	                return false;
	```
	If the previous node's value is greater than or equal to the current node's value, return false because the tree violates BST properties.

13. **Update Previous Node**
	```cpp
	            prv = node;
	```
	Update the 'prv' pointer to the current node, which will be used for comparison in the next iteration.

14. **Move Right**
	```cpp
	            node = node->right;
	```
	Move to the right child of the current node to continue the in-order traversal.

15. **End of While**
	```cpp
	    }
	```
	End of the while loop, indicating that all nodes have been processed.

16. **Return True**
	```cpp
	    return true;
	```
	If no violations were found, return true indicating the tree is a valid BST.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree, because we visit each node once during the inorder traversal.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case when the tree is skewed and all nodes are pushed onto the stack. In the best case, for a balanced tree, the space complexity is O(h), where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-binary-search-tree/description/)

---
{{< youtube s6ATEkipzow >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
