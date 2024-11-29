
+++
authors = ["grid47"]
title = "Leetcode 617: Merge Two Binary Trees"
date = "2024-09-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 617: Merge Two Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/617.webp"
youtube = "NtHOsOl8zvQ"
youtube_upload_date="2022-06-28"
youtube_thumbnail="https://i.ytimg.com/vi/NtHOsOl8zvQ/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/617.webp" 
    alt="Two binary trees merging together, with each node softly glowing as they combine."
    caption="Solution to LeetCode 617: Merge Two Binary Trees Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two binary trees, merge them into a new binary tree where overlapping nodes are summed, and non-overlapping nodes are retained as they are.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two binary trees, represented by their root nodes. Each node contains an integer value.
- **Example:** `root1 = [1, 3, 2, 5], root2 = [2, 1, 3, None, 4, None, 7]`
- **Constraints:**
	- The number of nodes in each tree is in the range [0, 2000].
	- -10^4 <= Node.val <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the merged binary tree.
- **Example:** `[3, 4, 5, 5, 4, None, 7]`
- **Constraints:**
	- The merged tree should be returned as the root node of the new binary tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** Merge two binary trees by summing overlapping nodes and using non-overlapping nodes directly.

- 1. If both nodes are non-null, sum the values and recursively merge the left and right subtrees.
- 2. If one of the nodes is null, return the non-null node as it is.
- 3. If both nodes are null, return null.
{{< dots >}}
### Problem Assumptions ✅
- Both input trees are valid binary trees.
{{< dots >}}
## Examples 🧩
- **Input:** `root1 = [1, 3, 2, 5], root2 = [2, 1, 3, None, 4, None, 7]`  \
  **Explanation:** In this example, the root nodes (1 and 2) are merged into 3. The left children (3 and 1) are merged into 4, and similarly for the right children. The leaves are merged by summing the node values.

{{< dots >}}
## Approach 🚀
We will merge the trees recursively by comparing the values of the nodes and summing them where both nodes are non-null, or directly using the non-null node if one is null.

### Initial Thoughts 💭
- The problem is a classic example of recursion where we merge two binary trees.
- We will recursively traverse both trees and merge them by summing the overlapping nodes and retaining the non-overlapping nodes.
{{< dots >}}
### Edge Cases 🌐
- If both trees are empty, return null.
- Handle cases where the trees have up to 2000 nodes.
- Trees with null nodes or trees that have only one node.
- Ensure that the function handles the merging of trees efficiently within the input size constraints.
{{< dots >}}
## Code 💻
```cpp
TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
    TreeNode* ans = new TreeNode(0);
    if(r1 == NULL && r2 == NULL) return NULL;
    if(r1 != NULL && r2 != NULL)
        ans->val = r1->val + r2->val;
    else if(r1 == NULL)
        ans->val = r2->val;
    else
        ans->val = r1->val;
    ans->left = mergeTrees(r1?r1->left:NULL, r2?r2->left:NULL);
    ans->right = mergeTrees(r1?r1->right:NULL, r2?r2->right:NULL);
    return ans;
}
```

The `mergeTrees` function merges two binary trees. If both trees have nodes at a given position, their values are summed up. If only one tree has a node, the value from that tree is used. The left and right subtrees are recursively merged in the same way.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2) {
	```
	Defines the `mergeTrees` function that takes two binary tree nodes (`r1` and `r2`) as input and returns a new merged tree rooted at `ans`.

2. **Node Creation**
	```cpp
	    TreeNode* ans = new TreeNode(0);
	```
	Creates a new `TreeNode` named `ans` and initializes its value to `0`. This will hold the merged values from both trees.

3. **Base Case (NULL check)**
	```cpp
	    if(r1 == NULL && r2 == NULL) return NULL;
	```
	Checks if both input nodes are NULL. If so, it returns NULL because there is no tree to merge.

4. **Both Nodes Present**
	```cpp
	    if(r1 != NULL && r2 != NULL)
	```
	Checks if both input nodes (`r1` and `r2`) are non-NULL. If true, their values will be added together to form the value of the merged node.

5. **Sum Values of Both Nodes**
	```cpp
	        ans->val = r1->val + r2->val;
	```
	If both nodes are non-NULL, the values from both nodes (`r1->val` and `r2->val`) are summed and stored in `ans->val`.

6. **Only First Node Present**
	```cpp
	    else if(r1 == NULL)
	```
	Checks if the first node (`r1`) is NULL, meaning only `r2` has a node at this position in the tree.

7. **Use Value from Second Node**
	```cpp
	        ans->val = r2->val;
	```
	If `r1` is NULL, the value from `r2` is assigned to `ans->val`, as `r2` is the only valid node.

8. **Only Second Node Present**
	```cpp
	    else
	```
	If neither of the previous conditions was met, it implies that `r2` is NULL and only `r1` is valid at this position.

9. **Use Value from First Node**
	```cpp
	        ans->val = r1->val;
	```
	If `r2` is NULL, the value from `r1` is assigned to `ans->val`, as `r1` is the only valid node.

10. **Recursive Left Subtree Merge**
	```cpp
	    ans->left = mergeTrees(r1?r1->left:NULL, r2?r2->left:NULL);
	```
	Recursively merges the left subtrees of `r1` and `r2`. If a tree is missing a left child, it passes NULL instead.

11. **Recursive Right Subtree Merge**
	```cpp
	    ans->right = mergeTrees(r1?r1->right:NULL, r2?r2->right:NULL);
	```
	Recursively merges the right subtrees of `r1` and `r2`. Similar to the left subtree, NULL is passed if a tree has no right child.

12. **Return Merged Tree**
	```cpp
	    return ans;
	```
	Returns the root of the merged tree, which has been constructed by recursively merging nodes and their children.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N)
- **Average Case:** O(N)
- **Worst Case:** O(N)

The time complexity is O(N) where N is the total number of nodes in both trees, as we visit each node once.

### Space Complexity 💾
- **Best Case:** O(H)
- **Worst Case:** O(H)

The space complexity is O(H) where H is the height of the tree due to the recursive call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-two-binary-trees/description/)

---
{{< youtube NtHOsOl8zvQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
