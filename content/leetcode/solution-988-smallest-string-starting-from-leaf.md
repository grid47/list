
+++
authors = ["grid47"]
title = "Leetcode 988: Smallest String Starting From Leaf"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 988: Smallest String Starting From Leaf in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UvdWfxQ_ZDs"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/UvdWfxQ_ZDs/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree, where each node contains a value between 0 and 25, corresponding to letters from 'a' to 'z'. Your task is to find the lexicographically smallest string that can be formed by traversing from a leaf node to the root node, using the values in each node as letters.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree, where each node has an integer value in the range [0, 25].
- **Example:** `root = [0, 1, 2, 3, 4, 3, 4]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 8500.
	- 0 <= Node.val <= 25.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the lexicographically smallest string that starts from a leaf node and ends at the root.
- **Example:** `Output: "dbd"`
- **Constraints:**
	- The string must be constructed by following the path from a leaf node to the root.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the binary tree from each leaf node to the root, constructing strings and determining the lexicographically smallest one.

- Traverse the tree recursively from root to leaf nodes.
- At each leaf node, generate the corresponding string by adding the character of the node to the string.
- Compare the generated string with the current smallest string and update accordingly.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a binary tree with no cycles.
- The tree contains at least one node (i.e., the root is not null).
{{< dots >}}
## Examples 🧩
- **Input:** `root = [0, 1, 2, 3, 4, 3, 4]`  \
  **Explanation:** In this example, the binary tree has leaf nodes with values corresponding to 'd', 'b', and 'd'. The lexicographically smallest string is formed by starting from the leaf 'd' and traversing back to the root, resulting in 'dbd'.

{{< dots >}}
## Approach 🚀
The approach involves recursively traversing the tree and constructing strings from leaf nodes to the root while keeping track of the lexicographically smallest string.

### Initial Thoughts 💭
- We need to traverse each path from a leaf to the root and compare the strings lexicographically.
- Using recursion allows us to easily explore all paths from leaf to root and compare the strings efficiently.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where the tree has only one node.
- Ensure the solution handles the maximum number of nodes efficiently.
- Consider trees with values representing letters near the boundaries of the alphabet, such as 'a' (0) or 'z' (25).
- Ensure the algorithm runs efficiently for a large number of nodes and is optimized for recursion.
{{< dots >}}
## Code 💻
```cpp
string ans = "~";
string smallestFromLeaf(TreeNode* root) {
    recur(root, "");
    return ans;
}
void recur(TreeNode* node, string s) {
    if(!node) return;
    if(!node->left && !node->right) {
        ans = min(ans, char(node->val + 'a') + s);
    }
    cout << node->val<<'\n';
    recur(node->left,  char(node->val + 'a') + s);
    recur(node->right, char(node->val + 'a') + s);  
}
```

This code defines the function `smallestFromLeaf` to find the lexicographically smallest string starting from the leaf node to the root in a binary tree. It uses recursion (`recur`) to traverse the tree and track the path from leaf to root, updating the answer string as it goes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	string ans = "~";
	```
	Initializes the variable `ans` to `~`, which will be used to store the smallest string found from a leaf to the root during the traversal.

2. **Function Definition**
	```cpp
	string smallestFromLeaf(TreeNode* root) {
	```
	Defines the function `smallestFromLeaf`, which takes the root node of a binary tree and returns the lexicographically smallest string from a leaf node to the root.

3. **Recursive Call**
	```cpp
	    recur(root, "");
	```
	Calls the helper function `recur` to start the recursive traversal of the tree. The empty string `""` is passed as the initial path.

4. **Return Result**
	```cpp
	    return ans;
	```
	Returns the variable `ans`, which contains the lexicographically smallest string from a leaf node to the root after the recursion completes.

5. **Helper Function Definition**
	```cpp
	void recur(TreeNode* node, string s) {
	```
	Defines the helper function `recur`, which performs the recursive traversal of the binary tree, building the string path from the leaf to the root.

6. **Base Case**
	```cpp
	    if(!node) return;
	```
	Checks if the current node is null, which is the base case for recursion. If the node is null, the function returns without doing anything.

7. **Leaf Node Check**
	```cpp
	    if(!node->left && !node->right) {
	```
	Checks if the current node is a leaf node (both left and right children are null). If it's a leaf, the function proceeds to check and update the answer.

8. **Update Answer**
	```cpp
	        ans = min(ans, char(node->val + 'a') + s);
	```
	Updates the `ans` variable with the lexicographically smaller string between the current `ans` and the string formed by adding the current node's value (converted to a character) to the path `s`.

9. **Recursive Call for Left Child**
	```cpp
	    recur(node->left,  char(node->val + 'a') + s);
	```
	Recursively calls the `recur` function for the left child of the current node, passing the current node's value (converted to a character) prepended to the string path `s`.

10. **Recursive Call for Right Child**
	```cpp
	    recur(node->right, char(node->val + 'a') + s);  
	```
	Recursively calls the `recur` function for the right child of the current node, prepending the current node's value (converted to a character) to the string path `s`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) where n is the number of nodes, as each node is visited once.
- **Average Case:** O(n) where n is the number of nodes, as each node contributes to a string comparison.
- **Worst Case:** O(n) where n is the number of nodes, since we visit each node in the tree once.

The time complexity is O(n), where n is the number of nodes in the tree, due to the tree traversal.

### Space Complexity 💾
- **Best Case:** O(1) if the tree is very shallow or balanced.
- **Worst Case:** O(h) where h is the height of the tree, due to recursion stack space.

The space complexity is O(h), where h is the height of the tree, due to recursion.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/)

---
{{< youtube UvdWfxQ_ZDs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
