
+++
authors = ["grid47"]
title = "Leetcode 2259: Remove Digit From Number to Maximize Result"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2259: Remove Digit From Number to Maximize Result in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDigit(string n, char digit) {
        for (int i = 0; i < n.size() - 1; ++i)
            if (n[i] == digit && n[i + 1] > digit)
                return n.substr(0, i) + n.substr(i + 1);
        int last_d = n.rfind(digit);
        return n.substr(0, last_d) + n.substr(last_d + 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2259.md" >}}
---
{{< youtube cinEIxOL0E8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2260: Minimum Consecutive Cards to Pick Up](https://grid47.xyz/posts/leetcode-2260-minimum-consecutive-cards-to-pick-up-solution/) |
| --- |
