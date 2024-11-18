
+++
authors = ["grid47"]
title = "Leetcode 3099: Harshad Number"
date = "2024-01-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3099: Harshad Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/harshad-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int tmp = x;
        while(tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        return x % sum == 0? sum : -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3099.md" >}}
---
{{< youtube QplrY0LW62M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3100: Water Bottles II](https://grid47.xyz/leetcode/solution-3100-water-bottles-ii/) |
| --- |
