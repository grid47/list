
+++
authors = ["grid47"]
title = "Leetcode 2566: Maximum Difference by Remapping a Digit"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2566: Maximum Difference by Remapping a Digit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "mmTJskqxquI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMaxDifference(int num) {
        int min_v = num, max_v = num;
        for (int i = 0; i < 10; ++i) {
            int lo = 0, hi = 0, mul = 1;
            for (int n = num; n; n /= 10) {
                bool replace = n % 10 == i;
                lo += (replace ? 0 : n % 10) * mul;
                hi += (replace ? 9 : n % 10) * mul;
                mul *= 10;
            }
            min_v = min(min_v, lo);
            max_v = max(max_v, hi);
        }
        return max_v - min_v;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2566.md" >}}
---
{{< youtube mmTJskqxquI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2567: Minimum Score by Changing Two Elements](https://grid47.xyz/leetcode/solution-2567-minimum-score-by-changing-two-elements/) |
| --- |
