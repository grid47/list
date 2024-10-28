
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1137: N-th Tribonacci Number"
date = "2021-09-18"
description = "Solution to Leetcode 1137"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-th-tribonacci-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        int n0 = 0, n1 = 1, n2 = 1, tmp;
        
        for(int i = 3; i < n + 1; i++) {
            tmp = n2 + n1 + n0;
            n0  = n1;
            n1  = n2;
            n2  = tmp;
        }
        
        return n2;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

