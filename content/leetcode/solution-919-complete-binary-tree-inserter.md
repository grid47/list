
+++
authors = ["grid47"]
title = "Leetcode 919: Complete Binary Tree Inserter"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 919: Complete Binary Tree Inserter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Design","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a complete binary tree. A complete binary tree is one where every level, except possibly the last, is completely filled, and all nodes are as far left as possible. Your task is to design a data structure that supports inserting new nodes while maintaining the completeness of the binary tree. Implement the CBTInserter class that supports two operations: inserting a new node and returning the root of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a complete binary tree and a value to insert.
- **Example:** `Input: root = [1, 2], val = 3`
- **Constraints:**
	- 1 <= n <= 1000
	- 0 <= Node.val <= 5000
	- 0 <= val <= 5000
	- At most 10^4 calls to insert and get_root will be made.

{{< dots >}}
### Output Specifications 📤
- **Output:** The `insert` method should return the value of the parent node of the newly inserted node. The `get_root` method should return the root node of the tree.
- **Example:** `Output: [null, 1, 2, [1, 2, 3, 4]]`
- **Constraints:**
	- The tree will always remain complete after each insertion.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maintain the completeness of the binary tree after each insertion while ensuring efficient updates.

- Use a list (array) to store the nodes in level-order. This allows easy access to parent and child nodes for insertion.
- When inserting a new node, add it to the list and determine whether it should be the left or right child of its parent, based on the index of the new node.
- Update the tree structure in the list and return the parent node's value.
{{< dots >}}
### Problem Assumptions ✅
- The input binary tree is a complete binary tree before the first insertion.
- The new node will always be inserted in the next available spot in the tree to maintain completeness.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, 2], val = 3`  \
  **Explanation:** The tree before insertion is [1, 2]. After inserting 3, the new tree becomes [1, 2, 3], where 1 is the parent of 2 and 3. The return value is the parent node's value, which is 1.

- **Input:** `Input: root = [1, 2, 3, 4], val = 5`  \
  **Explanation:** Before the insertion, the tree is [1, 2, 3, 4]. After inserting 5, the tree becomes [1, 2, 3, 4, 5]. The parent node of 5 is 2, so the return value is 2.

{{< dots >}}
## Approach 🚀
To insert a new node into the complete binary tree while maintaining its completeness, we use an array-based approach to store the tree in level order. This allows efficient access to parent nodes and insertion points.

### Initial Thoughts 💭
- The tree is complete, so every insertion can be handled by simply adding the new node to the next available position in the tree.
- Using a list to represent the tree in level order allows us to efficiently manage the insertions and get the parent of the inserted node in constant time.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that the tree will have at least one node, so there will be no empty inputs.
- The algorithm should handle up to 10^4 insertions efficiently.
- If the tree has only one node, the next insertion should simply add the second node as the left child.
- The tree will remain complete at all times, so there is no need to rebalance it.
{{< dots >}}
## Code 💻
```cpp
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
vector<TreeNode*> tree;
public:
CBTInserter(TreeNode* root) {
    tree.push_back(root);
    for(int i = 0; i < tree.size(); i++) {
        if(tree[i]->left) tree.push_back(tree[i]->left);
        if(tree[i]->right) tree.push_back(tree[i]->right);
    }
}

int insert(int val) {
    int N = tree.size();
    TreeNode* node = new TreeNode(val);
    tree.push_back(node);
    if(N%2) tree[(N-1)/2]->left = node;
    else    tree[(N-1)/2]->right= node;
    return tree[(N-1)/2]->val;
}

TreeNode* get_root() {
    return tree[0];
}
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
```

The 'CBTInserter' class helps in managing a complete binary tree. It allows inserting nodes while maintaining the complete binary tree property and retrieving the root of the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class CBTInserter {
	```
	Define the 'CBTInserter' class that manages a complete binary tree and provides methods for insertion and retrieval.

2. **Variable Declaration**
	```cpp
	vector<TreeNode*> tree;
	```
	A vector of pointers to 'TreeNode' objects, which holds the nodes of the complete binary tree.

3. **Access Specifier**
	```cpp
	public:
	```
	Specifies that the following methods and members are publicly accessible.

4. **Constructor**
	```cpp
	CBTInserter(TreeNode* root) {
	```
	Constructor for the 'CBTInserter' class that initializes the tree with the root node.

5. **Tree Initialization**
	```cpp
	    tree.push_back(root);
	```
	Add the root node to the 'tree' vector.

6. **Loop**
	```cpp
	    for(int i = 0; i < tree.size(); i++) {
	```
	Start a loop to traverse all nodes in the tree and add their children to the 'tree' vector.

7. **Child Insertion**
	```cpp
	        if(tree[i]->left) tree.push_back(tree[i]->left);
	```
	If the current node has a left child, add it to the 'tree' vector.

8. **Child Insertion**
	```cpp
	        if(tree[i]->right) tree.push_back(tree[i]->right);
	```
	If the current node has a right child, add it to the 'tree' vector.

9. **Method**
	```cpp
	int insert(int val) {
	```
	Define the 'insert' method that inserts a new node with value 'val' into the tree.

10. **Variable Declaration**
	```cpp
	    int N = tree.size();
	```
	Store the current size of the 'tree' vector, which is used to find the parent node of the new node.

11. **Node Creation**
	```cpp
	    TreeNode* node = new TreeNode(val);
	```
	Create a new 'TreeNode' with the given value 'val'.

12. **Tree Update**
	```cpp
	    tree.push_back(node);
	```
	Add the newly created node to the 'tree' vector.

13. **Child Assignment**
	```cpp
	    if(N%2) tree[(N-1)/2]->left = node;
	```
	If 'N' is odd, assign the new node as the left child of its parent.

14. **Child Assignment**
	```cpp
	    else    tree[(N-1)/2]->right= node;
	```
	If 'N' is even, assign the new node as the right child of its parent.

15. **Return Statement**
	```cpp
	    return tree[(N-1)/2]->val;
	```
	Return the value of the parent node to confirm where the new node was inserted.

16. **Method**
	```cpp
	TreeNode* get_root() {
	```
	Define the 'get_root' method that returns the root of the tree.

17. **Return Statement**
	```cpp
	    return tree[0];
	```
	Return the root of the tree (the first element in the 'tree' vector).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Both the `insert` and `get_root` operations run in constant time O(1), as we are only adding a new node to the list and returning the root.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n), where n is the number of nodes in the tree, as we store all nodes in the list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/complete-binary-tree-inserter/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
