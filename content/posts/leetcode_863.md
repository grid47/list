
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 863: All Nodes Distance K in Binary Tree"
date = "2022-06-21"
description = "Solution to Leetcode 863"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/)

---

**Code:**

{{< highlight cpp >}}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*, TreeNode*> mp;
    set<TreeNode*> st;
    vector<int> ans;

    void parents(TreeNode* node) {
        if(!node) return;
        if(node->left) {
            mp[node->left] = node;
            parents(node->left);
        }

        if(node->right) {
            mp[node->right] = node;
            parents(node->right);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        parents(root);

        dfs(target, k);
        return ans;
    }

    void dfs(TreeNode* node, int k) {
        if(st.count(node)) return;
        st.insert(node);

        if(k == 0) {
            ans.push_back(node->val);
            return;
        }

        if(node->left) dfs(node->left, k - 1);
        if(node->right) dfs(node->right, k - 1);
        if(mp[node]) dfs(mp[node], k - 1);
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/863.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

