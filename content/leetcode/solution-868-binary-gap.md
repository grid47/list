
+++
authors = ["grid47"]
title = "Leetcode 868: Binary Gap"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 868: Binary Gap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "I5pfHLmrBrA"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/binary-gap/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int binaryGap(int n) {
        int res = 0;
        for (int d = -32; n; n >>=1, d++)
            if (n % 2) 
            { 
                res = max(res, d);
                d   = 0;
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/868.md" >}}
---
{{< youtube I5pfHLmrBrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #869: Reordered Power of 2](https://grid47.xyz/leetcode/solution-869-reordered-power-of-2/) |
| --- |
