
+++
authors = ["grid47"]
title = "Leetcode 2415: Reverse Odd Levels of Binary Tree"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2415: Reverse Odd Levels of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "iR3r4iEIDZo"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/iR3r4iEIDZo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/)

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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> vals;
        int level = 0;

        while(!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++)  {
                TreeNode* node = q.front(); q.pop();
                if(level %2) node->val= vals[sz- i - 1];
                if(node->left) {
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }

                if(node->right) {
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            vals = temp;
            level++;
        }
        return root;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2415.md" >}}
---
{{< youtube iR3r4iEIDZo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2418: Sort the People](https://grid47.xyz/leetcode/solution-2418-sort-the-people/) |
| --- |