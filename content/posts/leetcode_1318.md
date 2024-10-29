
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1318: Minimum Flips to Make a OR b Equal to c"
date = "2021-03-22"
description = "Solution to Leetcode 1318"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int bit(int n, int i) {
        return (n >> i) & 1;
    }
    
    int minFlips(int a, int b, int c) {
        // (a|b) has zero and c has 1 required change is one
        // (a|b) has one and c has zero required change is one(if one of them have 1) or two (if both have one)
        
        /*
            0   0   1       1
            0   1   0       1
            1   0   0       1
            1   1   0       2
        */
        int cnt = 0;
        for(int i = 0; i < 31; i++) {
            if((!bit(a, i) && !bit(b, i) && bit(c, i)) ||
               (!bit(a, i) && bit(b, i) && !bit(c, i)) ||
               (bit(a, i) && !bit(b, i) && !bit(c, i)) ) {
                cnt++;
            } else if((bit(a, i) && bit(b, i) && !bit(c, i))) {
                cnt += 2;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

