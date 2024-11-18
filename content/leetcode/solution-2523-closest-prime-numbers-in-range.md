
+++
authors = ["grid47"]
title = "Leetcode 2523: Closest Prime Numbers in Range"
date = "2024-02-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2523: Closest Prime Numbers in Range in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "HqSBI1RVM8c"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/closest-prime-numbers-in-range/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool seive[1000001] = {};
    vector<int> p = {2};
    vector<int> closestPrimes(int left, int right) {
        
        for(int i = 3; i < 1000001; i += 2) {
            if(!seive[i]) {
                p.push_back(i);
                for (long long j = (long long) i * i; j < 1000001; j += i) {
                    seive[j] = true;
                }
            }
        }
        
        int n1 = -1, n2 = -1, i = lower_bound(p.begin(), p.end(), left) - p.begin();
        
        for(; i + 1 < p.size() && p[i + 1] <= right; i++) {
            if(n1 == -1 || n2 - n1 > p[i + 1] - p[i]) {
                n1 = p[i];
                n2 = p[i + 1];
                if(n2 - n1 < 3) break;
            }
        }
        return {n1, n2};
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2523.md" >}}
---
{{< youtube HqSBI1RVM8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2525: Categorize Box According to Criteria](https://grid47.xyz/leetcode/solution-2525-categorize-box-according-to-criteria/) |
| --- |
