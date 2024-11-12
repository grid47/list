
+++
authors = ["grid47"]
title = "Leetcode 1137: N-th Tribonacci Number"
date = "2024-07-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1137: N-th Tribonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/n-th-tribonacci-number/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        
        int n0 = 0, n1 = 1, n2 = 1, tmp;
        
        for(int i = 3; i < n + 1; i++) {
            tmp = n2 + n1 + n0;
            n0  = n1;
            n1  = n2;
            n2  = tmp;
        }
        
        return n2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1137.md" >}}
---
{{< youtube 3lpNp5Ojvrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1138: Alphabet Board Path](https://grid47.xyz/posts/leetcode-1138-alphabet-board-path-solution/) |
| --- |
