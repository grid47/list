
+++
authors = ["Yasir"]
title = "Leetcode 2582: Pass the Pillow"
date = "2017-10-04"
description = "Solution to Leetcode 2582"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pass-the-pillow/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
        int passThePillow(int n, int time) {
            return n - abs(n - 1 - time % (n * 2 - 2));
        }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

