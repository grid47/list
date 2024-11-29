
+++
authors = ["grid47"]
title = "Leetcode 1367: Linked List in Binary Tree"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1367: Linked List in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OaA9MgG00AE"
youtube_upload_date="2024-09-07"
youtube_thumbnail="https://i.ytimg.com/vi/OaA9MgG00AE/maxresdefault.jpg"
comments = true
+++



---
You are given a binary tree and a linked list. Determine if there exists a downward path in the binary tree that matches all elements of the linked list starting from its head node. A downward path means starting from any node in the binary tree and following child nodes downwards.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a linked list and a binary tree. The linked list is represented as an array of values and the binary tree is represented as a root node of a binary tree structure.
- **Example:** `head = [4, 2, 8], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]`
- **Constraints:**
	- The number of nodes in the binary tree will be in the range [1, 2500].
	- The number of nodes in the linked list will be in the range [1, 100].
	- 1 <= Node.val <= 100 for each node in both the linked list and binary tree.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return True if there exists a downward path in the binary tree that matches all elements of the linked list starting from its head node, otherwise return False.
- **Example:** `True`
- **Constraints:**
	- The result will be a boolean value: True or False.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine if there exists a downward path in the binary tree that matches all elements of the linked list starting from the head node.

- Perform a depth-first search (DFS) to check if the current node value matches the head of the linked list.
- If a match is found, recursively check the left and right child nodes to see if the subsequent linked list elements match the downward path.
- If no match is found at any step, return False.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree and linked list contain valid values as per the problem constraints.
- The input tree and linked list are not null.
{{< dots >}}
## Examples 🧩
- **Input:** `head = [4, 2, 8], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]`  \
  **Explanation:** The linked list elements [4, 2, 8] correspond to a downward path starting from node 4, then node 2, and then node 8 in the binary tree.

- **Input:** `head = [1, 4, 2, 6], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]`  \
  **Explanation:** The linked list elements [1, 4, 2, 6] form a valid downward path in the binary tree, matching the nodes from root down to 6.

{{< dots >}}
## Approach 🚀
The approach is to perform a depth-first search (DFS) to check for downward paths in the binary tree that match the linked list values.

### Initial Thoughts 💭
- A DFS approach can be used to search the binary tree for matching downward paths.
- At each node, check if it matches the current head of the linked list. If so, recursively check the left and right subtrees.
{{< dots >}}
### Edge Cases 🌐
- If the binary tree is empty, return False.
- Ensure the solution handles trees with up to 2500 nodes efficiently.
- If there is only one element in the linked list, check if that element exists as a downward path in the tree.
- The solution must efficiently handle the maximum constraints for both tree and list sizes.
{{< dots >}}
## Code 💻
```cpp
bool isSubPath(ListNode* head, TreeNode* root) {
    if(head == NULL) return true;
    if(root == NULL) return false;
    return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

bool dfs(ListNode* head, TreeNode* root) {
    if(head == NULL) return true;
    if(root == NULL) return false;
    return (head->val == root->val) && (dfs(head->next, root->left) || dfs(head->next, root->right));
}
```

This code checks if there is a path in a binary tree that matches the values of a linked list from head to tail, recursively comparing values along the tree nodes and the linked list nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isSubPath(ListNode* head, TreeNode* root) {
	```
	The function 'isSubPath' takes two parameters: a linked list 'head' and a binary tree 'root'. It returns true if a path from the linked list exists in the binary tree.

2. **Base Case for Linked List**
	```cpp
	    if(head == NULL) return true;
	```
	This is a base case where if the linked list 'head' is NULL, it indicates the end of the list has been reached, and thus the path has been successfully matched.

3. **Base Case for Binary Tree**
	```cpp
	    if(root == NULL) return false;
	```
	This is a base case where if the binary tree 'root' is NULL, it means there is no path to follow, so we return false.

4. **Recursive Search**
	```cpp
	    return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
	```
	The function recursively checks if the linked list matches starting from the current node in the binary tree or its left or right children.

5. **Function Declaration**
	```cpp
	bool dfs(ListNode* head, TreeNode* root) {
	```
	The function 'dfs' is a helper function that recursively checks whether the linked list starting from 'head' can match the binary tree starting from 'root'.

6. **Base Case for Linked List**
	```cpp
	    if(head == NULL) return true;
	```
	This is a base case where if the linked list 'head' is NULL, it indicates that the linked list has been completely matched.

7. **Base Case for Binary Tree**
	```cpp
	    if(root == NULL) return false;
	```
	This base case checks if the binary tree 'root' is NULL, which means the tree path has ended without matching the linked list.

8. **Recursive Matching**
	```cpp
	    return (head->val == root->val) && (dfs(head->next, root->left) || dfs(head->next, root->right));
	```
	The function compares the current node values of the linked list and the binary tree. If they match, it recursively checks the next node in the list against the left or right children of the current tree node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, the algorithm must visit every node in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is determined by the height of the binary tree due to recursive calls, where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-in-binary-tree/description/)

---
{{< youtube OaA9MgG00AE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
