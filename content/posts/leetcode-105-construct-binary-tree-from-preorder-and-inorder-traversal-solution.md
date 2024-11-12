
+++
authors = ["grid47"]
title = "Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/105.webp" 
    alt="A tree gently forming from two intertwining paths of glowing nodes, one representing preorder, the other inorder."
    caption="Solution to LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/105.md" >}}
---
{{< youtube GeltTz3Z1rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #107: Binary Tree Level Order Traversal II](https://grid47.xyz/posts/leetcode-107-binary-tree-level-order-traversal-ii-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
