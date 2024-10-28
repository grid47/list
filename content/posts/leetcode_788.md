
+++
authors = ["Yasir"]
title = "Leetcode 788: Rotated Digits"
date = "2022-09-02"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

