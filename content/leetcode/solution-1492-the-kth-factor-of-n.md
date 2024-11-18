
+++
authors = ["grid47"]
title = "Leetcode 1492: The kth Factor of n"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1492: The kth Factor of n in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "eD7-AQ2nUsI"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/the-kth-factor-of-n/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) k--;
            if(k == 0) return i;
        }
        return -1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1492.md" >}}
---
{{< youtube eD7-AQ2nUsI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1493: Longest Subarray of 1's After Deleting One Element](https://grid47.xyz/leetcode/solution-1493-longest-subarray-of-1s-after-deleting-one-element/) |
| --- |
