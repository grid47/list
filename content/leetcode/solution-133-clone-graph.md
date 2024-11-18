
+++
authors = ["grid47"]
title = "Leetcode 133: Clone Graph"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 133: Clone Graph in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Depth-First Search","Breadth-First Search","Graph"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "mQeF6bN8hMk"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/133.webp"
+++



[`Problem Link`](https://leetcode.com/problems/clone-graph/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/133.webp" 
    alt="A graph with nodes gently duplicating and glowing, forming an identical copy with soft edges."
    caption="Solution to LeetCode 133: Clone Graph Problem"
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
---
{{< youtube mQeF6bN8hMk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #134: Gas Station](https://grid47.xyz/leetcode/solution-134-gas-station/) |
| --- |
