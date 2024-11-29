
+++
authors = ["grid47"]
title = "Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree"
date = "2024-06-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1457: Pseudo-Palindromic Paths in a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MBsSpQnaFzg"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/MBsSpQnaFzg/maxresdefault.jpg"
comments = true
+++



---
You are given a binary tree where each node contains a digit from 1 to 9. A path from the root to a leaf node is considered pseudo-palindromic if at least one permutation of the node values in the path can form a palindrome. Your task is to return the number of pseudo-palindromic paths in the tree.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of the root node of a binary tree, where each node contains an integer from 1 to 9.
- **Example:** `Input: root = [4, 5, 3, 3, 2, null, 2]`
- **Constraints:**
	- The number of nodes in the tree is between 1 and 100,000.
	- Each node contains an integer between 1 and 9.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the number of pseudo-palindromic paths from the root to leaf nodes.
- **Example:** `Output: 2`
- **Constraints:**
	- The output must be a single integer representing the count of pseudo-palindromic paths.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the number of pseudo-palindromic paths in the tree.

- Use depth-first search (DFS) to traverse the tree from the root to the leaves.
- Keep track of the path from the root to the current node using bitwise operations to track the frequency of digits.
- A path is pseudo-palindromic if at most one digit occurs an odd number of times in the path.
- Count how many paths are pseudo-palindromic as you traverse the tree.
{{< dots >}}
### Problem Assumptions ✅
- The input tree is a valid binary tree with nodes containing digits from 1 to 9.
- There will be no more than 100,000 nodes in the tree.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: root = [2, 3, 1, 3, 1, null, 1]`  \
  **Explanation:** Output: 2. There are three paths: [2, 3, 3], [2, 1, 1], and [2, 3, 1]. The paths [2, 3, 3] and [2, 1, 1] are pseudo-palindromic, as they can be rearranged to form palindromes.

- **Input:** `Input: root = [5, 6, 6, null, null, 5, 5]`  \
  **Explanation:** Output: 1. Only the path [5, 6, 6] is pseudo-palindromic, as it can be rearranged to [6, 5, 6].

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, use a depth-first search (DFS) approach to traverse the binary tree while keeping track of node values using bitwise operations. Each node value is mapped to a bit, and the presence of a digit in the path is tracked using a bitmask.

### Initial Thoughts 💭
- We need to identify if the digits in a path can form a palindrome, which requires checking the frequency of digits in that path.
- A path can be pseudo-palindromic if at most one digit occurs an odd number of times.
- We can use a bitmask to track how many times each digit appears in the path and easily check if the path is pseudo-palindromic.
{{< dots >}}
### Edge Cases 🌐
- If the tree is empty, the output should be 0.
- For trees with a large number of nodes (up to 100,000), ensure the solution runs within time limits.
- A single-node tree with a digit from 1 to 9 should return 1, as the path is trivially pseudo-palindromic.
- Ensure that the solution handles edge cases like trees with no pseudo-palindromic paths.
{{< dots >}}
## Code 💻
```cpp
int pseudoPalindromicPaths (TreeNode* root) {
    return dfs(root, 0);
}

int dfs(TreeNode* root, int cnt){
    if(!root) return 0;
    cnt ^= (1 << (root->val - 1));
    int res = dfs(root->left, cnt) + dfs(root->right, cnt);
    if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
        res++;
    return res;
}

```

This code defines a function 'pseudoPalindromicPaths' to count the number of pseudo-palindromic paths in a binary tree. A path is pseudo-palindromic if at most one character has an odd count in its binary representation.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int pseudoPalindromicPaths (TreeNode* root) {
	```
	This function is the entry point for counting pseudo-palindromic paths. It calls the helper function 'dfs' starting from the root of the tree with an initial count of '0'.

2. **Function Call**
	```cpp
	    return dfs(root, 0);
	```
	This line calls the 'dfs' function to perform a depth-first search, passing the root of the tree and an initial value of 'cnt' (0). The result from 'dfs' is returned.

3. **Function Declaration**
	```cpp
	int dfs(TreeNode* root, int cnt){
	```
	The 'dfs' function is a recursive helper function that traverses the tree. It takes the current node ('root') and the bitmask 'cnt' which tracks the parity of the values of the nodes visited along the path.

4. **Base Case**
	```cpp
	    if(!root) return 0;
	```
	Base case of the recursion. If the current node is NULL, it returns 0 (no pseudo-palindromic path).

5. **Bit Manipulation**
	```cpp
	    cnt ^= (1 << (root->val - 1));
	```
	This line updates the 'cnt' bitmask by toggling the bit corresponding to the value of the current node. The bitmask tracks which values have odd counts.

6. **Recursive Call**
	```cpp
	    int res = dfs(root->left, cnt) + dfs(root->right, cnt);
	```
	This line recursively calls 'dfs' for both the left and right children of the current node. The results are accumulated in 'res'.

7. **Leaf Node Check**
	```cpp
	    if(root->left == NULL && root->right == NULL && (cnt &(cnt -1)) == 0)
	```
	At a leaf node, if the bitmask 'cnt' has at most one bit set (which means at most one value has an odd count), the path is pseudo-palindromic.

8. **Result Update**
	```cpp
	        res++;
	```
	If the current path is pseudo-palindromic, increment the result 'res'.

9. **Return Statement**
	```cpp
	    return res;
	```
	The result 'res', which is the total count of pseudo-palindromic paths found in the current subtree, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The DFS traversal visits every node exactly once, so the time complexity is linear in terms of the number of nodes, `n`.

### Space Complexity 💾
- **Best Case:** O(h)
- **Worst Case:** O(h)

The space complexity is O(h), where `h` is the height of the tree. This is due to the recursion stack used in the DFS traversal.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/)

---
{{< youtube MBsSpQnaFzg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
