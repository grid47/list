
+++
authors = ["grid47"]
title = "Leetcode 2427: Number of Common Factors"
date = "2024-03-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2427: Number of Common Factors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Enumeration","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QzFzbNvmRgs"
youtube_upload_date="2022-10-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QzFzbNvmRgs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/number-of-common-factors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int commonFactors(int a, int b) {
    int res = 1, hi = gcd(a, b);
    for (int n = 2; n <= hi; ++n)
        res += a % n == 0 && b % n == 0;
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2427.md" >}}
---
{{< youtube QzFzbNvmRgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2428: Maximum Sum of an Hourglass](https://grid47.xyz/leetcode/solution-2428-maximum-sum-of-an-hourglass/) |
| --- |