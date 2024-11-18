
+++
authors = ["grid47"]
title = "Leetcode 98: Validate Binary Search Tree"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 98: Validate Binary Search Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "s6ATEkipzow"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp"
+++



[`Problem Link`](https://leetcode.com/problems/validate-binary-search-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/98.webp" 
    alt="A glowing tree with balanced nodes, radiating a sense of order and validation."
    caption="Solution to LeetCode 98: Validate Binary Search Tree Problem"
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root, *prv = NULL;
        // stk.push(root);
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                if(prv != NULL && prv -> val >= node->val)
                    return false;
                prv = node;
                node = node->right;
            }
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/98.md" >}}
---
{{< youtube s6ATEkipzow >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #99: Recover Binary Search Tree](https://grid47.xyz/leetcode/solution-99-recover-binary-search-tree/) |
| --- |
