
+++
authors = ["grid47"]
title = "Leetcode 99: Recover Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 99: Recover Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/recover-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.jpeg" 
    alt="A tree softly rearranging its nodes, finding its balance and order."
    caption="Solution to LeetCode 99: Recover Binary Search Tree Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    TreeNode *prv = NULL, * fst = NULL , *scd = NULL;
    void inorder(TreeNode* node)
    {
        if(!node) return;
        inorder(node->left);
        if (prv && node->val < prv->val) {
            if (!fst)  fst = prv;
            scd = node; 
        }
        prv = node;
        inorder(node->right);
    }
public:
    void recoverTree(TreeNode* node) {
        inorder(node);
        swap(fst->val, scd->val);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/99.md" >}}
---
{{< youtube bJBwOMPhe6Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #100: Same Tree](https://grid47.xyz/posts/leetcode-100-same-tree-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
