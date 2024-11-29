
+++
authors = ["grid47"]
title = "Leetcode 979: Distribute Coins in Binary Tree"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 979: Distribute Coins in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "YfdfIOeV_RU"
youtube_upload_date="2024-05-18"
youtube_thumbnail="https://i.ytimg.com/vi/YfdfIOeV_RU/maxresdefault.jpg"
comments = true
+++



---
You are given a binary tree with `n` nodes, where each node contains `node.val` coins. There are exactly `n` coins in total across the tree. In one move, you can transfer a coin between two adjacent nodes (parent to child or child to parent). Return the minimum number of moves required to ensure that every node has exactly one coin.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A binary tree represented by an array of integers, where each integer corresponds to the number of coins at that node.
- **Example:** `root = [1, 0, 0]`
- **Constraints:**
	- 1 <= n <= 100
	- 0 <= Node.val <= n
	- The sum of all Node.val is n.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to make every node have exactly one coin.
- **Example:** `2`
- **Constraints:**
	- The output must be an integer representing the minimum number of moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to calculate the minimum moves by redistributing coins across the binary tree.

- Traverse the tree recursively.
- For each node, calculate the difference between the node's coin count and the desired coin count (which is 1).
- Accumulate the total moves by summing the absolute differences in coin count for each subtree.
- Return the total number of moves.
{{< dots >}}
### Problem Assumptions ✅
- The tree is well-formed, and all nodes are valid.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1, 0, 0]`  \
  **Explanation:** The root node has one coin, and both children have none. The solution involves moving coins from the root to its children to balance the tree.

- **Input:** `root = [0, 2, 0]`  \
  **Explanation:** In this case, two coins are initially at the left child. We move coins to the root and then move one coin to the right child.

{{< dots >}}
## Approach 🚀
A recursive approach is used to traverse the tree, compute the difference in coins for each node, and calculate the total moves required.

### Initial Thoughts 💭
- Each node needs to have exactly one coin.
- The total number of coins in the tree is already fixed and equal to the number of nodes.
- We need to find an efficient way to traverse the tree and redistribute coins to meet the target distribution.
{{< dots >}}
### Edge Cases 🌐
- An empty tree is not a valid input based on the constraints.
- For large inputs, ensure that the algorithm handles the maximum number of nodes efficiently.
- If all nodes already have one coin, no moves are needed.
- The tree must contain at least one node.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int mv;
public:
int distributeCoins(TreeNode* root) {
    mv = 0;
    move(root, mv);
    return mv;
}

int move(TreeNode* r, int & mv) {
    if(r == nullptr) return 0;
    int left = move(r->left, mv);
    int right = move(r->right, mv);
    mv += abs(left) + abs(right);
    return r->val + left + right - 1;
}
```

This code defines a solution to the problem of distributing coins in a binary tree, where each node has a coin, and the goal is to find the minimum number of moves required to balance the tree such that each node has exactly one coin.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Defines the class `Solution` which contains methods for solving the problem of distributing coins in a binary tree.

2. **Member Variable Declaration**
	```cpp
	int mv;
	```
	Declares a member variable `mv` which will hold the number of moves required to balance the coins in the binary tree.

3. **Public Method Declaration**
	```cpp
	public:
	```
	Begins the public section of the class, where the methods that can be accessed from outside the class are defined.

4. **Main Method**
	```cpp
	int distributeCoins(TreeNode* root) {
	```
	Defines the method `distributeCoins` which takes a pointer to the root of the binary tree and returns the minimum number of moves required to balance the coins.

5. **Initialize Moves**
	```cpp
	    mv = 0;
	```
	Initializes the `mv` variable to 0, which will be used to count the number of moves needed to balance the coins.

6. **Recursive Call to Move**
	```cpp
	    move(root, mv);
	```
	Calls the helper method `move` to recursively calculate the required moves, passing the root node and the `mv` variable.

7. **Return Result**
	```cpp
	    return mv;
	```
	Returns the total number of moves required to balance the tree.

8. **Helper Method Declaration**
	```cpp
	int move(TreeNode* r, int & mv) {
	```
	Defines the helper method `move`, which is a recursive function that calculates the number of moves required for each node to balance the coins in its subtree.

9. **Base Case**
	```cpp
	    if(r == nullptr) return 0;
	```
	Checks if the current node is null. If so, it returns 0, as no moves are needed for a non-existent node.

10. **Recursive Call for Left Subtree**
	```cpp
	    int left = move(r->left, mv);
	```
	Recursively calls the `move` method on the left child of the current node to calculate the number of moves for the left subtree.

11. **Recursive Call for Right Subtree**
	```cpp
	    int right = move(r->right, mv);
	```
	Recursively calls the `move` method on the right child of the current node to calculate the number of moves for the right subtree.

12. **Calculate Moves for Current Node**
	```cpp
	    mv += abs(left) + abs(right);
	```
	Calculates the total number of moves for the current node by adding the absolute values of the moves required for the left and right subtrees.

13. **Return Value for Current Node**
	```cpp
	    return r->val + left + right - 1;
	```
	Returns the value for the current node, adjusting for the moves required by its left and right children, and subtracting 1 because each node starts with one coin.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution requires traversing every node in the tree once, resulting in a time complexity of O(n).

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h) where h is the height of the tree due to recursion stack usage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/distribute-coins-in-binary-tree/description/)

---
{{< youtube YfdfIOeV_RU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
