
+++
authors = ["grid47"]
title = "Leetcode 230: Kth Smallest Element in a BST"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 230: Kth Smallest Element in a BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/230.webp"
youtube = "PwjF3RO9djY"
youtube_upload_date="2024-06-23"
youtube_thumbnail="https://i.ytimg.com/vi/PwjF3RO9djY/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/230.webp" 
    alt="A binary search tree with nodes softly glowing, showing the kth smallest element highlighted."
    caption="Solution to LeetCode 230: Kth Smallest Element in a BST Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary search tree and an integer k, your task is to return the kth smallest value in the tree (1-indexed).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of a binary search tree (BST), represented as a tree structure. The second input is an integer k (1 <= k <= n), where n is the number of nodes in the tree.
- **Example:** `Input: root = [7, 3, 10, 2, 5, null, 15], k = 2`
- **Constraints:**
	- 1 <= k <= n <= 10^4
	- 0 <= Node.val <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer representing the kth smallest value in the binary search tree.
- **Example:** `Output: 3`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the kth smallest element in the binary search tree by leveraging the properties of the binary search tree and performing an in-order traversal.

- Perform an in-order traversal of the binary search tree.
- Keep track of the number of nodes visited during the traversal.
- Return the value of the kth node when the counter reaches k.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a valid binary search tree.
- There are no duplicate values in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [7, 3, 10, 2, 5, null, 15], k = 2`  \
  **Explanation:** In this tree, the inorder traversal would give the sequence: [2, 3, 5, 7, 10, 15]. The second smallest value is 3, so the output is 3.

- **Input:** `Input: root = [4, 2, 6, 1, 3, 5, 7], k = 3`  \
  **Explanation:** The inorder traversal of the tree gives: [1, 2, 3, 4, 5, 6, 7]. The third smallest value is 3, so the output is 3.

{{< dots >}}
## Approach 🚀
To find the kth smallest value in a binary search tree, an in-order traversal can be used since it visits nodes in ascending order for a BST.

### Initial Thoughts 💭
- In-order traversal of a BST gives the values in sorted order.
- By counting the nodes during the traversal, we can identify when we reach the kth smallest element.
{{< dots >}}
### Edge Cases 🌐
- If the root is null, there are no elements to traverse, and the problem should return an error or invalid result.
- For large trees, ensure the solution can handle up to 10^4 nodes without performance degradation.
- If the tree has a single node, that node will be the kth smallest for any k = 1.
- The solution must work within time limits for up to 10^4 nodes.
{{< dots >}}
## Code 💻
```cpp
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stk;
    // stk.push(root);
    TreeNode* node= root;
    while(!stk.empty() || node) {
        if(node) {
            stk.push(node);
            node = node->left;
        } else {
            node = stk.top();
            stk.pop();
            k--;
            if(k == 0) return node->val;
            node = node->right;
        }
    }
    return NULL;
}
```

This function finds the k-th smallest element in a binary search tree (BST) by performing an in-order traversal using a stack.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int kthSmallest(TreeNode* root, int k) {
	```
	Defines the function `kthSmallest` that takes the root of a binary tree and the value `k`, and returns the k-th smallest element in the BST.

2. **Variable Initialization**
	```cpp
	    stack<TreeNode*> stk;
	```
	Initializes a stack `stk` to assist with the in-order traversal of the tree.

3. **Variable Initialization**
	```cpp
	    TreeNode* node= root;
	```
	Assigns the root of the tree to the `node` pointer for traversal.

4. **Loop Control**
	```cpp
	    while(!stk.empty() || node) {
	```
	Begins a `while` loop that runs until both the stack is empty and there are no more nodes to visit.

5. **Condition Check**
	```cpp
	        if(node) {
	```
	Checks if the current `node` is not null, meaning there is still a node to visit.

6. **Push Node**
	```cpp
	            stk.push(node);
	```
	Pushes the current node onto the stack to process it later.

7. **Traverse Left**
	```cpp
	            node = node->left;
	```
	Moves to the left child of the current node for further traversal.

8. **Else Condition**
	```cpp
	        } else {
	```
	If the current node is null, it means we've reached the leftmost node and can start processing nodes from the stack.

9. **Pop Node**
	```cpp
	            node = stk.top();
	```
	Pops the top node from the stack, which is the next node in the in-order traversal.

10. **Pop Node**
	```cpp
	            stk.pop();
	```
	Removes the node from the stack after it has been processed.

11. **Decrement k**
	```cpp
	            k--;
	```
	Decrements the value of `k` as we move closer to finding the k-th smallest element.

12. **Kth Element Check**
	```cpp
	            if(k == 0) return node->val;
	```
	Checks if the current node is the k-th smallest element. If so, returns its value.

13. **Traverse Right**
	```cpp
	            node = node->right;
	```
	Moves to the right child of the current node to continue the in-order traversal.

14. **Return Null**
	```cpp
	    return NULL;
	```
	Returns `NULL` if no k-th smallest element is found, which should never happen for a valid input.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because the traversal must visit every node in the tree at least once.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the stack used in the traversal (for the recursive solution, it depends on the tree's height).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)

---
{{< youtube PwjF3RO9djY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
