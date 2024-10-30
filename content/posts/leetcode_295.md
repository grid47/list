
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 295: Find Median from Data Stream"
date = "2024-01-10"
description = "Solution to Leetcode 295"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-median-from-data-stream/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class MedianFinder {
public:
    priority_queue<long> sm;
    priority_queue<long, vector<long>, greater<long>> lg;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        sm.push((long) num);
        lg.push((long) sm.top());
        sm.pop();
        if(sm.size() < lg.size()) {
            // cout << lg.top();
            sm.push(lg.top());
            lg.pop();
        }
    }
    
    double findMedian() {       
        return lg.size() < sm.size()? sm.top(): (double)(lg.top() + sm.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/295.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

