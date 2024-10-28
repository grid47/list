
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1114: Print in Order"
date = "2021-10-11"
description = "Solution to Leetcode 1114"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

