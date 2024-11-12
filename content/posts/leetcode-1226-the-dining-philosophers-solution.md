
+++
authors = ["grid47"]
title = "Leetcode 1226: The Dining Philosophers"
date = "2024-07-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1226: The Dining Philosophers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Concurrency"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1227: Airplane Seat Assignment Probability](https://grid47.xyz/posts/leetcode-1227-airplane-seat-assignment-probability-solution/) |
| --- |
