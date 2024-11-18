
+++
authors = ["grid47"]
title = "Leetcode 2544: Alternating Digit Sum"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2544: Alternating Digit Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "IFRYDmhEWGw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/alternating-digit-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int sgn = 1;
        while(n) {
            sum += sgn * (n % 10);
            n /= 10;
            sgn *= -1;
        }
        return sgn == -1? sum : -sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2544.md" >}}
---
{{< youtube IFRYDmhEWGw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2545: Sort the Students by Their Kth Score](https://grid47.xyz/leetcode/solution-2545-sort-the-students-by-their-kth-score/) |
| --- |
