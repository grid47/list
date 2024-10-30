
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1195: Fizz Buzz Multithreaded"
date = "2021-07-24"
description = "Solution to Leetcode 1195"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fizz-buzz-multithreaded/description/)

---
{{< youtube nan >}}
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

