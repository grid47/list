
+++
authors = ["grid47"]
title = "Leetcode 2873: Maximum Value of an Ordered Triplet I"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2873: Maximum Value of an Ordered Triplet I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, mxa = 0, mxab = 0;
        for(long a: nums) {
            res = max(res, mxab * a);
            mxab = max(mxab, mxa - a);
            mxa = max(mxa, a);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2873.md" >}}
---
{{< youtube U0abRgobTKg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2874: Maximum Value of an Ordered Triplet II](https://grid47.xyz/leetcode/solution-2874-maximum-value-of-an-ordered-triplet-ii/) |
| --- |
