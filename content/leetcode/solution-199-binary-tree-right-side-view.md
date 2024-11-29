
+++
authors = ["grid47"]
title = "Leetcode 199: Binary Tree Right Side View"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 199: Binary Tree Right Side View in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/199.webp"
youtube = "d4zLyf32e3I"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/d4zLyf32e3I/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/199.webp" 
    alt="A glowing tree viewed from the right side, with the rightmost nodes gently illuminating."
    caption="Solution to LeetCode 199: Binary Tree Right Side View Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. Imagine yourself standing on the right side of the tree, and return the values of the nodes you can see when viewed from the right, ordered from top to bottom. 
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary tree represented by the root node. The tree is defined as a TreeNode with properties: val, left, and right.
- **Example:** `root = [3,1,4,null,2]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 100].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers representing the values of the nodes visible from the right side of the tree, ordered from top to bottom.
- **Example:** `[3,4,2]`
- **Constraints:**
	- The output should be an array of integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the nodes that are visible from the right side of the binary tree.

- Use level-order traversal (breadth-first search) of the tree.
- At each level, record the last node encountered in that level, as it is the one visible from the right.
- Return the recorded nodes in the order they are encountered from top to bottom.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is well-formed and follows the structure of a TreeNode.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3,1,4,null,2]`  \
  **Explanation:** In this example, when viewed from the right side, the visible nodes are 3 (root), 4 (right child of root), and 2 (right child of node 1). The output is [3, 4, 2].

- **Input:** `root = [1, null, 2, null, 3]`  \
  **Explanation:** Here, the right-side view is simply the nodes 1, 2, and 3, which are all in a straight line from top to bottom. The output is [1, 2, 3].

- **Input:** `root = []`  \
  **Explanation:** If the tree is empty, the right-side view is also empty, so the output is [].

{{< dots >}}
## Approach 🚀
The approach is to use level-order traversal (BFS) to process nodes level by level and keep track of the last node at each level. These are the nodes visible from the right side.

### Initial Thoughts 💭
- Each level of the tree is processed, and the last node in each level will be visible from the right side.
- Level-order traversal is efficient for this problem because it processes nodes level by level, allowing us to easily pick the last node from each level.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return an empty list.
- If the tree has a large number of nodes, the solution should still work efficiently, processing each node exactly once.
- Handle trees where all nodes are on one side, such as a left-leaning or right-leaning tree.
- Ensure that the time complexity remains linear with respect to the number of nodes.
{{< dots >}}
## Code 💻
```cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(!root) return ans;
    list<TreeNode*> q;
    q.push_back(root);
    while(!q.empty()) {
        vector<int> res;
        int sz = q.size();
        while(sz--) {
            auto tmp = q.front();
            q.pop_front();
            res.push_back(tmp->val);
            if(tmp->left) q.push_back(tmp->left);
            if(tmp->right) q.push_back(tmp->right);
        }
        ans.push_back(res.back());
    }
    return ans;
}
```

This function performs a level-order traversal of a binary tree and returns a vector containing the rightmost node value at each level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> rightSideView(TreeNode* root) {
	```
	Define the function 'rightSideView' which takes a pointer to the root node of a binary tree and returns a vector of integers representing the rightmost value at each level.

2. **Variable Initialization**
	```cpp
	    vector<int> ans;
	```
	Initialize an empty vector 'ans' to store the rightmost values from each level of the binary tree.

3. **Base Case Check**
	```cpp
	    if(!root) return ans;
	```
	Check if the tree is empty (root is null). If it is, return the empty vector 'ans'.

4. **Queue Initialization**
	```cpp
	    list<TreeNode*> q;
	```
	Initialize a queue 'q' (implemented as a list) to help with the level-order traversal of the binary tree.

5. **Push Root to Queue**
	```cpp
	    q.push_back(root);
	```
	Add the root node to the queue to start the traversal.

6. **While Loop - Level Traversal**
	```cpp
	    while(!q.empty()) {
	```
	Start a while loop that runs as long as the queue is not empty, indicating there are still nodes to process.

7. **Result Vector Initialization**
	```cpp
	        vector<int> res;
	```
	Initialize an empty vector 'res' to store the values of the current level of nodes.

8. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Store the current size of the queue in 'sz', which represents the number of nodes at the current level.

9. **Inner While Loop - Process Nodes at Current Level**
	```cpp
	        while(sz--) {
	```
	Process each node at the current level by iterating over the queue based on the number of nodes (sz).

10. **Queue Front Node**
	```cpp
	            auto tmp = q.front();
	```
	Get the node at the front of the queue to process it.

11. **Pop Node from Queue**
	```cpp
	            q.pop_front();
	```
	Remove the node from the front of the queue after processing it.

12. **Push Node Value to Result**
	```cpp
	            res.push_back(tmp->val);
	```
	Add the value of the current node (tmp) to the 'res' vector.

13. **Left Child Check**
	```cpp
	            if(tmp->left) q.push_back(tmp->left);
	```
	If the current node has a left child, add it to the queue for the next level of traversal.

14. **Right Child Check**
	```cpp
	            if(tmp->right) q.push_back(tmp->right);
	```
	If the current node has a right child, add it to the queue for the next level of traversal.

15. **Push Rightmost Value to Answer**
	```cpp
	        ans.push_back(res.back());
	```
	After processing all nodes at the current level, add the rightmost node value (the last value in 'res') to the 'ans' vector.

16. **Return Result**
	```cpp
	    return ans;
	```
	Return the vector 'ans' containing the rightmost value at each level of the binary tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We visit each node once during the BFS traversal, making the time complexity O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used by the queue during the BFS traversal, where n is the number of nodes in the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-right-side-view/description/)

---
{{< youtube d4zLyf32e3I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
