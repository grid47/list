
+++
authors = ["Crafted by Me"]
title = "Leetcode 429: N-ary Tree Level Order Traversal"
date = "2023-08-31"
description = "Solution to Leetcode 429"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-ary-tree-level-order-traversal/description/)

---

**Code:**

{{< highlight cpp >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        levelOrderT(root, 0, ans);
        return ans;
    }

    void levelOrderT(Node* node, int level, vector<vector<int>> &ans) {
        if(level == size(ans)) {
            ans.push_back({node->val});
        } else {
            ans[level].push_back(node->val);
        }

        for(Node* child: node->children) {
            levelOrderT(child, level+1, ans);
        }
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/429.md" >}}
- by gpt
        
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

