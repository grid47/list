
+++
authors = ["Crafted by Me"]
title = "Leetcode 1226: The Dining Philosophers"
date = "2021-06-25"
description = "Solution to Leetcode 1226"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-dining-philosophers/description/)

---

**Code:**

{{< highlight cpp >}}
class DiningPhilosophers {
public:
    mutex mtx[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        
        unique_lock<mutex> lck1(mtx[left], defer_lock);
        unique_lock<mutex> lck2(mtx[right], defer_lock);
        
        if(philosopher % 2) {
            lck1.lock();
            lck2.lock();
            pickLeftFork();
            pickRightFork();
        } else {
            lck2.lock();
            lck1.lock();
            pickLeftFork();
            pickRightFork();            
        }
        eat();
        putLeftFork();
        putRightFork();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1226.md" >}}
---
{{< youtube cb6-GZiSaMY >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

