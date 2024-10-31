
+++
authors = ["Crafted by Me"]
title = "Leetcode 622: Design Circular Queue"
date = "2023-02-18"
description = "Solution to Leetcode 622"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

