
+++
authors = ["grid47"]
title = "Leetcode 1670: Design Front Middle Back Queue"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1670: Design Front Middle Back Queue in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Design","Queue","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HSOiUhfXUTg"
youtube_upload_date="2020-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/HSOiUhfXUTg/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/design-front-middle-back-queue/description/)

---
**Code:**

{{< highlight cpp >}}
class FrontMiddleBackQueue {
    deque<int> a, b;
    
    void a2b() {
        if (a.size() <= b.size()) return;
        b.push_front(a.back());
        a.pop_back();
    }
    /* keep operations around front of b and back of a */
    void b2a() {
        if (b.size() <= a.size() + 1) return;
        a.push_back(b.front());
        b.pop_front();
    }
    
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        a.push_front(val);
        a2b();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        b2a();
    }
    
    int popFront() {
        if(a.empty() && b.empty()) return -1;
        int ans;
        if(a.empty()) {
            ans = b.front();
            b.pop_front();
        } else {
            ans = a.front();
            a.pop_front();
            b2a();          
        }
        return ans;
    }
    
    int popMiddle() {
        if(a.empty() && b.empty()) return -1;
        int ans;
        if(a.size() == b.size()) {
            ans = a.back();
            a.pop_back();
        } else {
            ans = b.front();
            b.pop_front();      
        }
        return ans;        
    }
    
    int popBack() {
        if(a.empty() && b.empty()) return -1;
        int ans = b.back();
        b.pop_back();
        a2b();
        return ans;       
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1670.md" >}}
---
{{< youtube HSOiUhfXUTg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1672: Richest Customer Wealth](https://grid47.xyz/leetcode/solution-1672-richest-customer-wealth/) |
| --- |
