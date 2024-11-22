
+++
authors = ["grid47"]
title = "Leetcode 1026: Maximum Difference Between Node and Ancestor"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1026: Maximum Difference Between Node and Ancestor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "f37BCBHGFGA"
youtube_upload_date="2020-07-07"
youtube_thumbnail="https://i.ytimg.com/vi/f37BCBHGFGA/maxresdefault.jpg"
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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }
    int helper(TreeNode* node, int mx, int mn) {
        if(!node) return mx - mn;
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        
        return max(helper(node->left, mx, mn), helper(node->right, mx, mn));
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to find the maximum difference between the values of any ancestor node and any descendant node in a binary tree. An ancestor of a node is any predecessor node on the path from the root to that node, while a descendant is any node that is reachable from that node. For example, in the following tree:

```
       8
      / \
     3   10
    / \
   1   6
      / \
     4   7
```

The maximum ancestor-descendant difference is between the node `8` (ancestor) and `1` (descendant), resulting in a difference of `7`.

### Approach
To solve the problem of finding the maximum ancestor-descendant difference:
1. **Recursive Traversal**: The solution employs a recursive depth-first search (DFS) to traverse the tree. During traversal, it keeps track of the maximum and minimum values encountered along the path from the root to the current node.
2. **Base Case**: When a leaf node (or a null node) is reached, the difference between the maximum and minimum values encountered along the path is calculated and returned.
3. **Maximizing the Difference**: At each node, the algorithm compares the current node's value against the current maximum and minimum values and updates them accordingly. The maximum difference from the left and right subtrees is then compared to find the overall maximum difference.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   - The `maxAncestorDiff` function is defined in the `Solution` class. It takes a pointer to the root node of the binary tree (`TreeNode* root`) as its parameter.

2. **Initial Call to Helper Function**:
   - The function invokes a helper function named `helper`, passing the root node and initializing both the maximum and minimum values to the value of the root node.

3. **Helper Function Definition**:
   - The `helper` function is a recursive function that takes three parameters:
     - `node`: the current node being visited.
     - `mx`: the maximum value encountered so far along the path from the root to the current node.
     - `mn`: the minimum value encountered so far along the same path.

4. **Base Case**:
   - The first line inside the `helper` function checks if the `node` is `nullptr`. If it is, it indicates that a leaf node has been reached, and the function returns the difference between the maximum and minimum values encountered on that path (`mx - mn`).

5. **Updating Maximum and Minimum**:
   - The next two lines update the `mx` and `mn` values:
     - `mx` is updated to the maximum of its current value and the value of the current node (`node->val`).
     - `mn` is updated to the minimum of its current value and the value of the current node.

6. **Recursive Calls**:
   - The function then recursively calls itself for the left and right child nodes of the current node:
     - `helper(node->left, mx, mn)` to process the left subtree.
     - `helper(node->right, mx, mn)` to process the right subtree.
   - It returns the maximum value obtained from both subtrees using `max(...)`, thus capturing the maximum ancestor-descendant difference found at any point in the tree.

7. **Final Return**:
   - The `maxAncestorDiff` function ultimately returns the result from the `helper` function, which contains the maximum ancestor-descendant difference across the entire binary tree.

### Complexity Analysis
- **Time Complexity**: The time complexity of the solution is \(O(n)\), where \(n\) is the number of nodes in the binary tree. This is because each node is visited exactly once during the traversal.
- **Space Complexity**: The space complexity is \(O(h)\), where \(h\) is the height of the tree. This space is used by the recursion stack during the depth-first search traversal. In the worst case (for a skewed tree), this can become \(O(n)\), but for balanced trees, it will be \(O(\log n)\).

### Conclusion
The `maxAncestorDiff` function effectively computes the maximum difference between an ancestor and a descendant in a binary tree using a recursive approach. By maintaining the maximum and minimum values encountered along each path from the root to the leaves, it ensures that the solution is both efficient and straightforward.

This solution is useful in various scenarios where binary tree structures are involved, such as in data organization, hierarchical data representation, and computational biology where tree-like structures often appear. The approach exemplifies the power of recursion and depth-first traversal in tree-based problems, making it a valuable addition to any algorithm enthusiast's toolkit.

In summary, this implementation demonstrates how to leverage recursion for problem-solving in binary trees, showcasing an efficient method to calculate differences based on hierarchical relationships within the data structure. The focus on clarity and structured problem-solving is key in algorithm design, making this solution a robust reference for similar challenges in coding interviews and competitive programming.


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

---
{{< youtube f37BCBHGFGA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
