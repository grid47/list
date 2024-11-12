
+++
authors = ["grid47"]
title = "Leetcode 1014: Best Sightseeing Pair"
date = "2024-07-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1014: Best Sightseeing Pair in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/best-sightseeing-pair/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& val) {

        int res = 0, cur = 0;

        for(int x : val) {
            res = max(res, cur + x);
            cur = max(cur, x) - 1;
        }

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1014.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1015: Smallest Integer Divisible by K](https://grid47.xyz/posts/leetcode-1015-smallest-integer-divisible-by-k-solution/) |
| --- |
