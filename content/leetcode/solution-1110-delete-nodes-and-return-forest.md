
+++
authors = ["grid47"]
title = "Leetcode 1110: Delete Nodes And Return Forest"
date = "2024-07-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1110: Delete Nodes And Return Forest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UhKu0q1yXHY"
youtube_upload_date="2024-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UhKu0q1yXHY/maxresdefault.webp"
comments = true
+++



---
Given the root of a binary tree, and a list of values to delete, your task is to remove the nodes with the given values. The resulting tree will become a forest, where each tree is a disjoint set of nodes. Return the roots of the trees in the remaining forest.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree and a list `to_delete` containing the values of the nodes to be removed. The tree is a binary tree with distinct node values.
- **Example:** `Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]`
- **Constraints:**
	- The number of nodes in the tree is at most 1000.
	- Each node has a distinct value between 1 and 1000.
	- The `to_delete` array contains distinct values between 1 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of trees in the forest (represented by their roots). The trees are in the remaining forest after deleting the specified nodes.
- **Example:** `Output: [[1,2,null,4],[6],[7]]`
- **Constraints:**
	- The result should be the list of roots of the disjoint trees formed after deletion.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to remove nodes from the tree and form multiple disjoint trees. These disjoint trees should be collected and returned as a list of roots.

- Create a set from the `to_delete` list for efficient lookups.
- Traverse the tree and delete the nodes found in `to_delete`.
- For each node that is a root of a new tree, add it to the result list.
- During traversal, ensure that after deletion, the children of deleted nodes are properly handled as roots of new trees.
{{< dots >}}
### Problem Assumptions ✅
- Nodes to be deleted will always exist in the tree.
- After deletion, the remaining trees are disjoint and valid.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]`  \
  **Explanation:** In this example, the nodes with values 3 and 5 will be removed from the tree. This results in three disjoint trees: one with root 1, another with root 6, and another with root 7.

- **Input:** `Input: root = [1,2,4,null,3], to_delete = [3]`  \
  **Explanation:** Here, node 3 is deleted, and the resulting tree will have a single tree rooted at 1 with child 2 and 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we use a recursive depth-first traversal. During the traversal, we will delete the specified nodes and reassign the children of deleted nodes to be roots of new trees if necessary.

### Initial Thoughts 💭
- We need to traverse the tree and check if the current node is in the `to_delete` list. If it is, we remove it and its children become new trees.
- A depth-first search (DFS) approach can be used to handle the tree traversal and deletion of nodes efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty, the result should also be empty.
- The solution should efficiently handle trees with up to 1000 nodes.
- If the tree contains only the nodes that are to be deleted, the result should be an empty list.
- The solution should process the tree in O(n) time where n is the number of nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<TreeNode*> ans;
set<int> to_del;
public:
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    for(int i: to_delete) to_del.insert(i);
    helper(root, true);
    return ans;
}

TreeNode* helper(TreeNode* root, bool is_root) {
    if(root == NULL) return NULL;
    bool del = to_del.find(root->val) != to_del.end();
    if(is_root && !del) ans.push_back(root);
    root->left = helper(root->left, del);
    root->right = helper(root->right, del);
    return del? NULL : root;
}

```

This code defines a solution for the problem where nodes of a binary tree are deleted based on a given list of nodes to delete. The algorithm recursively processes each node, removes it if necessary, and returns the modified tree with the remaining nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	The class `Solution` is defined, which contains methods for solving the problem of deleting nodes from a binary tree.

2. **Variable Declaration**
	```cpp
	vector<TreeNode*> ans;
	```
	A vector `ans` is declared to store the remaining nodes in the tree after the specified nodes are deleted.

3. **Variable Declaration**
	```cpp
	set<int> to_del;
	```
	A set `to_del` is declared to hold the values of the nodes that need to be deleted, ensuring efficient look-up times.

4. **Access Modifier**
	```cpp
	public:
	```
	The `public` access modifier is used to expose the methods of the class to be accessible from outside the class.

5. **Function Declaration**
	```cpp
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
	```
	The method `delNodes` is declared, which accepts the root of the binary tree and a list of node values to delete. It returns a vector containing the remaining trees after deletions.

6. **Inserting to Set**
	```cpp
	    for(int i: to_delete) to_del.insert(i);
	```
	A loop iterates through the list `to_delete`, inserting each node value into the `to_del` set, marking the nodes that need to be deleted.

7. **Recursive Call**
	```cpp
	    helper(root, true);
	```
	The helper function is called with the root node and a `true` flag, indicating that the root of the tree is initially considered a potential root of a new tree after deletion.

8. **Return Statement**
	```cpp
	    return ans;
	```
	The method returns the `ans` vector, which contains the roots of the remaining trees after the deletions have been processed.

9. **Function Declaration**
	```cpp
	TreeNode* helper(TreeNode* root, bool is_root) {
	```
	The helper function is declared. It takes a node `root` and a boolean `is_root` to determine if the current node is the root of a new tree.

10. **Base Case**
	```cpp
	    if(root == NULL) return NULL;
	```
	The base case of the recursion checks if the current node is `NULL`. If it is, the function returns `NULL` to stop further recursion.

11. **Node Deletion Check**
	```cpp
	    bool del = to_del.find(root->val) != to_del.end();
	```
	A boolean variable `del` is set to `true` if the current node's value is in the `to_del` set, indicating that the node should be deleted.

12. **Adding Root to Result**
	```cpp
	    if(is_root && !del) ans.push_back(root);
	```
	If the current node is a root and not marked for deletion, it is added to the `ans` vector, representing a new tree root.

13. **Recursive Call for Left Child**
	```cpp
	    root->left = helper(root->left, del);
	```
	The helper function is called recursively for the left child of the current node. The `del` flag is passed to indicate whether the node should be deleted.

14. **Recursive Call for Right Child**
	```cpp
	    root->right = helper(root->right, del);
	```
	The helper function is called recursively for the right child of the current node with the `del` flag.

15. **Return Statement**
	```cpp
	    return del? NULL : root;
	```
	If the current node is marked for deletion, `NULL` is returned to remove it; otherwise, the current node is returned to link the tree structure.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the tree. We traverse the tree once, visiting each node.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive stack and the storage of the result list, where n is the number of nodes.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-nodes-and-return-forest/description/)

---
{{< youtube UhKu0q1yXHY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
