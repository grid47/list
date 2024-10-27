
+++
authors = ["Yasir"]
title = "Leetcode 889: Construct Binary Tree from Preorder and Postorder Traversal"
date = "2022-05-23"
description = "Solution to Leetcode 889"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/)

---

**Code:**

{{< highlight html >}}
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
    int preIdx = 0, postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        if(root->val  != postorder[postIdx])
            root->left = constructFromPrePost(preorder, postorder);

        if(root->val  != postorder[postIdx])
            root->right = constructFromPrePost(preorder, postorder);

        postIdx++;
        return root;
    }
};
{{< /highlight >}}

