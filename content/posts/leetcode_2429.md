
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2429: Minimize XOR"
date = "2018-03-07"
description = "Solution to Leetcode 2429"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-xor/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n = __builtin_popcount(num2);
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            if(((num1 >> i) & 1) == 1) {
                if(n > 0) {
                    res |= (1 << i);
                    n--;
                    if(n == 0) return res;
                }
            }
        }
        int i = 0;
        while(n > 0) {
            if(((res >> i) & 1) == 0) {
                res |= (1 << i);
                n--;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
