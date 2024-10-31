
+++
authors = ["Crafted by Me"]
title = "Leetcode 155: Min Stack"
date = "2024-05-30"
description = "Solution to Leetcode 155"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-stack/description/)

---

{{< youtube RfMroCV17-4 >}}

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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

