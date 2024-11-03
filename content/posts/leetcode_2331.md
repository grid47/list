
+++
authors = ["Crafted by Me"]
title = "Leetcode 2331: Evaluate Boolean Binary Tree"
date = "2018-06-16"
description = "In-depth solution and explanation for Leetcode 2331: Evaluate Boolean Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/evaluate-boolean-binary-tree/description/)

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
    bool evaluateTree(TreeNode* root) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val;
        
        if(root->val == 2)
            return evaluateTree(root->left) || evaluateTree(root->right);
      else

return evaluateTree(root->left) && evaluateTree(root->right);        
    }
};
{{< /highlight >}}


---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2332: The Latest Time to Catch a Bus](https://grid47.xyz/posts/leetcode_2332) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

