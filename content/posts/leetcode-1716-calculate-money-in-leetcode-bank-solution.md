
+++
authors = ["grid47"]
title = "Leetcode 1716: Calculate Money in Leetcode Bank"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1716: Calculate Money in Leetcode Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/)

---
**Code:**

{{< highlight cpp >}}

class Solution {
public:
    int totalMoney(int n) {
        int s = 1, ans = 0;
        while (n > 0) {
            for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
            s++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1716.md" >}}
---
{{< youtube tKK7gvPCQfs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1717: Maximum Score From Removing Substrings](https://grid47.xyz/posts/leetcode-1717-maximum-score-from-removing-substrings-solution/) |
| --- |
