
+++
authors = ["Crafted by Me"]
title = "Leetcode 155: Min Stack"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 155: Min Stack in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-stack/description/)

---

**Code:**

{{< highlight cpp >}}
class Node {
    public:
    int val;
    int mn;
    Node* node;
    Node(int val, int mn, Node* node) {
        this->val = val;
        this->mn = mn;
        this->node = node;
    }
};

class MinStack {
public:
    Node* head;
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        if(!head) {
            head = new Node(val, val, NULL);
        } else {
            head = new Node(val, min(head->mn, val), head);
        }
    }
    
    void pop() {
        head = head->node;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/155.md" >}}
---
{{< youtube RfMroCV17-4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #156: Binary Tree Upside Down](https://grid47.xyz/posts/leetcode_156) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
