
+++
authors = ["grid47"]
title = "Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree"
date = "2024-06-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1379: Find a Corresponding Node of a Binary Tree in a Clone of That Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Easy"
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        if (cloned == NULL)
            return cloned;
        if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
            ans = cloned;
        getTargetCopy(original, cloned->left, target);
        getTargetCopy(original, cloned->right, target);
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves two binary trees: an original tree and a cloned tree, both of which are structurally identical but may differ in node memory addresses. The goal is to find a reference to a specific target node in the cloned tree that corresponds to a given target node in the original tree. This is particularly useful in scenarios where we need to perform operations on a cloned version of a tree without modifying the original tree.

### Approach

To solve this problem, we can use a depth-first search (DFS) strategy to traverse the cloned tree while simultaneously searching for the target node from the original tree. The process involves:

1. **Recursive Traversal**: We will traverse the cloned tree using a recursive approach, comparing each node's value with the target node's value.
2. **Target Node Comparison**: When we find a node in the cloned tree that matches the value of the target node in the original tree, we will store a reference to this node.
3. **Return the Result**: After traversing the tree, we will return the reference to the found node.

### Code Breakdown (Step by Step)

The provided C++ code implements the above approach. Here's a detailed breakdown of how it works:

1. **TreeNode Structure**:
   ```cpp
   struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
   ```
   - The `TreeNode` structure defines a node in the binary tree, containing an integer value and pointers to its left and right children.

2. **Solution Class**:
   ```cpp
   class Solution {
   public:
       TreeNode* ans;
   ```
   - The `Solution` class contains a public member `ans`, which will store the reference to the found target node in the cloned tree.

3. **getTargetCopy Method**:
   ```cpp
   TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
   {
       if (cloned == NULL)
           return cloned;
   ```
   - This method takes three parameters: pointers to the original tree, the cloned tree, and the target node to find.
   - The first check ensures that if the current node in the cloned tree is `NULL`, we return `NULL`, indicating the end of that path in the tree.

4. **Target Node Comparison**:
   ```cpp
       if (cloned->val == target->val) // If target node found in cloned tree save it into a variable.
           ans = cloned;
   ```
   - If the value of the current node in the cloned tree matches the value of the target node, we store the reference to the cloned node in `ans`.

5. **Recursive Calls**:
   ```cpp
       getTargetCopy(original, cloned->left, target);
       getTargetCopy(original, cloned->right, target);
   ```
   - The method recursively calls itself to traverse the left and right children of the current node in the cloned tree, effectively performing a DFS traversal.

6. **Return the Result**:
   ```cpp
       return ans;
   }
   ```
   - Finally, after the recursive traversal, the method returns the `ans` variable, which will contain the reference to the target node in the cloned tree if found.

### Complexity

- **Time Complexity**: The time complexity of the solution is \(O(N)\), where \(N\) is the number of nodes in the cloned tree. In the worst case, we may have to visit all nodes to find the target node.

- **Space Complexity**: The space complexity is \(O(H)\), where \(H\) is the height of the tree. This accounts for the space used by the recursion stack during the DFS traversal. In a balanced binary tree, this would be \(O(\log N)\), and in the worst-case scenario (skewed tree), it could be \(O(N)\).

### Conclusion

The solution effectively finds the corresponding node in the cloned binary tree that matches the target node from the original tree by utilizing a depth-first search approach. By traversing the cloned tree and comparing node values, the algorithm efficiently identifies the desired node. This method is particularly useful in applications where maintaining the integrity of the original tree is crucial while performing operations on a cloned version. The clear structure and systematic approach of the code make it a valuable reference for developers and students working with binary trees and tree traversal algorithms. Overall, this problem highlights key concepts in tree data structures, recursion, and memory management, contributing to a deeper understanding of algorithmic problem-solving in computer science.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
