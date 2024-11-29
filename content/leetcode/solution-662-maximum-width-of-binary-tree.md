
+++
authors = ["grid47"]
title = "Leetcode 662: Maximum Width of Binary Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 662: Maximum Width of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/662.webp"
youtube = "zHz0Ut1r-_8"
youtube_upload_date="2023-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/zHz0Ut1r-_8/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/662.webp" 
    alt="A binary tree where the maximum width is highlighted, with the width softly glowing as it’s measured."
    caption="Solution to LeetCode 662: Maximum Width of Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. Determine the maximum width of the tree, which is defined as the maximum width among all levels. The width of a level is the distance between the leftmost and rightmost non-null nodes, including null nodes in between that would be present in a complete binary tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root of a binary tree represented as an array of integers, where each integer is a node value or null if the node does not exist.
- **Example:** `root = [1, 3, 2, 5, 3, null, 9]`
- **Constraints:**
	- 1 <= number of nodes <= 3000
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the maximum width of the binary tree.
- **Example:** `4`
- **Constraints:**
	- The output is guaranteed to be within the range of a 32-bit signed integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the maximum width of the binary tree by finding the maximum width across all levels of the tree.

- 1. Use a breadth-first search (BFS) approach to traverse the tree level by level.
- 2. At each level, compute the width by calculating the difference between the positions of the leftmost and rightmost non-null nodes.
- 3. Keep track of the maximum width encountered during the traversal.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is represented as a complete binary tree with null values for missing nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1, 3, 2, 5, 3, null, 9]`  \
  **Explanation:** The maximum width is at level 3 with the nodes [5, 3, null, 9], which gives a width of 4.

- **Input:** `root = [1, 3, 2, 5, null, null, 9, 6, null, 7]`  \
  **Explanation:** The maximum width is at level 4 with the nodes [6, null, null, null, null, null, 7], which gives a width of 7.

{{< dots >}}
## Approach 🚀
The approach for this problem uses a breadth-first search (BFS) to traverse the tree level by level, calculating the width at each level.

### Initial Thoughts 💭
- We can use BFS to explore each level of the tree.
- To calculate the width, we need to track the positions of nodes at each level.
- We should be able to find the width by using a queue to track the nodes and their positions in the tree.
{{< dots >}}
### Edge Cases 🌐
- The tree will always have at least one node.
- The algorithm needs to handle large trees with up to 3000 nodes efficiently.
- If a tree contains null values at various positions, these should be counted when calculating the width of the tree.
- Ensure that the width is calculated by including null nodes in the level width.
{{< dots >}}
## Code 💻
```cpp
int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;
    queue<pair<TreeNode*, int>> q;
    int width = 0;
    q.push({root, 0});
    while(!q.empty()) {
        int f = q.front().second;
        int b = q.back().second;
        int cnt = q.size();
        for(int i = 0; i < cnt; i++) {
            TreeNode* elem = q.front().first;
            int idx = q.front().second - b;
            q.pop();
            if(elem->left  != NULL) q.push({elem->left,  2 * idx + 1});
            if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});                
        }
        width = max(width, b - f + 1);
    }
    return width;
}
```

This function calculates the maximum width of a binary tree, which is defined as the maximum number of nodes present at any level of the tree.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int widthOfBinaryTree(TreeNode* root) {
	```
	This is the function definition for `widthOfBinaryTree`, which calculates the maximum width of a binary tree. It takes the root node of the tree as input and returns an integer value representing the width.

2. **Base Case**
	```cpp
	    if(root == NULL) return 0;
	```
	If the tree is empty (root is NULL), return 0 as the width.

3. **Queue Initialization**
	```cpp
	    queue<pair<TreeNode*, int>> q;
	```
	Initialize a queue `q` to store pairs of nodes and their corresponding indices in the tree. The index helps track the position of nodes at each level.

4. **Width Initialization**
	```cpp
	    int width = 0;
	```
	Initialize a variable `width` to track the maximum width of the tree, starting with a value of 0.

5. **Initial Node Push**
	```cpp
	    q.push({root, 0});
	```
	Push the root node into the queue with an index of 0.

6. **While Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Start a `while` loop that continues as long as the queue is not empty, processing each level of the tree.

7. **Front Node Index**
	```cpp
	        int f = q.front().second;
	```
	Get the index of the first node in the queue. This index represents the position of the leftmost node at the current level.

8. **Back Node Index**
	```cpp
	        int b = q.back().second;
	```
	Get the index of the last node in the queue. This index represents the position of the rightmost node at the current level.

9. **Queue Size**
	```cpp
	        int cnt = q.size();
	```
	Get the number of nodes at the current level by checking the size of the queue.

10. **Level Processing Loop**
	```cpp
	        for(int i = 0; i < cnt; i++) {
	```
	Start a loop to process each node at the current level.

11. **Pop Front Node**
	```cpp
	            TreeNode* elem = q.front().first;
	```
	Pop the first node from the queue and retrieve the node itself (`elem`).

12. **Calculate Node Index**
	```cpp
	            int idx = q.front().second - b;
	```
	Calculate the adjusted index for the current node by subtracting the index of the rightmost node (`b`). This helps to prevent overflow and handle large trees efficiently.

13. **Pop Node from Queue**
	```cpp
	            q.pop();
	```
	Remove the processed node from the queue.

14. **Push Left Child**
	```cpp
	            if(elem->left  != NULL) q.push({elem->left,  2 * idx + 1});
	```
	If the current node has a left child, push it to the queue with its new index calculated as `2 * idx + 1`.

15. **Push Right Child**
	```cpp
	            if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});
	```
	If the current node has a right child, push it to the queue with its new index calculated as `2 * idx + 2`.

16. **Update Maximum Width**
	```cpp
	        width = max(width, b - f + 1);
	```
	Update the `width` variable with the maximum width of the current level, calculated as the difference between the indices of the last and first nodes, plus one.

17. **Return Result**
	```cpp
	    return width;
	```
	Return the maximum width of the binary tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we process each node once during the BFS traversal.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use a queue to store nodes during the BFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)

---
{{< youtube zHz0Ut1r-_8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
