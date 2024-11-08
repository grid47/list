
+++
authors = ["grid47"]
title = "Leetcode 2550: Count Collisions of Monkeys on a Polygon"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2550: Count Collisions of Monkeys on a Polygon in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Recursion"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2550.md" >}}
---
{{< youtube fwdV-VrFRiA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2551: Put Marbles in Bags](https://grid47.xyz/posts/leetcode_2551) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
