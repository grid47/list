
+++
authors = ["grid47"]
title = "Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2817: Minimum Absolute Difference Between Elements With Constraint in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-between-elements-with-constraint/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
    set<int> s;
    int res = INT_MAX;
    for (int i = x; i < nums.size() && res > 0; ++i) {
        s.insert(nums[i - x]);
        auto it = s.upper_bound(nums[i]);
        if (it != begin(s))
            res = min(res, nums[i] - *prev(it));
        if (it != end(s))
            res = min(res, *it - nums[i]);
    }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2817.md" >}}
---
{{< youtube iZkBnYIJ9Qc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2824: Count Pairs Whose Sum is Less than Target](https://grid47.xyz/posts/leetcode-2824-count-pairs-whose-sum-is-less-than-target-solution/) |
| --- |
