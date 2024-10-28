
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 589: N-ary Tree Preorder Traversal"
date = "2023-03-20"
description = "Solution to Leetcode 589"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)

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
    vector<int> ans;
    void pre(Node* root) {
        if(root == NULL) return;
        ans.push_back(root->val);
        for(auto x: root->children)
            pre(x);
    }
    vector<int> preorder(Node* root) {
        pre(root);
        
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

