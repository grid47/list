
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 7: Reverse Integer"
date = "2024-10-23"
description = "Solution to Leetcode 7"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-integer/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reverse(int x)
    {
        int rev=0, pop;
        while(x != 0)
        {
            pop  = x % 10;
            x   /= 10;

            if( (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) || 
                (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) )
                return 0;

            rev  = rev * 10 + pop;
        }
        return  rev;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/7.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
