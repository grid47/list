
+++
authors = ["grid47"]
title = "Leetcode 896: Monotonic Array"
date = "2024-08-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 896: Monotonic Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "stkYclqstaA"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/monotonic-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isMonotonic(vector<int> A) {
        bool inc = true, dec = true;
        for (int i = 1; i < A.size(); ++i)
            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
        return inc || dec;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/896.md" >}}
---
{{< youtube stkYclqstaA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #898: Bitwise ORs of Subarrays](https://grid47.xyz/leetcode/solution-898-bitwise-ors-of-subarrays/) |
| --- |
