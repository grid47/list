
+++
authors = ["grid47"]
title = "Leetcode 2481: Minimum Cuts to Divide a Circle"
date = "2024-03-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2481: Minimum Cuts to Divide a Circle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        return n % 2 ? n : n / 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2481.md" >}}
---
{{< youtube l5akOAKERoY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2482: Difference Between Ones and Zeros in Row and Column](https://grid47.xyz/posts/leetcode-2482-difference-between-ones-and-zeros-in-row-and-column-solution/) |
| --- |
