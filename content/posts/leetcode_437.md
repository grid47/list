
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 437: Path Sum III"
date = "2023-08-20"
description = "Solution to Leetcode 437"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-sum-iii/description/)

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
    int cnt = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return cnt;
    }
    
    void dfs(TreeNode* root, long sum) {
        if(root == NULL) return;

        test(root, sum);
        dfs(root->left,  sum);
        dfs(root->right, sum);

    }
    
    void test(TreeNode* root, long sum) {
        if  (root     == NULL) return;
        if  (root->val == sum ) cnt++;
        test(root->left,  sum - root->val);
        test(root->right, sum - root->val);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/437.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
