
+++
authors = ["grid47"]
title = "Leetcode 1080: Insufficient Nodes in Root to Leaf Paths"
date = "2024-07-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1080: Insufficient Nodes in Root to Leaf Paths in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
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
You are given the root of a binary tree and an integer limit. Your task is to delete all nodes in the tree that are considered insufficient. A node is insufficient if every root-to-leaf path passing through that node has a sum strictly less than the given limit. A leaf is defined as a node with no children. Return the root of the resulting binary tree after the deletions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree represented by its root node and an integer limit.
- **Example:** `Input: root = [2, 3, 4, 5, -10, -10, 8, 10], limit = 15`
- **Constraints:**
	- 1 <= Number of nodes in the tree <= 5000
	- -10^5 <= Node value <= 10^5
	- -10^9 <= limit <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the root node of the resulting binary tree after deleting insufficient nodes.
- **Example:** `Output: [2, 3, 4, 5, null, null, 10]`
- **Constraints:**
	- The structure of the binary tree should be preserved after deleting the insufficient nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the tree and prune any nodes whose root-to-leaf path does not satisfy the sum condition with respect to the limit.

- 1. Perform a post-order traversal of the tree.
- 2. At each node, compute the sum of the path from root to leaf, considering all descendants.
- 3. If the sum at the current node is less than the limit, delete the node.
- 4. Return the modified tree after pruning the insufficient nodes.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid binary tree.
- The limit value is a valid integer within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [3, 1, 2, 4, 5, -99, 6], limit = 10`  \
  **Explanation:** In this case, the path from root to leaf through nodes 3 -> 1 -> 4 has a sum of 8, which is less than the limit. Thus, node 1 and its descendants (4) will be deleted. The resulting tree will have root 3, with the right child 2, and the leaf nodes 6 and 5 remaining.

- **Input:** `Input: root = [2, 3, 4, 5, 6, 7, 8], limit = 18`  \
  **Explanation:** The tree contains multiple paths where the sum exceeds the limit. After pruning, only the nodes forming valid paths above the limit are retained.

{{< dots >}}
## Approach 🚀
To solve this problem, a post-order depth-first search (DFS) approach can be employed, where each node is processed after its children, and insufficient nodes are removed based on the sum condition.

### Initial Thoughts 💭
- A bottom-up DFS traversal works well because we need to decide whether to prune a node after considering its children.
- Using recursion allows us to handle the pruning and return the modified tree efficiently.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (i.e., root is null), return null.
- The solution must handle large trees (up to 5000 nodes) efficiently.
- If the limit is extremely large or small, the algorithm should still work within the given constraints.
- The solution should efficiently prune insufficient nodes in large binary trees.
{{< dots >}}
## Code 💻
```cpp
TreeNode* sufficientSubset(TreeNode* root, int limit) {
    if(!root) return NULL;
    if(root->left == NULL && root->right == NULL)
        return root->val < limit ? NULL : root;
    root->left = sufficientSubset(root->left, limit - root->val);
    root->right= sufficientSubset(root->right, limit - root->val);
    return root->left == root->right ? NULL : root;
}
```

This function takes a binary tree and a limit value. It traverses the tree and removes any nodes where the sum of values from that node to the leaf is less than the given limit. If a leaf node's value is less than the limit, it is removed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	TreeNode* sufficientSubset(TreeNode* root, int limit) {
	```
	This line defines the function `sufficientSubset`, which takes a pointer to the root of a binary tree and an integer `limit`. It returns the root of the modified tree after removing insufficient nodes.

2. **Base Case - Empty Node**
	```cpp
	    if(!root) return NULL;
	```
	This checks if the current node is `NULL`. If the node is empty, it returns `NULL`, signaling the end of this path in the tree.

3. **Base Case - Leaf Node**
	```cpp
	    if(root->left == NULL && root->right == NULL)
	```
	This checks if the current node is a leaf (i.e., has no left or right child).

4. **Leaf Node Value Check**
	```cpp
	        return root->val < limit ? NULL : root;
	```
	If the node is a leaf, it checks whether its value is less than the `limit`. If it is, the node is removed (returns `NULL`), otherwise, it is kept.

5. **Recursive Call - Left Child**
	```cpp
	    root->left = sufficientSubset(root->left, limit - root->val);
	```
	This recursively calls the `sufficientSubset` function on the left child of the current node, reducing the `limit` by the current node's value.

6. **Recursive Call - Right Child**
	```cpp
	    root->right= sufficientSubset(root->right, limit - root->val);
	```
	This recursively calls the `sufficientSubset` function on the right child of the current node, similarly adjusting the `limit`.

7. **Return Condition**
	```cpp
	    return root->left == root->right ? NULL : root;
	```
	This checks if both the left and right children are `NULL` (meaning both children were removed). If so, the current node is also removed (returns `NULL`), otherwise, it is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we visit all nodes in the tree once, leading to a linear time complexity with respect to the number of nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is proportional to the height of the tree due to the recursion stack in the DFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
