
+++
authors = ["grid47"]
title = "Leetcode 111: Minimum Depth of Binary Tree"
date = "2024-10-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 111: Minimum Depth of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/111.webp"
youtube = "Ukbbnzxmd8o"
youtube_upload_date="2023-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/Ukbbnzxmd8o/sddefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/111.webp" 
    alt="A deep tree with soft, glowing light reaching the minimal depth, highlighting the shortest path."
    caption="Solution to LeetCode 111: Minimum Depth of Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a binary tree, find its minimum depth. The minimum depth is defined as the number of nodes along the shortest path from the root node down to the nearest leaf node. A leaf node is a node that does not have any children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary tree represented by its root node.
- **Example:** `root = [1,null,2,null,3,null,4]`
- **Constraints:**
	- The number of nodes in the tree is in the range [0, 10^5].
	- -1000 <= Node.val <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is the minimum depth of the binary tree, which is the number of nodes along the shortest path from the root to a leaf node.
- **Example:** `5`
- **Constraints:**
	- The minimum depth is always a positive integer if the tree is non-empty.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum depth by recursively checking the depth of the left and right subtrees and choosing the minimum of them.

- If the tree is empty, return 0.
- Traverse the tree recursively to find the depths of the left and right subtrees.
- If the left or right subtree is NULL, return the depth of the other subtree.
- Return the minimum of the left and right subtree depths plus one to account for the current node.
{{< dots >}}
### Problem Assumptions ✅
- The input is a valid binary tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [10,5,15,null,null,12,20]`  \
  **Explanation:** The tree is balanced and has a minimum depth of 2, as the shortest path from the root to a leaf is from 10 to 15.

- **Input:** `Input: root = [1,null,2,null,3,null,4]`  \
  **Explanation:** The tree is a straight line, and the minimum depth is 5, which corresponds to the path from 1 to 4.

{{< dots >}}
## Approach 🚀
To find the minimum depth of the binary tree, we need to recursively traverse the tree and calculate the depth of each subtree, ensuring that we take the shortest path to a leaf node.

### Initial Thoughts 💭
- A recursive approach can be used where the base case checks for null nodes and returns a depth of 0.
- At each step, we compare the depth of the left and right subtrees and return the smaller value.
- We can optimize by handling cases where one of the subtrees is null separately to avoid unnecessary recursive calls.
{{< dots >}}
### Edge Cases 🌐
- If the input tree is empty, return 0, as there are no nodes in the tree.
- The algorithm should efficiently handle large trees, up to the constraint of 10^5 nodes.
- The algorithm should work even for edge cases like a tree with only one node, where the minimum depth is 1.
- The algorithm should run in O(n) time, where n is the number of nodes in the tree, to handle large inputs.
{{< dots >}}
## Code 💻
```cpp
int minDepth(TreeNode* root) {
    
    if(root == NULL) return 0;
    
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    
    if(root->left && root->right) {
        return 1 + ((l < r)? l: r);            
    }
    
    if(root->left) {
        return 1 + l;                        
    }

    return 1 + r;                        
}
```

This solution computes the minimum depth of a binary tree using a recursive approach. It considers different cases based on the presence of left and right child nodes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minDepth(TreeNode* root) {
	```
	Define the main function to compute the minimum depth of a binary tree.

2. **Base Case**
	```cpp
	    if(root == NULL) return 0;
	```
	Base case: If the tree is empty, return 0 as the depth.

3. **Recursive Call**
	```cpp
	    int l = minDepth(root->left);
	```
	Recursively calculate the minimum depth of the left subtree.

4. **Recursive Call**
	```cpp
	    int r = minDepth(root->right);
	```
	Recursively calculate the minimum depth of the right subtree.

5. **Condition Evaluation**
	```cpp
	    if(root->left && root->right) {
	```
	Check if both left and right children exist.

6. **Return Statement**
	```cpp
	        return 1 + ((l < r)? l: r);            
	```
	Return the minimum depth of the left or right subtree plus 1 for the current node.

7. **Condition Evaluation**
	```cpp
	    if(root->left) {
	```
	Check if only the left child exists.

8. **Return Statement**
	```cpp
	        return 1 + l;                        
	```
	Return the depth of the left subtree plus 1 for the current node.

9. **Whitespace**
	```cpp
	
	```
	Add spacing for better readability.

10. **Return Statement**
	```cpp
	    return 1 + r;                        
	```
	If only the right child exists, return its depth plus 1 for the current node.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of nodes, because we visit each node once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(h)

The space complexity is O(h), where h is the height of the tree, due to the recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-depth-of-binary-tree/description/)

---
{{< youtube Ukbbnzxmd8o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
