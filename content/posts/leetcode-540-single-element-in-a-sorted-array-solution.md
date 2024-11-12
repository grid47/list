
+++
authors = ["grid47"]
title = "Leetcode 540: Single Element in a Sorted Array"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 540: Single Element in a Sorted Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-element-in-a-sorted-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res =0;
        for(int num : nums)
        res ^= num;

        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/540.md" >}}
---
{{< youtube T4nRgIxka18 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #542: 01 Matrix](https://grid47.xyz/posts/leetcode-542-01-matrix-solution/) |
| --- |
