
+++
authors = ["grid47"]
title = "Leetcode 1123: Lowest Common Ancestor of Deepest Leaves"
date = "2024-07-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1123: Lowest Common Ancestor of Deepest Leaves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yVw0Q8QknJg"
youtube_upload_date="2020-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yVw0Q8QknJg/maxresdefault.webp"
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }

    pair<TreeNode*, int> helper(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.second > right.second)
        return {left.first, left.second + 1};
        else if(left.second < right.second)
        return {right.first, right.second + 1};
        return {root, left.second + 1};
    }
};
{{< /highlight >}}
---


### Problem Statement
The problem requires finding the lowest common ancestor (LCA) of the deepest leaves in a binary tree. The LCA of two nodes `A` and `B` in a binary tree is defined as the deepest node that is an ancestor of both `A` and `B`. If the tree has multiple deepest leaves, the LCA should be the deepest node that connects them.

For instance, consider the binary tree below:

```
        1
       / \
      2   3
     / \   \
    4   5   6
   /
  7
```

In this example, the deepest leaves are `7`, and the LCA of the deepest leaves is `4`.

### Approach
To solve this problem, the algorithm follows a recursive approach:
1. **Depth-First Search (DFS)**: The algorithm traverses the tree using DFS to calculate the depth of each node and identify the deepest leaves.
2. **Pair Return**: The recursive helper function returns a pair consisting of:
   - The deepest node found (LCA candidate).
   - The depth of that node.
3. **Comparison of Depths**: While traversing the tree, if the left child is deeper, the left node is returned as the potential LCA. If the right child is deeper, the right node is returned. If both children are at the same depth, the current node is returned as the LCA.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class is defined, which contains the method `lcaDeepestLeaves`.

   ```cpp
   class Solution {
   public:
   ```

2. **Method Definition**: The public method `lcaDeepestLeaves` accepts a pointer to the root of the binary tree and calls the helper function.

   ```cpp
       TreeNode* lcaDeepestLeaves(TreeNode* root) {
           return helper(root).first; // Returns the first element of the pair returned by helper
       }
   ```

3. **Helper Function**: The `helper` function is defined, which is responsible for traversing the tree recursively.

   ```cpp
       pair<TreeNode*, int> helper(TreeNode* root) {
   ```

4. **Base Case**: The base case checks if the current node (`root`) is `NULL`. If it is, the function returns a pair with `NULL` and depth `0`.

   ```cpp
           if (root == NULL) return {NULL, 0}; // Base case
   ```

5. **Recursive Calls**: The function recursively calls itself for the left and right children of the current node to compute their respective depths and potential LCAs.

   ```cpp
           auto left = helper(root->left);   // Left subtree
           auto right = helper(root->right); // Right subtree
   ```

6. **Depth Comparison**: The function compares the depths of the left and right subtrees. Depending on which subtree is deeper, it returns the appropriate node and its depth.

   ```cpp
           if (left.second > right.second)
               return {left.first, left.second + 1}; // Left subtree is deeper
           else if (left.second < right.second)
               return {right.first, right.second + 1}; // Right subtree is deeper
   ```

7. **Same Depth Case**: If both left and right depths are equal, the current node is the LCA of the deepest leaves.

   ```cpp
           return {root, left.second + 1}; // Current node is LCA
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The overall time complexity of this solution is \(O(N)\), where \(N\) is the number of nodes in the tree. This is because the algorithm performs a single traversal of the tree.
- **Space Complexity**: The space complexity is \(O(H)\), where \(H\) is the height of the tree. This accounts for the space used by the call stack during the recursive traversal. In the worst case of a skewed tree, this could be \(O(N)\).

### Conclusion
The `lcaDeepestLeaves` function efficiently computes the lowest common ancestor of the deepest leaves in a binary tree using a depth-first search approach. By leveraging recursion, the algorithm explores each node while simultaneously calculating depths and potential ancestors.

This implementation exemplifies a clear and efficient method to tackle tree-related problems in C++. The use of a pair to return both the node and its depth is a clever way to maintain the necessary information during the recursive calls.

In summary, the solution showcases effective techniques for tree traversal and ancestor identification, making it a valuable reference for developers working on similar problems in binary trees. By emphasizing clarity and efficiency, this code serves as a strong example of best practices in algorithm design.


[`Link to LeetCode Lab`](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/)

---
{{< youtube yVw0Q8QknJg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
