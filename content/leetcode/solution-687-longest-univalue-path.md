
+++
authors = ["grid47"]
title = "Leetcode 687: Longest Univalue Path"
date = "2024-08-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 687: Longest Univalue Path in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp"
youtube = "ZeBr9JMcjrU"
youtube_upload_date="2020-06-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZeBr9JMcjrU/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/687.webp" 
    alt="A tree where the longest univalue path is traced and softly glowing as it’s found."
    caption="Solution to LeetCode 687: Longest Univalue Path Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given the root of a binary tree. The task is to find the length of the longest path in the tree where all the nodes in the path have the same value. The path can be anywhere in the tree, not necessarily passing through the root. The path length is determined by the number of edges between the nodes.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary tree represented by its root node.
- **Example:** `root = [3, 2, 3, 1, 3, null, 3]`
- **Constraints:**
	- 0 <= Number of nodes <= 10^4
	- -1000 <= Node.val <= 1000
	- Tree depth will not exceed 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the length of the longest path in the binary tree where all nodes in the path have the same value. The path length is measured by the number of edges.
- **Example:** `For root = [3, 2, 3, 1, 3, null, 3], the output is 3.`
- **Constraints:**
	- The output should be an integer representing the length of the longest path.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the longest path where all nodes have the same value in the binary tree.

- 1. Traverse the tree using DFS to explore the longest path for each node.
- 2. For each node, check if its left and right child nodes have the same value as itself.
- 3. Update the maximum path length encountered during the DFS traversal.
{{< dots >}}
### Problem Assumptions ✅
- The binary tree may have a depth of up to 1000 nodes.
{{< dots >}}
## Examples 🧩
- **Input:** `root = [3, 2, 3, 1, 3, null, 3]`  \
  **Explanation:** The longest path with the same value (i.e., 3) is 3 -> 3 -> 3, which has a length of 3.

- **Input:** `root = [4, 4, 4, 1, 1, null, 4]`  \
  **Explanation:** The longest path with the same value (i.e., 4) is 4 -> 4 -> 4, which has a length of 2.

{{< dots >}}
## Approach 🚀
The approach is to use depth-first search (DFS) to traverse the tree and calculate the longest path where all nodes have the same value. We need to explore both left and right subtrees and ensure that the path continues as long as the nodes have the same value.

### Initial Thoughts 💭
- We need to explore both left and right subtrees for each node to find the longest path where all nodes have the same value.
- DFS is an ideal choice for this problem since we are required to explore all possible paths in the binary tree.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, return 0.
- The solution should handle large trees efficiently with up to 10^4 nodes.
- If all nodes have the same value, the path length will be the depth of the tree.
- Ensure the solution works within the constraint that the tree depth will not exceed 1000.
{{< dots >}}
## Code 💻
```cpp
class Solution {
int maxi;
public:
int longestUnivaluePath(TreeNode* root) {
    maxi = 0;
    if((root == NULL) || (root->left == NULL && root->right == NULL)  )
    return 0;
    dfs(root);
    return maxi;
}

int dfs(TreeNode *root) {
    if(root == NULL) return 0;
    int l = 0, r = 0;
    int lft = dfs(root->left);
    int rgt = dfs(root->right);
    if((root->left != NULL) && (root->left->val == root->val))
    l = lft;
    if((root->right != NULL) && (root->right->val == root->val))
    r = rgt;        

    maxi = max(maxi, l + r);
    return 1 + max(l, r);
}
```

This solution defines a method to find the longest univalue path in a binary tree, where the path consists of nodes with the same value. The method uses depth-first search (DFS) to calculate the longest path, updating the maximum length when necessary.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Class Definition**
	```cpp
	class Solution {
	```
	Define the Solution class where the main logic for finding the longest univalue path will be implemented.

2. **Variable Declaration**
	```cpp
	int maxi;
	```
	Declare the variable 'maxi' to store the maximum length of the univalue path found during the DFS traversal.

3. **Access Modifier**
	```cpp
	public:
	```
	The 'public' access modifier indicates that the following methods and variables are accessible from outside the class.

4. **Method Definition**
	```cpp
	int longestUnivaluePath(TreeNode* root) {
	```
	Define the 'longestUnivaluePath' method, which accepts a TreeNode 'root' and returns the length of the longest path of nodes with the same value.

5. **Initialize maxi**
	```cpp
	    maxi = 0;
	```
	Initialize 'maxi' to zero before starting the DFS traversal.

6. **Base Case Check**
	```cpp
	    if((root == NULL) || (root->left == NULL && root->right == NULL)  )
	```
	Check if the root is NULL or if the root has no children. If either condition is true, return 0 as no univalue path can exist.

7. **Return 0**
	```cpp
	    return 0;
	```
	Return 0 if the root node is NULL or a leaf node, as no path is possible.

8. **DFS Call**
	```cpp
	    dfs(root);
	```
	Call the DFS helper function to start the depth-first search on the tree.

9. **Return Maxi**
	```cpp
	    return maxi;
	```
	After completing the DFS traversal, return the value of 'maxi', which holds the longest univalue path.

10. **Helper Method Definition**
	```cpp
	int dfs(TreeNode *root) {
	```
	Define the 'dfs' method that performs a depth-first search on the tree and returns the length of the longest univalue path starting from the current node.

11. **Base Case Check**
	```cpp
	    if(root == NULL) return 0;
	```
	Check if the current node is NULL. If it is, return 0 since there's no univalue path from a NULL node.

12. **Initialize Left and Right**
	```cpp
	    int l = 0, r = 0;
	```
	Initialize two variables, 'l' and 'r', to store the lengths of univalue paths in the left and right subtrees, respectively.

13. **Recursive DFS for Left Subtree**
	```cpp
	    int lft = dfs(root->left);
	```
	Recursively call 'dfs' on the left child of the current node and store the result in 'lft'.

14. **Recursive DFS for Right Subtree**
	```cpp
	    int rgt = dfs(root->right);
	```
	Recursively call 'dfs' on the right child of the current node and store the result in 'rgt'.

15. **Left Child Univalue Path Check**
	```cpp
	    if((root->left != NULL) && (root->left->val == root->val))
	```
	If the left child exists and has the same value as the current node, add the length of the left univalue path ('lft') to 'l'.

16. **Update Left Path Length**
	```cpp
	    l = lft;
	```
	Update 'l' with the value of 'lft', which represents the length of the univalue path on the left side.

17. **Right Child Univalue Path Check**
	```cpp
	    if((root->right != NULL) && (root->right->val == root->val))
	```
	If the right child exists and has the same value as the current node, add the length of the right univalue path ('rgt') to 'r'.

18. **Update Right Path Length**
	```cpp
	    r = rgt;        
	```
	Update 'r' with the value of 'rgt', which represents the length of the univalue path on the right side.

19. **Max Path Calculation**
	```cpp
	    maxi = max(maxi, l + r);
	```
	Update 'maxi' to be the maximum of the current value of 'maxi' and the sum of 'l' and 'r', which represents the longest univalue path found so far.

20. **Return Path Length**
	```cpp
	    return 1 + max(l, r);
	```
	Return the length of the longest univalue path that includes the current node. This is done by adding 1 to the maximum of 'l' and 'r'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of nodes in the tree
- **Average Case:** O(n), since we visit each node once during the DFS
- **Worst Case:** O(n), where n is the number of nodes in the tree

The time complexity is linear in terms of the number of nodes, as each node is visited once.

### Space Complexity 💾
- **Best Case:** O(h), where h is the height of the tree
- **Worst Case:** O(h), where h is the height of the tree (which can be up to 1000 in the worst case)

The space complexity is proportional to the height of the tree, as the DFS function uses the system call stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-univalue-path/description/)

---
{{< youtube ZeBr9JMcjrU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
