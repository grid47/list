
+++
authors = ["Crafted by Me"]
title = "Leetcode 2265: Count Nodes Equal to Average of Subtree"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2265: Count Nodes Equal to Average of Subtree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/)

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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        
        auto left = solve(root->left);
        int l_sum = left.first; // sum of nodes present in left sub tree
        int l_cnt = left.second; // no. of nodes present in left sub tree
        
        auto right = solve(root->right);
        int r_sum = right.first; // sum of nodes present in right sub tree
        int r_cnt = right.second; // no. of nodes present in left sub tree
        
        int sum = root->val + l_sum + r_sum;
        int cnt = l_cnt + r_cnt + 1;
        
        if(root->val == sum/cnt) ans++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube yg9A3yLTcsE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2266: Count Number of Texts](https://grid47.xyz/posts/leetcode_2266) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

