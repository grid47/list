
+++
authors = ["grid47"]
title = "Leetcode 971: Flip Binary Tree To Match Preorder Traversal"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 971: Flip Binary Tree To Match Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6L25Q-42OXA"
youtube_upload_date="2021-03-29"
youtube_thumbnail="https://i.ytimg.com/vi/6L25Q-42OXA/maxresdefault.jpg"
comments = true
+++



---
You are given the root of a binary tree with n nodes, where each node has a unique value from 1 to n. You are also given a sequence of n integers, voyage, representing the desired pre-order traversal of the tree. A node in the tree can be flipped by swapping its left and right children. Your task is to find the smallest set of nodes to flip such that the pre-order traversal matches voyage. If it is impossible to achieve this traversal, return [-1].
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The root of a binary tree and an array voyage of n integers.
- **Example:** `Input: root = [1,2,3], voyage = [1,3,2]`
- **Constraints:**
	- The binary tree has n nodes.
	- n == voyage.length
	- 1 <= n <= 100
	- 1 <= Node.val, voyage[i] <= n
	- All node values and voyage elements are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** A list of nodes that need to be flipped to achieve the pre-order traversal defined by voyage.
- **Example:** `Output: [1]`
- **Constraints:**
	- If flipping nodes is impossible, return [-1].
	- The output list may be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Determine the minimum set of nodes to flip so that the binary tree's pre-order traversal matches voyage.

- Perform a recursive depth-first traversal of the tree.
- Match the current node's value with the current index in voyage.
- If the left child's value does not match the next value in voyage, flip the current node.
- Continue traversing the left and right subtrees, updating the traversal index.
- If any mismatch occurs that cannot be resolved by flipping, return [-1].
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is correctly structured.
- All node values are unique and match the elements in voyage.
- The voyage array defines a valid pre-order traversal for some arrangement of the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1,2,4,null,null,3], voyage = [1,3,2,4]`  \
  **Explanation:** Flipping node 1 swaps the left and right children, resulting in a traversal of [1,3,2,4]. Output: [1].

- **Input:** `Input: root = [1,2,3,4], voyage = [1,2,4,3]`  \
  **Explanation:** The pre-order traversal already matches voyage. Output: [].

{{< dots >}}
## Approach 🚀
Use a recursive depth-first search to traverse the binary tree and match its pre-order traversal to voyage.

### Initial Thoughts 💭
- Pre-order traversal visits nodes in root-left-right order.
- A mismatch between the current node's left child and voyage implies a flip may be needed.
- Flipping is only necessary when voyage cannot otherwise be matched.
- Start from the root and traverse the tree recursively.
- Keep track of the current position in voyage.
- If a mismatch occurs, check if flipping can resolve it.
{{< dots >}}
### Edge Cases 🌐
- An empty tree or empty voyage should return [].
- For a tree with 100 nodes, ensure the traversal does not exceed the recursion limit.
- If voyage is not a valid pre-order traversal of the tree, return [-1].
- If flipping the root resolves all mismatches, include the root's value in the output.
- Ensure the input tree is valid and matches the size of voyage.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> res;
int i = 0;
public:
vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> fail = {-1};
    return dfs(root, voyage)? res: fail;
}

bool dfs(TreeNode* node, vector<int> &voyage) {
    if(node == NULL) return true;
    if(node->val != voyage[i++]) return false;
    if(node->left != NULL && node->left->val != voyage[i]) {
        res.push_back(node->val);
        return  dfs(node->right, voyage) && dfs(node->left, voyage);
    }
    return  dfs(node->left, voyage) && dfs(node->right, voyage);
}
```

This is the solution that flips the binary tree nodes to match the given voyage sequence. It uses depth-first search (DFS) to traverse the tree and recursively checks whether the nodes match the voyage or need to be flipped.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> res;
	```
	A vector to store the nodes where a flip is required in the tree.

2. **Variable Initialization**
	```cpp
	int i = 0;
	```
	A variable `i` used to keep track of the current index in the `voyage` vector during the DFS traversal.

3. **Access Modifier**
	```cpp
	public:
	```
	Access modifier that indicates the following methods and members are public and can be accessed from outside the class.

4. **Function Definition**
	```cpp
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
	```
	Function that accepts a root of a tree and a `voyage` vector, and returns a vector of nodes that need to be flipped to match the voyage.

5. **Vector Initialization**
	```cpp
	    vector<int> fail = {-1};
	```
	Initializes a fail vector that is returned when the voyage cannot be matched.

6. **Return Statement**
	```cpp
	    return dfs(root, voyage)? res: fail;
	```
	Checks if the tree can be matched with the voyage using DFS, returning the result vector or the fail vector if matching is impossible.

7. **DFS Function Definition**
	```cpp
	bool dfs(TreeNode* node, vector<int> &voyage) {
	```
	The DFS helper function that performs a depth-first search on the tree to check if the nodes match the voyage sequence and handles flips where necessary.

8. **Base Case**
	```cpp
	    if(node == NULL) return true;
	```
	Base case: if the node is null, return true as there's nothing to process.

9. **Voyage Check**
	```cpp
	    if(node->val != voyage[i++]) return false;
	```
	Checks if the current node's value matches the current value in the voyage sequence. If not, the function returns false.

10. **Flip Check**
	```cpp
	    if(node->left != NULL && node->left->val != voyage[i]) {
	```
	Checks if the left child exists and its value does not match the current value in the voyage sequence, indicating that a flip might be needed.

11. **Recording the Flip**
	```cpp
	        res.push_back(node->val);
	```
	Records the current node's value in the `res` vector as a node where a flip occurred.

12. **DFS Recursion with Flip**
	```cpp
	        return  dfs(node->right, voyage) && dfs(node->left, voyage);
	```
	Recursively checks the right and left subtrees after flipping them to match the voyage.

13. **DFS Recursion without Flip**
	```cpp
	    return  dfs(node->left, voyage) && dfs(node->right, voyage);
	```
	Recursively checks the left and right subtrees without flipping them.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each node is visited once during the traversal, making the time complexity linear in the number of nodes.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(n)

The space complexity depends on the depth of the recursion stack, which is equal to the height h of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/description/)

---
{{< youtube 6L25Q-42OXA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
