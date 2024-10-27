
+++
authors = ["Yasir"]
title = "Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors"
date = "2017-12-17"
description = "Solution to Leetcode 2507"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    int getFactSum(int n) {
        int div = 2, sum = 0;
        while(n > 1) {
            if(n % div == 0) {
                sum += div;
                n /= div;
            } else div++;
        }
        return sum;
    }
    
    int smallestValue(int n) {
        
        while(1) {
            int sum = getFactSum(n);
            if(sum == n) break;
            n = sum;
        }
        return n;
    }
};
{{< /highlight >}}

