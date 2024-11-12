
+++
authors = ["grid47"]
title = "Leetcode 2871: Split Array Into Maximum Number of Subarrays"
date = "2024-01-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2871: Split Array Into Maximum Number of Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res = 0, cur = 0;
        for (int n : nums) {
            cur = cur == 0 ? n : cur & n;
            res += cur == 0;
        }
        return max(1, res);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2871.md" >}}
---
{{< youtube xgzsBxfu8Ew >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2873: Maximum Value of an Ordered Triplet I](https://grid47.xyz/posts/leetcode-2873-maximum-value-of-an-ordered-triplet-i-solution/) |
| --- |
