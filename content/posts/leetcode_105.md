
+++
authors = ["Yasir"]
title = "Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal"
date = "2024-07-14"
description = "Solution to Leetcode 105"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    map<int, int> mp;
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;

        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return helper(0, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(int ps, int is, int ie) {
        if(ps >= preorder.size() || is > ie) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        root->left  = helper(ps + 1, is, mp[root->val] - 1);
        root->right = helper(ps + mp[root->val] - is + 1, mp[root->val] + 1, ie);

        return root;
    }
    
};
{{< /highlight >}}

