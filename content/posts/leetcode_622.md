
+++
authors = ["Crafted by Me"]
title = "Leetcode 622: Design Circular Queue"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 622: Design Circular Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Array","Linked List","Design","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-circular-queue/description/)

---

**Code:**

{{< highlight cpp >}}
class MyCircularQueue {
    vector<int> q;
    int frd, bck;
    int sz, cnt;
public:
    MyCircularQueue(int k): sz(k), frd(0), bck(-1), q(k, 0), cnt(0) {
        
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;        
        bck = (bck + 1) % sz;
        q[bck] = value;
        
        cnt++;
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;        

        frd = (frd +1) %sz;        
        cnt--;
        
        return true;        
    }
    
    int Front() {
        if(isEmpty()) return -1;
        
        return q[frd];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        
        return q[bck];        
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/622.md" >}}
---
{{< youtube aBbsfn863oA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #623: Add One Row to Tree](https://grid47.xyz/posts/leetcode_623) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

