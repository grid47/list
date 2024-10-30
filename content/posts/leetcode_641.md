
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 641: Design Circular Deque"
date = "2023-01-29"
description = "Solution to Leetcode 641"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-circular-deque/description/)

---

**Code:**

{{< highlight cpp >}}
class MyCircularDeque {
    vector<int> buf;
    int frd, bck;
    int sz, cnt;
public:
    MyCircularDeque(int k) : sz(k), buf(k, 0), bck(0), frd(k - 1), cnt(0) {
        
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        
        buf[frd] = value;
        frd = (frd -1 + sz) % sz;
        
        ++cnt;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        
        buf[bck] = value;        
        bck = (bck + 1) % sz;
        
        ++cnt;
        return true;        
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        
        frd = (frd + 1) % sz;
        
        --cnt;
        return true;        
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        bck = (bck - 1 + sz) % sz;
        
        --cnt;
        return true;        
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        
        return buf[(frd + 1) % sz];
        
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        
        return buf[(bck - 1 + sz) % sz];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return  cnt == sz;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/641.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

