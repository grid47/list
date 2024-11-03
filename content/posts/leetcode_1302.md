
+++
authors = ["Crafted by Me"]
title = "Leetcode 1302: Deepest Leaves Sum"
date = "2021-04-10"
description = "In-depth solution and explanation for Leetcode 1302: Deepest Leaves Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/deepest-leaves-sum/description/)

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
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            int sz = q.size();
            sum = 0;
            while(sz--) {
                sum += q.front()->val;
                TreeNode* x = q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
        }
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1302.md" >}}
---
{{< youtube ebJiQrgumP4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1303: Find the Team Size](https://grid47.xyz/posts/leetcode_1303) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

