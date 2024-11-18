
+++
authors = ["grid47"]
title = "Leetcode 1161: Maximum Level Sum of a Binary Tree"
date = "2024-07-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1161: Maximum Level Sum of a Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/)

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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, mx= root->val;
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            int sum = 0;
            while(sz--) {
                TreeNode* n = q.front();
                q.pop();
                sum += n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);

            }
            if(sum > mx) {
                ans = lvl;
                mx = sum;
            }
            lvl++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1161.md" >}}
---
{{< youtube v3e5uYmzyxs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1162: As Far from Land as Possible](https://grid47.xyz/leetcode/solution-1162-as-far-from-land-as-possible/) |
| --- |
