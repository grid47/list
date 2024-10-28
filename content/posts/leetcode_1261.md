
+++
authors = ["Yasir"]
title = "Leetcode 1261: Find Elements in a Contaminated Binary Tree"
date = "2021-05-17"
description = "Solution to Leetcode 1261"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/)

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
class FindElements {
    unordered_set<int> set;
public:
    void recover(TreeNode* root, int x) {
        if(root == NULL) return;
        root->val = x;
        set.emplace(x);
        recover(root->left, 2*x+1);
        recover(root->right, 2*x+2);
        }
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

