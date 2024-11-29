
+++
authors = ["grid47"]
title = "Leetcode 589: N-ary Tree Preorder Traversal"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 589: N-ary Tree Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/589.webp"
youtube = "2MjVm-hwyxs"
youtube_upload_date="2022-06-29"
youtube_thumbnail="https://i.ytimg.com/vi/2MjVm-hwyxs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/589.webp" 
    alt="An N-ary tree where each node is visited in preorder, with each visit softly glowing as the nodes are explored."
    caption="Solution to LeetCode 589: N-ary Tree Preorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of an n-ary tree, return the preorder traversal of its nodes' values. In one step, the node is visited first, followed by its children from left to right. The input is serialized in a level order format where each group of children is separated by a null value.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The root of an n-ary tree, represented in a serialized level order format, where each node and its children are listed sequentially. Each group of children is separated by a null value.
- **Example:** `Input: root = [10, null, 20, 30, 40, null, 50, 60]`
- **Constraints:**
	- 0 <= number of nodes <= 10^4
	- 0 <= Node.val <= 10^4
	- The height of the n-ary tree is <= 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** A list of integers representing the nodes' values in preorder traversal order.
- **Example:** `Output: [10, 20, 50, 60, 30, 40]`
- **Constraints:**
	- The output list contains integers in preorder traversal order of the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** Return the nodes' values in preorder traversal order.

- Start from the root node.
- Visit the node, then recursively visit its children in left to right order.
- Return the list of visited nodes' values.
{{< dots >}}
### Problem Assumptions ✅
- The tree is represented in level order format, with groups of children separated by null.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10, null, 20, 30, 40, null, 50, 60]`  \
  **Explanation:** Preorder traversal starts with the root node (10), followed by its children (20, 30, 40), and then recursively visits each child's children in the same manner.

- **Input:** `Input: root = [1, null, 2, 3, 4, 5, null, null, 6, 7, null, 8, null, 9, 10, null, null, 11, null, 12, null, 13, null, null, 14]`  \
  **Explanation:** This tree visits the root node (1), then its children (2, 3, 4), and continues recursively with the children of each node.

{{< dots >}}
## Approach 🚀
We can solve this problem using a recursive approach to traverse the tree in preorder.

### Initial Thoughts 💭
- Preorder traversal visits the node first and then its children.
- We can use a recursive function to perform the preorder traversal.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (root is null), return an empty list.
- The solution should be efficient enough to handle up to 10^4 nodes.
- If the tree has only one node, return that node.
- The tree height is less than or equal to 1000, so a recursive solution should work efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> ans;
void pre(Node* root) {
    if(root == NULL) return;
    ans.push_back(root->val);
    for(auto x: root->children)
        pre(x);
}
vector<int> preorder(Node* root) {
    pre(root);
    
    return ans;
}
```

This code defines a preorder traversal for a tree using a recursive helper function `pre`, which stores the node values in the global vector `ans`. The main function `preorder` calls this helper and returns the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	vector<int> ans;
	```
	Declares a global variable `ans`, a vector of integers, which will store the node values in preorder during the traversal.

2. **Function Declaration**
	```cpp
	void pre(Node* root) {
	```
	Declares the recursive helper function `pre`, which takes a pointer to the root of a node in the tree and performs the preorder traversal.

3. **Base Case**
	```cpp
	    if(root == NULL) return;
	```
	Checks if the current node is null (base case). If it is, the function returns immediately without doing any further processing.

4. **Push Current Node Value**
	```cpp
	    ans.push_back(root->val);
	```
	Pushes the current node's value to the `ans` vector to record it in the preorder sequence.

5. **Recursive Traversal**
	```cpp
	    for(auto x: root->children)
	```
	Iterates over each child of the current node (since it is assumed to be a tree or n-ary tree). The function recursively calls `pre` on each child.

6. **Recursive Call**
	```cpp
	        pre(x);
	```
	Recursively calls the `pre` function on the child node `x` to traverse deeper into the tree.

7. **Function Declaration**
	```cpp
	vector<int> preorder(Node* root) {
	```
	Declares the main `preorder` function, which initializes the preorder traversal by calling the helper function `pre` and then returns the result stored in the `ans` vector.

8. **Initial Traversal Call**
	```cpp
	    pre(root);
	```
	Calls the helper function `pre` to start the preorder traversal from the root node.

9. **Return Result**
	```cpp
	    return ans;
	```
	Returns the vector `ans`, which contains the values of the nodes in preorder.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursive call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)

---
{{< youtube 2MjVm-hwyxs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
