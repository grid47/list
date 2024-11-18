
+++
authors = ["grid47"]
title = "Leetcode 232: Implement Queue using Stacks"
date = "2024-10-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 232: Implement Queue using Stacks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Queue"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "eanwa3ht3YQ"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/232.webp"
+++



[`Problem Link`](https://leetcode.com/problems/implement-queue-using-stacks/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/232.webp" 
    alt="A series of stacks transforming into a queue, with elements gently flowing between them."
    caption="Solution to LeetCode 232: Implement Queue using Stacks Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
        
    }
    
    int peek() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/232.md" >}}
---
{{< youtube eanwa3ht3YQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #235: Lowest Common Ancestor of a Binary Search Tree](https://grid47.xyz/leetcode/solution-235-lowest-common-ancestor-of-a-binary-search-tree/) |
| --- |
