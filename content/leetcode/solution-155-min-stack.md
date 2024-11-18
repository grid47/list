
+++
authors = ["grid47"]
title = "Leetcode 155: Min Stack"
date = "2024-10-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 155: Min Stack in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/min-stack/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/155.webp" 
    alt="A stack where each layer gently illuminates, showing the minimum value glowing at the bottom."
    caption="Solution to LeetCode 155: Min Stack Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #162: Find Peak Element](https://grid47.xyz/leetcode/solution-162-find-peak-element/) |
| --- |
