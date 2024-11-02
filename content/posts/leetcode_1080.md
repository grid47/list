
+++
authors = ["Crafted by Me"]
title = "Leetcode 1080: Insufficient Nodes in Root to Leaf Paths"
date = "2020-11-17"
description = "Solution to Leetcode 1080"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/)

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
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(!root) return NULL;
        if(root->left == NULL && root->right == NULL)
            return root->val < limit ? NULL : root;
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right= sufficientSubset(root->right, limit - root->val);
        return root->left == root->right ? NULL : root;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

