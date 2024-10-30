
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1492: The kth Factor of n"
date = "2020-09-30"
description = "Solution to Leetcode 1492"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/the-kth-factor-of-n/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) k--;
            if(k == 0) return i;
        }
        return -1;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

