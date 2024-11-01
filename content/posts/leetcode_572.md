
+++
authors = ["Crafted by Me"]
title = "Leetcode 572: Subtree of Another Tree"
date = "2023-04-10"
description = "Solution to Leetcode 572"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/subtree-of-another-tree/description/)

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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(match(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);
    }
    
    bool match(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        if(r1->val != r2->val) return false;
        return match(r1->left, r2->left) &&
            match(r1->right, r2->right);
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/572.md" >}}
- by gpt
        
---
{{< youtube Qk7_vGWUMMQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

