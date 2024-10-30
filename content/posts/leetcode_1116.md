
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1116: Print Zero Even Odd"
date = "2021-10-11"
description = "Solution to Leetcode 1116"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

