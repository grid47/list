
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 133: Clone Graph"
date = "2024-06-19"
description = "Solution to Leetcode 133"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/clone-graph/description/)

---

**Code:**

{{< highlight cpp >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        Node * ans;
        ans = copy(node);
        return ans;
    }
    
    Node* copy(Node* node) {
        if(mp.count(node->val)) return mp[node->val];
        Node* ans = new Node(node->val);
        mp[node->val] = ans;
        for(auto it: node->neighbors) {
            Node* n = copy(it);
            ans->neighbors.push_back(n);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/133.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
