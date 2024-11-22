
+++
authors = ["grid47"]
title = "Leetcode 606: Construct String from Binary Tree"
date = "2024-09-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 606: Construct String from Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/606.webp"
youtube = "b1WpYxnuebQ"
youtube_upload_date="2022-09-07"
youtube_thumbnail="https://i.ytimg.com/vi/b1WpYxnuebQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/606.webp" 
    alt="A binary tree where a string is being constructed by traversing the tree, with each character softly glowing."
    caption="Solution to LeetCode 606: Construct String from Binary Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string left  = tree2str(root->left);
        if(left!= "") left = '(' + left + ')';
        string right = tree2str(root->right);
        if(right != "") right = '(' + right + ')';
        if(left == "" && right != "") left = "()";
        // if(left != "" && right == "") right = "()";        
        return to_string(root->val)+left+right;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given the root node of a binary tree, the task is to generate a string representation of the tree following a specific format. The string should represent the binary tree in the following way:

- The root node is represented by its value.
- Left and right subtrees are enclosed in parentheses.
- If the left child is `null`, it is represented as an empty pair of parentheses `()` and must be included even if the right child exists.
- If a node has only a right child, then the left child must still be represented by an empty pair of parentheses.

### Approach

The key observation in solving this problem is that the binary tree needs to be represented in a depth-first traversal manner, where the root node is processed first, followed by its left subtree and then its right subtree.

1. **Recursive Approach**: The problem can be solved efficiently using recursion, starting from the root node. At each step:
   - If the node is `null`, return an empty string.
   - Otherwise, convert the current node value to a string.
   - Recursively process the left and right subtrees.
   - If the left child exists, enclose it in parentheses. If the right child exists, do the same.
   
2. **Edge Cases**:
   - If the left child is `null` and the right child exists, the left child must still be represented as an empty pair of parentheses `()`.
   - If both children are `null`, the node itself should only be represented by its value.

### Code Breakdown (Step by Step)

#### Step 1: Check for `null` root
```cpp
if (root == NULL) return "";
```
- If the root node is `null`, return an empty string. This handles the base case of the recursion when we reach the end of a branch in the tree.

#### Step 2: Recursively process the left child
```cpp
string left = tree2str(root->left);
if (left != "") left = '(' + left + ')';
```
- We recursively call the `tree2str` function on the left child. If the left child exists, the resulting string is wrapped in parentheses.
- If the left child is `null`, the recursive call will return an empty string, and no parentheses will be added.

#### Step 3: Recursively process the right child
```cpp
string right = tree2str(root->right);
if (right != "") right = '(' + right + ')';
```
- Similarly, we recursively process the right child of the current node. If the right child exists, we wrap the resulting string in parentheses.

#### Step 4: Handle the case where the left child is `null` and the right child exists
```cpp
if (left == "" && right != "") left = "()";
```
- If the left child is `null` and the right child exists, we add an empty pair of parentheses for the left child. This ensures that the tree string is formatted correctly, showing the absence of a left child.

#### Step 5: Combine the results
```cpp
return to_string(root->val) + left + right;
```
- Finally, we return the string representation of the current node. This consists of:
  - The root node value as a string (`to_string(root->val)`).
  - The string representing the left child (if it exists).
  - The string representing the right child (if it exists).
  
The result is a string representing the tree in the required format.

### Complexity

#### Time Complexity:
- **O(N)**: The time complexity is linear with respect to the number of nodes in the tree. Each node is visited exactly once, and at each node, the string operations (concatenation) are performed in constant time, assuming that the length of the strings representing the left and right children are bounded by the tree height.

#### Space Complexity:
- **O(H)**: The space complexity is dominated by the recursion stack, which in the worst case (for a skewed tree) can be as deep as the height of the tree (`H`). In a balanced tree, the height would be logarithmic relative to the number of nodes (`O(log N)`).

### Conclusion

This solution efficiently converts a binary tree into its string representation following the required format using a recursive approach. The approach:
1. Uses depth-first traversal to process each node.
2. Handles edge cases, such as missing left or right children.
3. Ensures that the final string correctly represents the structure of the tree.

The solution provides an optimal time complexity of **O(N)** and a space complexity of **O(H)**, making it well-suited for trees of varying sizes, from balanced trees to skewed trees.

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-string-from-binary-tree/description/)

---
{{< youtube b1WpYxnuebQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
