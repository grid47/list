
+++
authors = ["grid47"]
title = "Leetcode 2415: Reverse Odd Levels of Binary Tree"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2415: Reverse Odd Levels of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iR3r4iEIDZo"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iR3r4iEIDZo/maxresdefault.webp"
comments = true
+++



---
Given the root of a perfect binary tree, reverse the values of the nodes at each odd level of the tree. The level of a node is defined as the number of edges along the path from the root to the node. A perfect binary tree is one where all nodes have two children and all leaves are on the same level.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a perfect binary tree represented by its root node.
- **Example:** `root = [4, 2, 6, 1, 3, 5, 7]`
- **Constraints:**
	- 1 <= Node.val <= 10^5
	- The number of nodes in the tree is between 1 and 214.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the root of the modified binary tree after reversing the nodes at each odd level.
- **Example:** `Output: [4, 6, 2, 1, 3, 5, 7]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to reverse the node values at each odd level while maintaining the structure of the tree.

- 1. Perform a level order traversal (breadth-first search) of the binary tree.
- 2. For each level, check if it is odd or even.
- 3. If the level is odd, collect the node values at that level and reverse the order of these values.
- 4. Update the node values at the odd levels with the reversed values.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is always a perfect binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [4, 2, 6, 1, 3, 5, 7]`  \
  **Explanation:** At level 1, the nodes are 2 and 6, which are reversed to become 6 and 2. The final output is [4, 6, 2, 1, 3, 5, 7].

{{< dots >}}
## Approach 🚀
The approach involves performing a level order traversal of the tree. At each odd level, we reverse the node values and update the tree accordingly.

### Initial Thoughts 💭
- We can perform a level-order traversal using a queue.
- At each odd level, we reverse the node values and update the tree structure.
- Since the binary tree is perfect, we can be sure that all levels are fully populated.
{{< dots >}}
### Edge Cases 🌐
- The input tree will always have at least one node, as per the problem constraints.
- The tree can have up to 214 nodes, which should be handled efficiently in terms of time and space.
- If the tree has only one level, no changes will be made as there are no odd levels.
- Ensure the algorithm works efficiently for a tree with up to 214 nodes.
{{< dots >}}
## Code 💻
```cpp
TreeNode* reverseOddLevels(TreeNode* root) {
    if(!root) return root;
    queue<TreeNode*> q;
    q.push(root);
    vector<int> vals;
    int level = 0;

    while(!q.empty()) {
        int sz = q.size();
        vector<int> temp;
        for(int i = 0; i < sz; i++)  {
            TreeNode* node = q.front(); q.pop();
            if(level %2) node->val= vals[sz- i - 1];
            if(node->left) {
                q.push(node->left);
                temp.push_back(node->left->val);
            }

            if(node->right) {
                q.push(node->right);
                temp.push_back(node->right->val);
            }
        }
        vals = temp;
        level++;
    }
    return root;
}
```

This function reverses the values at odd levels of a binary tree, using level-order traversal (BFS).

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	TreeNode* reverseOddLevels(TreeNode* root) {
	```
	Function declaration for 'reverseOddLevels'. It takes the root of a binary tree as input.

2. **Base Case**
	```cpp
	    if(!root) return root;
	```
	Checks if the root is null, and if so, returns null immediately (base case for recursion).

3. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Initialize a queue to facilitate level-order traversal (BFS).

4. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Push the root of the tree into the queue to begin the traversal.

5. **Initialize vals**
	```cpp
	    vector<int> vals;
	```
	Create a vector to store the node values at each level of the tree.

6. **Level Initialization**
	```cpp
	    int level = 0;
	```
	Initialize a variable 'level' to track the current level during traversal.

7. **While Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Begin the loop to process nodes in the queue until it is empty.

8. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Determine the number of nodes at the current level by checking the size of the queue.

9. **Temporary Storage**
	```cpp
	        vector<int> temp;
	```
	Create a temporary vector to store the values of the nodes at the current level.

10. **For Loop Start**
	```cpp
	        for(int i = 0; i < sz; i++)  {
	```
	Start a loop to process each node at the current level.

11. **Dequeue Node**
	```cpp
	            TreeNode* node = q.front(); q.pop();
	```
	Dequeue the front node and store it in 'node' for processing.

12. **Odd Level Check**
	```cpp
	            if(level %2) node->val= vals[sz- i - 1];
	```
	If the current level is odd, reverse the values of the nodes at that level.

13. **Left Child Check**
	```cpp
	            if(node->left) {
	```
	Check if the current node has a left child.

14. **Push Left Child**
	```cpp
	                q.push(node->left);
	```
	Push the left child of the node into the queue for future processing.

15. **Store Left Child Value**
	```cpp
	                temp.push_back(node->left->val);
	```
	Store the value of the left child in the temporary vector.

16. **Right Child Check**
	```cpp
	            if(node->right) {
	```
	Check if the current node has a right child.

17. **Push Right Child**
	```cpp
	                q.push(node->right);
	```
	Push the right child of the node into the queue.

18. **Store Right Child Value**
	```cpp
	                temp.push_back(node->right->val);
	```
	Store the value of the right child in the temporary vector.

19. **Update vals**
	```cpp
	        vals = temp;
	```
	Update the 'vals' vector to hold the values of the current level for the next iteration.

20. **Level Increment**
	```cpp
	        level++;
	```
	Increment the level counter to track the next level.

21. **Return Root**
	```cpp
	    return root;
	```
	Return the modified tree with odd levels reversed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we visit each node once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for the queue used in the level-order traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/)

---
{{< youtube iR3r4iEIDZo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
