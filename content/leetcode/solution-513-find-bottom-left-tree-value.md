
+++
authors = ["grid47"]
title = "Leetcode 513: Find Bottom Left Tree Value"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 513: Find Bottom Left Tree Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp"
youtube = "u_by_cTsNJA"
youtube_upload_date="2021-11-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/u_by_cTsNJA/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp" 
    alt="A tree with a glowing bottom-left node, showing the value of the deepest leftmost node in the binary tree."
    caption="Solution to LeetCode 513: Find Bottom Left Tree Value Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return the leftmost value in the last row of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree, represented as an array in level order.
- **Example:** `root = [1, 2, 3]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^4].
	- Node values range from -231 to 231 - 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the leftmost value in the last row of the tree.
- **Example:** `7`
- **Constraints:**
	- The output should be an integer, representing the leftmost value at the deepest level.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the leftmost value in the last row of the tree by traversing the tree level by level.

- 1. Initialize a queue for level order traversal.
- 2. Traverse the tree level by level using the queue.
- 3. For each level, update the result to the value of the first node in that level.
- 4. Continue until all levels have been processed.
- 5. Return the value of the first node of the last level.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree will be represented as an array using level order traversal.
- There will always be at least one node in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1, 2, 3]`  \
  **Explanation:** For the tree [1, 2, 3], the last row is at the second level, and the leftmost value is 2.

- **Input:** `root = [1, 2, 3, 4, null, 5, 6, null, null, 7]`  \
  **Explanation:** For the tree [1, 2, 3, 4, null, 5, 6, null, null, 7], the last row is at the fourth level, and the leftmost value is 7.

{{< dots >}}
## Approach 🚀
The approach is to use level order traversal (breadth-first search) to traverse the tree and capture the leftmost value in the last row.

### Initial Thoughts 💭
- Level order traversal is ideal for this problem, as it processes nodes row by row.
- We can use a queue to manage the nodes at each level.
- The leftmost value in the last row is always the first node encountered at the deepest level.
{{< dots >}}
### Edge Cases 🌐
- The tree will not be empty, as the problem guarantees at least one node.
- The approach efficiently handles up to 10^4 nodes with a time complexity of O(n).
- A tree with only one node should return that node's value.
- Ensure the tree is traversed level by level without skipping any levels.
{{< dots >}}
## Code 💻
```cpp
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int res = q.front()->val;
    while(!q.empty()) {
        int sz = q.size();
        res = q.front()->val;
        while(sz-- > 0) {
            root = q.front();
            q.pop();
            if(root->left)  q.push(root->left);
            if(root->right) q.push(root->right);                
        }
    }
    return res;
}
```

This solution uses a breadth-first search (BFS) approach to traverse the binary tree level by level, from left to right. It identifies the bottom-leftmost value of the tree by updating the result at each level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findBottomLeftValue(TreeNode* root) {
	```
	Defines the `findBottomLeftValue` function that takes a pointer to the root of a binary tree and returns the bottom-leftmost value.

2. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Declares a queue `q` to perform a breadth-first traversal of the tree.

3. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Pushes the root node of the tree into the queue to start the BFS.

4. **Initialize Result**
	```cpp
	    int res = q.front()->val;
	```
	Initializes `res` to store the value of the first node in the queue (i.e., the root node's value). This will be updated as we traverse the tree.

5. **BFS Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Starts a while loop that continues as long as the queue is not empty, ensuring all tree nodes are processed.

6. **Queue Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Calculates the number of nodes at the current level by checking the size of the queue.

7. **Update Result**
	```cpp
	        res = q.front()->val;
	```
	Updates `res` to the value of the leftmost node at the current level.

8. **Level Traversal Loop**
	```cpp
	        while(sz-- > 0) {
	```
	Begins an inner loop to process all nodes at the current level.

9. **Process Current Node**
	```cpp
	            root = q.front();
	```
	Assigns the front node of the queue to `root` for further processing.

10. **Pop Node from Queue**
	```cpp
	            q.pop();
	```
	Removes the front node from the queue after processing it.

11. **Push Left Child**
	```cpp
	            if(root->left)  q.push(root->left);
	```
	Pushes the left child of the current node to the queue if it exists.

12. **Push Right Child**
	```cpp
	            if(root->right) q.push(root->right);
	```
	Pushes the right child of the current node to the queue if it exists.

13. **Return Result**
	```cpp
	    return res;
	```
	Returns the value stored in `res`, which is the bottom-leftmost node's value.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the tree, as we traverse each node exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the queue storing nodes at the current level. In the best case (a skewed tree), the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-bottom-left-tree-value/description/)

---
{{< youtube u_by_cTsNJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
