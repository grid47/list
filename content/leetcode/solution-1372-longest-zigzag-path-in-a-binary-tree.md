
+++
authors = ["grid47"]
title = "Leetcode 1372: Longest ZigZag Path in a Binary Tree"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1372: Longest ZigZag Path in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "hbzdyIlvBKI"
youtube_upload_date="2023-04-20"
youtube_thumbnail="https://i.ytimg.com/vi/hbzdyIlvBKI/maxresdefault.jpg"
comments = true
+++



---
Given the root of a binary tree, find the length of the longest ZigZag path in the tree. A ZigZag path is one where you move left and right alternately, starting from any node.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by the root node. Each node is an integer.
- **Example:** `root = [1, null, 1, 1, 1, null, null, 1, 1, null, 1]`
- **Constraints:**
	- 1 <= Number of nodes <= 5 * 10^4
	- 1 <= Node.val <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the length of the longest ZigZag path in the tree.
- **Example:** `3`
- **Constraints:**
	- The output will be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the longest ZigZag path in the tree by alternating the direction of traversal.

- Start from any node and traverse the tree using a recursive approach.
- Keep track of the direction at each step (left or right).
- For each node, calculate the maximum ZigZag path length by switching the direction at each step.
{{< dots >}}
### Problem Assumptions ✅
- The tree is well-formed and does not contain cycles.
- Each node in the tree has at most two children (left and right).
{{< dots >}}
## Examples 🧩
- **Input:** `root = [1, null, 1, 1, 1, null, null, 1, 1, null, 1]`  \
  **Explanation:** The longest ZigZag path starts from the root, goes right, left, and then right again, with a length of 3.

- **Input:** `root = [1,1,1,null,1,null,null,1,1,null,1]`  \
  **Explanation:** The longest ZigZag path alternates between left and right, with a length of 4.

{{< dots >}}
## Approach 🚀
To solve the problem, use a depth-first search (DFS) approach to traverse the tree while alternating directions at each node.

### Initial Thoughts 💭
- The problem can be efficiently solved using a DFS approach with memoization.
- We can calculate the ZigZag length by maintaining a state that tracks the current direction and depth of traversal.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty (root is null), the result should be 0.
- The algorithm must efficiently handle trees with up to 50,000 nodes.
- If the tree contains only one node, the ZigZag length is 0.
- Ensure the solution is efficient for large trees with up to 50,000 nodes.
{{< dots >}}
## Code 💻
```cpp
int ans = 0;
map<TreeNode*, map<bool, int>> mp;
int zigzag(TreeNode* root, bool dir) {
    if(!root) return -1;
    if(mp.count(root) && mp[root].count(dir)) return mp[root][dir];
    int ans = 0;
    if(dir)
        ans = 1 + zigzag(root->left, !dir);
    if(!dir)
        ans = 1 + zigzag(root->right, !dir);            
    return mp[root][dir] = ans;
}

int longestZigZag(TreeNode* root) {
    if(!root) return 0;
    
    ans = max(ans, zigzag(root, 1));
    ans = max(ans, zigzag(root, 0));        
    
    if(root->left)
    longestZigZag(root->left);

    if(root->right)
    longestZigZag(root->right);

    return ans;
}
```

This code defines a solution to find the longest zigzag path in a binary tree, where the traversal alternates between left and right child nodes. The zigzag function recursively calculates the longest path, storing intermediate results in a map for efficiency.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int ans = 0;
	```
	Initialize the variable `ans` to store the maximum length of the zigzag path found.

2. **Data Structures**
	```cpp
	map<TreeNode*, map<bool, int>> mp;
	```
	A map `mp` is used to store intermediate results for each node (`TreeNode*`) and direction (`bool`), optimizing the recursive approach.

3. **Function Definition**
	```cpp
	int zigzag(TreeNode* root, bool dir) {
	```
	Define the recursive function `zigzag` that computes the zigzag length for a given node and direction.

4. **Base Case**
	```cpp
	    if(!root) return -1;
	```
	Base case: if the node is null, return -1 as there's no zigzag path from a null node.

5. **Memoization Check**
	```cpp
	    if(mp.count(root) && mp[root].count(dir)) return mp[root][dir];
	```
	Check if the zigzag path for the current node and direction has already been calculated and stored in `mp`. If so, return the stored result.

6. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initialize the local `ans` variable to store the zigzag length for the current node and direction.

7. **Recursive Step - Left Direction**
	```cpp
	    if(dir)
	```
	If the current direction is left (true), compute the zigzag length by moving to the left child node in the opposite direction.

8. **Recursive Call**
	```cpp
	        ans = 1 + zigzag(root->left, !dir);
	```
	Recursively compute the zigzag length by moving to the left child with the opposite direction (right). Add 1 to account for the current node.

9. **Recursive Step - Right Direction**
	```cpp
	    if(!dir)
	```
	If the current direction is right (false), compute the zigzag length by moving to the right child node in the opposite direction.

10. **Recursive Call**
	```cpp
	        ans = 1 + zigzag(root->right, !dir);            
	```
	Recursively compute the zigzag length by moving to the right child with the opposite direction (left). Add 1 to account for the current node.

11. **Memoization**
	```cpp
	    return mp[root][dir] = ans;
	```
	Store the computed zigzag length for the current node and direction in the `mp` map and return the result.

12. **Function Definition**
	```cpp
	int longestZigZag(TreeNode* root) {
	```
	Define the `longestZigZag` function, which computes the longest zigzag path starting from the root node.

13. **Base Case**
	```cpp
	    if(!root) return 0;
	```
	Base case: if the root is null, return 0 as there is no zigzag path.

14. **Recursive Call**
	```cpp
	    ans = max(ans, zigzag(root, 1));
	```
	Compute the zigzag path starting from the root with the left direction (1) and update `ans` with the maximum value.

15. **Recursive Call**
	```cpp
	    ans = max(ans, zigzag(root, 0));        
	```
	Compute the zigzag path starting from the root with the right direction (0) and update `ans` with the maximum value.

16. **Recursive Call**
	```cpp
	    if(root->left)
	```
	Check if the left child exists. If it does, recursively call `longestZigZag` on the left child.

17. **Recursive Call**
	```cpp
	    longestZigZag(root->left);
	```
	Recursively call `longestZigZag` for the left child node.

18. **Recursive Call**
	```cpp
	    if(root->right)
	```
	Check if the right child exists. If it does, recursively call `longestZigZag` on the right child.

19. **Recursive Call**
	```cpp
	    longestZigZag(root->right);
	```
	Recursively call `longestZigZag` for the right child node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear in terms of the number of nodes, as each node is visited once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

The space complexity is O(n) due to the recursion stack and memoization storage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/)

---
{{< youtube hbzdyIlvBKI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
