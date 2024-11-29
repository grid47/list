
+++
authors = ["grid47"]
title = "Leetcode 958: Check Completeness of a Binary Tree"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 958: Check Completeness of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9Jhtrwxp9ME"
youtube_upload_date="2023-03-16"
youtube_thumbnail="https://i.ytimg.com/vi/9Jhtrwxp9ME/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree. Determine if the tree is a complete binary tree. A complete binary tree is defined as follows: every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree represented by the 'TreeNode' structure, where each node has a value, a left child, and a right child.
- **Example:** `Input: root = [1, 2, 3, 4, 5, 6]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 100.
	- 1 <= Node.val <= 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if the binary tree is a complete binary tree, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The function should return a boolean indicating whether the tree is complete.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to verify that every level, except possibly the last, is completely filled and that all nodes in the last level are as far left as possible.

- 1. Traverse the binary tree using level-order traversal.
- 2. At each step, check if the current node is null. If it is null, ensure that no nodes exist after it in the same level.
- 3. If all levels are filled correctly and the last level's nodes are as far left as possible, return true. Otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is provided as a 'TreeNode' object.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, 2, 3, 4, 5, 6]`  \
  **Explanation:** In this case, every level before the last is filled completely, and all nodes in the last level are as far left as possible. Therefore, the tree is a complete binary tree.

- **Input:** `Input: root = [1, 2, 3, 4, 5, null, 7]`  \
  **Explanation:** In this case, the node with value 7 is not as far left as possible in the last level. Therefore, the tree is not a complete binary tree.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves performing a level-order traversal and ensuring that all levels are filled correctly, except possibly the last one, which must have all nodes as far left as possible.

### Initial Thoughts 💭
- Level-order traversal is ideal for this type of problem because it processes nodes level by level.
- We need to track the nodes at each level, ensuring that the last level’s nodes are positioned as far left as possible and no nodes exist after a null node in the level.
{{< dots >}}
### Edge Cases 🌐
- The tree will always contain at least one node, as per the constraints.
- For larger trees (up to 100 nodes), the solution should still perform efficiently as long as the traversal is done correctly.
- The tree can contain null nodes, but we must ensure that they appear only after all other nodes at the same level.
- The tree will always have between 1 and 100 nodes, and node values are bounded between 1 and 1000.
{{< dots >}}
## Code 💻
```cpp
bool isCompleteTree(TreeNode* root) {
    vector<TreeNode*> q;
    q.push_back(root);
    int i = 0;
    while(i < q.size() && q[i]) {
        q.push_back(q[i]->left);
        q.push_back(q[i]->right);
        i++;
    }
    while(i < q.size() && !q[i])
        i++;
    return i == q.size();
}
```

This function checks if a binary tree is complete. It performs a level-order traversal, adding child nodes to a queue. A complete binary tree must not have non-null nodes after a null node during traversal.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool isCompleteTree(TreeNode* root) {
	```
	Function declaration for `isCompleteTree`, which determines if a binary tree is complete.

2. **Data Structure Initialization**
	```cpp
	    vector<TreeNode*> q;
	```
	Initialize a vector `q` to simulate a queue for level-order traversal.

3. **Push Root Node**
	```cpp
	    q.push_back(root);
	```
	Add the root node to the queue as the starting point for traversal.

4. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initialize a variable `i` to track the current index in the queue.

5. **Traversal Loop**
	```cpp
	    while(i < q.size() && q[i]) {
	```
	Iterate over the queue, processing non-null nodes during level-order traversal.

6. **Add Left Child**
	```cpp
	        q.push_back(q[i]->left);
	```
	Add the left child of the current node to the queue, even if it's null.

7. **Add Right Child**
	```cpp
	        q.push_back(q[i]->right);
	```
	Add the right child of the current node to the queue, even if it's null.

8. **Increment Index**
	```cpp
	        i++;
	```
	Move to the next node in the queue.

9. **Null Node Check**
	```cpp
	    while(i < q.size() && !q[i])
	```
	Continue iterating through the queue, ensuring all subsequent nodes are null.

10. **Increment Index for Null Nodes**
	```cpp
	        i++;
	```
	Move to the next node while verifying the null condition.

11. **Return Condition**
	```cpp
	    return i == q.size();
	```
	Return true if all nodes are processed and null nodes appear only at the end of the queue.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Where n is the number of nodes in the binary tree. In all cases, we visit each node once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the space used by the queue during the level-order traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/)

---
{{< youtube 9Jhtrwxp9ME >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
