
+++
authors = ["grid47"]
title = "Leetcode 1315: Sum of Nodes with Even-Valued Grandparent"
date = "2024-06-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1315: Sum of Nodes with Even-Valued Grandparent in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
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
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root, 1, 1);
    }

    int helper(TreeNode* node, int p, int gp) {
        if (!node) return 0;
        return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val: 0);
    }
};
{{< /highlight >}}
---


### Problem Statement
Given a binary tree, find the sum of values of all nodes that have an even-valued grandparent. A grandparent node is defined as the parent of a node's parent. If a node does not have a grandparent, it is skipped. Return the sum of values of nodes that meet this condition.

### Approach
This problem uses a **recursive traversal** approach, where we keep track of the value of each node’s parent and grandparent. By using a helper function, we can pass the current node’s value as the parent and the previous parent’s value as the grandparent for each recursive call. This allows us to determine if the grandparent is even and conditionally add the node's value to the sum.

#### Key Steps:
1. **Define the Helper Function**: The helper function takes in the current node, its parent’s value, and its grandparent’s value.
2. **Base Case**: If the current node is `NULL`, return 0 because there are no values to add.
3. **Recursive Case**:
   - Recursively call the helper function for the left and right children of the current node.
   - Calculate the current node's value if its grandparent is even (`gp % 2 == 0`). If it is, add the current node’s value; otherwise, add 0.
4. **Accumulate Sum**: The total sum is calculated by recursively summing up the values from both left and right subtrees, plus the current node’s value if its grandparent is even.

### Code Breakdown (Step by Step)

1. **Initialize the Function**: Start with the main function `sumEvenGrandparent`, which calls the `helper` function on the root node. Initialize parent (`p`) and grandparent (`gp`) values to 1 to represent an odd value (since only even values are relevant).

   ```cpp
   int sumEvenGrandparent(TreeNode* root) {
       return helper(root, 1, 1);
   }
   ```

2. **Define the Helper Function**: The helper function takes in `node`, `p`, and `gp`. If the `node` is `NULL`, return 0 because there’s nothing to add.

   ```cpp
   int helper(TreeNode* node, int p, int gp) {
       if (!node) return 0;
   ```

3. **Recursive Accumulation**:
   - Recursively calculate the sum of values for the left and right subtrees, passing the current node’s value as the new parent and the old parent’s value as the new grandparent.
   - If the grandparent (`gp`) is even, add the current node’s value to the result.

   ```cpp
       return helper(node->left, node->val, p) + helper(node->right, node->val, p) + (gp % 2 == 0 ? node->val : 0);
   ```

4. **Return the Result**:
   - The helper function will return the sum of values of nodes with an even-valued grandparent for the entire tree when called from the main function.

### Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree. Each node is visited once, so the function runs in linear time.
- **Space Complexity**: \(O(H)\), where \(H\) is the height of the tree. This is due to the recursive stack in a depth-first traversal. In the worst case, if the tree is unbalanced, \(H\) could be \(N\); for a balanced tree, \(H\) is \(O(\log N)\).

### Conclusion
This solution efficiently calculates the sum of nodes with even-valued grandparents using recursion and conditional accumulation. The use of helper arguments for parent and grandparent values eliminates the need for additional data structures, making the code both space and time efficient. This approach is optimal for binary trees due to its simplicity and use of constant space beyond the recursive stack. The solution provides a clear, concise way to check relationships between nodes in a binary tree and accumulate specific values based on these relationships.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
