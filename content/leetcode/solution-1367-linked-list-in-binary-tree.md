
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
youtube = "OaA9MgG00AE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/linked-list-in-binary-tree/description/)

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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1367.md" >}}
---
{{< youtube OaA9MgG00AE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1371: Find the Longest Substring Containing Vowels in Even Counts](https://grid47.xyz/leetcode/solution-1371-find-the-longest-substring-containing-vowels-in-even-counts/) |
| --- |
