
+++
authors = ["grid47"]
title = "Leetcode 2395: Find Subarrays With Equal Sum"
date = "2024-03-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2395: Find Subarrays With Equal Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-subarrays-with-equal-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 1; i < nums.size(); ++i)
        if(!s.insert(nums[i - 1] + nums[i]).second)
            return true;
    return false;
  }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2395.md" >}}
---
{{< youtube 1v-XTlRvUvU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2396: Strictly Palindromic Number](https://grid47.xyz/leetcode/solution-2396-strictly-palindromic-number/) |
| --- |
