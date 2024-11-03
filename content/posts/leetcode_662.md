
+++
authors = ["Crafted by Me"]
title = "Leetcode 662: Maximum Width of Binary Tree"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 662: Maximum Width of Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-width-of-binary-tree/description/)

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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #663: Equal Tree Partition](https://grid47.xyz/posts/leetcode_663) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

