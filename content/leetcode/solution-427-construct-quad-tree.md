
+++
authors = ["grid47"]
title = "Leetcode 427: Construct Quad Tree"
date = "2024-09-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 427: Construct Quad Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Tree","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/427.webp"
youtube = "UQ-1sBMV0v4"
youtube_upload_date="2023-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/UQ-1sBMV0v4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/427.webp" 
    alt="A grid where sections gently form a quad tree, each section glowing as it is constructed."
    caption="Solution to LeetCode 427: Construct Quad Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an n x n binary grid of 0's and 1's. Your task is to represent this grid with a Quad-Tree. A Quad-Tree is a tree structure where each node has four children. Each internal node has two properties: `val` (True for a grid of 1's or False for a grid of 0's) and `isLeaf` (True if the node is a leaf, False if it has children). If the entire grid has the same value, the node is a leaf. If not, the grid is divided into four sub-grids, and the process is repeated recursively for each sub-grid. Your goal is to return the root of the Quad-Tree that represents the grid.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a grid, which is a 2D array of integers where each element is either 0 or 1. The grid is guaranteed to be a perfect square (n x n).
- **Example:** `[[0, 1], [1, 0]]`
- **Constraints:**
	- 1 <= n <= 64
	- grid is a 2D array of 0's and 1's

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the root of the Quad-Tree that represents the input grid. The Quad-Tree is serialized using a level-order traversal where each node is represented as a list with two values: `[isLeaf, val]`. If the node is a leaf, isLeaf is 1, and the value `val` is either 1 for True or 0 for False. Internal nodes are represented with isLeaf 0 and any value for val.
- **Example:** `[[0, 1], [1, 0], [1, 1], [1, 1], [1, 0]]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to recursively divide the grid into four quadrants and create a tree structure where each node represents a square of the grid. If all elements in the square are the same, the node is a leaf; otherwise, it is an internal node with four children.

- 1. Start with the whole grid.
- 2. If the grid is a 1x1 grid, return a leaf node.
- 3. If all elements of the grid are the same, return a leaf node with val set to that element's value.
- 4. Otherwise, split the grid into four sub-grids and recursively construct the Quad-Tree for each sub-grid.
- 5. If all four sub-grids have the same value, merge them into a single leaf node.
{{< dots >}}
### Problem Assumptions ✅
- The grid is square and consists of only 0's and 1's.
- The value of n is always a power of 2.
{{< dots >}}
## Examples 🧩
- **Input:** `[[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]`  \
  **Explanation:** This grid is split into four sub-grids. The top-left, bottom-left, and bottom-right sub-grids are uniform, while the top-right sub-grid has a mix of 1's and 0's. These sub-grids are further divided, leading to a Quad-Tree that efficiently represents the entire grid.

{{< dots >}}
## Approach 🚀
The approach to solving this problem involves recursively dividing the grid into smaller sub-grids and constructing the Quad-Tree based on the uniformity of the values in the sub-grids.

### Initial Thoughts 💭
- Each grid is divided into four quadrants at each step.
- If all elements of a sub-grid are the same, it can be represented as a leaf node.
- Recursive approach seems ideal, where we break down the grid into smaller grids and represent uniform grids as leaf nodes.
{{< dots >}}
### Edge Cases 🌐
- A grid with all elements as 0 or all elements as 1 will immediately return a leaf node.
- If n is large, the recursive approach may encounter performance issues, so optimization or memoization might be needed.
- Grids with a single 0 or 1 will result in a very simple tree with just one node.
- Only grids with dimensions that are powers of 2 need to be considered.
{{< dots >}}
## Code 💻
```cpp
Node* construct(vector<vector<int>>& grid) {
    return helper(grid, 0, 0, grid.size());
}

Node* helper(vector<vector<int>> &grid, int x, int y, int sz) {
    if(sz == 1) return new Node(grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
    Node* res = new Node();
    Node* topRight    = helper(grid, x , y+sz/2, sz / 2);
    Node* topLeft     = helper(grid, x , y, sz / 2);
    Node* bottomRight = helper(grid, x +sz/2, y+sz/2, sz / 2);
    Node* bottomLeft  = helper(grid, x +sz/2, y, sz / 2);

    if(topRight->isLeaf && topLeft->isLeaf && bottomRight->isLeaf && bottomLeft->isLeaf && 
    topLeft->val == topRight->val && topRight->val == bottomRight->val && bottomRight->val == bottomLeft->val) {
        res->val = topLeft->val;
        res-> isLeaf = true;
    } else {
         res->topRight    = topRight;   
         res->topLeft     = topLeft;   
         res->bottomRight = bottomRight;   
         res->bottomLeft  = bottomLeft;       
    }
    return res;
}


```

This code constructs a quadtree from a 2D grid using a divide-and-conquer approach. Each node represents a quadrant of the grid, and the recursion merges nodes if all child quadrants have the same value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	Node* construct(vector<vector<int>>& grid) {
	```
	Defines the `construct` function that initializes the recursive construction of the quadtree by calling the `helper` function with the entire grid.

2. **Recursive Call**
	```cpp
	    return helper(grid, 0, 0, grid.size());
	```
	Initiates the recursive construction of the quadtree starting from the top-left corner of the grid with its full size.

3. **Helper Function Declaration**
	```cpp
	Node* helper(vector<vector<int>> &grid, int x, int y, int sz) {
	```
	Defines the `helper` function, which recursively divides the grid into quadrants and constructs nodes for the quadtree.

4. **Base Case**
	```cpp
	    if(sz == 1) return new Node(grid[x][y] != 0, true, NULL, NULL, NULL, NULL);
	```
	Handles the base case: if the grid size is 1, creates a leaf node with the grid value indicating whether it is true (non-zero) or false (zero).

5. **Node Initialization**
	```cpp
	    Node* res = new Node();
	```
	Creates a new node to represent the current region of the grid.

6. **Recursive Subdivision**
	```cpp
	    Node* topRight    = helper(grid, x , y+sz/2, sz / 2);
	```
	Recursively constructs the top-right quadrant of the current grid region.

7. **Recursive Subdivision**
	```cpp
	    Node* topLeft     = helper(grid, x , y, sz / 2);
	```
	Recursively constructs the top-left quadrant of the current grid region.

8. **Recursive Subdivision**
	```cpp
	    Node* bottomRight = helper(grid, x +sz/2, y+sz/2, sz / 2);
	```
	Recursively constructs the bottom-right quadrant of the current grid region.

9. **Recursive Subdivision**
	```cpp
	    Node* bottomLeft  = helper(grid, x +sz/2, y, sz / 2);
	```
	Recursively constructs the bottom-left quadrant of the current grid region.

10. **Merge Condition**
	```cpp
	    if(topRight->isLeaf && topLeft->isLeaf && bottomRight->isLeaf && bottomLeft->isLeaf && 
	```
	Checks if all child nodes are leaves and have the same value, allowing them to be merged into a single leaf node.

11. **Merge Nodes**
	```cpp
	    topLeft->val == topRight->val && topRight->val == bottomRight->val && bottomRight->val == bottomLeft->val) {
	```
	Ensures that the values of all child nodes are equal before merging them.

12. **Set Leaf Node**
	```cpp
	        res->val = topLeft->val;
	```
	Assigns the value of the child nodes to the parent node since all child nodes have the same value.

13. **Set Leaf Flag**
	```cpp
	        res-> isLeaf = true;
	```
	Marks the current node as a leaf node because all child nodes were merged.

14. **Assign Children**
	```cpp
	         res->topRight    = topRight;   
	```
	Assigns the top-right child to the current node when the children cannot be merged.

15. **Assign Children**
	```cpp
	         res->topLeft     = topLeft;   
	```
	Assigns the top-left child to the current node when the children cannot be merged.

16. **Assign Children**
	```cpp
	         res->bottomRight = bottomRight;   
	```
	Assigns the bottom-right child to the current node when the children cannot be merged.

17. **Assign Children**
	```cpp
	         res->bottomLeft  = bottomLeft;       
	```
	Assigns the bottom-left child to the current node when the children cannot be merged.

18. **Return Node**
	```cpp
	    return res;
	```
	Returns the constructed node, which represents the current region of the grid.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

In the worst case, we need to examine all elements of the grid to determine if it can be represented as a leaf or needs further division.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n^2)

The space complexity is driven by the recursion depth and the storage of the Quad-Tree nodes, which in the worst case can be proportional to the size of the grid.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-quad-tree/description/)

---
{{< youtube UQ-1sBMV0v4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
