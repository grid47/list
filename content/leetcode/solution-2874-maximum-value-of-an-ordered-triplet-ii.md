
+++
authors = ["grid47"]
title = "Leetcode 2874: Maximum Value of an Ordered Triplet II"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2874: Maximum Value of an Ordered Triplet II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "QBLw9bVFIDQ"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long res = 0, n = nums.size();
        long maxa = 0, maxab = 0;
        for(int a: nums) {
            res = max(res, 1L * maxab * a);
            maxab = max(maxab, (long) maxa - a);
            maxa = max(maxa, (long)a);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2874.md" >}}
---
{{< youtube QBLw9bVFIDQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2875: Minimum Size Subarray in Infinite Array](https://grid47.xyz/leetcode/solution-2875-minimum-size-subarray-in-infinite-array/) |
| --- |
