
+++
authors = ["grid47"]
title = "Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2535: Difference Between Element Sum and Digit Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wg-szN5zvr4"
youtube_upload_date="2023-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/wg-szN5zvr4/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int dsum(int v) {
    return v == 0 ? 0 : v % 10 + dsum(v / 10);
}
int differenceOfSum(vector<int>& n) {
    return abs(accumulate(begin(n), end(n), 0) - 
        accumulate(begin(n), end(n), 0, [&](int s, int v){ return s + dsum(v); }));
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2535.md" >}}
---
{{< youtube wg-szN5zvr4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2536: Increment Submatrices by One](https://grid47.xyz/leetcode/solution-2536-increment-submatrices-by-one/) |
| --- |
