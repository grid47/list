
+++
authors = ["grid47"]
title = "Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2177: Find Three Consecutive Integers That Sum to a Given Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num %3 != 0) return ans;
        return {num / 3 - 1, num/ 3, num/3 + 1};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2177.md" >}}
---
{{< youtube DMBWjfh33wY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2178: Maximum Split of Positive Even Integers](https://grid47.xyz/posts/leetcode-2178-maximum-split-of-positive-even-integers-solution/) |
| --- |
