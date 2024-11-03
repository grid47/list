
+++
authors = ["Crafted by Me"]
title = "Leetcode 589: N-ary Tree Preorder Traversal"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 589: N-ary Tree Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Tree","Depth-First Search"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/589.md" >}}
---
{{< youtube 2MjVm-hwyxs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #590: N-ary Tree Postorder Traversal](https://grid47.xyz/posts/leetcode_590) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

