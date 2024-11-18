
+++
authors = ["grid47"]
title = "Leetcode 2641: Cousins in Binary Tree II"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2641: Cousins in Binary Tree II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "xvwTd19SncE"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/cousins-in-binary-tree-ii/description/)

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        list<TreeNode*> q;
        
        q.push_back(root);
        root->val = 0;
        map<TreeNode*, int> mp;
        while(!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while(sz--) {
                auto it = q.front();
                q.pop_front();
                if(it->left != NULL) {
                    mp[it] += it->left->val;
                    q.push_back(it->left);
                }
                if(it->right != NULL) {
                    mp[it] += it->right->val;
                    q.push_back(it->right);
                }
                sum += mp[it];
            }
            for(auto it: mp) {
                if(it.first->left != NULL) {
                    it.first->left->val = sum - it.second;
                }
                if(it.first->right != NULL) {
                    it.first->right->val = sum - it.second;
                }    
            }
            mp.clear();
        }
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2641.md" >}}
---
{{< youtube xvwTd19SncE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2643: Row With Maximum Ones](https://grid47.xyz/leetcode/solution-2643-row-with-maximum-ones/) |
| --- |
