
+++
authors = ["grid47"]
title = "Leetcode 655: Print Binary Tree"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 655: Print Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/655.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/655.webp" 
    alt="A binary tree where nodes are printed visually, with the structure softly glowing as it is printed."
    caption="Solution to LeetCode 655: Print Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, construct a matrix representation of the tree using specific formatting rules to place each node in the appropriate position in the matrix.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree represented as an array of nodes.
- **Example:** `root = [10, 5, 15, null, 7]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 210].
	- -99 <= Node.val <= 99
	- The depth of the tree will be in the range [1, 10].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a 0-indexed matrix representing the binary tree, formatted according to the specified rules.
- **Example:** `[['', '', '10', '', ''], ['', '5', '', '15', ''], ['', '', '', '7', '']]`
- **Constraints:**
	- The output matrix will be of size m x n, where m is the height of the tree + 1 and n is 2^height + 1 - 1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to recursively place each node in its appropriate position in the matrix based on the rules provided.

- 1. Calculate the height of the tree.
- 2. Calculate the width of the matrix using the tree height.
- 3. Recursively place the root node and its children in the matrix.
- 4. Fill in the left and right children by adjusting their positions accordingly in each row.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be a valid binary tree with nodes having unique values.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [10, 5, 15, null, 7]`  \
  **Explanation:** The root node `10` is placed in the center of the matrix. Its children, `5` and `15`, are placed in subsequent rows, with `7` placed as the child of `15`.

{{< dots >}}
## Approach 🚀
This problem can be solved by recursively placing each node at the appropriate position in a matrix based on the tree's structure.

### Initial Thoughts 💭
- This problem requires calculating the matrix dimensions based on the tree's height and recursively placing nodes.
- Recursive placement of nodes will involve carefully calculating the middle index of each row and adjusting for left and right children.
{{< dots >}}
### Edge Cases 🌐
- The tree will always contain at least one node.
- For trees with the maximum number of nodes, the solution should still function efficiently.
- The tree can have negative and zero values, which should be handled appropriately.
- Ensure that all nodes are placed correctly based on their position in the matrix.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> printTree(TreeNode* root) {
    int h = get_height(root), w = get_width(root);
    vector<vector<string>> ans(h, vector<string>(w, ""));
    helper(ans, root, 0, 0, w - 1);
    return ans;
}

int get_height(TreeNode *p) {
    if(!p) return 0;
    int left = get_height(p->left);
    int right = get_height(p->right);
    return max(left , right) + 1;
}

int get_width(TreeNode *p) {
    if(!p) return 0;
    int left = get_width(p->left);
    int right = get_width(p->right);
    return max(left, right)*2 + 1;
}

void helper(vector<vector<string>> &ans, TreeNode *p, int level, int l, int r) {
    if(!p) return;
    int mid = l + (r - l)/ 2;
    ans[level][mid] = to_string(p->val);
    helper(ans, p->left, level + 1, l, mid - 1);
    helper(ans, p->right, level + 1, mid + 1, r);        
}
};
```

This function prints a binary tree in a visual format. It uses a helper function to calculate the height and width of the tree, then places each node's value at the appropriate position in a 2D vector.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<string>> printTree(TreeNode* root) {
	```
	This is the header of the `printTree` function, which takes a pointer to the root of a binary tree and returns a 2D vector of strings representing the tree.

2. **Height and Width Calculation**
	```cpp
	    int h = get_height(root), w = get_width(root);
	```
	The height and width of the tree are calculated using the `get_height` and `get_width` functions. These values define the dimensions of the 2D array that will hold the tree values.

3. **2D Vector Initialization**
	```cpp
	    vector<vector<string>> ans(h, vector<string>(w, ""));
	```
	A 2D vector `ans` is initialized with dimensions `h` and `w`, where `h` is the height and `w` is the width of the tree. The vector is filled with empty strings to represent the unoccupied spaces.

4. **Helper Function Call**
	```cpp
	    helper(ans, root, 0, 0, w - 1);
	```
	The `helper` function is called to fill in the 2D vector with the values of the nodes at the correct positions.

5. **Return Result**
	```cpp
	    return ans;
	```
	The 2D vector `ans` is returned, which now contains the visual representation of the binary tree.

6. **Get Tree Height**
	```cpp
	int get_height(TreeNode *p) {
	```
	The `get_height` function calculates the height of a binary tree. It is used in the `printTree` function to determine the number of rows needed in the output.

7. **Base Case**
	```cpp
	    if(!p) return 0;
	```
	If the current node is null, the height is 0.

8. **Recursive Height Calculation**
	```cpp
	    int left = get_height(p->left);
	```
	Recursively calculate the height of the left subtree.

9. **Recursive Height Calculation**
	```cpp
	    int right = get_height(p->right);
	```
	Recursively calculate the height of the right subtree.

10. **Return Height**
	```cpp
	    return max(left , right) + 1;
	```
	The height of the current tree is the maximum of the left and right subtree heights, plus 1 for the current node.

11. **Get Tree Width**
	```cpp
	int get_width(TreeNode *p) {
	```
	The `get_width` function calculates the width of a binary tree. It is used in the `printTree` function to determine the number of columns needed in the output.

12. **Base Case**
	```cpp
	    if(!p) return 0;
	```
	If the current node is null, the width is 0.

13. **Recursive Width Calculation**
	```cpp
	    int left = get_width(p->left);
	```
	Recursively calculate the width of the left subtree.

14. **Recursive Width Calculation**
	```cpp
	    int right = get_width(p->right);
	```
	Recursively calculate the width of the right subtree.

15. **Return Width**
	```cpp
	    return max(left, right)*2 + 1;
	```
	The width of the tree is calculated as the maximum width of the left and right subtrees multiplied by 2, plus 1 for the current node.

16. **Helper Function**
	```cpp
	void helper(vector<vector<string>> &ans, TreeNode *p, int level, int l, int r) {
	```
	The `helper` function is a recursive function that fills the 2D vector `ans` with node values at the correct positions based on the tree structure.

17. **Base Case**
	```cpp
	    if(!p) return;
	```
	If the current node is null, the function returns without making changes.

18. **Calculate Middle Position**
	```cpp
	    int mid = l + (r - l)/ 2;
	```
	The middle column index is calculated to position the current node in the 2D vector.

19. **Place Node Value**
	```cpp
	    ans[level][mid] = to_string(p->val);
	```
	The value of the current node is placed in the 2D vector `ans` at the calculated middle position.

20. **Left Subtree**
	```cpp
	    helper(ans, p->left, level + 1, l, mid - 1);
	```
	Recursively call the helper function to place the left child in the appropriate position.

21. **Right Subtree**
	```cpp
	    helper(ans, p->right, level + 1, mid + 1, r);        
	```
	Recursively call the helper function to place the right child in the appropriate position.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and the matrix storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/print-binary-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
