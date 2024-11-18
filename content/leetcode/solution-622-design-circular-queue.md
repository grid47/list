
+++
authors = ["grid47"]
title = "Leetcode 622: Design Circular Queue"
date = "2024-09-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 622: Design Circular Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/622.webp"
youtube = "aBbsfn863oA"
youtube_upload_date="2022-02-19"
youtube_thumbnail="https://i.ytimg.com/vi/aBbsfn863oA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/design-circular-queue/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/622.webp" 
    alt="A circular queue with elements being added and removed, each action softly glowing as the queue operates."
    caption="Solution to LeetCode 622: Design Circular Queue Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #623: Add One Row to Tree](https://grid47.xyz/leetcode/solution-623-add-one-row-to-tree/) |
| --- |
