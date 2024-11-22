
+++
authors = ["grid47"]
title = "Leetcode 951: Flip Equivalent Binary Trees"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 951: Flip Equivalent Binary Trees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "izRDc1il9Pk"
youtube_upload_date="2021-08-14"
youtube_thumbnail="https://i.ytimg.com/vi/izRDc1il9Pk/maxresdefault.jpg"
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL || root2 == NULL) 
            return root1 == root2;

        return (root1->val == root2->val) && 
(flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));

    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine whether two binary trees are equivalent when considering a special form of equivalence, known as **flip equivalence**. In this problem, two binary trees are considered equivalent if they can be made identical by flipping the children of any number of nodes. A flip operation at a node means swapping its left and right children. The goal is to return `true` if the two binary trees are flip equivalent, and `false` otherwise.

### Approach

To solve this problem, we use a recursive approach to check the equivalence between two binary trees under the allowed flip operations. The idea is that for each pair of corresponding nodes in the two trees, we check if their values are the same, and then check recursively whether the subtrees rooted at those nodes are equivalent either in the original or flipped orientation.

There are two possible ways to check the equivalence of the subtrees:
1. The left child of `root1` is equivalent to the left child of `root2` and the right child of `root1` is equivalent to the right child of `root2`.
2. The left child of `root1` is equivalent to the right child of `root2` and the right child of `root1` is equivalent to the left child of `root2`.

If either of these conditions hold true for each pair of nodes, the trees are flip equivalent.

### Code Breakdown (Step by Step)

1. **Base Case**:
   ```cpp
   if(root1 == NULL || root2 == NULL) 
       return root1 == root2;
   ```
   - The base case checks whether either of the trees is `NULL`. If both are `NULL`, they are considered equivalent, so we return `true`. If only one of them is `NULL`, they are not equivalent, so we return `false`.

2. **Recursion for Node Values**:
   ```cpp
   return (root1->val == root2->val) && 
   (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
   flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
   ```
   - After ensuring that neither of the nodes is `NULL`, we check if their values are the same. If they are not, we return `false` immediately.
   - If the values are the same, we proceed to check the two recursive conditions:
     1. The left child of `root1` is flip equivalent to the left child of `root2` and the right child of `root1` is flip equivalent to the right child of `root2`.
     2. The left child of `root1` is flip equivalent to the right child of `root2` and the right child of `root1` is flip equivalent to the left child of `root2`.
   - If either of these conditions is true, we return `true`; otherwise, we return `false`.

3. **Flip Equivalence Check**:
   - The recursive function `flipEquiv()` is called for all the child nodes, checking whether the trees rooted at these child nodes are equivalent in either the original or flipped configuration.
   - The recursive calls are structured such that both configurations (original and flipped) are checked for each pair of corresponding child nodes.

### Complexity

1. **Time Complexity**:
   - The time complexity of this solution depends on the number of nodes in the binary trees. Since we visit each node once and perform constant-time operations for each node (i.e., comparing values and recursively checking child nodes), the time complexity is **O(N)**, where `N` is the number of nodes in the trees.
   - The recursion depth is also O(N) in the worst case (i.e., when the tree is skewed).

2. **Space Complexity**:
   - The space complexity is primarily due to the recursive stack used for traversing the tree. In the worst case (i.e., a skewed tree), the recursion depth will be O(N). Thus, the space complexity is **O(N)**.

### Conclusion

The solution uses a recursive approach to check if two binary trees are flip equivalent. The key idea is to recursively check the equivalence of the left and right subtrees, both in the original and flipped configurations, at each level of the tree. This approach ensures that we correctly handle cases where a flip at a node might be necessary to achieve equivalence. The time and space complexity of the solution are both O(N), making it efficient for solving this problem within the constraints typically given in competitive programming contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/flip-equivalent-binary-trees/description/)

---
{{< youtube izRDc1il9Pk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
