
+++
authors = ["grid47"]
title = "Leetcode 1114: Print in Order"
date = "2024-07-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1114: Print in Order in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1115: Print FooBar Alternately](https://grid47.xyz/leetcode/solution-1115-print-foobar-alternately/) |
| --- |
