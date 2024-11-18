
+++
authors = ["grid47"]
title = "Leetcode 655: Print Binary Tree"
date = "2024-09-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 655: Print Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/655.webp"
+++



[`Problem Link`](https://leetcode.com/problems/print-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/655.webp" 
    alt="A binary tree where nodes are printed visually, with the structure softly glowing as it is printed."
    caption="Solution to LeetCode 655: Print Binary Tree Problem"
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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = get_height(root), w = get_width(root);
        vector<vector<string>> ans(h, vector<string>(w, ""));
        helper(ans, root, 0, 0, w - 1);
        return ans;
    }

    int get_height(TreeNode *p) {
        if(!p) return 0;
        int left = get_height(p->left);
        int right = get_height(p->right);
        return max(left , right) + 1;
    }
    
    int get_width(TreeNode *p) {
        if(!p) return 0;
        int left = get_width(p->left);
        int right = get_width(p->right);
        return max(left, right)*2 + 1;
    }

    void helper(vector<vector<string>> &ans, TreeNode *p, int level, int l, int r) {
        if(!p) return;
        int mid = l + (r - l)/ 2;
        ans[level][mid] = to_string(p->val);
        helper(ans, p->left, level + 1, l, mid - 1);
        helper(ans, p->right, level + 1, mid + 1, r);        
    }
};

{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/655.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #658: Find K Closest Elements](https://grid47.xyz/leetcode/solution-658-find-k-closest-elements/) |
| --- |
