
+++
authors = ["grid47"]
title = "Leetcode 1339: Maximum Product of Splitted Binary Tree"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1339: Maximum Product of Splitted Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
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
Given the root of a binary tree, you need to split the tree into two subtrees by removing one edge. The goal is to maximize the product of the sums of these two subtrees. Return the maximum product of the sums of the two subtrees, modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree with root node given as an array representation of the tree.
- **Example:** `root = [3,1,5,6,2,4]`
- **Constraints:**
	- 2 <= Number of nodes <= 5 * 10^4
	- 1 <= Node.val <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the maximum product of the sums of the two subtrees after removing one edge, modulo 10^9 + 7.
- **Example:** `For root = [3,1,5,6,2,4], the output will be 162.`
- **Constraints:**
	- The product must be calculated before taking modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the product of the sums of two subtrees formed by removing one edge in the binary tree.

- 1. Compute the total sum of the tree.
- 2. For each subtree formed by cutting an edge, compute its sum and multiply it with the remaining sum of the tree.
- 3. Track the maximum product of the sums.
- 4. Return the maximum product modulo 10^9 + 7.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a binary tree with integer node values.
- The tree will always contain at least 2 nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: root = [3,1,5,6,2,4]`  \
  **Explanation:** By removing the edge between node 5 and node 6, we split the tree into two subtrees with sums 21 and 3. The product of their sums is 63, and taking modulo (10^9 + 7) gives 162.

- **Input:** `Example 2: root = [10,5,15,3,7,6,20]`  \
  **Explanation:** By removing the edge between node 15 and node 20, we split the tree into two subtrees with sums 40 and 5. Their product is 1350.

{{< dots >}}
## Approach 🚀
To solve the problem, we first compute the total sum of the tree and then for each edge, compute the product of the two subtrees formed by cutting that edge.

### Initial Thoughts 💭
- We can perform a depth-first traversal to compute the sum of the entire tree and the sums of individual subtrees formed by cutting each edge.
- The most efficient way to compute the sums and maximize the product is by performing a post-order traversal where we calculate the sum of each subtree and simultaneously track the maximum product.
{{< dots >}}
### Edge Cases 🌐
- The tree cannot be empty as the problem guarantees a minimum of two nodes.
- The solution must handle large trees efficiently, with up to 50,000 nodes.
- All nodes having the same value may simplify the problem but must be handled correctly.
- The solution must consider both the computation of the sums and the efficient traversal of the tree.
{{< dots >}}
## Code 💻
```cpp
class Solution {
long long sum = 0, ans = INT_MIN;
public:
int maxProduct(TreeNode* root) {
    sum = ino(root);
    ino(root);
    return (int) (ans % (int) (1e9 + 7));
}
long long ino(TreeNode* root, bool s = true) {
    if (root == NULL) return 0;
    long long sub = ino(root->left) 
                  + ino(root->right)
                  + root->val;
    ans = max(ans, sub * (sum - sub));
    return sub;
}
```

This class finds the maximum product of a split binary tree, where the product is the value of the subtree times the remaining tree. It uses a postorder traversal to calculate subtree sums and then evaluates the maximum product.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	Declares the Solution class which contains the logic for solving the problem.

2. **Variable Declaration**
	```cpp
	long long sum = 0, ans = INT_MIN;
	```
	Declares and initializes variables sum (for total sum of tree values) and ans (for tracking the maximum product).

3. **Access Modifier**
	```cpp
	public:
	```
	Indicates that the following members are accessible from outside the class.

4. **Method Declaration**
	```cpp
	int maxProduct(TreeNode* root) {
	```
	Defines the public method `maxProduct` that computes the maximum product of splitting the binary tree.

5. **Function Call**
	```cpp
	    sum = ino(root);
	```
	Calls the helper function `ino` to calculate the total sum of all nodes in the tree and stores it in `sum`.

6. **Function Call**
	```cpp
	    ino(root);
	```
	Calls the helper function `ino` again to traverse the tree and update the `ans` variable with the maximum product.

7. **Return Statement**
	```cpp
	    return (int) (ans % (int) (1e9 + 7));
	```
	Returns the maximum product modulo (10^9 + 7), as the result might be too large.

8. **Helper Function Declaration**
	```cpp
	long long ino(TreeNode* root, bool s = true) {
	```
	Defines the recursive helper function `ino` for calculating subtree sums and updating the maximum product.

9. **Base Case**
	```cpp
	    if (root == NULL) return 0;
	```
	Handles the base case where the current node is null, returning 0 as the sum for an empty subtree.

10. **Recursive Call**
	```cpp
	    long long sub = ino(root->left) 
	```
	Recursively calculates the sum of the left subtree.

11. **Recursive Call**
	```cpp
	                  + ino(root->right)
	```
	Recursively calculates the sum of the right subtree.

12. **Subtree Calculation**
	```cpp
	                  + root->val;
	```
	Adds the value of the current node to the sum of the left and right subtrees.

13. **Maximum Product Calculation**
	```cpp
	    ans = max(ans, sub * (sum - sub));
	```
	Calculates the product of the current subtree sum and the remaining tree sum, updating `ans` if a larger product is found.

14. **Return Statement**
	```cpp
	    return sub;
	```
	Returns the sum of the current subtree to be used by its parent node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the tree.
- **Average Case:** O(n)
- **Worst Case:** O(n)

We perform two DFS traversals, each taking O(n) time, where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the tree and the recursive call stack during the DFS.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
