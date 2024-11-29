
+++
authors = ["grid47"]
title = "Leetcode 2331: Evaluate Boolean Binary Tree"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2331: Evaluate Boolean Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "9a_cP54jn8Q"
youtube_upload_date="2024-05-16"
youtube_thumbnail="https://i.ytimg.com/vi/9a_cP54jn8Q/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a full binary tree. The leaf nodes hold boolean values: 0 (False) and 1 (True). The non-leaf nodes hold values 2 (OR) or 3 (AND). Your task is to evaluate the tree according to the logical operations and return the final boolean result of the root node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a full binary tree. Each node has a value of 0 or 1 (leaf nodes), or 2 (OR) or 3 (AND) for non-leaf nodes.
- **Example:** `root = [3, 2, 1, null, null, 0, 1]`
- **Constraints:**
	- 1 <= Number of nodes <= 1000
	- Each node has either 0 or 2 children.
	- Leaf nodes have value 0 or 1, non-leaf nodes have value 2 or 3.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the boolean result of evaluating the root node of the tree.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value (true or false).

{{< dots >}}
### Core Logic 🔍
**Goal:** Evaluate the binary tree using logical operations (AND/OR) and return the result at the root node.

- Check if the current node is a leaf node. If so, return its value.
- If the current node is not a leaf, recursively evaluate the left and right children.
- If the node is an AND node (value 3), return the result of applying AND on the left and right children's evaluations.
- If the node is an OR node (value 2), return the result of applying OR on the left and right children's evaluations.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a full binary tree, meaning each non-leaf node has exactly two children.
- The leaf nodes' values are either 0 or 1, representing boolean False and True respectively.
- Non-leaf nodes' values are either 2 (for OR operation) or 3 (for AND operation).
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3, 2, 1, null, null, 0, 1]`  \
  **Explanation:** The evaluation starts from the leaf nodes. The OR operation at the left child evaluates to 1, and the AND operation at the root results in true.

- **Input:** `root = [2, 0, 0]`  \
  **Explanation:** The OR operation at the root evaluates to false since both children are 0 (False).

{{< dots >}}
## Approach 🚀
We recursively evaluate the binary tree by checking each node's value. If the node is a leaf, we return its value. Otherwise, we evaluate its children and apply the corresponding logical operation.

### Initial Thoughts 💭
- Each node's value either indicates a leaf (0 or 1) or a logical operation (2 for OR, 3 for AND).
- We can use a recursive approach to evaluate each node based on whether it is a leaf or a non-leaf.
{{< dots >}}
### Edge Cases 🌐
- No tree (null input) should be handled.
- Large trees with 1000 nodes.
- A single leaf node with value 1 or 0.
- Ensure that the tree is properly constructed with each node having either 0 or 2 children.
{{< dots >}}
## Code 💻
```cpp
bool evaluateTree(TreeNode* root) {
    if(!root) return false;
    if(!root->left && !root->right) return root->val;
    
    if(root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);
  else

return evaluateTree(root->left) && evaluateTree(root->right);        
}
```

This function evaluates a binary tree where each node is either an operator (2 for OR, 3 for AND) or a leaf node with a value (0 or 1). The function returns the result of evaluating the logical expression represented by the tree, with OR and AND operations applied between nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool evaluateTree(TreeNode* root) {
	```
	Declares the function `evaluateTree`, which takes a `TreeNode* root` as input and returns a boolean value (`true` or `false`). It evaluates the logical expression represented by a binary tree.

2. **Base Case Check**
	```cpp
	    if(!root) return false;
	```
	Checks if the current node is `null`. If the node is `null`, it returns `false` as there is no logical expression to evaluate.

3. **Leaf Node Check**
	```cpp
	    if(!root->left && !root->right) return root->val;
	```
	If the node is a leaf node (no left or right child), it simply returns the value of the node (`root->val`), which is either 0 or 1.

4. **OR Operation Check**
	```cpp
	    if(root->val == 2)
	```
	Checks if the current node represents an OR operation (denoted by `2`). If it does, the function will recursively evaluate the left and right children using the logical OR operation.

5. **OR Operation Evaluation**
	```cpp
	        return evaluateTree(root->left) || evaluateTree(root->right);
	```
	If the current node is an OR operator, it evaluates the left and right children and returns the logical OR of their results.

6. **AND Operation Check**
	```cpp
	  else
	```
	If the node is not an OR operator (i.e., it must be an AND operator, denoted by `3`), the function proceeds to the AND evaluation.

7. **AND Operation Evaluation**
	```cpp
	return evaluateTree(root->left) && evaluateTree(root->right);
	```
	If the current node is an AND operator, it evaluates the left and right children and returns the logical AND of their results.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we visit each node in the tree once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive stack in the worst case, where n is the number of nodes in the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/evaluate-boolean-binary-tree/description/)

---
{{< youtube 9a_cP54jn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
