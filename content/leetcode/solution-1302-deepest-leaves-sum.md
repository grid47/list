
+++
authors = ["grid47"]
title = "Leetcode 1302: Deepest Leaves Sum"
date = "2024-06-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1302: Deepest Leaves Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ebJiQrgumP4"
youtube_upload_date="2023-06-03"
youtube_thumbnail="https://i.ytimg.com/vi/ebJiQrgumP4/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary tree, return the sum of values of its deepest leaves. The deepest leaves are the nodes found at the lowest level of the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree where each node is represented by a value.
- **Example:** `Input: root = [10, 5, 15, 3, 7, null, 20, null, null, 18]`
- **Constraints:**
	- The number of nodes in the tree is in the range [1, 10^4].
	- 1 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the sum of the values of the deepest leaves in the binary tree.
- **Example:** `Output: 38`
- **Constraints:**
	- The sum of the values of the deepest leaves.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the sum of the values of the deepest leaves of the binary tree.

- Perform a level-order traversal (breadth-first search) of the binary tree to find the deepest level.
- At each level, accumulate the values of all nodes. The sum of the last level's nodes will be the sum of the deepest leaves.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is valid and non-empty.
- The number of nodes in the tree will always be within the specified range.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10, 5, 15, 3, 7, null, 20, null, null, 18]`  \
  **Explanation:** The deepest leaves are 18 and 20. Their sum is 38.

- **Input:** `Input: root = [12, 8, 20, 4, 10, 16, 25]`  \
  **Explanation:** The deepest leaves are 16 and 25. Their sum is 41.

{{< dots >}}
## Approach 🚀
The optimal approach involves performing a level-order traversal of the tree to access all levels. By iterating through each level, we can find the deepest level's nodes and sum their values.

### Initial Thoughts 💭
- The deepest leaves are located at the last level of the tree. We need to find the last level efficiently.
- A breadth-first search is ideal for this problem, as it explores all nodes level by level.
{{< dots >}}
### Edge Cases 🌐
- The input tree will not be empty, as the problem guarantees that there is at least one node.
- For very large trees (up to 10^4 nodes), the solution must be optimized to avoid timeouts.
- If all nodes are at the same level, the sum will be the sum of all nodes in the tree.
- The solution must run in O(n) time where n is the number of nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
int deepestLeavesSum(TreeNode* root) {
    if(root == NULL) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int sum = 0;
    while(!q.empty()) {
        int sz = q.size();
        sum = 0;
        while(sz--) {
            sum += q.front()->val;
            TreeNode* x = q.front();
            q.pop();
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
    }
    return sum;
}
```

This function calculates the sum of the values of the deepest leaves of a binary tree using a level-order traversal. It uses a queue to explore each level of the tree and keeps updating the sum until it reaches the deepest level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int deepestLeavesSum(TreeNode* root) {
	```
	This line defines the function 'deepestLeavesSum' that takes the root of a binary tree ('root') as input and returns the sum of the values of the deepest leaves.

2. **Base Case Check**
	```cpp
	    if(root == NULL) return 0;
	```
	Checks if the root is NULL (empty tree). If the tree is empty, it immediately returns 0 as there are no leaves to sum.

3. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Declares a queue to facilitate a level-order traversal (breadth-first search) of the tree.

4. **Enqueue Root**
	```cpp
	    q.push(root);
	```
	Pushes the root node into the queue to start the level-order traversal.

5. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes the 'sum' variable to 0. This will accumulate the sum of values of nodes at the deepest level.

6. **While Loop - Tree Traversal**
	```cpp
	    while(!q.empty()) {
	```
	Begins a while loop that continues as long as there are nodes in the queue to process.

7. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Gets the size of the queue, which represents the number of nodes at the current level of the tree.

8. **Sum Reset**
	```cpp
	        sum = 0;
	```
	Resets the 'sum' to 0 for each level of the tree, ensuring only the sum of the current level's nodes is calculated.

9. **Inner While Loop - Node Processing**
	```cpp
	        while(sz--) {
	```
	Processes each node at the current level by iterating over the queue until all nodes at this level have been visited.

10. **Summing Node Values**
	```cpp
	            sum += q.front()->val;
	```
	Adds the value of the node at the front of the queue to the 'sum' variable.

11. **Pop Front Node**
	```cpp
	            TreeNode* x = q.front();
	```
	Stores the front node of the queue in variable 'x' to process it.

12. **Remove Processed Node**
	```cpp
	            q.pop();
	```
	Removes the front node from the queue after processing it.

13. **Enqueue Left Child**
	```cpp
	            if(x->left) q.push(x->left);
	```
	Checks if the current node has a left child. If so, it adds the left child to the queue.

14. **Enqueue Right Child**
	```cpp
	            if(x->right) q.push(x->right);
	```
	Checks if the current node has a right child. If so, it adds the right child to the queue.

15. **Return Deepest Sum**
	```cpp
	    return sum;
	```
	Returns the sum of the node values at the deepest level of the tree, which was accumulated in the 'sum' variable.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n) - In the best case, the traversal will visit all nodes once.
- **Average Case:** O(n) - On average, we will still visit all nodes once during the level-order traversal.
- **Worst Case:** O(n) - In the worst case, we visit every node in the tree.

The time complexity is O(n), where n is the number of nodes in the binary tree.

### Space Complexity 💾
- **Best Case:** O(n) - In the best case, the queue will hold all the nodes at the deepest level.
- **Worst Case:** O(n) - Space complexity is O(n) due to the storage requirements for the queue during the level-order traversal.

The space complexity is O(n), where n is the number of nodes in the tree.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/deepest-leaves-sum/description/)

---
{{< youtube ebJiQrgumP4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
