
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1680: Concatenation of Consecutive Binary Numbers"
date = "2020-03-24"
description = "Solution to Leetcode 1680"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int concatenatedBinary(int n) {
        
        int mod = (int) 1e9 + 7;
        
        long ans = 0;
        int len = 0;
        for(int i = 1; i <= n; i++) {
            if(__builtin_popcount(i) == 1) len++;
            
            ans = ((ans << len) % mod + i % mod) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

