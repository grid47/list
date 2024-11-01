
+++
authors = ["Crafted by Me"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-09-13"
description = "Solution to Leetcode 50"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/powx-n/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    double myPow(double x, int n) {
        if(n== 0) return 1;
        if(n < 0) return 1/x * myPow(1/x, -(n + 1));
        
        return (n % 2) ? x * myPow(x * x, n / 2) : myPow(x * x, n/ 2);
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/50.md" >}}
- by gpt
        
---
{{< youtube g9YQyYi4IQQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

