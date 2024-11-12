
+++
authors = ["grid47"]
title = "Leetcode 1609: Even Odd Tree"
date = "2024-05-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1609: Even Odd Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/even-odd-tree/description/)

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool isEI = true;
        // increasing - I
        // even - E
        while(!q.empty()) {
            int sz = q.size();
            int prv = isEI? INT_MIN : INT_MAX;
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
                if(isEI) {
                    if(n->val % 2 == 0) return false;
                    if(n->val <= prv)    return false;
                } else {
                    if(n->val % 2 == 1) return false;                    
                    if(n->val >= prv)    return false;
                }
                prv = n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            isEI = !isEI;
        }

        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1609.md" >}}
---
{{< youtube FkNWN1Fj_TY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1615: Maximal Network Rank](https://grid47.xyz/posts/leetcode-1615-maximal-network-rank-solution/) |
| --- |
