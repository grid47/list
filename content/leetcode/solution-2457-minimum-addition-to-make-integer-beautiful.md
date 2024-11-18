
+++
authors = ["grid47"]
title = "Leetcode 2457: Minimum Addition to Make Integer Beautiful"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2457: Minimum Addition to Make Integer Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int sum(long long n) {
        int res = 0;
        while(n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long n0 = n, base = 1;
        while(sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - n0;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2457.md" >}}
---
{{< youtube NoGK4582ey8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2460: Apply Operations to an Array](https://grid47.xyz/leetcode/solution-2460-apply-operations-to-an-array/) |
| --- |
