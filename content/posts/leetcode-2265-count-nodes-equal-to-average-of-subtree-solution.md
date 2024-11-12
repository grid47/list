
+++
authors = ["grid47"]
title = "Leetcode 2265: Count Nodes Equal to Average of Subtree"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2265: Count Nodes Equal to Average of Subtree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)

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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first; // sum of nodes present in left sub tree
        int l_cnt = left.second; // no. of nodes present in left sub tree
        
        auto right = solve(root->right);
        int r_sum = right.first; // sum of nodes present in right sub tree
        int r_cnt = right.second; // no. of nodes present in left sub tree
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt + 1;
        
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2265.md" >}}
---
{{< youtube yg9A3yLTcsE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2266: Count Number of Texts](https://grid47.xyz/posts/leetcode-2266-count-number-of-texts-solution/) |
| --- |
