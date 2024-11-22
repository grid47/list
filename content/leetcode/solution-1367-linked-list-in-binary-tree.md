
+++
authors = ["grid47"]
title = "Leetcode 1367: Linked List in Binary Tree"
date = "2024-06-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1367: Linked List in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "OaA9MgG00AE"
youtube_upload_date="2024-09-07"
youtube_thumbnail="https://i.ytimg.com/vi/OaA9MgG00AE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        if(head == NULL) return true;
        if(root == NULL) return false;
        return (head->val == root->val) && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to determine if a linked list is represented as a path in a binary tree. A path in a binary tree is defined as a sequence of nodes starting from any node and proceeding down to any leaf node, following child nodes. The goal is to find if there exists a path in the binary tree where the values of the nodes match the values in the linked list in the same order.

### Approach
To solve this problem, we can use a recursive depth-first search (DFS) strategy. The main steps involved are:
1. **Recursion through the Tree**: For each node in the binary tree, check if there is a path that matches the linked list starting from that node.
2. **Match the Linked List**: If the current node value in the binary tree matches the current node value in the linked list, proceed to the next node in the linked list while continuing the search in the left and right children of the binary tree.
3. **Base Cases**: Handle the cases where either the linked list or the binary tree is exhausted, returning true or false accordingly.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // If the linked list is empty, it is considered a subpath
        if(head == NULL) return true;
        // If the binary tree is empty, the linked list cannot be a subpath
        if(root == NULL) return false;
        // Check if the current tree node matches the head of the list and recursively check both subtrees
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool dfs(ListNode* head, TreeNode* root) {
        // If we've reached the end of the linked list, we've found a valid path
        if(head == NULL) return true;
        // If the binary tree node is null but the linked list isn't, return false
        if(root == NULL) return false;
        // Check for value match and continue DFS in both left and right child nodes of the binary tree
        return (head->val == root->val) && (dfs(head->next, root->left) || dfs(head->next, root->right));
    }
};
```

1. **Class Definition**:
   - The `Solution` class encapsulates the solution with two public methods: `isSubPath` and `dfs`.

2. **The `isSubPath` Method**:
   - **Base Case for Linked List**: If `head` is `NULL`, return `true` since an empty linked list is trivially a subpath.
   - **Base Case for Tree**: If `root` is `NULL` but `head` is not, return `false`, indicating that the linked list cannot be a subpath in an empty tree.
   - **DFS Call**: Call the `dfs` function to check if the linked list matches the path starting from the current tree node, and also recursively check the left and right subtrees of the current node in the binary tree using `isSubPath`.

3. **The `dfs` Method**:
   - **Base Case for Linked List**: If `head` is `NULL`, return `true`, as we have successfully matched all values in the linked list.
   - **Base Case for Tree**: If `root` is `NULL` but `head` is not, return `false`, indicating the path does not match.
   - **Value Matching and Recursion**: Check if the values of the current linked list node (`head->val`) and the current tree node (`root->val`) match. If they do, recursively check both the left and right children of the tree node, moving to the next node in the linked list (`head->next`).

### Complexity Analysis
- **Time Complexity**:
  - The worst-case time complexity can be approximated as \(O(N \times M)\), where \(N\) is the number of nodes in the binary tree and \(M\) is the number of nodes in the linked list. This is because we might explore every path in the tree for each node in the linked list.
  
- **Space Complexity**:
  - The space complexity is \(O(H)\), where \(H\) is the height of the binary tree due to the recursion stack. In the worst case of a skewed tree, this can be \(O(N)\).

### Conclusion
The provided solution efficiently checks if a linked list is a subpath of a binary tree using a depth-first search approach. By systematically exploring each node in the binary tree and matching it against the linked list, the algorithm successfully determines the presence of the linked list within the tree. This method is both straightforward and effective, showcasing the utility of recursion in tree traversal problems. The code is well-structured and optimized for clarity, making it an excellent reference for similar problems involving linked lists and binary trees.

This thorough explanation outlines the functionality and logic of the code, making it easier for readers to understand how the solution operates and how it can be applied in practice.


[`Link to LeetCode Lab`](https://leetcode.com/problems/linked-list-in-binary-tree/description/)

---
{{< youtube OaA9MgG00AE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
