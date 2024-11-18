
+++
authors = ["grid47"]
title = "Leetcode 1238: Circular Permutation in Binary Representation"
date = "2024-07-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1238: Circular Permutation in Binary Representation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/circular-permutation-in-binary-representation/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res;
        for(int i = 0; i < 1 << n; i++)
            res.push_back(start ^ i ^ i >> 1);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1238.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1239: Maximum Length of a Concatenated String with Unique Characters](https://grid47.xyz/leetcode/solution-1239-maximum-length-of-a-concatenated-string-with-unique-characters/) |
| --- |
