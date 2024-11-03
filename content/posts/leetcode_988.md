
+++
authors = ["Crafted by Me"]
title = "Leetcode 988: Smallest String Starting From Leaf"
date = "2022-02-18"
description = "In-depth solution and explanation for Leetcode 988: Smallest String Starting From Leaf in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-string-starting-from-leaf/description/)

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
    string ans = "~";
    string smallestFromLeaf(TreeNode* root) {
        recur(root, "");
        return ans;
    }
    void recur(TreeNode* node, string s) {
        if(!node) return;
        if(!node->left && !node->right) {
            ans = min(ans, char(node->val + 'a') + s);
        }
        cout << node->val<<'\n';
        recur(node->left,  char(node->val + 'a') + s);
        recur(node->right, char(node->val + 'a') + s);  
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/988.md" >}}
---

| Next : [LeetCode #989: Add to Array-Form of Integer](https://grid47.xyz/posts/leetcode_989) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

