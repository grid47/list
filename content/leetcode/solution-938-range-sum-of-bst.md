
+++
authors = ["grid47"]
title = "Leetcode 938: Range Sum of BST"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 938: Range Sum of BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ISUXXRnKmx0"
youtube_upload_date="2020-04-30"
youtube_thumbnail="https://i.ytimg.com/vi/ISUXXRnKmx0/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary search tree and two integers, low and high, return the sum of values of all nodes whose values are within the inclusive range [low, high]. You can assume that all nodes in the tree have distinct values.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary search tree and two integers, low and high.
- **Example:** `Input: root = [12,8,15,6,10,14,18], low = 8, high = 15`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 2 * 10^4].
	- 1 <= Node.val <= 10^5
	- 1 <= low <= high <= 10^5
	- All Node.val are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all node values within the range [low, high].
- **Example:** `Output: 35`
- **Constraints:**
	- The sum should be within the range of integer values.

{{< dots >}}
### Core Logic 🔍
**Goal:** Traverse the binary search tree and calculate the sum of all nodes with values in the range [low, high]. Use a recursive or iterative approach to explore the tree and accumulate the sum.

- 1. Perform an in-order traversal of the tree.
- 2. For each node, check if its value is within the given range [low, high].
- 3. If the value is within range, add it to the sum.
- 4. Return the accumulated sum after traversing all the nodes.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a binary search tree, so the nodes follow the binary search property: left child < root < right child.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [12,8,15,6,10,14,18], low = 8, high = 15`  \
  **Explanation:** In this case, the nodes in the range [8, 15] are 8, 10, 12, and 15. The sum of these values is 35.

- **Input:** `Input: root = [12,8,15,6,10,14,18], low = 10, high = 18`  \
  **Explanation:** The nodes in the range [10, 18] are 10, 12, 15, and 14. The sum of these values is 51.

{{< dots >}}
## Approach 🚀
The approach to solve this problem is to traverse the tree in a depth-first manner (in-order traversal) and accumulate the values of the nodes that lie within the given range. Since it's a binary search tree, we can optimize the traversal by pruning branches that are outside the given range.

### Initial Thoughts 💭
- The problem can be efficiently solved using a recursive depth-first traversal of the binary search tree.
- By leveraging the binary search tree properties, we can prune unnecessary branches of the tree (e.g., if a node's value is smaller than low, we don't need to visit its left subtree).
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (root is null), return 0.
- Ensure the solution handles large trees with up to 20,000 nodes efficiently.
- If low equals high, we are looking for nodes with a single value.
- All node values are unique, so we don't need to handle duplicates.
{{< dots >}}
## Code 💻
```cpp

int rangeSumBST(TreeNode* root, int low, int high) {
    if(!root) return 0;
    int sum = 0;
    sum += rangeSumBST(root->left, low, high);
    if(root->val >= low && root->val <= high)
        sum += root->val;
    sum += rangeSumBST(root->right, low, high);
    return sum;
}
```

This code implements the `rangeSumBST` function that calculates the sum of values within a specified range [low, high] in a binary search tree. It uses a recursive approach to traverse the tree and accumulate the sum of the nodes' values within the range.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int rangeSumBST(TreeNode* root, int low, int high) {
	```
	Define the function `rangeSumBST`, which takes a binary search tree root node and a range [low, high] as input and returns the sum of all node values within this range.

2. **Base Case**
	```cpp
	    if(!root) return 0;
	```
	Check if the root is null. If so, return 0, as there are no values to sum.

3. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initialize a variable `sum` to 0. This will store the cumulative sum of values within the range [low, high].

4. **Left Subtree Traversal**
	```cpp
	    sum += rangeSumBST(root->left, low, high);
	```
	Recursively traverse the left subtree of the current root, adding the sum of values within the range to `sum`.

5. **Range Check**
	```cpp
	    if(root->val >= low && root->val <= high)
	```
	Check if the current node's value is within the specified range [low, high]. If so, include it in the sum.

6. **Value Addition**
	```cpp
	        sum += root->val;
	```
	If the current node's value is within the range, add it to the cumulative `sum`.

7. **Right Subtree Traversal**
	```cpp
	    sum += rangeSumBST(root->right, low, high);
	```
	Recursively traverse the right subtree of the current root, adding the sum of values within the range to `sum`.

8. **Return Result**
	```cpp
	    return sum;
	```
	Return the final accumulated sum of all node values within the specified range.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we need to visit every node in the tree. The time complexity is linear with respect to the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h) in the worst case due to the recursion stack, where h is the height of the tree. In the best case, the tree is balanced, and the space complexity is O(log n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/range-sum-of-bst/description/)

---
{{< youtube ISUXXRnKmx0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
