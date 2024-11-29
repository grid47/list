
+++
authors = ["grid47"]
title = "Leetcode 530: Minimum Absolute Difference in BST"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 530: Minimum Absolute Difference in BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp"
youtube = "NttA_NC_ZhI"
youtube_upload_date="2024-06-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NttA_NC_ZhI/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp" 
    alt="A binary search tree where nodes light up showing the minimum absolute difference between node values."
    caption="Solution to LeetCode 530: Minimum Absolute Difference in BST Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a Binary Search Tree, which is represented as a list of integers where each value represents a node in the tree. Null values indicate absent nodes.
- **Example:** `Input: root = [4,2,6,1,3]`
- **Constraints:**
	- 2 <= The number of nodes in the tree <= 10^4
	- 0 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest absolute difference between values of any two nodes in the tree.
- **Example:** `Output: 1`
- **Constraints:**
	- The answer will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the minimum absolute difference between values of any two nodes in the BST.

- Perform an in-order traversal of the BST. In-order traversal of a BST yields a sorted list of values.
- For each adjacent pair of values in this sorted list, calculate the absolute difference.
- Track the minimum difference encountered.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid Binary Search Tree.
- The tree will contain at least two nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [4,2,6,1,3]`  \
  **Explanation:** An in-order traversal of the BST gives the values [1, 2, 3, 4, 6]. The minimum absolute difference is 1, as the closest pair is (2, 3).

{{< dots >}}
## Approach 🚀
To solve this problem, we will leverage an in-order traversal of the BST to generate a sorted list of node values, from which we can easily calculate the minimum absolute difference.

### Initial Thoughts 💭
- In-order traversal of a BST results in a sorted list of values.
- The minimum absolute difference between two nodes will always be between two adjacent nodes in the sorted list.
{{< dots >}}
### Edge Cases 🌐
- The tree has only one node (though this case is guaranteed not to happen due to the constraints).
- A tree with the maximum number of nodes (10^4 nodes).
- All nodes in the tree have the same value.
- Ensure correct handling of trees with multiple identical values.
{{< dots >}}
## Code 💻
```cpp
int getMinimumDifference(TreeNode* root) {
    TreeNode* prv = NULL; int ans = INT_MAX;
    stack<TreeNode*> stk;
    while(!stk.empty() || root) {
        if(root) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            if(prv != NULL) {
                ans = min(ans, root->val - prv->val);
            }
            prv = root;
            root = root->right;
        }
    }
    return ans;
}
```

This function computes the minimum absolute difference between values of any two nodes in a Binary Search Tree (BST). It uses an in-order traversal with a stack to traverse the tree iteratively and calculate the minimum difference between consecutive node values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition, Tree Traversal**
	```cpp
	int getMinimumDifference(TreeNode* root) {
	```
	Defines the `getMinimumDifference` function that calculates the minimum absolute difference between node values in a Binary Search Tree (BST). The function takes the root of the tree as an argument.

2. **Variable Initialization**
	```cpp
	    TreeNode* prv = NULL; int ans = INT_MAX;
	```
	Initializes a pointer `prv` to track the previous node during traversal and a variable `ans` to store the minimum difference, initially set to the maximum possible value (`INT_MAX`).

3. **Stack Initialization**
	```cpp
	    stack<TreeNode*> stk;
	```
	Creates a stack `stk` to assist with the in-order traversal of the tree. This stack helps simulate the recursion that would normally be used for tree traversal.

4. **While Loop, Tree Traversal**
	```cpp
	    while(!stk.empty() || root) {
	```
	Starts the while loop that continues until the stack is empty and the current node (`root`) is NULL, ensuring all nodes are visited.

5. **Condition, Node Traversal**
	```cpp
	        if(root) {
	```
	Checks if the current node (`root`) is not NULL, indicating there are still nodes to traverse in the tree.

6. **Push to Stack, Left Subtree**
	```cpp
	            stk.push(root);
	```
	Pushes the current node onto the stack to keep track of the path. This is part of the in-order traversal.

7. **Move to Left Child**
	```cpp
	            root = root->left;
	```
	Moves the current pointer to the left child of the current node, continuing the in-order traversal.

8. **Else Block, Backtrack**
	```cpp
	        } else {
	```
	Executes when the current node is NULL, indicating that the left subtree has been fully traversed and it's time to process the current node.

9. **Pop from Stack**
	```cpp
	            root = stk.top();
	```
	Pops the top element from the stack, which gives the node that is to be processed next in the in-order traversal.

10. **Pop Stack, Move to Next Node**
	```cpp
	            stk.pop();
	```
	Removes the current node from the stack after processing it.

11. **Check Previous Node**
	```cpp
	            if(prv != NULL) {
	```
	Checks if the previous node (`prv`) is not NULL, ensuring that there is a valid comparison between the current node and the previous one.

12. **Calculate Minimum Difference**
	```cpp
	                ans = min(ans, root->val - prv->val);
	```
	Calculates the minimum absolute difference between the current node's value and the previous node's value. If the difference is smaller than the current `ans`, it updates `ans`.

13. **Update Previous Node**
	```cpp
	            prv = root;
	```
	Updates the `prv` pointer to the current node, as it will be used for the next comparison.

14. **Move to Right Child**
	```cpp
	            root = root->right;
	```
	Moves the pointer to the right child of the current node to continue the in-order traversal.

15. **Return Minimum Difference**
	```cpp
	    return ans;
	```
	Returns the minimum absolute difference between node values found during the traversal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the tree, as we perform an in-order traversal and a single pass to calculate the differences.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the recursion stack of the in-order traversal, where n is the number of nodes, and O(h) in the best case, where h is the height of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)

---
{{< youtube NttA_NC_ZhI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
