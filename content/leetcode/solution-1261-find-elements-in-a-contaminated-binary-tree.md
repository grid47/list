
+++
authors = ["grid47"]
title = "Leetcode 1261: Find Elements in a Contaminated Binary Tree"
date = "2024-07-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1261: Find Elements in a Contaminated Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Design","Binary Tree"]
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
Given a contaminated binary tree, recover it and implement a class to search for specific values in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a list of operations. Each operation is either the initialization of a tree or a search for a target value.
- **Example:** `[[[-1, null, -1]], [1], [2]]`
- **Constraints:**
	- The tree has at most 10^4 nodes.
	- Each node value is -1 initially.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a list where each entry corresponds to the result of a 'find' operation, indicating whether the target exists in the tree.
- **Example:** `[null, false, true]`
- **Constraints:**
	- The result of the 'find' operation is either true or false.

{{< dots >}}
### Core Logic 🔍
**Goal:** Recover the tree's original values and search for specific targets efficiently.

- 1. Initialize the tree with the given contaminated root.
- 2. Recover the values of each node using depth-first traversal.
- 3. Implement the 'find' operation by checking if the target exists in the recovered set of values.
{{< dots >}}
### Problem Assumptions ✅
- The input tree has been contaminated (all node values are initially -1).
- Each node follows the given value rules in the original uncontaminated tree.
{{< dots >}}
## Examples 🧩
- **Input:** `[[[-1, null, -1]], [1], [2]]`  \
  **Explanation:** In this example, after recovering the tree, the result of searching for 1 is 'false' and 2 is 'true'.

{{< dots >}}
## Approach 🚀
The problem can be solved by first recovering the tree values using a recursive depth-first search and then using a set to store these values for efficient lookups.

### Initial Thoughts 💭
- The binary tree follows a specific value pattern which allows for recursive recovery.
- Use recursion to recover each node value, starting from the root. Then, store the recovered values in a set for efficient querying.
{{< dots >}}
### Edge Cases 🌐
- The input tree is empty, which should not happen according to the problem constraints.
- The solution should efficiently handle trees with up to 10^4 nodes.
- The root value is always 0 and must be recovered first.
- Handle up to 10^4 nodes efficiently in both time and space.
{{< dots >}}
## Code 💻
```cpp
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
unordered_set<int> set;
public:
void recover(TreeNode* root, int x) {
    if(root == NULL) return;
    root->val = x;
    set.emplace(x);
    recover(root->left, 2*x+1);
    recover(root->right, 2*x+2);
    }
FindElements(TreeNode* root) {
    recover(root, 0);
}

bool find(int target) {
    return set.count(target);
}
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
```

This code defines the `FindElements` class, which is used to recover a binary tree where all nodes are initially set to an unknown value. It also provides a method to check if a given target value exists in the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class FindElements {
	```
	This defines the `FindElements` class, which is used to recover the binary tree and search for specific elements.

2. **Data Member**
	```cpp
	unordered_set<int> set;
	```
	This declares an unordered set `set` to store the recovered values from the binary tree for fast look-up.

3. **Access Modifier**
	```cpp
	public:
	```
	This sets the section following it to public access, making the methods accessible outside the class.

4. **Function Definition**
	```cpp
	void recover(TreeNode* root, int x) {
	```
	This defines the `recover` function, which is used to traverse the tree and recover the values by assigning values based on the binary tree's structure.

5. **Base Case**
	```cpp
	    if(root == NULL) return;
	```
	This is the base case of the recursion: if the node is `NULL`, the function returns without performing any operations.

6. **Node Value Assignment**
	```cpp
	    root->val = x;
	```
	This assigns the current node's value to `x`.

7. **Insert to Set**
	```cpp
	    set.emplace(x);
	```
	This inserts the node's value `x` into the `set` for fast lookup during search operations.

8. **Recursive Call (Left Child)**
	```cpp
	    recover(root->left, 2*x+1);
	```
	This recursively calls the `recover` function to process the left child of the current node, assigning it the value `2*x+1`.

9. **Recursive Call (Right Child)**
	```cpp
	    recover(root->right, 2*x+2);
	```
	This recursively calls the `recover` function to process the right child of the current node, assigning it the value `2*x+2`.

10. **Constructor Definition**
	```cpp
	FindElements(TreeNode* root) {
	```
	This defines the constructor of the `FindElements` class, which initializes the tree recovery process.

11. **Call to recover**
	```cpp
	    recover(root, 0);
	```
	This calls the `recover` function to recover the tree starting from the root node with an initial value of 0.

12. **Function Definition**
	```cpp
	bool find(int target) {
	```
	This defines the `find` function, which checks if a given target value exists in the recovered tree.

13. **Set Lookup**
	```cpp
	    return set.count(target);
	```
	This checks if the `target` value is present in the `set` and returns `true` if it is, or `false` otherwise.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N), where N is the number of nodes in the tree (for the recovery operation).
- **Average Case:** O(1) for each 'find' operation (due to the set lookup).
- **Worst Case:** O(N) for the recovery operation and O(1) for each 'find' operation.

The time complexity of the recovery operation is O(N), where N is the number of nodes in the tree. The time complexity of each 'find' operation is O(1) due to the set lookup.

### Space Complexity 💾
- **Best Case:** O(N) for the space used by the set storing the recovered values.
- **Worst Case:** O(N), where N is the number of nodes in the tree (for storing the recovered values).

The space complexity is O(N) for storing the recovered tree values in the set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
