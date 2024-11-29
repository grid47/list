
+++
authors = ["grid47"]
title = "Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given two binary trees: an original tree and a cloned tree. The cloned tree is a copy of the original tree, and you are given a reference to a node in the original tree. Your task is to return the reference to the corresponding node in the cloned tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two binary trees: the original tree and its clone, and a target node from the original tree.
- **Example:** `original_tree = [5,3,8,1,4,7,10], target = 4`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 10^4.
	- The values of the nodes are unique.
	- The target node is a node from the original tree and is not null.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a reference to the corresponding node in the cloned tree.
- **Example:** `4`
- **Constraints:**
	- The node in the cloned tree that corresponds to the target node in the original tree should be returned.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to return a reference to the same node in the cloned tree as the target node in the original tree.

- Traverse the cloned tree in parallel with the original tree.
- When the target node in the original tree is found, return the corresponding node from the cloned tree.
{{< dots >}}
### Problem Assumptions ✅
- The cloned tree is an exact copy of the original tree, including structure and values.
{{< dots >}}
## Examples 🧩
- **Input:** `original_tree = [5,3,8,1,4,7,10], target = 4`  \
  **Explanation:** The target node is `4` in the original tree, and its corresponding node in the cloned tree should be returned.

{{< dots >}}
## Approach 🚀
The problem can be solved by using a depth-first search (DFS) or breadth-first search (BFS) traversal to find the target node in the original tree and return the corresponding node from the cloned tree.

### Initial Thoughts 💭
- The original and cloned trees have the same structure and values.
- A depth-first search can be used to find the target node in the original tree, and the corresponding node in the cloned tree can be returned.
{{< dots >}}
### Edge Cases 🌐
- If there is only one node in the tree, return that node.
- Ensure the solution works for large trees with up to 10^4 nodes.
- If the target is the root of the tree, return the root from the cloned tree.
- The tree must have a valid structure with unique values.
{{< dots >}}
## Code 💻
```cpp
TreeNode* ans;
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
{
    if (cloned == NULL)
        return cloned;
    if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
        ans = cloned;
    getTargetCopy(original, cloned->left, target);
    getTargetCopy(original, cloned->right, target);
    return ans;
}
```

This is the complete implementation of the `getTargetCopy` function that performs a depth-first search on the cloned tree to find a node that corresponds to the target node from the original tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	TreeNode* ans;
	```
	We declare a pointer `ans` of type `TreeNode*` that will hold the reference to the corresponding node in the cloned tree.

2. **Function Definition**
	```cpp
	TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
	```
	We define the function `getTargetCopy` that takes in three arguments: the original tree, the cloned tree, and the target node. It returns the corresponding node in the cloned tree.

3. **Base Case**
	```cpp
	    if (cloned == NULL)
	```
	We check if the current node in the cloned tree is `NULL`, which indicates we have reached a leaf or an empty subtree.

4. **Return Statement**
	```cpp
	        return cloned;
	```
	If the current node is `NULL`, we return `NULL` because there are no further nodes to check in this branch.

5. **Target Node Check**
	```cpp
	    if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
	```
	We check if the value of the current node in the cloned tree matches the target node's value.

6. **Assign Found Node**
	```cpp
	        ans = cloned;
	```
	If the values match, we assign the current node in the cloned tree to `ans` since it corresponds to the target node.

7. **Recursive Call (Left Subtree)**
	```cpp
	    getTargetCopy(original, cloned->left, target);
	```
	We make a recursive call to `getTargetCopy` to search the left subtree of the cloned tree.

8. **Recursive Call (Right Subtree)**
	```cpp
	    getTargetCopy(original, cloned->right, target);
	```
	We make a recursive call to `getTargetCopy` to search the right subtree of the cloned tree.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Once both subtrees have been searched, we return the `ans` variable, which contains the reference to the corresponding node in the cloned tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the tree, since we need to traverse all nodes to find the target.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h) where h is the height of the tree, due to the recursion stack used during the DFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
