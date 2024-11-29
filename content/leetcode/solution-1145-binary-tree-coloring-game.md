
+++
authors = ["grid47"]
title = "Leetcode 1145: Binary Tree Coloring Game"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1145: Binary Tree Coloring Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DIXDTh-aOQ4"
youtube_upload_date="2020-11-14"
youtube_thumbnail="https://i.ytimg.com/vi/DIXDTh-aOQ4/maxresdefault.jpg"
comments = true
+++



---
Two players play a turn-based game on a binary tree. We are given the root of the tree and the number of nodes, `n`, where `n` is odd, and each node has a distinct value from 1 to `n`. Player 1 selects a value `x` and colors the corresponding node red, while Player 2 selects a value `y` (where `y` ≠ `x`) and colors the corresponding node blue. Players take turns coloring neighboring nodes. The game ends when both players pass their turns, and the winner is the player who colored more nodes. Your task is to determine if Player 2 can guarantee a win by choosing a value `y`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of the binary tree, an integer `n` representing the total number of nodes, and an integer `x` representing the value Player 1 selects.
- **Example:** `Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3`
- **Constraints:**
	- 1 <= x <= n <= 100
	- n is odd
	- 1 <= Node.val <= n
	- All the values of the tree are unique

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if Player 2 can guarantee a win by choosing a value `y`, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**
	- The output should be a boolean value.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine if Player 2 can guarantee a win by choosing the right value `y`.

- 1. Traverse the tree and count the number of nodes in the left and right subtrees of the node where Player 1 colors the node.
- 2. Calculate the maximum number of nodes Player 2 can color by strategically choosing the correct starting node `y`.
- 3. Return true if Player 2 can color more nodes than Player 1; otherwise, return false.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary tree with no missing nodes.
- Player 1 always starts the game by selecting a node `x`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3`  \
  **Explanation:** In this case, Player 2 can select the node with value 2, which allows them to guarantee a win.

- **Input:** `Input: root = [1,2,3], n = 3, x = 1`  \
  **Explanation:** In this case, Player 1 can always win no matter what node Player 2 selects.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a depth-first search (DFS) to calculate the number of nodes in the left and right subtrees of the node where Player 1 colors a node. The key idea is to ensure Player 2 can color more nodes by strategically choosing the starting node `y`.

### Initial Thoughts 💭
- We need to track the number of nodes in the left and right subtrees of Player 1's node to calculate the optimal strategy for Player 2.
- A DFS approach can help us calculate the size of subtrees and determine the best node for Player 2 to start the game.
{{< dots >}}
### Edge Cases 🌐
- If the tree has no nodes, the game cannot be played.
- For large trees with up to 100 nodes, the solution should still be efficient.
- If `x` is the root node, Player 2 must select a neighboring node to start.
- The tree is always a valid binary tree with distinct node values.
{{< dots >}}
## Code 💻
```cpp
int lft, rht, val;
bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    val = x;
    cout<< n;
    n = count(root);
    cout<< n << "\n";        
    return max(max(lft, rht), n - lft-rht -1) > n/2;
}

int count(TreeNode* root) {
    if(!root) return 0;
    int l = count(root->left);
    int r = count(root->right);
    if(root->val == val)
    lft = l, rht = r;
    return l + r + 1;
}

};


```

This function determines if a player can win a binary tree game by making a move. It uses a recursive helper function `count` to calculate the size of the subtree rooted at a given node (denoted by `x`). The function compares the size of the largest subtree that can be isolated after the move to determine if it is greater than half the total number of nodes in the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int lft, rht, val;
	```
	The variables `lft`, `rht`, and `val` are declared. `lft` and `rht` will store the sizes of the left and right subtrees of the node `x`, while `val` stores the value of the node `x` for comparison in the recursive function.

2. **Function Definition**
	```cpp
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
	```
	The function `btreeGameWinningMove` is defined, which takes the root of the binary tree, the total number of nodes (`n`), and the value `x` of the target node to determine if the game can be won.

3. **Value Assignment**
	```cpp
	    val = x;
	```
	The value of `x` (the target node) is assigned to the `val` variable. This allows the program to identify the subtree rooted at node `x` during the recursion.

4. **Subtree Size Calculation**
	```cpp
	    n = count(root);
	```
	The function `count` is called with the root of the tree to calculate the size of the entire tree. This value is reassigned to `n`.

5. **Decision Making**
	```cpp
	    return max(max(lft, rht), n - lft - rht - 1) > n / 2;
	```
	This line calculates the largest possible subtree that can be isolated after a move, comparing the sizes of the left, right, and the remaining nodes. If the size of the largest subtree is greater than half the total tree size, it returns `true`, indicating a winning move.

6. **Helper Function Definition**
	```cpp
	int count(TreeNode* root) {
	```
	The helper function `count` is defined, which recursively calculates the size of the subtree rooted at `root`. It also checks whether the node matches the target node `x`.

7. **Base Case**
	```cpp
	    if(!root) return 0;
	```
	This is the base case of the recursion. If the `root` is null, it returns 0, indicating that there are no nodes in this subtree.

8. **Recursive Calls**
	```cpp
	    int l = count(root->left);
	```
	This recursively calls the `count` function on the left child of the current node to calculate the size of the left subtree.

9. **Recursive Calls**
	```cpp
	    int r = count(root->right);
	```
	This recursively calls the `count` function on the right child of the current node to calculate the size of the right subtree.

10. **Target Node Check**
	```cpp
	    if(root->val == val)
	```
	This checks if the current node is the target node `x` (whose value is stored in `val`). If true, the sizes of the left and right subtrees are stored in `lft` and `rht` respectively.

11. **Subtree Size Assignment**
	```cpp
	    lft = l, rht = r;
	```
	The sizes of the left and right subtrees are assigned to the variables `lft` and `rht` when the target node is found.

12. **Return Statement**
	```cpp
	    return l + r + 1;
	```
	This returns the size of the current subtree by summing the sizes of the left and right subtrees, and adding 1 for the current node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we visit each node in the tree once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursive call stack in the depth-first search.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-coloring-game/description/)

---
{{< youtube DIXDTh-aOQ4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
