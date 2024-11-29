
+++
authors = ["grid47"]
title = "Leetcode 113: Path Sum II"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 113: Path Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Backtracking","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/113.webp"
youtube = "MwLDG-WNOjM"
youtube_upload_date="2019-10-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MwLDG-WNOjM/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/113.webp" 
    alt="A radiant path of numbers, showing multiple possible paths with gentle branches leading to different sums."
    caption="Solution to LeetCode 113: Path Sum II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree and an integer targetSum, return all paths from the root to the leaf nodes where the sum of the node values along the path equals the targetSum. A root-to-leaf path is defined as any path that starts from the root and ends at a leaf node. A leaf node is a node that does not have any children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by the root node and an integer targetSum. The binary tree is represented as an array where each node is given by its value. Null values represent missing nodes.
- **Example:** `Input: root = [10,5,15,3,7,null,20], targetSum = 22`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 5000].
	- Each node value is between -1000 and 1000.
	- The targetSum is between -1000 and 1000.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of all root-to-leaf paths, where each path is represented as a list of node values that sum up to the given targetSum.
- **Example:** `Output: [[10,5,3], [10,15,20]]`
- **Constraints:**
	- Each path should be a valid root-to-leaf path with the sum of node values equal to targetSum.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to traverse the tree and accumulate the path sum from the root to the leaf nodes. If a path's sum matches the targetSum, it should be added to the result.

- Traverse the tree using depth-first search (DFS).
- At each node, subtract its value from targetSum and continue exploring both left and right children.
- If a leaf node is reached and the remaining sum equals 0, add the current path to the result.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid binary tree, where nodes have either zero, one, or two children.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10,5,15,3,7,null,20], targetSum = 22`  \
  **Explanation:** Starting from the root (10), we explore the left child (5) and its left child (3), which gives the path [10,5,3] with sum 22. We also explore the right child (15) and its right child (20), which gives the path [10,15,20] with sum 22.

- **Input:** `Input: root = [1,2,3], targetSum = 5`  \
  **Explanation:** No path from root to leaf sums up to 5. Therefore, the output is an empty list.

{{< dots >}}
## Approach 🚀
The solution involves using depth-first search (DFS) to traverse the tree. At each node, we reduce the targetSum by the current node value. If we reach a leaf node with the remaining targetSum equal to 0, we add that path to the result.

### Initial Thoughts 💭
- DFS is ideal for exploring all possible root-to-leaf paths.
- We need to ensure that when we reach a leaf node, we check if the path sum equals the targetSum.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (root is null), the output should be an empty list.
- The solution should efficiently handle trees with up to 5000 nodes.
- Handle negative targetSum and node values, ensuring the path sum calculation is correct even when values are negative.
- The solution should operate within time and space limits for trees with up to 5000 nodes.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int> > paths;
    vector<int> path;
    findPaths(root, sum, path, paths);
    return paths;  
}

void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {

    if (!node) return;

    path.push_back(node -> val);

    if (!(node -> left) && !(node -> right) && sum == node -> val)
        paths.push_back(path);

    findPaths(node -> left, sum - node -> val, path, paths);
    findPaths(node -> right, sum - node -> val, path, paths);

    path.pop_back();
}
```

This solution computes all root-to-leaf paths in a binary tree where the sum of node values equals the given target. It uses a backtracking approach to explore and record valid paths.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
	```
	Declare the main function to find all paths summing to a target value.

2. **Vector Initialization**
	```cpp
	    vector<vector<int> > paths;
	```
	Initialize a 2D vector to store all valid paths.

3. **Vector Initialization**
	```cpp
	    vector<int> path;
	```
	Initialize a 1D vector to temporarily store the current path.

4. **Recursive Call**
	```cpp
	    findPaths(root, sum, path, paths);
	```
	Invoke the helper function to find paths using backtracking.

5. **Return Statement**
	```cpp
	    return paths;  
	```
	Return the collection of all valid paths.

6. **Function Declaration**
	```cpp
	void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
	```
	Declare the helper function for recursive backtracking.

7. **Base Case**
	```cpp
	    if (!node) return;
	```
	Base case: If the node is null, terminate the current recursive call.

8. **Push Operation**
	```cpp
	    path.push_back(node -> val);
	```
	Add the current node's value to the path.

9. **Condition Evaluation**
	```cpp
	    if (!(node -> left) && !(node -> right) && sum == node -> val)
	```
	Check if the current node is a leaf and the remaining sum matches its value.

10. **Vector Insertion**
	```cpp
	        paths.push_back(path);
	```
	Record the current path as a valid result.

11. **Recursive Call**
	```cpp
	    findPaths(node -> left, sum - node -> val, path, paths);
	```
	Recursively explore the left subtree, updating the remaining sum.

12. **Recursive Call**
	```cpp
	    findPaths(node -> right, sum - node -> val, path, paths);
	```
	Recursively explore the right subtree, updating the remaining sum.

13. **Pop Operation**
	```cpp
	    path.pop_back();
	```
	Backtrack by removing the last node from the path.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we will traverse all nodes in the tree. Therefore, the time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursive call stack. In the worst case (unbalanced tree), h can be equal to n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/path-sum-ii/description/)

---
{{< youtube MwLDG-WNOjM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
