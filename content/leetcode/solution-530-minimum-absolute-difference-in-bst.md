
+++
authors = ["grid47"]
title = "Leetcode 530: Minimum Absolute Difference in BST"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 530: Minimum Absolute Difference in BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "NttA_NC_ZhI"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/530.webp" 
    alt="A binary search tree where nodes light up showing the minimum absolute difference between node values."
    caption="Solution to LeetCode 530: Minimum Absolute Difference in BST Problem"
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
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prv = NULL; int ans = INT_MAX;
        stack<TreeNode*> stk;
        while(!stk.empty() || root) {
            if(root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                if(prv != NULL) {
                    ans = min(ans, root->val - prv->val);
                }
                prv = root;
                root = root->right;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/530.md" >}}
---
{{< youtube NttA_NC_ZhI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #532: K-diff Pairs in an Array](https://grid47.xyz/leetcode/solution-532-k-diff-pairs-in-an-array/) |
| --- |
