
+++
authors = ["Yasir"]
title = "Leetcode 633: Sum of Square Numbers"
date = "2023-02-03"
description = "Solution to Leetcode 633"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-square-numbers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = sqrt(c);
        while(left <= right) {
            long res = left * left + right * right;
            if(res < c)
            left++;
            else if(res > c) 
            right--;
            else return true;
        }
        return false;
    }
};
{{< /highlight >}}

