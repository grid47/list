
+++
authors = ["Crafted by Me"]
title = "Leetcode 94: Binary Tree Inorder Traversal"
date = "2024-07-31"
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

{{< highlight cpp >}}
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


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/94.md" >}}
- by gpt
        
---
{{< youtube g_S5WuasWUE >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

