
+++
authors = ["Crafted by Me"]
title = "Leetcode 1195: Fizz Buzz Multithreaded"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1195: Fizz Buzz Multithreaded in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fizz-buzz-multithreaded/description/)

---

**Code:**

{{< highlight cpp >}}
class FizzBuzz {
private:
    int n, i;
    mutex f, b, fz, num;
public:
    FizzBuzz(int n) {
        f.lock();
        b.lock();
        fz.lock();
        i = 1;
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(i <= n) {
            f.lock();
            if(i <= n)            
            printFizz();
            i++;            
            if(i % 3== 0  && i % 5== 0 ) {
                fz.unlock();
            } else if(i % 3 == 0) {
                f.unlock();
            } else if(i % 5 == 0) {
                b.unlock();
            } else if(i <= n) {
                num.unlock();
            } else {
                fz.unlock();
                f.unlock();
                b.unlock();
                num.unlock();
            }

        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(i <= n) {
            b.lock();
            if(i <= n)            
            printBuzz();
            i++;
            if(i % 3== 0  && i % 5== 0 ) {
                fz.unlock();
            } else if(i % 3 == 0) {
                f.unlock();
            } else if(i % 5 == 0) {
                b.unlock();
            } else if(i <= n) {
                num.unlock();
            } else {
                fz.unlock();
                f.unlock();
                b.unlock();
                num.unlock();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i <= n) {
            fz.lock();
            if(i <= n)
            printFizzBuzz();
            i++;
            if(i % 3 == 0 && i % 5== 0 ) {
                fz.unlock();
            } else if(i % 3 == 0) {
                f.unlock();
            } else if(i % 5 == 0) {
                b.unlock();
            } else if(i <= n) {
                num.unlock();
            } else {
                fz.unlock();
                f.unlock();
                b.unlock();
                num.unlock();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(i <= n) {
            num.lock();
            if(i <= n)
            printNumber(i);
            i++;
            if(i % 3 == 0 && i % 5== 0 ) {
                fz.unlock();
            } else if(i % 3 == 0) {
                f.unlock();
            } else if(i % 5 == 0) {
                b.unlock();
            } else if(i <= n) {
                num.unlock();
            } else {
                fz.unlock();
                f.unlock();
                b.unlock();
                num.unlock();
            }
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1195.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1196: How Many Apples Can You Put into the Basket](https://grid47.xyz/posts/leetcode_1196) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

