
+++
authors = ["grid47"]
title = "Leetcode 110: Balanced Binary Tree"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 110: Balanced Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "BrnZDIoScEA"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/110.webp"
+++



[`Problem Link`](https://leetcode.com/problems/balanced-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/110.webp" 
    alt="A tree where branches gently balance on either side, with glowing nodes symbolizing equilibrium."
    caption="Solution to LeetCode 110: Balanced Binary Tree Problem"
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int l = h(root->left);
        int r = h(root->right);
        return abs(l - r) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right);
    }
    int h(TreeNode* node) {
        if(node == NULL) return 0;
        int l = h(node->left);
        int r = h(node->right);
        return 1 + max(l, r);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/110.md" >}}
---
{{< youtube BrnZDIoScEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #111: Minimum Depth of Binary Tree](https://grid47.xyz/leetcode/solution-111-minimum-depth-of-binary-tree/) |
| --- |
