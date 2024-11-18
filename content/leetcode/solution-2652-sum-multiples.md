
+++
authors = ["grid47"]
title = "Leetcode 2652: Sum Multiples"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2652: Sum Multiples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "A1BNPgQSHz8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/sum-multiples/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfMultiples(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            if((i % 3 == 0) || (i% 5 == 0) || (i % 7 == 0))
                sum += i;
        return sum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2652.md" >}}
---
{{< youtube A1BNPgQSHz8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2653: Sliding Subarray Beauty](https://grid47.xyz/leetcode/solution-2653-sliding-subarray-beauty/) |
| --- |
