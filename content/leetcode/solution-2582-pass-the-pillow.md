
+++
authors = ["grid47"]
title = "Leetcode 2582: Pass the Pillow"
date = "2024-02-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2582: Pass the Pillow in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pass-the-pillow/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
        int passThePillow(int n, int time) {
            return n - abs(n - 1 - time % (n * 2 - 2));
        }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2582.md" >}}
---
{{< youtube oVvmwsm2dKY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2583: Kth Largest Sum in a Binary Tree](https://grid47.xyz/leetcode/solution-2583-kth-largest-sum-in-a-binary-tree/) |
| --- |
