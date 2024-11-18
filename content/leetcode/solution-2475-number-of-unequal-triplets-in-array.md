
+++
authors = ["grid47"]
title = "Leetcode 2475: Number of Unequal Triplets in Array"
date = "2024-03-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2475: Number of Unequal Triplets in Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "AbSMJxiiJpk"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-unequal-triplets-in-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int unequalTriplets(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int n : nums)
        ++m[n];
    int res = 0, left = 0, right = nums.size();
    for (auto [n, cnt] : m) {
        right -= cnt;
        res += left * cnt * right;
        left += cnt;
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2475.md" >}}
---
{{< youtube AbSMJxiiJpk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2476: Closest Nodes Queries in a Binary Search Tree](https://grid47.xyz/leetcode/solution-2476-closest-nodes-queries-in-a-binary-search-tree/) |
| --- |
