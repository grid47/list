
+++
authors = ["Yasir"]
title = "Leetcode 7: Reverse Integer"
date = "2024-10-20"
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

{{< highlight html >}}
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

