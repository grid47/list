
+++
authors = ["grid47"]
title = "Leetcode 1161: Maximum Level Sum of a Binary Tree"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1161: Maximum Level Sum of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "v3e5uYmzyxs"
youtube_upload_date="2022-11-22"
youtube_thumbnail="https://i.ytimg.com/vi/v3e5uYmzyxs/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary tree, find the smallest level x (1-indexed) such that the sum of the values of nodes at level x is maximal. Each level of the tree corresponds to the distance from the root, with the root being level 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The binary tree is represented as an array using level-order traversal. Each element corresponds to a node's value, and null indicates missing children.
- **Example:** `Input: root = [5, 3, 8, -1, 4, null, 2]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^4].
	- -10^5 <= Node.val <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest level x (1-indexed) with the maximal sum of node values.
- **Example:** `Output: 2`
- **Constraints:**
	- If there are multiple levels with the same maximal sum, return the smallest level x.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the level in a binary tree with the maximum sum of node values.

- Perform a level-order traversal of the binary tree using a queue.
- For each level, calculate the sum of node values.
- Keep track of the level with the highest sum.
- Return the smallest level x with the maximum sum.
{{< dots >}}
### Problem Assumptions ✅
- The input binary tree is valid.
- Levels are 1-indexed, starting from the root.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [5, 3, 8, -1, 4, null, 2]`  \
  **Explanation:** Level 1 sum = 5, Level 2 sum = 3 + 8 = 11, Level 3 sum = -1 + 4 + 2 = 5. The level with the maximum sum is 2, so the output is 2.

- **Input:** `Input: root = [10, 2, 10, 20, -5, null, 15]`  \
  **Explanation:** Level 1 sum = 10, Level 2 sum = 2 + 10 = 12, Level 3 sum = 20 + -5 + 15 = 30. The level with the maximum sum is 3, so the output is 3.

{{< dots >}}
## Approach 🚀
Perform a level-order traversal using a queue and calculate the sum of node values at each level. Track the maximum sum and corresponding level.

### Initial Thoughts 💭
- Level-order traversal naturally groups nodes by levels.
- We can calculate sums during the traversal without additional structure.
- Use a queue to manage nodes and calculate sums level by level.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the input always contains at least one node.
- A tree with 10,000 nodes and varying values.
- Node values are all negative.
- The tree is skewed (all nodes are either left or right children).
- Tree height could be significant, affecting traversal time.
{{< dots >}}
## Code 💻
```cpp
int maxLevelSum(TreeNode* root) {
    int ans = 1, mx= root->val;
    queue<TreeNode*> q;
    q.push(root);
    int lvl = 1;
    while(!q.empty()) {
        int sz = q.size();
        int sum = 0;
        while(sz--) {
            TreeNode* n = q.front();
            q.pop();
            sum += n->val;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);

        }
        if(sum > mx) {
            ans = lvl;
            mx = sum;
        }
        lvl++;
    }
    return ans;
}
```

This function `maxLevelSum` computes the level in a binary tree where the sum of node values is maximized. The tree is traversed level by level using a queue, and the sum of values is computed for each level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	int maxLevelSum(TreeNode* root) {
	```
	Define the function `maxLevelSum` that takes the root of a binary tree and returns the level with the maximum sum of node values.

2. **Variable Initialization**
	```cpp
	    int ans = 1, mx= root->val;
	```
	Initialize `ans` to 1 to represent the level with the maximum sum, and `mx` to the value of the root node as the initial maximum sum.

3. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Declare a queue to perform level order traversal of the binary tree.

4. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Push the root node into the queue to start the level order traversal.

5. **Level Initialization**
	```cpp
	    int lvl = 1;
	```
	Initialize the level counter `lvl` to 1, as the root is at level 1.

6. **Queue Processing Loop**
	```cpp
	    while(!q.empty()) {
	```
	While the queue is not empty, continue processing each level of the tree.

7. **Level Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Get the number of nodes at the current level by measuring the size of the queue.

8. **Sum Initialization**
	```cpp
	        int sum = 0;
	```
	Initialize `sum` to 0 for calculating the sum of node values at the current level.

9. **Process Nodes at Current Level**
	```cpp
	        while(sz--) {
	```
	Loop through all nodes at the current level, decrementing the level size counter `sz`.

10. **Process Each Node**
	```cpp
	            TreeNode* n = q.front();
	```
	Get the front node from the queue (i.e., the first node in the current level).

11. **Remove Node from Queue**
	```cpp
	            q.pop();
	```
	Remove the front node from the queue as it has been processed.

12. **Accumulate Node Value**
	```cpp
	            sum += n->val;
	```
	Add the value of the current node to the `sum` for the current level.

13. **Push Left Child**
	```cpp
	            if(n->left) q.push(n->left);
	```
	If the current node has a left child, push it to the queue for processing in the next level.

14. **Push Right Child**
	```cpp
	            if(n->right) q.push(n->right);
	```
	If the current node has a right child, push it to the queue for processing in the next level.

15. **Update Maximum Level**
	```cpp
	        if(sum > mx) {
	```
	If the sum of values at the current level is greater than the previous maximum sum (`mx`), update `mx` and set the current level as the answer.

16. **Set Answer to Current Level**
	```cpp
	            ans = lvl;
	```
	Set `ans` to the current level (`lvl`) since this level has the maximum sum.

17. **Update Maximum Sum**
	```cpp
	            mx = sum;
	```
	Update `mx` to the new maximum sum for the current level.

18. **Increment Level Counter**
	```cpp
	        lvl++;
	```
	Increment the level counter to move to the next level of the tree.

19. **Return Result**
	```cpp
	    return ans;
	```
	Return the level with the maximum sum of node values.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each node is visited once, and sum calculation is O(1) per node.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(w)

The queue stores nodes level by level, with maximum width w.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/)

---
{{< youtube v3e5uYmzyxs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
