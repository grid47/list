
+++
authors = ["grid47"]
title = "Leetcode 107: Binary Tree Level Order Traversal II"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 107: Binary Tree Level Order Traversal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp"
youtube = "6e4pmYyr_1o"
youtube_upload_date="2021-01-20"
youtube_thumbnail="https://i.ytimg.com/vi/6e4pmYyr_1o/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/107.webp" 
    alt="A tree with soft concentric circles, each level glowing and expanding outward from the center."
    caption="Solution to LeetCode 107: Binary Tree Level Order Traversal II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. This means that for each level, starting from the leaf level and moving towards the root, you should collect the node values from left to right.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by its root node.
- **Example:** `root = [5,3,8,1,4,7,9]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 2000].
	- -1000 <= Node.val <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of lists representing the node values at each level from bottom to top.
- **Example:** `[[1, 4], [3, 8], [5]]`
- **Constraints:**
	- The output should represent the nodes' values level by level from leaf to root.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to perform a bottom-up level order traversal of the binary tree, ensuring each level is collected in the correct order, from leaf to root.

- Use a queue to perform a breadth-first traversal of the tree.
- For each level, collect the values into a list and store it.
- Since we need the levels from bottom to top, push each level's result onto a stack.
- Finally, pop the elements from the stack to return the bottom-up level order.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree is non-empty, or it is an empty tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [3,9,20,null,null,15,7]`  \
  **Explanation:** In this case, the binary tree can be visualized as:

        3
       /  \
      9   20
          /  \
         15   7

The bottom-up level order traversal is: [[15,7], [9,20], [3]].

- **Input:** `Input: root = [1]`  \
  **Explanation:** In this case, the binary tree consists of a single node 1. The bottom-up level order traversal is simply: [[1]].

- **Input:** `Input: root = []`  \
  **Explanation:** If the tree is empty, the bottom-up level order traversal should return an empty list: [].

{{< dots >}}
## Approach 🚀
The approach for solving this problem involves using a breadth-first search (BFS) to explore the tree level by level. Since we need the result in bottom-up order, we can utilize a stack to reverse the order after performing the traversal.

### Initial Thoughts 💭
- A level order traversal typically uses a queue, but we need the result in reverse order (bottom-up).
- We can store the level order results in a stack and then pop the stack to get the desired bottom-up order.
{{< dots >}}
### Edge Cases 🌐
- If the root is null (empty tree), return an empty list.
- The algorithm should be efficient enough to handle trees with up to 2000 nodes.
- Handle trees where all nodes are on one side (skewed trees).
- Ensure the solution works for both balanced and unbalanced trees.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> levelOrderBottom(TreeNode* root) {

    vector<vector<int>> ans;        
    queue<TreeNode*> q;
    if(root == NULL) return ans;
    
    q.push(root);        
    stack<vector<int>> stk;
            
    while(!q.empty())
    {
        vector<int> ans;
        int sz = q.size();

        while(sz--) {
            TreeNode* tmp = q.front();
            q.pop();
            ans.push_back(tmp->val);

            if(tmp->left)   q.push(tmp->left);
            if(tmp->right)  q.push(tmp->right);                
        }
        stk.push(ans);
    }

    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;      
}
```

This function performs a level-order traversal of a binary tree from the bottom level to the top.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
	```
	Define the function 'levelOrderBottom' to return the bottom-up level order traversal of the tree.

2. **Variable Declaration**
	```cpp
	    vector<vector<int>> ans;        
	```
	Declare a vector to store the final level-order traversal results.

3. **Variable Declaration**
	```cpp
	    queue<TreeNode*> q;
	```
	Declare a queue to process tree nodes level by level.

4. **Base Case Check**
	```cpp
	    if(root == NULL) return ans;
	```
	Check if the tree is empty. If yes, return an empty result.

5. **Queue Operation**
	```cpp
	    q.push(root);        
	```
	Push the root node into the queue to begin the level-order traversal.

6. **Variable Declaration**
	```cpp
	    stack<vector<int>> stk;
	```
	Declare a stack to store the levels temporarily in reverse order.

7. **Loop Definition**
	```cpp
	    while(!q.empty())
	```
	Start a loop to process each level of the tree until the queue is empty.

8. **Level Storage**
	```cpp
	        vector<int> ans;
	```
	Declare a vector to store values of the current level.

9. **Queue Size**
	```cpp
	        int sz = q.size();
	```
	Get the size of the current level by checking the number of nodes in the queue.

10. **Loop Definition**
	```cpp
	        while(sz--) {
	```
	Loop through all nodes of the current level.

11. **Queue Operation**
	```cpp
	            TreeNode* tmp = q.front();
	```
	Fetch the front node from the queue.

12. **Queue Operation**
	```cpp
	            q.pop();
	```
	Remove the front node from the queue after processing.

13. **Node Value Collection**
	```cpp
	            ans.push_back(tmp->val);
	```
	Add the value of the current node to the level vector.

14. **Conditional Function Call**
	```cpp
	            if(tmp->left)   q.push(tmp->left);
	```
	If the current node has a left child, add it to the queue for processing.

15. **Conditional Function Call**
	```cpp
	            if(tmp->right)  q.push(tmp->right);
	```
	If the current node has a right child, add it to the queue for processing.

16. **Stack Operation**
	```cpp
	        stk.push(ans);
	```
	Push the current level vector onto the stack.

17. **Loop Definition**
	```cpp
	    while(!stk.empty())
	```
	Start a loop to retrieve levels from the stack in reverse order.

18. **Stack Operation**
	```cpp
	        ans.push_back(stk.top());
	```
	Add the top level vector from the stack to the result vector.

19. **Stack Operation**
	```cpp
	        stk.pop();
	```
	Remove the top level from the stack after adding it to the result.

20. **Return Value**
	```cpp
	    return ans;      
	```
	Return the final bottom-up level order traversal vector.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes in the tree, since each node is processed exactly once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space used by the queue and the stack to store the nodes and their values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/)

---
{{< youtube 6e4pmYyr_1o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
