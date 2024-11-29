
+++
authors = ["grid47"]
title = "Leetcode 103: Binary Tree Zigzag Level Order Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 103: Binary Tree Zigzag Level Order Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/103.webp"
youtube = "igbboQbiwqw"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/igbboQbiwqw/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/103.webp" 
    alt="A glowing zigzag path moving through tree levels, creating a calming, fluid motion."
    caption="Solution to LeetCode 103: Binary Tree Zigzag Level Order Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, your task is to return the zigzag level order traversal of its nodes' values. This means you need to traverse the tree level by level, alternating between left to right and right to left on each level.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given the root of a binary tree, where each node has a value and pointers to its left and right children.
- **Example:** `root = [4,2,6,1,3,5,7]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 2000].
	- -100 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a 2D array where each element represents a level in the binary tree. For each level, alternate between traversing left to right and right to left.
- **Example:** `Output: [[4], [6, 2], [1, 3, 5, 7]]`
- **Constraints:**
	- The output should be an array of arrays where each inner array contains the values of the nodes at that level, following the zigzag order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to perform a zigzag level order traversal using a breadth-first search (BFS) approach. At every odd level, the node values should be traversed from right to left.

- Start by performing a regular level order traversal using a queue.
- After collecting the nodes at each level, reverse the values at odd levels to achieve the zigzag pattern.
- Push the left and right children of each node into the queue to process the next level.
{{< dots >}}
### Problem Assumptions ✅
- The input is always a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3,9,20,null,null,15,7]`  \
  **Explanation:** The binary tree has the following structure:

       3
      / \
     9  20
        /  \
       15   7

The zigzag level order traversal is: [[3], [20, 9], [15, 7]]

- **Input:** `root = [1]`  \
  **Explanation:** The binary tree consists of just one node, which is the root node. The zigzag level order traversal is: [[1]]

- **Input:** `root = []`  \
  **Explanation:** An empty tree has no nodes, so the zigzag level order traversal is: []

{{< dots >}}
## Approach 🚀
The problem can be solved using a breadth-first search (BFS) where nodes are processed level by level. We will alternate the direction of traversal based on the level number.

### Initial Thoughts 💭
- Zigzag traversal requires alternating the order of nodes on each level.
- By using BFS, we can traverse the tree level by level, and reversing the nodes at odd levels will give us the desired zigzag order.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (i.e., the root is null), return an empty list.
- For large trees with up to 2000 nodes, ensure the solution handles the input efficiently.
- If a node has only one child (either left or right), make sure it is properly handled during the zigzag traversal.
- The tree must be processed within the provided constraints (2000 nodes).
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> tmp;
    queue<TreeNode*> q;

    if(root == NULL) return ans;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            TreeNode* it = q.front();
            q.pop();
            tmp.push_back(it->val);
            if(it->left  != NULL) q.push(it->left);
            if(it->right != NULL) q.push(it->right);
        }
        ans.push_back(tmp);
        tmp.clear();
    }
    return ans;
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    vector<vector<int>> ans = levelOrder(root);
    for(int i = 1; i < ans.size(); i += 2)
    {
        vector<int> tmp = ans[i];
        reverse(tmp.begin(), tmp.end());
        ans[i] = tmp;
    }
    return ans;

}
```

This function performs a level-order traversal on a binary tree, followed by a zigzag traversal, where every alternate level is reversed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> levelOrder(TreeNode* root) {
	```
	Define the 'levelOrder' function that performs a level-order traversal of a binary tree and returns a 2D vector.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	Initialize a 2D vector 'ans' to store the values of each level during the level-order traversal.

3. **Temporary Vector Initialization**
	```cpp
	    vector<int> tmp;
	```
	Initialize a temporary vector 'tmp' to store the values of nodes at each level.

4. **Queue Initialization**
	```cpp
	    queue<TreeNode*> q;
	```
	Create a queue 'q' for performing breadth-first search (BFS), which will store the nodes at each level.

5. **Empty Tree Check**
	```cpp
	    if(root == NULL) return ans;
	```
	Check if the root is null. If it is, return the empty result vector 'ans'.

6. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Push the root node into the queue to start the traversal.

7. **Main BFS Loop**
	```cpp
	    while(!q.empty()) {
	```
	Start the BFS loop which continues as long as there are nodes in the queue.

8. **Level Size**
	```cpp
	        int sz = q.size();
	```
	Store the number of nodes at the current level by checking the size of the queue.

9. **Level Node Processing**
	```cpp
	        while(sz--) {
	```
	Process each node at the current level by looping through the queue until all nodes at this level are processed.

10. **Queue Front**
	```cpp
	            TreeNode* it = q.front();
	```
	Get the front node from the queue to process it.

11. **Queue Pop**
	```cpp
	            q.pop();
	```
	Remove the processed node from the queue.

12. **Add Node Value to Temp**
	```cpp
	            tmp.push_back(it->val);
	```
	Add the current node's value to the 'tmp' vector.

13. **Left Child Check**
	```cpp
	            if(it->left  != NULL) q.push(it->left);
	```
	If the current node has a left child, push it to the queue for the next level.

14. **Right Child Check**
	```cpp
	            if(it->right != NULL) q.push(it->right);
	```
	If the current node has a right child, push it to the queue for the next level.

15. **Push Level to Result**
	```cpp
	        ans.push_back(tmp);
	```
	After processing all nodes at the current level, push the 'tmp' vector to 'ans'.

16. **Clear Temp Vector**
	```cpp
	        tmp.clear();
	```
	Clear the temporary vector 'tmp' for the next level.

17. **Return Result**
	```cpp
	    return ans;
	```
	Return the final 2D vector 'ans', which contains the level-order traversal of the tree.

18. **Function Definition**
	```cpp
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	```
	Define the 'zigzagLevelOrder' function which calls 'levelOrder' and modifies the result to achieve zigzag ordering.

19. **Call levelOrder**
	```cpp
	    vector<vector<int>> ans = levelOrder(root);
	```
	Call the 'levelOrder' function to get the initial level-order traversal.

20. **Zigzag Traversal**
	```cpp
	    for(int i = 1; i < ans.size(); i += 2)
	```
	Loop through the result vector and reverse every alternate level to achieve a zigzag order.

21. **Reverse Current Level**
	```cpp
	        vector<int> tmp = ans[i];
	```
	Copy the current level into 'tmp' before reversing it.

22. **Reverse Vector**
	```cpp
	        reverse(tmp.begin(), tmp.end());
	```
	Reverse the current level to achieve zigzag order.

23. **Assign Reversed Level**
	```cpp
	        ans[i] = tmp;
	```
	Assign the reversed level back to the result vector 'ans'.

24. **Return Result**
	```cpp
	    return ans;
	```
	Return the final result vector with the zigzag level-order traversal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In all cases, we must visit each node in the tree once, so the time complexity is O(n), where n is the number of nodes in the tree.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In the worst case, the queue may hold all the nodes at the last level of the tree, resulting in a space complexity of O(n). In the best case, when the tree is perfectly balanced, the space complexity could be reduced to O(log n).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/)

---
{{< youtube igbboQbiwqw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
