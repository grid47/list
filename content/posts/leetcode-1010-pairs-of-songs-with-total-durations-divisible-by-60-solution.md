
+++
authors = ["grid47"]
title = "Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60"
date = "2024-07-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1010: Pairs of Songs With Total Durations Divisible by 60 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60, 0);
        int res = 0;
        for(int t: time) {
            res += c[(600 - t)%60];
            c[t%60] += 1;
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1010.md" >}}
---
{{< youtube gM5Wu42UTQk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1011: Capacity To Ship Packages Within D Days](https://grid47.xyz/posts/leetcode-1011-capacity-to-ship-packages-within-d-days-solution/) |
| --- |
