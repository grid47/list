
+++
authors = ["grid47"]
title = "Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit"
date = "2024-06-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1438: Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sliding Window","Heap (Priority Queue)","Ordered Set","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);
            while(!ms.empty() && *ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[j++]));
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1438.md" >}}
---
{{< youtube V-ecDfY5xEw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1441: Build an Array With Stack Operations](https://grid47.xyz/posts/leetcode-1441-build-an-array-with-stack-operations-solution/) |
| --- |
