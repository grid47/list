
+++
authors = ["grid47"]
title = "Leetcode 1195: Fizz Buzz Multithreaded"
date = "2024-07-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1195: Fizz Buzz Multithreaded in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1201: Ugly Number III](https://grid47.xyz/leetcode/solution-1201-ugly-number-iii/) |
| --- |
