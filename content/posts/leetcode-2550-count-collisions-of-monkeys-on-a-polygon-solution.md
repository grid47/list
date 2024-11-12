
+++
authors = ["grid47"]
title = "Leetcode 2550: Count Collisions of Monkeys on a Polygon"
date = "2024-02-26"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2553: Separate the Digits in an Array](https://grid47.xyz/posts/leetcode-2553-separate-the-digits-in-an-array-solution/) |
| --- |
