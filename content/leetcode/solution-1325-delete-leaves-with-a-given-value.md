
+++
authors = ["grid47"]
title = "Leetcode 1325: Delete Leaves With a Given Value"
date = "2024-06-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1325: Delete Leaves With a Given Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "FqAoYAwbwV8"
youtube_upload_date="2024-05-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/FqAoYAwbwV8/maxresdefault.webp"
+++



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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root->left) root->left = removeLeafNodes(root->left, target);
        if(root->right) root->right = removeLeafNodes(root->right, target);
        return root->left == root->right && root->val == target ? nullptr : root;
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires us to remove all leaf nodes from a binary tree whose values equal a given target value. A leaf node is defined as a node that has no left or right children. If a parent node becomes a leaf (meaning both its children were removed), we need to propagate this up the tree and potentially remove the parent as well.

### Approach
The approach taken in this solution is a recursive depth-first traversal of the binary tree. During the traversal, the algorithm performs the following tasks:

1. **Recursively Traverse**:
   - First, the function checks the left child of the current node and recursively calls itself to process the left subtree.
   - Then, it checks the right child and processes the right subtree similarly.

2. **Condition for Removal**:
   - After processing both children, the function checks if the current node has become a leaf node (both left and right children are null) and if its value matches the target.
   - If both conditions are satisfied, the function returns `nullptr`, effectively removing the node.
   - If the node should not be removed, it returns the current node.

3. **Base Case**:
   - The base case for the recursion is when the node is null. The function should handle this case to avoid dereferencing a null pointer.

### Code Breakdown (Step by Step)

1. **TreeNode Definition**:
   - This structure defines a binary tree node with integer values, along with pointers to left and right children.
   ```cpp
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
   ```

2. **Remove Leaf Nodes Function**:
   - This is the main function that initiates the removal process for leaf nodes with the target value.
   ```cpp
   class Solution {
   public:
       TreeNode* removeLeafNodes(TreeNode* root, int target) {
   ```

3. **Recursive Calls**:
   - The function makes recursive calls for both the left and right children of the current node.
   ```cpp
           if(root->left) root->left = removeLeafNodes(root->left, target);
           if(root->right) root->right = removeLeafNodes(root->right, target);
   ```

4. **Check for Leaf Node**:
   - After the recursive calls, the function checks if both left and right pointers are `nullptr` and if the current node's value equals the target.
   ```cpp
           return root->left == root->right && root->val == target ? nullptr : root;
   ```

5. **Function Return**:
   - The function returns either `nullptr` (if the current node needs to be removed) or the current node itself (if it should be retained in the tree).

### Complexity Analysis

- **Time Complexity**: 
  - The time complexity of this algorithm is \(O(N)\), where \(N\) is the number of nodes in the binary tree. In the worst case, the function visits every node once to determine whether it should be removed or retained.

- **Space Complexity**:
  - The space complexity is \(O(H)\), where \(H\) is the height of the binary tree. This accounts for the recursion stack. In the case of a balanced tree, the height would be \(O(\log N)\), and in the worst case of a skewed tree, it could be \(O(N)\).

### Conclusion
The provided solution efficiently removes leaf nodes from a binary tree that match a specified target value using a straightforward recursive approach. The depth-first traversal ensures that each node is checked and potentially modified based on its children. This implementation demonstrates the power of recursion in tree structures, allowing for elegant solutions to problems involving tree manipulation. By maintaining clear conditions for removal, the code effectively cleans up the tree while preserving the overall structure where necessary. This problem showcases important concepts in tree traversal and dynamic modification of tree structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-leaves-with-a-given-value/description/)

---
{{< youtube FqAoYAwbwV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
