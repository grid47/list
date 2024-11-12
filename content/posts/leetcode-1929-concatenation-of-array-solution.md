
+++
authors = ["grid47"]
title = "Leetcode 1929: Concatenation of Array"
date = "2024-04-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1929: Concatenation of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/concatenation-of-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1929.md" >}}
---
{{< youtube 68isPRHgcFQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1930: Unique Length-3 Palindromic Subsequences](https://grid47.xyz/posts/leetcode-1930-unique-length-3-palindromic-subsequences-solution/) |
| --- |
