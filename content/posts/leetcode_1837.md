
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1837: Sum of Digits in Base K"
date = "2019-10-19"
description = "Solution to Leetcode 1837"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-digits-in-base-k/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumBase(int n, int k) {
        int res=0;
        while(n!=0)
        {
            res+=(n%k);
            n/=k;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

