
+++
authors = ["Crafted by Me"]
title = "Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2471: Minimum Number of Operations to Sort a Binary Tree by Level in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/)

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
        
    int minimumOperations(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            vector<int> arr, idx(sz);
            while(sz--) {
                auto it = q.front();
                q.pop();
                arr.push_back(it->val);
                if(it->left != NULL) q.push(it->left);
                if(it->right!= NULL) q.push(it->right);
            }
            // cout << sz << " ";
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](int i, int j) { return arr[i] < arr[j]; });
            for(int i = 0; i < idx.size(); i++)
                for(; idx[i] != i; cnt++)
                    swap(idx[i], idx[idx[i]]);
        }
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube yi_h_UMHD7s >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2472: Maximum Number of Non-overlapping Palindrome Substrings](https://grid47.xyz/posts/leetcode_2472) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

