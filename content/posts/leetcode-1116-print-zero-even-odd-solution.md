
+++
authors = ["grid47"]
title = "Leetcode 1116: Print Zero Even Odd"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1116: Print Zero Even Odd in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/print-zero-even-odd/description/)

---
**Code:**

{{< highlight cpp >}}
class ZeroEvenOdd {
private:
    int n;
    mutex mtx1, mtx2, mtx;
public:
    ZeroEvenOdd(int n) {
        mtx1.lock();
        mtx2.lock();
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        int t = 0;
        for(int j = 0; j < n; j++) {
            // cout << j << " ";
            mtx.lock();
            printNumber(0);
            if(t == 0) {
                t = 1;
                mtx1.unlock();         
            }
            else {
                t = 0;
                mtx2.unlock();            
            }            
        }
    }

    void even(function<void(int)> printNumber) {
        int i = 2;
        while(i <= n) {
            mtx2.lock();
            printNumber(i);
            mtx.unlock();
            i += 2;
        }
    }

    void odd(function<void(int)> printNumber) {
        int i = 1;
        while(i <= n) {
            mtx1.lock();
            printNumber(i);        
            mtx.unlock();
            i += 2;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1116.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1122: Relative Sort Array](https://grid47.xyz/posts/leetcode-1122-relative-sort-array-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
