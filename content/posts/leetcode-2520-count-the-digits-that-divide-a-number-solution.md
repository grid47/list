
+++
authors = ["grid47"]
title = "Leetcode 2520: Count the Digits That Divide a Number"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2520: Count the Digits That Divide a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        for (int n = num; n > 0; n /= 10)
            res += num % (n % 10) == 0;
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2520.md" >}}
---
{{< youtube 7SHHsS5kPJ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2521: Distinct Prime Factors of Product of Array](https://grid47.xyz/posts/leetcode-2521-distinct-prime-factors-of-product-of-array-solution/) |
| --- |
