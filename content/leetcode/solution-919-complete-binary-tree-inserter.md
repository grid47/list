
+++
authors = ["grid47"]
title = "Leetcode 919: Complete Binary Tree Inserter"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 919: Complete Binary Tree Inserter in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Design","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/complete-binary-tree-inserter/description/)

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
class CBTInserter {
    vector<TreeNode*> tree;
public:
    CBTInserter(TreeNode* root) {
        tree.push_back(root);
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i]->left) tree.push_back(tree[i]->left);
            if(tree[i]->right) tree.push_back(tree[i]->right);
        }
    }
    
    int insert(int val) {
        int N = tree.size();
        TreeNode* node = new TreeNode(val);
        tree.push_back(node);
        if(N%2) tree[(N-1)/2]->left = node;
        else    tree[(N-1)/2]->right= node;
        return tree[(N-1)/2]->val;
    }
    
    TreeNode* get_root() {
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/919.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #921: Minimum Add to Make Parentheses Valid](https://grid47.xyz/leetcode/solution-921-minimum-add-to-make-parentheses-valid/) |
| --- |
