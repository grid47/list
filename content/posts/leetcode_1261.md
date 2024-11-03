
+++
authors = ["Crafted by Me"]
title = "Leetcode 1261: Find Elements in a Contaminated Binary Tree"
date = "2021-05-21"
description = "In-depth solution and explanation for Leetcode 1261: Find Elements in a Contaminated Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/description/)

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
class FindElements {
    unordered_set<int> set;
public:
    void recover(TreeNode* root, int x) {
        if(root == NULL) return;
        root->val = x;
        set.emplace(x);
        recover(root->left, 2*x+1);
        recover(root->right, 2*x+2);
        }
    FindElements(TreeNode* root) {
        recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1261.md" >}}
---


"| 1262: Greatest Sum Divisible by Three |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

