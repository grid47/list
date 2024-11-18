
+++
authors = ["grid47"]
title = "Leetcode 2274: Maximum Consecutive Floors Without Special Floors"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2274: Maximum Consecutive Floors Without Special Floors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "ZQ6iiXxEhRY"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& spec) {

        sort(spec.begin(), spec.end());
        int prv = bottom - 1, n = spec.size();

        int res = 0;
        for(int cur : spec) {
            res = max(res, cur - prv - 1);
            prv = cur > prv ? cur : prv;
        }
        res = max(res, top - prv);

        return res;
    }
};

// bottom - top
// spec
// 
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2274.md" >}}
---
{{< youtube ZQ6iiXxEhRY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2275: Largest Combination With Bitwise AND Greater Than Zero](https://grid47.xyz/leetcode/solution-2275-largest-combination-with-bitwise-and-greater-than-zero/) |
| --- |
