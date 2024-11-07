
+++
authors = ["Crafted by Me"]
title = "Leetcode 295: Find Median from Data Stream"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 295: Find Median from Data Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","Design","Sorting","Heap (Priority Queue)","Data Stream"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-median-from-data-stream/description/)

---

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
---
{{< youtube itmhHWaHupI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #297: Serialize and Deserialize Binary Tree](https://grid47.xyz/posts/leetcode_297) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
