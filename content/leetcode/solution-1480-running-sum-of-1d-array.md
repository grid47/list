
+++
authors = ["grid47"]
title = "Leetcode 1480: Running Sum of 1d Array"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1480: Running Sum of 1d Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/running-sum-of-1d-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        return nums;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1480.md" >}}
---
{{< youtube qNbwIHhMOr8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1481: Least Number of Unique Integers after K Removals](https://grid47.xyz/leetcode/solution-1481-least-number-of-unique-integers-after-k-removals/) |
| --- |
