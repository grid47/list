
+++
authors = ["Crafted by Me"]
title = "Leetcode 138: Copy List with Random Pointer"
date = "2023-06-17"
description = "Solution to Leetcode 138"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/copy-list-with-random-pointer/description/)

---

**Code:**

{{< highlight cpp >}}
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> mp;
    Node* copyRandomList(Node* head) {
        mp.clear();
        return copy(head);
        
    }
    
    Node* copy(Node* head) {
        if(!head) return head;
        if(mp.count(head)) return mp[head];
        
        Node* node = new Node(head->val);
        mp[head] = node;
        node->next = copy(head->next);
        node->random = copy(head->random);
        
        return node;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/138.md" >}}
---
{{< youtube 5Y2EiZST97Y >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

