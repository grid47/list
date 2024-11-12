
+++
authors = ["grid47"]
title = "Leetcode 1837: Sum of Digits in Base K"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1837: Sum of Digits in Base K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-digits-in-base-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumBase(int n, int k) {
        int res=0;
        while(n!=0)
        {
            res+=(n%k);
            n/=k;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1837.md" >}}
---
{{< youtube tPbypmspAi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1838: Frequency of the Most Frequent Element](https://grid47.xyz/posts/leetcode-1838-frequency-of-the-most-frequent-element-solution/) |
| --- |
