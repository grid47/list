
+++
authors = ["Crafted by Me"]
title = "Leetcode 1115: Print FooBar Alternately"
date = "2020-10-13"
description = "Solution to Leetcode 1115"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/print-foobar-alternately/description/)

---

**Code:**

{{< highlight cpp >}}
class FooBar {
private:
    int n;
    mutex mtx1, mtx2;
public:
    FooBar(int n) {
        mtx2.lock();
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            mtx1.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            mtx2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            mtx2.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            mtx1.unlock();
        }
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

