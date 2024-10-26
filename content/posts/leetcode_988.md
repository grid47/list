
+++
authors = ["Yasir"]
title = "Leetcode 988: Smallest String Starting From Leaf"
date = "2022-02-12"
description = "Solution to Leetcode 988"
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

