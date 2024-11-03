
+++
authors = ["Crafted by Me"]
title = "Leetcode 2550: Count Collisions of Monkeys on a Polygon"
date = "2017-11-09"
description = "In-depth solution and explanation for Leetcode 2550: Count Collisions of Monkeys on a Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    
    int power(int a, int n) {
        if(n == 0) return 1;
        long long res = power(a, n/2) % mod;

        long long y = (res * res) %mod;
        // cout << (int) y << " " ;
        if(n & 1) {
            y = (a * y) % mod;
            return y;            
        }
        return y % mod;
    }
    
    int monkeyMove(int n) {
        
        int res = power(2, n);
        
        return (res - 2)<0? mod - res:res-2 ;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2551: Put Marbles in Bags](grid47.xyz/leetcode_2551) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

