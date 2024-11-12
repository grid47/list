
+++
authors = ["grid47"]
title = "Leetcode 2275: Largest Combination With Bitwise AND Greater Than Zero"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2275: Largest Combination With Bitwise AND Greater Than Zero in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Bit Manipulation","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int largestCombination(vector<int>& candidates) {
        int res = 0, cur = 0;
        for(int  i = 1; i < 10000000; i <<= 1) {
            cur = 0;
            for(int a: candidates)
                if(a & i)
                cur++;
            res = max(res, cur);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2275.md" >}}
---
{{< youtube OyyfVofM_MM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2278: Percentage of Letter in String](https://grid47.xyz/posts/leetcode-2278-percentage-of-letter-in-string-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
