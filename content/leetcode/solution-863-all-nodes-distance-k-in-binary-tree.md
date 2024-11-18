
+++
authors = ["grid47"]
title = "Leetcode 863: All Nodes Distance K in Binary Tree"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 863: All Nodes Distance K in Binary Tree in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Tree","Depth-First Search","Breadth-First Search","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "g1R3yEtHT8E"
img_src = ""
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
---
{{< youtube g1R3yEtHT8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #865: Smallest Subtree with all the Deepest Nodes](https://grid47.xyz/leetcode/solution-865-smallest-subtree-with-all-the-deepest-nodes/) |
| --- |
