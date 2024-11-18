
+++
authors = ["grid47"]
title = "Leetcode 2180: Count Integers With Even Digit Sum"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2180: Count Integers With Even Digit Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "McbkGprY2C4"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-integers-with-even-digit-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countEven(int num) {
        int temp = num, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2180.md" >}}
---
{{< youtube McbkGprY2C4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2181: Merge Nodes in Between Zeros](https://grid47.xyz/leetcode/solution-2181-merge-nodes-in-between-zeros/) |
| --- |
