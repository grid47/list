
+++
authors = ["grid47"]
title = "Leetcode 2549: Count Distinct Numbers on Board"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2549: Count Distinct Numbers on Board in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "oZFY64vwfXI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-distinct-numbers-on-board/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctIntegers(int n) {
        if(n == 1 || n == 2) return 1;
        return n - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2549.md" >}}
---
{{< youtube oZFY64vwfXI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2550: Count Collisions of Monkeys on a Polygon](https://grid47.xyz/leetcode/solution-2550-count-collisions-of-monkeys-on-a-polygon/) |
| --- |
