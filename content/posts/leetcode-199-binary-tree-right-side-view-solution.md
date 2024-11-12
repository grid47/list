
+++
authors = ["grid47"]
title = "Leetcode 199: Binary Tree Right Side View"
date = "2024-10-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 199: Binary Tree Right Side View in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-tree-right-side-view/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/199.webp" 
    alt="A glowing tree viewed from the right side, with the rightmost nodes gently illuminating."
    caption="Solution to LeetCode 199: Binary Tree Right Side View Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        list<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            vector<int> res;
            int sz = q.size();
            while(sz--) {
                auto tmp = q.front();
                q.pop_front();
                res.push_back(tmp->val);
                if(tmp->left) q.push_back(tmp->left);
                if(tmp->right) q.push_back(tmp->right);
            }
            ans.push_back(res.back());
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/199.md" >}}
---
{{< youtube d4zLyf32e3I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #200: Number of Islands](https://grid47.xyz/posts/leetcode-200-number-of-islands-solution/) |
| --- |
