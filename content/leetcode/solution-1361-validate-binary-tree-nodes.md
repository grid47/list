
+++
authors = ["grid47"]
title = "Leetcode 1361: Validate Binary Tree Nodes"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1361: Validate Binary Tree Nodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Union Find","Graph","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Mw67DTgUEqk"
youtube_upload_date="2023-10-17"
youtube_thumbnail="https://i.ytimg.com/vi/Mw67DTgUEqk/maxresdefault.jpg"
comments = true
+++



---
You are given `n` nodes in a binary tree, numbered from `0` to `n-1`. Each node `i` has two children: `leftChild[i]` and `rightChild[i]`. If a node has no left child, its value will be `-1`. Similarly, if a node has no right child, its value will also be `-1`. Your task is to return `true` if and only if these nodes form exactly one valid binary tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the number of nodes `n`, and two arrays `leftChild` and `rightChild` representing the left and right children of each node.
- **Example:** `n = 5, leftChild = [1, -1, 3, -1, 2], rightChild = [4, -1, -1, -1, -1]`
- **Constraints:**
	- n == leftChild.length == rightChild.length
	- 1 <= n <= 10^4
	- -1 <= leftChild[i], rightChild[i] <= n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a boolean value: `true` if the nodes form exactly one valid binary tree, otherwise `false`.
- **Example:** `true`
- **Constraints:**
	- The output will be either `true` or `false`.

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine whether the nodes form exactly one valid binary tree, we will use a union-find structure to ensure that there is exactly one connected component and no cycles.

- Implement a union-find data structure to track connected components and ensure there is only one parent for each node (except the root).
- Traverse through each node and attempt to unify the current node with its left and right children.
- Check for cycles or multiple parents for any node during the traversal.
{{< dots >}}
### Problem Assumptions ✅
- Each node will have at most two children, and no node will have more than one parent (except the root).
{{< dots >}}
## Examples 🧩
- **Input:** `n = 5, leftChild = [1, -1, 3, -1, 2], rightChild = [4, -1, -1, -1, -1]`  \
  **Explanation:** This example forms a valid binary tree. The node structure follows the rules of a binary tree, and there are no cycles or multiple parents for any node.

- **Input:** `n = 4, leftChild = [1, -1, 3, -1], rightChild = [2, 3, -1, -1]`  \
  **Explanation:** This example forms an invalid tree due to the cycle between nodes 2 and 3, which makes it impossible to form a valid binary tree.

{{< dots >}}
## Approach 🚀
To solve this problem, we can use a union-find (disjoint-set) approach to track connected components and validate that no cycles are present while ensuring every node except the root has exactly one parent.

### Initial Thoughts 💭
- A valid binary tree must have a single connected component and no cycles.
- The union-find data structure will help in merging nodes and tracking their parents efficiently.
- The key to the solution is ensuring each node is connected properly and that no node has more than one parent.
{{< dots >}}
### Edge Cases 🌐
- If `n == 1`, the tree is trivially valid as there is only one node.
- Ensure that the solution handles the maximum input size efficiently.
- Handle cases where the left or right child values are -1 for many nodes.
- The union-find operations must be efficient enough to handle the problem's constraints.
{{< dots >}}
## Code 💻
```cpp
bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
    UF uf = UF(n);
    for(int i = 0; i < n; i++) {
        if(lc[i] >= 0) {
            
if(!uf.uni(i, lc[i])) 
return false; 
            
        }
        if(rc[i] >= 0) {
 
if(!uf.uni(i, rc[i])) 
return false; 
            
        }
    }
    cout << uf.net;
    return uf.net == 1;
}
```

This code validates whether the given nodes and their left and right children form a valid binary tree structure using the Union-Find data structure.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool validateBinaryTreeNodes(int n, vector<int>& lc, vector<int>& rc) {
	```
	The function 'validateBinaryTreeNodes' takes the number of nodes 'n', and two vectors 'lc' and 'rc' representing the left and right child indices of each node. It returns 'true' if the structure forms a valid binary tree, and 'false' otherwise.

2. **Initialize Union-Find**
	```cpp
	    UF uf = UF(n);
	```
	Initializes a Union-Find (UF) data structure with 'n' nodes. This will be used to track connected components and ensure that no cycles exist in the binary tree structure.

3. **For Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates over all the nodes from 0 to n-1 to check each node's left and right children for valid connections.

4. **Left Child Check**
	```cpp
	        if(lc[i] >= 0) {
	```
	Checks if the left child of node 'i' exists (i.e., 'lc[i] >= 0'). If it exists, it tries to connect the current node with its left child.

5. **Union Operation**
	```cpp
	if(!uf.uni(i, lc[i])) 
	```
	Attempts to union the current node 'i' and its left child 'lc[i]'. If the union operation fails (i.e., they are already in the same set), the tree is invalid, and the function returns 'false'.

6. **Return False**
	```cpp
	return false; 
	```
	If the union operation for the left child fails, the function immediately returns 'false' indicating that the tree structure is invalid.

7. **Right Child Check**
	```cpp
	        if(rc[i] >= 0) {
	```
	Checks if the right child of node 'i' exists (i.e., 'rc[i] >= 0'). If it exists, it tries to connect the current node with its right child.

8. **Union Operation for Right Child**
	```cpp
	if(!uf.uni(i, rc[i])) 
	```
	Attempts to union the current node 'i' and its right child 'rc[i]'. If the union operation fails, the tree is invalid, and the function returns 'false'.

9. **Return False**
	```cpp
	return false; 
	```
	If the union operation for the right child fails, the function immediately returns 'false' indicating that the tree structure is invalid.

10. **Return Statement**
	```cpp
	    return uf.net == 1;
	```
	Returns 'true' if the number of disjoint sets in the Union-Find structure is exactly 1, meaning the tree is connected and valid. Otherwise, returns 'false'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n log n)

The union-find operations are near constant time, with a worst-case of O(log n) due to path compression and union by rank.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the parent and size information for each node in the union-find structure.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/validate-binary-tree-nodes/description/)

---
{{< youtube Mw67DTgUEqk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
