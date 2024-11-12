
+++
authors = ["grid47"]
title = "Leetcode 230: Kth Smallest Element in a BST"
date = "2024-10-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 230: Kth Smallest Element in a BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Depth-First Search","Binary Search Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/230.jpeg" 
    alt="A binary search tree with nodes softly glowing, showing the kth smallest element highlighted."
    caption="Solution to LeetCode 230: Kth Smallest Element in a BST Problem"
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        // stk.push(root);
        TreeNode* node= root;
        while(!stk.empty() || node) {
            if(node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                k--;
                if(k == 0) return node->val;
                node = node->right;
            }
        }
        return NULL;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/230.md" >}}
---
{{< youtube PwjF3RO9djY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #231: Power of Two](https://grid47.xyz/posts/leetcode-231-power-of-two-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
