
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 868: Binary Gap"
date = "2022-06-15"
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

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/868.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

