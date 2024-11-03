
+++
authors = ["Crafted by Me"]
title = "Leetcode 1114: Print in Order"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1114: Print in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/print-in-order/description/)

---

**Code:**

{{< highlight cpp >}}
class Foo {
    int curVal;
    std::mutex mtx;
public:
    Foo() {
        curVal = 1;
    }

    void first(function<void()> printFirst) {
        mtx.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        curVal++;
        mtx.unlock();
    }

    void second(function<void()> printSecond) {
        mtx.lock();
        while(curVal != 2)
        {
            mtx.unlock();
            mtx.lock();
        }
        mtx.unlock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        curVal++ ;       
    }

    void third(function<void()> printThird) {
        mtx.lock();
        while(curVal != 3)
        {
            mtx.unlock();
            mtx.lock();
        }
        mtx.unlock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        curVal++;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1114.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1115: Print FooBar Alternately](https://grid47.xyz/posts/leetcode_1115) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

