
+++
authors = ["grid47"]
title = "Leetcode 100: Same Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 100: Same Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/100.webp"
youtube = "jK6XXYezw2g"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi/jK6XXYezw2g/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/100.webp" 
    alt="Two trees glowing in harmony, showing perfect symmetry and balance."
    caption="Solution to LeetCode 100: Same Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two binary trees. Your task is to check if these two trees are the same. Two binary trees are considered the same if they are structurally identical and the nodes have the same value at each corresponding position.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the roots of two binary trees, 'p' and 'q'. Each tree is represented by its root node, and each node contains a value as well as pointers to its left and right children.
- **Example:** `p = [3, 5, 8, 2, 6], q = [3, 5, 8, 2, 6]`
- **Constraints:**
	- 0 <= number of nodes <= 100
	- -104 <= Node.val <= 104

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return 'true' if the two trees are identical, and 'false' otherwise.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to recursively check if the structure and values of corresponding nodes in the two trees are the same.

- If both trees are empty (i.e., both root nodes are null), return true.
- If one tree is empty and the other is not, return false.
- If both trees are non-empty, check if the value of the current node in both trees is the same.
- Recursively check the left and right subtrees.
{{< dots >}}
### Problem Assumptions ✅
- Both trees are binary trees.
{{< dots >}}
## Examples 🧩
- **Input:** `p = [1, 2, 3], q = [1, 2, 3]`  \
  **Explanation:** Both trees are structurally identical and have the same values, so the output is true.

- **Input:** `p = [1, 2], q = [1, null, 2]`  \
  **Explanation:** The structures of the trees differ because one tree has a null value where the other tree has a node, so the output is false.

- **Input:** `p = [1, 2, 3], q = [1, 1, 2]`  \
  **Explanation:** The trees are not identical because the node values are different at the same positions, so the output is false.

{{< dots >}}
## Approach 🚀
The problem can be solved using a recursive approach that checks the equality of the two trees node by node.

### Initial Thoughts 💭
- Both trees must have the same structure and corresponding node values to be considered the same.
- We can solve this problem recursively by checking the root nodes and then moving to the left and right children of the trees.
{{< dots >}}
### Edge Cases 🌐
- If both trees are empty, return true.
- The solution should be efficient enough to handle up to 100 nodes in each tree.
- If one tree has a null value where the other has a node, return false.
- Ensure that the recursion depth does not exceed the limits for large inputs.
{{< dots >}}
## Code 💻
```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;
    int ans = p->val == q->val;
    ans &= isSameTree(p->left, q->left);
    ans &= isSameTree(p->right, q->right);
    return ans;
}
```

This function checks if two binary trees are identical by recursively comparing their nodes' values and structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool isSameTree(TreeNode* p, TreeNode* q) {
	```
	We define the function 'isSameTree' which takes two pointers to the root nodes of two trees and returns whether the trees are identical.

2. **Base Case 1**
	```cpp
	    if(p == NULL && q == NULL) return true;
	```
	If both nodes are NULL, it means both trees are empty, so they are considered identical.

3. **Base Case 2**
	```cpp
	    if(p == NULL || q == NULL) return false;
	```
	If one of the nodes is NULL and the other is not, the trees are not identical.

4. **Value Comparison**
	```cpp
	    int ans = p->val == q->val;
	```
	We compare the values of the current nodes. If they are not equal, the trees are not identical, and 'ans' is set to 0.

5. **Left Subtree Comparison**
	```cpp
	    ans &= isSameTree(p->left, q->left);
	```
	We recursively check if the left subtrees of both trees are identical by calling 'isSameTree' on the left children.

6. **Right Subtree Comparison**
	```cpp
	    ans &= isSameTree(p->right, q->right);
	```
	We recursively check if the right subtrees of both trees are identical by calling 'isSameTree' on the right children.

7. **Return Result**
	```cpp
	    return ans;
	```
	Finally, we return the result of all the comparisons. If all are true, the trees are identical.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we must check all nodes in both trees, where n is the number of nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the recursion depth is equal to the height of the tree, which can be up to O(n) for a skewed tree. In the best case (balanced tree), it is O(log n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/same-tree/description/)

---
{{< youtube jK6XXYezw2g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
