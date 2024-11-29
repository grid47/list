
+++
authors = ["grid47"]
title = "Leetcode 2641: Cousins in Binary Tree II"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2641: Cousins in Binary Tree II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xvwTd19SncE"
youtube_upload_date="2024-10-23"
youtube_thumbnail="https://i.ytimg.com/vi/xvwTd19SncE/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values. Two nodes are cousins if they have the same depth but different parents. The depth of a node is the number of edges from the root to the node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by the root node, which is an instance of a TreeNode. Each TreeNode has a value, a left child, and a right child.
- **Example:** `root = [3, 4, 6, 2, 5, null, 7]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^5].
	- 1 <= Node.val <= 10^4.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the modified binary tree where each node's value is replaced by the sum of its cousins' values.
- **Example:** `Output: [0, 0, 0, 7, 7, null, 11]`
- **Constraints:**
	- The output tree will maintain the structure of the original tree, with modified values.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to replace the value of each node with the sum of its cousins' values, ensuring that the tree's structure is maintained.

- Step 1: Traverse the tree level by level using a queue to process each node.
- Step 2: For each level, calculate the sum of the values of the cousins by excluding the node's own value.
- Step 3: Replace the node's value with the sum of its cousins.
- Step 4: Move to the next level and repeat the process.
{{< dots >}}
### Problem Assumptions ✅
- The input binary tree is non-empty and consists of positive integer values.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3, 4, 6, 2, 5, null, 7]`  \
  **Explanation:** For the root [3], there are no cousins, so its sum is 0. The node with value 4 has cousins 6 and 7, so its new value will be 13. Similarly, other nodes' values are replaced based on the sum of their cousins.

{{< dots >}}
## Approach 🚀
We will traverse the tree level by level, using a queue to handle each level. For each level, we compute the sum of the cousins' values by excluding the node's value, and then update the tree accordingly.

### Initial Thoughts 💭
- We need to process the tree level by level to correctly identify cousins, as nodes on the same level with different parents are cousins.
- Using a queue for level-order traversal is an efficient way to handle this problem, allowing us to compute the cousin sums as we process each level.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty, return an empty tree.
- For large trees with up to 100,000 nodes, the solution must be efficient and handle the maximum input size within time limits.
- If all nodes at a particular level have the same value, the sum of the cousins will be the same for each node at that level.
- Ensure the algorithm runs in linear time relative to the number of nodes, i.e., O(n), where n is the number of nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
TreeNode* replaceValueInTree(TreeNode* root) {
    
    list<TreeNode*> q;
    
    q.push_back(root);
    root->val = 0;
    map<TreeNode*, int> mp;
    while(!q.empty()) {
        int sz = q.size();
        long long sum = 0;
        while(sz--) {
            auto it = q.front();
            q.pop_front();
            if(it->left != NULL) {
                mp[it] += it->left->val;
                q.push_back(it->left);
            }
            if(it->right != NULL) {
                mp[it] += it->right->val;
                q.push_back(it->right);
            }
            sum += mp[it];
        }
        for(auto it: mp) {
            if(it.first->left != NULL) {
                it.first->left->val = sum - it.second;
            }
            if(it.first->right != NULL) {
                it.first->right->val = sum - it.second;
            }    
        }
        mp.clear();
    }
    return root;
}
```

This code defines a function `replaceValueInTree` that traverses a binary tree using breadth-first search (BFS) and replaces each node's value with the sum of the values of all nodes in its subtree, excluding the current node's value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Initialization**
	```cpp
	TreeNode* replaceValueInTree(TreeNode* root) {
	```
	Define the function `replaceValueInTree` that takes a root node of a tree and returns the root after modifying node values.

2. **Queue Setup**
	```cpp
	    list<TreeNode*> q;
	```
	Initialize a queue `q` to facilitate breadth-first traversal of the tree.

3. **Queue Initialization**
	```cpp
	    q.push_back(root);
	```
	Add the root node to the queue for BFS traversal.

4. **Initial Assignment**
	```cpp
	    root->val = 0;
	```
	Set the root node's value to 0 as part of initialization.

5. **Map Setup**
	```cpp
	    map<TreeNode*, int> mp;
	```
	Initialize a map `mp` to store the accumulated sums for each node.

6. **Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Start a loop that continues until the queue is empty, indicating all nodes are processed.

7. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue, representing the number of nodes at the current level.

8. **Sum Initialization**
	```cpp
	        long long sum = 0;
	```
	Initialize a variable `sum` to keep track of the sum of node values at the current level.

9. **Level Processing**
	```cpp
	        while(sz--) {
	```
	Process each node in the current level of the tree.

10. **Node Access**
	```cpp
	            auto it = q.front();
	```
	Get the front node of the queue to process it.

11. **Node Removal**
	```cpp
	            q.pop_front();
	```
	Remove the front node from the queue after accessing it.

12. **Left Child Check**
	```cpp
	            if(it->left != NULL) {
	```
	Check if the current node has a left child.

13. **Left Child Sum**
	```cpp
	                mp[it] += it->left->val;
	```
	Add the value of the left child to the map.

14. **Left Child Enqueue**
	```cpp
	                q.push_back(it->left);
	```
	Add the left child to the queue for processing in the next iteration.

15. **Right Child Check**
	```cpp
	            if(it->right != NULL) {
	```
	Check if the current node has a right child.

16. **Right Child Sum**
	```cpp
	                mp[it] += it->right->val;
	```
	Add the value of the right child to the map.

17. **Right Child Enqueue**
	```cpp
	                q.push_back(it->right);
	```
	Add the right child to the queue for processing in the next iteration.

18. **Sum Update**
	```cpp
	            sum += mp[it];
	```
	Add the value of the current node to the total sum.

19. **Update Nodes**
	```cpp
	        for(auto it: mp) {
	```
	Iterate through the map to update each node's value based on the sum.

20. **Left Node Update**
	```cpp
	            if(it.first->left != NULL) {
	```
	Check if the current node has a left child to update its value.

21. **Left Node Value Update**
	```cpp
	                it.first->left->val = sum - it.second;
	```
	Update the left child node's value based on the calculated sum.

22. **Right Node Update**
	```cpp
	            if(it.first->right != NULL) {
	```
	Check if the current node has a right child to update its value.

23. **Right Node Value Update**
	```cpp
	                it.first->right->val = sum - it.second;
	```
	Update the right child node's value based on the calculated sum.

24. **Map Reset**
	```cpp
	        mp.clear();
	```
	Clear the map to prepare for the next level.

25. **Return**
	```cpp
	    return root;
	```
	Return the modified root node after the entire tree has been processed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we visit each node exactly once during the level-order traversal.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the queue used for the level-order traversal, which can hold up to n nodes in the worst case.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

---
{{< youtube xvwTd19SncE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
