
+++
authors = ["Crafted by Me"]
title = "Leetcode 788: Rotated Digits"
date = "2021-09-05"
description = "Solution to Leetcode 788"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rotated-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rotatedDigits(int n) {
        int f[] = {1,1,2,0,0,2,2,0,1,2};
        int res = 0;
        for(int i = 0; i <= n; i++) {
            int p = i;
            int s = 1;
            while(p) {
                s *= f[p%10];
                p /= 10;
            }
            if (s >= 2) res +=1;
        }        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/788.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

