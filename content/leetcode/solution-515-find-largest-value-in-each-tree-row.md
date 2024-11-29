
+++
authors = ["grid47"]
title = "Leetcode 515: Find Largest Value in Each Tree Row"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 515: Find Largest Value in Each Tree Row in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/515.webp"
youtube = "0EVQluJY224"
youtube_upload_date="2021-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/0EVQluJY224/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/515.webp" 
    alt="A tree with rows of values, each row highlighted with the largest value softly glowing."
    caption="Solution to LeetCode 515: Find Largest Value in Each Tree Row Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is the root of a binary tree, represented as an array in level order.
- **Example:** `root = [3, 5, 2, 8, 6, 4]`
- **Constraints:**
	- The number of nodes in the tree will be in the range [0, 10^4].
	- Node values range from -231 to 231 - 1.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an array of the largest value in each row of the tree.
- **Example:** `[3, 5, 8]`
- **Constraints:**
	- The output should be an array of integers, where each integer is the largest value in the corresponding row of the tree.

{{< dots >}}
### Core Logic 🔍
**Goal:** To traverse each level of the tree and find the maximum value at that level.

- 1. Perform a level order traversal using a queue.
- 2. For each level, calculate the maximum value by comparing all the nodes at that level.
- 3. Store the maximum value for each level.
- 4. Return the array of maximum values.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree will be represented as an array using level order traversal.
- The tree will not be empty unless specified.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3, 5, 2, 8, 6, 4]`  \
  **Explanation:** For the tree [3, 5, 2, 8, 6, 4], the largest values at each level are: Level 0 = 3, Level 1 = 5, Level 2 = 8.

- **Input:** `root = [7, 1, 9, 4, null, 10]`  \
  **Explanation:** For the tree [7, 1, 9, 4, null, 10], the largest values at each level are: Level 0 = 7, Level 1 = 9, Level 2 = 10.

{{< dots >}}
## Approach 🚀
The approach is to use a level order traversal to traverse the tree and find the largest value at each level.

### Initial Thoughts 💭
- We need to process nodes level by level to find the maximum value in each row.
- A queue is ideal for this kind of level order traversal.
- For each level, we can find the maximum value by comparing all nodes at that level.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return an empty array.
- The algorithm should efficiently handle up to 10^4 nodes.
- Ensure the solution works with trees that have both positive and negative node values.
- The solution should handle up to 10^4 nodes in the tree.
{{< dots >}}
## Code 💻
```cpp
vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
    vector<int> res;        
    if(!root) return res;
    q.push(root);
    int mx;

    while(!q.empty()) {
        int sz = q.size();
        mx = INT_MIN;
        while(sz-- > 0) {
            root = q.front();
            q.pop();
            mx = max(mx, root->val);                
            if(root->left)  q.push(root->left);
            if(root->right) q.push(root->right);                
        }
        res.push_back(mx);
    }
    return res;    
}
```

This function finds the largest value in each row of a binary tree. It uses a breadth-first search (BFS) traversal to process each level of the tree and keeps track of the largest value at each level.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> largestValues(TreeNode* root) {
	```
	Defines the `largestValues` function, which returns a vector containing the largest value from each row in the binary tree.

2. **Queue Initialization**
	```cpp
	        queue<TreeNode*> q;
	```
	Initializes a queue to store nodes for the breadth-first traversal of the tree.

3. **Result Vector Initialization**
	```cpp
	    vector<int> res;        
	```
	Creates a vector `res` to store the largest value for each level of the tree.

4. **Check for Empty Tree**
	```cpp
	    if(!root) return res;
	```
	Checks if the tree is empty. If it is, returns the empty result vector.

5. **Push Root to Queue**
	```cpp
	    q.push(root);
	```
	Pushes the root node of the tree into the queue to begin the breadth-first traversal.

6. **Initialize Max Value**
	```cpp
	    int mx;
	```
	Declares a variable `mx` to store the largest value at each level of the tree during traversal.

7. **BFS Loop Start**
	```cpp
	    while(!q.empty()) {
	```
	Starts the outer while loop, which will run as long as there are nodes in the queue.

8. **Level Size Calculation**
	```cpp
	        int sz = q.size();
	```
	Calculates the number of nodes at the current level by checking the size of the queue.

9. **Initialize Max Value for Level**
	```cpp
	        mx = INT_MIN;
	```
	Initializes `mx` to the minimum possible integer value before comparing it with node values at the current level.

10. **Level Traversal Loop**
	```cpp
	        while(sz-- > 0) {
	```
	Begins an inner loop to process all nodes at the current level.

11. **Process Current Node**
	```cpp
	            root = q.front();
	```
	Retrieves the front node from the queue for processing.

12. **Pop Node from Queue**
	```cpp
	            q.pop();
	```
	Removes the front node from the queue after processing it.

13. **Update Max Value**
	```cpp
	            mx = max(mx, root->val);                
	```
	Updates the `mx` variable to hold the maximum value between the current value of `mx` and the current node's value.

14. **Push Left Child**
	```cpp
	            if(root->left)  q.push(root->left);
	```
	Pushes the left child of the current node to the queue if it exists.

15. **Push Right Child**
	```cpp
	            if(root->right) q.push(root->right);                
	```
	Pushes the right child of the current node to the queue if it exists.

16. **Store Max Value for Level**
	```cpp
	        res.push_back(mx);
	```
	Stores the largest value of the current level (`mx`) into the result vector.

17. **Return Result**
	```cpp
	    return res;    
	```
	Returns the result vector containing the largest value from each level of the binary tree.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of nodes in the tree because we process each node exactly once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) in the worst case due to the queue storing nodes at each level. In the best case (a skewed tree), the space complexity is O(1).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/)

---
{{< youtube 0EVQluJY224 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
