
+++
authors = ["grid47"]
title = "Leetcode 589: N-ary Tree Preorder Traversal"
date = "2024-09-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 589: N-ary Tree Preorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Tree","Depth-First Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/589.webp" 
    alt="An N-ary tree where each node is visited in preorder, with each visit softly glowing as the nodes are explored."
    caption="Solution to LeetCode 589: N-ary Tree Preorder Traversal Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #592: Fraction Addition and Subtraction](https://grid47.xyz/leetcode/solution-592-fraction-addition-and-subtraction/) |
| --- |
