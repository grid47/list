
+++
authors = ["grid47"]
title = "Leetcode 2441: Largest Positive Integer That Exists With Its Negative"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2441: Largest Positive Integer That Exists With Its Negative in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "Ec0T3so3m2Y"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int findMaxK(vector<int>& nums) {
    int arr[2001] = {}, res = -1;
    for (int n : nums) {
        if (arr[-n + 1000])
            res = max(res, abs(n));
        ++arr[n + 1000];        
    }
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2441.md" >}}
---
{{< youtube Ec0T3so3m2Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2442: Count Number of Distinct Integers After Reverse Operations](https://grid47.xyz/leetcode/solution-2442-count-number-of-distinct-integers-after-reverse-operations/) |
| --- |
