
+++
authors = ["grid47"]
title = "Leetcode 102: Binary Tree Level Order Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 102: Binary Tree Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/102.webp"
youtube = "6ZnyEApgFYg"
youtube_upload_date="2021-03-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6ZnyEApgFYg/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/102.webp" 
    alt="A tree with soft, glowing rings representing each level, expanding outward."
    caption="Solution to LeetCode 102: Binary Tree Level Order Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, your task is to return the level order traversal of its nodes' values. This means you should traverse the tree level by level, from left to right at each level.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree, where each node has a value and pointers to its left and right children.
- **Example:** `root = [5,3,8,1,4,null,9]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 2000].
	- -1000 <= Node.val <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a 2D array where each element represents a level in the binary tree. Each level is a list of node values at that level, traversed from left to right.
- **Example:** `Output: [[5], [3, 8], [1, 4, 9]]`
- **Constraints:**
	- The output should be an array of arrays where each inner array contains the values of the nodes at that level.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to perform a level order traversal of the binary tree using a queue to process nodes level by level.

- Start by checking if the root is null. If it is, return an empty list.
- Initialize a queue with the root node.
- While the queue is not empty, process each node at the current level.
- For each level, create a list of node values and add the left and right children of each node to the queue.
{{< dots >}}
### Problem Assumptions ✅
- The input is always a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3,9,20,null,null,15,7]`  \
  **Explanation:** The binary tree has the following structure:

       3
      / \
     9  20
        /  \
       15   7

The level order traversal is: [[3], [9, 20], [15, 7]]

- **Input:** `root = [1]`  \
  **Explanation:** The binary tree consists of just one node, which is the root node. The level order traversal is: [[1]]

- **Input:** `root = []`  \
  **Explanation:** An empty tree has no nodes, so the level order traversal is: []

{{< dots >}}
## Approach 🚀
The problem can be solved using a breadth-first search (BFS) approach where we explore the tree level by level, ensuring nodes at each level are processed from left to right.

### Initial Thoughts 💭
- Level order traversal can be efficiently implemented using a queue.
- By using a queue, we can ensure that we process nodes level by level, which is the key to solving this problem.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (i.e., the root is null), return an empty list.
- For large trees with up to 2000 nodes, ensure the solution handles the input efficiently.
- If a node has only one child (either left or right), make sure it is properly handled during the level order traversal.
- The tree must be processed within the provided constraints (2000 nodes).
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        vector<int> res;
        while(sz--) {
            TreeNode* tmp = q.front();
            res.push_back(tmp->val);
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        ans.push_back(res);
    }
    return ans;
}
```

This function performs a level-order traversal (BFS) on a binary tree, returning the values of each level in separate vectors.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> levelOrder(TreeNode* root) {
	```
	Define the function 'levelOrder' which takes the root of the tree and returns a 2D vector of integers, representing the tree's level-order traversal.

2. **Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initialize an empty 2D vector 'ans' to store the values of each level of the tree.

3. **Base Case**
	```cpp
	    if(!root) return ans;
	```
	If the tree is empty (root is NULL), return the empty result vector.

4. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Create a queue to assist in performing a breadth-first search (BFS). The queue will hold nodes at each level.

5. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Push the root node to the queue to begin the level-order traversal.

6. **Main BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	While the queue is not empty, continue processing the nodes level by level.

7. **Level Size**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue, which represents the number of nodes at the current level.

8. **Result Vector**
	```cpp
	        vector<int> res;
	```
	Initialize a temporary vector 'res' to hold the node values for the current level.

9. **Level Nodes Processing**
	```cpp
	        while(sz--) {
	```
	Process each node at the current level by looping through the queue until all nodes at this level are visited.

10. **Queue Front**
	```cpp
	            TreeNode* tmp = q.front();
	```
	Get the front node from the queue, which is the current node to be processed.

11. **Add Node Value**
	```cpp
	            res.push_back(tmp->val);
	```
	Add the value of the current node to the 'res' vector.

12. **Queue Pop**
	```cpp
	            q.pop();
	```
	Pop the processed node from the queue.

13. **Left Child Check**
	```cpp
	            if(tmp->left) q.push(tmp->left);
	```
	If the current node has a left child, push it onto the queue for the next level.

14. **Right Child Check**
	```cpp
	            if(tmp->right) q.push(tmp->right);
	```
	If the current node has a right child, push it onto the queue for the next level.

15. **Push Level to Result**
	```cpp
	        ans.push_back(res);
	```
	After processing all nodes at the current level, add the 'res' vector to the final result vector 'ans'.

16. **Return Result**
	```cpp
	    return ans;
	```
	Return the final 2D vector 'ans' which contains the level-order traversal of the tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, we must visit each node in the tree once, so the time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the queue may hold all the nodes at the last level of the tree, resulting in a space complexity of O(n). In the best case, when the tree is perfectly balanced, the space complexity could be reduced to O(log n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-level-order-traversal/description/)

---
{{< youtube 6ZnyEApgFYg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
