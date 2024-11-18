
+++
authors = ["grid47"]
title = "Leetcode 2869: Minimum Operations to Collect Elements"
date = "2024-01-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2869: Minimum Operations to Collect Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-collect-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt[51] = {}, i = nums.size() - 1;
        for (int found = 0; found < k; --i)
            if (nums[i] <= k)
                found += cnt[nums[i]]++ == 0;
        return nums.size() - i - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2869.md" >}}
---
{{< youtube ohl7rEwEI9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2870: Minimum Number of Operations to Make Array Empty](https://grid47.xyz/leetcode/solution-2870-minimum-number-of-operations-to-make-array-empty/) |
| --- |
