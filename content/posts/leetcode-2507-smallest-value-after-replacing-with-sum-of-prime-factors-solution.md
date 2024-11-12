
+++
authors = ["grid47"]
title = "Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors"
date = "2024-03-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2507: Smallest Value After Replacing With Sum of Prime Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2507.md" >}}
---
{{< youtube Z11zwNKd89I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2511: Maximum Enemy Forts That Can Be Captured](https://grid47.xyz/posts/leetcode-2511-maximum-enemy-forts-that-can-be-captured-solution/) |
| --- |
