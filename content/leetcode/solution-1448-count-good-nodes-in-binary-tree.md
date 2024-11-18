
+++
authors = ["grid47"]
title = "Leetcode 1448: Count Good Nodes in Binary Tree"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1448: Count Good Nodes in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "2AdOBLcj2wk"
youtube_upload_date="2024-04-17"
youtube_thumbnail="https://i.ytimg.com/vi/2AdOBLcj2wk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/)

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
    int goodNodes(TreeNode* root) {
        return good(root, -100000);
    }

    int good(TreeNode* node, int mx) {
        if(node == NULL) return 0;
        int res = (node->val >= mx) ? 1: 0;
        res += good(node->left, max(mx, node->val));
        res += good(node->right, max(mx, node->val));
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1448.md" >}}
---
{{< youtube 2AdOBLcj2wk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1451: Rearrange Words in a Sentence](https://grid47.xyz/leetcode/solution-1451-rearrange-words-in-a-sentence/) |
| --- |
