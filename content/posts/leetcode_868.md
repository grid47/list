
+++
authors = ["Yasir"]
title = "Leetcode 868: Binary Gap"
date = "2022-06-14"
description = "Solution to Leetcode 868"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-gap/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        for (int d = -32; n; n >>=1, d++)
            if (n % 2) 
            { 
                res = max(res, d);
                d   = 0;
            }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

