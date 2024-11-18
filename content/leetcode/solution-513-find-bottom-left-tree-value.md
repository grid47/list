
+++
authors = ["grid47"]
title = "Leetcode 513: Find Bottom Left Tree Value"
date = "2024-09-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 513: Find Bottom Left Tree Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp"
youtube = "u_by_cTsNJA"
youtube_upload_date="2021-11-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/u_by_cTsNJA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/find-bottom-left-tree-value/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/513.webp" 
    alt="A tree with a glowing bottom-left node, showing the value of the deepest leftmost node in the binary tree."
    caption="Solution to LeetCode 513: Find Bottom Left Tree Value Problem"
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = q.front()->val;
        while(!q.empty()) {
            int sz = q.size();
            res = q.front()->val;
            while(sz-- > 0) {
                root = q.front();
                q.pop();
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);                
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/513.md" >}}
---
{{< youtube u_by_cTsNJA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #515: Find Largest Value in Each Tree Row](https://grid47.xyz/leetcode/solution-515-find-largest-value-in-each-tree-row/) |
| --- |
