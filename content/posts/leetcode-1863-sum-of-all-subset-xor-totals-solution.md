
+++
authors = ["grid47"]
title = "Leetcode 1863: Sum of All Subset XOR Totals"
date = "2024-05-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1863: Sum of All Subset XOR Totals in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Backtracking","Bit Manipulation","Combinatorics","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        for (auto i = 1; i < (1 << nums.size()); ++i) {
            int total = 0;
            for (auto j = 0; j < nums.size(); ++j)
                if (i & (1 << j))
                    total ^= nums[j];
            res += total;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1863.md" >}}
---
{{< youtube LI7YR-bwNYY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1865: Finding Pairs With a Certain Sum](https://grid47.xyz/posts/leetcode-1865-finding-pairs-with-a-certain-sum-solution/) |
| --- |
