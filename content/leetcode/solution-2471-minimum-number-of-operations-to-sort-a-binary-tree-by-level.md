
+++
authors = ["grid47"]
title = "Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yi_h_UMHD7s"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yi_h_UMHD7s/maxresdefault.webp"
comments = true
+++



---
You are given the root of a binary tree with unique values. In one operation, you can choose any two nodes at the same level and swap their values. Return the minimum number of operations needed to make the values at each level sorted in strictly increasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree, represented as an array of unique integers, where each node's value is at its respective position in the level-order traversal of the tree.
- **Example:** `root = [1, 5, 4, 7, 6, 8, 9, null, null, null, null, 10]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^5].
	- 1 <= Node.val <= 10^5
	- All the values of the tree are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of swaps needed to make the tree's nodes at each level sorted in strictly increasing order.
- **Example:** `Output: 4`
- **Constraints:**
	- The output should be an integer count.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of swaps required to sort each level of the tree in strictly increasing order.

- Perform a level-order traversal of the binary tree.
- For each level, find the minimum number of swaps required to sort the values at that level.
- Sum up the swaps for each level and return the total.
{{< dots >}}
### Problem Assumptions ✅
- The input will always represent a valid binary tree with unique values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [1, 5, 4, 7, 6, 8, 9, null, null, null, null, 10]`  \
  **Explanation:** At the second level, we need to swap the values 5 and 4 to make it [4, 5]. Similarly, at the third level, we need to swap 7 with 6, and then 8 with 7. This leads to a total of 4 swaps.

{{< dots >}}
## Approach 🚀
The solution involves traversing the tree level by level and sorting the node values at each level using the minimum number of swaps.

### Initial Thoughts 💭
- We need to track the node values at each level of the tree and count the swaps required to sort them.
- A level-order traversal will give us the node values at each level. Sorting these values with the minimum number of swaps is the main challenge.
{{< dots >}}
### Edge Cases 🌐
- The tree will not be empty, as per the problem's constraints.
- For large trees, ensure the solution handles up to 10^5 nodes efficiently.
- If the tree is already sorted at each level, no swaps will be needed.
- The number of nodes can be as large as 10^5, so the algorithm needs to be efficient enough to handle such large inputs.
{{< dots >}}
## Code 💻
```cpp
    
int minimumOperations(TreeNode* root) {
    int cnt = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int sz = q.size();
        vector<int> arr, idx(sz);
        while(sz--) {
            auto it = q.front();
            q.pop();
            arr.push_back(it->val);
            if(it->left != NULL) q.push(it->left);
            if(it->right!= NULL) q.push(it->right);
        }
        // cout << sz << " ";
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
        for(int i = 0; i < idx.size(); i++)
            for(; idx[i] != i; cnt++)
                swap(idx[i], idx[idx[i]]);
    }
    return cnt;
}
```

This function calculates the minimum number of operations required to rearrange the nodes in a binary tree so that the nodes' values are sorted in ascending order by swapping their positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minimumOperations(TreeNode* root) {
	```
	This is the declaration of the function `minimumOperations`, which takes the root of a binary tree as input and returns the minimum number of operations needed to reorder the nodes.

2. **Variable Initialization**
	```cpp
	    int cnt = 0;
	```
	The variable `cnt` is initialized to 0. It will count the number of operations (node swaps) required.

3. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	A queue `q` is created to help with level-order traversal (breadth-first search) of the binary tree.

4. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	The root of the tree is added to the queue to start the level-order traversal.

5. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	The loop continues as long as there are nodes in the queue. This represents level-order traversal.

6. **Size Calculation**
	```cpp
	        int sz = q.size();
	```
	The variable `sz` stores the current size of the queue, which represents the number of nodes at the current level of the tree.

7. **Array Initialization**
	```cpp
	        vector<int> arr, idx(sz);
	```
	Two vectors are initialized: `arr` to store the values of nodes at the current level, and `idx` to store their indices.

8. **Level Traversal**
	```cpp
	        while(sz--) {
	```
	A loop that iterates over all nodes at the current level, decreasing `sz` until no more nodes are left.

9. **Queue Front Node**
	```cpp
	            auto it = q.front();
	```
	The node at the front of the queue is accessed for processing.

10. **Pop Node from Queue**
	```cpp
	            q.pop();
	```
	The node at the front of the queue is removed.

11. **Add Node Value to Array**
	```cpp
	            arr.push_back(it->val);
	```
	The value of the current node is added to the `arr` vector.

12. **Left Child Check**
	```cpp
	            if(it->left != NULL) q.push(it->left);
	```
	If the node has a left child, it is added to the queue for the next level of traversal.

13. **Right Child Check**
	```cpp
	            if(it->right!= NULL) q.push(it->right);
	```
	If the node has a right child, it is added to the queue for the next level of traversal.

14. **Index Initialization**
	```cpp
	        iota(idx.begin(), idx.end(), 0);
	```
	The `iota` function fills the `idx` vector with indices from 0 to `sz-1`, preparing it for sorting based on node values.

15. **Sorting Indices**
	```cpp
	        sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
	```
	The `idx` vector is sorted in ascending order of the values in the `arr` vector, so we can track the correct positions of the nodes.

16. **Rearrangement Loop**
	```cpp
	        for(int i = 0; i < idx.size(); i++)
	```
	A loop that iterates over all indices in the `idx` vector, which represents the sorted order of node values.

17. **Swap Nodes**
	```cpp
	            for(; idx[i] != i; cnt++)
	```
	If the node is not in its correct position, we increment `cnt` and swap the node with the node at the correct index.

18. **Swap Elements in Array**
	```cpp
	                swap(idx[i], idx[idx[i]]);
	```
	This line swaps the elements in the `idx` array to move the node to its correct position, counting each swap.

19. **Return Statement**
	```cpp
	    return cnt;
	```
	The function returns the total number of swaps `cnt` required to sort the nodes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The worst case occurs when sorting the values at each level takes O(log n) time for each level.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we need to store the values at each level of the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/)

---
{{< youtube yi_h_UMHD7s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
