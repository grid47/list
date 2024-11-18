
+++
authors = ["grid47"]
title = "Leetcode 2786: Visit Array Positions to Maximize Score"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2786: Visit Array Positions to Maximize Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long maxScore(vector<int>& n, int x) {
        long long eve = n[0] - (n[0] % 2 ? x : 0);
        long long odd = n[0] - (n[0] % 2 ? 0 : x);
        for (int i = 1; i < n.size(); ++i)
            if (n[i] % 2)   odd = n[i] + max(odd, eve - x);
            else            eve = n[i] + max(eve, odd - x);
        return max(eve, odd);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2786.md" >}}
---
{{< youtube JtogyeIxGWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2788: Split Strings by Separator](https://grid47.xyz/leetcode/solution-2788-split-strings-by-separator/) |
| --- |
