
+++
authors = ["grid47"]
title = "Leetcode 1356: Sort Integers by The Number of 1 Bits"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1356: Sort Integers by The Number of 1 Bits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation","Sorting","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/)

---
**Code:**

{{< highlight cpp >}}
// class cmp {
//     public:
//     bool operator() (int a, int b) {
//         int x = __builtin_popcount(a);
//         int y = __builtin_popcount(b);
//         if(x == y) return a < b;
//         return x < y;
//     }
// };

bool cmp(int a, int b) {
        int x = __builtin_popcount(a);
        int y = __builtin_popcount(b);
        if(x == y) return a < b;
        return x < y;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), cmp);

        return arr;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1356.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1357: Apply Discount Every n Orders](https://grid47.xyz/leetcode/solution-1357-apply-discount-every-n-orders/) |
| --- |
