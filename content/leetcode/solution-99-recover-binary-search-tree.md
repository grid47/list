
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
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp"
youtube = "bJBwOMPhe6Y"
youtube_upload_date="2020-10-31"
youtube_thumbnail="https://i.ytimg.com/vi/bJBwOMPhe6Y/sddefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/recover-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/99.webp" 
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #100: Same Tree](https://grid47.xyz/leetcode/solution-100-same-tree/) |
| --- |