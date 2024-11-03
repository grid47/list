
+++
authors = ["Crafted by Me"]
title = "Leetcode 437: Path Sum III"
date = "2023-08-23"
description = "In-depth solution and explanation for Leetcode 437: Path Sum III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/path-sum-iii/description/)

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
    int cnt = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return cnt;
    }
    
    void dfs(TreeNode* root, long sum) {
        if(root == NULL) return;

        test(root, sum);
        dfs(root->left,  sum);
        dfs(root->right, sum);

    }
    
    void test(TreeNode* root, long sum) {
        if  (root     == NULL) return;
        if  (root->val == sum ) cnt++;
        test(root->left,  sum - root->val);
        test(root->right, sum - root->val);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/437.md" >}}
---
{{< youtube Vam9gldRapY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #438: Find All Anagrams in a String](https://grid47.xyz/posts/leetcode_438) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

