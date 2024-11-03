
+++
authors = ["Crafted by Me"]
title = "Leetcode 50: Pow(x, n)"
date = "2024-09-13"
description = "In-depth solution and explanation for Leetcode 50: Pow(x, n) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube g9YQyYi4IQQ >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

