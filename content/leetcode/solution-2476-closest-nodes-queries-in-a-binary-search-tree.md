
+++
authors = ["grid47"]
title = "Leetcode 2476: Closest Nodes Queries in a Binary Search Tree"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2476: Closest Nodes Queries in a Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "KFYvX7u-Hs8"
youtube_upload_date="2022-11-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/KFYvX7u-Hs8/maxresdefault.webp"
comments = true
+++



---
You are given the root of a binary search tree (BST) and an array of queries. For each query, find the largest value smaller than or equal to the query value and the smallest value greater than or equal to the query value in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary search tree (BST) and an array of queries.
- **Example:** `root = [10, 5, 20, 2, 7, 15, 30], queries = [6, 25, 5]`
- **Constraints:**
	- The number of nodes in the tree is between 2 and 10^5.
	- 1 <= Node.val <= 10^6
	- The length of queries is between 1 and 10^5.
	- 1 <= queries[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D array where each element represents the answers to each query. The first element in the pair should be the largest value smaller than or equal to the query, and the second should be the smallest value greater than or equal to the query.
- **Example:** `Output: [[5, 7], [20, 20], [5, 5]]`
- **Constraints:**
	- The output should be a 2D array of integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** For each query, find the largest value smaller than or equal to the query and the smallest value greater than or equal to the query.

- Traverse the binary search tree (BST) and store the values in a sorted order.
- For each query, find the largest number less than or equal to the query and the smallest number greater than or equal to the query using binary search techniques.
{{< dots >}}
### Problem Assumptions ✅
- The binary search tree (BST) is a valid BST, and the input query array contains positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10,5,20,2,7,15,30], queries = [6, 25, 5]`  \
  **Explanation:** For the query 6, the largest number smaller or equal to 6 is 5, and the smallest number greater or equal to 6 is 7. For the query 25, the largest number smaller or equal to 25 is 20, and the smallest number greater or equal to 25 is 20. For the query 5, the largest number smaller or equal to 5 is 5, and the smallest number greater or equal to 5 is 5.

{{< dots >}}
## Approach 🚀
We need to find the closest nodes in the BST for each query value by traversing the tree and using binary search techniques.

### Initial Thoughts 💭
- The problem can be solved efficiently by storing the tree's values in sorted order and using binary search for each query.
- We can perform an in-order traversal of the tree to get a sorted list of values and then use binary search to find the closest nodes for each query.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least 2 nodes in the tree, so no empty inputs are possible.
- Ensure the solution is efficient for large trees and large query arrays.
- If no valid smaller or larger value exists, return -1.
- The solution must be optimized for time complexity due to the input size constraints.
{{< dots >}}
## Code 💻
```cpp
class Solution {
vector<int> v;
void traverse(TreeNode* root) {
    if(root != nullptr) {
        traverse(root->left);
        if(v.empty() || v.back() < root->val)
            v.push_back(root->val);
        traverse(root->right);
    }
}
public:
vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    traverse(root);
    vector<vector<int>> res;
    for(int q: queries) {
        auto it = lower_bound(begin(v), end(v), q);
        if(it != end(v) && *it==q)
        res.push_back({q, q});
        else
        res.push_back({it == begin(v)? -1: *prev(it), it == end(v)? -1: *it});
    }
    return res;
}
```

This solution defines a `Solution` class that includes a method `closestNodes` which takes in a binary search tree (`TreeNode* root`) and a list of query values. The method returns a list of closest nodes for each query, utilizing an in-order traversal to build a sorted list of node values.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Declaration**
	```cpp
	class Solution {
	```
	This is the declaration of the `Solution` class which contains the method `closestNodes` that solves the problem.

2. **Member Variable Declaration**
	```cpp
	vector<int> v;
	```
	A member variable `v` of type `vector<int>` is declared, which will store the values of the nodes in the tree in sorted order.

3. **Helper Function Declaration**
	```cpp
	void traverse(TreeNode* root) {
	```
	This is a helper function `traverse` that performs an in-order traversal of the binary search tree to collect the node values in sorted order.

4. **Null Check**
	```cpp
	    if(root != nullptr) {
	```
	Checks if the current node is not null before proceeding with further traversal.

5. **Left Subtree Traversal**
	```cpp
	        traverse(root->left);
	```
	Recursively traverses the left subtree of the current node.

6. **Value Insertion Check**
	```cpp
	        if(v.empty() || v.back() < root->val)
	```
	Checks if the `v` vector is empty or if the last element in `v` is smaller than the current node's value, ensuring values are inserted in increasing order.

7. **Push Value to Vector**
	```cpp
	            v.push_back(root->val);
	```
	Inserts the current node's value into the `v` vector if it satisfies the condition.

8. **Right Subtree Traversal**
	```cpp
	        traverse(root->right);
	```
	Recursively traverses the right subtree of the current node.

9. **Public Access Modifier**
	```cpp
	public:
	```
	The `public` access modifier, indicating that the methods following it are accessible from outside the class.

10. **Method Declaration**
	```cpp
	vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
	```
	This is the main method `closestNodes`, which receives a tree root and a list of queries, and returns a list of vectors containing the closest nodes for each query.

11. **Inorder Traversal Call**
	```cpp
	    traverse(root);
	```
	Calls the `traverse` function to populate the vector `v` with the sorted node values from the tree.

12. **Result Vector Initialization**
	```cpp
	    vector<vector<int>> res;
	```
	Initializes a 2D vector `res` to store the results of closest nodes for each query.

13. **Loop Over Queries**
	```cpp
	    for(int q: queries) {
	```
	Iterates over each query value `q` in the `queries` list.

14. **Lower Bound Search**
	```cpp
	        auto it = lower_bound(begin(v), end(v), q);
	```
	Uses the `lower_bound` function to find the first position in the sorted vector `v` where the value is greater than or equal to the query `q`.

15. **Exact Match Check**
	```cpp
	        if(it != end(v) && *it==q)
	```
	Checks if the query `q` exactly matches an element in the sorted vector `v`.

16. **Exact Match Result**
	```cpp
	        res.push_back({q, q});
	```
	If an exact match is found, it pushes a vector containing the query value `q` as both the lower and upper bound into the result vector `res`.

17. **Otherwise Result**
	```cpp
	        else
	```
	Handles the case where the query does not have an exact match in the sorted vector `v`.

18. **Result for No Exact Match**
	```cpp
	        res.push_back({it == begin(v)? -1: *prev(it), it == end(v)? -1: *it});
	```
	If there is no exact match, it pushes a pair of the closest smaller and larger values (or -1 if no such values exist) into the result vector `res`.

19. **Return Result**
	```cpp
	    return res;
	```
	Returns the result vector `res` containing the closest nodes for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n + q log n)
- **Average Case:** O(n + q log n)
- **Worst Case:** O(n + q log n)

The time complexity for this solution is O(n + q log n), where n is the number of nodes and q is the number of queries.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the values of the BST in a sorted array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/description/)

---
{{< youtube KFYvX7u-Hs8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
