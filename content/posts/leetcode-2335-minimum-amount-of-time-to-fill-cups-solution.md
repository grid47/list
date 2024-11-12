
+++
authors = ["grid47"]
title = "Leetcode 2335: Minimum Amount of Time to Fill Cups"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2335: Minimum Amount of Time to Fill Cups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int fillCups(vector<int>& A) {
        int mx = 0, sum = 0;
        for(int& a: A) {
            mx = max(a, mx);
            sum += a;
        }
        return max(mx, (sum + 1) / 2);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2335.md" >}}
---
{{< youtube jcfxf8gjVbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2336: Smallest Number in Infinite Set](https://grid47.xyz/posts/leetcode-2336-smallest-number-in-infinite-set-solution/) |
| --- |
