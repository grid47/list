
+++
authors = ["Yasir"]
title = "Leetcode 201: Bitwise AND of Numbers Range"
date = "2024-04-09"
description = "Solution to Leetcode 201"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/bitwise-and-of-numbers-range/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    int shift = 0;
    
    while(right != left)
    {
        right >>= 1 ;
        left  >>= 1;
        shift++;
    }
    
    return right << shift;
    }
};
{{< /highlight >}}

