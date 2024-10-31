
+++
authors = ["Crafted by Me"]
title = "Leetcode 2549: Count Distinct Numbers on Board"
date = "2017-11-09"
description = "Solution to Leetcode 2549"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-distinct-numbers-on-board/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctIntegers(int n) {
        if(n == 1 || n == 2) return 1;
        return n - 1;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

