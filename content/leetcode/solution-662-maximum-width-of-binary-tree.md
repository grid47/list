
+++
authors = ["grid47"]
title = "Leetcode 662: Maximum Width of Binary Tree"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 662: Maximum Width of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/662.webp" 
    alt="A binary tree where the maximum width is highlighted, with the width softly glowing as it’s measured."
    caption="Solution to LeetCode 662: Maximum Width of Binary Tree Problem"
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int width = 0;
        q.push({root, 0});
        while(!q.empty()) {
            int f = q.front().second;
            int b = q.back().second;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode* elem = q.front().first;
                int idx = q.front().second - b;
                q.pop();
                if(elem->left  != NULL) q.push({elem->left,  2 * idx + 1});
                if(elem->right != NULL) q.push({elem->right, 2 * idx + 2});                
            }
            width = max(width, b - f + 1);
        }
        return width;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/662.md" >}}
---
{{< youtube zHz0Ut1r-_8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #667: Beautiful Arrangement II](https://grid47.xyz/leetcode/solution-667-beautiful-arrangement-ii/) |
| --- |
