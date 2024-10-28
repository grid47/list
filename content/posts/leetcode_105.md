
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal"
date = "2024-07-16"
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

{{< highlight cpp >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

