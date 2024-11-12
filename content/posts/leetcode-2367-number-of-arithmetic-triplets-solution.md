
+++
authors = ["grid47"]
title = "Leetcode 2367: Number of Arithmetic Triplets"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2367: Number of Arithmetic Triplets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-arithmetic-triplets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
    int cnt[201] = {}, res = 0;
    for (auto n : nums) {
        if (n >= 2 * diff)
            res += cnt[n - diff] && cnt[n - 2 * diff];
        cnt[n] = true;
    }
    return res;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2367.md" >}}
---
{{< youtube WEyiBgwO4ZA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2368: Reachable Nodes With Restrictions](https://grid47.xyz/posts/leetcode-2368-reachable-nodes-with-restrictions-solution/) |
| --- |
