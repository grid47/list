
+++
authors = ["grid47"]
title = "Leetcode 2236: Root Equals Sum of Children"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2236: Root Equals Sum of Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Binary Tree"]
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
You are given a binary tree with three nodes: the root, its left child, and its right child. Determine whether the value of the root node is equal to the sum of the values of its two children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree with exactly three nodes: a root node, a left child, and a right child. Each node contains an integer value.
- **Example:** `Input: root = [7, 3, 4]`
- **Constraints:**
	- The binary tree always has three nodes: root, left child, and right child.
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value indicating whether the value of the root node is equal to the sum of the values of its two children.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Check if the sum of the values of the left and right children equals the value of the root node.

- 1. Access the value of the root node.
- 2. Access the values of the left and right child nodes.
- 3. Compute the sum of the left and right child node values.
- 4. Compare the computed sum with the value of the root node.
- 5. Return true if they are equal; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree input will always be valid with three nodes.
- No additional nodes or structures are present in the input.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [7, 3, 4]`  \
  **Explanation:** The value of the root is 7, and the sum of the left and right children is 3 + 4 = 7. Since they are equal, the output is true.

- **Input:** `Input: root = [8, 5, 2]`  \
  **Explanation:** The value of the root is 8, and the sum of the left and right children is 5 + 2 = 7. Since they are not equal, the output is false.

{{< dots >}}
## Approach 🚀
The approach involves simple arithmetic comparisons to validate the relationship between the root and its children.

### Initial Thoughts 💭
- The tree is small with only three nodes, so the logic is straightforward.
- The problem only requires basic comparison of integer values.
- Accessing and comparing node values directly should be sufficient to solve this problem efficiently.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as the input always contains three nodes.
- Not applicable, as the input size is fixed to three nodes.
- All node values are zeros, e.g., root = [0, 0, 0].
- The root value is negative, and its children sum to match it.
- Ensure comparisons handle both negative and positive integers correctly.
{{< dots >}}
## Code 💻
```cpp
bool checkTree(TreeNode* root) {
    return (root->left->val)+(root->right->val)==root->val;
}
```

This function checks if the sum of the values of the left and right child nodes of a binary tree's root node equals the value of the root node itself.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	bool checkTree(TreeNode* root) {
	```
	Defines the 'checkTree' function that takes a pointer to the root of a binary tree and returns a boolean value.

2. **Return Statement**
	```cpp
	    return (root->left->val)+(root->right->val)==root->val;
	```
	Returns 'true' if the sum of the values of the left and right children of the root node equals the root's value; otherwise, returns 'false'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because the binary tree always contains exactly three nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space as no additional memory is required beyond the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/root-equals-sum-of-children/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
