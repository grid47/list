
+++
authors = ["grid47"]
title = "Leetcode 894: All Possible Full Binary Trees"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 894: All Possible Full Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Tree","Recursion","Memoization","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "nZtrZPTTCAo"
youtube_upload_date="2021-09-20"
youtube_thumbnail="https://i.ytimg.com/vi/nZtrZPTTCAo/maxresdefault.jpg"
comments = true
+++



---
Given an integer n, return all possible full binary trees with exactly n nodes. Each node of the tree must have the value 0. A full binary tree is defined as a binary tree where each node has either 0 or 2 children.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a single integer n which represents the number of nodes in the full binary trees. n will always be an odd integer.
- **Example:** `Input: n = 5`
- **Constraints:**
	- 1 <= n <= 20
	- n is always an odd integer.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all possible full binary trees with n nodes. Each tree in the list should be represented by its root node, where each node has the value 0. The trees can be returned in any order.
- **Example:** `Output: [[0,0,0,null,null,0,0],[0,0,0,0,0,0,0]]`
- **Constraints:**
	- The output should contain all unique full binary trees with n nodes.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all unique full binary trees for a given number of nodes n.

- 1. Use dynamic programming (DP) to generate all possible full binary trees with n nodes.
- 2. For each odd number of nodes i (1, 3, 5, ..., n), split the nodes into two subtrees by considering all possible left and right subtree sizes.
- 3. Recursively generate full binary trees for smaller subproblems and combine them into larger trees.
- 4. Store the root node of each tree and ensure the trees are unique.
{{< dots >}}
### Problem Assumptions ✅
- The value of n will always be odd.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5`  \
  **Explanation:** In this case, there are two possible full binary trees with 5 nodes. The trees are constructed by considering all possible ways to split the nodes into left and right subtrees.

- **Input:** `Input: n = 7`  \
  **Explanation:** For n = 7, there are several possible full binary trees. Each tree has 3 nodes in the left and right subtrees, with a root node connecting them.

{{< dots >}}
## Approach 🚀
The approach uses dynamic programming (DP) to build all possible full binary trees for n nodes. For each odd number n, recursively generate the left and right subtrees and combine them into full binary trees.

### Initial Thoughts 💭
- Each tree must have an odd number of nodes, as each non-leaf node must have exactly two children.
- Dynamic programming can be used to efficiently generate all possible full binary trees for smaller values of n and combine them.
- We can use a bottom-up approach, starting with small values of n and incrementally constructing larger trees.
{{< dots >}}
### Edge Cases 🌐
- If n = 1, the only possible tree is a single node.
- The solution should efficiently handle values of n up to 20.
- Since n is always an odd number, the solution can be designed to only process odd numbers.
- The solution should handle n up to 20 without performance issues.
{{< dots >}}
## Code 💻
```cpp
vector<TreeNode*> allPossibleFBT(int n) {
    
    vector<vector<TreeNode*>> dp(n + 1);
    dp[1].push_back(new TreeNode(0));

    for(int i = 3; i <= n; i += 2) {
        for(int l = 1; l < i; l += 2) {
            // cout << l;
            for(auto it: dp[l])
            for(auto it2: dp[i - l - 1]) {
                TreeNode* node = new TreeNode(0);
                node->left = it;
                node->right = it2;
                dp[i].push_back(node);
            }
        }
    }
    return dp[n];        
}
```

This code defines the function `allPossibleFBT`, which generates all possible full binary trees with `n` nodes. It uses dynamic programming to build solutions progressively by combining smaller trees into larger ones.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<TreeNode*> allPossibleFBT(int n) {
	```
	Define the function `allPossibleFBT`, which takes an integer `n` as input and returns a vector of pointers to TreeNode, representing all possible full binary trees with `n` nodes.

2. **Empty Line**
	```cpp
	    
	```
	This line is empty and used for formatting purposes.

3. **Dynamic Programming Table Initialization**
	```cpp
	    vector<vector<TreeNode*>> dp(n + 1);
	```
	Initialize a 2D vector `dp` where `dp[i]` will store all possible full binary trees with `i` nodes.

4. **Base Case Initialization**
	```cpp
	    dp[1].push_back(new TreeNode(0));
	```
	For the base case, initialize `dp[1]` with a single node tree. This is the only full binary tree with 1 node.

5. **Outer Loop (Iterating over odd numbers)**
	```cpp
	    for(int i = 3; i <= n; i += 2) {
	```
	Start a loop from `i = 3` to `n`, incrementing by 2. This ensures that only odd values of `i` are considered, as full binary trees can only have an odd number of nodes.

6. **Inner Loop (Iterating over left subtree sizes)**
	```cpp
	        for(int l = 1; l < i; l += 2) {
	```
	Start a loop to iterate over possible sizes of the left subtree, where `l` is the size of the left subtree, and it must be odd.

7. **Comment**
	```cpp
	            // cout << l;
	```
	This line is a commented-out debug statement that would print the current size of the left subtree.

8. **Loop Through Left Subtree Trees**
	```cpp
	            for(auto it: dp[l])
	```
	Iterate over all trees in `dp[l]`, which represent possible left subtrees for a tree with `i` nodes.

9. **Loop Through Right Subtree Trees**
	```cpp
	            for(auto it2: dp[i - l - 1]) {
	```
	Iterate over all trees in `dp[i - l - 1]`, which represent possible right subtrees for a tree with `i` nodes.

10. **TreeNode Creation**
	```cpp
	                TreeNode* node = new TreeNode(0);
	```
	Create a new tree node to serve as the root of the current full binary tree.

11. **Assign Left Subtree**
	```cpp
	                node->left = it;
	```
	Assign the left child of the current node to be one of the trees from `dp[l]`.

12. **Assign Right Subtree**
	```cpp
	                node->right = it2;
	```
	Assign the right child of the current node to be one of the trees from `dp[i - l - 1]`.

13. **Store Created Tree**
	```cpp
	                dp[i].push_back(node);
	```
	Add the newly created full binary tree to `dp[i]`, which stores all possible full binary trees with `i` nodes.

14. **End Inner Loop**
	```cpp
	            }
	```
	End the loop that iterates over possible right subtree trees.

15. **End Left Subtree Loop**
	```cpp
	        }
	```
	End the loop that iterates over possible left subtree sizes.

16. **End Outer Loop**
	```cpp
	    }
	```
	End the loop that iterates over all possible tree sizes `i`.

17. **Return Result**
	```cpp
	    return dp[n];        
	```
	Return the vector `dp[n]`, which contains all possible full binary trees with `n` nodes.

18. **End Function**
	```cpp
	}
	```
	End the function definition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^3)
- **Worst Case:** O(n^3)

The time complexity is O(n^3) in the worst case, where n is the number of nodes. The dynamic programming approach generates and combines trees for each odd value of n.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) in the worst case, where n is the number of nodes. This is due to the storage required for the DP array and the binary trees generated.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/all-possible-full-binary-trees/description/)

---
{{< youtube nZtrZPTTCAo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
