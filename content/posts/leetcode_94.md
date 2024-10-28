
+++
authors = ["Yasir"]
title = "Leetcode 94: Binary Tree Inorder Traversal"
date = "2024-07-27"
description = "Solution to Leetcode 94"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-inorder-traversal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;
        while (root || !todo.empty()) {
            while (root) {
                todo.push(root);
                root = root -> left;
            }
            root = todo.top();
            todo.pop();
            nodes.push_back(root -> val);
            root = root -> right;
        }
        return nodes;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

