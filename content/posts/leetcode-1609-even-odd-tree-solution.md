
+++
authors = ["grid47"]
title = "Leetcode 1609: Even Odd Tree"
date = "2024-11-01"
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1610: Maximum Number of Visible Points](https://grid47.xyz/posts/leetcode-1610-maximum-number-of-visible-points-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}