
+++
authors = ["Yasir"]
title = "Leetcode 343: Integer Break"
date = "2023-11-20"
description = "Solution to Leetcode 343"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/integer-break/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int product = 1;
        while(n > 4) {
            product *= 3;
            n -= 3;
        }
        product *= n;
        return product;
    }
};
{{< /highlight >}}

