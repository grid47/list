
+++
authors = ["grid47"]
title = "Leetcode 104: Maximum Depth of Binary Tree"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 104: Maximum Depth of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/104.webp"
youtube = "ScvTcU2Aifs"
youtube_upload_date="2024-04-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ScvTcU2Aifs/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/104.webp" 
    alt="A deep, glowing tree with rays of light expanding downwards to symbolize depth."
    caption="Solution to LeetCode 104: Maximum Depth of Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. Your task is to return the maximum depth of the tree. The maximum depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root node of a binary tree, where each node contains a value, and pointers to its left and right children.
- **Example:** `root = [5,3,8,2,4,7,9]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 10^4].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** You should return an integer representing the maximum depth of the binary tree.
- **Example:** `Output: 3`
- **Constraints:**
	- The output should be a single integer representing the depth of the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum depth of the binary tree by recursively calculating the depth of the left and right subtrees, and returning the larger of the two depths plus one.

- Base Case: If the root is NULL, return 0.
- Recursively find the maximum depth of the left subtree.
- Recursively find the maximum depth of the right subtree.
- Return the larger of the two depths plus one to account for the current node.
{{< dots >}}
### Problem Assumptions ✅
- The input will always represent a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3,9,20,null,null,15,7]`  \
  **Explanation:** The binary tree has the following structure:

       3
      / \
     9  20
        /  \
       15   7

The longest path is from root (3) to leaf nodes (15 or 7), which has a depth of 3.

- **Input:** `root = [1,null,2]`  \
  **Explanation:** The binary tree consists of the root node (1) and its right child (2), forming a path of depth 2.

- **Input:** `root = []`  \
  **Explanation:** An empty tree has no nodes, so the maximum depth is 0.

{{< dots >}}
## Approach 🚀
The problem can be solved using a recursive approach to traverse the tree and calculate the depth of each subtree.

### Initial Thoughts 💭
- The problem can be solved using recursion by finding the depth of the left and right subtrees at each node.
- By utilizing recursion, we can efficiently calculate the maximum depth of the tree by always comparing the depths of the left and right subtrees.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return 0.
- For large trees with up to 10,000 nodes, ensure the solution handles the input efficiently.
- If the tree is heavily unbalanced (e.g., all nodes are on one side), the depth should be calculated correctly based on the longest path.
- The tree can contain up to 10,000 nodes, so the algorithm should be efficient in terms of time complexity.
{{< dots >}}
## Code 💻
```cpp
int maxDepth(TreeNode* root) {
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
```

This function calculates the maximum depth (or height) of a binary tree using a recursive approach.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maxDepth(TreeNode* root) {
	```
	Define the function 'maxDepth' which takes the root of a binary tree and returns the maximum depth of the tree.

2. **Base Case Check**
	```cpp
	    if(root == NULL) return 0;
	```
	Check if the current node is null. If it is, return a depth of 0, representing the base case of the recursion.

3. **Recursive Call**
	```cpp
	    return 1 + max(maxDepth(root->left), maxDepth(root->right));
	```
	Recursively calculate the maximum depth of the left and right subtrees, add 1 to account for the current node, and return the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we need to visit each node in the tree, so the time complexity is O(n), where n is the number of nodes.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h) in the worst case, where h is the height of the tree. In the best case, the tree is perfectly balanced, and the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-depth-of-binary-tree/description/)

---
{{< youtube ScvTcU2Aifs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
