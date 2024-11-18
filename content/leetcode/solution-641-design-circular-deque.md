
+++
authors = ["grid47"]
title = "Leetcode 641: Design Circular Deque"
date = "2024-09-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 641: Design Circular Deque in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/design-circular-deque/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/641.webp" 
    alt="A circular deque with elements being added and removed, each operation glowing softly as it occurs."
    caption="Solution to LeetCode 641: Design Circular Deque Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #645: Set Mismatch](https://grid47.xyz/leetcode/solution-645-set-mismatch/) |
| --- |
