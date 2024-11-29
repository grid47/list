
+++
authors = ["grid47"]
title = "Leetcode 2673: Make Costs of Paths Equal in a Binary Tree"
date = "2024-02-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2673: Make Costs of Paths Equal in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "W62wT5Lem6E"
youtube_upload_date="2023-05-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/W62wT5Lem6E/maxresdefault.webp"
comments = true
+++



---
You are given a perfect binary tree with `n` nodes, where each node has a cost associated with it. The tree is numbered from 1 to n, with node 1 as the root. For each node `i`, its left child is `2*i` and its right child is `2*i + 1`. You are allowed to increment the cost of any node by 1 any number of times. Your task is to return the minimum number of increments required to make the total cost of the path from the root to each leaf node equal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `n` representing the number of nodes in a perfect binary tree, followed by a list of integers `cost`, where `cost[i]` is the cost of node `i+1`.
- **Example:** `Input: n = 5, cost = [2, 4, 3, 2, 5]`
- **Constraints:**
	- 3 <= n <= 10^5
	- n + 1 is a power of 2
	- cost.length == n
	- 1 <= cost[i] <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a single integer, which represents the minimum number of increments required to make the cost of all root-to-leaf paths equal.
- **Example:** `Output: 4`
- **Constraints:**
	- The result should be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of increments required to equalize the path costs.

- Step 1: Starting from the leaf nodes, propagate the required increments up to the root node, ensuring each path has the same total cost.
- Step 2: For each non-leaf node, compare the costs of its left and right children. Increment the smaller one to match the larger one and count the number of increments.
- Step 3: Repeat the process until you reach the root node.
{{< dots >}}
### Problem Assumptions ✅
- The tree is a perfect binary tree, meaning every non-leaf node has exactly two children.
- All nodes have a non-negative cost value.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5, cost = [2, 4, 3, 2, 5]`  \
  **Explanation:** In this case, the two paths from root to leaves are [2, 4, 5] and [2, 3, 5]. To equalize the path costs, we increment the cost of node 2 to match node 3's cost. This requires 4 increments, so the total increments required are 4.

{{< dots >}}
## Approach 🚀
To solve this problem, we will work our way from the leaf nodes upwards to the root, balancing the path costs by making necessary increments.

### Initial Thoughts 💭
- We need to ensure that the cost of each root-to-leaf path is the same.
- This requires comparing the costs of left and right children of every node and balancing them.
- Starting from the leaf nodes and adjusting the internal nodes' costs seems to be an efficient way to solve this problem.
{{< dots >}}
### Edge Cases 🌐
- The input will always have at least 3 nodes, ensuring a valid binary tree structure.
- The solution must handle up to 10^5 nodes efficiently.
- If the tree already has equal costs for all root-to-leaf paths, the result should be 0 increments.
- Ensure the solution runs in O(n) time complexity to handle the largest inputs.
{{< dots >}}
## Code 💻
```cpp
int minIncrements(int n, vector<int>& A) {
    int res = 0;
    for (int i = n / 2 - 1; i >= 0; --i) {
        int l = i * 2 + 1, r = i * 2 + 2;
        res += abs(A[l] - A[r]);
        A[i] += max(A[l], A[r]);
    }
    return res;
}
```

The function 'minIncrements' calculates the minimum number of increments required to make the array a valid heap. It iterates over the elements and compares each pair of child nodes in the heap, accumulating the difference and adjusting the parent element accordingly.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minIncrements(int n, vector<int>& A) {
	```
	This is the function definition of 'minIncrements', which takes an integer 'n' (size of the array) and a reference to a vector 'A'. The goal is to compute the minimum number of increments needed to turn the array into a valid heap.

2. **Result Initialization**
	```cpp
	    int res = 0;
	```
	We initialize 'res' to 0. This variable will keep track of the total number of increments made while adjusting the array.

3. **Loop Start**
	```cpp
	    for (int i = n / 2 - 1; i >= 0; --i) {
	```
	We start a loop that iterates over the parent nodes of the binary heap, starting from the last parent node (at index 'n / 2 - 1') and moving upwards.

4. **Child Nodes Calculation**
	```cpp
	        int l = i * 2 + 1, r = i * 2 + 2;
	```
	For each parent node, we calculate the indices of its left ('l') and right ('r') children using the standard binary heap indexing formula.

5. **Difference Calculation**
	```cpp
	        res += abs(A[l] - A[r]);
	```
	We calculate the absolute difference between the values of the left and right children, adding this value to 'res' to account for the required increments to make the children equal.

6. **Adjust Parent Value**
	```cpp
	        A[i] += max(A[l], A[r]);
	```
	To maintain the heap property, we adjust the parent node's value by adding the maximum of its left or right child's value.

7. **Return Result**
	```cpp
	    return res;
	```
	We return the total number of increments made to the array, stored in 'res'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only need to traverse the tree once, adjusting costs from the leaves to the root.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space needed for the cost array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

---
{{< youtube W62wT5Lem6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
