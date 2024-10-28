
+++
authors = ["Yasir"]
title = "Leetcode 338: Counting Bits"
date = "2023-11-26"
description = "Solution to Leetcode 338"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/counting-bits/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

